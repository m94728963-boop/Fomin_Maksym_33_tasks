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

        if (choice == 1) {
            Planet p;
            cout << "Name: ";
            cin.ignore();
            getline(cin, p.name);

            cout << "Size: "; cin >> p.size;
            cout << "Life? (1 Yes / 0 No): "; cin >> p.life;
            cout << "Orbit: "; cin >> p.orbit;
            cout << "Star: ";
            cin.ignore();
            getline(cin, p.star);


            ofstream out("planets.txt", ios::app);
            if (out.is_open()) {
                out << p.name << " " << p.size << " " << p.life << " " << p.orbit << " " << p.star << endl;
                out.close();
                cout << "Saved to planets.txt!" << endl;
            }
        }
    }

    return 0;
}