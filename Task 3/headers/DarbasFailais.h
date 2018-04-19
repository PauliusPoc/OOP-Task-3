
#ifndef JUXRVHTG_DARBASFAILAIS_H
#define JUXRVHTG_DARBASFAILAIS_H

#include "SkaiciavimoBudai.h"

#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>
#include <list>



using std::vector;
using std::cout; using std::cin; using std::endl;
using std::string;
using std::ifstream; using std::ofstream;
using std::list; using std::deque;

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
void ListNuskaitymas(list<Kolega> &kolegos, const string &s);
void DequeNuskaitymas(deque<Kolega> &kolegos, const string &s);
bool KolegosCompareV(Kolega lhs, Kolega rhs);

#endif //JUXRVHTG_DARBASFAILAIS_H
