#include <iostream>
#include "type.h"
#include "list_spliting.h"
#include "running.h"
#include "vm.h"


int main()
{
	Flisp_Value x;
	// Flisp_functions["print"].set_func([](std::list<Flisp_Value> args_list) {
	// 	for (auto i = args_list.begin(); i != args_list.end(); i++) {
	// 		std::string s;
	// 		i->get_value(s);
	// 		std::cout << s << " ";
	// 	}
	// 	std::cout << std::endl;
	// 	return Flisp_Value();
	// 	});
	// Flisp_running("(print \"Hello, world!\")");
	// Flisp_VM vm = Flisp_VM();
	// Flisp_Func f = Flisp_Func();
	// f.set_func([](std::list<Flisp_Value> args_list) {
	// 	for (auto & i : args_list) {
	// 		std::string s;
	// 		i.get_value(s);
	// 		std::cout << s << " ";
	// 	}
	// 	std::cout << std::endl;
	// 	return Flisp_Value();
	// });
	// vm.add_function("print", f);
	// vm.running("(print \"Hello, world!\")");
	// return 0;
}
