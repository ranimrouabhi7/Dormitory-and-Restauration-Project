#include "dorm.h"
#include <iostream>

using namespace std;

dormitory::dormitory(int,std::string){}

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
    
int dormitory::get_capacity(){ return capacity; }
    
string dormitory::get_dorm_name(){ return dorm_name; }

int dormitory::get_available_rooms(){ return capacity - sizeof(students); }

room* dormitory::get_room(int nb)
{
    for(int i = 0; i < sizeof(rooms); i++)
    {
        if((rooms + i)->get_room_nb() == nb) return (rooms + i);
    }
} 