
#include "../headers/IvestiesMetodai.h"

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
