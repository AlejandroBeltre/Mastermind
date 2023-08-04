/*
    Enunciado: Mastermind.

    Integrantes:
                1115242 - Alejandro Beltre
                1113810 - Henry Alburquerque
                1114331 - Erick Tejada
                1115070 - Sebastian Mateo
                1115279 - Ismael Polanco
                - Keisy Polanco
                1114343 - David Ramirez

    Fecha: 03-08-2023
 */


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void generadorRandom(int numeroAdivinar[4]) {

    for(int i = 0; i < 4; i++){
        bool noRepetido = true;
        int numAleatorio;
        srand(time(NULL));
        while(noRepetido){
            numAleatorio = 1 + rand() % 6;
            int contador = 0;
            for(int j = 0; j < 4; j++) {
                if (numAleatorio != numeroAdivinar[j]) {
                    contador++;
                }
            }
            if(contador == 4){
                noRepetido = false;
            }
        }
        numeroAdivinar[i] = numAleatorio;
    }
}

string validarEntrada(){
    bool continuar = true;
    string entradaValidada;

    while(continuar) {
        cin >> entradaValidada;
        if (entradaValidada.length() == 4) {
            int contador = 0;
            for (int i = 0; i < entradaValidada.length(); ++i) {
                if(isdigit(entradaValidada[i])){
                    contador++;
                }
            }
            if(contador == 4){
                continuar = false;
            }
            else{
                cout << "Los cuatros digitos deben de ser numeros." << endl;
            }
        } else {
            cout << "Solo se permiten cuatro digitos." << endl;
        }
    }
    return entradaValidada;
}
int main() {
    int numeroAdivinar[4] = {0, 0, 0, 0};
    generadorRandom(numeroAdivinar);
    string numeros;
    int fallos = 0;


    for(int i = 10; i > 0; i--) {
        cout << "-------------------------------" << endl;
        cout << "Introduzca los cuatros numeros: " << endl;
        numeros = validarEntrada();
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