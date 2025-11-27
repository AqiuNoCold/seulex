#include <unordered_map>
#include <string>
#include <iostream>
#include <unistd.h>

#include "global.h"
#include "readfile.h"
#include "regular.h"
#include "nfa.h"
#include "dfa.h"

void test()
{
    // 创建 NFA 状态
    State* s0 = new State{0};
    State* s1 = new State{1};
    State* s2 = new State{2};  // Accepting for "aa"
    State* s3 = new State{3};
    State* s4 = new State{4};
    State* s5 = new State{5};  // Accepting for "ab"
    State* s6 = new State{6};
    State* s7 = new State{7};  // Accepting for "ba"
    State* s8 = new State{8};
    // 创建 ε-transition
    s0->transitions.push_back({EPSILON, s1});
    s0->transitions.push_back({EPSILON, s3});
    s0->transitions.push_back({EPSILON, s6});
    s1->transitions.push_back({'a', s2});   // "aa" path
    s2->transitions.push_back({'a', s7});   // accept "aa"
    s3->transitions.push_back({'a', s4});   // "ab" path
    s4->transitions.push_back({'b', s5});   // accept "ab"
    s6->transitions.push_back({'b', s8});   // accept "ba"
    s8->transitions.push_back({'a', s8});   // loop on "ba"
    NFA nfa;
    nfa.start = s0;
    printNFA(nfa.start);
    // 设置多个接受状态和相应的动作
    acceptActions[5] = "MATCH_AB";
    acceptActions[7] = "MATCH_AA";
    acceptActions[8] = "MATCH_BA";
    for (const auto &p : acceptActions)
    {
        auto id = p.first;
        auto action = p.second;
        cout << id << ":" << action << endl;
    }
    vector<DFAState*> dfaStates = convertNFAtoDFA(nfa, acceptActions);
    for(auto & state : dfaStates)
    {
        printDFA(state);
    }
    vector<DFAState*> minState = minimizeDFA(dfaStates);
    cout << "done" << endl;
    for(auto & state : minState)
    {
        printDFA(state);
    }
    generateDFAtoDOT(minState, "dfa.dot");
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cerr << "用法: " << argv[0] << " <lex文件路径>" << endl;
        return 1;
    }
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working dir: %s\n", cwd);
    }
    printf("Looking for file: %s\n", argv[1]);
    string inputFile = argv[1];
    if(!readfile(inputFile)) {  // 读取指定文件
        cerr << "Failed to read file: " << inputFile << endl;
        return 1;
    }
    cout << "完成NFA构建" << endl;
    NFA dummy = merge(); 
    cout << "完成NFA合并" << endl;
    vector<DFAState*> dfaStates = convertNFAtoDFA(dummy, acceptActions);
    cout << "完成NFA转DFA" << endl;
    vector<DFAState*> minState = minimizeDFA(dfaStates);
    cout << "完成最小化DFA" << endl;
    // 输出DFA图和词法分析器
    generateDFAtoDOT(minState, "dfa.dot");
    generateYylexFromDFA(minState, "lex.yy.c");

    cout << "已成功处理文件: " << inputFile << endl;

    return 0;
}