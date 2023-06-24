#include <iostream>

#include "Matrix.h"

int main() {
    try {
        Matrix matrix1("C:\\Users\\79157\\CLionProjects\\Prep_Mucn\\Task_1\\matrix1.csv");
        Matrix matrix2("C:\\Users\\79157\\CLionProjects\\Prep_Mucn\\Task_1\\matrix2.csv");
        std::cout << matrix1 << std::endl;

        Matrix result;

        result = matrix1 * matrix2;
        std::cout << result << std::endl;

    } catch (const std::exception &e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    }

    return 0;
}
