//
// Created by Acer on 2018-03-13.
//

#ifndef JUXRVHTG_PROFILING_H
#define JUXRVHTG_PROFILING_H

#include "DarbasFailais.h";

#include <random>
#include <chrono>
#include <algorithm>
#include <deque>
#include <list>

using std::mt19937;

void ArKietas(vector<Kolega> &koleg, vector<Kolega> &geek, vector<Kolega> &lose, bool arVidurkiu);
void ListArKietas(list<Kolega> &koleg, list<Kolega> &geek, list<Kolega> &lose, bool arVidurkiu);
void DequeArKietas(deque<Kolega> &koleg, deque<Kolega> &geek, deque<Kolega> &lose, bool arVidurkiu);
void StartProfiling(unsigned int n, ofstream &pr, unsigned int met);
void ListStartProfiling(unsigned int n, ofstream &pr, unsigned int met);
void DequeStartProfiling(unsigned int n, ofstream &pr, unsigned int met);
void GeneruokTestui(unsigned int n, ofstream &fk);
void StartTesting(const unsigned int nTestu);

#endif //JUXRVHTG_PROFILING_H
