#include <iostream>
#include <vector>
#include <cmath>
#include <windows.h>

using namespace std;

double calculateMean(const vector<double>& arr) {
    double sum = 0;
    for (double val : arr) {
        sum += val;
    }
    return sum / arr.size();
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    vector<double> X = { 20, 11, 10, 19, 22, 23, 11, 18, 14, 25 };

    double mean = calculateMean(X);
    cout << "Середнє значення (x_cp): " << mean << endl;

    return 0;
}