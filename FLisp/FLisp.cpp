#include <iostream>
#include "type.h"
#include "list_spliting.h"


int main()
{
	Flisp_Value x;
	x.set_value(5);
	std::cout << (int)x << std::endl;
	return 0;
}
