using namespace std;
#include <iostream>
#include <iomanip>
#include <string>


class DoublyLL{

private:

	struct Lnode{

	int regno;
	string name;
	string course;
	string mail_id;
	string phone_no;

	Lnode * next = NULL;
	Lnode * prev = NULL;
	};
	

public:	
	
	Lnode * head = NULL;
	
	int listlen=0;
	
		
	void display_list();
	void insert_case(char);
	void insert_node(int);
	int search(int);
	void delete_case(char);
	void delete_node(int);
	void delete_course(string);
	
};

void DoublyLL::display_list(){

	if(head != NULL){
		Lnode * inode = head;

		cout << "Reg No." << setw(30) << "Name" << setw(30) << "Course" << setw(30) << "Mail ID" << setw(30) << "Phone No.\n";
	
		while(inode!=NULL){
		
			
			cout << inode->regno << setw(30) << inode->name << setw(30) << inode->course << setw(30) << inode->mail_id 				<< setw(30) << inode->phone_no << "\n";
			inode = inode->next;

			}
		}

}

void DoublyLL::insert_case(char suboption){
	
	int regno;
	int pos;
	
	switch(suboption){
		
		case 'a':
			insert_node(0);
			break;
		case 'b':
			insert_node(listlen);
			break;
		case 'c':
			cout<< "Enter Reg No.\n";
			cin >> regno;
			pos = search(regno);
			if(pos!= -1)
				insert_node(pos);
			else
				cout << "Reg No. doest exist!\n";
			break;
		case 'd':
			cout<< "Enter Reg No.\n";
			cin >> regno;
			pos = search(regno);
			if(pos!= -1)
				insert_node(pos+1);
			else
				cout << "Reg No. doest exist!\n";
			break;
		default:
			cout << "Wrong option \n";
			break;
		}
	
}


void DoublyLL::delete_case(char suboption){
	
	int regno;
	int pos;
	string course;
	
	switch(suboption){
		
		case 'a':
			delete_node(0);
			break;
		case 'b':
			delete_node(listlen-1);
			break;
		case 'c':
			cout<< "Enter Reg No.\n";
			cin >> regno;
			pos = search(regno);
			
			if(pos == -1)
				cout << "Reg No. doest exist!\n";
			else if(pos == 0)
				cout << "Can't delete before first node\n";
			else
				delete_node(pos-1);
			
			break;
		case 'd':
			cout<< "Enter Reg No.\n";
			cin >> regno;
			pos = search(regno);
			
			if(pos == -1)
				cout << "Reg No. doest exist!\n";
			else if(pos == (listlen-1))
				cout << "Can't delete after last node\n";
			else
				delete_node(pos+1);
			
			break;
		case 'e':
			cout<< "Enter Reg No.\n";
			cin >> regno;
			pos = search(regno);
			
			if(pos == -1)
				cout << "Reg No. doest exist!\n";
			else
				delete_node(pos);
			
			break;
		case 'f':
			cout<< "Enter course name\n";
			cin >> course;
			delete_course(course);
			break;
			
		default:
			cout << "Wrong option \n";
			break;
		}
	
}


void DoublyLL::insert_node(int pos){

	
	int count=0;

	Lnode * nnode = new struct Lnode; // create new node

	// Enter details

	cout << "Reg No \n";
	cin >> nnode->regno;
	cout << "Name \n";
	cin >> nnode->name;
	cout << "Course \n";
	cin >> nnode->course;
	cout << "Mail ID \n";
	cin >> nnode->mail_id;
	cout << "Phone no \n";
	cin >> nnode->phone_no;		
	

	
	if(head == NULL){	//head is null

		head = nnode;
		
	}
	else if(pos == 0){	//insert at first
		
		nnode->next = head;
		head->prev = nnode;
		head = nnode;
		}
		
	else{			//insert at any position
	
		Lnode * inode = head;
		
		while(count<pos-1){
			inode = inode->next;
			count++;
			}
		if(pos == listlen){
			inode->next = nnode;		//insert at last
			nnode->prev = inode;
			}
		else{ 
			nnode->next = inode->next;
			nnode->prev = inode;
			 
			inode->next = nnode;
			nnode->next->prev = nnode;
			}
		}
	
	listlen++; // increments length of list

}


void DoublyLL::delete_node(int pos){

	int count=0;		
	
	Lnode * inode = head;
	
	if(head == NULL || pos == -1)
		cout << "List is empty\n";
	else{
	
		if(pos == 0){	//delete at first
		
			head = head->next;
			if(head!=NULL)
				head->prev = NULL;
			delete inode;
			}
		
		else{			//delete at any position
	
			while(count<pos){
				inode = inode->next;
				count++;
				}
			if(pos == (listlen-1)){		//delete at last
				inode->prev->next = NULL;
				delete inode;
				}
			else{
				inode->prev->next = inode->next;
				inode->next->prev = inode->prev;
				delete inode;
				}
			
		}
	
		listlen--; // increments length of list
	}
}

void DoublyLL::delete_course(string course){

	Lnode * inode = head;
	Lnode * pnode = head;
	Lnode * temp;
	
	while(inode!=NULL){
		if(inode->course == course){
			if(inode == head){
				head = inode->next;
				head->prev = NULL;
				delete inode;
				inode = head;
				
				
				}
			else{
				inode->prev->next = inode->next;
				if(inode->next!=NULL)
					inode->next->prev = inode->prev;
				temp = inode;
				inode = inode->next;
				delete temp;
				
				
				}
			
			listlen--;
			}
		else{
			
			inode = inode->next;
			}
			
	}
}

int DoublyLL::search(int regno){

	int pos = -1;
	int i=0;
	
	Lnode * inode = head;
	
	while(inode!=NULL){
		if(inode->regno == regno){
			pos = i;
			break;
		}	
		inode = inode->next;
		i++;
	}
	return pos;	
	
}



//---------------- MAIN ---------------//


int main(){

	DoublyLL doubly;


	int val;
	int option=1; //OPTION


	while(option!=0){

	cout << "Enter your option \n 1. Display List \n 2. Insert node in list \n\t a.Insert in beginning \n\t b.Insert in last 		\n\t c.Insert before node \n\t d.Insert after node \n 3. Delete node in list \n\t a.Delete in beginning \n\t b.Delete in last 		\n\t c.Delete before node \n\t d.Delete after node \n\t e.Delete particular node\n\t f. Delete by course\n" << endl;
	cin >> option;

	char suboption;

		switch(option){

		case 1:
	
			doubly.display_list();
			break;
	
		case 2:
			
			cout << "Enter suboption  ";
			cin >> suboption;
			doubly.insert_case(suboption);
			break;
		
		case 3:
			
			cout << "Enter suboption  ";
			cin >> suboption;
			doubly.delete_case(suboption);
			break;

		default:
		break;
		}
	}
}

