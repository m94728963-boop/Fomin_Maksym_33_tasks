#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <future>
#include <windows.h> 

using namespace std;
using namespace std::chrono;

void printArray(const vector<int>& arr);
void generateArray(vector<int>& arr, int n);
void bubbleSort(vector<int>& arr);
void selectionSort(vector<int>& arr);
int partition(vector<int>& arr, int low, int high);
void quickSort(vector<int>& arr, int low, int high);
int binarySearch(const vector<int>& arr, int key);
void runTest(int n);

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

void generateArray(vector<int>& arr, int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);
    arr.clear();
    for (int i = 0; i < n; ++i) arr.push_back(dis(gen));
}

