#include <iostream>
#include "error.h"
#include <cstdlib>


// a function to noise error
void Flisp_noise(const char* message) {
	std::cout << message << " Program exit";
	std::exit(1);
}
