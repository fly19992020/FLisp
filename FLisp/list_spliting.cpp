#include "type.h"
#include <iostream>
#include <list>


Flisp_Value Flisp_List_Spliting(std::string s)
{
	std::list<Flisp_Value> l;
	Flisp_Value v;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			int j = i;
			int count = 1;
			while (count != 0) {
				j++;
				if (s[j] == '(') count++;
				if (s[j] == ')') count--;
			}
			l.push_back(Flisp_List_Spliting(s.substr(i + 1, j - i - 1)));
			i = j;
		}
		else if (s[i] == ' ') {
			continue;
		}
		else {
			int j = i;
			while (s[j] != ' ' && s[j] != ')' && j < s.length()) {
				j++;
			}
			Flisp_Value subs;
			subs.set_value_as_a_name(s.substr(i, j - i));
			l.push_back(subs);
			i = j - 1;
		}
	}
	v.set_value(l);
	return v;
}
