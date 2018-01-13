#include <iostream>
#include <stdlib.h>


using namespace std;

class Queue{
	
	int * queue;
	int count = 0;
	int size;
	
public:
	Queue(int s){ queue =(int *) calloc(sizeof(int), s); size = s;};
	~Queue(){ free(queue);};
	
	void add(int);
	void remove();
	void display();
	
	bool isEmpty();
	bool isFull();
	void getsize();
	void frontElement();
	void lastElement();
	
};

void Queue::add(int val){

	if(!isFull()){
		
		queue[count] = val;
		count++;
		}
	else{
		cout << "Queue is full\n";
		}
}

void Queue::remove(){
	
	if(!isEmpty()){
		
		for(int i = 0 ; i < count-1 ; i++){
			
			queue[i] = queue[i+1];
			}
		count--;
		}
	else{
		cout << "Queue is empty\n";
		}
}

void Queue::frontElement(){
	
	if(!isEmpty())
		cout << queue[0] << endl;
	else
		cout << "Queue empty\n";
}

void Queue::lastElement(){
	
	if(!isEmpty())
		cout << queue[count-1] << endl;
	else
		cout << "Queue empty\n";
}







void Queue::display(){
	
	for(int i =0 ; i < count ; i++){
		cout << queue[i] << " -- ";
		}
}

bool Queue::isEmpty(){

	if(count == 0)
		return true;
	else
		return false;
}

bool Queue::isFull(){
	
	if(count == size)
		return true;
	else
		return false;
}

void Queue::getsize(){
	
	cout << count << endl;
}





int main(){

	int size;
	
	cout << "Enter queue size\n";
	cin >> size;

	Queue qu(size);
	
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

