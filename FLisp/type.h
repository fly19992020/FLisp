#pragma once
#include <string>
#include <iostream>
#include <list>


// the base class of all the types of Flisp
class Flisp_Type {};


// the class of floats: the num is a double instead of a float
class Flisp_Num:public Flisp_Type {
public:
	double num;
};


// the class of strings
class Flisp_String:public Flisp_Type {
public:
	std::string str;
};


// the class of name: function name, value name, etc
class Flisp_Name :public Flisp_Type {
public:
	std::string name;
};


// the class of lists
class Flisp_list :public Flisp_Type {
public:
	std::list<Flisp_Type> list;
};
