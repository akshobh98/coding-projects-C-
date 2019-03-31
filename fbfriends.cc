//Akshobh Mirapurkar
//Project 2
//September 30, 2018

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<algorithm>
#include "fbfriends.h"
#include "date.h"
#include "friend.h"
using namespace std;

//Constructor
FBFriends::FBFriends(){
	used = 0;
	current_index = 0;
	data = new Friend[5];
	capacity = 5;
}

//Deconstructor
FBFriends::~FBFriends(){
	delete [] data;
}

//Copy constructor
FBFriends::FBFriends(const FBFriends& other){
	capacity = other.capacity;
	data = new Friend[capacity];
	used = other.used;	
	current_index = other.current_index;
	for(int i = 0; i < used; i++){
		data[i] = other.data[i];
	}
}

void FBFriends::operator =(const FBFriends& other){
	if(this == &other){ //Checks if both the arguments  have the same address, if they do, then just return the object itself
		return;
	} else {
		delete []data;
		capacity = other.capacity;
		data = new Friend[capacity];
		used = other.used;
		copy(other.data, other.data + used, data);
	}
}

void FBFriends::start(){
	current_index = 0;
}

void FBFriends::advance(){
	current_index++;
}	

bool FBFriends::is_item(){
	return current_index < used;
}	

Friend FBFriends::current(){
	return data[current_index];
}

void FBFriends::remove_current(){
	int flag = 0;
	for(int i = 0; i < (used - 1); i++){
		if(current_index == i){	 	//If current_index becomes i the flag increments
			flag++;
		}
		if(flag == 1){
			data[i] = data[i + 1]; 	//If the flag increments shift every element to the left
		}
	}
	used--;
}

void FBFriends::attach(const Friend& f){
	if(used == capacity){	//If the array is full, then call the resize
		resize();
	}	
	
	if(!(is_item())){
		current_index = used - 1;
	}	
	
	for(int i = 0; i > current_index; i--){		//Shifts everything rightward
		data[i] = data[i - 1];
	}
	
	data[current_index + 1] = f;	//Put the object into the index after the current_index
	used++;
		
}

void FBFriends::insert(const Friend& f){
	if(used == capacity){
                resize();
        }
	
	if(!(is_item())){
		current_index  = used;
	}

	for(int i = used; i > current_index; i--){
		data[i] = data[i - 1];
	}
	
	data[current_index] = f;
	used++;

        
}

void FBFriends::resize(){
	Friend *tmpptr;	//Make a new temp pointer
	tmpptr = new Friend[capacity + 5]; //Point it to a dynamic array		
	capacity +=5;	//To break out of the if statement condition resize is used in
	for(int i = 0; i < used; i++){
		tmpptr[i] = data[i];	//Copy the existing array to the new dynamic array
	}
	delete [] data;	//Delete the existing array
	data = tmpptr;	//Make the two pointers point to the same array
}

void FBFriends::show_all(ostream& outs)const{
	for(int i = 0; i < used; i++){
		outs << data[i] << endl;
	}
}

Friend FBFriends::find_friend(const string& name)const{	
	for(int i = 0; i < used; i++){
		if(name == data[i].get_name()){
			return data[i];
		}
	}
	
	cout << "No such friend found" << endl;
	return Friend();
}

bool FBFriends::is_friend(const Friend& f)const{
	for(int i = 0; i < used; i++){
                if(f == data[i]){
                        return true;
                } else {
			return false;
		}
	}

	return 0;	
}

void FBFriends::bday_sort(){
	
	int min_idx; 
	Friend tmp;
  
    // One by one move boundary of unsorted subarray 
    for (int i = 0; i < (used - 1); i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (int j = i + 1; j < used; j++){
          if (data[j].get_bday() < data[min_idx].get_bday()){ 
            min_idx = j; 
  	   }
	}
        // Swap the found minimum element with the first element 
        tmp = data[i];
	data[i] = data[min_idx];
	data[min_idx] = tmp;
    } 

	cout << "They are all sorted!" << endl;
}

void FBFriends::load(istream& ins){	
	Friend tmp;	//A Friend object to read values into
	ins >> tmp;	
	while(!(ins.eof())){
		attach(tmp);	//Attaches the object in the array
		cout << tmp;	
		ins >> tmp;	
		current_index++; //Puts the next element in the next index	
	}

}

void FBFriends::save(ostream& outs){
	for(int i = 0; i < used; i++){
		outs << data[i] << endl;
	}
}


