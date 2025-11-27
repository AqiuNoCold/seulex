#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

vector<DFAState*> convertNFAtoDFA(NFA& nfa, unordered_map<int, string>& acceptActions);
vector<DFAState*> minimizeDFA(const vector<DFAState*>& dfaStates);
void printDFA(DFAState* state);
void generateDFAtoDOT(const vector<DFAState*>& dfaStates, const string& filename);
void generateYylexFromDFA(const vector<DFAState*>& dfaStates, const string& filename);
