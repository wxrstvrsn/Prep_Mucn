#include <iostream>
#include "PassOrDie.h"

 int main() {
     std::vector<Student*> students;

     students.emplace_back(new RegularStudent("John Smith", 10));
     students.emplace_back(new SmartStudent("Alice Johnson", 6));
     students.emplace_back(new GeniusStudent("Michael Brown", 0));

     std::cout << sizeof(RegularStudent) << " == " << sizeof(SmartStudent) << " == " << sizeof(GeniusStudent) << " == " << sizeof(Student) << std::endl;
//
//     for (const auto& student : students) {
//         std::cout << *student;
//         if (student->passExam())
//             std::cout << "Passed the exam" << std::endl;
//         else
//             std::cout << "Failed the exam" << std::endl;
//
//         std::cout << "-----------------------" << std::endl;
//     }

     // Освобождаем память
     for (const auto& student : students) {
         delete student;
     }

     return 0;
 }
//
//#include <iostream>
//
//using namespace std;
//
//template<typename T>
//void fun(const T &x) {
//    static int count = 0;
//    cout << "x = " << x << " count = " << count << endl;
//    ++count;
//    return;
//}
//
//int main() {
//    fun<int>(1);
//    fun<int>(1);
//    fun<double>(1.1);
//    return 0;
//}