//
// Created by Acer on 2018-03-13.
//

#ifndef JUXRVHTG_PROFILING_H
#define JUXRVHTG_PROFILING_H

#include "../headers/DarbasFailais.h"
#include "../headers/Studentas.h"

#include <random>
#include <chrono>
#include <algorithm>
#include <deque>
#include <list>

using std::mt19937;

bool RibaV (Studentas&);
bool RibaM (Studentas&);

template<typename T> void ArKietas(T &koleg, T &geek, bool arVidurkiu);
void StartProfiling(unsigned int n, ofstream &pr, unsigned int met);

void GeneruokTestui(unsigned int n);
void StartTesting(const unsigned int nTestu);

#endif //JUXRVHTG_PROFILING_H
