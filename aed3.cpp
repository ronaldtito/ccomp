#include "iostream"
#include "stdlib.h"
//#include "conio.h"
#include "time.h"
using namespace std;

template <class T>
void swap1(T *a , T *b )
{
    T temp = *a;
    *a = *b ;
    *b = temp;
}

template <class T>
void print(T *arreglo, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout <<endl;
}

// ---------------------------------
//Polymorphism

//template <class T>
class Ordenar
{
public:
    virtual bool cmp(int a, int b) = 0;
};

//template <class M>
class cless : public Ordenar /* <class T>*/
{
public:
    bool cmp(int a,int b)
    {
        return a < b;
    }
};

//template <class M>
class cgreater : public Ordenar /* <class T>*/
{
public:
    bool cmp(int a,int b)
    {
        return a > b;
    }
};

template <class T, class Op>
void sort1(T *ini , T *fin)
{
    Op orde;
    
    T *temp = ini + 1, *in = ini;
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

template <class T>
class Ordenar_PF
{
public:
    bool c_lessPF(T, T);
    bool c_greaterPF(T, T);
};

template <class T>
bool Ordenar_PF<T>::c_lessPF(T a ,T b)
{
    return a < b;
}

template <class T>
bool Ordenar_PF<T>::c_greaterPF(T a ,T b)
{
    return a > b;
}


template <class T , class Orden>
void sort2(T *ini , T *fin , bool (Orden:: *compara)(T, T))
{
    Orden operation;
    T *temp = ini + 1, *in = ini;
    while(in != fin)
    {
        while(temp > ini && (operation.*compara)(*temp, *(temp-1)))
        {
            swap1(temp , temp-1);
            temp--;
        }
        in++;
        temp= in + 1;
    }
}



// -----------------------------
// Functores
template <class T>
class c_less
{
public:
    inline bool operator() (T a ,T b)
    {
        return a < b ;
    }
};

template <class T>
class c_greater
{
public:
    inline bool operator() (T a ,T b)
    {
        return a > b ;
    }
};


template <class T, class Ope>
void sort3(T *ini , T *fin)
{
    Ope ord;
    T *temp = ini + 1, *in = ini;
    while(in != fin +1)
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
/*
void insertion (int * ini ,int *fin)
{
    int *in = ini , *x , *j;
    while( in != fin)
    {
        x = in;
    }
}*/
int main()
{
    unsigned t0 ,t1;
    //srand(time(NULL));
    int sizze = 1000000;
    int array[sizze];
    
    for(int i = 0 ; i < sizze ; i++)
    {
        array[i] = rand()%sizze;
    }
    
    int *ini, *fin;
    
    ini = &array[0]; fin =&array[sizze];
    
    /*int a[10] = {5,7,2,4,9,1,3,6,8,0};
    int *ini, *fin;
    ini = &a[0]; fin=&a[10];
    */
    
    
    
    //print<int>(ini,sizze);
    cout<<"----------"<<endl;
   
    // Polymorphism
   // /*
    t0 = clock();
    sort1<int , cgreater >(ini,fin);
    t1 = clock();
    // */
    
    
    //Puntero a Funcion
    /*
    t0 = clock();
    bool (Ordenar_PF<int>::*comparar)(int,int) = &Ordenar_PF<int>::c_greaterPF;
    sort2<int,Ordenar_PF<int> >(ini,fin,comparar);
    t1 = clock();
    // */
    
    
    //Function Object
     /*
    t0 = clock();
    sort3<int,c_greater<int> >(ini,fin);
    t1 = clock();
    // */
    
   // print<int>(ini,sizze);
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
}
