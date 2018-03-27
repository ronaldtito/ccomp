#include <iostream>
#include <time.h>
#include "stdlib.h"

using namespace std;


void swap1(int *a , int *b )
{
    int temp = *a;
    *a = *b ;
    *b = temp;
}


void print(int *arreglo, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout <<endl;
}

bool ascendente (int a, int b)
{
    return a < b;
}

bool descendente(int a, int b)
{
    return a>b;
}

// ---------------------------------
//Polymorphism
class Ordenar
{
public:
   virtual bool cmp(int a, int b ) = 0;
};

class cless : public Ordenar
{
public:
    bool cmp(int a, int b)
    {
        return a < b;
    }
};

class cgreater : public Ordenar
{
public:
    bool cmp(int a, int b)
    {
        return a > b;
    }
};
   //insertion
template </*class T,*/ class Op>
void sort1(int *ini , int *fin)
{
    Op orde;
    int *temp = ini + 1, *in = ini;
    while(in != fin)
    {
        while(temp > ini && orde.cmp(*temp, *(temp-1)))
        {
            swap1(temp , temp-1);
            temp-=1;
        }
        in++;
        temp= in + 1;
    }
}

//---------------------------
// Puntero a funcion
//template <class T>
class Ordenar_PF
{
public:
    bool c_lessPF(int, int);
    bool c_greaterPF(int, int);
};

//template <class T>
bool Ordenar_PF::c_lessPF(int a , int b)
{
    return a < b;
}

//template <class T>
bool Ordenar_PF::c_greaterPF(int a , int b)
{
    return a > b;
}
   // insertion

template <class Orden>
void sort2(int *ini , int *fin , bool (Orden:: *compara)(int, int))
{
    Orden operation;
    int *temp = ini + 1, *in = ini;
    while(in != fin)
    {
        while(temp > ini && (operation.*compara)(*temp, *(temp-1)))
        {
            swap1(temp , temp-1);
            temp-=1;
        }
        in++;
        temp= in + 1;
    }
}

//void sort2(int *ini , int *fin , bool (*cmp)(int, int))
//{
//    int *temp = ini + 1, *in = ini;
//    while(in != fin)
//    {
//        while(temp > ini && cmp(*temp, *(temp-1)))
//        {
//            swap1(temp , temp-1);
//            temp-=1;
//        }
//        in++;
//        temp= in + 1;
//    }
//}

// -----------------------------
// Functores
class c_less
{
public:
    inline bool operator() (int a ,int b)
    {
        return a < b ;
    }
};

class c_greater
{
public:
    inline bool operator() (int a ,int b)
    {
        return a > b ;
    }
};
      //insertion
template </*class T,*/ class Ope>
void sort3(int *ini , int *fin)
{
    Ope ord;
    int *temp = ini + 1, *in = ini;
    while(in != fin)
    {
        while(temp > ini && ord(*temp, *(temp-1)))
        {
            swap1(temp , temp-1);
            temp-=1;
        }
        in++;
        temp= in + 1;
    }
}

// --------------
int main()
{

    unsigned t0, t1;

    srand(time(NULL));
    int sizze = 100000;
    int b[sizze];
    for(int i = 0 ;i < sizze; i++)
    {
        b[i] = rand()% sizze;
    }
    int *ini, *fin;
    ini = &b[0]; fin = &b[sizze];

    //----------------
    //print(ini,5000);

    /*
    t0=clock();
    sort1<cless>(ini,fin);
    t1 = clock();
    */


    //bool (*com)(int a, int b) = ascendente;

    /*
    t0=clock();
    bool (Ordenar_PF::*comparar)(int,int) = &Ordenar_PF::c_lessPF;
    sort2<Ordenar_PF>(ini, fin, comparar);
    t1=clock();
    //*/


    /*
    t0=clock();
    sort3<c_less>(ini,fin);
    t1=clock();
    //*/


    print(ini,5000);
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

}
