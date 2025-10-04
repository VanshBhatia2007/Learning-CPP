#include<iostream>
#include <cstring>
using namespace std;

//blueprint

class car{
public:
    //data members
    char name[100];
    int model;
    int price;

    void print(){
        cout<<"name "<<name<<endl;
        cout<<"price "<<price<<endl;
        cout<<"model "<<model<<endl;
    }
    //constructor
    car(){
        cout<<"inside default constructor"<<endl;
    }
    //parameterised constructor
    car(char *n,int p,int m){
        cout<<"inside parameterised constructor"<<endl;
        strcpy(name,n);
        price =p;
        model=m;
    }
    //destructor
    ~car(){
        cout<<"deleting"<<name<<endl;
    }
    
};

int main(){
    car a;
    strcpy(a.name,"BMW");
    a.model=2025;
    a.price=10;

    car b("AUDI",10,2025);
    a.print();
    b.print();
    return 0;
}