
#include <string>
#include <iostream>
using namespace std;

//elemente speichern wert und zeiger auf nächsten wert -> verkettete liste 
struct ListElement
{
    int id;
    ListElement* p_next;
};
//frage; warum nicht direct im struct mit dabei? 

//Startpointer für erstes Listenelement

ListElement* p_root = nullptr;

void add_new_head_element(int id)
{
    //reihenfolge wichtig, erst neuen knoten, dann pp_root 
    ListElement* p_new_element = new ListElement();
    p_new_element->id = id;
    p_new_element->p_next = p_root;
    p_root = p_new_element;
}

void add_new_tail_element(int id)
{
    ListElement* p_new_element = new ListElement();

    p_new_element->id = id;
    p_new_element->p_next = nullptr;

    //läuft ans ende der liste wegen nullptr
    if (p_root == nullptr)
    {

        //Auch add_new_head_element nutzbar
        p_root = p_new_element;
    }
    else
    {
        ListElement* p_tmp = p_root;
        while (p_tmp->p_next != nullptr)
        {
            p_tmp = p_tmp->p_next;
        }
        p_tmp->p_next = p_new_element;
    }
}
// "->" operator wegweisungsoperator

void delete_element(int id)
{
    ListElement *p_tmp = p_root;
    ListElement *p_predecessor = nullptr;

    //es wird nach der id gesucht 
    while (p_tmp != nullptr && p_tmp->id != id)
    {
        p_predecessor = p_tmp;
        p_tmp = p_tmp->p_next;
    }
    if (p_tmp != nullptr)
    {
        if (p_tmp == p_root)
        {
            p_root = p_tmp->p_next;
        }
        else
        {
            p_predecessor->p_next = p_tmp->p_next;
        }
    }
    delete p_tmp;
}

void print_list()
{
    // Hier programmieren:
    // Die Liste durchlaufen und jeweils die id des listenElements ausgeben.
    ListElement* p_tmp = p_root;
    //muss man ListElement* machen? was wenn ich jeden mal p_tmp oben initialisier? 
    // läuft durch bis temp beim nullptr ist 
    while (p_tmp != nullptr)
    {
        std::cout << p_tmp->id << std::endl;
        p_tmp = p_tmp->p_next;
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    add_new_tail_element(9);
    add_new_head_element(2);
    add_new_head_element(1);
    add_new_tail_element(10);
    print_list();
    delete_element(2);
    print_list();

    return 0;
};

