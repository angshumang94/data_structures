#include <iostream>
using namespace std;



class Queue{
	
	struct Node{
        int value;
        Node * next;
        Node * prev;
    };

    Node * head = NULL;
	int size = 0;
	
	
public:
	
	void add(int);
	void remove();
	void display();
	
	void getsize();
	void frontElement();
	void lastElement();
	
};


void Queue::add(int value){

    Node * nnode = new Node;
    nnode->value = value;

    if(head == NULL){
        head = nnode;
        head->next = head;
        head->prev = head;
        
    }
    else{
        
        Node * pnode = head->prev;
        pnode->next = nnode;
        nnode->prev = pnode;

        head->prev = nnode;
        nnode->next = head;
    }

    size++;

}

void Queue::remove(){

    if(head == NULL){
        cout << "Queue is empty" << endl;
    }
    else{

        if(size!=1){
        Node * tnode = head;
        

        head = head->next;

        head->prev = tnode->prev;
        tnode->prev->next = head;

        delete tnode;
        }

        else{
            delete head;
            head = NULL;
        }

    }
    size--;
}


void Queue::display(){

    if(head != NULL){
    Node * inode = head;

    while(inode->next!=head){

        cout << inode->value << " -- ";
        inode = inode->next;
    }
    
    cout << inode->value;

    cout << endl;
    }
    else
        cout << "Queue empty" << endl;
}

void Queue::getsize(){
    cout << size << endl;
}

void Queue::frontElement(){
    
    if(head!=NULL){
        cout << head->value << endl;
    }
    else    
        cout << "Queue is empty"<< endl;
}

void Queue::lastElement(){
    if(head!=NULL){

    cout << head->prev->value << endl;

    }

    else
        cout << "Queue is empty"<< endl;
}


int main(){

	Queue qu;
	
	int option = 0;
	
	while(option!=7){
	
		cout << "1. Add Element \n2. Remove Element \n3. Number of elements in the queue\n4. First element of the queue\n5. Last element of the queue\n6. Display queue\n7. Exit\n";
		cin >> option;
		
		switch(option){
			
			case 1:
				int val;
				cout << "Enter value\n";
				cin >> val;
				qu.add(val);
				break;
			
			case 2:
				qu.remove();
				break;
			case 3:
				qu.getsize();
				break;
			case 4:
				qu.frontElement();
				break;
			case 5:
				qu.lastElement();
				break;
			case 6:
				qu.display();
				break;
			case 7:
				option = 7;
				break;
			default:
				break;
			}
		}
}