//******************************************
//
// Akshobh Mirapurkar 
// Project 1
// Runtime class implementation
// September 10, 2018
//
//*****************************************

#include <iostream>
using namespace std;
    
class MyTime
{   
  public:

    // CONVERT THESE CONSTRUCTORS INTO A SINGLE CONSTRUCTOR THAT USES 
    // DEFAULT ARGUMENTS
    MyTime();
    MyTime(int h, int m, int s);   
   
      
    void Reset(int h, int m, int s);    
   
    friend MyTime operator + (const MyTime& t1, const MyTime& t2);
 
    friend MyTime operator - (const MyTime& t1, const MyTime& t2);
 
    friend MyTime operator * (const MyTime& t1, int num);

    friend MyTime operator / (const MyTime& t1, double num);

    friend std::istream& operator >>(std::istream& fin, MyTime& t);
    
    friend std::ostream& operator <<(std::ostream& fout, const MyTime& t);

    friend bool operator == (const MyTime& t1, const MyTime& t2);

    friend bool operator < (const MyTime& t1, const MyTime& t2);

    friend bool operator <= (const MyTime& t1, const MyTime& t2);

    void input(std::istream& ins);            

    void output(std::ostream& outs)const;

    int get_hours() const{return hours;}
    int get_minutes() const{return minutes;}
    int get_seconds()const {return seconds;}
   
  private:
      void simplify();
      int hours;      // hours can be > 24
      int minutes;   // 0 <= minutes <= 59
      int seconds;
 };
   
ostream& operator <<(ostream& outs, const MyTime& t1);


istream& operator >> (istream& ins, MyTime& t1);

