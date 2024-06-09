#include <bits/stdc++.h>

using namespace std;

// struct Node {
//  	Node* left;
//  	Node* right;

//  	int data;


//  };

// Node* CreateNode(){
// 	Node* root = new Node;
// 	int data;
// 	cout<<"Insert data";
// 	cin>>data;

// 	if(data==-1){
// 		return NULL;
// 	}

// 	root->data= data;

// 	cout<<"Insert left child of "<<data;

// 	root->left= CreateNode();
// 	cout<<"Insert right child of "<<data;

// 	root->right= CreateNode();

// 	return root;

// }

class Node{
 public:
	Node* left;
	Node* right;
	int data;

	Node(int data): left(nullptr),right(nullptr),data(data){}

	static Node* createNode(){

		int data;
		cin>>data;
		if(data==-1) return nullptr;
			Node* root = new Node(data);
			root->left= createNode();
			root->right=createNode();
			return root;
	}

	static void inorder(Node* root){

		if(root==nullptr){
			return;
		}
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}

	static int Height(Node* root){
		if(root==nullptr){
			return 0;
		}
		int left = Height(root->left);
		int right= Height(root->right);

		return 1 + (max(left,right));

	}

	static int Size(Node* root){
		if(root==nullptr){
			return 0;
		}

		return 1+ Size(root->left)+ Size(root->right);
	}

	static void LevelOrderDFS(Node* root,int level){
		//if we want to print full tree then call for all level
		//O(N^2)
		if(root==nullptr){
			return;
		}
		if(level==1){
			cout<<root->data<<" ";
		}

		LevelOrderDFS(root->left,level-1);
		LevelOrderDFS(root->right,level-1);
		return;

	}

	static void LevelOrderBFS(Node* root){

		if(root==nullptr) return;
		queue<Node*> q;
		q.push(root);

		while(!q.empty()){
			Node* temp= q.front();
			cout<<temp->data;
			q.pop();
			if(temp->left!=nullptr)
			q.push(temp->left);
			if(temp->right!=nullptr)
			q.push(temp->right);

		}

		return;
	}

	
};
 

int main (){
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r",stdin);
	freopen("output1.txt","w",stdout);
#endif

   Node* r= Node::createNode();


   // cout<<"data of root is "<<r->data;
cout<<"inorder= ";
 Node::inorder(r); 
 cout<<endl;
 cout<<"Height= "<<Node::Height(r); 
 cout<<endl;
 cout<<"Size= "<<Node::Size(r);	
 cout<<endl;
 cout<<"LevelOrderDFS ";
 Node::LevelOrderDFS(r,2);	
 cout<<endl;
 cout<<"LevelOrderBFS ";
 Node::LevelOrderBFS(r);


}
