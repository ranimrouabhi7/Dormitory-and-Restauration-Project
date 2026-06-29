#include <iostream>
#include "dorm.h"
#include "restaurant.h"
#include "room.h"
#include "student.h"

using namespace std;

int main()
{
    // ── STUDENTS ─────────────────────────────────────────
    cout << "=== CREATING STUDENTS ===" << endl;
    student s1(101, "Ranim Rouabhi", 2, true);
    student s2(202, "Amina Benkaci", 1, true);
    student s3(303, "Youcef Meziani", 3, false);

    s1.display_info(); cout << "\n\n";
    s2.display_info(); cout << "\n\n";
    s3.display_info(); cout << "\n\n";

    // ── DORMITORY ────────────────────────────────────────
    cout << "=== CREATING DORMITORY ===" << endl;
    dormitory dorm(5, "Residence A", 2);
    cout << "Dorm: " << dorm.get_dorm_name() << endl;
    cout << "Rooms: " << dorm.get_capacity() << endl;
    cout << "Room capacity: " << dorm.get_rooms_capacity() << "\n\n";

    // ── ASSIGN STUDENTS ──────────────────────────────────
    cout << "=== ASSIGNING STUDENTS ===" << endl;
    dorm.add_student(s1, 0);
    dorm.add_student(s2, 1);

    s1.display_info(); cout << "\n\n";
    s2.display_info(); cout << "\n\n";

    // ── REMOVE STUDENT ───────────────────────────────────
    cout << "=== REMOVING STUDENT ===" << endl;
    dorm.remove_student(s1, 0);
    s1.display_info(); cout << "\n\n";

    // ── RESTAURANT ───────────────────────────────────────
    cout << "=== RESTAURANT ===" << endl;
    restaurant resto;
    resto.add_to_breakfast("Monday", "Bread");
    resto.add_to_breakfast("Monday", "Eggs");
    resto.add_to_breakfast("Monday", "Milk");
    resto.add_to_launch("Monday", "Chicken");
    resto.add_to_launch("Monday", "Rice");
    resto.add_to_dinner("Monday", "Soup");
    resto.add_to_dinner("Monday", "Salad");
    resto.add_to_breakfast("Friday", "Crepes");
    resto.add_to_launch("Friday", "Couscous");
    resto.add_to_dinner("Friday", "Yogurt");

    cout << "Menu before removal:" << endl;
    resto.display();

    cout << "\nRemoving Eggs from Monday breakfast...\n";
    resto.remove_from_breakfast("Monday", "Eggs");

    cout << "\nMenu after removal:" << endl;
    resto.display();

    return 0;
}