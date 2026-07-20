#include "dorm.h"
#include <iostream>

using namespace std;

dormitory::dormitory(int cap, string name, int room_cap) : restau()
{
    set_dorm_name(name);
    set_capacity(cap);
    available_rooms = cap;
    set_rooms_capacity(room_cap);
    set_rooms(cap,room_cap);
}

dormitory::dormitory(const dormitory& other)
{
    dorm_name = other.dorm_name;
    capacity = other.capacity;
    rooms_capacity = other.rooms_capacity;
    available_rooms = other.available_rooms;
    students = other.students;
    restau = other.restau;

    rooms = new room[capacity];
    for(int i = 0; i < capacity; i++)
        rooms[i] = other.rooms[i];
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


void dormitory::add_student(resident_student& stud, int room)
{
    if( get_available_rooms() == 0) throw ; // invalid assignment exception
    if( (rooms + room)->is_fully_occupied() ) throw ; // the same 
    if( room == 0 ) throw ; // invalid room
    students.insert(students.begin() + room, stud);
    (rooms + room)->increase_nb();
}

void dormitory::remove_student(resident_student& stud)
{
    for(size_t i = 0; i < students.size(); i++)
    { if(students[i] == stud) 
        { 
            students.erase(students.begin() + i); 
            stud.set_dormitory("NOTHING");
            stud.set_room(0);
            return; 
        } 
    }
    throw ; // student not found exception
}

room* dormitory::get_rooms(){ return rooms; }