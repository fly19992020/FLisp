/* vm.h
   VMs in the Flisp_Value.
   A part of Flisp.
   (c) fly19992020 2024-2025
*/

#ifndef VM_H
#define VM_H
#include <map>
#include <iostream>
class Flisp_Func;
class Flisp_Value;
#include "type.h"

class Flisp_VM {
public:
    Flisp_Value eval(Flisp_Value v);
    Flisp_Value running(const std::string& s);
    void add_function(const std::string& name, const Flisp_Func& func);
    void add_variable(const std::string& name, const Flisp_Value& value);
protected:
    std::map<std::string, Flisp_Func> functions;
    std::map<std::string, Flisp_Value> global_variables; // Map to store variables
};

#endif //VM_H
