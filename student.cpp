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

void student::assign_to_dorm(){} //*****
    
void student::assign_to_room(int roomnb)
{
    if(dorm->get_room(roomnb)->is_fully_occupied()) throw; // invalid assignment exception
    room = dorm->get_room(roomnb);
    dorm->get_room(roomnb)->increase_nb();
}

void student::display_info()
{
    cout << "student ID: " << ID << "\n"
        << "student FullName: " << FullName << "\n"
        << "Academic Year: " << AcademicYear << "\n";
    if ( is_residant )
    {
        cout << "Dormitory: " << dorm->get_dorm_name() << "\n"
            << "Room: " << room->get_room_nb();
    }
}
