// Matrix header
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

class Matrix {
    public:
        Matrix();
        Matrix(int numLines_, int numColumns_);
        ~Matrix();
        
        void update(int line_, int column_, int value_);
        void print();
        int getElement(int line_, int column_) {return matrix[line_][column_];};
        Matrix multiply(Matrix matrixA_, Matrix matrixB_);

    private:
        int numLines;
        int numColumns;
        int **matrix;
};

#endif // MATRIX_HPP
// Path: include/matrix.hpp