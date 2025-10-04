#include<iostream>
using namespace std;

int main(){
    int *a= new int[10];
    *a=1;
    cout<<*a<<endl;

    
    int n;
	cin >> n;
	int*arr = new int[n];

	for (int i = 0; i < n; ++i)
	{
		arr[i] = i + 1;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
    delete []a;
    a=NULL;
}