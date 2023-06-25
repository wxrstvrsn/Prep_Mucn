//
// Created by wxrstvrsn on 25.06.2023.
//

#include "SimulateShooting.h"

Person::Person(const std::string &_name, int _age, int _shootingExperience) : name(_name), age(_age),
                                                                              shootingExperience(_shootingExperience) {}

std::ostream &operator<<(std::ostream &out, const Person &person) {
    out << "Name: " << person.name << ", Age: " << person.age << ", Shooting Experience: " << person.shootingExperience;
    return out;
}

Novice::Novice(const std::string &_name, int _age, int _shootingExperience) :
        Person(_name, _age, _shootingExperience) {}

bool Novice::Shoot() const {
    double probability = 0.01 * shootingExperience;
    std::random_device rd; // создали объект для получения случайного seed'a
    std::default_random_engine rng(rd()); // создали генератор rng, проинициализировав его случайным seed'ом
    std::uniform_real_distribution<double> dist(0.0, 1.0); // указали диапазон генерации случайных чисел
    return dist(rng) <=
           probability; // если случайно сгенерированное число меньше вероятности попадания для объекта Person, то вернем true
}

Experienced::Experienced(const std::string &_name, int _age, int _shootingExperience) :
        Person(_name, _age, _shootingExperience) {}

bool Experienced::Shoot() const {
    double probability = 0.05 * shootingExperience;
    std::random_device rd; // создали объект для получения случайного seed'a
    std::default_random_engine rng(rd()); // создали генератор rng, проинициализировав его случайным seed'ом
    std::uniform_real_distribution<double> dist(0.0, 1.0); // указали диапазон генерации случайных чисел
    return dist(rng) <=
           probability; // если случайно сгенерированное число меньше вероятности попадания для объекта Person, то вернем true
}


Veteran::Veteran(const std::string &_name, int _age, int _shootingExperience) :
        Person(_name, _age, _shootingExperience) {}

bool Veteran::Shoot() const {
    double probability = 0.9 - (0.01 * age);
    std::random_device rd; // создали объект для получения случайного seed'a
    std::default_random_engine rng(rd()); // создали генератор rng, проинициализировав его случайным seed'ом
    std::uniform_real_distribution<double> dist(0.0, 1.0); // указали диапазон генерации случайных чисел
    return dist(rng) <=
           probability; // если случайно сгенерированное число меньше вероятности попадания для объекта Person, то вернем true
}
