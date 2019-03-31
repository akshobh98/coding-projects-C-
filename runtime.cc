//******************************************
//
// Akshobh Mirapurkar 
// Project 1
// Runtime class implementation
// September 10, 2018
//
//*****************************************

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<cmath>
#include "runtime.h"
using namespace std;

Runtime::Runtime(){
	distance = 0.0;
}

Runtime Runtime::operator + (const Runtime &rhs)const{
	Runtime temp;	
	temp.rtime = rtime + rhs.rtime;
	temp.distance = distance + rhs.distance;
	return temp;
}

Runtime Runtime::operator - (const Runtime &rhs)const{
	Runtime temp;
	temp.rtime = (rtime - rhs.rtime);
	temp.distance = abs(distance - rhs.distance);
	return temp;
}

Runtime Runtime::operator * (const double &rhs)const{
	Runtime temp;
	temp.rtime = rtime * rhs;

	temp.distance = distance * rhs;
	return temp;
}

Runtime Runtime::operator /(const double &rhs)const{
	Runtime temp;
	temp.rtime = rtime / rhs;
	temp.distance = distance / rhs;
	return temp;
}	


bool Runtime::operator == (const Runtime &rhs)const{
	if((rtime == rhs.rtime) && (distance == rhs.distance)){
		return true;
	} else {
		return false;
	}
}

bool Runtime::operator != (const Runtime &rhs)const{
	Runtime temp;
	if(!(rtime == temp.rtime) && !(distance == temp.distance)){
		return true;
	} else {
		return false;
	}
}

bool Runtime::distance_equal(double d)const{
	if(abs(distance - d)< 0.1){
		return true;
	} else {
		return false;
	}
}

void Runtime::input(istream &ins){
	char junk;
	if (&ins == &cin)	//Checks to see if the streams are the same
		cout << "Time: ";	//If they are the output prints on the screen
	ins >> rtime;
	ins.get(junk);
	if (&ins == &cin)
		cout << "Distance: ";
	ins >> distance;
}

istream& operator >>(istream &ins, Runtime &rhs){
	rhs.input(ins);
	return ins;
}

void Runtime::output(ostream &outs)const{
	if (&outs == &cout)	//Checks to see if the streams are the same
	{
		outs << "Time: " << rtime << endl;	//If they are the output prints on the screen
		outs << "Distance: " << distance << endl;
	}
	else
	{
		outs << rtime << " " << distance << endl;	//Else in a file
	}
}

ostream& operator <<(ostream &outs, const Runtime &rhs){
	rhs.output(outs);	
	return outs;
}

//Reverses the arguments for multiplication
Runtime operator *(const double& lhs, const Runtime& rhs){
	Runtime temp;	
	temp.set_time(rhs.get_time() * lhs);	//Sets the time as the product of rtime of rhs and the double lhs
	temp.set_distance(rhs.get_distance() * lhs);	//Sets the distance as the product of distance of rhs and the double lhs
	return temp;	//returns temp
}
