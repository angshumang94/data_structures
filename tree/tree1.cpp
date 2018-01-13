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
	
	void delete_r(Node * ,int);
	void transplant(Node *, Node *);
	Node * mintree(Node *);
	
	
	void inorder_r(Node *);
	void inorder_i(Node *);
	void preorder_r(Node *);
	void preorder_i(Node *);
	void postorder_r(Node *);
	void postorder_i(Node *);
	
	void level_i(Node *);
	void level_r(Node *);
	void level_rec(Node *,int);
	
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


void Tree::level_r(Node * inode){
	
	int h = height(inode);
	
	for(int i =1 ; i <= h ; i++){
		
		level_rec(inode,i);
		
		
		}

}


	
void Tree::level_rec(Node * inode, int height ){
	
	if(inode != NULL){
		
		if(height == 1)
			cout << inode->val << " -- ";
		else{
			
			level_rec(inode->left,height-1);
			level_rec(inode->right,height-1);
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


void Tree::delete_r(Node * inode, int val){
	
	
if(inode!=NULL){	
	if(val < inode->val)
		delete_r(inode->left,val);
	else if(val > inode->val)
		delete_r(inode->right,val);
	else{
		
		if(inode->right == NULL){
			transplant(inode, inode->left);
			
			}
		else if(inode->left == NULL){
			transplant(inode, inode->right);
			
			}
		
		else{
			Node * successor = mintree(inode->right);
			
			
			if(successor != inode->right){
				
				transplant(successor,successor->right);
				successor->right = inode->right;
				successor->right->parent = successor;
				}
			
			transplant(inode,successor);
			successor->left = inode->left;
			successor->left->parent = successor;
			
			
			}
		
		delete inode;
		
		}
	}
else{
	
	cout << "Node not found\n";
	}
}





void Tree::transplant(Node * pnode, Node * nnode){
	
	if(pnode->parent == NULL)
		root = nnode;
	else if(pnode == pnode->parent->left)
		pnode->parent->left = nnode;
	else
		pnode->parent->right = nnode;
	
	
	if(nnode != NULL)
		nnode->parent = pnode->parent;
		
}


Tree::Node * Tree::mintree(Node * inode){
		
	while(inode->left != NULL)
		inode = inode->left;
	
	return inode;
}







int main(){

	Tree tree;
	int val,option=0;
	
	
	while(option!=12){
	
		cout << "Enter option" << endl;
		cout << "1. Insert of a node in the tree\n2. Deletion of a node from a tree\nTraversal(iterative)\n3. Preorder\n4. In order\n5. Post Order\n6. Level Order\nTraversal(recursive)\n7. Preorder\n8. In order\n9. Post Order\n10. Level Order\n11. Exit" << endl;
		cin >> option;
		
		switch(option){
			
			case 1:
				cout <<"Enter value"<<endl;
				cin >>val;
				tree.insert_iter(val);
				break;
			
			case 2:
				cout <<"Enter value"<<endl;
				cin >>val;
				tree.delete_r(tree.getroot(),val);
				break;
			case 3:
				tree.preorder_i(tree.getroot());
				break;
			case 4:
				tree.inorder_i(tree.getroot());
				break;
			case 5:
				tree.postorder_i(tree.getroot());
				break;
			case 6:
				tree.level_i(tree.getroot());
				break;
			case 7:
				tree.preorder_r(tree.getroot());
				break;
			case 8:
				tree.inorder_r(tree.getroot());
				break;
			case 9:
				tree.postorder_r(tree.getroot());
				break;
			case 10:
				tree.level_r(tree.getroot());
				break;
			case 11:
				option = val;
				break;
			default:
				break;
			
		
		

		}
	}
	
	return 0;
	
}










					
