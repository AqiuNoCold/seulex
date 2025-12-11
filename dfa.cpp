#include <!ostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <fstream>
#include <iterator>

#include "global.h"

set<int> epsilonClosure(const set<int>& states, unordered_map<int, State*>& idToState) {
    set<int> closure = states;
    stack<int> st;
    for (int id : states) st.push(id);
    while (!st.empty()) {
        int current = st.top(); st.pop();
        State* state = idToState[current];
        for (auto& [ch, next] : state->transitions) {
            if (ch == EPSILON && !closure.count(next->id)) {
                closure.insert(next->id);
                st.push(next->id);
            }
        }
    }

    return closure;
}

set<int> move(const set<int>& states, char symbol, unordered_map<int, State*>& idToState) {
    set<int> result;
    for (int id : states) {
        for (auto& [ch, next] : idToState[id]->transitions) {
            if (ch == symbol) {
                result.insert(next->id);
            }
        }
    }
    return result;
}

vector<DFAState*> convertNFAtoDFA(NFA& nfa, unordered_map<int, string>& acceptActions) {
    unordered_map<int, State*> idToState;
    queue<State*> stateQueue;
    stateQueue.push(nfa.start);
    while (!stateQueue.empty()) {
        State* curr = stateQueue.front(); stateQueue.pop();
        if (idToState.count(curr->id)) continue;
        idToState[curr->id] = curr;
        for (auto& [ch, next] : curr->transitions) {
            stateQueue.push(next);
        }
    }
    set<char> alphabet;
    for (auto& [_, state] : idToState) {
        for (auto& [ch, _] : state->transitions) {
            if (ch != EPSILON) alphabet.insert(ch);
        }
    }
    map<set<int>, DFAState*> dfaMap;
    vector<DFAState*> dfaStates;
    int dfaId = 0;
    set<int> startSet = epsilonClosure({nfa.start->id}, idToState);
    auto* startDFA = new DFAState{dfaId++, startSet};
    for (int id : startSet) {
        if (acceptActions.count(id)) {
            startDFA->isAccepting = true;
            startDFA->action = acceptActions[id];
            break;
        }
    }
    dfaMap[startSet] = startDFA;
    dfaStates.push_back(startDFA);
    queue<DFAState*> q;
    q.push(startDFA);
    while (!q.empty()) {
        DFAState* current = q.front(); q.pop();
        for (char ch : alphabet) {
            set<int> moved = move(current->nfaStates, ch, idToState);
            if (moved.empty()) continue;
            set<int> closure = epsilonClosure(moved, idToState);
            if (!dfaMap.count(closure)) {
                DFAState* newDFA = new DFAState{dfaId++, closure};
                for (int id : closure) {
                    if (acceptActions.count(id)) {
                        newDFA->isAccepting = true;
                        newDFA->action = acceptActions[id];
                        break;
                    }
                }
                dfaMap[closure] = newDFA;
                dfaStates.push_back(newDFA);
                q.push(newDFA);
            }
            current->transitions[ch] = dfaMap[closure];
        }
    }
    return dfaStates;
}

void printDFA(DFAState* state) {
    if (!state) return;
    cout << "State ID: " << state->id << "\n";
    cout << "Accepting: " << (state->isAccepting ? "Yes" : "No") << "\n";
    cout << "Action: " << state->action << "\n";
    cout << "Transitions:\n";
    for (const auto& [symbol, target] : state->transitions) {
        cout << "  '" << symbol << "' -> " << target->id << "\n";
    }
    cout << "----------------------\n";
}

vector<DFAState*> minimizeDFA(const vector<DFAState*>& dfaStates) {
    vector<set<DFAState*>> partitions;
    set<DFAState*> accepting, nonAccepting;

    for (auto* state : dfaStates) {
        if (state->isAccepting)
            accepting.insert(state);
        else
            nonAccepting.insert(state);
    }

    if (!accepting.empty()) partitions.push_back(accepting);
    if (!nonAccepting.empty()) partitions.push_back(nonAccepting);

    bool changed;
    do {
        changed = false;
        vector<set<DFAState*>> newPartitions;

        for (auto& group : partitions) {
            map<string, set<DFAState*>> splitter;

            for (auto* state : group) {
                string sig;
                for (auto& [ch, target] : state->transitions) {
                    int groupID = -1;
                    for (int i = 0; i < partitions.size(); ++i) {
                        if (partitions[i].count(target)) {
                            groupID = i;
                            break;
                        }
                    }
                    sig += ch + to_string(groupID) + ";";
                }
                sig += "|" + state->action;
                splitter[sig].insert(state);
            }

            if (splitter.size() == 1) {
                newPartitions.push_back(group);
            } else {
                for (auto& [_, subGroup] : splitter) {
                    newPartitions.push_back(subGroup);
                }
                changed = true;
            }
        }

        partitions = newPartitions;
    } while (changed);

    // 找出起始状态所属分组
    DFAState* originalStart = dfaStates[0];
    set<DFAState*>* startGroup = nullptr;

    for (auto& group : partitions) {
        if (group.count(originalStart)) {
            startGroup = &group;
            break;
        }
    }

    // 创建新状态 & 映射
    map<DFAState*, DFAState*> oldToNew;
    vector<DFAState*> minimizedStates;
    int nextID = 0;

    // 优先创建起始状态分组，确保它排第一个
    if (startGroup) {
        DFAState* rep = *startGroup->begin();
        DFAState* newStart = new DFAState(nextID++, {});
        newStart->isAccepting = rep->isAccepting;
        newStart->action = rep->action;
        minimizedStates.push_back(newStart);

        for (auto* oldState : *startGroup) {
            oldToNew[oldState] = newStart;
        }
    }

    // 再创建其它分组的状态
    for (auto& group : partitions) {
        if (&group == startGroup) continue; // 跳过已处理的起始组

        DFAState* rep = *group.begin();
        DFAState* newState = new DFAState(nextID++, {});
        newState->isAccepting = rep->isAccepting;
        newState->action = rep->action;
        minimizedStates.push_back(newState);

        for (auto* oldState : group) {
            oldToNew[oldState] = newState;
        }
    }

    // 构建转移表
    for (auto& [oldState, newState] : oldToNew) {
        for (auto& [ch, target] : oldState->transitions) {
            newState->transitions[ch] = oldToNew[target];
        }
    }

    return minimizedStates; // 起始状态排在 index 0
}

string escapeDOTLabel(const string& label) {
    string result;
    for (char c : label) {
        switch (c) {
            case '\"': result += "\\\""; break;
            case '\\': result += "\\\\"; break;
            case '%':  result += "%%"; break;
            case '{':  result += "\\{"; break;
            case '}':  result += "\\}"; break;
            case '|':  result += "\\|"; break;
            case '<':  result += "\\<"; break;
            case '>':  result += "\\>"; break;
            default:   result += c; break;
        }
    }
    return result;
}


void generateDFAtoDOT(const vector<DFAState*>& dfaStates, const string& filename) {
    ofstream out(filename);
    if (!out.is_open()) {
        cerr << "无法打开文件 " << filename << " 进行写入！" << endl;
        return;
    }

    out << "digraph DFA {\n";
    out << "    rankdir=LR;\n";
    out << "    node [shape = circle];\n";

    for (auto* state : dfaStates) {
        if (state->isAccepting) {
            out << "    " << state->id << " [shape=doublecircle,label=\""
                << state->id;
            if (!state->action.empty()) {
                out << "\\n" << escapeDOTLabel(state->action);
            }
            out << "\"];\n";
        } else {
            out << "    " << state->id << " [label=\"" 
                << state->id << "\"];\n";
        }
    }

    out << "    start [shape=plaintext,label=\"\"];\n";
    if (!dfaStates.empty()) {
        out << "    start -> " << dfaStates[0]->id << ";\n";
    }

    for (auto* state : dfaStates) {
        for (auto& [symbol, target] : state->transitions) {
            out << "    " << state->id << " -> " << target->id
                << " [label=\"" << escapeDOTLabel(string(1, symbol)) << "\"];\n";
        }
    }
    out << "}\n";
    out.close();
    cout << "已导出 DFA 到文件：" << filename << endl;
}

string escapeCharForCase(char c) {
    switch (c) {
        case '\n': return "\\n";
        case '\t': return "\\t";
        case '\r': return "\\r";
        case '\f': return "\\f";
        case '\\': return "\\\\";
        case '\'': return "\\'";
        default:
            if (isprint(static_cast<unsigned char>(c))) {
                return string(1, c);
            } else {
                char buf[6];
                snprintf(buf, sizeof(buf), "\\x%02X", static_cast<unsigned char>(c));
                return string(buf);
            }
    }
}


void generateYylexFromDFA(const vector<DFAState*>& dfaStates, const string& filename) {
    // 定义标记，用于后续重新生成时保留用户在文件中手动添加的其他代码
    const string prologBegin = "/* __SEULEX_PROLOG_BEGIN__ */";
    const string prologEnd = "/* __SEULEX_PROLOG_END__ */";
    const string yylexBegin = "/* __SEULEX_YYLEX_BEGIN__ */";
    const string yylexEnd = "/* __SEULEX_YYLEX_END__ */";

    string originalContent;
    
    // 1. 读取现有文件内容（如果存在），以便保留用户自定义部分
    {
        ifstream existing(filename);
        if (existing.is_open()) {
            originalContent.assign((istreambuf_iterator<char>(existing)),
                                    istreambuf_iterator<char>());
        }
    }

    // 2. 剥离旧的自动生成部分
    auto stripSection = [&](const string& beginMarker, const string& endMarker) {
        size_t begin = originalContent.find(beginMarker);
        if (begin != string::npos) {
            size_t end = originalContent.find(endMarker, begin + beginMarker.size());
            if (end != string::npos) {
                originalContent.erase(begin, end - begin + endMarker.size());
            }
        }
    };

    stripSection(prologBegin, prologEnd);
    stripSection(yylexBegin, yylexEnd); // 注意：这里你的逻辑是将整个yylex函数体替换

    ofstream out(filename);
    if (!out.is_open()) {
        cerr << "无法打开文件 " << filename << " 进行写入！" << endl;
        return;
    }

    // 3. 写入头部定义 (Prolog)
    out << prologBegin << "\n";
    out << "#include <stdio.h>\n";
    out << "#include <string.h>\n";
    out << "#include <stdlib.h>\n\n"; // 添加 stdlib.h
    
    out << "int yylineno = 1;\n";
    out << "FILE *yyin = NULL;\n";
    out << "FILE *yyout = NULL;\n\n";
    out << "char yytext[1024] = \"\";\n";
    out << "int yyleng = 0;\n\n";
    
    out << "static int input(void) {\n";
    out << "    int c = fgetc(yyin ? yyin : stdin);\n";
    out << "    if (c == '\\n') yylineno++;\n";
    out << "    return c;\n"; // EOF 在 C 中通常是 -1，这里直接返回即可
    out << "}\n\n";
    
    // 修正 unput/ungetc 的宏或辅助函数，确保使用正确的流
    out << "static void yyunput(int c) {\n";
    out << "    if (c == '\\n') yylineno--;\n";
    out << "    ungetc(c, yyin ? yyin : stdin);\n";
    out << "}\n\n";

    out << "#define ECHO fwrite(yytext, 1, yyleng, yyout ? yyout : stdout)\n";
    out << prologEnd << "\n\n";

    // 4. 写入用户原来的其他内容（如果有）
    if (!originalContent.empty()) {
        // 简单的去除多余空行的处理
        size_t first_non_newline = originalContent.find_first_not_of("\n");
        if (first_non_newline != string::npos) {
             out << originalContent.substr(first_non_newline);
        }
        if (originalContent.back() != '\n') {
            out << "\n";
        }
    }

    // 5. 生成核心 yylex 函数
    out << yylexBegin << "\n";
    out << "int yylex() {\n";
    out << "    int state = " << dfaStates[0]->id << ";\n"; // 初始状态
    out << "    int ch;\n";
    out << "    yyleng = 0;\n";
    out << "    memset(yytext, 0, sizeof(yytext));\n\n";
    
    out << "    while (1) {\n"; // 使用死循环，内部通过 break 或 return 跳出
    out << "        ch = input();\n";
    out << "        printf(\"Read char: '%c' (ASCII %d) in state %d\\n\", ch, ch, state);\n\n";
    out << "        if (ch == EOF && yyleng == 0) {\n";
    out << "            return YYEOF;\n";
    out << "        }\n\n";

    out << "        switch(state) {\n";

    for (auto* state : dfaStates) {
        out << "            case " << state->id << ":\n";
        
        // 检查是否有出边
        if (state->transitions.empty()) {
            // 没有出边，说明这是一个死胡同或者纯接受状态
            // 逻辑：回退刚才读入的字符（因为它没被匹配），然后检查当前状态是否接受
            out << "                yyunput(ch);\n"; 
            if (state->isAccepting) {
                if (!state->action.empty()) {
                    out << "                " << state->action << "\n";
                }
                // 执行完动作后，重置状态机以读取下一个 Token
                out << "                state = " << dfaStates[0]->id << ";\n";
                out << "                yyleng = 0; memset(yytext, 0, sizeof(yytext));\n";
                out << "                break;\n"; 
            } else {
                out << "                // 错误：到达死状态且非接受状态\n";
                out << "                printf(\"Lexical error at line %d: unexpected character '%c'\\n\", yylineno, ch);\n";
                out << "                return -1;\n";
            }
            continue; 
        }

        // 有出边，生成内部 switch
        out << "                switch(ch) {\n";
        
        for (const auto& pair : state->transitions) {
            char symbol = pair.first;
            DFAState* target = pair.second;
            string escaped = escapeCharForCase(symbol);

            out << "                    case '" << escaped << "':\n";
            out << "                        state = " << target->id << ";\n";
            out << "                        if (yyleng < 1023) yytext[yyleng++] = ch;\n";
            // 保留你原来的特殊逻辑（虽然看起来有点奇怪，可能是特定需求）
            if (symbol == ' ' && state->id != 0 && state->id != 1) {
                 // out << "                        yytext[yyleng++] = ch;\n"; 
            }
            out << "                        break;\n";
        }

        // 内部 switch 的 default：当前字符不匹配任何出边
        out << "                    default:\n";
        out << "                        yyunput(ch);\n"; // 回退字符
        if (state->isAccepting) {
            // 贪婪匹配原则：如果当前无法继续匹配，但当前状态是接受状态，则匹配成功
            if (!state->action.empty()) {
                out << "                        " << state->action << "\n";
                // 动作执行完后，重置状态机
                out << "                        state = " << dfaStates[0]->id << ";\n";
                out << "                        yyleng = 0; memset(yytext, 0, sizeof(yytext));\n";
            } else {
                out << "                        return 0;\n";
            }
        } else {
            // 既不能转换，也不是接受状态 -> 词法错误
            out << "                        printf(\"Lexical error: unexpected char '%c'\\n\", ch);\n";
            out << "                        return -1;\n";
        }
        out << "                        break;\n";
        out << "                }\n"; // end inner switch
        out << "                break;\n";
    }

    out << "            default:\n";
    out << "                return -1; // 未知状态错误\n";
    out << "        }\n"; // end outer switch
    out << "    }\n"; // end while
    out << "}\n"; // end function
    out << yylexEnd << "\n";

    out.close();
    cout << "已成功生成 lex.yy.c (" << filename << ")" << endl;
}