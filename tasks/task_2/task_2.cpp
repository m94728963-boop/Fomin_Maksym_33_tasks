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

double calculateDeviation(const vector<double>& arr, double mean) {
    double n = arr.size();
    double sumSq = 0;
    for (double val : arr) {
        sumSq += (val * val);
    }
    return sqrt((1.0 / (n - 1.0)) * sumSq - (n / (n - 1.0)) * (mean * mean));
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    vector<double> X = { 20, 11, 10, 19, 22, 23, 11, 18, 14, 25 };

    double mean = calculateMean(X);
    double deviation = calculateDeviation(X, mean);

    cout << "Середнє значення (x_cp): " << mean << endl;
    cout << "Середньоквадратичне відхилення (y): " << deviation << endl;

    return 0;
}