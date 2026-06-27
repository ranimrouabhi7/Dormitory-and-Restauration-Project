#ifndef DORM_H
#define DORM_H
#include "restaurant.h"
#include "room.h"
#include "student.h"
#include <string>
#include <vector>

/*
capacity 
rooms system (composition) => to track rooms
retaurant (composition) => for meals and menues
available rooms (index track)
display (occupied and available)
*/

class dormitory 
{
private :
    std::string dorm_name;
    int capacity;
    int available_rooms; // = capacity - nb of students (the size of the vector of students)
    
    // composition
    restaurant restau;
    room* rooms; // array
    std::vector <student> students; 
public :
    dormitory(int,std::string);

    // setters and getters
    void set_dorm_name(std::string);
    void set_capacity(int);
    std::string get_dorm_name();
    int get_capacity();
    int get_available_rooms();
    room* get_room(int); 
};

#endif