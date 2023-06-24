//
// Created by wxrstvrsn on 24.06.2023.
//

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#pragma once

class Matrix {
public:
    //! Default constructor
    Matrix(int _rows = 0, int _cols = 0);

    //! Constructor from Csv-file
    Matrix(const std::string &filename);

    //! Copy constructor
    Matrix(const Matrix &other);

    //! Copy assignment
    Matrix &operator=(const Matrix &other);

    //! Move constructor
    Matrix &operator=(Matrix &&other);

    //! Addiction operator
    Matrix &operator+(const Matrix &other);

    //! Multiply operator
    Matrix &operator*(const Matrix &other);

    //! Print function
    friend std::ostream &operator<<(std::ostream &out, const Matrix &object);


    //! Check size when initialize
    void checkSize();

    //! Check size when addiction
    void checkSizeAddiction(const Matrix &other);

    //! Check size when multiply
    void checkSizeMultiply(const Matrix &other);

private:
    int rows;
    int cols;
    std::vector<int> data;
};

