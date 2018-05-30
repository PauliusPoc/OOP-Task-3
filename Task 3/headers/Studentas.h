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



///Studentus apibrėžianti klasė
class Studentas {
// realizacija
private:
    ///Studento vardas
    std::string vardas_;
    ///Studento pavardė
    std::string pavarde_;
    ///Studento egzamino balas
    double egzaminas_;
    ///Studento pažymių vektorius
    std::vector<double> nd_;
// interfeisas
public:
    ///default Studentas konstruktorius
    Studentas() : egzaminas_(0) { }

    /// Išveda Studento klasės objekto vardą, pavardę, galutinį balą skaičiuojant vidurkiu ir mediana
    friend std::ostream &operator<<(std::ostream &output, Studentas &S){
        output << S.vardas_ << " " << S.pavarde_ << " " << S.Vidurkis() << " " << S.Mediana() << std::endl;
    }

    ///Pažiūrima ar Studento vardas ir pavardė sutampa su kito Studento
    bool operator==(const Studentas &a){
        return (vardas_==a.vardas_ && pavarde_==a.pavarde_);
    }
    /// Pažiūrima ar Studento vardas abeceles tvarka turetu eiti po kito Studento
    bool operator<(const Studentas &a){
        return (vardas_<a.vardas_);
    }
    /// Pasižiūrima blablabla loginio operatoriaus overloada tereikėjo pritaikyti
    bool operator<=(const Studentas &a){
        return (vardas_<=a.vardas_);
    }
    /// Pasižiūrima blablabla loginio operatoriaus overloada tereikėjo pritaikyti
    bool operator>=(const Studentas &a){
        //return (pavarde_>=a.pavarde_);
        return !operator<(a);
    }

    /**
 * Sukonstruoja Studento objektą iš duomenų įvesties stream'o.
 * @param input įvesties stream'as
 */
    explicit Studentas(std::istream& input);

    ///Gražina Studento vardą
    inline std::string vardas() const { return vardas_; }
    ///Gražina Studento pavardę
    inline std::string pavarde() const { return pavarde_; }

    ///Skaičiuoja Studento galutinį balą pagal medianą
    double Mediana();
    ///Skaičiuoja Studento galutinį balą pagal Vidurkį
    double Vidurkis();
};

#endif //TASK_3_STUDENTAS_H
