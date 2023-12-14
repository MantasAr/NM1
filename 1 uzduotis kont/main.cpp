#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Vertinimai {
    int nr;
    double geriausias;
    double blogiausias;
};

int main() {
    ifstream viešbutisFile("viešbutis.txt");
    ifstream vertinimaiFile("vertinimai.txt");
    ofstream rezultataiFile("rezultatai.txt");

    if (!viešbutisFile.is_open() || !vertinimaiFile.is_open() || !rezultataiFile.is_open()) {
        cout << "Nepavyko atidaryti vieno iš failų.";
        return 1;
    }

    int n, m;
    viešbutisFile >> n >> m;

    vector<vector<double>> įvertinimai;
    for (int i = 0; i < m; ++i) {
        vector<double> vertinimaiEksperto;
        for (int j = 0; j < n; ++j) {
            double vert;
            vertinimaiFile >> vert;
            vertinimaiEksperto.push_back(vert);
        }
        įvertinimai.push_back(vertinimaiEksperto);
    }

    vector<Vertinimai> rezultatai;
    for (int i = 0; i < n; ++i) {
        double geriausias = įvertinimai[0][i];
        double blogiausias = įvertinimai[0][i];
        for (int j = 1; j < m; ++j) {
            if (įvertinimai[j][i] > geriausias) {
                geriausias = įvertinimai[j][i];
            }
            if (įvertinimai[j][i] < blogiausias) {
                blogiausias = įvertinimai[j][i];
            }
        }
        Vertinimai vertinimas;
        vertinimas.nr = i + 1;
        vertinimas.geriausias = geriausias;
        vertinimas.blogiausias = blogiausias;
        rezultatai.push_back(vertinimas);
    }

    for (const auto &rez : rezultatai) {
        rezultataiFile << rez.nr << " geriausias " << rez.geriausias << ", blogiausias " << rez.blogiausias << endl;
    }

    viešbutisFile.close();
    vertinimaiFile.close();
    rezultataiFile.close();

    cout << "Rezultatai įrašyti į rezultatai.txt failą." << endl;

    return 0;
}
