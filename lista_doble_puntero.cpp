#include <iostream>



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

//--------
template<class T>
class Node
{
public:
    T data;
    Node * next;
};

template <class T , class Op>
class Clist
{
public:
    Node<T> * head;
    bool Find(T x, Node<T> **&p);
    bool Insert(T x);
    bool Remove(T x);
    void Print();
};

template <class T , class Op>
bool Clist<T,Op>::Find(T x, Node<T> **&p)
{
    Op op;
    for(p= &head; *p != NULL && op((*p)->data, x) ; p = &(*p)->next);
    /*if((*p) != NULL && (*p)->data == x )
        return true;
    else
        return false;*/
    return (*p) && (*p)->data == x;
}

template <class T , class Op>
bool Clist<T,Op>::Insert(T x)
{
    Node<T> **p;
    if(Find(x,p))
        return false;
    
    Node<T> *N = new Node<T> (x);
    N->next = *p;
    *p=N;
    return true;
}

template <class T , class Op>
bool Clist<T,Op>::Remove(T x)
{
    Node<T> **p;
    if(Find(x , p))
    {
        Node<T> *N = (*p);
        *p = N->next;
        delete N;
        return true;
    }
    return false;
}

int main() {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
