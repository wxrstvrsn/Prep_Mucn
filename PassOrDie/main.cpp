 #include <iostream>
#include "PassOrDie.h"

 int main() {
     std::vector<Student*> students;

     students.emplace_back(new RegularStudent("John Smith", 10));
     students.emplace_back(new SmartStudent("Alice Johnson", 6));
     students.emplace_back(new GeniusStudent("Michael Brown", 0));

     for (const auto& student : students) {
         std::cout << *student;
         if (student->passExam())
             std::cout << "Passed the exam" << std::endl;
         else
             std::cout << "Failed the exam" << std::endl;

         std::cout << "-----------------------" << std::endl;
     }

     // Освобождаем память
     for (const auto& student : students) {
         delete student;
     }

     return 0;
 }
