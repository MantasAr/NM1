#include <iostream>

using namespace std;


void generuotiSakini(string vardas, string pavarde, int amzius, string profesija) {
    cout << vardas << " " << pavarde << " yra " << amzius << "-aisiais metais gimes " << profesija << "." << endl;
}

int main() {
    // Pirmasis kvietimas
    generuotiSakini("Jonas", "Jonaitis", 30, "programuotojas");

    // Antrasis kvietimas su skirtingais duomenimis
    generuotiSakini("Marius", "Mariukas", 25, "inzinierius");

    return 0;
}
