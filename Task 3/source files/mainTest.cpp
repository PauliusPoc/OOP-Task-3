#include "../headers/Profiling.h"
#include <gmock/gmock.h>

TEST(nuskaitymas, ns){
    vector<Studentas> studentai;
    Studentas *k;
    std::ifstream fd;

    try {
        fd.open( "test.txt", std::ios::in);
        if (!fd.good()) throw "Error opening file";
    } catch (string &e){
        cout << e << endl;
        return;
    }catch (char const* e){
        cout << "Duomenu failas neegzistuoja" << endl;
        return;
    }

    while (!fd.eof()) {
        k = new Studentas(fd);
        if (fd.eof()) break;
        try {
            studentai.push_back(*k);
        }catch (std::exception exc){
            cout << exc.what() << endl;
            std::terminate();
        }
    }
    EXPECT_EQ(10, studentai.size());
    EXPECT_EQ(studentai[0].vardas(), "Pavarde1");
}
TEST(vidurkis, vid){

    std::ifstream fd;

    try {
        fd.open( "test.txt", std::ios::in);
        if (!fd.good()) throw "Error opening file";
    } catch (string &e){
        cout << e << endl;
        return;
    }catch (char const* e){
        cout << "Duomenu failas neegzistuoja" << endl;
        return;
    }
    Studentas k(fd);
    EXPECT_DOUBLE_EQ(k.Vidurkis(), double(5.6));
}
//is kolegu trina jeigu yra geekas
TEST(rusiavimas, rs){
    vector<Studentas> studentai, geek;
    Nuskaitymas(studentai, "test.txt");
    EXPECT_EQ(studentai.size(), 10);
    ArKietas(studentai,geek,true);
    EXPECT_EQ(studentai.size(), 1);
    EXPECT_EQ(geek.size(), 9);
    EXPECT_EQ(studentai[0].vardas(), "Pavarde1");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
}