#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <windows.h>

using namespace std;

int countWords(const string& sentence) {
    stringstream ss(sentence);
    string word;
    int count = 0;
    while (ss >> word) count++;
    return count;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cout << "Помилка: файл input.txt не знайдено!" << endl;
        return 1;
    }

    vector<string> sentences;
    string line;
    while (getline(inputFile, line)) {
        if (!line.empty()) sentences.push_back(line);
    }
    inputFile.close();

    sort(sentences.begin(), sentences.end(), [](const string& a, const string& b) {
        return countWords(a) > countWords(b);
        });

    ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        for (const string& s : sentences) {
            outputFile << s << endl;
        }
        outputFile.close();
        cout << "Результат успішно записано в output.txt" << endl;
    }
    else {
        cout << "Помилка при створенні вихідного файлу!" << endl;
    }

    return 0;
}