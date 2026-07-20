#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class student
{
private :
    int ID;
    std::string FullName;
    int AcademicYear;
public :
    student(int,std::string,int);
    // setters & getters
    void set_ID(int);
    void set_Fname(std::string);
    void set_AYear(int);
    int get_ID() const;
    std::string get_Fname() const;
    int get_AYear() const;

    // display
    virtual void display_info() const; 

    // == oprator overloading
    virtual bool operator == (student&) const;

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
    bool operator == (student&) const override;
};

#endif