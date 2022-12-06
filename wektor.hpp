#include<iostream>
using namespace std;
class Wektor
{
private:
    int dlugosc;
    int pojemnosc;
    double* tab;
public:
    
    Wektor(int n){
        tab=new double[n];
        for (int i = 0; i < n; i++)
        {
            tab[i]=0.0;
        }
        dlugosc=n;
        pojemnosc=n;
    };
    ~Wektor(){
        delete[] tab;
        cout << "tablica usunieta" << endl;
    };
    void getterDlugosc() 
    {
        cout << "dlugosc wynosi" << dlugosc << endl;
    }
    void getterPojemnosc() 
    {
        cout << "pojemnosc wynosi" << dlugosc << endl;
    }
    void print()
    {
        cout << "kolejne argumenty wektora:" << endl;
        for (int i = 0; i < dlugosc; i++)
        {
            cout << tab[i] << endl;
        }      
    };
    void zmienDlugosc(int d)
    {
        if (d<= dlugosc) 
        {
            for (int i = 0; i < dlugosc; i++)
            {
                tab[i]=0.0;
            }
            dlugosc=d;
        } 
        else
        {
            double* tab2=tab;
            tab=new double[d];
            for (int i = 0; i < dlugosc; i++)
            {
                tab[i]=tab2[i];
            }
            for (int i = dlugosc; i < d; i++)
            {
                tab[i]=0.0;
            }
            pojemnosc=d;
            dlugosc=d;
            delete[] tab2;
        }    
    };
    double& operator[](int index)
    {
        if (index>=dlugosc)
        {
            zmienDlugosc(index);
        }
        return tab[index];        
    }
};

struct Kokardka
{
    Kokardka() {dlugosc=42;}
    Kokardka(int d) {dlugosc=d;}
    
    int dlugosc;
};

struct Prezent
{
    Prezent(int dk)
    {
        cout << k.dlugosc << endl;
        k.dlugosc=dk;
        cout << k.dlugosc << endl;
    }
    
    Kokardka k;
    // Inne pola ...
};
