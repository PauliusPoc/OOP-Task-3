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

### Programos veikimo sparta aprašyta v1.0.1 bei v0.5 changeloguose (žemiau)

## Versijų istorija (changelog)

# [Changelog v1.0.1 (2018-04-05)](https://github.com/paulyskas/OOP-Task-2/releases/tag/v1.0.1)
## *Pridėta*

- 2 Template'ai *ArKietas* funkcijoms pritaikyti skirtingoms strategijoms, pateiktose [reikalavimuose](https://github.com/objprog/praktika/wiki/2-oji-u%C5%BEduotis#reik-versijai-1.0)
- Pridėti skaičiavimo algoritmai accumulate
- Pridėtas remove_if algoritmas
- **Išmatuoti programos veikimo greičiai:**

1 Strategija: duomenų rikiavimas juos išskirstan tarp 3 skirtingų konteinerių
2 Strategija: duomenų rikiavimas juos išskirstant tarp 2 skirtingų konteinerių (trinant)

n - duomenų skaičius

### Matuojame laiką dirbdami su vector

|Funkcija                     |n = 10    |n = 100     |n = 1000    |n = 10000   |n = 100000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Duomenų nuskaitymas iš failo |0.0015039 s|0.0049565 s|0.0200548 s|0.202248 s|1.99347 s|
|Duomenų išrikiavimas (skirstant)|0        s|0         s|0.0005018 s|0.0060171 s|0.0647589 s|
|Duomenų išrikiavimas (trinant)  |0        s|0        s|0.0005015 s|0.004011 s|0.0396056 s|

### Matuojame laiką dirbdami su list

|Funkcija                     |n = 10    |n = 100     |n = 1000    |n = 10000   |n = 100000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Duomenų nuskaitymas iš failo |0.0010029 s|0.0027926 s|0.0190516 s|0.222091 s|1.96827 s|
|Duomenų išrikiavimas (skirstant)|0        s|0         s|0.0005018 s|0.0045121 s|0.0451439 s|
|Duomenų išrikiavimas (trinant)  |0        s|0      s|0.0005014 s|0.0040106 s|0.0431163 s|

### Matuojame laiką dirbdami su deque

|Funkcija                     |n = 10    |n = 100     |n = 1000    |n = 10000   |n = 100000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Duomenų nuskaitymas iš failo |0.0005006 s|0.0025072 s|0.0190493 s |0.210573 s|1.89855 s|
|Duomenų išrikiavimas (skirstant)|0        s|0         s|0.000503 s |0.0050139 s|0.0406081 s|
|Duomenų išrikiavimas (trinant)  |0        s|0         s|0 s |0.0040099 s|0.0395513 s|



## *Ištrinta*

- Funkcijos `ListArKietas, DequeArKietas`

# [Changelog v1.0 (2018-04-03)](https://github.com/paulyskas/OOP-Task-2/releases/tag/v1.0)
## *Pridėta*

- Pagaliau pridėtas GUI pasirinkimas nr. 3: "Generavimas/profiliavimas".
- Implementuota 2-a strategija  *(Bendro studentų konteinerio skaidymas panaudojant tik vieną naują konteineri)*

# [Changelog v0.5 (2018-03-14)](https://github.com/paulyskas/OOP-Task-2/releases/tag/v0.5)
## *Pridėta*

- Pridėtos funkcijos `profiling.cpp` faile:
  ```c++ 
    ListArKietas
    DequeArKietas
    ListStartProfiling
    DequeStartProfiling
  ```
- Išmatuoti programos veikimo laikai naudojant *vector, list, deque* konteinerius

## Matavimai:

### Vector:

|Funkcija                     |n = 10    |n = 100     |n = 1000    |n = 10000   |n = 100000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Duomenų nuskaitymas iš failo |0.0015054 s|0.003069 s|0.0200534 s |0.194018 s|2.04896 s|
|Duomenų išrikiavimas |0        s|0         s|0.0005021 s |0.0050113 s|0.0626618 s|

### List:

|Funkcija                     |n = 10    |n = 100     |n = 1000    |n = 10000   |n = 100000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Duomenų nuskaitymas iš failo |0.0004999 s|0.0196077 s|0.0199956 s |0.194074 s|2.01492 s|
|Duomenų išrikiavimas |0        s|0         s|0.0005022 s |0.004512 s|0.0481287 s|

### Deque:

|Funkcija                     |n = 10    |n = 100     |n = 1000    |n = 10000   |n = 100000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Duomenų nuskaitymas iš failo |0.0005026 s|0.021055 s|0.190506 s|0.194074 s|1.91818 s|
|Duomenų išrikiavimas |0        s|0         s|0.0005026 s |0.0060167 s|0.0426704 s|


## *Pakeista*

- Funkcija `nTestu` faile `main.cpp` ištrinta, ir jos vidus perkeltas į paprastą if statement *29*-oje `main.cpp` eilutėje.

# [Changelog v0.4 (2018-03-14)](https://github.com/paulyskas/OOP-Task-2/releases/tag/v0.4)
## *Pridėta*

- Generuojami failai su atsitiktiniais studentų įrašais.
  - Failai generuojami 10,100,1000 ir t.t. įrašų, `main.cpp` failo funkcijoje Performance pasirenkant norimą failų kiekį pagal šią progresiją.
  - Vieno iš failų fragmento pavyzdys:
![randgeneratedfailas](https://user-images.githubusercontent.com/31746944/38517458-bdcf70a8-3c42-11e8-8237-cf56e3a99a19.JPG)

- Studentai rūšiuojami į **geek'us** ir **loserius** `profiling.cpp` faile, `ArKietas` funkcijoje, pagal galutinius jų gautus įvertinimus.

- Išmatuotas programos veikimo greitis 

### Gauti matavimų rezultatai:

|Funkcija                     |n = 10    |n = 100     |n = 1000    |n = 10000   |n = 100000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Duomenų generavimas |0.0005022 s|0.0025249 s|0.0221172 s |0.21156 s|2.08855 s|
|Duomenų nuskaitymas iš failo |0.0015054 s|0.0199956 s|0.0199956 s |0.194016 s|1.92907 s|
|Duomenų išrikiavimas |0        s|0         s|0.0005021 s |0.005072 s|0.0516376 s|
|Iš viso |0.0020076 s|0.0055346 s|0.0426149 s|0.410648 s|4.06926 s|


# [Changelog v0.3 (2018-03-06)](https://github.com/paulyskas/OOP-Task-2/releases/tag/v0.3)
## *Pridėta*

- Kodas iš `main.cpp`  **refactorintas** į `DarbasFailais.cpp`, `IvestiesMetodai.cpp`, `SkaiciavimoBudai.cpp`, kaip ir header failai tuo pačiu pavadinimu.
- Pridėtas **exception handling** kur tai implementuoti yra naudos.

## *Pakeista*

- Duomenų struktūros perkeltos į header failus

# [Changelog v0.2 (2018-02-27)](https://github.com/paulyskas/OOP-Task-2/releases/tag/v0.2)
## *Pridėta*
- Pridėta galimybė nuskaityti failus, su tokia struktūra:
![kolegos](https://user-images.githubusercontent.com/31746944/38359649-9bc800ac-38d1-11e8-9884-ac24d4ff0389.JPG)
- Nuskaičius failus, jų duomenys surikiuojami  pagal galutinį balą didėjimo tvarka faile `output.txt`
![output](https://user-images.githubusercontent.com/31746944/38359680-a1403d92-38d1-11e8-8bb2-9e5bf02144c3.JPG)

# [Changelog v0.1.1 (2018-02-22)](https://github.com/paulyskas/OOP-Task-2/releases/tag/v0.1.1)
## *Pridėta*
- Ištaisyta žiopla klaida Suma funkcijose (pridėtos ``` n++; ``` eilutės, kad skaičiavimai veiktų).

# [Changelog v0.1 (2018-02-21)(https://github.com/paulyskas/OOP-Task-2/releases/tag/v0.1)

