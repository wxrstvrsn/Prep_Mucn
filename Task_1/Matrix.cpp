//
// Created by wxrstvrsn on 24.06.2023.
//

#include "Matrix.h"

Matrix::Matrix(int _rows, int _cols) : rows(_rows), cols(_cols) {}

Matrix::Matrix(const std::string &filename) {
    cols = 0;
    rows = 0;
    std::fstream fs;

    fs.open(filename, std::fstream::in);
    if (!fs.is_open()) {
        throw std::runtime_error("Could not open");
    }

    std::string line;
    std::string cell;

    while (getline(fs, line)) {
        std::stringstream stream(line);

        while (getline(stream, cell, ',')) {
            try {
                int value = std::stoi(cell);
                data.push_back(value);
            } catch (const std::exception &e) {
                throw std::runtime_error("Incompatible conversion to integer. Incorrect data in file");
            }
        }
        ++rows;
        if (cols == 0) {
            cols = data.size();
        } else {
            try {
                this->checkSize();
            } catch (const std::exception &e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
    std::cout << rows << " " << cols << std::endl;
    fs.close();
}

void Matrix::checkSize() {
    if (data.size() % cols != 0) {
        throw std::runtime_error("Incorrect matrix size");
    }
}

Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols), data(other.data) {}

Matrix &Matrix::operator=(const Matrix &other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data;

        other.rows = 0;
        other.cols = 0;
        other.data.clear();
    }

    return *this;

}

Matrix &Matrix::operator+(const Matrix &other) {
    try {
        this->checkSizeAddiction(other);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    for (int i = 0; i < data.size(); ++i) {
        data[i] += other.data[i];
    }

    return *this;
}

void Matrix::checkSizeAddiction(const Matrix &other) {
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::runtime_error("Matrices have different sizes, addition is not allowed");
    }
}

Matrix &Matrix::operator*(const Matrix &other) {
    try {
        this->checkSizeMultiply(other);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Matrix result(rows, other.cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            int sum = 0;
            for (int k = 0; k < cols; ++k) {
                sum += data[i * cols + k] * other.data[k * other.cols + j];
//                std::cout << data[i * cols + k] << " " << other.data[k * other.cols + j] << std::endl;
            }
//            std::cout << "SUM: " << sum << std::endl;

            result.data.push_back(sum);
        }
    }

    *this = result;

    return *this;

}

void Matrix::checkSizeMultiply(const Matrix &other) {

//    std::cout << "CHECKING FOR *: " + std::to_string(this->rows) + " " +  std::to_string(other.cols) << std::endl;
    if (this->rows != other.cols) {
        throw std::runtime_error("Matrices have is not allowed size for multiplication");
    }
}

std::ostream &operator<<(std::ostream &out, const Matrix &object) {
    for (int i = 0; i < object.data.size(); ++i) {
        out << object.data[i] << " ";
        if ((i + 1) % object.cols == 0) {
            out << "\n";
        }
    }
    out << "\n\n";
    return out;
}



