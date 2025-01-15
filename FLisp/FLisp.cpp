#include <iostream>
#include "type.h"
#include "list_spliting.h"


int main()
{
	Flisp_Value x;
	std::string n = "testing";
	Flisp_Value l = Flisp_List_Spliting(n);
	return 0;
}

