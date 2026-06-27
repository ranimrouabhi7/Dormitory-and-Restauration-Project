#include "dorm.h"
#include <iostream>

using namespace std;

dormitory::dormitory(int cap, string name)
{
    set_dorm_name(name);
    set_capacity(cap);
    available_rooms = cap;
    rooms = new room[cap];
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

void dormitory::set_rooms(int cap)
{
    rooms = new room[cap];
    for( int i = 0; i < cap; i++ )
    {
        rooms[i].set_room_nb(i+1);
        rooms[i].set_capacity(rooms_capacity);
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


void dormitory::add_student(student stud)
{
    if( get_available_rooms() == 0) throw ; // invalid assignment exception
    if( (rooms + stud.get_room())->is_fully_occupied() ) throw ; // the same 
    students.insert(students.begin() + stud.get_room(), stud);
    (rooms + stud.get_room())->increase_nb();
}