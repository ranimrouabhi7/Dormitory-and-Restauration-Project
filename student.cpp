#include "student.h"
#include <iostream>

using namespace std;

student::student(int id, string fname, int acyear, bool is_res)
{
    set_ID(id);
    set_Fname(fname);
    set_AYear(acyear);
    set_accomondation_status(is_res);
    set_dormitory("NOTHING");
    set_room(0);
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

void student::set_dormitory(string dorm){ dormitory_name = dorm; }
    
void student::set_room(int roomnb){ room_number = roomnb; }
    
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

bool student::operator == (student stud)
{
    if(ID != stud.ID) return false;
    if(FullName != stud.FullName) return false; 
    if(AcademicYear != stud.AcademicYear) return false;
    if(is_residant != stud.is_residant) return false;
    if(room_number != stud.room_number) return false;
    return true;
}
