#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
public:
    unordered_map<string, list<pair<string,int>>>adj;

    void addedge(string u,string v,int d,bool bidir=true){
        adj[u].push_back({v,d});
        if(bidir==true){
            adj[v].push_back({u,d});
        }
    }

    void print(){
        for
    }
};