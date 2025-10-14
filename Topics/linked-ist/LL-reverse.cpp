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
int length(node* head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"NULL\n";
}

//reverse

void reverse(node* &head,node* &tail){
    node* c=head,*p=NULL, *n;
    while(c!=NULL){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    swap(head,tail);
}
int main(){
    node* head,*tail;
    head=tail=NULL;
    insertatend(head,tail,1);
    insertatend(head,tail,2);
    insertatend(head,tail,3);
    insertatend(head,tail,4);
    insertatend(head,tail,5);
    print(head);
    reverse(head,tail);
    print(head);
}