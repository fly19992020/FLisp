/* type.cpp
   The definition of some functions in the Flisp_Value.
   A part of Flisp. 
   (c) fly19992020 2024
*/
#include "type.h"
#include "error.h"

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
        std::string* pointer = (std::string*)value_pointer;
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
        std::list<Flisp_Value>* pointer = (std::list<Flisp_Value>*)value_pointer;
        for (auto i = pointer->begin(); i != pointer->end(); i++) {
            pr.push_back(*i);
        }
    }
    else { // if not, noise an error
        Flisp_noise("typeError");
    }
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
        int* p = (int*)malloc(sizeof(i));
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
        std::string* p = new std::string; // get a new address
        if (p != nullptr) {
            p->erase();
            p->append(s);
        }
        else { // if the p is a nullptr, noise an error
            Flisp_noise("nullptr. ");
        }
        value_pointer = p;
    }
    else if (used == false) {
        used = true;
        std::string* p = new std::string;
        if (p != nullptr) {
            p->erase();
            p->append(s);
        }
        else { // if the p is a nullptr, noise an error
            Flisp_noise("nullptr. ");
        }
        value_pointer = p;
    }
}

void Flisp_Value::set_value(std::list<Flisp_Value> l)
{
    type = FLISP_LIST;
    if (used == true) { // if the value is used
        free(value_pointer); // free the old address
        std::list<Flisp_Value>* p = new std::list<Flisp_Value>; // get a new address
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
    else if (used == false) {
        used = true;
        std::list<Flisp_Value>* p = new std::list<Flisp_Value>;
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

void Flisp_Value::set_value_as_a_name(std::string s)
{
	type = FLISP_NAME;
	if (used == true) { // if the value is used
		free(value_pointer); // free the old address
		std::string* p = new std::string; // get a new address
		if (p != nullptr) {
			p->erase();
			p->append(s);
		}
		else { // if the p is a nullptr, noise an error
			Flisp_noise("nullptr. ");
		}
		value_pointer = p;
	}
	else if (used == false) {
		used = true;
		std::string* p = new std::string;
		if (p != nullptr) {
			p->erase();
			p->append(s);
		}
		else { // if the p is a nullptr, noise an error
			Flisp_noise("nullptr. ");
		}
		value_pointer = p;
	}
}

Flisp_Value::Flisp_Value()
{
    used = false;
    type = FLISP_NUL;
    value_pointer = nullptr;
}
