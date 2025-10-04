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

    //functions

    void print(){
        cout<<"name "<<name<<endl;
        cout<<"price "<<price<<endl;
        cout<<"model "<<model<<endl;
    }
    // Default constructor
    car() {
    }

    car(car &x){
        strcpy(name, x.name);
        price = x.price;
        model = x.model;
    }
};

int main(){
    car a;
    strcpy(a.name,"BMW");
    a.model=2025;
    a.price=10;
    // cout<<"name "<<a.name<<endl;
    // cout<<"price "<<a.price<<endl;
    // cout<<"model "<<a.model<<endl;

    car b;
    strcpy(b.name,"AUDI");
    b.model=2025;
    b.price=10;
    // cout<<"name "<<b.name<<endl;
    // cout<<"price "<<b.price<<endl;
    // cout<<"model "<<b.model<<endl;


    //copy constructor
    car c=a;
    a.print();
    c.print();
}