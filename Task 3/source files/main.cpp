#include "../headers/Profiling.h"

int main() {


    m1:
    cout << "Pasirinkite: \n1-Failo generavimas\n 2-Profiliavimas\n";
    char pas{};
    cin >> pas;
    if (pas != '1' & pas != '2'){
        cout << "toks pasirinkimas negalimas\n";
    }
    if (pas == '1')
    {
        const unsigned int nTestu = 5; // kiek testų failų generuoti
        GeneruokTestui(nTestu);
        goto m1;
    }
    if (pas == '2'){
        StartTesting(5);
    }

    return 0;

}





