//Akshobh Mirapurkar
//Project 5: Program that incorporates the concept of inheritance classes and creates a list of pointers to a parent class and adds objects to the list
//according to the user and outputs it to the screen and a file
//Implementation file of closet_item.h
//November 12, 2018


#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<fstream>
#include<list>
#include "closet_item.h"
using namespace std;

//Parent class defined in the Closet_item.h file

//Shoes class begins
Shoes::Shoes(double s, string n, string c){
	size = s;
	name = n;
	color = c;
}

void Shoes::input(istream& ins){
	//Checking the input stream to use the appropriate input
	if(&ins == &cin){
       		cout << "Enter size (US Sizing): ";
              	cin >> size;
                cout << "Enter name: ";
		//So the name can have a space
             	while(cin.peek() == '\n' || cin.peek() == '\r'){
			cin.ignore();
		}
		getline(cin, name);
                cout << "Enter color: ";
		while(cin.peek() == '\n' || cin.peek() == '\r'){
               		cin.ignore();
              	}
              	getline(cin, color);
	} else {
               	ins >>  size;
		while(ins.peek() == '\n' || ins.peek() == '\r'){
                     	ins.ignore();
             	}
		getline(ins, name);
		while(ins.peek() == '\n' || ins.peek() == '\r'){
               		ins.ignore();
            	}
		getline(ins, color);
		while(ins.peek() == '\n' || ins.peek() == '\r'){
                	ins.ignore();
                }
      	}
}

void Shoes::output(ostream& outs)const{
	//Checking the output stream to use the appropriate output 
	if(&outs == &cout){
		cout << "Shoes --" << endl;
             	cout << "Size (US Sizing): " << size << endl;
               	cout << "Name: " << name << endl;
             	cout << "Color: " << color << endl;
		cout << endl;
	} else {
		outs << "shoes" << endl; //Output the "identifier" for the class in the text file
		outs << size << endl;
                outs << name << endl;
             	outs << color << endl;
     	}
}
//Shoes class ends

//Skeletons class begins
Skeletons::Skeletons(double l, int b, string s, string g){
	length = l;
	bones = b;
	skull = s;
	gender = g;
}

void Skeletons::input(istream& ins){
	if(&ins == &cin){
        	cout << "Enter length of the skeleton in feet: ";
                cin >> length;
               	cout << "Enter number of bones: ";
              	cin >> bones;
              	cout << "Does the skeleton have a skull?: ";
              	cin >> skull;
		cout << "Enter the gender of the skeleton: ";
		cin >> gender;
	} else {
            	ins >> length;
              	ins >> bones;
              	ins >> skull;
		ins >> gender;
      	}
}

void Skeletons::output(ostream& outs)const{
	if(&outs == &cout){
		cout << "Skeleton --" << endl;
		cout << "Length: " << length << "ft" <<  endl;
		cout << "Number of bones: " << bones << endl;
		cout << "Does the skeleton have a skull: " << skull << endl;
		cout << "Gender: " << gender << endl;
		cout << endl;
	} else {
		outs << "skeletons" << endl;	//The identifier for Skeletons object
		outs << length << endl;
		outs << bones << endl;
		outs << skull << endl;
		outs << gender << endl;
	}
}
//Skeletons class ends

//Nunchuks class begins
Nunchuks::Nunchuks(string m, string r, double l, string u){
	material = m;
      	roch = r;
   	length = l;
	usedornew = u;
}

void Nunchuks::input(istream& ins){
	if(&ins == &cin){
      		cout << "Enter the material of the nunchuk (Wooden maybe): ";
          	cin >> material;
              	cout << "Rope or Chain?: ";
               	cin >> roch;
		if(roch == "Rope" || roch == "rope"){
			cout << "Enter the length of the rope in meters: ";
			cin >> length;
		} else if(roch == "Chain" || roch == "chain"){
			cout << "Enter the length of the chain in meters: ";
			cin >> length;
		}
		cout << "Is the nunchuk used or new? ";
		cin >> usedornew;
 	} else {
           	ins >> material;
             	ins >> roch;
              	ins >> length;
              	ins >> usedornew;
    	}
}


void Nunchuks::output(ostream& outs)const{
	if(&outs == &cout){
		cout << "Nunchuk --" << endl;
		cout << "Material: " << material << endl;
		cout << "Rope/Chain:" << roch << endl;
		cout << "Length: " << length << "m" << endl;
		cout << "Used/New: " << usedornew << endl;
		cout << endl;
	} else {
		outs << "nunchuks" << endl;	//The identifier for Nunchuks object
		outs << material << endl;
		outs << roch << endl;
		outs << length << endl;
		outs << usedornew << endl;
	}
}
//Nunchuks class ends

//Book class begins
Books::Books(string g, string n, string a){
 	genre = g;
     	name = n;
      	author = a;
}

void Books::input(istream& ins){
 	 if(&ins == &cin){
       		cout << "Enter the genre of the book:  ";
              	cin >> genre;
            	cout << "Enter the name of the book:  ";
		while(cin.peek() == '\n' || cin.peek() == '\r'){
			cin.ignore();
		}
		getline(cin, name);
               	cout << "Enter the author of the book: ";
       		while(cin.peek() == '\n' || cin.peek() == '\r'){
                	cin.ignore();
              	}
		getline(cin, author);
	} else {
           	ins >> genre;
		while(ins.peek() == '\n' || ins.peek() == '\r'){
               		ins.ignore();
              	}
              	getline(ins, name);
		while(ins.peek() == '\n' || ins.peek() == '\r'){
                	ins.ignore();
              	}
             	getline(ins, author);
		while(ins.peek() == '\n' || ins.peek() == '\r'){
                	ins.ignore();
       		}
	}
}
 
void Books::output(ostream& outs)const{
	if(&outs == &cout){
		cout << "Books -- " << endl;
               	cout << "Genre: " << genre << endl;
              	cout << "Name: " << name << endl;
              	cout << "Author: " << author <<  endl;
		cout << endl;
     	} else {
		outs << "books" << endl;	//The identifier for Books object
                outs << genre << endl;
             	outs << name << endl;
                outs << author << endl;
    	}
}
//Books class ends

//Pets class begins
Pets::Pets(string t, string b, string as, int a){
	type = t;
	breed = b;
	adopt = as;
	age = a;
}

void Pets::input(istream& ins){
	if(&ins == &cin){
      		cout << "Enter the type of animal:  ";
             	cin >> type;
             	cout << "Enter the breed:  ";
    		while(cin.peek() == '\n' || cin.peek() == '\r'){
              		cin.ignore();
		}
              	getline(cin, breed);
           	cout << "Is the animal adopted?: ";
             	cin >> adopt;
		cout << "Enter the age of the animal: ";
			cin >> age;
   	} else {
             	ins >> type;
		while(ins.peek() == '\n' || ins.peek() == '\r'){
               		ins.ignore();
             	}
              	getline(ins, breed);
		while(ins.peek() == '\n' || ins.peek() == '\r'){
                  	ins.ignore();
            	}
             	ins >> adopt;
		ins >> age;
    	}
}

void Pets::output(ostream& outs)const{
	if(&outs == &cout){
    		cout << "Pets -- " << endl;
              	cout << "Type of animal: " << type << endl;
             	cout << "Breed: " << breed << endl;
               	cout << "Adopted?: " << adopt << endl;
             	cout << "Age: " << age << " year(s)" << endl;
		cout << endl;
 	} else {
		outs << "pets" << endl;		//The identifier for Pets object
               	outs << type  << endl;
               	outs << breed << endl;
               	outs << adopt << endl;
		outs << age << endl;
   	}
}
//Pets class ends

