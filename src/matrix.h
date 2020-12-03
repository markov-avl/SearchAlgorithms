#include <fstream>

#ifndef SORTS_MATRIX_H
#define SORTS_MATRIX_H

void deleteMatrix(char** matrix, int n);
char** getNewMatrix(int n);
char** getMatrixFromFile(std::ifstream& file, int& n, int& responseCode);
char* getColumn(char** matrix, int n, int columnIndex);

enum matrix {
    SUCCESS,
    FILE_NOT_FOUND,
    FILE_IS_EMPTY,
    UNPARSEABLE,
    NOT_A_QUADRATIC_MATRIX,
    WRONG_ELEMENT
};

#endif
