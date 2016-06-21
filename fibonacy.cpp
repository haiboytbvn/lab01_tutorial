#include <iostream>
#include <conio.h>
using namespace std;

//fibonacy

int main(){
	
	int number;
	cout << "input a number: ";
	cin >> number;
	cout << endl;

	int first = 1;
	int second = 1;
	cout << first << " " << second << " ";
	
	int next;
	next = first + second;
	
	long sum;
	sum = first + second;

	while(next < number){
		cout << next << " ";
		
		sum += next;
		
		first = second;
		second = next;
		next = first + second;
	}
	
	cout << endl << "Sum is: " << sum;
	getch();
	return 0;	
}

