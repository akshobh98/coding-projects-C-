//Akshobh Mirapurkar
//Project 5: Program that incorporates the concept of inheritance classes and creates a list of pointers to a parent class and adds objects to the list
//according to the user and outputs it to the screen and a file
//November 12, 2018

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<list>
#include<fstream>
#include "closet_item.h"
using namespace std;

//Displays menu and returns the user's choice
int menu();

int main(){
	cout << "Welcome to Closet ManagementTM, ALL RIGHTS RESERVED" << endl;

	string user;

	//Making a list of pointers called closet
	list<Closet_item*> closet;

	cout << "Please enter your username: ";
	cin >> user;
	
	string filename = user + ".txt"; //Makes the name of the text file

	ifstream ins;
	ins.open(filename.c_str());
	if(!ins.fail()){
		//Read in the identifier of the object at the top of the object in the string "something"
		string something;
		while(!ins.eof()){
			ins >> something;
			if(something == "shoes"){
				Closet_item* tmp = new Shoes;
				while(ins.peek() == '\n' || ins.peek() == '\r'){
					ins.ignore();
				}
				tmp -> input(ins);
				while(ins.peek() == '\n' || ins.peek() == '\r'){
                                	ins.ignore();
                        	}
				closet.push_back(tmp);
			} else if(something == "skeletons"){
				Closet_item* tmp = new Skeletons;
				while(ins.peek() == '\n' || ins.peek() == '\r'){
					ins.ignore();
				}
				tmp -> input(ins);
				while(ins.peek() == '\n' || ins.peek() == '\r'){
                                	ins.ignore();
                        	}
				closet.push_back(tmp);
			} else if(something == "nunchuks"){
				Closet_item* tmp = new Nunchuks;
				while(ins.peek() == '\n' || ins.peek() == '\r'){
					ins.ignore();
				}
				tmp -> input(ins);
				while(ins.peek() == '\n' || ins.peek() == '\r'){
                                	ins.ignore();
                        	}
				closet.push_back(tmp);
			} else if(something == "books"){
				Closet_item* tmp = new Books;
				while(ins.peek() == '\n' || ins.peek() == '\r'){
                                	ins.ignore();
                        	}
				tmp -> input(ins);
				while(ins.peek() == '\n' || ins.peek() == '\r'){
                                	ins.ignore();
                        	}
				closet.push_back(tmp);
			} else if(something == "pets"){
				Closet_item* tmp = new Pets;
				while(ins.peek() == '\n' || ins.peek() == '\r'){
                                	ins.ignore();
                        	}
				tmp -> input(ins);
				while(ins.peek() == '\n' || ins.peek() == '\r'){
                                	ins.ignore();
                        	}
				closet.push_back(tmp);
			}
		}

		ins.close();
	} else {
		//Make a new file with the user's desired name if the file doesn't already exist
		cout << endl;
		cout << "Looks like you don't have an account!" << endl;
		cout << "Lets have you signed up!" << endl;
		string name;
		cout << "Enter your full name without spaces to signup: ";
		cin >> name;
		filename = name + ".txt";
	}
 
	//Menu shows on the screen and returns the choice to the variable choice
	int choice = 0;
	do{
		choice = menu();
		switch(choice){
			case 1:{
					Closet_item* tmp;
					tmp = new Shoes;
					tmp -> input(cin);
					closet.push_back(tmp);
				}
				break;
			case 2:{
					Closet_item* tmp;
					tmp = new Skeletons;
					tmp -> input(cin);
					closet.push_back(tmp);
				}
				break;
			case 3:{
					Closet_item* tmp;
					tmp = new Nunchuks;
					tmp -> input(cin);
					closet.push_back(tmp);
				}
				break;
			case 4:{
					Closet_item* tmp;
					tmp = new Books;
					tmp -> input(cin);
					closet.push_back(tmp);
				}
				break;
			case 5:{
					Closet_item* tmp;
					tmp = new Pets;
					tmp -> input(cin);
					closet.push_back(tmp);
				}
				break;
			case 6:{
					cout << endl;
					list<Closet_item*>::iterator it;
					for(it = closet.begin(); it != closet.end(); ++it){
						(*it) -> output(cout);
					}
				}
				break;
			case 7: cout << "See you soon!" << endl;
				break;

			default:{
					cout << "Please enter a valid choice :)" << endl;
				}
				break;
		}
	} while(choice != 7);
	//Output the list in the file to create a backup
	ofstream outs;
	outs.open(filename.c_str());
	list<Closet_item*>::iterator it;
        for(it = closet.begin(); it != closet.end(); ++it){
                (*it) -> output(outs);
	}

	outs.close();


return 0;
}

int menu(){
	int c = 0;
	cout << endl;
	cout << "1) Add new shoes " << endl;
	cout << "2) Add new skeletons" << endl;
	cout << "3) Add new nunchuks" << endl;
	cout << "4) Add new books" << endl;
	cout << "5) Add new pets" << endl;
	cout << "6) Display current closet" << endl;
	cout << "7) Exit" << endl;
	cout << endl;
	cout << "Select from the choices above: ";
	cin >> c;
	return c;
}
