#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class Tree{

	struct Node{
	
	int val;
	Node * parent;
	Node * left;
	Node * right;
	};
	
	Node * root = NULL;
	
	public:
	
	void insert_iter(int);
	void inorder_r(Node *);
	void inorder_i(Node *);
	void preorder_r(Node *);
	void preorder_i(Node *);
	void postorder_r(Node *);
	void postorder_i(Node *);
	
	void level_i(Node *);
	void level_rec(Node *);
	void level_r(Node *,int);
	
	int height(Node *);
	Node * getroot();
	
	
};


void Tree::insert_iter(int val){

	Node * nnode = new Node;
	nnode->val = val;
	Node * inode = root;

	if(root == NULL){
		root = nnode;
		}
	else{
		while(true){
			
			if(val > inode->val){
			
				if(inode->right != NULL)
					inode = inode->right;
				else{
					inode->right = nnode;
					nnode->parent = inode;
					break;
					}
				}
			else if(val < inode->val){
			
				if(inode->left != NULL)
					inode = inode->left;
				else{
					inode->left = nnode;
					nnode->parent = inode;
					break;
					}
				}
			else{
				cout << "Node exists!\n";
				break;
				}
			}
		}
}


void Tree::inorder_r(Node * inode){

	if(inode!=NULL){
		inorder_r(inode->left);
		cout << inode->val << " -- ";
		inorder_r(inode->right);
		}
}


void Tree::inorder_i(Node * inode){

	stack <Node *> stk;
	bool empty = false;
	
	while(!empty){
	
		
		if(inode != NULL){
			
			stk.push(inode);
			inode = inode->left;
			
			}
		else if(!stk.empty()){
			inode = stk.top();
			cout << inode->val << " -- ";
			stk.pop();
			inode = inode->right;
			}
		else{
			empty = true;
		}
	}
	
	cout << endl;
}
		
		

void Tree::preorder_r(Node * inode){

	if(inode!=NULL){
		cout << inode->val << " -- ";
		preorder_r(inode->left);
		preorder_r(inode->right);
		}
}

void Tree::preorder_i(Node * inode){

	stack <Node *> stk;
	bool empty = false;
	
	while(!empty){
	
		
		if(inode != NULL){
			
			cout << inode->val << " -- ";
			
			if(inode->right != NULL)
				stk.push(inode->right);
			
			inode = inode->left;
			}
		else if(!stk.empty()){
			
			inode = stk.top();
			stk.pop();
			}
		else
			empty = true;
	}
	
	cout << endl;
}

void Tree::postorder_r(Node * inode){

	if(inode!=NULL){
		postorder_r(inode->left);
		postorder_r(inode->right);
		cout << inode->val << " -- ";
		}
}

void Tree::postorder_i(Node * inode){

	stack <Node *> stk;
	bool empty = false;
	Node * last = NULL;
	
	while(!empty){
	
		
		if(inode != NULL){
			
			
			
			stk.push(inode);
			
			inode = inode->left;
			}
		else if(!stk.empty()){
			
			inode = stk.top();
			if(inode->right != NULL && inode->right != last){

				inode = inode->right;
				}
			else{
				cout << inode->val << " -- ";
				stk.pop();
				last = inode;
				inode = NULL;
				}
			}
		else
			empty = true;
	}
	
	cout << endl;
}


void Tree::level_i(Node * inode){

	queue <Node *> qu;
	
	qu.push(inode);
	
	while(!qu.empty()){
		
		inode = qu.front();
		if(inode->left) qu.push(inode->left);
		if(inode->right) qu.push(inode->right);
		
		cout << inode->val << " -- ";
		
		qu.pop();
		}
	
	cout << endl;
}


void Tree::level_rec(Node * inode){
	
	int h = height(inode);
	
	for(int i =1 ; i <= h ; i++){
		
		level_r(inode,i);
		
		
		}

}


	
void Tree::level_r(Node * inode, int height ){
	
	if(inode != NULL){
		
		if(height == 1)
			cout << inode->val << " -- ";
		else{
			
			level_r(inode->left,height-1);
			level_r(inode->right,height-1);
		}
	}
}
	
	
	

int Tree::height(Node * inode){
	
	int left, right;
	if(inode == NULL)
		return 0;
	else{
		left = height(inode->left);
		right = height(inode->right);
		
		if(left > right)
			return left+1;
		else
			return right+1;
		}
}
		


Tree::Node * Tree::getroot(){

	return root;
}





int main(){

	Tree tree;
	int val,count=0;
	
	while(count < 9){
	
		cin >> val;
		tree.insert_iter(val);
		count++;
		}
	
	cout << "inorder" << endl;
	tree.inorder_i(tree.getroot()) ;
	cout << "preorder" << endl;
	tree.preorder_i(tree.getroot()) ;
	cout << "postorder" << endl;
	tree.postorder_i(tree.getroot());
	cout << "levelorder" << endl;
	tree.level_rec(tree.getroot());
	
	return 0;
}










					
