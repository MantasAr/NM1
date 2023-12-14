#include <iostream> // Įtraukiame iostream biblioteką, kad galėtume naudoti įvesties ir išvesties operacijas.
#include <fstream> // Įtraukiame iomanip biblioteką, naudosime vėliau rezultatų formatavimui.
using namespace std; // Kad nereikėtų rašyti std prie kiekvienos funkcijos
// --- FUNKCIJOS ---
bool arPirminis(int skaicius) { // Tikrina, ar skaičius yra pirminis
    if (skaicius == 0 || skaicius == 1) return false; // 0 ir 1 nėra pirminiai
    for (int i = 2; i <= skaicius / 2; ++i) { // Žiūrima, ar skaičius dalijasi iš sau mažesnio be liekanos
        if (skaicius % i == 0) return false;
    }
    return true;
}
// --- PAGRINDINĖ FUNKCIJA ---
int main() {
    ofstream rezultatai("skaiciai.txt"); // Sukuriame rezultatų failą
    cout << "Įveskite skaičius, kuriuos norite patikrinti (baigti įvedimą įrašant 0): ";
    int skaicius;
    while (cin >> skaicius && skaicius != 0) { // Veiks tol, kol vartotojas įrašys 0
        rezultatai << skaicius << " "; // Įrašo skaičių į failą
        bool arPirminisRez = arPirminis(skaicius); // Panaudojama funkcija
        if (arPirminisRez) rezultatai << "true"; // Tikrina, ar skaičius yra pirminis ar ne ir įrašoma
        else rezultatai << "false";
        rezultatai << endl;
    }
    return 0; // Baigiama funkcija
}

