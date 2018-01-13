using namespace std;
#include <iostream>
#include <iomanip>
#include <string>


class Stack{

	struct Node{
	
	int value;
	Node * next;
	};
	
	int stack_size = 0;
	
	Node * top = NULL;
	
public:

	void push(int);
	int pop();
	int peak();
	void display();
	void getsize();
	
	
};

void Stack::push(int value){

	Node * nnode = new Node;
	
	nnode->value = value;
	nnode->next = top;
	top = nnode;
	
	stack_size++;
}

int Stack::pop(){

	int value;
	Node * temp;
	
	if(top == NULL){
		cout << "Stack Underflow\n";
		return -1;
	}
	else{
		
		value = top->value;
		temp = top;
		top = top->next;
		delete temp;
		stack_size--;
		return value;
	}
	
}

int Stack::peak(){
	
	if(top == NULL){
		cout << "Stack is empty\n";
		return -1;
		}
	else
		return top->value;
}

void Stack::display(){
	
	Node * temp = top;
	
	while(temp!=NULL){
		
		cout << temp->value << endl;
		temp = temp->next;
		}
}

void Stack::getsize(){
	
	cout << stack_size << endl;
}


int main()
{

	int option = 0 ;
	int val;
	
	Stack stack;
	
	while(option!=6){
	
		cout << "1. Push \n 2. Pop \n 3. Number of elements in the stack \n 4. Peak element of the stack \n 5. Displaying all elements of the stack \n 6. Exit \n";
		
		cin >> option;
		
		switch(option){
		
			case 1:
				cout << "Enter value\n";
				cin >> val;
				stack.push(val);
				break;
				
			case 2:
				cout << stack.pop();
				break;
				
			case 3:
				stack.getsize();
				break;
				
			case 4:
				cout << stack.peak();
				break;
				
			case 5:
				stack.display();
				break;
			
			case 6:
				option = 6;
				break;
			default:
				break;
			}
	}
}
				
				
				
				
				
