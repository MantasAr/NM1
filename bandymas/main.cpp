#include <iostream> // Įtraukiame iostream biblioteką, kad galėtume naudoti įvesties ir išvesties operacijas.
#include <fstream> // Įtraukiame iomanip biblioteką, naudosime vėliau rezultatų formatavimui.


using namespace std;

// Funkcija, kuri sugeneruoja skaičių seką ir įrašo ją į failą
void generuotiIrIrasymas() {

    int skaicius = 7; // Pradinis skaičius
    ofstream failas("skaiciu_seka.txt"); // Sukuriamas failas skaiciu_seka.txt

        for (int i = 0; i < 7; ++i) {
            failas << skaicius << " "; // Įrašoma kiekviena sekos reikšmė į failą atskiriant tarpu
            skaicius++; // Pridedamas 1 prie skaičiaus
        }
        failas.close();
        cout << "Skaiciu seka irasyta i faila";
    }

// Metodas, kuris nuskaito skaičių seką iš failo ir išveda į ekraną atskiriant dvigubu tarpu
void skaitymasIrIsvedimas() {
    ifstream failas("skaiciu_seka.txt"); // Atidaromas failas skaiciu_seka.txt skaitymui

        int skaicius;
        while (failas >> skaicius) {
            cout << skaicius << "  "; // Išvedama kiekviena skaityta reikšmė atskiriant dvigubu tarpu
        }
        failas.close();
        cout << "Nepavyko atidaryti failo";
    }

int main() {
    generuotiIrIrasymas(); // Sugeneruojama ir įrašoma skaičių seka į failą
    skaitymasIrIsvedimas(); // Nuskaitoma skaičių seka iš failo ir išvedama į ekraną atskiriant dvigubu tarpu

    return 0;
}
