#include <fstream>

#ifndef SORTS_MATRIX_H
#define SORTS_MATRIX_H

void deleteMatrix(char** matrix, int n);
char** getNewMatrix(int n);
char** getMatrixFromFile(std::ifstream& file, int& n, int& responseCode);

enum matrix {
    SUCCESS,
    FILE_NOT_FOUND,
    FILE_IS_EMPTY,
    UNPARSEABLE,
    NOT_A_MATRIX,
    NOT_A_QUADRATIC_MATRIX,
    WRONG_ELEMENT
};

#endif
