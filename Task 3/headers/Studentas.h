//
// Created by Acer on 2018-04-23.
//

#ifndef TASK_3_STUDENTAS_H
#define TASK_3_STUDENTAS_H

#include "iostream"
#include "fstream"
#include "string"
#include "vector"
#include "algorithm"



// Reikia includinti visas priklausomybes: <iostream>, <string>, <vector>, "mediana.h"
class Studentas {
// realizacija
private:
    std::string vardas_;
    std::string pavarde_;
    double egzaminas_;
    std::vector<double> nd_;
// interfeisas
public:
    Studentas() : egzaminas_(0) { }  // default konstruktorius

    bool operator==(Studentas &a){
        return (vardas_==a.vardas() && pavarde_&&a.)
    }

    explicit Studentas(std::istream& input);
    inline std::string vardas() const { return vardas_; }    // get'eriai, inline
    inline std::string pavarde() const { return pavarde_; }  // get'eriai, inline


    double Mediana();
    double Vidurkis();
};

#endif //TASK_3_STUDENTAS_H
