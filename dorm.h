#ifndef DORM_H
#define DORM_H
#include "restaurant.h"
#include "room.h"
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
    int available_rooms; 
    int rooms_capacity;
    
    // composition
    restaurant restau;
    room* rooms; // array
    
    int get_available_rooms(); // rooms that are not fully occupied
public :
    dormitory(const dormitory&); // necessary for the vector of dorms (reallocation process and ptr data member)
    dormitory(int,std::string,int); // restau default constructor will run

    // setters and getters
    void set_dorm_name(std::string);
    void set_capacity(int);
    void set_rooms(int,int);
    void set_rooms_capacity(int);
    std::string get_dorm_name();
    int get_capacity();
    int get_rooms_capacity();
    room* get_rooms();

    // methods
    void add_student(resident_student&,int);
    void remove_student(resident_student&);

    // destructor
    ~dormitory(){ delete[] rooms; }
};

#endif