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


template <class T>
class Node{
public:
    T data;
    Node *next;
    Node();
    Node(T x);
};

template <class T>
Node<T>::Node(){ next = NULL;}

template <class T>
Node<T>::Node(T x){ data = x ;next = NULL;}


template <class T,  class Op>
class LISTA
{
public:
    Node<T> *head;
    LISTA();
    bool find(T x , Node<T> *&p, Node<T> *&prev);
    bool insertar(T x);
    bool eliminar_nodo(T x);
    void print();
};

template <class T, class Op>
LISTA<T,Op>::LISTA()
{
    head=NULL;
}

template <class T, class Op>
bool LISTA<T,Op>::find(T x, Node<T> *&p,Node<T> *&prev)
{
    Op op;
    for(p = head; p != NULL && op(p->data, x); p = p->next)
        prev = p;
    if(p != NULL && x == p->data )
            return true;
    else
        return false;
}

template <class T, class Op>
bool LISTA<T, Op>::insertar(T x){
    
    Node<T> *nuevo,*temp=head,*prev;
    
    nuevo=new Node<T>(x);
    
    
    if( temp == NULL )
    {
        head = nuevo;
        return true;
    }
    if(temp->data > x)
    {
        nuevo->next=head;
        head=nuevo;
    }
    
    if(find(x, temp,prev))
    {
        return false;
    }
    prev->next = nuevo;
    nuevo->next = temp;
    return true;
}

template<class T , class Op>
bool LISTA<T, Op>::eliminar_nodo(T x){
    Node<T> *prev, *cur, *temp;
    
    cur = head->next;

    temp = head;
    
    if(temp->data==x){
        head=temp->next;
        delete temp;
    }
    
    else
    {
        if(find(x, temp, prev))
        {
            prev->next = temp->next;
            delete temp;
            return true;
        }
    }
    return false;
}


template <class T, class Op>
void LISTA<T, Op>::print(){
    Node<T> *temp;
    temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main() {
    LISTA<int, c_less<int> > *Lista1 = new LISTA<int , c_less<int> >();
    Lista1->insertar(5);
    Lista1->insertar(3);
    Lista1->insertar(2);
    Lista1->insertar(10);
    Lista1->insertar(4);
    Lista1->eliminar_nodo(2);
    Lista1->print();
    
}
