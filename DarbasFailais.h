//
// Created by Acer on 2018-03-13.
//

#ifndef JUXRVHTG_DARBASFAILAIS_H
#define JUXRVHTG_DARBASFAILAIS_H

#include "SkaiciavimoBudai.h";

#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>



using std::vector;
using std::cout; using std::cin; using std::endl; using std::string;
using std::ifstream; using std::ofstream;

struct Kolega {
    string vardas{};
    string pavard{};
    vector<double> pazymiai{};
    double galBalasV{};
    double galBalasM{};
    double egzam{};
};

void Isvestis(const vector<Kolega> &kolegos, size_t dv, size_t dp);
void Nuskaitymas(vector<Kolega> &kolegos, const string &s);
bool KolegosCompareV(Kolega lhs, Kolega rhs);

#endif //JUXRVHTG_DARBASFAILAIS_H
