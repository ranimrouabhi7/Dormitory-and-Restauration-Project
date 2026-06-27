#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "dorm.h"
#include "room.h"
/*
ID
FullName
AcademicYear
Dorm => add it to the students vector of the dorm
Room => assign it to the room 
2 vectors 1 for students and 1 for rooms and the index of the student is the same as the index of its room in that dorm
if a student is not a residant he wont be in the vector of any dorm 

Display
*/

class student
{
private :
    int ID;
    std::string FullName;
    int AcademicYear;
    bool is_residant;
    dormitory* dorm; // ptr to the dorm of the student
    room* room; // ptr to its room 
public :
    student(int,std::string,int,bool); // ptrs are null initially
    
    // setters & getters
    void set_ID(int);
    void set_Fname(std::string);
    void set_AYear(int);
    void set_accomondation_status(bool);
    int get_ID();
    std::string get_Fname();
    int get_AYear();
    bool get_accomondation_status();

    void assign_to_dorm(); // if residant, we assign the pointer
    void assign_to_room(int); // we check here, we assign the pointer 

    // display
    void display_info();
};

#endif