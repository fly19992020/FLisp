#pragma once
#include <iostream>
#include <list>
#define FLISP_NUL 0
#define FLISP_NAME 1
#define FLISP_LIST 2
#define FLISP_NUM 3
#define FLISP_STRING 4


class Flisp_Value {
private:
	void* value_pointer;
	int type;
	bool used = 0;
public:
	void get_value(int& pr); // get a int
	void get_value(std::string& pr); // get a string
	void set_value(int i);
	void set_value(std::string s);
	void set_value(std::list<Flisp_Value> l);
	void set_value_as_a_name(std::string s);
	Flisp_Value();
};
