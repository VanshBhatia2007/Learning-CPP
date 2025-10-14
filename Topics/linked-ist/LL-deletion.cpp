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
void deleteAtEnd(node* &head, node* &tail) {
	node* t = head;
	while (t->next != tail) {
		t = t->next;
	}

	delete tail;
	t->next = NULL;
	tail = t;
}
void delteatfront(node* &head ,node* &tail){
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
void deleteAtMiddle(node* &head, node*& tail, int pos) {
	if (pos == 0) {
		delteatfront(head, tail);
	}
	else if (pos >= length(head) - 1) {
		deleteAtEnd(head, tail);
	}
	else {
		node* t = head;
		for (int i = 0; i < pos - 1; ++i)
		{
			t = t->next;
		}

		node* n = t->next;
		t->next = n->next;
		delete n;
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
int main(){
    node* head,*tail;
    head=tail=NULL;
    insertatend(head,tail,1);
    insertatend(head,tail,2);
    insertatend(head,tail,3);
    insertatend(head,tail,4);
    insertatend(head,tail,5);
}