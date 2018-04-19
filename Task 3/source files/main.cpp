
#include "../headers/SkaiciavimoBudai.h"
#include "../headers/IvestiesMetodai.h"
#include "../headers/DarbasFailais.h"
#include "../headers/Profiling.h"

int main() {



    cout << "Pasirinkite: \n1-Failo generavimas\n 2-Profiliavimas\n";
    char pas{};
    cin >> pas;
    if (pas != '1' & pas != '2'){
        cout << "toks pasirinkimas negalimas\n";
    }
    if (pas == '1')
    {
        const unsigned int nTestu = 3; // kiek testų failų generuoti
        GeneruokTestui(nTestu);
    }
    if (pas == '3')
    {

    }
    if (pas == '2'){
        cout << "Studento vardas:" << endl;
        string vardas{};
        cin >> vardas;
        cout << "Studento pavarde:" << endl;
        string pavarde{};
        cin >> pavarde;

        double egz{};
        cout << "Pasirinkite ivedimo tipo buda:\n Vektoriai -1\n Masyvas -2\n";

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
        double galBal{}; //galutinis studento balas

        //SkaiciavimoBudai.cpp -----------------

        if (pas == '1') {
            galBal = Mediana(egz, pazymiai);
        } else if (pas == '2') {
            galBal = Suma(egz, pazymiai);
        }

        //--------------------------------------

        cout << vardas << " " << pavarde << endl;
        cout << "Namu darbu pazymiai:\n";
        for (auto v:pazymiai) {
            cout << std::fixed << std::setprecision(2) << v << endl;
        }
        cout << "Egzamino pazimys: " << std::fixed << std::setprecision(2) << egz << endl;
        cout << "Galutinis pazimys: " << std::fixed << std::setprecision(2) << galBal << endl;


    } else if (pas == '2') {
        auto *pazymiai = new double[1];
        int size = 0;

        cout << "Pasirinkite ivedimo buda: \n AutoRandom-1\n Rankomis-2\n";
        cin >> pas;
        if (pas == '1') {
            Auto(egz, pazymiai, size);
        } else if (pas == '2') {

            Ivedimas(pazymiai, size, egz);
        }

        cout << "Pasirinkite skaiciavimo buda: \n Mediana-1\n Vidurkis-2\n";
        cin >> pas;


        double galBal{};
        if (pas == '1') {
            galBal = Mediana(egz, pazymiai, size);
        } else if (pas == '2') {
            galBal = Suma(egz, pazymiai, size);
        }

        cout << vardas << " " << pavarde << endl;
        cout << "Namu darbu pazymiai:\n";
        for (int i = 0; i < size; i++) {
            cout << std::fixed << std::setprecision(2) << pazymiai[i] << endl;
        }
        cout << "Egzamino pazimys: " << std::fixed << std::setprecision(2) << egz << endl;
        cout << "Galutinis pazimys: " << std::fixed << std::setprecision(2) << galBal << endl;
    }
    }

    return 0;

}





