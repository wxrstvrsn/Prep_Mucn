//
// Created by wxrstvrsn on 25.06.2023.
//

#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class Histogram {
public:
    // Конструктор, принимающий массив значений и количество интервалов
    Histogram(const std::vector<int> &values, int numIntervals);

    // Конструктор по умолчанию
    Histogram() = default;

    // Конструкторы копирования и перемещения
    Histogram(const Histogram& other) = default;
    Histogram(Histogram&& other) noexcept = default;

    // Операторы копирующего и перемещающего присваивания
    Histogram& operator=(const Histogram& other) = default;
    Histogram& operator=(Histogram&& other) noexcept = default;

    // Оператор вставки в поток для вывода гистограммы
    friend std::ostream& operator<<(std::ostream& out, const Histogram& histogram);

private:
    std::vector<int> intervals;
};

