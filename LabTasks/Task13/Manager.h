
/* HIER */
#pragma once
#include <string>
#include "Employee.h"
using namespace std;

class Manager: public Employee /* HIER */
{
    double _salary;

public:
    Manager(const string, const string, double);
    double get_income() const;
    void print() const;
};