
#include <iostream>
#include "Manager.h"
using namespace std;
/* HIER */

Manager::Manager(const string f_n, const string l_n, double s = 0)
    : Employee(f_n, l_n) 
{
    /* HIER */
    _salary = s;
}
double Manager::get_income() const
{
    /* HIER */
    return _salary;
}
void Manager::print() const
{
    cout << "Manager: ";
    Employee::print();
}