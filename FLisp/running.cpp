#include "running.h"
#include "type.h"
#include "list_spliting.h"
#include <iostream>
#include <list>
#include <map>

std::map<std::string, Flisp_Value> FLisp_functions = {};

Flisp_Value Flisp_eval(Flisp_Value v)
{
	std::list<Flisp_Value> l;
	v.get_value(l);
	std::string s;
	l.begin()->get_value(s);
	if (FLisp_functions.find(s) != FLisp_functions.end()) {

	}
}

// Run a lisp code in a std::string, and it will return the last value. 
Flisp_Value Flisp_running(std::string s) {
	Flisp_Value list = Flisp_List_Spliting(s);
	std::list<Flisp_Value> commands = {};
	list.get_value(commands);
	Flisp_Value v;
	for (auto i = commands.begin(); i != commands.end(); i++) {
		v = Flisp_eval(*i);
	}
	Flisp_Value r = v;
	return r;
}
