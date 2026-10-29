#include <iostream>
using namespace std;

// Klasse Point und Circle implementieren
class Point{

    double _x;
    double _y;

    public:

    Point(double x = 0, double y = 0){
        _x = x;
        _y = y;

    }

    double get_x() const{ 
    return _x;}

    double get_y() const{ 
    return _y;}

    void set_x(double x){
        _x = x;}

    void set_y(double y){
        _y = y;}

    void move(double dx, double dy){
        _x +=dx;
        _y += dy;
    }

    void print(bool endLine = true) const {
        cout << "(" << _x << ", " << _y << ")";
        if (endLine) {
            cout << endl;
        }
    }


};

class Circle{

    Point _centre;
    double _radius;

    public:

    Circle(Point centre = Point(), double radius = 1){
        _centre = centre;
        _radius = radius;
    }

    Point get_centre() const{ 
    return _centre;}

    double get_radius() const{ 
    return _radius;}

    void set_centre(Point centre){
        _centre = centre;
    }

    void set_radius(double radius){
        _radius = radius;
    }

    void move(double dx, double dy) {
    _centre.move(dx, dy);}

   void print(bool endLine = true) const {
        cout << "[";
     _centre.print(false); // false, damit kein Zeilenumbruch nach dem Punkt kommt
        cout << ", " << _radius << "]";
        if (endLine) {
            cout << endl;
        }
    }


};


// Hauptprogramm
int main(int argc, char *argv[])
{
	Point p;
	Circle c(p);
	cout << "Ausgabe 1:" << endl;
	p.print();
	c.print();
	p.set_x(1.1);
	p.set_y(2.2);
	c.set_centre(p);
	c.set_radius(3.3);
	cout << "Ausgabe 2:" << endl;
	p.print(false);
	cout << " == (" << p.get_x() << ", " << p.get_y() << ")"
		<< endl;
	c.print();
	p.move(1.0, 1.0);
	c.move(2.0, 2.0);
	cout << "Ausgabe 3:" << endl;
	p.print();
	c.print();
	return 0;
}