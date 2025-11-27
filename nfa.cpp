#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <cctype>
#include <unordered_set>
#include <queue>

#include"global.h"

int state_id = 0;

int precedence(char op) {
    switch (op) {
        case '*':
            return 3;
        case CONNECT:
            return 2;
        case '|':
            return 1;
        default:
            return 0;
    }
}

bool isOperator(char c) {
    return c == '|' || c == '*' || c == CONNECT;
}

bool isEscaped(const string& regex, size_t i) {
    if (i > 0 && regex[i - 1] == '\\' && !isEscaped(regex, i-1)) {
        return true;
    }
    return false;
}

string infixToPostfix(const string& regex) {
    string output;
    stack<char> operators;
    for (size_t i = 0; i < regex.size(); ++i) {
        char c = regex[i];
        if (isEscaped(regex, i)) {
            output += c;
            continue;
        }
        if (c == '(') {
            operators.push(c);  // 左括号
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                output += operators.top();
                operators.pop();
            }
            if (!operators.empty()) operators.pop(); // pop '('
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                output += operators.top();
                operators.pop();
            }
            operators.push(c);
        } else if (!isOperator(c)) {
            output += c;
        }
        // cout << "第" << i << "轮:";
        // print_unseen(output);
    }
    while (!operators.empty()) {
        output += operators.top();
        operators.pop();
    }
    return output;
}

State* new_state() {
    State* s = new State();
    s->id = state_id++;
    return s;
}

NFA postfixToNFA(const string& postfix) {
    stack<NFA> nfaStack;
    bool escaped = false;
    for (size_t i = 0; i < postfix.size(); ++i) {
        char token = postfix[i];
        if (escaped) {
            State* s = new_state();
            State* e = new_state();
            s->transitions.push_back({token, e});
            nfaStack.push({s, e});
            escaped = false;
            continue;
        }
        if (token == '\\') {
            escaped = true;
            continue;
        }
        if (token == CONNECT) {
            NFA b = nfaStack.top(); nfaStack.pop();
            NFA a = nfaStack.top(); nfaStack.pop();
            a.end->transitions.push_back({EPSILON, b.start});
            nfaStack.push({a.start, b.end});
        }
        else if (token == '|') {
            NFA b = nfaStack.top(); nfaStack.pop();
            NFA a = nfaStack.top(); nfaStack.pop();
            State* s = new_state();
            State* e = new_state();
            s->transitions.push_back({EPSILON, a.start});
            s->transitions.push_back({EPSILON, b.start});
            a.end->transitions.push_back({EPSILON, e});
            b.end->transitions.push_back({EPSILON, e});
            nfaStack.push({s, e});
        }
        else if (token == '*') {
            NFA a = nfaStack.top(); nfaStack.pop();
            State* s = new_state();
            State* e = new_state();
            s->transitions.push_back({EPSILON, a.start});
            a.end->transitions.push_back({EPSILON, a.start});
            a.start->transitions.push_back({EPSILON, e});
            nfaStack.push({s, e});
        }
        else {
            // 普通字符
            State* s = new_state();
            State* e = new_state();
            s->transitions.push_back({token, e});
            nfaStack.push({s, e});
        }
    }
    if (escaped) {
        cerr << "Error: trailing escape character '\\' with no character after it.\n";
    }

    return nfaStack.top();
}


void printNFA(State* start) {
    unordered_set<int> visited;
    queue<State*> q;
    q.push(start);
    visited.insert(start->id);
    while (!q.empty()) {
        State* current = q.front();
        q.pop();
        for (const auto& [symbol, next] : current->transitions) {
            cout << "State " << current->id << " --";
            if (symbol == EPSILON)
                cout << "ε";
            else
                cout << symbol;
            cout << "--> State " << next->id << endl;

            if (!visited.count(next->id)) {
                visited.insert(next->id);
                q.push(next);
            }
        }
    }
}

NFA merge(){
    State* newStart = new State{-1};
    for(auto &nfa : NFAtable)
    {
        newStart->transitions.push_back({ EPSILON , nfa.start });
    }
    return NFA{newStart, nullptr};
}