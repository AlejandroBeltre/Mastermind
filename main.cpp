/*
    Enunciado: Mastermind.
    Integrantes:
                1115242 - Alejandro Aquiles Beltre Pimentel
                1113810 - Henry Hermes Alburquerque Baez
                1114331 - Erick Tejada
                1115070 - Sebastian Mateo
                1115279 - Ismael Armando Polanco García
    Fecha: 03-08-2023
 */


#include <iostream>
#include <string>

using namespace std;

int main() {
    int numeroAdivinar[4] = {4, 1, 2, 6};
    string numeros;

    for(int i = 10; i > 0; i--) {
        cout << "Introduzca los cuatros numeros: " << endl;
        cin >> numeros;
        for (int j = 0; j < 4; j++) {
            if (numeroAdivinar[j] == isdigit(numeros[j])) {
                cout << "C" << endl;
            }
            else (){
                cout << "F" << endl;
            }
        }
    }
    return 0;
}
