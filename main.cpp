#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <chrono>

using std::cout; using std::cin; using std::endl; using std::string; using std::vector; using std::mt19937;
using std::uniform_real_distribution;

double Mediana(double egz, double varEil[], int &size) {

    for (int i = 0; i < size; i++) {
        for (int t = 0; t < size - 1; t++) {
            if (varEil[i] < varEil[t]) std::swap(varEil[i], varEil[t]);
        }
    }

    double ats{};

    if (size == 0) return 0.6*egz;
    else if (size % 2 == 0) ats = ((varEil[size / 2] + (varEil[size / 2 - 1])) / 2);
    else ats = varEil[(size - 1) / 2];

    return 0.4 * (ats / size) + (0.6 * egz);
}

double Mediana(double egz, vector<double> varEil) {

    for (int i = 0; i < varEil.size(); i++) {
        for (int t = 0; t < varEil.size() - 1; t++) {
            if (varEil[i] < varEil[t]) std::swap(varEil[i], varEil[t]);
        }
    }

    double ats{};

    if (varEil.empty()) return 0.6*egz;
    else if (varEil.size() % 2 == 0) ats = ((varEil[varEil.size() / 2] + (varEil[varEil.size() / 2 - 1])) / 2);
    else ats = varEil[(varEil.size() - 1) / 2];

    return 0.4 * (ats / varEil.size()) + (0.6 * egz);
}

double Suma(double egz, vector<double> varEil) {
    int suma{}, n{};
    if(varEil.empty()) return 0.6 * egz;
    for (auto v:varEil) {
        suma += v;
    }
    return 0.4 * (suma / n) + (0.6 * egz);
}

double Suma(double egz, double *&varEil, int &size) {
    int suma{}, n{};
    for (int i = 0; i < size; i++) {
        suma += varEil[i];
    }
    if(suma == 0) return 0.6 * egz;
    return 0.4 * (suma / n) + (0.6 * egz);
}

void Ivedimas(double *&pazymiai, int &size, double &egz) {

    cout << "Iveskite egzamino bala" << endl << endl;
    cin >> egz;

    cout << "Iveskite pazymius, ivedus 0 ivedimas baigtas\n";
    int capacity = 1;

    double k{-1.0};
    while (k) {
        cin >> k;
        if ( k == 0 ) break;
        if (k < 1 || k > 10) cout << "Iveskite skaiciu desimtbaleje sistemoje\n";
        else {
            if (capacity > size) {
                pazymiai[size] = k;
                size++;
            } else if (capacity <= size) {
                capacity *= 2;
                auto *pakeitimas = new double[capacity];
                for (int i = 0; i < size; i++) {
                    pakeitimas[i] = pazymiai[i];
                }
                pazymiai = pakeitimas;
                pazymiai[size] = k;
                size++;
            }
        }

    }
}

void Ivedimas(vector<double> &pazymiai, double &egz) {
    cout << "Iveskite egzamino bala" << endl << endl;
    cin >> egz;
    cout << "Iveskite pazymius, ivedus 0 ivedimas baigtas\n";
    double k{-1.0};
    //InVariant: vartotojas vis dar iveda double tipo skaicius
    while (k) {
        cin >> k;
        if ( k == 0 ) break;
        if (k < 1 || k > 10) cout << "Iveskite skaiciu desimtbaleje sistemoje\n";
        else pazymiai.push_back(k);
    }
}

void Auto(double &egzam, vector<double> &pazym) {

    cout << "Kiek pazymiu generuoti? ";
    int kiekis{};
    cin >> kiekis;

    mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    uniform_real_distribution<double> dist(1, 10);

    egzam = dist(mt);
    for (int i = 0; i < kiekis; i++) {
        pazym.push_back(dist(mt));
    }
}

void Auto(double &egzam, double *&pazym, int &size) {
    cout << "Kiek pazymiu generuoti? ";
    cin >> size;
    pazym = new double[size];

    mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    uniform_real_distribution<> dist(1.0, 10.0);

    egzam = dist(mt);
    for (int i = 0; i < size; i++) {
        pazym[i] = dist(mt);
    }
}

int main() {
    cout << "Studento vardas:" << endl;
    string vardas{};
    cin >> vardas;
    cout << "Studento pavarde:" << endl;
    string pavarde{};
    cin >> pavarde;

    double egz{};

    cout << "Pasirinkite ivedimo tipo buda:\n Vektoriai -1\n Masyvas -2\n";
    char pas{};
    cin >> pas;


    if (pas == '1') {
        vector<double> pazymiai;


        cout << "Pasirinkite ivedimo buda: \n AutoRandom-1\n Rankomis-2\n";
        cin >> pas;
        if (pas == '1') {
            Auto(egz, pazymiai);
        } else if (pas == '2') {
            Ivedimas(pazymiai, egz);
        }

        cout << "Pasirinkite skaiciavimo buda: \n Mediana-1\n Vidurkis-2\n";
        cin >> pas;
        double galBal{};
        if (pas == '1') {
            galBal = Mediana(egz, pazymiai);
        } else if (pas == '2') {
            galBal = Suma(egz, pazymiai);
        }

        cout << vardas << " " << pavarde << endl;
        cout << "Namu darbu pazymiai:\n";
        for (auto v:pazymiai) {
            cout << std::fixed << std::setprecision(2) << v << endl;
        }
        cout << "Egzamino pazimys: " << std::fixed << std::setprecision(2) << egz << endl;
        cout << "Galutinis pazimys: " << std::fixed << std::setprecision(2) << galBal << endl;


    } else if (pas == '2') {
        auto *pazimiai = new double[1];
        int size = 0;

        cout << "Pasirinkite ivedimo buda: \n AutoRandom-1\n Rankomis-2\n";
        cin >> pas;
        if (pas == '1') {
            Auto(egz, pazimiai, size);
        } else if (pas == '2') {

            Ivedimas(pazimiai, size, egz);
        }

        cout << "Pasirinkite skaiciavimo buda: \n Mediana-1\n Vidurkis-2\n";
        cin >> pas;
        double galBal{};
        if (pas == '1') {
            galBal = Mediana(egz, pazimiai, size);
        } else if (pas == '2') {
            galBal = Suma(egz, pazimiai, size);
        }

        cout << vardas << " " << pavarde << endl;
        cout << "Namu darbu pazymiai:\n";
        for (int i = 0; i < size; i++) {
            cout << std::fixed << std::setprecision(2) << pazimiai[i] << endl;
        }
        cout << "Egzamino pazimys: " << std::fixed << std::setprecision(2) << egz << endl;
        cout << "Galutinis pazimys: " << std::fixed << std::setprecision(2) << galBal << endl;
    }

    return 0;

}



