#include <iostream>
using namespace std;



class Queue{
	
	struct Node{
        int value;
        Node * next;
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
        
    }
    else{
        Node * inode = head;

        while(inode->next != NULL){
            inode = inode->next;

        }

        inode->next = nnode;
    }

    size++;

}


void Queue::remove(){

    if(head == NULL){
        cout << "Queue is empty" << endl;
    }
    else{
        Node * tnode = head;

        head = head->next;

        delete tnode;

    }
    size--;
}

void Queue::display(){

    Node * inode = head;

    while(inode!=NULL){

        cout << inode->value << " -- ";
        inode = inode->next;
    }

    cout << endl;
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

        Node * inode = head;

        while(inode->next!=NULL){
        inode = inode->next;
        }

    cout << inode->value << endl;

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

