#include "dorm.h"
#include <iostream>

using namespace std;

dormitory::dormitory(int cap, string name, int room_cap) : restau(0)
{
    set_dorm_name(name);
    set_capacity(cap);
    available_rooms = cap;
    set_rooms_capacity(room_cap);
    set_rooms(cap,room_cap);
}

void dormitory::set_dorm_name(string name){ dorm_name = name; }
    
void dormitory::set_capacity(int cap)
{
    if(cap > 0) 
    {   
        capacity = cap;
        return;
    }
    throw ; // invalid input exception
}

void dormitory::set_rooms_capacity(int room_cap)
{
    if(room_cap > 0) 
    {   
        rooms_capacity = room_cap;
    }
    else throw ; // invalid input exception
}

void dormitory::set_rooms(int cap, int rooms_cap)
{
    rooms = new room[cap];
    for( int i = 0; i < cap; i++ )
    {
        rooms[i].set_room_nb(i+1);
        rooms[i].set_capacity(rooms_cap);
    }
}
    
int dormitory::get_capacity(){ return capacity; }
    
string dormitory::get_dorm_name(){ return dorm_name; }

int dormitory::get_available_rooms()
{
    int available = 0;
    for(int i = 0; i < capacity; i++)
    {
        if( ! (rooms + i)->is_fully_occupied() ) available++;
    }
    return available;
}

int dormitory::get_rooms_capacity(){ return rooms_capacity; }


void dormitory::add_student(student& stud, int room)
{
    if( get_available_rooms() == 0) throw ; // invalid assignment exception
    if( (rooms + room)->is_fully_occupied() ) throw ; // the same 
    students.insert(students.begin() + room, stud);
    (rooms + room)->increase_nb();
    stud.set_dormitory(dorm_name);
    stud.set_room(room);
}

void dormitory::remove_student(student& stud, int room)
{
    for(int i = 0; i < students.size(); i++)
    { if(students[i] == stud) 
        { 
            students.erase(students.begin() + i); 
            stud.set_accomondation_status(false);
            stud.set_dormitory("NOTHING");
            stud.set_room(0);
            return; 
        } 
    }
    throw ; // student not found exception
}