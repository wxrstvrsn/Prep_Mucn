//
// Created by wxrstvrsn on 25.06.2023.
//
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


template<typename T>
class MatrixTemplate {
public:
    //! Default constructor
    MatrixTemplate();

    //! Constructs a Matrix
    MatrixTemplate(int _rows = 0, int _cols = 0);

    //! Copy constructor
    MatrixTemplate(const MatrixTemplate &other);

    //! Copy assignment operator
    MatrixTemplate<T> &
    operator=(const MatrixTemplate &other); // ВАЖНО: указывать как возвращаемое значение Матрицу и шаблоном
    // MatrixTemplate<T>

    //! Move constructor
    MatrixTemplate(MatrixTemplate &&other);

    //!Move assignment operator
    MatrixTemplate<T> &
    operator=(MatrixTemplate &&other); // ВАЖНО: указывать как возвращаемое значение Матрицу и шаблоном
    // MatrixTemplate<T>

    //! Addition operator
    MatrixTemplate &operator+(const MatrixTemplate &other);

    //! Index operator
    std::vector<T> &operator()(const int i, const int j);

    //! Equivalent operator
    bool operator==(const MatrixTemplate &other);

    //! notEquivalent operator
    bool operator!=(const MatrixTemplate &other);

    //! Fill entire matrix with given value
    void fillEntire(const T &value);

    //!Fill row-by-row

    //! Fill elem-by-elem
    void fillElemByElem();

    //! Transpose matrix
    void transpose();

    //! Fill row with given values
    void fillByRow();

    //! Print function
    friend std::ostream &operator<<(std::ostream &out, const MatrixTemplate &matrix) {
        std::string dashes(matrix.cols, '-');
        std::cout << dashes << std::endl;

        for (int i = 0; i < matrix.data.size(); ++i) {
            out << matrix.data[i] << " ";
            if ((i + 1) % matrix.cols == 0) {
                out << "\n";
            }
        }
        out << "\n";
        return out;
    };

    //! Fill row


    //! Checking sizes for addition
    void checkDimensions(const MatrixTemplate &other);

private:
    int rows;
    int cols;
    std::vector<T> data;
};

template<typename T>
MatrixTemplate<T>::MatrixTemplate() : rows(0),
                                      cols(0) {} // ВАЖНО: указывать как возвращаемое значение Матрицу и шаблоном
// MatrixTemplate<T>

template<typename T>
MatrixTemplate<T>::MatrixTemplate(const MatrixTemplate &other) : rows(other.rows), cols(other.cols),
                                                                 data(other.data) {} // ВАЖНО: указывать как возвращаемое значение Матрицу и шаблоном
// MatrixTemplate<T>

template<typename T>
MatrixTemplate<T>::MatrixTemplate(int _rows, int _cols) : rows(_rows),
                                                          cols(_cols) { // ВАЖНО: указывать как возвращаемое значение Матрицу и шаблоном
    // MatrixTemplate<T>
    data.resize(rows * cols);
}

template<typename T>
MatrixTemplate<T> &MatrixTemplate<T>::operator=(
        const MatrixTemplate &other) { // ВАЖНО: указывать как возвращаемое значение Матрицу и шаблоном
    // MatrixTemplate<T>
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
    }

    return *this;
}

template<typename T>
MatrixTemplate<T>::MatrixTemplate(MatrixTemplate &&other)  : rows(other.rows),
                                                             cols(other.cols), // ВАЖНО: указывать как возвращаемое значение Матрицу и шаблоном
        // MatrixTemplate<T>
                                                             data(std::move(other.data)) {}

template<typename T>
MatrixTemplate<T> &
MatrixTemplate<T>::operator=(MatrixTemplate &&other) { // ВАЖНО: указывать как возвращаемое значение Матрицу и шаблоном
    // MatrixTemplate<T>
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = std::move(other.data);
        other.rows = 0;
        other.cols = 0;
    }

    return *this;
}

template<typename T>
MatrixTemplate<T> &MatrixTemplate<T>::operator+(
        const MatrixTemplate &other) { // ВАЖНО: указывать как возвращаемое значение Матрицу и шаблоном
    // MatrixTemplate<T>
    checkDimensions(other);
    for (int i = 0; i < data.size(); ++i) {
        data[i] += other.data[i];
    }
    return *this;
}

template<typename T>
void MatrixTemplate<T>::checkDimensions(
        const MatrixTemplate &other) { // ВАЖНО: указывать как возвращаемое значение Матрицу и шаблоном
    // MatrixTemplate<T>
    if (rows != other.rows || cols != other.cols) {
        throw std::runtime_error("Incorrect dimensions, addition is not available");
    }
}

template<typename T>
bool MatrixTemplate<T>::operator==(
        const MatrixTemplate &other) { // ВАЖНО: указывать как возвращаемое значение Матрицу и шаблоном
    // MatrixTemplate<T>
    return rows == other.rows && cols == other.cols && data = other.data;
}

template<typename T>
bool MatrixTemplate<T>::operator!=(
        const MatrixTemplate &other) { // ВАЖНО: указывать как возвращаемое значение Матрицу и шаблоном
    // MatrixTemplate<T>
    return (!*this == other);
}

template<typename T>
void MatrixTemplate<T>::fillEntire(const T &value) { // ВАЖНО: указывать как возвращаемое значение Матрицу и шаблоном
    // MatrixTemplate<T>
    for (int i = 0; i < data.size(); ++i) {
        data[i] = value;
    }
}

template<typename T>
std::vector<T> &MatrixTemplate<T>::operator()(const int i, const int j) {
    return data[i * cols + j];
}

template<typename T>
void MatrixTemplate<T>::fillElemByElem() {
    int j = 0;
    for (int i = 0; i < data.size(); ++i) {
        std::cout << " (i, j): (" << (j + 1) << ", " << (i % cols + 1) << ") : ";
        if ((i + 1) % cols == 0 && i != 0) {
            ++j;
        }
        T value;
        std::cin >> value;
        if (!std::cin) {
            throw std::runtime_error("Given incorrect data");
        }
        data[i] = value;
    }
}

template<typename T>
void MatrixTemplate<T>::transpose() {
    std::vector<T> transposedData(cols *rows);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int originalIndex = i * cols + j;

            int transposedIndex = j * rows + i;

            transposedData[transposedIndex] = data[originalIndex];
        }
    }

    data = transposedData;

    std::swap(rows, cols);
}

template<typename T>
void MatrixTemplate<T>::fillByRow() {
    for (int j = 0; j < rows; ++j) {
        for (int i = 0; i < cols; ++i) {
            std::cout << " (i, j): " << "(" << j << ", " << i << "): ";
            T value;
            std::cin >> value;
            if(!std::cin) {
                throw std::runtime_error("Given incorrect data");
            }
            data[j * cols + i] = value;
        }
    }
}




