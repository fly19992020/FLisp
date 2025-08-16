/* type.cpp
   The definition of some functions in the Flisp_Value.
   A part of Flisp. 
   (c) fly19992020 2024-2025
*/
#include "type.h"
#include "error.h"
#include "running.h"

void Flisp_Value::get_value(int& pr)
{
    if (type == FLISP_NUM) { // check if the type is correct
        auto* pointer = static_cast<int*>(this->value_pointer);
        pr = *pointer;
    }
    else { // if not, noise an error
        Flisp_noise("typeError");
    }
}

void Flisp_Value::get_value(std::string& pr)
{
    if ((type == FLISP_STRING) || (type == FLISP_NAME)) { // check if the type is correct
        auto* pointer = static_cast<std::string*>(this->value_pointer);
        pr = *pointer;
    }
    else { // if not, noise an error
        Flisp_noise("typeError");
    }
}

void Flisp_Value::get_value(std::list<Flisp_Value>& pr)
{
    if (type == FLISP_LIST) { // check if the type is correct
		pr.clear();
        auto* pointer = static_cast<std::list<Flisp_Value> *>(value_pointer);
        for (auto & i : *pointer) {
            pr.push_back(i);
        }
    }
    else { // if not, noise an error
        Flisp_noise("typeError");
    }
}

int Flisp_Value::get_type() const
{
    return this->type;
}

void Flisp_Value::set_value(int i)
{
    type = FLISP_NUM;
    if (used == true) { // if the value is used
        free(value_pointer); // free the old address
        auto p = new int; // get a new address
    	*p = i;
        value_pointer = p;
    }
    else if (used == false) {
        used = true;
        auto p = new int;
    	*p = i;
        value_pointer = p;
    }
}

void Flisp_Value::set_value(const std::string& s)
{
    type = FLISP_STRING;
    if (used == true) { // if the value is used
        free(value_pointer); // free the old address
        auto* p = new std::string; // get a new address
    	p->erase();
    	p->append(s);
        value_pointer = p;
    }
    else if (used == false) {
        used = true;
        auto* p = new std::string;
        p->erase();
    	p->append(s);
        value_pointer = p;
    }
}

void Flisp_Value::set_value(const std::list<Flisp_Value>& l)
{
    type = FLISP_LIST;
    if (used == true) { // if the value is used
        free(value_pointer); // free the old address
        auto* p = new std::list<Flisp_Value>; // get a new address
    	for (auto & i : l) {
    		p->push_back(i);
    	}
        value_pointer = p;
    }
    else if (used == false) {
        used = true;
        auto* p = new std::list<Flisp_Value>;
    	for (auto i : l) {
    		p->push_back(i);
    	}
        value_pointer = p;
    }
}

/*void Flisp_Value::set_value(Flisp_Value(*function_pointer)(std::list<Flisp_Value>args_list))
{
	type = FLISP_C_FUNC;
	if (used == true) { // if the value is used
		free(value_pointer); // free the old address
		Flisp_Value(*p)(std::list<Flisp_Value>args_list) = function_pointer; // get a new address
		if (p != nullptr) {
			value_pointer = p;
		}
		else { // if the p is a nullptr, noise an error
			Flisp_noise("nullptr. ");
		}
	}
	else if (used == false) {
		used = true;
		value_pointer = function_pointer;
	}
}*/

void Flisp_Value::set_value(Flisp_Func f)
{
	type = FLISP_FUNC;
	if (used == true) { // if the value is used
		free(value_pointer); // free the old address
		auto* p = new Flisp_Func; // get a new address
		*p = f;
		value_pointer = p;
	}
	else if (used == false) {
		used = true;
		value_pointer = &f;
	}
}

void Flisp_Value::set_value_as_a_func(Flisp_Value f)
{
	type = FLISP_FUNC;
	if (used == true) { // if the value is used
		free(value_pointer); // free the old address
		auto* p = new Flisp_Func; // get a new address
		p->set_func(f);
		value_pointer = p;
	}
	else if (used == false) {
		used = true;
		value_pointer = &f;
	}
}

void Flisp_Value::set_value_as_a_name(const std::string& s)
{
	type = FLISP_NAME;
	if (used == true) { // if the value is used
		free(value_pointer); // free the old address
		auto* p = new std::string; // get a new address
		p->erase();
		p->append(s);
		value_pointer = p;
	}
	else if (used == false) {
		used = true;
		auto* p = new std::string;
		p->erase();
		p->append(s);
		value_pointer = p;
	}
}

Flisp_Value::operator int()
{
	if (type == FLISP_NUM) {
		int r = *static_cast<int *>(value_pointer);
		return r;
	}
	else {
		Flisp_noise("typeError");
		return 0;
	}
}

Flisp_Value::operator std::string()
{
	if ((type == FLISP_STRING) || (type == FLISP_NAME)) {
		std::string r = *static_cast<std::string *>(value_pointer);
		return r;
	}
	else {
		Flisp_noise("typeError");
		return "";
	}
}

Flisp_Value::Flisp_Value()
{
    used = false;
    type = FLISP_NUL;
    value_pointer = nullptr;
}

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
