#include<iostream>
using namespace std;

// Hier die Klasse Point implementieren
class Point {
private:
    double x;
    double y;

public:
    // Setter-Methoden
    void set_x(double new_x) {
        x = new_x;
    }

    void set_y(double new_y) {
        y = new_y;
    }

    // Getter-Methoden
    double get_x() const {
        return x;
    }

    double get_y() const {
        return y;
    }

    // Print-Methode
    void print() const {
        cout << "print-Methode:" << endl;
        cout << "X = " << x << endl;
        cout << "Y = " << y << endl;
    }
};

int main(int argc, char* argv[]) {
    Point p;
    p.set_x(1);
    p.set_y(10.5);
    p.print();
    p.set_x(5);
    cout << "X ohne print(): " << p.get_x() << endl;
    cout << "Y ohne print(): " << p.get_y() << endl;
    return 0;
}
