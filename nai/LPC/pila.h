#ifndef PILA_H
#define PILA_H
#include "nodo.h"
#include<iostream>
using namespace std;


/*-------------------------------definicion de la clase pila-----------------------------------*/

template <typename Elemento>
class Pila{
    private:
        int tam;
        Nodo<Elemento> *tope;
    public:
        Pila();                                                         //constructor por defecto
        Pila(const Pila<Elemento> &pila);                               //constructor copia
        void copiar(const Pila<Elemento> &pila);                        //copia()
        Elemento topePila();                                            //obtiene el tope (elemento)
        int longitud();                                                 //longitud de la pila
        bool esVacia();                                                 //verifica si pila es vacia
        void apilar(Elemento dato);                                     //apila un elemento 
        void desapilar();                                               //desapila el nodo
        void modTope(Elemento dato);                                    //reescribe el tope
        ~Pila();                                                        //destructor por defecto
        void destruir();                                                //destruye la pila 
        //void invertir();           m o d i f i c a r                  //invierte la pila
        void concatenar(Pila<Elemento> &pila);                          // concatena una pila extra a la pila instanciada
        void mostrar();                                                 // imprime la pila insertada
};


/*----------------------------------implementacion de sus metodos----------------------------------*/


/*constructor por defecto*/
template<typename Elemento>
Pila<Elemento>::Pila(){

    this->tam = 0;
    this->tope = nullptr;
}


/* metodo que copia una pila */
template<typename Elemento>
Pila<Elemento>::Pila(const Pila<Elemento> &pila){

    copiar(pila);
}


/*metodo copiar, en realidar hace copia de cada tope*/
template<typename Elemento>
void Pila<Elemento>::copiar(const Pila<Elemento> &pila){

    if(pila.tam == 0){
        this->tam = 0;
        this->tope = nullptr;
        return;
    }

    Pila<Elemento> pilaAux;
    Nodo<Elemento> *nActual = pila.tope;

    while(nActual != nullptr){
        pilaAux.apilar(nActual->obtInfo());
        nActual = nActual->obtSiguiente();
    }

    while( !pilaAux.esVacia()){                
        this->apilar(pilaAux.topePila());                                   //apilamos en la pila actual
        pilaAux.desapilar();
    }

    this->tam = pila.tam;
}


/*adquiere el elemento tope*/
template<typename Elemento>
Elemento Pila<Elemento>::topePila(){

   if(this->tam == 0){
    return -1;                                      //pila aqui, porque puede ser un elemento valido
   }else{
    return this->tope->obtInfo();
   }

}


/*adquiere el tamaño de la pila*/
template<typename Elemento>
int Pila<Elemento>::longitud(){

    return this->tam;
}


/*retorna true si la lista esta vacia*/
template<typename Elemento>
bool Pila<Elemento>::esVacia(){

    return (this->tam == 0);
}


/*apila un elemento (nodo con el nuevo dato) al tope*/
template<typename Elemento>
void Pila<Elemento>::apilar(Elemento dato){
    
    Nodo<Elemento> *nNuevo = new Nodo<Elemento>(dato);
    nNuevo->modSiguiente(this->tope);
    this->tope = nNuevo;
    this->tam ++;
}



/*desapila un elemento (nodo) de la pila*/
template<typename Elemento>
void Pila<Elemento>::desapilar(){
    
    if(!esVacia()){
        Nodo<Elemento> *nTope = this->tope;
        this->tope = nTope->obtSiguiente();
        delete nTope;
        this->tam --;
    }
   
}



/*reescribimos el primero sii la pila no esta vacia */
template<typename Elemento>
void Pila<Elemento>::modTope(Elemento dato){
    
    if(esVacia()){
        cout<<"la pila esta vacia"<<endl;
        return;
    }

    this->tope->modInfo(dato);
    
}


/*destructor por defecto*/
template<typename Elemento>
Pila<Elemento>::~Pila(){
    destruir();
}


/*destructor por defecto*/
template<typename Elemento>
void Pila<Elemento>::destruir(){
    
    while(this->tam != 0){
        desapilar();
    }
}



/*invierte la pila*/
/*template<typename Elemento>
void Pila<Elemento>::invertir(){
    Pila<Elemento> pAux;                                                                           //se crea una pila aux


    while( !esVacia() ){
        Elemento dato = topePila();
        desapilar();
        pAux.apilar(dato);
    }
    
    
    while(!pAux.esVacia()){
        Elemento dato = topePila();
        pAux.desapilar();
        apilar(dato);
    }

    /*while( !esVacia() ){
        Elemento dato = topePila();
        desapilar();
        pAux.apilar(dato);
    }


    while(!pAux.esVacia()){
        Elemento dato = topePila();
        pAux.desapilar();
        apilar(dato);
    }
    

}*/



/* une una pila a la instanciada */
template<typename Elemento>
void Pila<Elemento>::concatenar(Pila<Elemento> &pila) {
    if (pila.esVacia()) {
        return;                                                                                     // Si la pila a concatenar está vacía, no hacemos nada
    }

    
    Pila<Elemento> pAux;                                                                             // Usamos una pila auxiliar para invertir el orden de los elementos


    while (!pila.esVacia()) {                                                                       // Desapilamos todos los elementos de la pila a concatenar y los apilamos en la pila auxiliar
        Elemento dato = pila.topePila();                                                            // Obtenemos el dato del tope de la pila a concatenar
        pila.desapilar();                                                                           // Desapilamos el elemento de la pila a concatenar
        pAux.apilar(dato);                                                                          // Apilamos el dato en la pila auxiliar
    }

    
    while (!pAux.esVacia()) {                                                                       // Ahora apilamos los elementos de la pila auxiliar en la pila actual
        Elemento dato = pAux.topePila();                                                            // Obtenemos el dato del tope de la pila auxiliar
        pAux.desapilar();                                                                           // Desapilamos el elemento de la pila auxiliar
        apilar(dato);                                                                               // Apilamos el dato en la pila actual
    }
}



/*muestra la pila*/
template<typename Elemento>
void Pila<Elemento>::mostrar(){
    Nodo<Elemento> *nActual = this->tope;

    cout << "Elementos de la pila: ";
    while (nActual != nullptr) {
        cout << nActual->obtInfo();
        nActual = nActual->obtSiguiente();
        if (nActual != nullptr) {
            std::cout << " -> "; 
        }
    }
    cout<<endl; 
}
    

#endif //PILA_H