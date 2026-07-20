#include "room.h"
#include <iostream>

using namespace std;

room::room(int nb, int cap)
{ 
    nb_of_students = 0;
    set_room_nb(nb);
    set_capacity(cap);
}
    
void room::set_room_nb(int nb){ room_nb = nb; }
    
void room::set_capacity(int cap){ capacity = (cap > 0 ? cap : 1); }
    
int room::get_room_nb(){ return room_nb; }
    
int room::get_capacity(){ return capacity; }

void room::increase_nb(){ nb_of_students++; }
    
bool room::is_fully_occupied(){ return capacity==nb_of_students; }

void room::add_a_student(resident_student& stud)
{
    if( this->is_fully_occupied() ) throw;
    students.push_back(stud);
    nb_of_students++;
}

bool room::is_resident_here(resident_student& stud)
{
    for(resident_student& s : students)
        if(s == stud) return true;
    return false;
}

void room::remove_a_student(resident_student& stud)
{
    for( auto it = students.begin(); it != students.end(); it++ )
    {
        if ( *it == stud ) // it is the itterator pointer (to the current obj)
        {
            students.erase(it);
            nb_of_students--;
            break;
        }
    }
}


