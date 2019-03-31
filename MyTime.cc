//******************************************
//
// Akshobh Mirapurkar 
// Project 1
// Runtime class implementation
// September 10, 2018
//
//*****************************************


// The implementation file for the MyTime class
#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
// Constructors
MyTime::MyTime(){
	hours = 0;
	minutes = 0;
	seconds = 0;
}

MyTime::MyTime(int h, int m,int s){
	hours = h;
	minutes = m;
	seconds = s;
}

void MyTime::Reset(int h, int m,int s){
	hours = h;
	minutes = m;
	seconds = s;
}

void MyTime::simplify(){
	minutes += seconds/60;
	seconds = seconds%60;
       	hours += minutes/60;
	minutes = minutes%60;
}

MyTime operator + (const MyTime& t1, const MyTime& t2){
	MyTime tmp;
        tmp.hours = t1.hours + t2.hours;
	tmp.minutes = t1.minutes + t2.minutes;
	tmp.seconds = t1.seconds + t2.seconds;
	tmp.simplify();
	return tmp;
}

MyTime operator - (const MyTime& t1, const MyTime& t2){
	MyTime tmp;
	tmp.seconds = 
		abs((t1.hours*3600+t1.minutes*60+t1.seconds) 
		- (t2.hours*3600+t2.minutes*60+t2.seconds));
	tmp.simplify();
	return tmp;
}

MyTime operator / (const MyTime& t1, double num){
	MyTime tmp;
	tmp.seconds = t1.hours*3600 + t1.minutes*60 + t1.seconds;
	tmp.seconds /= num;
	tmp.simplify();
	return tmp;
}

MyTime operator * (const MyTime& t1, int num){
	MyTime tmp;
        tmp.seconds = t1.hours*3600 + t1.minutes*60 + t1.seconds;
	tmp.seconds *= num;
	tmp.simplify();
	return tmp;
}

bool operator == (const MyTime& t1, const MyTime& t2){
	return t1.hours == t2.hours && t1.minutes == t2.minutes
				&&t1.seconds == t2.seconds;
}

bool operator < (const MyTime& t1, const MyTime& t2){
	return (t1.hours*3600 + t1.minutes*60 + t1.seconds) < 
		(t2.hours*3600 + t2.minutes*60 + t2.seconds);
}

bool operator <=(const MyTime& t1, const MyTime& t2){
	return t1 == t2 || t1 < t2;
}

void MyTime::input(istream&ins){
       // Here you are to copy the implementation code from the >> operator shown below
	// remember to that variables will be local here - so no referene to t1
       //Then you can have the >> operator call this function.
      // In the .h file remove the word friend for the operator and move its prototype to a spot
      // under the class declaration
	char junk;
        ins>>hours;
        ins.get(junk);
        ins>>minutes;
        ins.get(junk);
        ins>>seconds;
        simplify();
}

void MyTime::output(ostream& outs)const{
	// Do the same thing a you did for the function above except using the code for the << 
	//operator
	outs<<hours<<':'<<setw(2)<<setfill('0')<<minutes;
        outs<<':'<<setw(2)<<setfill('0')<<seconds;


}


ostream& operator <<(ostream& outs, const MyTime& t1){
        /*outs<<t1.hours<<':'<<setw(2)<<setfill('0')<<t1.minutes;
	outs<<':'<<setw(2)<<setfill('0')<<t1.seconds;*/
	t1.output(outs);
	return outs;
}

istream& operator >> (istream& ins, MyTime& t1){
	/*char junk;
	ins>>t1.hours;
  	ins.get(junk);
	ins>>t1.minutes;
	ins.get(junk);
	ins>>t1.seconds;
	t1.simplify();*/
	t1.input(ins);
	return ins;
}


