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
    car(car &X) {
		cout << "Inside copy constructor\n";
		strcpy(name, X.name);
		price = X.price;
		model = X.model;
	}
   
};

int main(){
    car a;
    strcpy(a.name,"BMW");
    a.model=2025;
    a.price=10;

    car b("AUDI",10,2025);

    car c=a;//car c(a)
    c=b;
    a.print();
    b.print();
    c.print();
    return 0;
}