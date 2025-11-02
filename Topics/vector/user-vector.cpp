#include<iostream>
#include<vector>
using namespace std;


class UserVector{
public:
    int *arr;
    int cs;
    int ts;
    UserVector(int s=1){
        arr = new int[s];
        ts=s;
        cs=0;
    }
    void push_back(int d){
        if(cs==ts){
            int *oldarr=arr;
            int oldts=ts;
            ts*=2;
            arr=new int[ts];
            for(int i=0;i<oldts;i++){
                arr[i]=oldarr[i];
            }
            delete []oldarr;
        }
        arr[cs++]=d;
    }

    void pop_back(){
        if(cs>0){
            cs--;
        }

    }
    int size() {
        return cs;
    }

    int capacity() {
        return ts;
    }
    //operator overloading
    int operator[](int indx){
        return arr[indx];
    }
};

int main(){
    UserVector v;
    for(int i=1;i<=10;i++){
        v.push_back(i);
    }
    cout<<"size "<<v.size()<<endl;
    cout<<"capacity "<<v.capacity()<<endl;
    for(int i=0;i<=v.size();i++){
        cout<<v[i]<<" ";

    }
    cout<<endl;
    return 0;
}