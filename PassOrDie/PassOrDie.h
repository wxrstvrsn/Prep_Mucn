//
// Created by wxrstvrsn on 26.06.2023.
//

#pragma once

#include <iostream>
#include <string>
#include <random>
#include <vector>

class Student {
protected:
    std::string fullName;
    int attendanceCount;
    static int practiceCount;

public:
    Student(const std::string &name, int attendance)
            : fullName(name), attendanceCount(attendance) {}

    virtual bool passExam() const = 0;

    friend std::ostream &operator<<(std::ostream &os, const Student &student) {
        os << "Student: " << student.fullName << std::endl;
        os << "Attendance: " << student.attendanceCount << std::endl;
        return os;
    }
};

int Student::practiceCount = 18;

class RegularStudent : public Student {
public:
    RegularStudent(const std::string &name, int attendance)
            : Student(name, attendance) {}

    bool passExam() const override {
        if (attendanceCount < practiceCount / 2) {
            std::cout << "LAZY FOOL\n";
            return false;
        } else {
            std::cout << "RANDOM\n";
            std::random_device seed;
            std::default_random_engine rng(seed());
            std::uniform_real_distribution<double> dist(0.0, 1.0);
            return dist(rng) <= 0.5;
        }
    }
};

class SmartStudent : public Student {
public:
    SmartStudent(const std::string &name, int attendance)
            : Student(name, attendance) {}

    bool passExam() const override {
        if (attendanceCount < practiceCount / 2) {
            std::cout << "LAZY FOOL\n";
            return false;
        } else {
            std::cout << "RANDOM\n";
            std::random_device seed;
            std::default_random_engine rng(seed());
            std::uniform_real_distribution<double> dist(0.0, 1.0);
            return dist(rng) <= 1;
        }
    }

};

class GeniusStudent : public Student {
public:
    GeniusStudent(const std::string &name, int attendance)
            : Student(name, attendance) {}

    bool passExam() const override {
        return attendanceCount > 0;
    }
};

