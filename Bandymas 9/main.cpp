#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int skaiciuotiLenteles(int kabinetuSkaicius) {
    int lentelesSkaicius = 0;

    for (int kabinetoNumeris = 1; kabinetoNumeris <= kabinetuSkaicius; ++kabinetoNumeris) {
        // Apskaičiuojame, kiek lentelių prireiks kiekvienam kabinetui
        int lenteliuSkaiciusKabinti = to_string(kabinetoNumeris).length();
        lentelesSkaicius += lenteliuSkaiciusKabinti;
    }

    return lentelesSkaicius;
}

int main() {
    // Nuskaitome pradinių duomenų failą
    ifstream pradiniaiFailas("duomenys.txt");
    int kabinetuSkaicius;

    if (pradiniaiFailas.is_open()) {
        pradiniaiFailas >> kabinetuSkaicius;
        pradiniaiFailas.close();
    } else {
        cout << "Nepavyko atidaryti failo duomenys.txt" << endl;
        return 1;
    }

    // Skaičiuojame lenteles
    int rezultatas = skaiciuotiLenteles(kabinetuSkaicius);

    // Įrašome rezultatą į rezultatų failą
    ofstream rezultatuFailas("rezultatai.txt");

    if (rezultatuFailas.is_open()) {
        rezultatuFailas << rezultatas;
        rezultatuFailas.close();
    } else {
        cout << "Nepavyko atidaryti failo rezultatai.txt" << endl;
        return 1;
    }

    return 0;
}
