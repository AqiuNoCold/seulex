#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <unordered_map>
#include <stack>
#include <map>
#include <unordered_set>
#include <unistd.h>

#include "global.h"
#include "regular.h"
#include "nfa.h"
#include "dfa.h"

unordered_map<string, string> id2regex;
vector<NFA> NFAtable;
unordered_map<int, string> acceptActions;


ifstream ifile;
ofstream ofile;

int checkSpecsign(char c)
{
	if(c=='%')
	{
		char cc=ifile.get();
		switch(cc)
		{
		case '%':
			return LAYER_ID;
		case '{':
			return HEADER_BEGIN;
		case '}':
			return HEADER_END;
		default:
			ifile.unget();
			break;
		}
	}
	return ERROR;
}

bool get_file(string s)
{
    int lineno=0;
    char c;
	int state=checkSpecsign(c);
	pair<string,string> pi;
	state=BEGIN;
	while (!ifile.eof() && state != HEADER_BEGIN)
	{
		c = ifile.get();
		if (c == '\n') {
			continue;
		}
		if (c == '%') {
			state = checkSpecsign(c);
			if (state == ERROR) {
				cerr << "There is an error in line " << lineno << " !" << endl;
				return false;
			}
			continue;
		} else {
			ifile.unget();
		}
	
		string onestr;
		getline(ifile, onestr);
	
		size_t space_pos = onestr.find_first_of(" \t");
		if (space_pos == string::npos) {
			cerr << "Missing regular expression in line: " << lineno << endl;
			return false;
		}
	
		string id = onestr.substr(0, space_pos);
		string re = onestr.substr(space_pos + 1);
		re.erase(0, re.find_first_not_of(" \t")); // 去掉 re 前空格
		re.erase(re.find_last_not_of(" \t") + 1); // 去掉 re 后空格
	
		re = replaceDefinitions(re);
		pi.first = id;
		pi.second = re;
		id2regex.insert(pi);
	
		lineno++;
	}
    // for(auto i = id2regex.begin(); i != id2regex.end(); i++)
    // {
    //     cout << i->first << ":" << i->second << endl;
    // }
    while(!ifile.eof()&&state!=HEADER_END)
	{
		c=ifile.get();
		if(c=='\t') continue;
		if(c=='%') {state=checkSpecsign(c);continue;}
		if(c=='\n') lineno++;
		ofile.put(c);
	}
    // cout << "写完毕" << endl;
    while (c = ifile.get() == '\n'); 
    c = ifile.get();
    while(!ifile.eof()&&state!=LAYER_ID)
	{
		c=ifile.get();
        if(c == '\n')
        {
            continue;
        }
		if(c=='%')
		{
			state=checkSpecsign(c);
			if(state==ERROR)
			{
				cerr<<"There is an error in line "<<lineno<<" !"<<endl;
				return false;
			}
			continue;
		}
		else
		{
			ifile.unget();
		}
		string onestr;
		string re, action;
		getline(ifile, onestr);		
		size_t lbrace_pos = onestr.rfind("{ ");
		if (lbrace_pos == string::npos) {
			printf("Debug: onestr='%s'\n", onestr.c_str());
			cerr << "Missing '{ ' in line: " << lineno << endl;
			return false;
		}		
		re = onestr.substr(0, lbrace_pos);
		re.erase(re.find_last_not_of(" \t") + 1);
		action = onestr.substr(lbrace_pos + 2);
		action.erase(0, action.find_first_not_of(" \t"));
		action.erase(action.find_last_not_of(" \t") + 1);
		if (!action.empty() && action.back() == '}') {
			action.pop_back();
		}
		cout << "orginal: " << re << " action:" << action << endl;
		re = convertToStandardRE(re);
		cout << "infix:";
		print_unseen(re);
		re = infixToPostfix(re);
		cout << "postfix:";
		print_unseen(re);
		NFA nfa = postfixToNFA(re);
        NFAtable.push_back(nfa);
		acceptActions.insert({nfa.end->id, action});
		// printNFA(nfa.start);
		// cout << "--------------------sep-----------------" << endl;
        lineno++;
	}
    while((c=ifile.get())!=-1)
	{
		ofile.put(c);
	}
	ifile.close();
	ofile.close();
    return true;
}

bool readfile(string s)
{
	ifile.close();
    ifile.clear();
	// 调试信息
    cout << "尝试打开文件: " << s << endl;
    cout << "文件是否存在: " << (access(s.c_str(), F_OK) == 0 ? "是" : "否") << endl;
    ifile.open(s.c_str(),ios::in);
	ofile.open("lex.yy.c",ios::out);
    if(!ifile)
	{
		cerr<<"Open the file error!"<<endl;
		return 0;
	}
    if(get_file(s)){cout << "读取文件成功!" << endl;}
    return 1;
}

// int main() {
// 	readfile();
// }
