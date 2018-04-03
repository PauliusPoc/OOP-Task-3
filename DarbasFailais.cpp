
#include "DarbasFailais.h"


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


void Nuskaitymas(vector<Kolega> &kolegos, const string &s) {
    double *p = new double[5], egzam;
    vector<double> paz{};
    string v, pa;
    Kolega k{};
    ifstream fd;

    try {
        fd.open( s, std::ios::in);
        if (!fd.good()) throw "Error opening file";
    } catch (string &e){
        cout << e << endl;
        return;
    }catch (char const* e){
        cout << "Duomenu failas neegzistuoja" << endl;
        return;
    }


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

void ListNuskaitymas(list<Kolega> &kolegos, const string &s) {
    double *p = new double[5], egzam;
    vector<double> paz{};
    string v, pa;
    Kolega k{};
    ifstream fd;

    try {
        fd.open( s, std::ios::in);
        if (!fd.good()) throw "Error opening file";
    } catch (string &e){
        cout << e << endl;
        return;
    }catch (char const* e){
        cout << "Duomenu failas neegzistuoja" << endl;
        return;
    }


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

void DequeNuskaitymas(deque<Kolega> &kolegos, const string &s) {
    double *p = new double[5], egzam;
    vector<double> paz{};
    string v, pa;
    Kolega k{};
    ifstream fd;

    try {
        fd.open( s, std::ios::in);
        if (!fd.good()) throw "Error opening file";
    } catch (string &e){
        cout << e << endl;
        return;
    }catch (char const* e){
        cout << "Duomenu failas neegzistuoja" << endl;
        return;
    }


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
