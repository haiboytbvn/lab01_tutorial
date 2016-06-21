#include <iostream>
#include <conio.h>    
#include <iomanip>  
#include <stdio.h>
#include <String.h>
using namespace std; 

/*
input student with info
input mark win, word, jira
show list student with info and mark
*/
 
struct student{
	int id;
	string name;
	string birth;
	int winMark;
	int wordMark;
	int jiraMark;
	int sum;
	string rank;
};

struct Node{ 	
	student s;
	Node *next;
};
 
Node *head, *tail;

 //interface menu
void menu(){
	cout << endl << endl;
	cout << "Menu" << endl;
	cout << "1: Input new Student Info" << endl;
	cout << "2: Input/Edit Student Mark" << endl;
	cout << "3: Output Student" << endl;
	cout << "------------------------------" << endl;
	cout << "Choose your number: ";
}

int checkMark(){
	
	int tmp;
	while(!(cin >> tmp)){
		cout << "Invalid mark. Try again !" << endl;
		cout << "re-input mark: ";
		cin.clear();
		cin.ignore();
		fflush(stdin);
	}
	while(tmp < 0 || tmp > 10){
			cout << "Invalid mark. Try again !" << endl;
			cout << "re-input mark: ";
			return checkMark();
	}	
	return tmp;
}

//set student information detail 
student info(){
					  	
	student s;

	cout << "input name: ";
	getline(cin, s.name);
	fflush(stdin);
	
	cout << "input date of birth (dd/mm/yyyy): ";
	getline(cin, s.birth);
	fflush(stdin);
	
	s.sum = 0;
	return s;
}

void showlist(){
   Node *p = head;
 	int i = 0;
   
   //if list empty
   if(p == NULL){
   	cout << "List have 0 student. Please add first";
   	return;
   }

   //show (title)
   cout << endl;
   cout << " ----------------------------------------------------------------------------------------" << endl;
   cout <<  "|" << setw(4) << " No" << " |" << setw(30) << "Name" << " |"  << setw(15) << "Birthday" << " |"  << setw(10) << "Sum" << " |"  << setw(20) << "Rank" << " |"  << endl;
   cout << " ----------------------------------------------------------------------------------------" << endl;
   
	while(p != NULL){		//p is not tail
		p->s.id = ++i;		//set id list student
		//print each row
   	cout << "|" << setw(4) << p->s.id << " |" <<  setw(30) << p->s.name << " |"  << setw(15) << p->s.birth << " |"  << setw(10) << p->s.sum << " |"  << setw(20) << p->s.rank << " |"   << endl;    
		p = p->next;	
	}
		cout << " ----------------------------------------------------------------------------------------" << endl;	
}


 
// add 1 student to end of list
void addStudent(){
	
// create new node to set value
   Node *p = new Node; 
   
	student st = info();  
   p->s = st;
   p->next = NULL;  
   if (head == NULL)                       
      head = p;
   else
       tail->next = p;
   tail = p;                              
}
  
  
void addMark(){
	
	Node *p = head;
	int i;
	cout << "input row need add/edit mark: ";
	cin >> i;
	
	//find node i
	while(p->s.id != i){		
   	p = p->next;
   	
   	//if not found student i ( i > number of student)
		if(p == NULL){
	   	cout << "Not found this student. Check input correct! ";
	   	showlist();
	   	return;
   	}
	}	
	

	//input mark
	cout << "word mark: ";
	p->s.wordMark = checkMark();
	cout << "win mark: ";
	p->s.winMark = checkMark();
	cout << "jira mark: ";
	p->s.jiraMark = checkMark();
	fflush (stdin);
	
	// calculate sum and rate
	p->s.sum = p->s.winMark + p->s.wordMark + p->s.jiraMark;
	if(p->s.sum < 0 || p->s.sum > 30)
		p->s.rank = "";
	else if(p->s.sum < 18){
		p->s.rank = "Average";
	}
	else if(p->s.sum < 24){
		p->s.rank = "Good";
	}
	else{
		p->s.rank = "Excellence";
	}
	
}
 // show list to console


int main(){
	cout << "Student Manager" << endl;
	
	head = NULL;
	tail = head;	
	
	int choose;
	
	do{
		menu();
		if(!(cin >> choose)){
			choose = 0;
			cin.clear();
		}
		
		fflush(stdin);
		switch(choose){
			case 1:{
				addStudent();	
				break;
			}
			case 2:{
				//if list empty
				if(head == NULL){
   				cout << "List have 0 student. Please add first";
   				break;
   			}
				addMark();
				break;
			}
			
			case 3:{
				showlist();
				break;
			}
			
			default:{
				cout << "Wrong choose. Try again!";
				break;
			}	
		}	
		
	}while(1);
	
	return 0;
}



