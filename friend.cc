//Akshobh Mirapurkar
//Project 2
//September 30, 2018

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<fstream>
#include "friend.h"
#include "date.h"
using namespace std;

//Construtor
Friend::Friend(){
	name = "No Name";
}

//Accessor Function
string Friend::get_name()const{
	return name;
}
//Accessor Function
Date Friend::get_bday()const{
	return bday;
}


bool Friend::operator == (const Friend& other)const{
	if((name == other.name) && (bday == other.bday)){
		return true;
	} else {
		return false;

	}
}

bool Friend::operator != (const Friend& other)const{
	if(!(name == other.name) && !(bday == other.bday)){
		return true;
	} else {
		return false;
	}
}

void Friend::input(istream& ins){
	//Checks to see if the stream is the same as cin	
	if(&ins == &cin){
		if(cin.peek() == '\n'){
			cin.ignore(100, '\n');
		}
		cout << "Name: ";
		getline(cin, name);
		cout << "Date: ";
		cin >> bday;
	} else {
		while(ins.peek() == '\n' || ins.peek() == '\r'){
			ins.ignore();
		}
		getline(ins, name);
		ins >> bday;
		ins.ignore(100, '\n');
	}
	
}

void Friend::output(ostream& outs)const{
	if(&outs == &cout){
		cout << "Name: " << name << endl;
		cout << "Birthday: " << bday << endl;
	} else {
		outs << name << endl;
		outs << bday << endl;
	}
}

istream& operator >>(istream& ins,Friend& f){
	f.input(ins);
	return ins;
}

ostream& operator <<(ostream& outs,const Friend& f){
	f.output(outs);
	return outs;
}




