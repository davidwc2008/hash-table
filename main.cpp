/*
David Chen
C++ 2018
Hash Table Program
+ Random Generator
*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

//Student struct declaration
struct Student
{
  char firstname [20];
  char lastname [20];
  int studentid;
  float gpa;
  
  Student* next;
};

//function declaration
void add(Student*); //add to the hash table
void print();
void remove(int ID);
int hash(); //this is the hash function that will return an index
string generateFirst(); //this will generate a random first name
string generateLast(); //this will generate a random last name

int main() {
	cout << "Welcome to Student List.  Type ADD to add students, PRINT to print student information, and DELETE to remove a student's information." << endl;
	cout << "Additionally, type GENERATE to randomly generate and add new students.  Finally, type QUIT to quit." << endl;

	char invalid = 'y';
	string input;

	while (invalid == 'y'){
		cin >> input;
		if (!strcmp(input, "ADD")){
			Student* a = new Student;
			cout << "Enter first name: " << endl;
			cin >> a->firstname;
			cout << "Enter last name: " << endl;
			cin >> a->lastname;
			cout << "Enter student id: " << endl;
			cin >> a->studentid;
			cout << "Enter GPA: " << endl;
			cin >> a->gpa;
			add(a);
		}else if (!strcmp(input, "PRINT")){
			print();
		}else if (!strcmp(input, "DELETE")){
			int ID;
			cout << "Enter ID Number: " << endl;
			cin >> ID;
			remove(ID); 
		}else if (!strcmp(input, "GENERATE")) {
			int number = 0;
			int iterations = 0;
			cout << "# of students: " << endl;
			cin >> number;
			while(iterations < number) {
				int ID = 123456;
				Student* a = new Student;
				a->firstname = generateFirst();
				a->lastname = generateLast();
				a->id = ID;
				srand(time(NULL));
				double decimal = (double)rand()/(RAND_MAX);
				int integer = rand() % 5;
				a->gpa = decimal + integer;
				add(a);
				ID++; 
				iterations++;
			}
			cout << "Success: " << number << " students generated." << endl;
		}else if (!strcmp(input, "QUIT")){
			break;
		}else {
			cout << "Invalid input.  Would you like to try again?  Press y for yes and n for no. ";
			cin >> invalid;
		}
	}
	return 0;
}

//add to the hash table
void add(Student* a) {
	
}

void print() {
	
}
void remove(int ID) {
	
}

//this is the hash function that will return an index
int hash() {

}

//this will generate a random first name	
string generateFirst() {
	srand(time(NULL));
	ifstream file;
	string fileName = "firstnames.txt";
	file.open(fileName);

	string array[50];
	for (int i = 0; i < 50; i++) {
		file >> array[i];
	}
	int integer = rand() % 50;
	return array[integer];
}

//this will generate a random last name	
string generateLast() {
	srand(time(NULL));
	ifstream file;
	string fileName = "lastnames.txt";
	file.open(fileName);

	string array[50];
	for (int i = 0; i < 50; i++) {
		file >> array[i];
	}
	int integer = rand() % 50;
	return array[integer];
}	