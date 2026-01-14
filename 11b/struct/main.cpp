#include <string>
#include <fstream>
#include <iostream>
#include <map>

struct diak
{
    int id;
    std::string nev;
    std::string osztaly;
    double atlag;
};

diak legjobb_diak(const diak *diakok, int meret)
{
    diak legjobb = diakok[0];
    for (int i = 1; i < meret; ++i)
    {
        if (diakok[i].atlag > legjobb.atlag)
        {
            legjobb = diakok[i];
        }
    }
    return legjobb;
}

diak leggyengebb_diak(const diak *diakok, int meret)
{
    diak leggyengebb = diakok[0];
    for (int i = 1; i < meret; ++i)
    {
        if (diakok[i].atlag < leggyengebb.atlag)
        {
            leggyengebb = diakok[i];
        }
    }
    return leggyengebb;
}

std::map<std::string, double> osztalyok_atlagai(const diak *diakok, int meret)
{
    std::string *osztalyok = new std::string[meret];
    int osztaly_db = 0;

    for (int i = 0; i < meret; ++i)
    {
        bool van = false;
        for (int j = 0; j < osztaly_db; ++j)
        {
            if (osztalyok[j] == diakok[i].osztaly)
            {
                van = true;
                break;
            }
        }

        if (!van) osztalyok[osztaly_db++] = diakok[i].osztaly;
    }

    std::map<std::string, double> atlagok;
    for (int i = 0; i < osztaly_db; ++i)
    {
        double osszeg = 0;
        int darab = 0;
        for (int j = 0; j < meret; ++j)
        {
            if (diakok[j].osztaly == osztalyok[i])
            {
                osszeg += diakok[j].atlag;
                darab++;
            }
        }
        double osztaly_atlag = osszeg / darab;

        atlagok[osztalyok[i]] = osztaly_atlag;
    }

    return atlagok;
}

int main()
{
    std::ifstream inf("diakok.txt");
    int meret = 0;
    inf >> meret;
    diak *diakok = new diak[meret];

    for (int i = 0; i < meret; ++i)
    {
        inf >> diakok[i].id >> diakok[i].nev >> diakok[i].osztaly >> diakok[i].atlag;
    }
    inf.close();

    diak legjobb = legjobb_diak(diakok, meret);
    std::cout << "Legjobb diak: " << legjobb.id << std::endl;

    diak leggyengebb = leggyengebb_diak(diakok, meret);
    std::cout << "Leggyengebb diak: " << leggyengebb.id << std::endl;

    std::map<std::string, double> atlagok = osztalyok_atlagai(diakok, meret);
    for (const auto &osztaly : atlagok)
    {
        std::cout << osztaly.first << " " << osztaly.second << std::endl;
    }   

    return 0;
}