#include <iostream>
#include <string>
#include <unordered_map>
#include <regex>
#include <set>
#include <sstream>

#include "global.h"


bool isMetaChar(char c)
{
    return c == '|' || c == '+' || c == '*' || c == '"' || c == '\\' || c == '(' || c ==')' || c=='?';
}

string expandWildcard(const string& regex) {
    string result;
    bool inQuotes = false;
    for (int i = 0; i < regex.size(); i++) {
        char ch = regex[i];
        if (ch == '"') {
            if(regex[i-1]&&regex[i-1]=='\\'){
                result+=ch;
                continue;
            }
            inQuotes = !inQuotes;
            result += ch;
        } else if (!inQuotes && ch == '.') {
            result += "[^\n]"; 
        } else {
            result += ch;
        }
    }
    return result;
}



string replaceDefinitions(const string& regex) {
    string result;
    bool inQuotes = false;

    for (size_t i = 0; i < regex.size(); ) {
        if (regex[i] == '"') {
            if(regex[i-1]&&regex[i-1]=='\\'){            
                result += regex[i++];
                continue;
            }
            inQuotes = !inQuotes;
            result += regex[i++];
        } else if (!inQuotes && regex[i] == '{') {
            size_t j = i + 1;
            while (j < regex.size() && regex[j] != '}') ++j;
            if (j < regex.size()) {
                string id = regex.substr(i + 1, j - i - 1);
                if (id2regex.find(id) != id2regex.end()) {
                    result += id2regex[id];
                } else {
                    cerr << "Error: Undefined id {" << id << "} in regex." << endl;
                    result += regex.substr(i, j - i + 1);
                }
                i = j + 1;
            } else {
                result += regex[i];
                ++i;
            }
        } else {
            result += regex[i];
            ++i;
        }
    }
    return result;
}


string expandCharClass(const string& regex) {
    string result;
    bool inQuotes = false;
    string universe = "\n";
    for (char ch = 32; ch <= 126; ++ch) {
        universe += ch;
    }

    for (size_t i = 0; i < regex.size(); ) {
        if (regex[i] == '"') {
            if(regex[i-1]&&regex[i-1]=='\\'){
                result += regex[i++];
                continue;
            }
            inQuotes = !inQuotes;
            result += regex[i++];
        } else if (!inQuotes && regex[i] == '[') {
            ++i;
            bool negate = false;
            if (i < regex.size() && regex[i] == '^') {
                negate = true;
                ++i;
            }
            set<char> included;
            while (i < regex.size() && regex[i] != ']') {
                if (i + 1 < regex.size() && regex[i] == '\\') {
                    char next = regex[i + 1];
                    auto it = escapeMap.find(next);
                    if (it != escapeMap.end()) {
                        included.insert(it->second);
                    } else {
                        // 插入原始字符（未知转义？你可以选择忽略或者报警）
                        included.insert(next);
                    }
                    i += 2;
                } else if (i + 2 < regex.size() && regex[i + 1] == '-' && regex[i + 2] != ']') {
                    char start = regex[i];
                    char end = regex[i + 2];
                    for (char ch = start; ch <= end; ++ch)
                        included.insert(ch);
                    i += 3;
                } else {
                    included.insert(regex[i]);
                    ++i;
                }
            }
            if (i < regex.size() && regex[i] == ']') ++i; // skip ']'
            string charClass = "(";
            if (negate) {
                for (char ch : universe) {
                    if (included.find(ch) == included.end()) {
                        if(isMetaChar(ch)){charClass += '\\';}
                        charClass += ch;
                        charClass += '|';
                    }
                }
            } else {
                for (char ch : included) {
                    if(isMetaChar(ch)){charClass += '\\';}
                    charClass += ch;
                    charClass += '|';
                }
            }
            if (!charClass.empty() && charClass.back() == '|') charClass.pop_back();
            charClass += ")";
            result += charClass;
        } else {
            result += regex[i++];
        }
    }
    return result;
}

// 转义双引号中的特殊字符
string escapeQuotes(const string& regex) {
    string result;
    bool inQuotes = false;
    for (size_t i = 0; i < regex.size(); ++i) {
        if (regex[i] == '"') {
            if(regex[i-1]&&regex[i-1]=='\\'){
                result+=regex[i];
                continue;}
            inQuotes = !inQuotes;
        } 
        else if (inQuotes && isMetaChar(regex[i])) {
            result += '\\'; // 转义特殊字符
            result += regex[i];
        } 
        else {
            result += regex[i];
        }
    }
    return result;
}

string handleQuestionAndPlus(const string& regex) {
    string result;
    for (size_t i = 0; i < regex.size(); ++i) {
        char ch = regex[i];
        if(ch == '\\')
        {
            result += ch;
            result += regex[i+1];
            i += 1;
            continue;
        }
        if (ch == '?' || ch == '+') {
            if (result.empty()) {
                cerr << "Error: Unexpected " << ch << " at beginning of regex." << endl;
                continue;
            }
            // 向后处理 ? 和 +
            if (result.back() == ')') {
                // 向前找匹配的 (
                int cnt = 0;
                size_t j = result.size() - 1;
                while (j != string::npos) {
                    if (result[j] == ')') ++cnt;
                    else if (result[j] == '(') --cnt;
                    if (cnt == 0) break;
                    if (j == 0) break;
                    --j;
                }
                string sub = result.substr(j);
                result.erase(j);
                if (ch == '?') {
                    result +="(" + sub + "|" + EPSILON + ")";
                } else { // ch == '+'
                    result += sub + sub + "*";
                }
            } else {
                char prev = result.back();
                result.pop_back();
                if (ch == '?') {
                    result += "(";
                    result += prev;
                    result += "|";
                    result += EPSILON;
                    result += ")";
                } else { // ch == '+'
                    result += prev;
                    result += prev;
                    result += "*";
                }
            }
        } else {
            result += ch;
        }
    }
    return result;
}


string addConcatenation(const string& regex) {
    if (regex.empty()) return "";
    
    // 第一步：将转义序列替换为临时占位符
    string processed;
    vector<string> escapeSequences;  // 存储转义序列
    bool inEscape = false;
    string currentEscape;
    
    for (char c : regex) {
        if (inEscape) {
            currentEscape += c;
            escapeSequences.push_back("\\" + string(1, c));  // 记录原始转义序列
            processed += ESCAPE_PLACEHOLDER;  // 使用特殊占位符，如 '\x01'
            inEscape = false;
        } else if (c == '\\') {
            inEscape = true;
            currentEscape = "\\";
        } else {
            processed += c;
        }
    }
    
    // 第二步：在处理的字符串中添加连接符
    string withConnections;
    for (size_t i = 0; i < processed.size() - 1; ++i) {
        char curr = processed[i];
        char next = processed[i + 1];
        
        withConnections += curr;
        
        // 判断是否需要连接符
        if (curr != '(' && curr != '|' && 
            next != '|' && next != ')' && next != '*') {
            withConnections += CONNECT;
        }
    }
    withConnections += processed.back();  // 添加最后一个字符
    
    // 第三步：将占位符恢复为原始转义序列
    string result;
    size_t escapeIndex = 0;
    
    for (char c : withConnections) {
        if (c == ESCAPE_PLACEHOLDER) {
            if (escapeIndex < escapeSequences.size()) {
                result += escapeSequences[escapeIndex++];
            }
        } else {
            result += c;
        }
    }
    
    return result;
}

string convertToStandardRE(const string& extendedRE) {
    string standardRE = extendedRE;
    standardRE = replaceDefinitions(standardRE);
    standardRE = expandWildcard(standardRE);
    standardRE = expandCharClass(standardRE);
    standardRE = escapeQuotes(standardRE);
    standardRE = handleQuestionAndPlus(standardRE);
    standardRE = addConcatenation(standardRE);
    return standardRE;
}




// int main() {
//     // 定义正则表达式的标识符
//     id2regex["D"] = "[0-9]";
//     id2regex["L"] = "[a-zA-Z_]";
//     id2regex["H"] = "[a-fA-F0-9]";

//     // 测试拓展正则表达式
//     string extendedRE = "a|[abc]";
//     string standardRE = convertToStandardRE(extendedRE);

//     cout << "Extended RE: " << extendedRE << endl;
//     cout << "Standard RE: " << standardRE << endl;

//     return 0;
// }