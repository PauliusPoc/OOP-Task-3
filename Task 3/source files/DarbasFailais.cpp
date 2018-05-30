
#include "../headers/DarbasFailais.h"
#include "../headers/Studentas.h"

void Nuskaitymas(vector<Studentas> &studentai, const string &s) {
    ifstream fd;
    Studentas *k;
    studentai.reserve(100000);

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

    while (!fd.eof()){
        k = new Studentas(fd);
        if (fd.eof()) break;
        studentai.push_back(*k);
    }
}


/*bool KolegosCompareV(Studentas lhs, Studentas rhs) {
    if (lhs.pavarde() <= rhs.pavarde()) {
        if (lhs.pavarde() == rhs.pavarde()) {
            return lhs.vardas() < rhs.vardas();
        } else return true;
    } else return false;
}*/


/*void Isvestis(const vector<Kolega> &kolegos, size_t dv, size_t dp) {
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
}*/
