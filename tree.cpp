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

	static void leftViewUtil(Node* root,vector<int> &v,int level){
		if(root==nullptr) return;

		if(level == static_cast<int>(v.size())){
            v.push_back(root->data);
		}

		leftViewUtil(root->left,v,level+1);
		leftViewUtil(root->right,v,level+1);
		return;

	}
	static void leftView(Node* root){
		if(root==nullptr) return;

		vector<int> v;

		leftViewUtil(root,v,0);

		for(auto i: v){
			cout<<i<<" ";
		}


	}

	static void rightViewUtil(Node* root,vector<int> &v,int level){
		if(root==nullptr) return;

		if(level == static_cast<int>(v.size())){
            v.push_back(root->data);
		}
		else{
			v[level]=root->data;
		}

		rightViewUtil(root->left,v,level+1);
		rightViewUtil(root->right,v,level+1);
		return;

	}
	static void rightView(Node* root){
		if(root==nullptr) return;

		vector<int> v;

		rightViewUtil(root,v,0);

		for(auto i: v){
			cout<<i<<" ";
		}


	}

	static void topView(Node* root){
		if(root==nullptr){
			return;
		}

		map<int,int> topmap;
		queue<pair<Node*,int>> q;

		q.push(make_pair(root,0));

		while(!q.empty()){
            Node* temp = q.front().first;
            int hd = q.front().second;
            q.pop();
			if(topmap.find(hd)==topmap.end()){
				topmap[hd]=temp->data;
			}

			if(temp->left!=nullptr){
				q.push(make_pair(temp->left,hd-1));

			}
			if(temp->right!=nullptr){
				q.push(make_pair(temp->right,hd+1));
				
			}
		}

		for(auto it : topmap){
			cout<<it.second<<" ";
		}
		cout<<endl;


	}
	static void bottomView(Node* root){
		if(root==nullptr){
			return;
		}

		map<int,int> bottommap;
		queue<pair<Node*,int>> q;

		q.push(make_pair(root,0));

		while(!q.empty()){
            Node* temp = q.front().first;
            int hd = q.front().second;
            q.pop();
			
				bottommap[hd]=temp->data;
			

			if(temp->left!=nullptr){
				q.push(make_pair(temp->left,hd-1));

			}
			if(temp->right!=nullptr){
				q.push(make_pair(temp->right,hd+1));
				
			}
		}

		for(auto it : bottommap){
			cout<<it.second<<" ";
		}
		cout<<endl;


	}
    static int heightOfTreeForDiameter(Node* root,int &ans){
    	if(root==nullptr){
    		return 0;
    	}

    	int lh = heightOfTreeForDiameter(root->left,ans);
    	int rh = heightOfTreeForDiameter(root->right,ans);

    	ans = max(ans,1+lh+rh);

    	return 1+max(lh,rh);


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
 cout<<endl;
 cout<<"LeftView ";
 Node::leftView(r);
 cout<<endl;
 cout<<"RightView ";
 Node::rightView(r);
 cout<<endl;
 cout<<"TopView ";
 Node::topView(r);
 cout<<"BottomView ";
 Node::bottomView(r);
 cout<<"Diameter ";
 int ans=0;
 Node::heightOfTreeForDiameter(r,ans);
 cout<<ans;
 


}
