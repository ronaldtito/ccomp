#include <iostream>
using namespace std;


class Nodo{
public:
    int val;
    Nodo *next;
};

class LISTAS
{
public:
    Nodo *head;
    LISTAS();
  //  void create(int );
  //  void push(int );
    void insertar(int , int );
  //  int pop(int );
    void eliminar_nodo(int );
  //  void vacio();
    void print();
};

LISTAS::LISTAS()
{
    head=NULL;
}

void LISTAS::create(int n){
    Nodo *prev, *cur;
    head->val=1;
    prev = head;
    for(int i=2;i<=n;i++){
        cur=new Nodo();
        cur->val=i;
        prev->next=cur;
        prev=cur;
    }
    prev->next=NULL;
}

void LISTAS::push(int x){
    Nodo *nuevo,*temp;
    nuevo =new Nodo();
    nuevo->val=x;
    temp=head;
    if(head==NULL){
        head=nuevo;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nuevo;
    }
}
void LISTAS::insertar(int pos, int x){
    Nodo *nuevo,*temp,*prev;
    nuevo=new Nodo();
    nuevo->val=x;
    if(pos==1){
        nuevo->next=head;
        head=nuevo;
    }
    else{
        temp=head;
        for(int i = 1; i <=pos-2; i++){
            temp = temp->next;
        }
        prev=temp->next;
        temp->next=nuevo;
        nuevo->next=prev;
    }
}

int LISTAS::pop(int pos){
    int valor;
    Nodo *temp, *prev, *cur;
    if(pos == 1){
        valor =head->val;
        temp=head;
        head=head->next;
        delete temp;
    }
    else{
        cur=head;
        for(int i = 1; i <=pos-2;i++){
            cur = cur->next;
        }
        prev = cur->next;
        cur->next=prev->next;
        valor = prev->val;
        temp=prev;
        delete temp;
    }
    return valor;
}

void LISTAS::eliminar_nodo(int key){
    Nodo *prev, *cur, *tem;
    cur = head ->next;
    if(head->val==key){
        tem=head;
        head=head->next;
        delete tem;
    }
    else{
        while(cur != NULL){
            if(cur->val == key){
                prev->next = cur->next;
                delete cur;
                break;
            }
            prev=cur;
            cur=cur->next;
        }
    }
}

void LISTAS::print(){
    Nodo *tem;
    tem=head;
    while(tem != NULL){
        cout<<tem->val<<" ";
        tem=tem->next;
    }
    cout<<endl;
}


int main() {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
