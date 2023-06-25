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

    int intervalSize = (maxValue - minValue + 1) / numIntervals;

    for (int value: values) {
        int intervalIndex = (value - minValue) / intervalSize;
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
