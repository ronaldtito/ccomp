#include <stdio.h>
struct node{
    int val;
    struct node *next;
};

int create(int n){
    int i;
    struct node *head,*prev,*cur;
    head=malloc(sizeof(struct node));
    head-> val=1;
    prev=head;
    for(i=2;i<=n;i++){
        cur=malloc(sizeof(struct node));
        cur->val=i;
        prev->next=cur;
        prev=cur;
    }
    prev->next=NULL;
    return head;
}
void imprimir(struct node *head){
    struct node *t;
    t=head;
    while(t!=NULL){
        printf("%d",t->val);
        t=t->next;
    }
}
int eliminar(struct node *head, int n){
    struct node *prev, *cur,*temp;
//    prev=malloc(sizeof(struct node));
//    cur=malloc(sizeof(struct node));
    if(head->val==n){
        temp=head;
        head=head->next;
        free(temp);
    }
    else{
        prev=head;
        cur=head->next;
        while(cur!= NULL){
            if(cur->val==n){
                prev->next=cur->next;
                free(cur);
                break;
            }
        }
        prev=cur;
        cur=cur->next;
    }
    return head;
}
//int insertar(struct node *head, int n){
//    struct node *prev, *cur,*tem;
//    int a=1,b=1;
//    prev=malloc(sizeof(struct node));
//    cur=malloc(sizeof(struct node));
//    prev=head;
//    cur=prev->next;
//    while(cur!=NULL){
//        cur=cur->next;
//        a++;
//        }
//    a/=2;
//    while(b<=a){
//        prev=prev->next;
//        b+=1;
//    }
//    tem=malloc(sizeof(struct node));
//        tem->val=prev;
//        tem->next=prev;
//        head->next=tem;

//    while(cur->val<n){
//        cur=malloc(sizeof(struct node));
//        prev=prev->next;
//        cur=cur->next;
//    }
//    if(cur->val!=n){
//        tem=malloc(sizeof(struct node));
//        tem->val=cur;
//        tem->next=cur;
//        prev->next=tem;
//    }
//return head;
//}
void doble(struct node *head1, struct node *head2){
    struct node *begin;
    begin=malloc(sizeof(struct node));
    begin=head1;
    while(begin!=NULL){
        begin=head1->next;
    }
    begin->next=head2;
    printf("%d",begin->next);
}
int begining(struct node *head, int n){
    struct node *begin;
    begin=malloc(sizeof(struct node));
    begin->val=n;
    begin->next=head;
    return begin;
}
main(){
    struct node *head;
    struct node *head2;                            h
    head=create(5);
    head2=create(4);
    imprimir(doble(head,head2));
}

