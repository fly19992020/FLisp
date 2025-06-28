#pragma once
#include "type.h"
#include "list_spliting.h"
#include <iostream>
#include <map>

extern std::map<std::string, Flisp_Func> Flisp_functions;
[[deprecated]]Flisp_Value Flisp_eval(Flisp_Value v);
[[deprecated]]Flisp_Value Flisp_running(const std::string& s);
