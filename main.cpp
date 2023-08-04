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
#include <cstdlib>

using namespace std;

int main() {
    int numeroAdivinar[4] = {4, 1, 2, 6};
    string numeros;
    int fallos = 0;

    for(int i = 10; i > 0; i--) {
        cout << "-------------------------------" << endl;
        cout << "Introduzca los cuatros numeros: " << endl;
        cin >> numeros;
        int aciertos = 0;
        cout << i << ". ";
        for (int j = 0; j < 4; j++) {
            if (numeros[j] - '0' == numeroAdivinar[j]) {
                cout << "C";
                aciertos++;
            }
            else{
                aciertos = 0;
                for(int k = 0; k < 4; k++){
                    if(numeros[j] - '0' == numeroAdivinar[k]) {
                        cout << "F";
                        break;
                    }
                    else{
                        fallos ++;
                    }
                    if (fallos == 4){
                        cout << "X";
                    }
                }
                fallos = 0;
            }
        }
        if(aciertos == 4){
            cout << "" << endl;
            cout << "Felicitaciones, usted ha ganado." << endl;
            cout << "Su puntaje es: " << i * 10 << endl;
            break;
        }
        cout << "" << endl;
        cout << "Tiene " << i - 1 << " intentos restantes." << endl;
    }
    return 0;
}