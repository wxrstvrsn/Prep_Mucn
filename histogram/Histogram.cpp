//
// Created by wxrstvrsn on 25.06.2023.
//

#include "Histogram.h"

Histogram::Histogram(const std::vector<int> &values, int numIntervals) : intervals(numIntervals, 0) {
    if (values.empty()) {
        throw std::invalid_argument("Empty values array");
    }
    if (numIntervals <= 0) {
        throw std::invalid_argument("Invalid number of intervals");
    }

    int minValue = *std::min_element(values.begin(), values.end());
    int maxValue = *std::max_element(values.begin(), values.end());
    // Ищем минимальный и максимальный элемент в векторе значений

                        //Находим длину интервала как конец - начало + 1
        // Вычисляем длину каждого интервала -- делим разброс всех значений на заданное число интервалов
    int intervalSize = (maxValue - minValue + 1) / numIntervals;

    for (int value: values) {
        int intervalIndex = (value - minValue) / intervalSize;
        // Находим индекс элемента (к какому интервалу он относится по счету) -- получаем относительное положение значения в диапазоне

//        Например, если минимальное значение диапазона равно 0, максимальное значение равно 100,
//        и количество интервалов равно 5, то размер каждого интервала будет 20. Значения в
//        диапазоне [0, 20) попадут в интервал с индексом 0, значения в диапазоне
//        [20, 40) попадут в интервал с индексом 1, и так далее.


        if (intervalIndex >= 0 && intervalIndex < numIntervals) {
            ++intervals[intervalIndex];
        }
    }
}

std::ostream &operator<<(std::ostream &out, const Histogram &histogram) {
    char barSymbol = '+'; // Символ для представления значения в гистограмме

    for (int count : histogram.intervals) {
        std::string bar(count, barSymbol);
        out << ":" <<bar << '\n';
    }

    return out;
}
