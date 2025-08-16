#pragma once
class Flisp_VM;
#include <iostream>
#include <list>
#include "vm.h"
#define FLISP_NUL 0
#define FLISP_NAME 1
#define FLISP_LIST 2
#define FLISP_NUM 3
#define FLISP_STRING 4
#define FLISP_FUNC 5
#define FLISP_C_FUNC 0
#define FLISP_LISP_FUNC 1

typedef char Func_Type;


class Flisp_Func;
class Flisp_Value {
private:
	void* value_pointer;
	int type;
	bool used = false;
public:
	void get_value(int& pr); // get an int
	void get_value(std::string& pr); // get a string
	void get_value(std::list<Flisp_Value>& pr); // get a list
	void get_value(Flisp_Func& pr); // get a function
	int get_type() const;
	void set_value(int i);
	void set_value(const std::string& s);
	void set_value(const std::list<Flisp_Value>& l);
	//void set_value(Flisp_Value(*function_pointer)(std::list<Flisp_Value> args_list));
	void set_value(Flisp_Func f);
	void set_value_as_a_func(Flisp_Value f);
	void set_value_as_a_name(const std::string& s);
	explicit operator int();
	explicit operator std::string();
	Flisp_Value();
};

/* the class for functions in Flisp:
 * two types of functions:
 * 1. C++ functions
 * 2. Lisp functions:
 * for example: [[+ a, b][print "Hello"]]
 */ 
class Flisp_Func {
private:
	Func_Type type;
	Flisp_Value(*function_pointer)(std::list<Flisp_Value> args_list, Flisp_VM vm);
	Flisp_Value value_function;
public:
	Flisp_Value run(const std::list<Flisp_Value> &args_list, Flisp_VM vm);
	void set_func(Flisp_Value(*function_pointer)(std::list<Flisp_Value> args_list, Flisp_VM vm));
	void set_func(Flisp_Value v);
	Flisp_Func();
};
