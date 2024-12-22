#include <iostream>
#include "type.h"


int main()
{
	Flisp_Value x;
	std::string s = "poi";
	x.set_value(s);
	std::string vs;
	x.get_value(vs);
	std::cout << vs << std::endl;
	x.set_value(10);
	int vi = 0;
	x.get_value(vi);
	std::cout << vi << std::endl;
	return 0;
}

