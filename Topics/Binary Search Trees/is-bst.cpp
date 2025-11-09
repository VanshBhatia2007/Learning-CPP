#include <iostream>
#include <queue>
#include<climits>
using namespace std;

class node {
public:
	int data;
	node* left, *right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};

node* insertInBST(node* root, int d) {
	if (!root) {
		root = new node(d);
		return root;
	}

	if (root->data > d) {
		root->left = insertInBST(root->left, d);
	}
	else {
		root->right = insertInBST(root->right, d);
	}
	return root;
}

void preorder(node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void postorder(node* root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}


node* createBST() {
	int data;
	cin >> data;
	node* root = NULL;
	while (data != -1) {
		root = insertInBST(root, data);
		cin >> data;
	}
	return root;
}

class Tuple{
public:
    bool isbst;
    int mi,mx;
};
Tuple isbst(node* root){
    //base case
    if(root==NULL){
        Tuple ans;
        ans.isbst=true;
        ans.mi=INT_MAX;
        ans.mx=INT_MIN;
        return ans;
    }
    //recursive case
    Tuple left=isbst(root->left);
    Tuple right=isbst(root->right);
    Tuple ans;
    if(left.isbst==true and right.isbst==true and root->data>=left.mx and root->data<=right.mi){
        ans.isbst=true;
    }
    else ans.isbst=false;
    ans.mx=max(root->data,max(left.mx,right.mx));
    ans.mi=min(root->data,min(left.mi,right.mi));
    return ans;
}

bool isBST(node* root, int mi = INT_MIN, int mx = INT_MAX) {
	if (!root) return true;

	if (root->data >= mi and root->data <= mx and isBST(root->left,mi,root->data) and isBST(root->right,root->data,mx)) {
		return true;
	}
	else {
		return false;
	}
}

int main(){
    node* root=createBST();
    if(isBST(root)){
        cout<<"bst hai";
    }
    else cout<<"nhi hai";
    return 0;
}