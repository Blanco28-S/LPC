/*-----------PRUEBAS ----------*/

/*#include <iostream>
#include "nodo.h" // Asegúrate de incluir tu archivo de cabecera
using namespace std;

int main() {
    
  // Crear un nodo con un dato entero
    Nodo<char> nodo1('a');
    
    // Verificar que el dato se haya almacenado correctamente
    cout << "Dato en nodo1: " << nodo1.obtInfo() <<endl;

    // Crear otro nodo
    Nodo<char> nodo2('e');
    
    // Modificar el siguiente nodo de nodo1 para que apunte a nodo2
    nodo1.modSiguiente(&nodo2);
    
    // Verificar que el siguiente nodo de nodo1 es nodo2
    if (nodo1.obtSiguiente() != NULL) {
      cout << "Dato en el siguiente nodo de nodo1: " << nodo1.obtSiguiente()->obtInfo() <<endl;
    }else {
      cout << "nodo1 no tiene siguiente nodo." <<endl;
    }

    // Modificar el dato en nodo1
    nodo1.modInfo('i');
    cout << "Nuevo dato en nodo1: " << nodo1.obtInfo() <<endl;

    // Verificar que el siguiente nodo de nodo2 es nulo
    if (nodo2.obtSiguiente() == nullptr) {
      cout << "nodo2 no tiene siguiente nodo." <<endl;
    }
 
    
  return 0;
}
*/
/*
#include <iostream>
#include <string>
#include "lista.h" // Asegúrate de que la ruta sea correcta

using namespace std;

int main(void) {
    // Crear una lista de enteros
    Lista<int> lista;

    cout<<"entro aqui "<<endl;
    // Insertar elementos en la lista
    cout << "Insertando elementos en la lista..." << endl;
    lista.insertar(1, 2); // Asegúrate de que la posición sea válida
    lista.insertar(2, 5);
    lista.insertar(3, 7);
    lista.insertar(4, 7);
    lista.insertar(5, 9);
    lista.insertar(6, 6);
    lista.insertar(7, 3);
    lista.insertar(8, 200);

    cout<<"entro aqui "<<endl;
    // Mostrar la lista
    cout << "Elementos de la lista 1 sin ordenar:" << endl;
    lista.mostrar();
    cout<<endl;

    cout<<"entro aqui "<<endl;
    // Mostrar la lista
    cout << "Elementos de la lista 1 ordenado:" << endl;
    lista.ordenar();
    lista.mostrar();
    cout<<endl;

    /*cout<<"entro aqui "<<endl;
    lista.destruir();
    cout << "lista 1 destruida.... :)" << endl;
    if(lista.esVacia()){
      cout<<"Lista vacia"<<endl;
    }else{
      cout<<"Lista no vacia"<<endl;
    }*/


    /**
    cout<<"entro aqui "<<endl;
    // Consultar un elemento
    cout << "Elemento en la posicion 3: " << lista.consultar(3) << endl; // Verifica que la posición sea válida
    
    
    cout<<"entro aqui "<<endl;
    // Modificar un elemento
    cout << "Modificando el elemento en la posición 2 a 87..." << endl;
    lista.modificar(2, 87);
    lista.mostrar();
    cout<<endl;


    cout<<"entro aqui "<<endl;
    cout<<"eliminar  la posicion 1 "<<endl;
    lista.eliminar(1);
    lista.mostrar();

    cout<<endl;
    cout<<"entro aqui "<<endl;
    cout<<"la longitud de la lista es: "<<lista.longitud()<<endl;
    
    cout<<"entro aqui "<<endl;
    cout<<"eliminar  la posicion 3"<<endl;
    lista.eliminar(3);
    lista.mostrar();

    <<endl;
    cout<<"entro aqui "<<endl;
    cout<<"la longitud de la lista es: "<<lista.longitud()<<endl;


    cout<<"entro aqui "<<endl;
    cout<<"eliminar  la posicion:"<<lista.longitud()<<endl;
    lista.eliminar(lista.longitud());
    lista.mostrar();


    cout<<"entro aqui "<<endl;
    // Consultar un elemento
    cout << "Elemento en la posicion 1: " << lista.consultar(1) << endl; // Verifica que la posición sea válida
    
    cout<<"entro aqui "<<endl;
    // Consultar un elemento
    cout << "Elemento en ultima posicion: " << lista.consultar(lista.longitud()) << endl; // Verifica que la posición sea válida
    
    cout<<"entro aqui "<<endl;
    // Modificar un elemento
    cout << "Modificando el elemento en la posición 1 a 433..." << endl;
    lista.modificar(1, 433);
    lista.mostrar();
    cout<<endl;


    cout<<"entro aqui "<<endl;
    // Modificar un elemento
    cout << "Modificando el elemento en la posición " <<lista.longitud()<<" a 334..."<< endl;
    lista.modificar(lista.longitud(), 334);
    lista.mostrar();
    cout<<endl;


    cout<<"entro aqui "<<endl;    
    if(lista.esVacia()){
      cout<<"lista vacia"<<endl;
    }else{
      cout<<"lista no vacia"<<endl;
    }

    
    cout<<"entro aqui "<<endl;    
    cout<<"buscar el elemento 5  "<<endl;  
    if(lista.estaElemento(5)){
      cout<<"Esta en la posicion "<<lista.buscar(5);
    }else{
      cout<<"La lista no  contiene el elemento";
    }


    cout<<"entro aqui "<<endl;    
    cout<<"cadena invertida"<<endl;  
    cout<<"entro aqui "<<endl;   
    lista.invertir();
    lista.mostrar();

    cout<<"entro aqui "<<endl;    
    cout<<"concatenar listas"<<endl;  
    cout<<"entro aqui "<<endl;   */
    
    //Lista<int> lista2;
    /*cout<<"lista 2 es vacia?"<<endl;
    if(lista2.esVacia()){
      cout<<"Lista vacia"<<endl;
    }else{
      cout<<"Lista no vacia"<<endl;
    }
    cout<<"entro aqui "<<endl;
    lista2.copiar(lista);*/
    

    // Insertar elementos en la lista
    /*cout << "Insertando elementos en la lista 2..." << endl;
    lista2.insertar(1, 2); // Asegúrate de que la posición sea válida
    lista2.insertar(2, 5);
    lista2.insertar(3, 7);
    lista2.insertar(4, 7);
    lista2.insertar(5, 6);
    


    cout<<"entro aqui "<<endl;
    // Mostrar la lista
    cout << "Elementos de la lista 2:" << endl;
    lista2.mostrar();
    cout<<endl;
    lista2.insertar(lista2.longitud()+1, 200);
    lista2.mostrar();
    cout<<endl;

    
    cout<<"entro aqui "<<endl;
    cout<<"verificamos si la lista 1 es sublista de la lista 2.... "<<endl;
    if(lista.sublista(lista2)){
      cout<<"Si es sublista"<<endl;
    }else{
      cout<<"No es sublista"<<endl;
    }


    /*cout<<"entro aqui "<<endl;
    lista2.destruir();
    cout << "lista 2 destruida.... :)" << endl;
    if(lista2.esVacia()){
      cout<<"Lista vacia"<<endl;
    }else{
      cout<<"Lista no vacia"<<endl;
    }*/


    
    /*cout<<"entro aqui "<<endl;
    // Mostrar la lista
    cout << "Union de la lista 1 y la lista 2:" << endl;
    lista.concatenar(lista2);
    cout << "longitud de la lista nueva formada de la union:" <<lista.longitud()<< endl;
    cout << "Union de las listas" << endl;
    lista.mostrar();
    cout<<endl;*/

    /*cout << "Ver si las dos listas son iguales" << endl;
    cout<<"entro aqui "<<endl;


    bool esIgual = false;
    esIgual = lista.igualar(lista,lista2);
    if(esIgual){
      cout<<"Ambas listas son iguales"<<endl;
    }else{
      cout<<"Ambas listas son diferentes"<<endl;
    }

    return 0;
}
*/

#include<iostream>

#include "./LPC/cola.h"

using namespace std;

void probarCola(){
  Cola<int> cola1;
  Cola<int> cola2;

  cola1.encolar(45);
  cola1.encolar(46);
  cola1.encolar(47);
  cola1.encolar(48);
  cola1.encolar(49);
  cola1.encolar(50);

  cout<<"\n";

  cola2.encolar(11);
  cola2.encolar(22);
  cola2.encolar(33);

 /* cout << "Lista de strings antes de ordenar: ";
  listaCadena.mostrar();

  cout<<"\n";

  listaCadena.ordenar();
  cout << "Lista de strings después de ordenar: ";
  listaCadena.mostrar();

  cout<<"\n";*/
  cout << "cola 1: "<<endl;
  cola1.mostrar();

  cout<<"\n";
  cout << "cola 2: "<<endl;
  cola2.mostrar();

  cout<<"\n";

  cout<<"longitud de la cola 1: "<<cola1.longitud()<<endl;
  cout<<"longitud de la cola 2: "<<cola2.longitud()<<endl;

  //cola2.limpiar();
  /*
  if(cola2.esVacia()){
    cout<<"cola vacia"<<endl;
  }else{
    cout<<"cola llena"<<endl;
  }
  cout<<"\n";
  cout<<"  "<<cola1.buscar(47);*/
  
  cola1.encolar(0);
  cout<<"\n";
  cola1.mostrar();
  cout<<"\n";
  //cout<<"el ultimo en la cola es:  "<<cola1.cola()<<endl;
  //cout<<"el primero de la cola es:  "<<cola1.frente()<<endl;
  cola1.desencolar();
  cout<<"\n";
  cola1.mostrar();
  cola1.destruir();
  cout<<"\n";
  if(cola1.esVacia()){
    cout<<"cola vacia"<<endl;
  }else{
    cout<<"cola llena"<<endl;
  }
  Cola<int> cola3;
  cola3.encolar(5);
  cola3.encolar(6);
  cola3.encolar(7);
  cola3.encolar(4);
  cola3.encolar(4);
  cola3.encolar(0);


  cola2.mostrar();
  cout<<"\n";
  cola3.mostrar();
  cout<<"\n";
  //cola2.copiar(cola3);
  //cout<<"\n";
  cout<<"concatenar cola 2 y cola 3"<<endl;
  cola2.concatenar(cola3);
  cola2.mostrar();
  cout<<"\n";
  cout<<"posicion del elemento buscado: "<<cola2.buscar(4)<<endl;;
  
}


int main(void){
  probarCola();
}



/*#include<iostream>
#include "pila.h"
using namespace std;

void pruebasPila(){
  Pila<int> pila1;
  Pila<int> pila2;

  cout<<"entro en apilar"<<endl;
  pila1.apilar(4);
  pila1.apilar(9);
  pila1.apilar(48);
  pila1.apilar(0);
  cout<<"entro en, ya apilo"<<endl;

  pila1.mostrar();

  if(pila1.esVacia()){
    cout<<"pila vacia"<<endl;
  }else{
    cout<<"pila no vacia"<<endl;
  }

  cout<<"entro en aqui"<<endl;

  cout<<"el tope de la pila es: "<<pila1.topePila()<<endl;

  pila1.desapilar();
  pila1.mostrar();

  cout<<"el tope de la pila es: "<<pila1.topePila()<<endl;

  pila2.copiar(pila1);
  pila2.mostrar();

  pila2.modTope(100);
  pila2.mostrar();

  pila1.concatenar(pila2);
  pila1.mostrar();*/
/*
  cout<<"la longitud de la concatenacion de ambas pilas es: "<<pila1.longitud()<<endl;
  cout<<"pila invertida"<<endl;
  pila1.invertir();
  pila1.mostrar();*/

/* pila1.destruir();
  if(pila1.esVacia()){
    cout<<"se destruyo :()"<<endl;
  }else{
    cout<<"fuck :)"<<endl;
  }

}
  



int main(void){
  pruebasPila();

  return 0;
}*/

  
