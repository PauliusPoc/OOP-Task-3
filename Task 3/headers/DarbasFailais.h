
#ifndef JUXRVHTG_DARBASFAILAIS_H
#define JUXRVHTG_DARBASFAILAIS_H

//#include "SkaiciavimoBudai.h"
#include "Studentas.h"

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


//void Isvestis(const vector<Studentas> &kolegos, size_t dv, size_t dp);
/**
    Kuriami objektai nuskaitant failą (kviečiama iš profiling.cpp StartProfiling funkcijos
    @param studentai  kolegos vektorius
    @param s failo, iš kurio bus nuskaitomi duomenys, pavadinimas
*/
void Nuskaitymas(vector<Studentas> &studentai, const string &s);
//bool KolegosCompareV(Studentas lhs, Studentas rhs);

#endif //JUXRVHTG_DARBASFAILAIS_H
