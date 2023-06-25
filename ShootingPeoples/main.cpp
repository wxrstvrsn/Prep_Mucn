#include <iostream>
#include "SimulateShooting.h"

void simulateShooting(std::vector<Person *> &shooters) {
    bool hit = false;
    for (const auto &person: shooters) {
        std::cout << "Person: " << *person << std::endl;
        hit = person->Shoot();
        std::cout << "Shoot: " << (hit ? "Hit" : "Miss") << std::endl;
        if (hit || shooters.size() == 1) {
            break;
        }
    }
}

int main() {
    Novice novice("John", 25, 2);
    Experienced experienced("Alice", 30, 5);
    Veteran veteran("Mike", 45, 20);

    std::vector<Person *> people = {&novice, &experienced, &veteran};

    simulateShooting(people);


    return 0;
}
