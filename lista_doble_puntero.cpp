#include <iostream>
using namespace std;


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
    Node();
    Node(T x);
};

template <class T>
Node<T>::Node(){ next = NULL;}

template <class T>
Node<T>::Node(T x){ data = x ;next = NULL;}


template <class T , class Op>
class Clist
{
public:
    Node<T> * head;
    bool Find(T x, Node<T> **&p);
    bool Insert(T x);
    bool Remove(T x);
    void Print();
    Clist();
    ~Clist();
};

template <class T, class Op>
Clist<T,Op>::Clist(){ head = NULL;}

template <class T, class Op>
Clist<T, Op>::~Clist()
{
    Node<T> **temp = &head, **prev;
    while(( *temp )!= NULL )
    {
        (*prev)=(*temp)->next;
        delete *temp;
        temp=prev;
    }
}

template <class T , class Op>
bool Clist<T,Op>::Find(T x, Node<T> **&p)
{
    Op op;
    for(p= &head; *p != NULL && op((*p)->data, x) ; p = &(*p)->next);
    if((*p) != NULL && (*p)->data == x )
        return true;
    else
        return false;
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

template <class T, class Op>
void Clist<T, Op>::Print()
{
    Node<T> *temp=head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Clist<int, c_less<int> > *Lista1 = new Clist<int, c_less<int> >();
    Lista1->Insert(5);
    Lista1->Insert(3);
    Lista1->Insert(2);
    Lista1->Insert(10);
    Lista1->Insert(4);
    Lista1->Remove(3);
    Lista1->Remove(2);
    Lista1->Print();
    //delete Lista1;
    
}
