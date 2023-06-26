//
// Created by wxrstvrsn on 26.06.2023.
//

#include "SteelSheet.h"

SteelSheet::SteelSheet(const double &_thickness) : thickness(_thickness) {}

double SteelSheet::getWeight(const double &density) {
    return Square() * density * thickness;
}

Triangle::Triangle(const double &_thickness, const double &_sideA, const double &_sideB) : SteelSheet(_thickness),
                                                                                           sideA(_sideA),
                                                                                           sideB(_sideB) {}

double Triangle::Square() const {
    return 0.5 * sideA * sideB;
}

Rectangle::Rectangle(const double &_thickness, const double &_sideA, const double &_sideB) : SteelSheet(_thickness),
                                                                                             sideA(_sideA),
                                                                                             sideB(_sideB) {}

double Rectangle::Square() const {
    return sideA * sideB;
}

SquareSheet::SquareSheet(const double &_thickness, const double &_sideLength) : SteelSheet(_thickness),
                                                                                sideLength(_sideLength) {}

double SquareSheet::Square() const {
    return sideLength * sideLength;
}
