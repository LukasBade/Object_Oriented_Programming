#include <string>
#include <iostream>
using namespace std;

//Bauplan für Objekte "Klasse"


// Klasse Student
class Student{
private:
    //durch include string
    string _name;
    string _firstname;

    public:


};

//Methoden von Student außerhalb

// Klasse Employee

class Employee {
private:
    string _name;
    string _first_name;

    public:
    



};


int main(int argc, char *argv[])
{
    Student stud_mustermann = Student("Mustermann", "Max");
    Employee empl_mustermann = Employee(stud_mustermann);
    Employee mit_default = Employee();
    stud_mustermann.print();
    stud_mustermann.print(true);
    empl_mustermann.print();
    mit_default.print();
    Student *p_stud_mustermann = nullptr;
    cout << "Block wird betreten" << endl;
    {
        p_stud_mustermann = new Student("Mustermann", "Markus");
        p_stud_mustermann->print(true);
    }
    cout << "Block wurde verlassen" << endl;
    delete p_stud_mustermann;
    return 0;
}

