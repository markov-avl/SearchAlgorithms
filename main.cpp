#include <iostream>
#include <fstream>
#include "src/constants.h"
#include "src/matrix.h"


int main() {
    using namespace std;

    ifstream infile(INFILE_PATH);
    int n, responseCode;
    char** matrix = getMatrixFromFile(infile, n, responseCode);

    if (responseCode == matrix::SUCCESS) {
        cout << "НОРМ" << endl;
    } else if (responseCode == matrix::FILE_NOT_FOUND) {
        cout << FILE_NOT_FOUND_ERROR << endl;
    } else if (responseCode == matrix::FILE_IS_EMPTY) {
        cout << FILE_IS_EMPTY_ERROR << endl;
    } else if (responseCode == matrix::UNPARSEABLE) {
        cout << UNPARSEABLE_ERROR << endl;
    } else if (responseCode == matrix::NOT_A_MATRIX) {
        cout << NOT_A_MATRIX_ERROR << endl;
    } else if (responseCode == matrix::NOT_A_QUADRATIC_MATRIX) {
        cout << NOT_A_QUADRATIC_MATRIX_ERROR << endl;
    } else {
        cout << WRONG_ELEMENT_ERROR << endl;
    }

    deleteMatrix(matrix, n);
}