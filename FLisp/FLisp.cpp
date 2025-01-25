#include <iostream>
#include "type.h"
#include "list_spliting.h"


int main()
{
	Flisp_Value x;
	std::string n = "(a 10 sdjah)";
	Flisp_Value l = Flisp_List_Spliting(n);
	std::list<Flisp_Value> v;
	l.get_value(v);
	std::list<Flisp_Value> v2;
	v.begin()->get_value(v2);
	std::string v3;
	v2.begin()->get_value(v3);
	std::cout << v3;
	return 0;
}
