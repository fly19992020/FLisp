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
        int* pointer = (int*)value_pointer;
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
        auto* pointer = (std::list<Flisp_Value>*)value_pointer;
        for (auto & i : *pointer) {
            pr.push_back(i);
        }
    }
    else { // if not, noise an error
        Flisp_noise("typeError");
    }
}

int Flisp_Value::get_type()
{
    return this->type;
}

void Flisp_Value::set_value(int i)
{
    type = FLISP_NUM;
    if (used == true) { // if the value is used
        free(value_pointer); // free the old address
        int* p = (int*)malloc(sizeof(i)); // get a new address
        if (p != nullptr) {
            *p = i;
        }
        else { // if the p is a nullptr, noise an error
            Flisp_noise("nullptr. ");
        }
        value_pointer = p;
    }
    else if (used == false) {
        used = true;
        auto p = static_cast<int*>(malloc(sizeof(i)));
        if (p != nullptr) {
            *p = i;
        }
        else { // if the p is a nullptr, noise an error
            Flisp_noise("nullptr. ");
        }
        value_pointer = p;
    }
}

void Flisp_Value::set_value(std::string s)
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

void Flisp_Value::set_value(std::list<Flisp_Value> l)
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
        if (p != nullptr) {
            for (auto i = l.begin(); i != l.end(); i++) {
                p->push_back(*i);
            }
        }
        else { // if the p is a nullptr, noise an error
            Flisp_noise("nullptr. ");
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
		Flisp_Func* p = new Flisp_Func; // get a new address
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
		Flisp_Func* p = new Flisp_Func; // get a new address
		p->set_func(f);
		value_pointer = p;
	}
	else if (used == false) {
		used = true;
		value_pointer = &f;
	}
}

void Flisp_Value::set_value_as_a_name(std::string s)
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
		int r = *(int*)value_pointer;
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
		std::string r = *(std::string*)value_pointer;
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

Flisp_Value Flisp_Func::run(std::list<Flisp_Value>& args_list)
{
	if (type == FLISP_C_FUNC) {
		return function_pointer(args_list);
	}
	else if (type == FLISP_LISP_FUNC) {
		std::list<Flisp_Value> l;
		value_function.get_value(l);
		Flisp_Value v;
        std::list<Flisp_Value> vl; // A list to get the list. 
		std::string v1; // A string to get the first string.
		Flisp_Value v2; // A value to get the second value.
		for (auto i = l.begin(); i != l.end(); i++) {
            if (i->get_type() == FLISP_LIST) {
				i->get_value(vl); // Get the list.
				auto j = vl.begin(); // Get the first value.
				j->get_value(v1); // Get the first string.
				v2 = *(++j); // move to and get the second value.
                if (v1 == "return") {
                    return Flisp_eval(v2);
                }
				v = Flisp_eval(*i);
            }
		}
		return v;
	}
	else {
		Flisp_noise("typeError");
	}
}

void Flisp_Func::set_func(Flisp_Value(*function_pointer)(std::list<Flisp_Value>args_list))
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
