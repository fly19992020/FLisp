#include <iostream>
#include "type.h"


int main()
{
	Flisp_Value x;
	std::string n = "testing";
	x.set_value_as_a_name(n);
	std::string v;
	x.get_value(v);
	std::cout << v;
	return 0;
}

