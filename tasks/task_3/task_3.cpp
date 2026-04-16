#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <windows.h>

using namespace std;

int** createMatrix(int n) {
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    return matrix;
}

void deleteMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void fillMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 87 - 43;
        }
    }
}

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

int countEvenInSector4(int** matrix, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j && i + j > n - 1) {
                if (matrix[i][j] % 2 == 0) count++;
            }
        }
    }
    return count;
}

int findValueWithMaxAbs(int** matrix, int n) {
    int valueWithMaxAbs = matrix[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(matrix[i][j]) > abs(valueWithMaxAbs)) {
                valueWithMaxAbs = matrix[i][j];
            }
        }
    }
    return valueWithMaxAbs;
}

int processSector7(int** matrix, int n, int maxAbs) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i) {
                count++;
                matrix[i][j] = maxAbs;
            }
        }
    }
    return count;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(0));

    int n;
    cout << "Введіть розмір квадратної матриці n: ";
    cin >> n;

    if (n <= 0) return 0;

    int** matrix = createMatrix(n);
    fillMatrix(matrix, n);

    cout << "\nПочаткова матриця:" << endl;
    printMatrix(matrix, n);

    int evenCount = countEvenInSector4(matrix, n);
    cout << "\nКількість парних елементів у секторі 4: " << evenCount << endl;

    int maxAbsVal = findValueWithMaxAbs(matrix, n);
    int sector7Count = processSector7(matrix, n, maxAbsVal);

    cout << "Максимальне значення по модулю в матриці: " << maxAbsVal << endl;
    cout << "Кількість елементів у секторі 7: " << sector7Count << endl;

    cout << "\nМатриця після заміни в секторі 7:" << endl;
    printMatrix(matrix, n);

    deleteMatrix(matrix, n);
    return 0;
}