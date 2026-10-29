#include <string>
#include <iostream>
using namespace std;

//Warum Klassen? -> Kapselung durch private und public
//Code von außen greift nicht direkt aud sas Attribut zu sondern muss get- oder print- Methoden nutzen

//Konstruktoren und Initialisierungliste
//Student: ohne Liste - Erst Initialisierung dann Zuweisung -> Kostet Performance
//Zuweisung im Body, Initialisierung mit ""


//Employee: mit Liste - Variablen direkt mit Parametern initialisiert
//Nicht im Body! Kein "leerer String"

//Warum?
//-> Performance da weniger Schritte
//const Werte können nicht erneut zugewiesenm werden
//Refernzen genauso nur in der Initialisierungsliste möglich

//Konstruktor: Wird dann aufgerufen wenn ein ein Objekt mit der Klasse erstellt wird und füllt Attribute
//hat KEINEN Rückgabewert und heißt exakt wie die Klasse!

//const wirkt hier als read-only für die objekte welche aus den klassen benutzt/gegetted werden

// Klasse Student
class Student{
private:
    //durch include string
    string _name;
    string _firstname;

    public:

    public:
    // Prototypen (Implementierung erfolgt außerhalb)
    Student(string name, string first_name);
    ~Student();
    
    string getName() const;
    string getFirstName() const;
    
    void print() const;
    void print(bool endLine) const;


};

//Methoden von Student außerhalb

//Konstruktor
Student::Student(string name, string firstname) {
    // Keine Initialisierungsliste laut Anforderung
    _name = name;
    _firstname = firstname;
    cout << "Parametrisierter Konstruktor Student: " << _firstname << " " << _name <<  endl;
}

Student::~Student() {
    cout << "Destruktor Student: " << _firstname << " " << _name <<  endl;
}

string Student::getName() const { 
    return _name; 
}

 string Student::getFirstName() const { 
    return _firstname; 
}

void Student::print() const {
     cout << "print() ohne Parameter; Student: " << _firstname << " " << _name <<  endl;
}

void Student::print(bool endLine) const {
     cout << "print() mit Parameter; Student: " << _firstname << " " << _name;
    if (endLine) {
         cout <<  endl;
    }
}


// Klasse Employee

class Employee {
private:
    string _name;
    string _firstname;

public:
    // Parametrisierter Konstruktor mit Initialisierungsliste
    Employee( string name,  string firstname) 
        : _name(name), _firstname(firstname) {
         cout << "Parametrisierter Konstruktor Employee: " << _firstname << " " << _name <<  endl;
    }

    // Standardkonstruktor (delegiert an den parametrisierten Konstruktor via Initialisierungsliste)
    //"dont repeat yourself"
    Employee() : Employee("Mustermann", "Erika") {
         cout << "Standardkonstruktor Employee: " << _firstname << " " << _name <<  endl;
    }

    // Konvertierungskonstruktor (nutzt Initialisierungsliste und get-Methoden von Student)
    //Kann Student Objekt in Employee umwandeln indem get verwendet wird

    //explicit -> kann NUR student into employee und nicht einen employee ercheaten
    //schützt vor ungewollten Konvertierungen weil der konvertierungskonstruktor "richtig handelt"
    Employee(const Student& student) 
        : _name(student.getName()), _firstname(student.getFirstName()) {
         cout << "Konvertierungskonstruktor Employee: " << _firstname << " " << _name <<  endl;
    }

    // Destruktor
    ~Employee() {
         cout << "Destruktor Employee: " << _firstname << " " << _name <<  endl;
    }

    // Print-Methoden innerhalb der Klasse implementiert
    void print() const {
         cout << "print() ohne Parameter; Mitarbeiter: " << _firstname << " " << _name <<  endl;
    }

    void print(bool endLine) const {
         cout << "print() mit Parameter; Mitarbeiter: " << _firstname << " " << _name;
        if (endLine) {
             cout <<  endl;
        }
    }
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
        p_stud_mustermann = new Student("Mustermann", "Markus"); //Heap? -> deswegen außerhalb scope
        p_stud_mustermann->print(true);
    }
    cout << "Block wurde verlassen" << endl;
    delete p_stud_mustermann;
    return 0;
}

