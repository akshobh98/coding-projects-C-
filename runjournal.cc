//********************************************************
//
// Akshobh Mirapurkar
// Project 1
// September 16, 2018
// Program that stores a running journal
//
//
//
//********************************************************


#ifndef RUNJOURNAL_H 
#define RUNJOURNAL_H
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
#include "runjournal.h"
using namespace std;

//Constructors
Runjournal::Runjournal(){
	used = 0;
}

//Function that records and saves runs into an array
void Runjournal::record(Runtime r1){
	if(used < capacity){		//Verifying that array is not full
		data[used] = r1;
		used++;			
	} else {
		cout << "Can't load another run. Sorry" << endl;
	}

}

void Runjournal::display()const{
	for(size_t i = 0; i < used; i++){ 	//Loops and displays each element of the array
		cout << data[i] << endl;
	}

}

MyTime Runjournal::total_time(){
	MyTime sum; 
	for(size_t i = 0; i < used; i++){
		sum = sum + data[i].get_time();
	}
	
	return sum;
}

MyTime Runjournal::average_pace(){
	Runtime temp;
	MyTime sum;	//Adds all the times of the runs 
	for(size_t i = 0; i < used; i++){
		sum = sum + data[i].get_time();
	}

	temp.set_time(sum);	//Sets the total time to an object temp
	
	double dist = 0.0;	//Adds all the distances of the runs
	for(size_t i = 0; i < used; i++){
		dist = dist + data[i].get_distance();
	}

	temp.set_distance(dist);	//Sets the total distance to temp

	
	return temp.pace();	//Calls the pace function to get the average pace
}

double Runjournal::total_distance(){
	double sum = 0.0;
	for(size_t i = 0; i < used; i++){
			sum = sum + data[i].get_distance();
	}
	
	return sum;
}

//Function to sort the runs by time
void Runjournal::time_sort(){
	bool done = false;
    	MyTime tmp;
    	while(!done){
        	done = true;
        	for(int i=used-1; i > 0; --i){
            		if(data[i].get_time() < data[i-1].get_time()){
                		done = false;
                		tmp = data[i].get_time();
                		data[i].set_time(data[i - 1].get_time());
                		data[i - 1].set_time(tmp);
                        }
                }
        }
}

//Function to sort the runs by distance
void Runjournal::distance_sort(){
	bool done = false;	
    	double tmp;
    	while(!done){
        	done = true;
        	for(size_t i = used - 1; i > 0; --i){
            		if(data[i].get_distance() < data[i - 1].get_distance()){
                		done = false;
                		tmp = data[i].get_distance();
                		data[i].set_distance(data[i - 1].get_distance());
                		data[i - 1].set_distance(tmp);
                        }
                }
        }
}

void Runjournal::distance_view(double target){
	//Flag to check if the target is found or not
	int flag = 0;


	for(size_t i = 0; i < used; i++){
		if(data[i].get_distance() == target){
			cout << data[i] << endl;
			flag++;	
		}
	
	}

	//Since flag doesn't increment it never gets into the for loop, so no such distance is found
	if(flag == 0){
		cout << "No such run found" << endl;
	}
	
}

void Runjournal::find_remove(Runtime target){
	char prompt; 

	//For loop for a linear search going through each element of the array
	for (size_t i = 0; i < used; i++)
	{
		//If target is found prompts the choice to remove the element
		if (data[i] == target)
		{
			cout << "Entry found. Remove? (y) ";
			cin >> prompt;
			if (prompt == 'y' || prompt == 'Y')
			{
				while (i < (used - 1)) 	//Loop to remove the element of the array
				{
					data[i] = data[i + 1]; //Copies each element over to the previous index
					i++;
				}
				used--;	//Decrementing the size of the array
			}
			return;
		}
	}
	// If entry not found.
	cout << "Entry not found.";
}	

//Function to save the runs to a file	
void Runjournal::save(ofstream &ofs){
	for(size_t i = 0; i < used; i++){
		ofs << data[i] << endl;
	}
}

#endif
