#include<string>
#include<unordered_set>

using namespace std;
string infixToPostfix(const string& regex);
NFA postfixToNFA(const string& postfix);
void printNFA(State* start);
NFA merge();
