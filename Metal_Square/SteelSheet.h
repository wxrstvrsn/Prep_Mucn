//
// Created by wxrstvrsn on 26.06.2023.
//

#pragma once

class SteelSheet {
public:
    SteelSheet(const double &_thickness);

    //! Returns a square of object
    virtual double Square() const = 0;

    //! Returns a weight of object
    double getWeight(const double &density);

protected:
    double thickness;
};

class Triangle : public SteelSheet {
private:
    double sideA;
    double sideB;
public:
    Triangle(const double &_thickness, const double &_sideA, const double &_sideB);

    double Square() const override;
};

class Rectangle : public SteelSheet {
private:
    double sideA;
    double sideB;

public:
    Rectangle(const double &_thickness, const double &_sideA, const double &_sideB);

    double Square() const override;
};

class SquareSheet : public SteelSheet {
private:
    double sideLength;
public:
    SquareSheet(const double &_thickness, const double &_sideLength);

    double Square() const override;
};
