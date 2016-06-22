#include <iostream>
#include <conio.h>
#include <String.h>

using namespace std;

/*number solve
Input: 2 4 7 2 3 5 6 3 3 1
Output:
Min: 1, Max 7
Most Freq: 3 (3 times)
Sort ASC: 1 2 2 3 3 3 4 5 6 7

*/
string input();
int sizeInput(string s);
void saveToArray(int ar[], string s);
void print(int ar[], int size);
void quickSort(int ar[], int left, int right);
void swap(int &a, int &b);
void findMostFreq(int ar[], int size);

int main(){
	string in;
	in = input();
	
	//create array to save list number input
	int size = sizeInput(in);
	int *ar;
	ar = new int[size];
	saveToArray(ar, in);
	
	//sort
	quickSort(ar, 0, size-1);
	
	//find min/max
	cout << "Min: " << ar[0] << ",  " << "Max: " << ar[size-1] << endl;
	
	//find most Freq
	findMostFreq(ar, size);
	
	//print list  of number after sort asc
	print(ar, size);

	return 0;

}


string input(){
	string in;
	cout << "input : ";
	getline(cin, in);
	in += ' ';
	return in;
}

//count number of input
int sizeInput(string s){
	int count = 0;
	int i=0;
	while(s[i] != '\0'){    	//not is end of input

		if(s[i] != ' '){			// not is ' ' and next is ' ' of '\0'   <end of number>
			if(s[i+1] == ' ' || s[i+1] == '\0'){
				count++;
			}
		}
		i++;
	};
	return count;
}

// convert input string to int and save in array
void saveToArray(int ar[], string s){
	int i = 0;
	int value = 0;
	int j = 0;
	while(s[i] != '\0'){
		
		if(s[i] != ' '){
			value = value*10 + ((int)s[i]-48);
		}
		
		if(s[i] == ' ' && value > 0){
			ar[j] = value;
			j++;
			value = 0;
		}
		
		i++;
	};
}


void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}


void quickSort(int ar[], int left, int right){
	int i = left;
	int j = right;
	int mid = ar[(left+right)/2+1];			
	while(i<=j){									
		while(ar[i] < mid)
			i++;
		while(ar[j] > mid)
			j--;
		if(i <= j){
			swap(ar[i], ar[j]);
			i++;
			j--;
		}
	}

	if(left < j)
		quickSort(ar, left, j);
	if(i < right)
		quickSort(ar, i, right);
}

//only for sorted list
void findMostFreq(int ar[], int size){		
	int maxFreq = 1;
	int freq = 1;
	int numberMaxFreq[size];
	for (int i=0; i<size; i++){			//set value of list numberMaxFreq = 0
		numberMaxFreq[i] = 0;
	}

	int j = -1;									
	for(int i=0; i<size; i++){			
		if(ar[i] == ar[i-1]){
			freq++;	
		}	
		else{			
			freq = 1;			//reset freq default
		}
			
		if(freq > maxFreq){					// maxFreq is changed
			maxFreq = freq;					//set maxFreq
			numberMaxFreq[j] = 0;			//reset value list numberMaxFreq
			j = -1;
			numberMaxFreq[j+1] = ar[i];			//numberMaxFreq[0] = ar[i];	
		}
		if(freq == maxFreq){
			j++;
			numberMaxFreq[j] = ar[i];
		}
	}
	cout << "Most Freq: ";
	j = 0;
	while(numberMaxFreq[j] > 0){						//show list numberMaxFreq
		cout << numberMaxFreq[j] << " ";
		j++;
	}
	cout << "(" << maxFreq << " times)";
}

//show array 
void print(int ar[], int size){
	cout << endl <<  "array: ";
	for(int i=0; i<size; i++){
		cout << ar[i] << " ";
	}
}
