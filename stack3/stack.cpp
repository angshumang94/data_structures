using namespace std;
#include <iostream>
#include <iomanip>
#include <string>


class Stack{

	int * stack;

	int count =0;
	
	int stack_size;
	
	
public:

	Stack(int s){ stack =(int *) calloc(sizeof(int), s); stack_size = s;};
	~Stack(){ free(stack);}
	void push(int);
	int pop();
	int peak();
	void display();
	void getsize();
	bool isEmpty();
	bool isFull();
	
	
};

void Stack::push(int value){

	if(!isFull()){

		stack[count] = value;
		count++;

	}
	else
		cout << "Stack Overflow" <<endl;
	
}

int Stack::pop(){

	int value;
	
	if(isEmpty()){
		cout << "Stack Underflow\n";
		return -1;
	}
	else{
		
		value = stack[count-1];
		count--;
		return value;
	}
	
}

int Stack::peak(){
	
	if(isEmpty()){
		cout << "Stack is empty\n";
		return -1;
		}
	else
		return stack[count-1];
}

void Stack::display(){

	
	for(int i =count-1 ; i >=0 ; i--){
		cout << stack[i] << endl;

	}
}

void Stack::getsize(){
	
	cout << count << endl;
}

bool Stack::isEmpty(){
	return count==0;
}

bool Stack::isFull(){
	return count==stack_size;
}

int main()
{

	int option = 0 ;
	int val;

	cout << "Enter stack size" << endl;
	cin >> val;

	Stack stack(val);
	
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
				
				
				
				
				
