#include<iostream>
#include<queue>
using namespace std;

class cmp{
public:
    bool operator()(int a,int b){
        return a>b; // '>' se minheap bnega and '<' se maxheap bnega
    }
};

void printheap(priority_queue<int,vector<int>,cmp> h){
     while(!h.empty()){
		cout << h.top() << " ";

		h.pop();
	}
	cout << endl;
}
int main(){
    int k=3,cs=0;
    priority_queue<int,vector<int>,cmp> h;
    while(true){
        int data;
        cin>>data;

        if(data==-1){
            printheap(h);
        }
        else{
            if(cs==k){
                if(h.top()<data){
                    h.pop();
                    h.push(data);
                }
            }
            else{
                h.push(data);
                cs++;
            }
        }
    }
}