#include "student.h"
#include <iostream>

using namespace std;

student::student(int id, string fname, int acyear) // is not resident
{
    set_ID(id);
    set_Fname(fname);
    set_AYear(acyear);
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
    
int student::get_ID() const { return ID; }
    
string student::get_Fname() const { return FullName; }
    
int student::get_AYear() const { return AcademicYear; }

void student::display_info() const
{
    cout << "student ID: " << ID << "\n"
         << "student FullName: " << FullName << "\n"
         << "Academic Year: " << AcademicYear << "\n";
}

bool student::operator == (student& stud) const
{
    if(ID != stud.ID) return false;
    if(FullName != stud.FullName) return false;
    if(AcademicYear != stud.AcademicYear) return false;
    return true;
}

resident_student::resident_student(int id, string fname, int acyear, string dorm, int room): student(id,fname,acyear)
{
    set_dormitory(dorm);
    set_room(room);
}

void resident_student::set_dormitory(string dorm) { dorm_name = dorm;}

void resident_student::set_room(int room) { this->room = room; }

string resident_student::get_dormitory() const { return dorm_name; }
    
int resident_student::get_room() const { return room; }

void resident_student::display_info() const
{
    student::display_info();
    cout << "dorm name: " << dorm_name << "\n"
        << "room number: " << room << "\n";
}

bool resident_student:: operator == (student& stud) const
{
    if( ! this -> student::operator == (stud)) return false;
    const resident_student* res = dynamic_cast <const resident_student*> (&stud);
    if(res == nullptr) return false;
    if(dorm_name != res->dorm_name) return false; 
    if(room != res->room) return false;
    return true;
}
