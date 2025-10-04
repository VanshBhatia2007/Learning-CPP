#include<iostream>
#include <cstring>
using namespace std;

//blueprint

class car{
public:
    //data members
    char *name;
    int model;
    int price;

    void print(){
        cout<<"name "<<name<<endl;
        cout<<"price "<<price<<endl;
        cout<<"model "<<model<<endl;
    }

    //constructor
    car(){
        name =NULL;
        
        cout<<"inside default constructor"<<endl;
    }
    //parameterised constructor
    car(char *n,int p,int m){
        cout<<"inside parameterised constructor"<<endl;
        name = new char[strlen(n)+1];
        strcpy(name,n);
        price =p;
        model=m;
    }
        //Shallow and deep copy
    void setname(char *n){
        if(name!=NULL){
            delete []name;
        }
        name = new char[strlen(n)+1];
        strcpy(name,n);
    }
};

int main(){
    car a;
    a.setname("BMW");
    a.model=2025;
    a.price=10;

    car b("AUDI",10,2025);
    a.print();
    b.print();
    return 0;
}