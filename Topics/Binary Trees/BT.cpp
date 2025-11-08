#include<iostream>
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

int pre[] = {8, 10, 1, 6, 4, 7, 3, 14, 13};
int k = 0;
node* createTree(int *in, int s, int e) {
	if (s > e) return NULL;

	node* root = new node(pre[k++]);
	int j;
	for (int i = s; i <= e; ++i)
	{
		if (in[i] == root->data) {
			j = i;
			break;
		}
	}

	root->left = createTree(in, s, j - 1);
	root->right = createTree(in, j + 1, e);
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
int main() {
	int in[] = {1, 10, 4, 6, 7, 8, 3, 13, 14};
	int n = sizeof(in) / sizeof(int);

	node* root = createTree(in, 0, n - 1);
	preorder(root);
	cout<<endl;
	inorder(root);
	cout << endl;
	postorder(root);
	cout << endl;


	return 0;
}