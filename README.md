# Pauliaus Pociaus objektinio programavimo 2 užduotis. (VU ISI 1 kursas)

# Vertinimas 

## Programos veikimas
- Programoje nuskaitomi tokie duomenys:
  - Studento vardas, pavardė
  - Studento n atliktų darbų įverčiai dešimtbalėje sistemoje
  - Galutinio egzamino rezultatas dešimtbalėje sistemoje
- Pagal įvestus duomenis apskaičiuojamas galutinis balas pasirenkamai (pagal vidurkį arba medianą)
- Surinkti duomenys išvedami į ekraną arba į rezultatų failą.
- Vartotojui suteikiama galimybė pažymius generuoti automatiškai.
- Vartotojas gali išmatuoti programos veikimo greitį ir gauti rezultatus į rezultatų failą.
## Programos išvedimas
```shell
Pasirinkite:
1-Failo nuskaitymas
 2-Ivedimas ranka
 3-Generavimas/profiliavimas2
2
Studento vardas:
Augustinas
Studento pavarde:
Makevicius
Pasirinkite ivedimo tipo buda:
 Vektoriai -1
 Masyvas -2
1
Pasirinkite ivedimo buda:
 AutoRandom-1
 Rankomis-2
1
Kiek pazymiu generuoti?10
 10
Pasirinkite skaiciavimo buda:
 Mediana-1
 Vidurkis-2
1
Augustinas Makevicius
Namu darbu pazymiai:
2.17
2.29
2.33
3.61
5.52
6.27
6.42
6.63
7.09
9.48
Egzamino pazimys: 3.68
Galutinis pazimys: 2.44

Process finished with exit code 0
```
## Įdiegimas naudojant `GCC`kompiliatorių 

- `git clone https://github.com/paulyskas/OOP-Task-2.git`
- `cd OOP Task 2`
- `cmake . -G "MinGW Makefiles"`
- `mingw32-make`
- `.\OOP Task 2`
