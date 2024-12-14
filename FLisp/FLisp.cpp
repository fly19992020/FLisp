#include <iostream>
#include "type.h"


int main()
{
	Flisp_Value x;
	x.set_value(1000);
	int v;
	x.get_value(&v);
	std::cout << v;
	return 0;
}

