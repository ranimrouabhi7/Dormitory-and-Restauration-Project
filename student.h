#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "room.h"

class student
{
private :
    int ID;
    std::string FullName;
    int AcademicYear;
public :
    student(int,std::string,int);
    // setters & getters
    virtual void set_ID(int);
    virtual void set_Fname(std::string);
    virtual void set_AYear(int);
    virtual int get_ID() const;
    virtual std::string get_Fname() const;
    virtual int get_AYear() const;

    // display
    virtual void display_info() const; 

    // == oprator overloading
    virtual bool operator == (const student&) const;

    // destructor
    virtual ~student() {};
};

class resident_student : public student
{
private :
    std::string dorm_name;
    int room;
public : 
    resident_student(int,std::string,int,std::string,int);

    // setters
    void set_dormitory(std::string);
    void set_room(int);

    // getters
    std::string get_dormitory() const;
    int get_room() const;

    // overrided functions
    void display_info() const override;
    bool operator == (const student&) const override;
};

#endif