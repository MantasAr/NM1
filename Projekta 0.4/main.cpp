#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Atidarome pradinių duomenų failą
    ifstream input("duomenys.txt");

    // Tikriname, ar failas buvo sėkmingai atidarytas
    if (!input.is_open()) {
        cout << "Nepavyko atidaryti pradinių duomenų failo." << endl;
        return 1;
    }
setlocale(LC_ALL, "Lithuanian");
    // Skaitome pradinius duomenis iš failo
    int k, m, n;
    input >> k >> m >> n;

    // Uždarome pradinių duomenų failą
    input.close();

    // Apskaičiuojame, kiek porcijų ledų buvo pardavęs per n dienų
    int total_ledai = 0;
    for (int i = 0; i < n; i++) {
        total_ledai += k;
        k += m; // Padidiname kiekvieną dieną pardavimų kiekį
    }

    // Atidarome rezultatų failą
    ofstream output("rezultatai.txt");

    // Tikriname, ar failas buvo sėkmingai atidarytas
    if (!output.is_open()) {
        cout << "Nepavyko atidaryti rezultatų failo." << endl;
        return 1;
    }

    // Įrašome rezultatus į failą
    output << total_ledai << endl;

    // Uždarome rezultatų failą
    output.close();

    cout << "Rezultatai sėkmingai įrašyti į rezultatų failą." << endl;

    return 0;
}
