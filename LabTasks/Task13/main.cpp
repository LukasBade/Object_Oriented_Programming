#include <iostream>
#include "Manager.h"
#include "Worker.h"
using namespace std;

/* HIER */

int main()
{
    Manager m("Max", "Mustermann", 1000.00); 
    m.print();
    cout << "Gehalt: " << m.get_income() << endl << endl;
    Worker w("Lukas", "Bade", 15.00, 40);
    w.print();
    cout << "Lohn: " << w.get_income() << endl;
    return 0;
}