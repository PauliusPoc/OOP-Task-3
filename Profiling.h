//
// Created by Acer on 2018-03-13.
//

#ifndef JUXRVHTG_PROFILING_H
#define JUXRVHTG_PROFILING_H

#include "DarbasFailais.h";

#include <random>
#include <chrono>
#include <algorithm>

using std::mt19937;

void ArKietas(vector<Kolega> &koleg, vector<Kolega> &geek, vector<Kolega> &lose, bool arVidurkiu);
void StartProfiling(unsigned int n, ofstream &pr, unsigned int met);
void GeneruokTestui(unsigned int n, ofstream &fk);
void StartTesting(const unsigned int nTestu);

#endif //JUXRVHTG_PROFILING_H
