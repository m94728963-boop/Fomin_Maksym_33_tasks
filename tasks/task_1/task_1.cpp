#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <future>
#include <algorithm>
#include <windows.h>

using namespace std;
using namespace std::chrono;

void generateArray(vector<int>& arr, int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);
    arr.clear();
    for (int i = 0; i < n; ++i) arr.push_back(dis(gen));
}

void printArray(const vector<int>& arr) {
    if (arr.size() > 60) return;
    for (int x : arr) cout << x << " ";
    cout << endl;
}
