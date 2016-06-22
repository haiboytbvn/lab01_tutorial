#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

char* createFile();
void writeInputToFile(char*filename);
int numberOfInput(char*fileName);
float* readDataFromFile(char*filename);
void sumSquare(float array[], int length);


int main(){
	char*fileName;
	fileName = createFile();
	writeInputToFile(fileName);
	int length = numberOfInput(fileName);
	float*array;
	array = readDataFromFile(fileName);
	sumSquare(array,length);
	return 0;
}

//create file .txt with name
char* createFile(){
	cout << "Create file named: ";
	string s;
	getline(cin, s);
	char*fileName = new char[s.length()+5];
	for(int i=0; i<s.length(); i++){
		fileName[i] = s[i];
	}
	fileName[s.length()] = '.';
	fileName[s.length()+1] = 't';
	fileName[s.length()+2] = 'x';
	fileName[s.length()+3] = 't';
	fileName[s.length()+4] = '\0';
	return fileName;
}


void writeInputToFile(char*fileName){
	// input from keyboard 
	cout << "Input: ";
	string input;
	getline(cin, input);
	//open and save into file
	ofstream file(fileName);
	file << input;
	file.close();
}

int numberOfInput(char*fileName){
	ifstream file(fileName);
	int length = 0;
	float value;
   while(file >> value){
   	length++;
	}
	file.close();
	return length;
}


float* readDataFromFile(char*fileName){
	ifstream file(fileName);	
	float*array;
	int length = numberOfInput(fileName);
	array = new float[length];
	int i = 0;
   while(!file.eof()){
   	if((file >> array[i]))
   		i++;
   	else{
   		cout << "Input Invalid!";
   		return 0;
   	}
	}
	file.close();
	return array;
}

void sumSquare(float array[], int length){
	float sum = 0;
	for(int i=0; i<length; i++){
		sum+= array[i]*array[i];
	}
	cout << "Sum Square is: " << sum;
}
