#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T x);
    Node();
};

template<class T>
Node<T>::Node(T x)
{
    data = x;
    left = NULL;
    right = NULL;
}
template<class T>
Node<T>::Node()
{
    left = NULL;
    right = NULL;
}

template <class T>
class c_less
{
public:
    inline bool operator() (T a ,T b)
    {
        return a < b ;
    }
};


template<class T, class Op>
class Binario
{
public:
    Binario();
    bool BFind(T x ,Node<T> *p, Node<T> *temp);
    bool BInsert(T x);
    bool BRemove(T x);

    Node<T> *root;
    Op op;
};

template<class T, class Op>
Binario<T,Op>::Binario(){root = NULL;}


template<class T, class Op>
bool Binario<T,Op>::BFind(T x,Node<T> *p,Node<T> *temp)
{
    p = root;
    while( p != NULL && x != p->data)
    {
        temp = p;
        if(op(p->data,x))
            p = p->left;
        else
        {
            p = p->right;
        }
    }
    return !!p;
}
template<class T, class Op>
bool Binario<T,Op>::BInsert(T x)
{
    Node<T> *p =root, *temp;
    if(Bfind(x,p,temp))
        return 0;
    else
    {
        temp = new Node<T>(x);
        return 1;
    }
}


main()
{
    Binario<int,c_less<int> > *bin = new Binario<int,c_less<int> >();
}
