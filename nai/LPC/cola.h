#ifndef COLA_H
#define COLA_H
#include "nodo.h"
#include<iostream>
using namespace std;


/*-------------------------------definicion de la clase cola-----------------------------------*/

template <typename Elemento>
class Cola{
    private:
        int tam;
        Nodo<Elemento> *primero, *ultimo;
    public:
        Cola();                                                         //constructor por defecto
        Cola(const Cola<Elemento> &cola);                               //constructor copia
        void copiar(const Cola<Elemento> &cola);                        //realiza la copia
        int buscar(Elemento dato);                                      //busco un Elemento en particular
        Elemento frente();                                              //obtengo el frente de la cola
        Elemento cola();                                                //obtengo el ultimo de la cola
        int longitud();                                                 //longitud de la cola
        bool esVacia();                                                 //verifica si cola es vacia
        void encolar(Elemento dato);                                    //encola un Elemento 
        ~Cola();                                                        //destructor por defecto
        void destruir();                                                //destruye la cola 
        void desencolar();                                              //desencolar
        void limpiar();                                                 //borra los Elementos de la cola 
        void invertir();                                                //invierte la cola  (m o d i f i c a r)
        void concatenar(Cola<Elemento> &cola);                          //une dos cola (une una cola a la cola instanciada)
        void mostrar();                                                 //impeime la cola
};



/*-------------------------------implementacion de sus metodos-----------------------------------*/


// Constructor por defecto
template <typename Elemento>
Cola<Elemento>::Cola(){
    this->tam = 0;
    this->primero = nullptr;
    this->ultimo = nullptr;
}


// Constructor copia m o d i f i c a r
template <typename Elemento>
Cola<Elemento>::Cola(const Cola<Elemento> &cola){
    copiar();
}
   


/*genera la copia nodo a nodo*/
template <typename Elemento>
void Cola<Elemento>::copiar(const Cola<Elemento> &cola){
    
    if(cola.tam != 0){
        limpiar();  

        Nodo<Elemento> *nActual = cola.primero;
        Nodo<Elemento> *nNuevo = new Nodo<Elemento>(nActual->obtInfo());        //crea un nuevo  nodo en la memoria dinamica y lo inicializa con el valor que tiene nActual     

        this->primero = nNuevo;
        Nodo<Elemento> *nAux = nNuevo;

        nActual = nActual->obtSiguiente();                                      // Avanzar al siguiente nodo de la cola original
        //desencolar();
        while (nActual != nullptr) {
            nNuevo = new Nodo<Elemento>(nActual->obtInfo());                    // Crear un nuevo nodo
            nAux->modSiguiente(nNuevo);                                         // Enlazar el nuevo nodo al final de la nueva cola
            nAux = nNuevo;                                                      // Mover nAux al nuevo nodo
            nActual = nActual->obtSiguiente();                                  // Avanzar al siguiente nodo de la cola original
        }
        this->ultimo = nAux;
        this->tam = cola.tam;
        return;
    }
   
    cout<<"[Warning] no se puede copiar una cola vacia "<<endl;

}





/*busca la posicion de un  Elemento (dato)*/
template <typename Elemento>
int Cola<Elemento>::buscar(Elemento dato){
    int  contador = 1;
    Nodo<Elemento> *nActual = this->primero;

    while(nActual != nullptr){
        if(nActual->obtInfo() == dato){
            return (contador);
        }
        contador++;         
        nActual = nActual->obtSiguiente();
        
    }
    //cout<<" Elemento no encontrado "<<endl;

}
    


 
/*Método para obtener el frente de la cola sii la cola no es vacia*/
template <typename Elemento>
Elemento Cola<Elemento>::frente(){
    
    if (!esVacia()) {
        return (this->primero->obtInfo());
    }

}


/* Método para obtener el último de la cola*/
template <typename Elemento>
Elemento Cola<Elemento>::cola(){
    
    if (this->tam != 0) {
        return this->ultimo->obtInfo();
    }
   
}

/* Método para obtener la longitud de la cola*/
template <typename Elemento>
int Cola<Elemento>::longitud() {
    return (this->tam);
}


/* Método para verificar si la cola está vacía*/
template <typename Elemento>
bool Cola<Elemento>::esVacia() {
    return (this->tam == 0);
}


/* Método para encolar un Elemento */
template <typename Elemento>
void Cola<Elemento>::encolar(Elemento dato) {
    Nodo<Elemento> *nNuevo = new Nodo<Elemento>(dato);

    if(this->tam == 0){
        this->primero = nNuevo;
    } else {
        Nodo<Elemento> *nAux = this->ultimo;
        nAux->modSiguiente(nNuevo);   
    }
    this->ultimo = nNuevo;
    this->tam++;
}




/* Destructor por defecto */
template <typename Elemento>
Cola<Elemento>::~Cola(){
    destruir();
}




/* Método para destruir la cola (por el frente)*/
template <typename Elemento>
void Cola<Elemento>::destruir(){
    
    while(!esVacia()){
        desencolar();
    }

    
}




/* Método para desencolar */ 
template <typename Elemento>
void Cola<Elemento>::desencolar() {
 
    if(this->tam != 0){
        Nodo<Elemento> *nActual = this->primero;
        this->primero = nActual->obtSiguiente();
        delete nActual;
        this->tam--;
        return;
    }
    cout<<"[ERROR] cola vacia, no se puede desencolar "<<endl;                        //se muestra si llamo a X metodo si le quito el comentado :) 
    
}


/* Método para limpiar la cola*/
template <typename Elemento>
void Cola<Elemento>::limpiar(){
    destruir();
    this->tam = 0;
    this->primero = nullptr;
    this->ultimo = nullptr;
}



/* Método para invertir la cola sii esta llena*/
template <typename Elemento>
void Cola<Elemento>::invertir() {

    if(!esVacia()){
        Cola<Elemento> *nAux = this->primero;
        this->primero = this->ultimo;
        this->ultimo = nAux;
        return;
    }
    //cout<<"[WARNING] asegurate que la cola tenga Elementos para invertir"<<endl;
    
}



/*  Método para concatenar una cola a la cola instanciada  */ //mejorar
template <typename Elemento>
void Cola<Elemento>::concatenar(Cola<Elemento> &cola) {
    
    if(cola.tam != 0){
        Nodo<Elemento> *nActual = this->ultimo;
        nActual->modSiguiente(cola.primero);
        this->ultimo = cola.ultimo;
        this->tam += cola.tam;
        return;
    }
    cout<<"[WARNING] asegurate que la cola tenga Elementos para concatenar"<<endl;
}


/*la cola debe ser diferente de vacio*/
template <typename Elemento> 
void Cola<Elemento>::mostrar(){

    if(this->esVacia()){
        cout<<"La Cola esta vacia. "<<endl;
        
    }else{
        Nodo<Elemento> *nNodo = this->primero;
        while(nNodo != nullptr){
            cout<<nNodo->obtInfo()<<" -> ";
            nNodo = nNodo->obtSiguiente();
        }

    }
}


#endif //COLA_H