/* type.cpp
   The definition of some functions in the Flisp_Value.
   A part of Flisp. 
   (c) fly19992020 2024
*/
#include "type.h"
#include "error.h"

void Flisp_Value::get_value(void* pr)
{
	switch (type) {
	case FLISP_NUM: // if the type is num
		int* pointer = (int*)value_pointer;
		int value = *pointer;
		*(int*)pr = value;
		break;
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
	//return nullptr;
}

void Flisp_Value::set_value(std::list<Flisp_Value> l)
{
	//return nullptr;
}

void Flisp_Value::set_value_as_a_name(std::string s)
{
	//return nullptr;
}
