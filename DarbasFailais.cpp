
#include "DarbasFailais.h";



void Isvestis(const vector<Kolega> &kolegos, size_t dv, size_t dp) {
    ofstream fr("output.txt");
    fr << std::left << std::setw(static_cast<int>(dp + 4)) << "Pavarde" << std::setw(static_cast<int>(dv + 4)) << "Vardas"
       << std::setw(18 + 4) << "Galutinis-vidurkis" << std::setw(17 + 4) << "Galutinis-mediana" << endl;
    for (auto k : kolegos) {
        k.galBalasM = Mediana(k.egzam, k.pazymiai);
        k.galBalasV = Suma(k.egzam, k.pazymiai);
        fr << std::left << std::setw(static_cast<int>(dp + 4)) << k.pavard << std::setw(static_cast<int>(dv + 4)) << k.vardas
           << std::setprecision(2) << std::fixed << std::setw(18 + 4)
           << k.galBalasV << std::setw(17 + 3) << k.galBalasM << endl;
    }
}

void Nuskaitymas(vector<Kolega> &kolegos) {
    double *p = new double[5], egzam;
    vector<double> paz{};
    string v, pa;
    Kolega k{};
    ifstream fd("kursiokai.txt");

    while (fd >> pa >> v >> p[0] >> p[1] >> p[2] >> p[3] >> p[4] >> egzam) {
        k.vardas = v;
        k.pavard = pa;
        for (int i = 0; i < 5; i++) paz.push_back(p[i]);
        k.pazymiai = paz;
        paz.clear();
        k.egzam = egzam;
        kolegos.push_back(k);
    }
}

bool KolegosCompareV(Kolega lhs, Kolega rhs) {
    if (lhs.pavard <= rhs.pavard) {
        if (lhs.pavard == rhs.pavard) {
            return lhs.vardas < rhs.vardas;
        } else return true;
    } else return false;
}
