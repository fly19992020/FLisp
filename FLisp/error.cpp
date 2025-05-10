#include <iostream>
#include "error.h"

const char *Flisp_Error::what() const noexcept {
	return "Flisp_Error";
}


// a function to noise error
void Flisp_noise(const char* message) {
	std::cout << message << " Program exit";
	throw(Flisp_Error());
}
