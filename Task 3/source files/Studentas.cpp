//
// Created by Acer on 2018-04-23.
//

#include "../headers/Studentas.h"
#include "iomanip"
using namespace std;


Studentas::Studentas(istream &input) {
    input >> pavarde_ >> vardas_;
    for (int i = 0; i < 5; i++){
        double t;
        input >> t;
        nd_.push_back(t);
    }
    input >> egzaminas_;
}


double Studentas::Vidurkis(){
    double suma{};
    suma = accumulate(nd_.begin(), nd_.end(), 0.0);
    return (suma / nd_.size())*0.4+0.6*egzaminas_;
}
double Studentas::Mediana() {
    std::sort(nd_.begin(), nd_.end());
    if (nd_.empty()) return 0.6 * egzaminas_;
    return (nd_.size() % 2 == 0 ? ((nd_[nd_.size() / 2] + (nd_[nd_.size() / 2 - 1])) / 2)
                                : nd_[(nd_.size() - 1) / 2]) * 0.4 + (0.6 * egzaminas_);
}
