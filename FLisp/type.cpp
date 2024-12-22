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
	if (type == FLISP_STRING) { // check if the type is correct
		std::string* pointer = (std::string*)value_pointer;
		pr = *pointer;
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
		std::string* p = (std::string*)malloc(sizeof(s)); // get a new address
		if (p != nullptr) {
			*p = s;
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
	//return nullptr;
}

void Flisp_Value::set_value_as_a_name(std::string s)
{
	//return nullptr;
}

Flisp_Value::Flisp_Value() // the init function
{
	used = false;
	type = FLISP_NUL;
	value_pointer = nullptr;
}
