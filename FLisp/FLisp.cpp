#include "FLisp.h"
#include "num.h"
#include "type.h"
#include "list_split.h"


int main()
{
	Flisp_list opt;
	Flisp_Name name_i;
	opt = Flisp_list_from_String("a a a a");
	for (auto i = opt.list.begin(); i != opt.list.end(); i++) {
		name_i = (Flisp_Name)*i;
		std::cout << name_i.name << "+1";
	}
	return 0;
}

