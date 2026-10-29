#include <iostream>
#include <string>
using namespace std;
//statische Variablen:
//gehört zur Klasse, nicht einem Objekt
//geteiltes Attribut!


// Klasse Customer definieren
class Customer{
    //private:
    //static
    static int _s_count; //underscore ist nur Naming convention oder wichtig für den compiler?
    static int _s_id_generator;

    //Membervariablen bzw. Attribut
    string _name;
    string _location;
    int _age;
    double _business_done;
    int _transaction_count;
    int _id;

    public:

    //A)
    //keine initialisierungsliste, da konstruktur nicht nur parameter den attributen zuweist
    Customer(string name = "Unbekannt", int age = 0, string location = "Unbekannt") {
        _name = name;
        _age = age;
        _location = location;

        //infos zu kunden und startwert
        _business_done = 0.0;
        _transaction_count = 0;

        _s_id_generator++;
        _s_count++;
        //id zuweisen, hier direkt mit der Anzahl der kunden gelinked
        _id = _s_id_generator;
    }

    //B)
    ~Customer() {
        _s_count--;
    }


    //C)
    void do_business(double amount) {
        _business_done += amount;      
        _transaction_count++;           
    }

    //D)
    //Gehört zu keinem Objekt via *this 
    static int get_s_count() {
        return _s_count;
    }

    //E)
    void print() const {
        cout << "Kunde " << _name << " aus " << _location << " (ID = " << _id << ", " << _age << " Jahre) hatte " << _transaction_count << " Transaktion(en) und " << _business_done << " Euro Umsatz" << endl;
    }

};

//statische attribute einer klasse werden nicht am anfang initialisiert, also muss speicher manuell gegeben werden
int Customer::_s_count = 0;
int Customer::_s_id_generator {0};

int main(int argc, char *argv[]) {
    Customer peter = Customer("Peter", 17, "Stuttgart");
	Customer simon = Customer("Simon", 23, "Heilbronn");
    peter.~Customer();
	Customer micheal = Customer("Michael", 21, "Karlsruhe");
	Customer claudia = Customer("Claudia", 30, "Nagold");
    std::cout << "Anzahl Kunden: " << Customer::get_s_count() << std::endl;
	simon.do_business(230);
	simon.do_business(400);
	claudia.do_business(1000);
	micheal.do_business(199);
	simon.do_business(3.99);
	simon.print();
	micheal.print();
	claudia.print();
    claudia.~Customer();
    std::cout << "Anzahl Kunden: " << Customer::get_s_count() << std::endl;
	return 0;
}

