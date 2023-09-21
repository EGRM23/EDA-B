#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include <iomanip>
using namespace std;

constexpr int FLOAT_MIN = 0;
constexpr int FLOAT_MAX = 1;

int main()
{
    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<float> distr(FLOAT_MIN, FLOAT_MAX);

    int d = 4000; //dimensiones
    int c = 40000; //cantidad de puntos

    //creacion de la matriz que guardara nuestros puntos y sus coordenadas
    double** n = new double*[c];
    for (int i = 0; i < c; i++)
    {
        n[i] = new double[d];
        for (int j = 0; j < d; j++)
        {
            n[i][j] = distr(eng);
        }
    }

    //hallando las distancias
    double tempdist = 0;
    //int contador = 0;

    ofstream dist("distancias_"+to_string(d)+"D.txt");
    dist << "X";
    for (int p1 = 0; p1 < c; p1++)
    {
        for (int p2 = c-1; p2 > p1; p2--)
        {
            tempdist = 0;
            for (int i = 0; i < d; i++)
            {
                tempdist += pow(n[p1][i] - n[p2][i],2);
            }
            dist << "\n" << setprecision(4) << sqrt(tempdist);
            //contador++;
        }
    }
    dist.close();

    //cout << contador;
    for (int i = 0; i < c; i++)
    {
        delete [] n[i];
    }
    delete [] n;
    return 0;
}