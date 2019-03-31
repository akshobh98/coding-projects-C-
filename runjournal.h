//******************************************
//
// Akshobh Mirapurkar 
// Project 1
// Runtime class implementation
// September 10, 2018
//
//*****************************************

#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include "runtime.h"

using namespace std;

const int capacity = 200;

class Runjournal{
	private:
		size_t used;
		Runtime data[capacity];
 	public:
		Runjournal();
		void record(Runtime r1);
		void display()const;
		MyTime total_time();
		MyTime average_pace();
		void find_remove(Runtime target);
		void distance_view(double target);
		void time_sort();
		void distance_sort();
		double total_distance();
		void save(ofstream &ofs);
};

	
