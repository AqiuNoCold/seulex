#include <iostream>
#include "global.h"

const unordered_map<char, char> escapeMap = {
    {'t', '\t'},
    {'v', '\v'},
    {'n', '\n'},
    {'f', '\f'},
    {'r', '\r'},
    {'\\', '\\'},
    {'\'', '\''},
    {'\"', '\"'}
};

void print_unseen(string regex)
{
    for(auto ch : regex)
    {
        if (ch == EPSILON)
        {
            cout << "ε";
        }
        else if (ch == CONNECT)
        {
            cout << "•";
        }
        else{ cout << ch;}
    }
    cout << endl;
}

