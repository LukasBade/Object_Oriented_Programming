#include <string>
#include <ctime>
#include <iostream>

using namespace std;


//ToDo: Namespaces aufräumen und vor Abnahme anpassen, bessere Schleifen auswählen


// Aufzählungstyp für wählbare Objekte
// STEIN - 0, SCHERE - 1, PAPIER - 2
enum class Object
{
    ROCK,
    SCISSORS,
    PAPER
};

// Aufzählungstyp für mögliche Spielausgänge
enum class Result
{
    PLAYER_ONE_WINS,
    PLAYER_TWO_WINS,
    DRAW
};

// Struktur für einen Spieler bestehend aus Name und Wahl des Spielers
struct Player
{
    string name;
    Object choice;
};

// Name des Spielers eingeben
// HIER programmieren:
    // Den Namen des Spielers von der Konsole einlesen und zurückgeben
    // Tip: für das Einlesen eines Strings gibt es eine bestimmte Funktion, siehe auch Vorlesung Folie "Eine Zeile als String einlesen"
string insert_name()
{
    //Aus der Foliensammlung, Liest eine Zeile *ganz* als String ein
    cout << "Name des Spielers: " ;
    string sName;
    getline(cin, sName);
    return sName;
}


Object determine_choice(string choice)
{
    if (choice.compare("CoderunnerTestValueROCK") == 0)
    {
        return Object::ROCK;
    }
    else if (choice.compare("CoderunnerTestValueSCISSORS") == 0)
    {
        return Object::SCISSORS;
    }
    else if (choice.compare("CoderunnerTestValuePAPER") == 0)
    {
        return Object::PAPER;
    }
    else
    {
        // Den Computer zufällig waehlen lassen.

        // HIER beantworten Sie folgende Fragen:
        // Was bewirkt die funktion srand?
        // Die Fuktion srand ist im Ganzen der Zufallsgenerator.

        // Warum wird hier die Zeit (time) als Eingabe für die Funktion srand verwendet?
        // Die Zeit ist ein nicht fixer Wert welcher "immer" anders ist. 

        // Wie funktioniert die funktion rand?
        // Es erzeugt einen Nullpointer auf einen zufälligen Wert durch die Zeit und Modulo 3. Diesert Wert wird als Objekt geschrieben.
        
        // Warum wird hier modulo 3 verwendet?
        // 3 "Ergebnisse" als bruachen wir Modulo 3 für Rest 0, 1 und 2.

        srand(static_cast<int>(time(nullptr)));
        int choice = rand() % 3;
        return static_cast<Object>(choice);
    }
}

// Die Wahl von Stein etc. als String zurückgeben lassen
string get_name(Object object)
{

    // HIER programmieren:
    // Abhängig vom vorliegenden Objekt einen entsprechenden String zurückgeben.
    // z.B: Wenn object dem Wert Object::ROCK entspricht, dann String "Stein" zurückgeben

    //Idee: Switch Case mit den einzelnen Objekten als sofortige Rückgabewert
    switch (object)
    {
        case Object::ROCK:
            return "Stein";
        case Object::SCISSORS:
            return "Schere";
        case Object::PAPER:
            return "Papier";
    }

    return "Invalide Auswahl"; //An sich doppelt gemoppelt durch den switch case und die do while schleife welche bei falscher eingabe weiter fragt, aber nötig um eine fehlermeldung zu vermeiden

}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void print_choice(Player player)
{

    // HIER programmieren:
    // Auf der Konsole ausgeben, für welches Objekt sich der Spieler entschieden hat.
    // z.B.: "Computer hat das Objekt Schere gewählt"
    // TIP: Nutzen sie hierzu die Funktion get_name

    //get_name gibt name des objektes zurück, beides kommt aus der struct
    cout << player.name << " hat das Objekt " << get_name(player.choice) << " gewählt" << endl;

}

// Die Wahl des Spielers abfragen
Object choose()
{

    // HIER programmieren:
    // Die Wahl des Spielers von der Konsole einlesen und zurückgeben
    // Stellen sie sicher, dass es sich um eine gültige Wahl handelt!
    // TIP: Nutzen Sie dazu eine geeignete Schleife. Siehe auch Vorlesung Folie "Annehmende Schleifenanweisungen – Do"

    //do while da man auf eine richtige eingabe wartet btw iteriert

    int input; //Input variable gültigkeit in der schleife 

    do
    {
        cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier): ";
        
        if (cin >> input) 
        {
            // Bereich 1-3
            if (input >= 1 && input <= 3) 
            {
                // Struct - 1 
                return static_cast<Object>(input - 1);
            }
        }


    } while (true);
}


Result determine_result(Player player_1, Player player_2)
{

    // HIER programmieren:
    // Vergleichen Sie die gewählten Objekte, ermitteln sie das Spielergebnis und geben sie es zurück.
    // TIP: Wenn Sie für den Vergleich mit ganzene Zahlen _rechnen_ wollen, dann nutzen sie den static_cast, siehe auch Vorlesung Folie "Casts in C++: Static_cast"

    //Stein 0, Scheere 1, Papier 2
    //Lösung mit static cast bzw numbers
    int choice_1 = static_cast<int>(player_1.choice);
    int choice_2 = static_cast<int>(player_2.choice);

    if (choice_1 == choice_2)
    {
        return Result::DRAW;
    }
    else if ((choice_1 == 0 && choice_2 == 1) || (choice_1 == 1 && choice_2 == 2) || (choice_1 == 2 && choice_2 == 0))
    {
        return Result::PLAYER_ONE_WINS;
    }
    else
    {
        return Result::PLAYER_TWO_WINS;
    }


    //Frage; Lösung nicht besser ohne Berechnunge durch kleinen Vergleich der Inpute direkt mit if else und || statements?
}

void print_result(Player player_1, Player player_2)
{

    // HIER programmieren:
    // Ermitteln Sie zunächst das Spielergebnis. Nutzen sie dazu die Funktion determine_result.
    // Geben Sie anschließend auf der Konsole aus, wer gewonnen hat.
    // z.B: "Spieler Computer hat gewonnen" oder "Unentschieden"

    // print result via cout -> viele möglichkeiten = switch case oder else if - was ist truly besser in c++?
    Result result = determine_result(player_1, player_2);
    switch (result)
    {
    case Result::DRAW:
        cout << "Unentschieden" << endl;
        break;
    case Result::PLAYER_ONE_WINS:
        cout << "Spieler " << player_1.name << " hat gewonnen." << endl;
        break;
    case Result::PLAYER_TWO_WINS:
        cout << "Spieler " << player_2.name << " hat gewonnen." << endl;
        break;
    }

}

int main(int argc, char *argv[])
{
    Player player_1, player_2;
    player_1.name = "Computer";
    player_2.name = insert_name();
    player_1.choice = determine_choice(player_2.name);
    cout << "Der Computer hat seine Wahl getroffen." << endl;
    player_2.choice = choose();
    print_choice(player_1);
    print_choice(player_2);
    print_result(player_1, player_2);

    return 0;
}

