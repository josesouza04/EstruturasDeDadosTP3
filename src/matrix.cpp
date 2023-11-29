// Matrix implementation
#include "../include/matrix.hpp"

Matrix::Matrix() {
    numLines = 0;
    numColumns = 0;
    matrix = nullptr;
}

Matrix::Matrix(int numLines_, int numColumns_) {
    numLines = numLines_;
    numColumns = numColumns_;
    matrix = new int*[numLines];
    for (int i = 0; i < numLines; i++) {
        matrix[i] = new int[numColumns];
    }
    for (int i = 0; i < numLines; i++) {
        for (int j = 0; j < numColumns; j++) {
            if (i == j) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < numLines; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matrix::update(int line_, int column_, int value_) {
    matrix[line_][column_] = value_;
}

Matrix Matrix::multiply(Matrix matrixA_, Matrix matrixB_) {
    Matrix result = Matrix(2, 2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.update(i, j, 0);
            for (int k = 0; k < 2; k++) {
                result.update(i, j, result.getElement(i, j) + matrixA_.getElement(i, k) * matrixB_.getElement(k, j));
            }
        }
    }
    return result;
}

void Matrix::print() {
    for (int i = 0; i < numLines; i++) {
        for (int j = 0; j < numColumns; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Path: src/matrix.cpp