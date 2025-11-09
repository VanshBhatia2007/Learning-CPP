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

node* searchkey(node* root,int key){
    if(root==NULL) return NULL;
    //recursive case
    if(root->data==key){
        return root;
    }
    else if(root->data>key){
        node* ans=searchkey(root->left,key);
        if(ans!=NULL){
            return ans;
        }
        else{
            return NULL;
        }
    }
    else{
        return searchkey(root->right,key);
    }
}

int main(){
    node* root=createBST();
    node* ans=searchkey(root,10);
    if(ans==NULL){
        cout<<"key not found";
    }
    else{
        cout<<ans->data;
    }
    return 0;
}