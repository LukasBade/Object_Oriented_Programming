#include<iostream>
using namespace std;

class Date {
	
	int _day, _month, _year;

public:
	Date(int day = 0, int month = 0, int year = 0)
        :_day(day), _month(month), _year(year) {} //Liste

	Date operator+(int count) const {
        // Datum in absolute Tage umrechnen (-1, da bei 1 basierend gestartet wird)
        int total_days = (_year - 1) * 360 + (_month - 1) * 30 + (_day - 1) + count;
        
        // Wieder zurückrechnen in Jahr, Monat und Tag
        int y = total_days / 360;
        int rem = total_days % 360;
        int m = rem / 30;
        int d = rem % 30;
        
        return Date(d + 1, m + 1, y + 1);
    }
    
    // Ausgabeoperator für cout
    friend ostream & operator<<(ostream & os, const Date & dt) {
        os << dt._day << "." << dt._month << "." << dt._year;
        return os;
    }
};



int main(int argc, char *argv[])
{
    Date begin_task = Date(26,10,2023);
    cout << "Die Aufgabe beginnt am " << begin_task << endl;
    Date end_task = begin_task + 6;
    cout << "Die Aufgabe endet am " << end_task << endl;
    Date one_year_and_one_month_later = begin_task + 390;
    cout << "Ein Jahr und ein Monat nach Aufgabenbeginn ist der " << one_year_and_one_month_later << endl;
    Date three_years_and_eleven_months_later = begin_task + 1410;
    cout << "Drei Jahre und 11 Monate nach Aufgabenbeginn ist der " << three_years_and_eleven_months_later << endl;
}

