#include "SkaiciavimoBudai.h"

double Mediana(double egz, double varEil[], int &size) {
    sort(varEil, varEil + size);

    double ats{};

    if (size == 0) return 0.6 * egz;
    else if (size % 2 == 0) ats = ((varEil[size / 2] + (varEil[size / 2 - 1])) / 2);
    else ats = varEil[(size - 1) / 2];

    return 0.4 * (ats / size) + (0.6 * egz);
}


double Mediana(double egz, vector<double> &varEil) {
    sort(varEil.begin(), varEil.end());

    double ats{};

    if (varEil.empty()) return 0.6 * egz;
    else if (varEil.size() % 2 == 0) ats = ((varEil[varEil.size() / 2] + (varEil[varEil.size() / 2 - 1])) / 2);
    else ats = varEil[(varEil.size() - 1) / 2];

    return 0.4 * (ats / varEil.size()) + (0.6 * egz);
}

double Suma(double egz, vector<double> varEil) {
    int suma{}, n{};
    if (varEil.empty()) return 0.6 * egz;
    for (auto v:varEil) {
        suma += v;
        n++;
    }
    return 0.4 * (suma / n) + (0.6 * egz);
}

double Suma(double egz, double *&varEil, int &size) {
    int suma{}, n{};
    for (int i = 0; i < size; i++) {
        suma += varEil[i];
        n++;
    }
    if (suma == 0) return 0.6 * egz;
    return 0.4 * (suma / n) + (0.6 * egz);
}