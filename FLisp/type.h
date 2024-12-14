#pragma once
#include <iostream>
#include <list>
#define FLISP_NAME 0
#define FLISP_LISP 1
#define FLISP_NUM 2


class Flisp_Value {
private:
	void* value_pointer;
	int type;
	bool used = 0;
public:
	void get_value(void* pr);
	void set_value(int i);
	void set_value(std::string s);
	void set_value(std::list<Flisp_Value> l);
	void set_value_as_a_name(std::string s);
};
