#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <vector>
#include <string>

/*
daily meals 
a vector for each (breakfast,lunch,dinner)
each day is associated with 3 vectors (a day is a struct)
*/

struct day
{
    std::string day;
    std::vector<std::string> breackfast;
    std::vector<std::string> launch;
    std::vector<std::string> dinner;
    void vector_display(std::vector <std::string>);
};

class restaurant
{
private :
    day week_days[7];
public :
    restaurant();
    void add_to_breakfast(std::string,std::string); // specify the date and the meal
    void remove_from_breakfast(std::string,std::string); // we have to handle the exception of the meal not in the menu
    void add_to_launch(std::string,std::string);
    void remove_from_launch(std::string,std::string);
    void add_to_dinner(std::string,std::string);
    void remove_from_dinner(std::string,std::string);

    // display menu
    
    void display(); 
    
};
#endif