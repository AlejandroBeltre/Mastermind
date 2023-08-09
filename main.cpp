/*
    Enunciado: Mastermind.

    Integrantes:

                1115242 - Alejandro Beltre
                1113810 - Henry Alburquerque
                1114331 - Erick Tejada
                1115070 - Sebastian Mateo
                1115279 - Ismael Polanco
                1114531 - Keisy Polanco
                1114343 - David Ramirez
                1109094 - Nelson Colon

    Fecha: 03-08-2023
 */

//Se importan las librerias.
#include <iostream> //Se utiliza para poder manejar los inputs y outputs.
#include <string> //Importa la clase string.
#include <cstdlib> //Proporciona funciones relacionadas para el manejo de la memoria.
#include <ctime> //Proporciona funciones para trabajar con el tiempo y fecha.

using namespace std;

//Crea un arreglo de 4 digitos random para adivinar el numero del 1 al 6.
void generadorRandom(int numeroAdivinar[4]) {

    bool noRepetido; //garantiza que estos digitos no se repitan utilizandolo en un while.
    int numAleatorio;
    /* srand() establece un punto de partida, una "semilla", para que, en base a esta, se calculen los números aleatorios
       time(NULL) retorna el tiempo en segundos que ha pasado desde 1-1-1970 hasta la ejecución de la línea. */
    srand(time(NULL));
    /*este for es para crear los 4 digitos random, y dentro del creamos dos variables de tipo bool e int, además
      de importar la funcion srand par utilizar la hora y fecha de la pc para poder crear los digitos aleatorios.*/
    for(int i = 0; i < 4; i++){
        noRepetido = true;
        while(noRepetido){
            numAleatorio = 1 + rand() % 6;
            /* rand() devuelve un numero pseudo-aleatorio que va desde el 0 hasta RAND_MAX, una constante = 32767
               Se le suma 1 debido a que el rango inferior es 0, y, se divide de forma modular entre 6 para asegurar que
               el numero a generar este dentro del rango [1,6] */
            int contador = 0; //Este contador nos ayudara a que cuando se creen cuatro numeros se rompa el while.
            for(int j = 0; j < 4; j++) { //este for le suma 1 al contador cada vez que se crea un digito que no sea igual al anterior.
                if (numAleatorio != numeroAdivinar[j]) {
                    contador++;
                }
            }
            if(contador == 4){ //este if garantiza que se rompa el while para poder seguir.
                noRepetido = false;
            }
        }
        numeroAdivinar[i] = numAleatorio; //Aqui se le asignan los valores aleatorios al arreglo de 4 espacios.
    }
}


string validarEntrada(){ //Funcion para validar entrada del usuario.
    bool continuar = true;
    string entradaValidada;

    while(continuar) { // este while es para que el usuario pueda seguir introduciendo numeros luego de una entarda erronea.
        cin >> entradaValidada;
        if (entradaValidada.length() == 4) { //Confirma que el usuario no introduzca numeros de más de 4 digitos.
            int contador = 0; //este contador nos ayudara a que cuando se creen cuatro numeros se rompa el while.
            for (int i = 0; i < entradaValidada.length(); ++i) { //Recorre cada posicion de la entrada.
                if(isdigit(entradaValidada[i]) && (entradaValidada[i] - '0') <= 6 && (entradaValidada[i] - '0') != 0){  //Verifica la condificion aplicada.
                    contador++;
                }
            }
            if(contador == 4){ //rompe el bucle si es igual a 4
                continuar = false;
            }
            else{
                cout << "Los cuatros digitos deben de ser numeros entre 1 a 6." << endl;
                cout << "Intentelo de nuevo: " << endl;
            }
        } else {
            cout << "Solo se permiten cuatro digitos." << endl;
            cout << "Intentelo de nuevo: " << endl;
        }
    }
    return entradaValidada;
}
int main() {
    int numeroAdivinar[4] = {0, 0, 0, 0}; //Arreglo de digitos de numero a advinar.
    generadorRandom(numeroAdivinar); //Llamamos a la funcion para generar los digitos del arreglo.
    string numeros; //Los digitos introducidos del usuario.

    cout << "> MasterMind" << endl;

    int fallos = 0; //Almacena los fallos cometidos por el usuario.

    for(int i = 10; i > 0; i--) { //Recorre los intentos del usuario y tiene 10 intentos.
        cout << "-------------------------------" << endl;
        cout << "Introduzca los cuatros numeros: " << endl;
        numeros = validarEntrada(); //LLamamos a la funcion validar entrada para validar la entrada del usuario.
        int aciertos = 0; //Si los aciertos son 4 rompe el bucle
        cout << i << ". ";
        for (int j = 0; j < 4; j++) {
            if (numeros[j] - '0' == numeroAdivinar[j]) { //este if hace que si un digito esta en la posicion correcta, se le sume un acierto y se vuelva a repetir, si no es asi, salta al siguiente.
                /*  Al char correspondiente del string suministrado por el usuario, se le resta el valor ASCII de '0' (48)
               para "convertir" el char en un entero.

               Ejemplo: Digamos que el char es '2', con código ASCII 50. '2' - '0' = 2

               El resultado luego es comparado con el digito correspondiente de la clave a adivinar */
                cout << "C";
                aciertos++;
            }
            else{
                aciertos = 0; //Los aciertos se vuelven 0 para no cargarlos a lo largo de los intentos.
                for(int k = 0; k < 4; k++){ //este for determina si el digito se encuentra dentro o no.
                    if(numeros[j] - '0' == numeroAdivinar[k]) { //este if le asigna una f si el digito esta dentro del arreglo.
                        cout << "F";
                        break;
                    }
                    else{
                        fallos ++;
                    }
                    if (fallos == 4){ // y este si tiene cuatro fallos si no esta dentro del arreglo y rompe el bucle.
                        cout << "X";
                    }
                }
                fallos = 0;
            }
        }
        if(aciertos == 4){ // este if garantiza que si el usuario tiene sus 4 aciertos gana y se le otorga su puntuacion.
            cout << "" << endl;
            cout << "Felicitaciones, usted ha ganado." << endl;
            cout << "Su puntaje es: " << i * 10 << endl;
            break;
        }
        //Si no se cumple el if se le dice cuantos intentos tiene restante al usuario.
        cout << "" << endl;
        cout << "Tiene " << i - 1 << " intentos restantes." << endl;
    }
    return 0;
}