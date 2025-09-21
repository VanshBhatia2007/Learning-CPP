#include<iostream>
using namespace std;


void merge(int *a,int *b,int *c,int s,int e){
    int m=(s+e)/2;
    int i=s,j=m+1,k=s;
    while(i<=m && j<=e){
        if(b[i]<c[j]) a[k++]=b[i++];
        else a[k++]=c[j++];
    }
    while(i<=m){
        a[k++]=b[i++];
    }
    while(j<=e){
        a[k++]=c[j++];
    }
}

void mergesort(int *a,int s,int e){
    if(s>=e){
        return ;
    }
    //divide
    int mid=(s+e)/2;
    int b[1000],c[1000];
    for(int i=s;i<=mid;++i){
        b[i]=a[i];
    }
    for(int j=mid+1;j<=e;++j){
        c[j]=a[j];
    }
    //sort
    mergesort(b,s,mid);
    mergesort(c,mid+1,e);
    //merge
    merge(a,b,c,s,e);
}

int main(){
    int a[] = {6, 4, 7, 2, 1, 5};
	int n = sizeof(a) / sizeof(int);

	mergesort(a, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}