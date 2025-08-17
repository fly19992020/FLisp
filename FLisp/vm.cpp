/* vm.cpp
   The definition of the methods of VM class.
   A part of Flisp.
   (c) fly19992020 2024-2025
*/

#include "vm.h"

#include "error.h"
#include "list_spliting.h"

Flisp_Value Flisp_VM::eval(Flisp_Value v) {
    if (v.get_type() == FLISP_LIST) {
        std::list<Flisp_Value> l; // Extract the list from the value
        v.get_value(l); // Assuming v is a list type
        if (l.empty()) {
            return {};
        }
        std::string s;
        l.begin()->get_value(s);
        l.pop_front();
        if (s == "define") {
            this->add_variable(s, eval(l.front())); // If the first element is "define", add a variable
            return {}; // Return an empty value after defining a variable
        } else if (s == "quote") {
            return l.front(); // If the first element is "quote", return the first value in the list
        }
        if (this->functions.contains(s)) {
            return this->functions.find(s)->second.run(l, *this); // Run the function with the list of arguments
        } else if(this->global_variables.contains(s)) {
            if (this->global_variables[s].get_type() == FLISP_FUNC) {
                Flisp_Func f;
                this->global_variables[s].get_value(f);
                return f.run(l, *this); // Run the function stored in the variable
            }
        } else {
            Flisp_noise("function not found");
            return {}; // Return an empty value on error
        }
    }
}

Flisp_Value Flisp_VM::running(const std::string &s) {
    Flisp_Value list = Flisp_List_Spliting(s); // Split the string into a list of values
    std::list<Flisp_Value> commands = {}; // Create a list to hold the commands
    list.get_value(commands);
    Flisp_Value v;
    for (auto i : commands) {
        v = this->eval(i); // Evaluate each command in the list
    }
    Flisp_Value r = v;
    return r;
}

void Flisp_VM::add_function(const std::string &name, const Flisp_Func& func) {
    this->functions[name] = func; // Add the function to the map
}

void Flisp_VM::add_variable(const std::string &name, const Flisp_Value& value) {
    this->global_variables[name] = value; // Add the variable to the map
}
