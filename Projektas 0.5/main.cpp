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

    int n, x, b;
    input >> n >> x >> b; // Skaitome dienų skaičių, šūvių skaičių ir baudos minučių skaičių

    int total_time = 0; // Viso laiko suma

    // Skaitome laiką ir šūvių skaičių kiekvienam etapui
    for (int i = 0; i < n; i++) {
        int laikas, kiek_kartu_pataike;
        input >> laikas >> kiek_kartu_pataike;

        // Apskaičiuojame, kiek minučių pridėti dėl baudų
        int baudos_laikas = (x - kiek_kartu_pataike) * b;

        // Pridedame laiką, kurį užtruko įveikti etapą ir baudos laiką
        total_time += laikas + baudos_laikas;
    }

    // Uždarome pradinių duomenų failą
    input.close();

    // Atidarome rezultatų failą
    ofstream output("rezultatai.txt");

    // Tikriname, ar failas buvo sėkmingai atidarytas
    if (!output.is_open()) {
        cout << "Nepavyko atidaryti rezultatų failo." << endl;
        return 1;
    }

    // Įrašome rezultatą į failą
    output << total_time << endl;

    // Uždarome rezultatų failą
    output.close();

    cout << "Rezultatas sėkmingai įrašytas į rezultatų failą." << endl;

    return 0;
}
