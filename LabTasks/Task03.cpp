#include <iostream>

// Funktion mit einem Default-Parameter für die Breite
//width 0 als default wert falls kein zwetier parameter übvergeben wiord
//-1 als defautl wert möglich um failsave falls width = height nicht funktiuoniert
//Negativ Wert geschickter
void print_rectangle(int height, int width = 0) {
    // Wenn kein zweiter Parameter übergeben wurde, ist es ein Quadrat
    if (width == 0) {
        width = height;
    }

    // Äußere Schleife für die Zeilen (Höhe)
    for (int i = 0; i < width; ++i) {
        // Innere Schleife für die Spalten (Breite)
        for (int j = 0; j < height; ++j) {
            std::cout << "X ";
        }
        std::cout << "\n"; // Zeilenumbruch nach jeder Reihe
    }
}

int main(int argc, char *argv[])
{
	std::cout << "x = 2, y = 5: " << std::endl;
	print_rectangle(2, 5);

    std::cout << std::endl;
	std::cout << "x = 3, y = 3: " << std::endl;
	print_rectangle(3, 3);

    std::cout << std::endl;
	std::cout << "x = 4: " << std::endl;
	print_rectangle(4);

	return 0;
};