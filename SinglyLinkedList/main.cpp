#include <iostream>
#include "LinkedList.h"

int main() {
    try {
        LinkedList<int> list1;
        list1.add(3);
        list1.add(2);
        list1.add(1);

        std::cout << list1 << std::endl;

        LinkedList<int> list2;
        list2.add(6);
        list2.add(5);
        list2.add(4);

        std::cout << list2.isEmpty() << std::endl;
        std::cout << list2 << std::endl;

        list1 += list2;

        std::cout << "-------------------------" << std::endl;
        std::cout << list1 << std::endl;

        list2.clear();


        return 0;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
