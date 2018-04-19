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

    pr << "1 Strategija:\n";
    for (unsigned int i = 1; i <= nTestu; i++){

        StartProfiling(i, pr, static_cast<unsigned int>(metod));
        ListStartProfiling(i, pr, static_cast<unsigned int>(metod));
        DequeStartProfiling(i, pr, static_cast<unsigned int>(metod));
        pr << endl << endl << endl;
    }
    pr << "2 Strategija:\n";
    for (unsigned int i = 1; i <= nTestu; i++){

        NStartProfiling(i, pr, static_cast<unsigned int>(metod));
        NListStartProfiling(i, pr, static_cast<unsigned int>(metod));
        NDequeStartProfiling(i, pr, static_cast<unsigned int>(metod));
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

//---------------------------------------------------------------------------------------------
//Profiliavimai 1-a strategija (studento laikymas ir studentu ir kategorizuotame konteineryje,)
// Container<Kolega> kolegos nemodifikuojamas
//---------------------------------------------------------------------------------------------

template<typename T> void ArKietas(T&koleg, T &geek, T &lose, bool arVidurkiu) {

    for (auto &k : koleg){
        if (arVidurkiu){
            double suma{};
            suma = std::accumulate(k.pazymiai.begin(), k.pazymiai.end(), 0.0);
            k.galBalasV = suma / k.pazymiai.size();
            if (k.galBalasV >= 6)geek.push_back(k);
            else lose.push_back(k);
        } else {
            std::sort(k.pazymiai.begin(), k.pazymiai.end());
            k.galBalasM = k.pazymiai.size() % 2 == 0 ? (k.pazymiai[k.pazymiai.size() / 2] + k.pazymiai[k.pazymiai.size() / 2 - 1]) / 2
                                                     : k.pazymiai[k.pazymiai.size() / 2];
            if (k.galBalasM >= 6) geek.push_back(k);
            else lose.push_back(k);
        }
    }
}

void StartProfiling(unsigned int n, ofstream &pr, const unsigned int met) {

    vector<Kolega> kolegos, geek, los;
    auto dydis = (unsigned int)std::pow(10,n);
    kolegos.reserve(dydis);
    string fi = "perf" + std::__cxx11::to_string(dydis) + "_IN.txt";
    string fo = "perf" + std::__cxx11::to_string(dydis) + "_OUT.txt";

    ofstream fk;
    try {
        fk.open(fi, std::ios_base::out);
        if (!fk.good()) throw "Error opening file";
    } catch (string &e){
        cout << e << endl;
        std::terminate();
    }

    pr << "-------------------------------VECTOR-----------------------------------------------" << endl;
    pr << "Dirbame su " + std::to_string(dydis) + " įrašų" << endl;

    //auto start = laikas::now();
    //GeneruokTestui(dydis, fk);
    //auto end = laikas::now();
    //std::chrono::duration<double> diff = end - start;
    //auto grandTotal = diff;
    //pr <<"Generavimas užtruko  "<< (diff).count()<<" s."<<endl;

    auto start = laikas::now(); //delete auto if uncommented above
    Nuskaitymas(kolegos, fi);
    auto end = laikas::now();
    std::chrono::duration<double> diff = end - start;
    pr <<"Nuskaitymas užtruko  "<< (diff).count()<<" s."<<endl;
    auto grandTotal = diff;

    start = laikas::now();
    ArKietas(kolegos,geek,los, met == 1);
    end = laikas::now();
    diff = end - start;
    pr <<"Rūšiavimas užtruko  "<< (diff).count()<<" s."<<endl;
    grandTotal += diff;

    pr <<"Iš viso:  "<< (grandTotal).count()<<" s."<<endl;


    pr << "------------------------------------------------------------------------------------" << endl << endl;

}







/*void ListArKietas(list<Kolega> &koleg, list<Kolega> &geek, list<Kolega> &lose, bool arVidurkiu) {
    auto k = koleg.begin();
    while(k != koleg.end()){
        if (arVidurkiu){
            double suma{};
            for (auto paz : k->pazymiai)
                suma += paz;
            if(suma / k->pazymiai.size() >= 6.0){
                geek.push_back(*k);
                k = koleg.erase(k);
            }
            //else lose.push_back(k);
            else k++;
        } else{
            double med{};
            sort(k->pazymiai.begin(), k->pazymiai.end());
            med = k->pazymiai.size() % 2 == 0 ? (k->pazymiai[k->pazymiai.size() / 2] + k->pazymiai[k->pazymiai.size() / 2 - 1]) / 2
                                             : k->pazymiai[k->pazymiai.size() / 2];

            if(med >= 6){
                geek.push_back(*k);
                k = koleg.erase(k);
            }
            //else lose.push_back(k);
            else k++;
        }
    }
}

void DequeArKietas(deque<Kolega> &koleg, deque<Kolega> &geek, deque<Kolega> &lose, bool arVidurkiu) {

    for (unsigned int i = 0; i < koleg.size(); i++) {
        Kolega *k = &koleg[i];
        if (arVidurkiu){
            double suma{};
            for (auto paz : k->pazymiai)
                suma += paz;
            if(suma / k->pazymiai.size() >= 6.0){
                geek.push_back(*k);
                koleg.erase(koleg.begin() + i);
            }
            //else lose.push_back(k);
        } else{
            double med{};
            sort(k->pazymiai.begin(), k->pazymiai.end());
            med = k->pazymiai.size() % 2 == 0 ? (k->pazymiai[k->pazymiai.size() / 2] + k->pazymiai[k->pazymiai.size() / 2 - 1]) / 2
                                             : k->pazymiai[k->pazymiai.size() / 2];

            if(med >= 6) {
                geek.push_back(*k);
                koleg.erase(koleg.begin() + i);;
            }
            //else lose.push_back(k);

        }
    }
}*/

void ListStartProfiling(unsigned int n, ofstream &pr, const unsigned int met) {

    list<Kolega> kolegos, geek, los;
    auto dydis = (unsigned int)std::pow(10,n);
    string fi = "perf" + std::__cxx11::to_string(dydis) + "_IN.txt";
    string fo = "perf" + std::__cxx11::to_string(dydis) + "_OUT.txt";

    pr << "------------------------------------LIST--------------------------------------------" << endl;
    pr << "Dirbame su " + std::to_string(dydis) + " įrašų" << endl;
    
    auto start = laikas::now();
    ListNuskaitymas(kolegos, fi);
    auto end = laikas::now();
    std::chrono::duration<double> diff = end - start;
    pr <<"Nuskaitymas užtruko  "<< (diff).count()<<" s."<<endl;
    auto grandTotal = diff;

    start = laikas::now();
    ArKietas(kolegos,geek,los, met == 1);
    end = laikas::now();
    diff = end - start;
    pr <<"Rūšiavimas užtruko  "<< (diff).count()<<" s."<<endl;
    grandTotal += diff;

    pr <<"Iš viso:  "<< (grandTotal).count()<<" s."<<endl;


    pr << "------------------------------------------------------------------------------------" << endl << endl;

}

void DequeStartProfiling(unsigned int n, ofstream &pr, const unsigned int met) {

    deque<Kolega> kolegos, geek, los;
    auto dydis = (unsigned int)std::pow(10,n);
    string fi = "perf" + std::__cxx11::to_string(dydis) + "_IN.txt";
    string fo = "perf" + std::__cxx11::to_string(dydis) + "_OUT.txt";


    pr << "------------------------------------DEQUE-------------------------------------------" << endl;
    pr << "Dirbame su " + std::to_string(dydis) + " įrašų" << endl;

    auto start = laikas::now();
    DequeNuskaitymas(kolegos, fi);
    auto end = laikas::now();
    std::chrono::duration<double> diff = end - start;
    pr <<"Nuskaitymas užtruko  "<< (diff).count()<<" s."<<endl;
    auto grandTotal = diff;

    start = laikas::now();
    ArKietas(kolegos,geek,los, met == 1);
    end = laikas::now();
    diff = end - start;
    pr <<"Rūšiavimas užtruko  "<< (diff).count()<<" s."<<endl;
    grandTotal += diff;

    pr <<"Iš viso:  "<< (grandTotal).count()<<" s."<<endl;


    pr << "------------------------------------------------------------------------------------" << endl << endl;

}

//-------------------------------------------------------------------------
//Profiliavimas 2-a strategija (Studento laikymas tik kategorizuotame faile)
//Container<Kolegos> kolegos studentas yra trinamas, jeigu studentas yra "geekas"
//-------------------------------------------------------------------------

template<typename T> void ArKietas(T&koleg, T &geek, bool arVidurkiu) {

    for (auto &k : koleg){
        if (arVidurkiu){
            double suma{};
            suma = std::accumulate(k.pazymiai.begin(), k.pazymiai.end(), 0.0);
            k.galBalasV = suma / k.pazymiai.size();
            if (k.galBalasV >= 6) geek.push_back(k);
        } else {
            std::sort(k.pazymiai.begin(), k.pazymiai.end());
            k.galBalasM = k.pazymiai.size() % 2 == 0 ? (k.pazymiai[k.pazymiai.size() / 2] + k.pazymiai[k.pazymiai.size() / 2 - 1]) / 2
                                                     : k.pazymiai[k.pazymiai.size() / 2];
            if (k.galBalasM >= 6) geek.push_back(k);
        }
    }
    if (arVidurkiu) koleg.erase(std::remove_if(koleg.begin(), koleg.end(), RibaV), koleg.end());
    else koleg.erase(std::remove_if(koleg.begin(), koleg.end(), RibaM), koleg.end());
}

void NStartProfiling(unsigned int n, ofstream &pr, const unsigned int met) {

    vector<Kolega> kolegos, geek;
    auto dydis = (unsigned int)std::pow(10,n);
    kolegos.reserve(dydis);
    string fi = "perf" + std::__cxx11::to_string(dydis) + "_IN.txt";
    string fo = "perf" + std::__cxx11::to_string(dydis) + "_OUT.txt";

    ofstream fk;
    try {
        fk.open(fi, std::ios_base::out);
        if (!fk.good()) throw "Error opening file";
    } catch (string &e){
        cout << e << endl;
        std::terminate();
    }

    pr << "-------------------------------VECTOR-----------------------------------------------" << endl;
    pr << "Dirbame su " + std::to_string(dydis) + " įrašų" << endl;

    //auto start = laikas::now();
    //GeneruokTestui(dydis, fk);
    //auto end = laikas::now();
    //std::chrono::duration<double> diff = end - start;
    //auto grandTotal = diff;
    //pr <<"Generavimas užtruko  "<< (diff).count()<<" s."<<endl;

    auto start = laikas::now(); //delete auto if uncommented above
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

void NListStartProfiling(unsigned int n, ofstream &pr, const unsigned int met) {

    list<Kolega> kolegos, geek;
    auto dydis = (unsigned int)std::pow(10,n);
    string fi = "perf" + std::__cxx11::to_string(dydis) + "_IN.txt";
    string fo = "perf" + std::__cxx11::to_string(dydis) + "_OUT.txt";

    pr << "------------------------------------LIST--------------------------------------------" << endl;
    pr << "Dirbame su " + std::to_string(dydis) + " įrašų" << endl;

    auto start = laikas::now();
    ListNuskaitymas(kolegos, fi);
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

void NDequeStartProfiling(unsigned int n, ofstream &pr, const unsigned int met) {

    deque<Kolega> kolegos, geek;
    auto dydis = (unsigned int)std::pow(10,n);
    string fi = "perf" + std::__cxx11::to_string(dydis) + "_IN.txt";
    string fo = "perf" + std::__cxx11::to_string(dydis) + "_OUT.txt";


    pr << "------------------------------------DEQUE-------------------------------------------" << endl;
    pr << "Dirbame su " + std::to_string(dydis) + " įrašų" << endl;

    auto start = laikas::now();
    DequeNuskaitymas(kolegos, fi);
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

bool RibaV (Kolega& val) {
    return val.galBalasV >= 6.0;
}
bool RibaM (Kolega& val) {
    return val.galBalasM >= 6.0;
}



