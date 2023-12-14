#include <iostream>
using namespace std;

int main() {

    int pazymys;

    setlocale (LC_ALL, "Lithuanian");

    cout << "Iveskite pazymi nuo 1 iki 10: ";
    cin >> pazymys;


        if (pazymys >= 8.5 && pazymys <= 10) {
            cout << "A+" << endl;
        } else if (pazymys >= 7.5 && pazymys < 8.5) {
            cout << "A" << endl;
        } else if (pazymys >= 7 && pazymys < 7.5) {
            cout << "B+" << endl;
        } else if (pazymys >= 6.5 && pazymys < 7) {
            cout << "B" << endl;
        } else if (pazymys >= 6 && pazymys < 6.5) {
            cout << "C" << endl;
        } else if (pazymys >= 5.5 && pazymys < 6) {
            cout << "D" << endl;
        } else {
            cout << "F" << endl;
        }

    return 0;
}
