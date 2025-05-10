#include <iostream>
#include "type.h"
#include "list_spliting.h"
#include "running.h"


int main()
{
	Flisp_Value x;
	Flisp_functions["print"].set_func([](std::list<Flisp_Value> args_list) {
		for (auto i = args_list.begin(); i != args_list.end(); i++) {
			std::string s;
			i->get_value(s);
			std::cout << s << " ";
		}
		std::cout << std::endl;
		return Flisp_Value();
		});
	Flisp_running("(print \"Hello, world!\")");
	return 0;
}
