#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Planet {
    string name;
    double size;
    int life;
    double orbit;
    string star;
};

int main() {
    int choice;

    while (true) {
        cout << "\n1. Add Planet" << endl;
        cout << "2. Show All" << endl;
        cout << "3. Show Habitable" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 0) break;
    }

    return 0;
}