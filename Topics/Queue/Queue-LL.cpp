#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node(int d) {
		data = d;
		next = NULL;
	}
};

class Queue{
private:
    node* head, *tail;
public:
	int cs;
	Queue() {
		head = tail = NULL;
		cs = 0;
	}
    void push(int d){
        if (head == NULL) {
			head = tail = new node(d);
		}
        else{
            node* n= new node(d);
            tail->next=n;
            tail=n;
        }
    }
    void pop(){
        if(head==NULL) return;

        else if(head->next==NULL){
            delete head;
            head=tail=NULL;
        }
        else{
            node* t=head;
            head=head->next;
            delete t;
        }
        cs--;
    }
    bool empty(){
        if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
    }
    int front(){
        return head->data;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}