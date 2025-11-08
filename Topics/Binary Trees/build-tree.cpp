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

int countnodes(node* root){
	if(root==NULL) return 0;

	int lst=countnodes(root->left);
	int rst=countnodes(root->right);

	return 1+lst+rst;
}
int height(node* root){
	if(root==NULL) return 0;
	int lsth = height(root->left);
	int rsth = height(root->right);
	int ans= max(lsth,rsth) + 1;

	return ans;
}

int diameter(node* root){
	if(root==NULL) return 0;
	int lsth=height(root->left);
	int rsth=height(root->right);
	int op1= lsth + rsth;
	int op2 = diameter(root->left);
	int op3= diameter(root->right);
	return max(op1,max(op2,op3));

}
class Pair{
public:
	int height,diameter;	
};

Pair fastdiameter(node* root){
	//base case
	if(root==NULL){
		Pair ans;
		ans.height=ans.diameter=0;
		return ans;
	}
	Pair left=fastdiameter(root->left);
	Pair right=fastdiameter(root->right);
	Pair ans;
	ans.height=max(left.height,right.height)+1;
	int op1=left.height+right.height;
	int op2=left.diameter;
	int op3=right.diameter;
	ans.diameter=max(op1,max(op2,op3));

	return ans;
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


void mirror(node* root){
	if(root==NULL) return;

	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right);
}

int main(){
	node* root = createtree();
	preorder(root);
	cout<<endl;
	cout<<height(root)<<endl;
	cout<<countnodes(root)<<endl;
	cout<<diameter(root)<<endl;
	Pair ans = fastdiameter(root);
	cout << "Fast height   : " << ans.height << endl;
	cout << "Fast Diameter : " << ans.diameter << endl;
	levelorderprint(root);
	mirror(root);
	return 0;
}