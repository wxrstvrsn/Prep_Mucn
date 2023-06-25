//
// Created by wxrstvrsn on 25.06.2023.
//
#include <string>
#include <iostream>
#include <random>

class Person {
public:
    Person(const std::string &_name, int _age, int _shootingExperience);
    virtual bool Shoot() const = 0;

    friend std::ostream &operator<<(std::ostream &out, const Person &person);

protected:
    int age;
    int shootingExperience;
    std::string name;
};

class Novice : public Person{

public:
    Novice(const std::string &_name, int _age, int _shootingExperience);

    bool Shoot() const override;
};

class Experienced : public Person {

    bool Shoot() const override;

public:
    Experienced(const std::string &_name, int _age, int _shootingExperience);
};

class Veteran : public Person {

    bool Shoot() const override;

public:
    Veteran(const std::string &_name, int _age, int _shootingExperience);
};