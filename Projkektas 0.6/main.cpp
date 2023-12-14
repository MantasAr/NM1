#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    ifstream inputFile("technika.txt");
    ofstream outputFile("pagaminta.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Nepavyko atidaryti failų.";
        return 1;
    }

    int n;
    inputFile >> n;

    unordered_map<int, int> gaminiuSavikainos;

    for (int i = 0; i < n; ++i) {
        int gaminioNumeris, gaminiuSkaicius;
        inputFile >> gaminioNumeris >> gaminiuSkaicius;

        int savikainosSuma = 0;
        for (int j = 0; j < gaminiuSkaicius; ++j) {
            int savikaina;
            inputFile >> savikaina;
            savikainosSuma += savikaina;
        }

        gaminiuSavikainos[gaminioNumeris] += savikainosSuma;
    }

    string pavadinimai[] = {"", "Pjaustykliu", "Virduliu", "Mikseriu", "Plaktuviu"};

    for (int i = 1; i <= 4; ++i) {
        outputFile << pavadinimai[i] << ": " << gaminiuSavikainos[i] << " Eur" << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Rezultatai įrašyti į pagaminta.txt failą." << endl;

    return 0;
}
