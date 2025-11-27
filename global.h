#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define LAYER_ID 15
#define HEADER_BEGIN 16
#define HEADER_END 17
#define BEGIN 0
#define ERROR -11
#define EPSLONG -1
#define CONNECT '\x1D'
#define EPSILON '\x1B'
using namespace std;

struct State {
    int id;
    vector<pair<char, State*>> transitions;
    State() : id(), transitions() {};
    State(int _id) : id(_id), transitions() {};
};

struct NFA {
    State* start;
    State* end;
};

struct DFAState {
    int id;
    map<char, DFAState*> transitions;
    set<int> nfaStates;
    bool isAccepting = false;
    string action;
    DFAState(int id_, const set<int>& nfaStates_)
    : id(id_), nfaStates(nfaStates_) {}
};



extern unordered_map<string, string> id2regex;
extern vector<NFA> NFAtable;
extern unordered_map<int, string> acceptActions;
extern const unordered_map<char, char> escapeMap;
void print_unseen(string regex);
