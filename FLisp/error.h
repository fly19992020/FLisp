#pragma once

class Flisp_Error: public std::exception {
    [[nodiscard]] const char* what() const noexcept override;
};
// a function to noise error
void Flisp_noise(const char* message);
