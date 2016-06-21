#include <iostream>
#include <conio.h>
using namespace std;

//cost telephone

int main(){
	
	int time;
	cout << "input call time: ";
	cin >> time;
	int mod;
	
	long cost = -1;
	

	if(time < 0){
		cout << "input invalid !";
	}
	else if (time == 0){
		cost = 0;
		cout << "Cost is: " << cost;
	}
	else if(time <= 50){
		cost = 25000 + time*600;
		cout << endl << "Cost is: 25000 + " << time << "*600 = " << cost;
	}
	else if(time <= 200){
		mod = time - 50;
			cost = 25000 + 50*600 + mod*400;
		cout << endl << "Cost is: 25000 + 50*600 + " << mod << "*400 = " << cost;
	}
	else{
		mod = time - 200;
		cost = 25000 + 50*600 + 150*400 + mod*200;
		cout << endl << "Cost is: 25000 + 50*600 + 150*400 + " << mod << "*200 = " << cost;	
	}
	
	return 0;
}
