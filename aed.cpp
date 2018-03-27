
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
void sort2(int *ini , int *fin , bool (Orden:: *cmp)(int, int))
{
    Orden ord;
    int *temp = ini + 1, *in = ini;
    while(in != fin)
    {
        while(temp > ini && ord.*cmp(*temp, *(temp-1)))
        {
            swap1(temp , temp-1);
            temp-=1;
        }
        in++;
        temp= in + 1;
    }
}

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
    srand(time(NULL));
    int b[5000];
    for(int i = 0 ;i < 5000; i++)
    {
        b[i] = rand()% 5000;
    }
   // Ordenar_PF ordenar;
    
    bool (Ordenar_PF::*cmp)(int,int) = &Ordenar_PF::c_lessPF;
    
    ////
    int a[11] = {6,7,1,4,2,9,3,0,5,8,10};
    int *ini, *fin;
    ini = &a[0]; fin = &a[10];
    print(ini,11);
    //sort1<cless>(ini,fin);
    sort2<Ordenar_PF>(ini, fin, cmp);
    print(ini,11);
    cout<< fin;
}
