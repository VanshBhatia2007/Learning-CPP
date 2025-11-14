#include<iostream>
#include<queue> 
using namespace std;

class cmp{
public:
    bool operator()(int a,int b){
        return a>b; // '>' se minheap bnega and '<' se maxheap bnega
    }
};

int main(){
    // priority_queue<int> h; //maxheap
    priority_queue<int , vector<int>,cmp> h;
    h.push(5);
    h.push(1);
    h.push(2);
    h.push(4);
    h.push(3);

    //heap sort
    while(!h.empty()) {
		cout << h.top() << " ";

		h.pop();
	}
	cout << endl;
	return 0;
}