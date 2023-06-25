//
// Created by wxrstvrsn on 25.06.2023.
//
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
/* Иной способ реализация перегруженного оператора вывода в шаблонном классе
 *
 * когда мы в классе пишем
 * friend  ostream& operator << (ostream &, const Matrix<T> &);
 *
 * То мы говорим ему, что есть некоторая функция, которая принимает шаблонный объект.
 * Но в данном случае Matrix<T> Никакой не шаблонный объект, а вполне конкретная реализация
 * Чтобы реализация всегда учитывала тип <T> нужно либо написать реализацию прямо в классе около определения
 * Либо вынести определение (реализацию) функции вывода перед классом
 * А поскольку мы вынесем ее раньше всего класса, то перед тем, как упоминать <T> в этой функции
 * надо сказать, что класс шаблонный (получается нечто похожее на статические методы)
 *
 * Перед определением функции вывода пишем:
 * template<typename T>
 * class NameClass;
 *
 * Потом с функцией:
 * template<typename T>
 * std::ostream &operator<<(std::ostream &out, const Matrix<T> &matrix); -- корректно вынесли определение общего шаблона*/
template<typename T>
class MatrixTemplate;


template<typename T>
std::ostream &operator<<(std::ostream &out, const MatrixTemplate<T> &matrix);

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
    MatrixTemplate<T> &operator=(const MatrixTemplate &other);

    //! Move constructor
    MatrixTemplate(MatrixTemplate &&other);

    //!Move assignment operator
    MatrixTemplate &operator=(MatrixTemplate &&other);

    //! Addition operator
    MatrixTemplate &operator+(const MatrixTemplate &other);

    //! Equivalent operator
    bool operator==(const MatrixTemplate &other);

    //! notEquivalent operator
    bool operator!=(const MatrixTemplate &other);

    //! Fill entire matrix with given value
    void fillEntire(const T &value);

    //! Fill row with given value

    //! Print function
    /* А сюда пихаем специализацию */
    friend std::ostream &operator<<<T>(std::ostream &out, const MatrixTemplate &matrix);

    //! Fill row


    //! Checking sizes for addition
    void checkDimensions(const MatrixTemplate &other);

private:
    int rows;
    int cols;
    std::vector<T> data;
};

template<typename T>
MatrixTemplate<T>::MatrixTemplate() : rows(0), cols(0) {}

template<typename T>
MatrixTemplate<T>::MatrixTemplate(const MatrixTemplate &other) : rows(other.rows), cols(other.cols), data(other.data) {}

template<typename T>
MatrixTemplate<T>::MatrixTemplate(int _rows, int _cols) : rows(_rows), cols(_cols) {
    data.resize(rows * cols);
}

template<typename T>
MatrixTemplate<T> &MatrixTemplate<T>::operator=(const MatrixTemplate &other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
    }

    return *this;
}

template<typename T>
MatrixTemplate<T>::MatrixTemplate(MatrixTemplate &&other)  : rows(other.rows), cols(other.cols),
                                                             data(std::move(other.data)) {}

template<typename T>
MatrixTemplate<T> &MatrixTemplate<T>::operator=(MatrixTemplate &&other) {
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
MatrixTemplate<T> &MatrixTemplate<T>::operator+(const MatrixTemplate &other) {
    checkDimensions(other);
    for (int i = 0; i < data.size(); ++i) {
        data[i] += other.data[i];
    }
    return *this;
}

template<typename T>
void MatrixTemplate<T>::checkDimensions(const MatrixTemplate &other) {
    if (rows != other.rows || cols != other.cols) {
        throw std::runtime_error("Incorrect dimensions, addition is not available");
    }
}

template<typename T>
bool MatrixTemplate<T>::operator==(const MatrixTemplate &other) {
    return rows == other.rows && cols == other.cols && data = other.data;
}

template<typename T>
bool MatrixTemplate<T>::operator!=(const MatrixTemplate &other) {
    return (!*this == other);
}

template<typename T>
void MatrixTemplate<T>::fillEntire(const T &value) {
    for(int i = 0; i < data.size(); ++i) {
        data[i] = value;
    }
}


template<typename T>
std::ostream &operator<<(std::ostream &out, const MatrixTemplate<T> &matrix)  {
    for (int i = 0; i < matrix.data.size(); ++i) {
        out << matrix.data[i] << " ";
        if ((i + 1) % matrix.cols == 0) {
            out << "\n";
        }
    }
    out << "\n";
}
