
#ifndef JUXRVHTG_IVESTIESMETODAI_H
#define JUXRVHTG_IVESTIESMETODAI_H

#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include <fstream>



using std::vector;
using std::cout; using std::cin; using std::endl; using std::string; using std::mt19937;
using std::uniform_real_distribution; using std::ifstream; using std::ofstream;

void Ivedimas(double *&pazymiai, int &size, double &egz);
void Ivedimas(vector<double> &pazymiai, double &egz);
void Auto(double &egzam, vector<double> &pazym);
void Auto(double &egzam, double *&pazym, int &size);

#endif //JUXRVHTG_IVESTIESMETODAI_H
