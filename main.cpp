#include <iostream>
#include <fstream>
#include "src/constants.h"
#include "src/matrix.h"
#include "src/search_algorithms.h"


void useLinearSearchWithABarrier(char** matrix, int n) {
    using namespace std;

    int index;
    char* column;
    char key[2];
    cout << "Введите ключ для линейного поиска с барьером (один символ): ";
    cin.getline(key, 2);
    cout << "Введен символ: " << key[0] << endl;

    for (int i = 0; i < n; ++i) {
        column = getColumn(matrix, n, i);
        index = findUsingLinearSearchWithABarrier(column, n, key[0]);
        cout << i + 1 << " столбец: ";
        if (index == -1) {
            cout << "не найдено" << endl;
        } else {
            cout << index + 1 << endl;
        }
        delete[] column;
    }
}

void useInterpolationSearch(char** matrix, int n) {
    using namespace std;

    int index;
    char* column;
    char key[2];
    cout << "Введите ключ для интерполяционного поиска (один символ): ";
    cin.getline(key, 2);
    cout << "Введен символ: " << key[0] << endl;

    for (int i = 0; i < n; ++i) {
        column = getColumn(matrix, n, i);
        index = findUsingInterpolationSearch(column, n, key[0]);
        cout << i + 1 << " столбец: ";
        if (index == -2) {
            cout << "вектор не отсортирован" << endl;
        } else if (index == -1) {
            cout << "не найдено" << endl;
        } else {
            cout << index + 1 << endl;
        }
        delete[] column;
    }
}

int main() {
    using namespace std;

    ifstream infile(INFILE_PATH);
    int n, responseCode;
    char** matrix = getMatrixFromFile(infile, n, responseCode);

    if (responseCode == matrix::SUCCESS) {
        cout << MATRIX_PARSED_SUCCESSFULLY << endl;
        useLinearSearchWithABarrier(matrix, n);
        cout << endl;
        useInterpolationSearch(matrix, n);
    } else if (responseCode == matrix::FILE_NOT_FOUND) {
        cout << FILE_NOT_FOUND_ERROR << endl;
    } else if (responseCode == matrix::FILE_IS_EMPTY) {
        cout << FILE_IS_EMPTY_ERROR << endl;
    } else if (responseCode == matrix::UNPARSEABLE) {
        cout << UNPARSEABLE_ERROR << endl;
    } else if (responseCode == matrix::NOT_A_QUADRATIC_MATRIX) {
        cout << NOT_A_QUADRATIC_MATRIX_ERROR << endl;
    } else {
        cout << WRONG_ELEMENT_ERROR << endl;
    }

    infile.close();
    deleteMatrix(matrix, n);
}