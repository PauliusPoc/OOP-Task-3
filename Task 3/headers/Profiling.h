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

///return Gražina ar studento galutinis balas didesnis už "ribinį" balą
bool RibaV (Studentas&);
///return Gražina ar studento galutinis balas didesnis už "ribinį" balą
bool RibaM (Studentas&);

/**
 * Studentų rūšiavimo funkcija
 * @tparam T norimas konteinerio/klasės tipas
 * @param koleg  Studentų konteineris
 * @param geek "Gerųjų" Studentų konteineris
 * @param arVidurkiu pažymių skaičiavimo būdas. (true) jei vidurkiu, (false) jeigu mediana
 */
template<typename T> void ArKietas(T &koleg, T &geek, bool arVidurkiu);
/**
 * Profiliavimmo funkcija
 * @param n laipsnio rodiklis, kiek įrašų bus faile (n^10)
 * @param pr išvesties failo pavadinimas
 * @param met skaičiavimo metodo numeris (Vidurkis ar Mediana)
 */
void StartProfiling(unsigned int n, ofstream &pr, unsigned int met);

/**
 * Įvesties failų generavimas
 * Sukuria tiek failų, atitinkamai pagal n dydį.
 * @param n laipsnio rodiklis, kiek įrašų bus faile (n^10)
 *
 */
void GeneruokTestui(unsigned int n);
/**
 * Pasiruošimas profiliavimo testui
 * @param nTestu nurodytas norimų testų kiekis
 */
void StartTesting(const unsigned int nTestu);

#endif //JUXRVHTG_PROFILING_H
