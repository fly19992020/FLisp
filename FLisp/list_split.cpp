#include "list_split.h"
#include <iostream>
#include <string>

Flisp_list Flisp_list_from_String(std::string str)
{
	Flisp_list r;
	Flisp_Name this_name;
	std::string this_char;
	for (int i = 0; i <= str.length(); i++) {
		this_char = str[i];
		if (str[i] != ' ' && i != str.length()) {
			this_name.name.append(this_char);
		}
		else {
			r.list.push_back(this_name);
			this_name.name = "";
		}
	}
	return r;
}
