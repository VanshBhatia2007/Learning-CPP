#include <iostream>
#include <queue>
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

class Pair{
public:
    bool isbalanced;
    int height;
};

Pair isbalanced(node* root){
    Pair p;
	if (!root) {
		p.height = 0;
		p.isbalanced = true;
		return p;
	}
	Pair left = isbalanced(root->left);
	Pair right = isbalanced(root->right);
	p.height = max(left.height, right.height) + 1;
	if (abs(left.height - right.height) <= 1 and left.isbalanced and right.isbalanced) {
		p.isbalanced = true;
	}
	else {
		p.isbalanced = false;
	}

	return p;
}


int main(){
    node* root=createBST();
    Pair ans=isbalanced(root);
    if(ans.isbalanced) cout<<"balanced";
    else cout<<"not balanced"; 
    return 0;
}