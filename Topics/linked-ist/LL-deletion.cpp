#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int d){
        data =d;
        next =NULL;
    }
};
void insertatend(node* &head ,node* &tail,int d ){
    if(head==NULL){
        node* n=new node(d);
        head =tail=n;
    }
    else{
        node* n=new node(d);
        tail->next=n;
        tail=n;
    }
}

void delteatfront(node* &head ,node* &tail,int d){
    if(head==NULL) return;
    else if(head->next==NULL){
        delete head;
        head=tail=NULL;
    }
    else{
        node* temp=head;
        head=head->next;
        delete temp;
    }
}
int main(){
    node* head,*tail;
    head=tail=NULL;
    insertatend(head,tail,1);
    insertatend(head,tail,2);
    insertatend(head,tail,3);
    insertatend(head,tail,4);
    insertatend(head,tail,5);
}