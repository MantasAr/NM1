#include <iostream> // Įtraukiame įvesties/išvesties biblioteką
#include <fstream>  // Įtraukiame failų operacijų biblioteką

using namespace std; // Naudojame standartinį C++ vardespac'ą

int main() { // Pagrindinė programa prasideda čia
    ifstream input("duomenys.txt"); // Atidarome pradinių duomenų failą "duomenys.txt" skaitymui

    if (!input.is_open()) { // Tikriname, ar failas buvo sėkmingai atidarytas
        cout << "Nepavyko atidaryti pradinių duomenų failo." << endl; // Jei ne, išvedame klaidos pranešimą
        return 1; // Ir baigiame programos darbą su grąžinimo kodu 1
    }

    int n, x, b; // Sukuriame tris sveikuosius skaičius n, x ir b
    input >> n >> x >> b; // Nuskaitome duomenis iš failo: dienų skaičių, šūvių skaičių ir baudos minučių skaičių

    int total_time = 0; // Sukuriame kintamąjį total_time, kurį naudosime laikui saugoti

    // Ciklas, skirtas apdoroti kiekvieną etapą
    for (int i = 0; i < n; i++) {
        int laikas, kiek_kartu_pataike; // Sukuriame du kintamuosius - laikas ir kiek kartų pataikyta

        input >> laikas >> kiek_kartu_pataike; // Nuskaitome duomenis apie etapą iš failo

        int baudos_laikas = (x - kiek_kartu_pataike) * b; // Apskaičiuojame baudos laiką

        total_time += laikas + baudos_laikas; // Pridedame etapo laiką ir baudos laiką prie bendro laiko
    }

    input.close(); // Uždarome pradinių duomenų failą

    ofstream output("rezultatai.txt"); // Atidarome rezultatų failą "rezultatai.txt" rašymui

    if (!output.is_open()) { // Tikriname, ar failas buvo sėkmingai atidarytas
        cout << "Nepavyko atidaryti rezultatų failo." << endl; // Jei ne, išvedame klaidos pranešimą
        return 1; // Ir baigiame programos darbą su grąžinimo kodu 1
    }

    output << total_time << endl; // Įrašome apskaičiuotą laiką į rezultatų failą su nauja eilute

    output.close(); // Uždarome rezultatų failą

    cout << "Rezultatas sėkmingai įrašytas į rezultatų failą." << endl; // Išvedame pranešimą apie sėkmingą rezultato įrašymą

    return 0; // Baigiame programos darbą su grąžinimo kodu 0, nurodydami, kad vykdymas buvo sėkmingas
}
