//
// Created by Acer on 2018-03-13.
//


#include "../headers/Profiling.h"


using laikas = std::chrono::high_resolution_clock;
using ns = std::chrono::microseconds;
using std::chrono::time_point;

using std::uniform_int_distribution;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::deque;
using std::list;
using std::sort;


void StartTesting(const unsigned int nTestu) {
    ofstream pr;
    try {
        pr.open("ProfilingResult.txt", std::ios_base::out);
        if (!pr.good()) throw "Error opening file";
    } catch (string &e){
        cout << e << endl;
        std::terminate();
    }

    c2:
    int metod{};
    if (cout << "Pasirinkite funkcija. 1 - skaiciuok pagal vidurki, 2 - skaiciuok pagal mediana: " && !(cin >> metod)) {
        cin.clear(); //clear bad input flag
        cin.ignore(::std::numeric_limits<int>::max(), '\n'); //discard input
        cout << "Neteisinga įvestis\n";
        goto c2;
    }
    if (metod != 1 && metod != 2) {
        cout << "Toks pasirinkimas negalimas" << endl;
        goto  c2;
    }
    for (unsigned int i = 1; i <= nTestu; i++){

        StartProfiling(i, pr, static_cast<unsigned int>(metod));
        pr << endl << endl << endl;
    }


}

void GeneruokTestui(unsigned int n) {
    mt19937 mt(static_cast<long unsigned int>(std::chrono::_V2::system_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> dist(1, 10);
    unsigned int dydis {};

    for (int k = 1; k <= n ; k++){
        dydis = (unsigned int)std::pow(10,k);
        string fi = "perf" + std::__cxx11::to_string(dydis) + "_IN.txt";
        ofstream fk (fi);
        for (unsigned int i = 1; i <= dydis; i++){
            fk << "Vardas" + std::__cxx11::to_string(i) << " Pavarde" + std::__cxx11::to_string(i);
            for (int j = 0; j < 6; j++){
                fk << " " <<  std::__cxx11::to_string(dist(mt));
            }
            fk << endl;
        }
        fk.close();
    }
}


//-------------------------------------------------------------------------
//Profiliavimas 2-a strategija (Studento laikymas tik kategorizuotame faile)
//Container<Studentas> kolegos studentas yra trinamas, jeigu studentas yra "geekas"
//-------------------------------------------------------------------------

template<typename T> void ArKietas(T&koleg, T &geek, bool arVidurkiu) {

    for (Studentas &k : koleg){
        if (arVidurkiu){
            if (k.Vidurkis() >= 6) geek.push_back(k);
        } else
            if (k.Mediana() >= 6) geek.push_back(k);
    }
    if (arVidurkiu) koleg.erase(std::remove_if(koleg.begin(), koleg.end(), RibaV), koleg.end());
    else koleg.erase(std::remove_if(koleg.begin(), koleg.end(), RibaM), koleg.end());
}

void StartProfiling(unsigned int n, ofstream &pr, const unsigned int met) {

    vector<Studentas> kolegos, geek;
    auto dydis = (unsigned int)std::pow(10,n);
    kolegos.reserve(dydis);
    string fi = "perf" + std::__cxx11::to_string(dydis) + "_IN.txt";

    pr << "-------------------------------VECTOR-----------------------------------------------" << endl;
    pr << "Dirbame su " + std::to_string(dydis) + " įrašų" << endl;

    auto start = laikas::now();
    Nuskaitymas(kolegos, fi);
    auto end = laikas::now();
    std::chrono::duration<double> diff = end - start;
    pr <<"Nuskaitymas užtruko  "<< (diff).count()<<" s."<<endl;
    auto grandTotal = diff;

    start = laikas::now();
    ArKietas(kolegos,geek, met == 1);
    end = laikas::now();
    diff = end - start;
    pr <<"Rūšiavimas užtruko  "<< (diff).count()<<" s."<<endl;
    grandTotal += diff;

    pr <<"Iš viso:  "<< (grandTotal).count()<<" s."<<endl;


    pr << "------------------------------------------------------------------------------------" << endl << endl;

}

bool RibaV (Studentas& val) {
    return val.Vidurkis() >= 6.0;
}
bool RibaM (Studentas& val) {
    return val.Mediana() >= 6.0;
}



