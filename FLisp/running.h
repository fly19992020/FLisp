#pragma once
#include "type.h"
#include "list_spliting.h"
#include <iostream>


Flisp_Value Flisp_eval(Flisp_Value v);
Flisp_Value Flisp_running(std::string s);
