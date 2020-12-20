#include <fstream>
#include <exception>
#include "matrix.h"


int getRows(std::ifstream& file) {
    std::string line;
    int rows = 0;
    file.clear();
    file.seekg(0);
    while (!file.eof()) {
        getline(file, line);
        ++rows;
    }
    file.clear();
    file.seekg(0);
    return rows;
}

int getColumns(std::string& row) {
    int columns = 0;
    int index = 0;
    int carriage = int(row.find(' ', index));
    int rowLength = int(row.length());
    while (carriage > 0) {
        if (carriage - index > 0) {
            ++columns;
        }
        index = carriage + 1;
        carriage = int(row.find(' ', index));
        if (index < rowLength && carriage == -1) {
            ++columns;
        }
    }
    return columns;
}

bool fillRowWithElements(char** matrix, std::string& row, int rowIndex, int n) {
    int rowLength = row.length();
    int column = 0;
    int index = 0;
    int carriage = int(row.find(' ', index));
    std::string number;
    while (carriage > 0) {
        if (carriage - index > 0) {
            number = row.substr(index, carriage);
            try {
                matrix[rowIndex][column] = char(std::stoi(number));
                ++column;
            } catch (std::logic_error e) {
                return false;
            }
        }
        index = carriage + 1;
        carriage = int(row.find(' ', index));
        if (index < rowLength && carriage == -1) {
            number = row.substr(index, rowLength);
            try {
                matrix[rowIndex][column] = char(std::stoi(number));
                ++column;
            } catch (std::logic_error e) {
                return false;
            }
        }
    }
    return true;
}

void deleteMatrix(char** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

char** getNewMatrix(int n) {
    char** matrix = new char*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new char[i]{};
    }
    return matrix;
}

char** getMatrixFromFile(std::ifstream& file, int& n, int& responseCode) {
    n = 0;
    if (file.is_open()) {
        file.seekg(0, std::ios::end);
        if (file.tellg() == 0) {
            responseCode = matrix::FILE_IS_EMPTY;
            return new char*;
        }
        file.clear();
        file.seekg(0);

        std::string line;
        int rowIndex = 0;
        int rows = getRows(file);
        int columns;
        char** matrix = getNewMatrix(rows);

        while (!file.eof()) {
            getline(file, line);
            if (int(line.find('\r')) > -1) {
                line.erase(line.length() - 1);
            }
            columns = getColumns(line);
            if (columns == -1) {
                responseCode = matrix::UNPARSEABLE;
                deleteMatrix(matrix, rows);
                return new char*;
            } else if (rows != columns) {
                responseCode = matrix::NOT_A_QUADRATIC_MATRIX;
                deleteMatrix(matrix, rows);
                return new char*;
            } else if (!fillRowWithElements(matrix, line, rowIndex, rows)) {
                responseCode = matrix::WRONG_ELEMENT;
                deleteMatrix(matrix, rows);
                return new char*;
            }
            ++rowIndex;
        }
        file.clear();
        file.seekg(0);

        n = rows;
        responseCode = matrix::SUCCESS;
        return matrix;
    } else {
        responseCode = matrix::FILE_NOT_FOUND;
        return new char*;
    }
}

char* getColumn(char** matrix, int n, int columnIndex) {
    char* column = new char[n];
    for (int i = 0; i < n; ++i) {
        column[i] = matrix[i][columnIndex];
    }
    return column;
}