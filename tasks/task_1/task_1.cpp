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

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[min_idx]) min_idx = j;
        swap(arr[i], arr[min_idx]);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(const vector<int>& arr, int key) {
    int low = 0, high = (int)arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    system("chcp 1251 > nul");

    int choice;
    do {
        cout << "=== Програма сортування та пошуку ===" << endl;
        cout << "1. Запустити тести для значень n {10, 50, 800, 5000, 40000}" << endl;
        cout << "2. Ввести власне значення n" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            vector<int> counts = { 10, 50, 800, 5000, 40000 };
            for (int n : counts) runTest(n);
        }
        else if (choice == 2) {
            int customN;
            cout << "Введіть n: ";
            cin >> customN;
            runTest(customN);
        }

    } while (choice != 0);

    return 0;
}

void runTest(int n) {
    vector<int> original, data;
    generateArray(original, n);

    cout << "\n>>> Результати для n = " << n << " <<<" << endl;
    if (n <= 50) {
        cout << "Початковий масив: ";
        printArray(original);
    }

    data = original;
    auto start = high_resolution_clock::now();
    bubbleSort(data);
    auto end = high_resolution_clock::now();
    cout << "Сортування бульбашкою: " << duration_cast<microseconds>(end - start).count() << " мкс" << endl;

    data = original;
    start = high_resolution_clock::now();
    selectionSort(data);
    end = high_resolution_clock::now();
    cout << "Сортування вибором:   " << duration_cast<microseconds>(end - start).count() << " мкс" << endl;

    data = original;
    start = high_resolution_clock::now();
    quickSort(data, 0, (int)data.size() - 1);
    end = high_resolution_clock::now();
    cout << "Швидке сортування:    " << duration_cast<microseconds>(end - start).count() << " мкс" << endl;

    data = original;
    start = high_resolution_clock::now();
    auto handle = async(launch::async, [&]() {
        quickSort(data, 0, (int)data.size() - 1);
        });
    handle.get();
    end = high_resolution_clock::now();
    cout << "Швидке (асинхронно):  " << duration_cast<microseconds>(end - start).count() << " мкс" << endl;

    int key;
    cout << "Введіть число для пошуку: ";
    cin >> key;
    int idx = binarySearch(data, key);
    if (idx != -1) cout << "Елемент знайдено за індексом: " << idx << endl;
    else cout << "Елемент не знайдено." << endl;
    cout << "---------------------------------------" << endl;
}