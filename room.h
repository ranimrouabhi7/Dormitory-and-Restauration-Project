#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include "student.h"
/*
an array of room numbers (a ptr/dynamic arr) 

rooms occupancy 
prevent over-occupancy
*/

class room
{
private :
    int room_nb;
    int capacity;
    int nb_of_students; // increased when assigned
    std::vector <resident_student> students;
public :
    room() : room_nb(0), capacity(1), nb_of_students(0) {}; 
    room(int,int);
    
    // setters & getters
    void set_room_nb(int);
    void set_capacity(int);
    int get_room_nb();
    int get_capacity();

    // method 
    void increase_nb();
    bool is_fully_occupied();
    void add_a_student(resident_student&);
    void remove_a_student(resident_student&);
    bool is_resident_here(resident_student&);
};

#endif