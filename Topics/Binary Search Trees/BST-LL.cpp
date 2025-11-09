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
class LinkedList {
public:
	node*head, *tail;
};

LinkedList bstToLL(node* root) {
	LinkedList l;
	if (!root) {
		l.head = l.tail = NULL;
		return l;
	}
    // left or right dono h
	if (root->left != NULL and root->right != NULL) {
		LinkedList left = bstToLL(root->left);
		LinkedList right = bstToLL(root->right);
		left.tail->right = root;
		root->right = right.head;
		l.head = left.head;
		l.tail = right.tail;
		return l;
	}
    // only left is there
	else if (root->left != NULL and root->right == NULL) {
		LinkedList left = bstToLL(root->left);
		left.tail->right = root;
		l.head = left.head;
		l.tail = root;
		return l;
	}
    //only right is there
	else if (root->left == NULL and root->right != NULL) {
		LinkedList right = bstToLL(root->right);
		root->right = right.head;
		l.head = root;
		l.tail = right.tail;
		return l;
	}
    // both are not there
	else {
		l.head = root;
		l.tail = root;
		return l;
	}
}

int main(){
    node* root=createBST();
    LinkedList l=bstToLL(root);
    while(l.head!=NULL){
        cout<<l.head->data<<"-->";
        l.head=l.head->right;
    }
    cout << "NULL\n";
    return 0;
}