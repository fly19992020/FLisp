#include <iostream>
#include "type.h"


int main()
{
	Flisp_Value x;
	std::string s = "poi";
	x.set_value(s);
	std::string vs;
	x.get_value(vs);
	std::cout << vs;
	return 0;
}

