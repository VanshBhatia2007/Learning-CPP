#include<iostream>
#include <cstring>
using namespace std;

//blueprint

class car{
    int dis;//private
public:
    //data members
    char name[100];
    int model;
    int price;
    const int tyre;
    static int cnt;

    void print(){
        cout<<"name "<<name<<endl;
        cout<<"price "<<price<<endl;
        cout<<"model "<<model<<endl;
        cout<<"tyre "<<tyre<<endl;
        cout<<"cnt "<<cnt<<endl;
    }

    void setName(const char* n) {
        strcpy(name, n);
    }

    void setPrice(int p) {
        price = p;
    }

    int getPrice() const {
        return price;
    }

    //constructor
    car() : tyre(4) {//giving value to a cont variable
        cout<<"inside default constructor"<<endl;
        cnt++;
    }
    //parameterised constructor
    car(char *n,int p,int m) : tyre(4) {
        cout<<"inside parameterised constructor"<<endl;
        strcpy(name,n);
        price =p;
        model=m;
        cnt++;
    }
    //copy constructor
    car(car &X) : tyre(4) {
		cout << "Inside copy constructor\n";
		strcpy(name, X.name);
		price = X.price;
		model = X.model;
        cnt++;
	}

    void operator=(car X) { // Car X = A
		strcpy(name, X.name);
		price = X.price;
		model = X.model;
    }
    ~car(){
        cnt--;
    }
    friend ostream& operator<<(ostream& os, car &X);
    friend istream& operator>>(istream &is, car &X);

    
};


int car::cnt=0;//giving value to a static variable

ostream& operator<<(ostream& os, car &X) {
	cout << "Name    : " << X.name << endl;
	cout << "Price   : " << X.getPrice() << endl;
	cout << "Model   : " << X.model << endl << endl;
	return os;
}

istream& operator>>(istream &is, car &X) {
	char n[1000];
	cout << "Enter name  : "; cin.getline(n, 1000);
	X.setName(n);
	int p;
	cout << "Enter price :"; cin >> p;
	X.setPrice(p);

	cout << "Enter model :"; cin >> X.model;
	return is;
}

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
    cout<<car::cnt<<endl;
    return 0;
}