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

node* createtree(){
	//base case
	int data;
	cin>>data;
	if(data==-1) return NULL;
	//recursive case
	node* root= new node(data);
	root->left=createtree();
	root->right=createtree();
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

void levelorderprint(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* f=q.front();
		q.pop();

		if(f!=NULL){
			cout<<f->data<<" ";
			if(f->left!=NULL){
				q.push(f->left);
			}

			if(f->right!=NULL){
				q.push(f->right);
			}
		}
		else{
			cout << '\n';
			if (!q.empty()) {
				q.push(NULL);
			}
		}
	}

}

node* searchnode(node* root,int key){
    //base case
    if(root==NULL) return NULL;
    //recursive case
    if(root->data==key){
        return root;
    }

    node* left=searchnode(root->left,key);
    if(left!=NULL){
        return left;
    }
    node* right=searchnode(root->right,key);
    return right;
}

void printrange(node* root,int k1,int k2){
	//base case
	if(!root) return;

	//recursive case
	if(root->data>=k1 and root->data<=k2){
		cout<<root->data<<" ";
	}
	printrange(root->left,k1,k2);
	printrange(root->right,k1,k2);
}


int main(){
	node* root = createtree();
	preorder(root);
	levelorderprint(root);
    cout<<searchnode(root,3)<<endl;
	printrange(root,3,10);
	return 0;
}