#include "restaurant.h"
#include <iostream>

using namespace std;

restaurant::restaurant(day[]){}
    
void restaurant::add_to_breakfast(string DAY, string meal)
{
    for(int i = 0; i < 7; i++)
    {
        if(DAY == week_days[i].day)
        {
            week_days[i].breackfast.push_back(meal);
            return;
        }
    }
}
    
void restaurant::remove_from_breakfast(string DAY, string meal)
{
    for(int i = 0; i < 7; i++)
    {
        if(DAY == week_days[i].day)
        {
            for(int j = 0; j < sizeof(week_days[i].breackfast); j++)
            {
                if(meal == week_days[i].breackfast[j]) week_days[i].breackfast.erase(week_days[i].breackfast.begin() + j);
                return;
            }
        }
    }
    throw ; // meal not in breakfast exception

}
    
void restaurant::add_to_launch(string DAY, string meal)
{
    for(int i = 0; i < 7; i++)
    {
        if(DAY == week_days[i].day)
        {
            week_days[i].launch.push_back(meal);
            return;
        }
    }
}
    
void restaurant::remove_from_launch(string DAY, string meal)
{
    for(int i = 0; i < 7; i++)
    {
        if(DAY == week_days[i].day)
        {
            for(int j = 0; j < sizeof(week_days[i].launch); j++)
            {
                if(meal == week_days[i].launch[j]) week_days[i].launch.erase(week_days[i].launch.begin() + j);
                return;
            }
        }
    }
    throw ;
}
    
void restaurant::add_to_dinner(string DAY, string meal)
{
    for(int i = 0; i < 7; i++)
    {
        if(DAY == week_days[i].day)
        {
            week_days[i].dinner.push_back(meal);
            return;
        }
    }
}
    
void restaurant::remove_from_dinner(string DAY, string meal)
{
    for(int i = 0; i < 7; i++)
    {
        if(DAY == week_days[i].day)
        {
            for(int j = 0; j < sizeof(week_days[i].dinner); j++)
            {
                if(meal == week_days[i].dinner[j]) week_days[i].dinner.erase(week_days[i].dinner.begin() + j);
                return;
            }
        }
    }
    throw ;
}
    
void day::vector_display(vector <string> v)
{
    for(string i : v) cout << i << ' ';
}

void restaurant::display()
{
    
    for(int i = 0; i < 7; i++)
    {
        for(char c : week_days[i].day) cout << toupper(c);
        cout << "menu: " << '\n'
            << "breackfast: " << '\n';
        week_days[i].vector_display(week_days[i].breackfast);
        cout << "launch: " << '\n';
        week_days[i].vector_display(week_days[i].launch);
        cout << "dinner: " << '\n';
        week_days[i].vector_display(week_days[i].dinner);
    }
}