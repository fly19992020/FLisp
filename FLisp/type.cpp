/* type.cpp
   The definition of some functions in the Flisp_Value.
   A part of Flisp. 
   (c) fly19992020 2024-2025
*/
#include "type.h"
#include "error.h"
#include "running.h"



Flisp_Value Flisp_Func::run(const std::list<Flisp_Value>& args_list, Flisp_VM vm)
{
	if (type == FLISP_C_FUNC) {
		return function_pointer(args_list, vm);
	}
	else if (type == FLISP_LISP_FUNC) {
		std::list<Flisp_Value> l;
		value_function.get_value(l);
		Flisp_Value v;
        std::list<Flisp_Value> vl; // A list to get the list. 
		std::string v1; // A string to get the first string.
		// A value to get the second value.
		for (auto & i : l) {
            if (i.get_type() == FLISP_LIST) {
				i.get_value(vl); // Get the list.
				if (vl.empty()) {
					continue;
				}
				auto j = vl.begin(); // Get the first value.
				j->get_value(v1); // Get the first string.
				Flisp_Value v2 = *(++j); // move to and get the second value.
                if (v1 == "return") {
                    return vm.eval(v2); // If the first string is "return", return the second value.
                }
				v = vm.eval(i);
            }
		}
		return v;
	}
	return {};
}

void Flisp_Func::set_func(Flisp_Value(*function_pointer)(std::list<Flisp_Value>args_list, Flisp_VM vm))
{
	type = FLISP_C_FUNC;
	this->function_pointer = function_pointer;
}

void Flisp_Func::set_func(Flisp_Value v)
{
	type = FLISP_LISP_FUNC;
	this->value_function = v;
}

Flisp_Func::Flisp_Func()
{
	type = FLISP_C_FUNC;
	function_pointer = nullptr;
}

std::string Flisp_Name::get_name()
{
	return this->name;
}
void Flisp_Name::set_name(const std::string& s) {
	this->name = s;
}
