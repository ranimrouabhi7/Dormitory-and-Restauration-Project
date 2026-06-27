#include "student.h"
#include <iostream>

using namespace std;

student::student(int id, string fname, int acyear, bool is_res)
{
    set_ID(id);
    set_Fname(fname);
    set_AYear(acyear);
    set_accomondation_status(is_res);
}

void student::set_ID(int id) // id should contain exactly 4dgs
{
    if(id / 1000 == 0 && id > 0) ID = id;
    else throw; // the catch in the main (do not forget to create the exception class)
}
    
void student::set_Fname(string fname){ FullName = fname; }
    
void student::set_AYear(int year)
{
    if(year < 1) throw; // the invalid data exception class
    AcademicYear = ( year <= 5 ? year : 1 );
}
    
void student::set_accomondation_status(bool residant){ is_residant = residant; }
    
int student::get_ID(){ return ID; }
    
string student::get_Fname(){ return FullName; }
    
int student::get_AYear(){ return AcademicYear; }
    
bool student::get_accomondation_status(){ return is_residant; }

string student::get_dormitory(){ return dormitory_name; }
    
int student::get_room(){ return room_number; }

void student::display_info()
{
    cout << "student ID: " << ID << "\n"
        << "student FullName: " << FullName << "\n"
        << "Academic Year: " << AcademicYear << "\n";
    if ( is_residant )
    {
        cout << "Dormitory: " << dormitory_name << "\n"
            << "Room: " << room_number;
    }
}
