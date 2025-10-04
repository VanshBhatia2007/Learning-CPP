#include<iostream>
#include <cstring>
using namespace std;

//blueprint

class car{
private:
    int price;
public:
    //data members
    char name[100];
    int model;
    

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
    //setter
    void setprice(int p){
        if (p >= 100 && p < 150) price = p;
        else price = 120;
    }
    //getter
    int getprice(){
        return price;
    }
    
};

int main(){
    car a;
    strcpy(a.name,"BMW");
    a.model=2025;
    a.setprice(100);

    cout<<a.getprice();

    car b("AUDI",10,2025);
    a.print();
    b.print();
    return 0;
}