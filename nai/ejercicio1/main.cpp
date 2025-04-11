#include <iostream>
#include <sstream>
#include "../LPC/lista.h"

using namespace std;
/*-Wall -Wextra -I../LPC*/
string ruleta(Lista<string> &personas, int k) {
    if (personas.esVacia()) {
        return "";                                                                                                  // Retorna una cadena vacía en lugar de un espacio
    }

    bool sentRelog = true;                                                                                          // Comienza hacia la derecha en el sentido horario
    int pos = 0, pasoAct;

    while (personas.longitud() > 1) {
        pasoAct = (k - 1) % personas.longitud();                                                                    // Corrige el cálculo de la posición a eliminar
        if (!sentRelog) {                                                                                           // Si no se está en sentido horario
            pasoAct = personas.longitud() - pasoAct;                                                                // Decrementa la posición
        }

        pos = (pos + pasoAct) % personas.longitud();                                                                // Se sitúa en la posición seleccionada

        personas.eliminar(pos + 1);                                                                                 // Elimina a la persona (ajustar si la lista es 0-indexada o 1-indexada)

        sentRelog = !sentRelog;                                                                                     // Cambia al sentido contrario

        if (!sentRelog && pos > 0) {                                                                                // Ajusta para ir en sentido contrario
            pos--;
        }
    }

    return personas.consultar(1);                                                                                   // Retorna la última persona restante
}

int main() {
    int n;                                                                                                          // Número de casos de prueba
    cin >> n;

    if (n <= 0) {
        return 0;
    }

    Lista<int> valoresK;                                                                                            // Leer los valores de k para cada caso
    for (int i = 0; i < n; i++) {                                                                                   // Llena los valores k en la lista
        int k;
        cin >> k;
        valoresK.insertar(i + 1, k);
    }

    Lista<Lista<string>*> listasPersonas;                                                                           // Leer los nombres de las personas
    string linea;
    cin.ignore();                                                                                                   // Limpiar el buffer después de leer los números

    while (getline(cin, linea)) {
        istringstream ss(linea);
        string nombre;
        Lista<string>* listaActual = new Lista<string>();

        while (ss >> nombre) {
            listaActual->aggFinal(nombre);
        }

        if (listaActual->longitud() > 0) {
            listasPersonas.aggFinal(listaActual);
        } else {
            delete listaActual;                                                                                         // Elimina la lista si está vacía
        }
    }

    for (int i = 1; i <= n; i++) {                                                                                      // Procesar cada caso de prueba
        int k = valoresK.consultar(i);
        Lista<string> personas;

        for (int j = 1; j <= listasPersonas.longitud(); j++) {                                                          // Construir la lista de personas para este caso
            Lista<string>* listaActual = listasPersonas.consultar(j);
            if (i <= listaActual->longitud()) {
                personas.aggFinal(listaActual->consultar(i));
            }
        }

        personas.hacerCircular();                                                                                       // Hacer circular la lista

        string elegido = ruleta(personas, k);                                                                           // Encontrar al elegido
        cout << elegido << endl;
    }

    for (int i = 1; i <= listasPersonas.longitud(); i++) {
        delete listasPersonas.consultar(i);                                                                             // Liberar memoria
    }

    return 0;
}


