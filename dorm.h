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
    int available_rooms; 
    int rooms_capacity;
    
    // composition
    restaurant restau;
    room* rooms; // array
    std::vector <student> students;
    
    int get_available_rooms(); // rooms that are not fully occupied
public :
    dormitory(int,std::string,int); // restau default constructor will run

    // setters and getters
    void set_dorm_name(std::string);
    void set_capacity(int);
    void set_rooms(int);
    void set_rooms_capacity(int);
    std::string get_dorm_name();
    int get_capacity();
    int get_rooms_capacity();

    // methods 
    void add_student(student,int);
    void remove_student(student,int);

    // destructor
    ~dormitory(){ delete[] rooms; }
};

#endif