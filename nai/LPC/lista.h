#ifndef LISTA_H_
#define LISTA_H_
#include "nodo.h"
#include<iostream>
using namespace std;


/*-------------------------------definicion de la clase lista-----------------------------------*/

template <typename Elemento>
class Lista{
    private:
        int tam;
        Nodo<Elemento> *primero, *ultimo;                           //puntero al primero y otro al ultimo :)
    public:
        Lista();                                                    //constructor por defecto
        Lista(const Lista<Elemento> &lista);                        //constructor copia  (pila aqui)
        void copiar(const Lista<Elemento> &lista);                  //copia ()
        Elemento consultar(int pos);                                //ingresada una posicion retorna el elemento
        int buscar(Elemento dato);                                  //devuelve la posicion del elemento insertado
        int longitud();                                             // da el tamaño de la lista
        bool esVacia();                                             //verifica si la lista es vacia                                     
        bool estaElemento(Elemento dato);                           // verifica si en dato esta en la lista                  
        void modificar(int pos, Elemento dato);                     // en la posicion deseada ingresa un nuevo dato
        void insertar(int pos, Elemento dato);                      //inserta un dato en una posicion de la lista
        ~Lista();                                                   //destructor instanciado
        void limpiar();                                                                 //borra los elementos de la lista 
        void destruir();                                                                //destruye la lista
        void eliminar(int pos);                                                         //elimina una posicion de la lista
        void invertir();                                                                //invierte la lista
        void concatenar(Lista<Elemento> &lista);                                        //concatena una lista extra a la lista original
        bool igualar(Lista<Elemento> &Lista1, Lista<Elemento>  &Lista2);                //compara si dos listas son iguales
        void mostrar();                                                                 //imprime la lista insertada
        bool sublista(Lista<Elemento> &lista);                                          //debe verificar si una lista es sublista de la lista instanciada
                                                                                        //A es sublista de B, si todos los elementos de A estan en B de forma contigua y si A es vacia entonces es sublista de B
        void aggFinal(Elemento dato);                                                   //agrega al final (porsia se necesita aunque creo que ni hace falta :=)
        void hacerCircular();                                                           //hace que la lista instanciada se haga circular


        /*MergeSort*/
        void ordenar();
        Nodo<Elemento>* mergeSort(Nodo<Elemento> *cabeza);
        Nodo<Elemento>* dividir(Nodo<Elemento> *cabeza);
        Nodo<Elemento>* mezclar(Nodo<Elemento> *izquierda, Nodo<Elemento> *derecha);
        void actualizarUltimoYTamano();

};


/*----------------------------------implementacion de sus metodos----------------------------------*/


/*constructor por defecto*/
template <typename Elemento>
Lista<Elemento>::Lista(){      
    this->tam = 0;
    this->primero = NULL;
    this->ultimo = NULL;
}

/*realiza la copia de una lista, llamando al procedimiento copia()*/
template <typename Elemento>
Lista<Elemento>::Lista(const Lista<Elemento> &lista){   
    copiar(lista);
}


/*genera la copia nodo a nodo*/
template <typename Elemento>
void Lista<Elemento>::copiar(const Lista<Elemento> &lista){
    
    if(lista.tam != 0){
        limpiar();                                                              //limpia la lista instanciada 

        Nodo<Elemento> *nActual = lista.primero;
        Nodo<Elemento> *nNuevo = new Nodo<Elemento>(nActual->obtInfo());        //crea un nuevo  nodo en la memoria dinamica y lo inicializa con el valor que tiene nActual     
    
        this->primero = nNuevo;
        Nodo<Elemento> *nAux = nNuevo;
    
        nActual = nActual->obtSiguiente();                                      // Avanzar al siguiente nodo de la lista original
    
        while (nActual != NULL) {
            nNuevo = new Nodo<Elemento>(nActual->obtInfo());                    // Crear un nuevo nodo
            nAux->modSiguiente(nNuevo);                                         // Enlazar el nuevo nodo al final de la nueva lista
            nAux = nNuevo;                                                      // Mover nAux al nuevo nodo
            nActual = nActual->obtSiguiente();                                  // Avanzar al siguiente nodo de la lista original
        }
    
        this->ultimo = nAux;                                                    // Actualizar el último nodo de la nueva lista
        this->tam = lista.tam;                                                  // Actualizar el tamaño de la lista
    

        return;
    }

    cout<<"[ERROR] no se puede copiar una lista vacia "<<endl;

   
}

template<typename Elemento>
void Lista<Elemento>::limpiar(){
    destruir();
    this->tam = 0;
    this->primero = NULL;
    this->ultimo = NULL;
}


/*consulto el elemento (dato), dada una posicion*/
template <typename Elemento>
Elemento Lista<Elemento>::consultar(int pos){
    Nodo<Elemento> *nActual = this->primero;
    

    if(pos < 1 || pos > this->tam){
        return Elemento();                                                            //retorna un objeto por defecto m o  i f i c a r 
    }


    if(pos == 1){

        return nActual->obtInfo();

    }else if(pos == this->tam){

        return this->ultimo->obtInfo();
           

    }else{
   
        for(int i=1; i<pos; i++){
            nActual = nActual->obtSiguiente();
        }
        return(nActual->obtInfo());

    }
}


/*busca la posicion de un  elemento (dato)*/
template <typename Elemento>
int Lista<Elemento>::buscar(Elemento dato){
    int  contador = 1;
    Nodo<Elemento> *nActual = this->primero;

    while(nActual != NULL){
        if(nActual->obtInfo() == dato){
            return (contador);
        }
        contador++;         
        nActual = nActual->obtSiguiente();
        
    }
    return -1;
}

 

/*muestra el tamaño de la lista*/
template <typename Elemento>
int Lista<Elemento>::longitud(){
    return (this->tam);
}
   

/*muestra si la lista creada es vacia*/
template <typename Elemento>
bool Lista<Elemento>::esVacia(){
    return (this->tam == 0);
}
   


/*determina si un elemento (dato) se encuentra en la lista*/
template <typename Elemento>
bool Lista<Elemento>::estaElemento(Elemento dato){              
    Nodo<Elemento> *nActual = this->primero;
    bool esActivo = false;


    while(nActual != NULL && !esActivo){
        if(nActual->obtInfo() == dato){
            esActivo = true;
        }
        nActual = nActual->obtSiguiente();
    }

    if(!esActivo){
        return (false);
    }else{
        return (true);
    }
}




/*sobreescribe un elemento del campo Info (dato)*/
template <typename Elemento>
void Lista<Elemento>::modificar(int pos, Elemento dato){            
    int i = 1;
    bool esActivo = false;
    Nodo<Elemento> *nActual = this->primero;

    while( nActual != NULL && !esActivo){
        if( i == pos ){
            nActual->modInfo(dato);
            esActivo = true;
        }
        nActual = nActual->obtSiguiente();
        i++;
    }
}



/*inserta en la lista un nuevo nodo con su elemento (dato) nuevo*/
template <typename Elemento>
void Lista<Elemento>::insertar(int pos, Elemento dato){
    Nodo<Elemento> *nNodo = new Nodo<Elemento>;                     //creacion del nodo que reservara el nuevo dato
    Nodo<Elemento> *nAnterior=NULL;
   

    nNodo->modInfo(dato);
    nNodo->modSiguiente(NULL);

    if(pos == 1){       //inserta en la primera posicion
        
        nNodo->modSiguiente(this->primero);         //debo pasarle una direccion de memoria
        this->primero = nNodo;
        if(this->tam == 0){
            this->ultimo = nNodo;
        }
        
    }else if(pos == this->tam + 1){
        if(this->ultimo != NULL){
            this->ultimo->modSiguiente(nNodo);
        }
        this->ultimo = nNodo;
    }else{
        nAnterior = this->primero;
        for(int i=0; i < pos - 1; i++){
            nAnterior = nAnterior->obtSiguiente();
        }
        nNodo->modSiguiente(nAnterior->obtSiguiente());
        nAnterior->modSiguiente(nNodo);
    }

    this->tam++;
}



/* destructor por defecto */
template<typename Elemento>
Lista<Elemento>::~Lista(){
    destruir();
}


/*elimina la lista completamente*/
template <typename Elemento>
void Lista<Elemento>::destruir(){
    Nodo<Elemento> *nActual = this->primero;
    Nodo<Elemento> *nSiguiente = NULL;

    while(nActual != NULL){
        nSiguiente = nActual->obtSiguiente();
        delete nActual;
        nActual = nSiguiente;
        this->tam--;
    }
    this->primero = NULL;                            // Asegúrate de que el puntero primero sea NULL
    this->ultimo = NULL;                             // Asegúrate de que el puntero ultimo sea NULL
    this->tam = 0;                                      // Reinicia el tamaño de la lista

}


/*elimina una posicion de la lista (el nodo)*/
template <typename Elemento>
void Lista<Elemento>::eliminar(int pos){
    Nodo<Elemento> *nActual = this->primero;

    if(pos == 1){
        this->primero = nActual->obtSiguiente();
        nActual->modSiguiente(NULL);
        if(this->tam == 1){
            this->ultimo = NULL;
        }
    }else{
        Nodo<Elemento> *nAnterior = NULL; 
        
        for(int i=1; i<pos; i++){
            nAnterior = nActual;
            nActual = nActual->obtSiguiente();
        }

        if(pos == this->tam){
        
            this->ultimo = nAnterior;
            nAnterior->modSiguiente(NULL);

        }else{
               
            nAnterior->modSiguiente(nActual->obtSiguiente());
            nActual->modSiguiente(NULL);

        }
    

    }
    delete nActual;
    this->tam--;
}


/*invierte la lista*/
template <typename Elemento>
void Lista<Elemento>::invertir(){
    Nodo<Elemento> *nActual = this->primero;
    Nodo<Elemento> *nSiguiente = NULL;       //apuntadores a: anterior, actual y siguiente
    Nodo<Elemento> *nAnterior = NULL;

    

    while( nActual != NULL){
        nSiguiente = nActual->obtSiguiente();    
        nActual->modSiguiente(nAnterior);
        nAnterior = nActual;
        nActual = nSiguiente;
        //nSiguiente = nSiguiente->obtSiguiente();
            
    }
    this->ultimo = this->primero;
    this->primero = nAnterior;
    
}


/*optimizar*/
/*une dos listas, sin importar que la lista instanciada sea vacia*/
template <typename Elemento> 
void Lista<Elemento>::concatenar(Lista<Elemento> &lista){

    if(lista.tam != 0){
        if(this->tam == 0){
            this->primero = lista.primero;
        }else{
            this->ultimo->modSiguiente(lista.primero);
        }
        this->ultimo = lista.ultimo;
        this->tam += lista.tam;
    }

}


/*pre: {lista1 & lista2 != vacio}*/
/*compara que dos listas sean iguales*/
template <typename Elemento> 
bool Lista<Elemento>::igualar(Lista<Elemento> &lista1, Lista<Elemento>  &lista2){
    
    if(lista1.esVacia() && lista2.esVacia()){
        return true;
    }

    if(lista1.tam != lista2.tam){
        return false;
    }

    Nodo<Elemento> *nAux1 = lista1.primero;
    Nodo<Elemento> *nAux2 = lista2.primero;

    while( nAux1 != NULL && nAux2 != NULL ){
        if(nAux1->obtInfo() != nAux2->obtInfo()){
            return false;
        }else{
            nAux1 = nAux1->obtSiguiente();
            nAux2 = nAux2->obtSiguiente();

        }
    }
    
    return true;

}

/*la lista debe ser diferente de vacio*/
template <typename Elemento> 
void Lista<Elemento>::mostrar(){

    if(this->esVacia()){                                                                        //p i l a aqui
        cout<<"La Lista esta vacia. "<<endl;
        
    }else{
        Nodo<Elemento> *nNodo = this->primero;
        while(nNodo != NULL){
            cout<<nNodo->obtInfo()<<" -> ";
            nNodo = nNodo->obtSiguiente();
        }

    }
}


/*verifica si es sublista*/
template <typename Elemento>
bool Lista<Elemento>::sublista(Lista<Elemento> &lista) {
    if (lista.tam == 0) {
        return true;                                                                                // Una lista vacía es siempre una sublista
    }

    if (this->tam < lista.tam) {
        return false;                                                                               // Si la lista actual es más pequeña que la lista a comparar, no puede ser sublista
    }

    Nodo<Elemento> *nActual = this->primero; 
    Nodo<Elemento> *nSublista = lista.primero; 

    while (nActual != NULL) {
        // Comienza a comparar solo si el primer elemento de la sublista coincide
        if (nActual->obtInfo() == nSublista->obtInfo()) {
            Nodo<Elemento> *tempActual = nActual;                                                  // Nodo temporal para recorrer la lista actual
            Nodo<Elemento> *tempSub = nSublista;                                                   // Nodo temporal para recorrer la sublista
            bool esSublista = true;                                                                // Bandera para verificar si es sublista

            // Compara los nodos de la sublista con los nodos de la lista actual
            while (tempSub != NULL) {
                if (tempActual == NULL || tempActual->obtInfo() != tempSub->obtInfo()) {
                    esSublista = false;                                                            // No coincide, no es sublista
                    break;
                }
                tempActual = tempActual->obtSiguiente();
                tempSub = tempSub->obtSiguiente();
            }

            if (esSublista) {
                return true;                                                                       // Se encontró una coincidencia completa
            }
        }
        nActual = nActual->obtSiguiente();                                                         // Avanza al siguiente nodo de la lista actual
    }

    return false;                                                                                  // No se encontró la sublista
}


template <typename Elemento>
void Lista<Elemento>::aggFinal(Elemento dato){
    Nodo<Elemento> *nNuevo = new Nodo<Elemento>(dato);                  // se crea un nueco nodo con y se le inserta el dato
    
    if (this->esVacia()) {
        
        this->primero = nNuevo;
        this->ultimo = nNuevo;
    } else {
        
        this->ultimo->modSiguiente(nNuevo);
        this->ultimo = nNuevo;
    }
    
    this->tam++;

}
      
template <typename Elemento>
void Lista<Elemento>::hacerCircular() {
    if (this->primero != NULL) {                                       // Si la lista no está vacía
        this->ultimo->modSiguiente(this->primero);                        // El último nodo apunta al primero
    }
}


/*-----------------------metodo de ordenamiento mergeSort*/

template <typename Elemento>
void Lista<Elemento>::ordenar() {
    if (this->primero == NULL || this->primero->obtSiguiente() == NULL) {
        return;                                                                                 // La lista está vacía o tiene un solo elemento
    }

    this->primero = mergeSort(this->primero);                                                   // Ordena la lista
    // Actualiza el puntero 'ultimo' y 'tam' si es necesario
    actualizarUltimoYTamano();
}

template <typename Elemento>
Nodo<Elemento>* Lista<Elemento>::mergeSort(Nodo<Elemento> *cabeza){
    if (cabeza == NULL || cabeza->obtSiguiente() == NULL) {
        return cabeza;                                                                          // Caso base: lista vacía o un solo nodo
    }

    // Divide la lista en dos mitades
    Nodo<Elemento> *mitad = dividir(cabeza);
    Nodo<Elemento> *izquierda = mergeSort(cabeza);                                              // Ordena la primera mitad
    Nodo<Elemento> *derecha = mergeSort(mitad);                                                 // Ordena la segunda mitad

    // Mezcla las dos mitades ordenadas
    return mezclar(izquierda, derecha);
}

template <typename Elemento>
Nodo<Elemento>* Lista<Elemento>::dividir(Nodo<Elemento> *cabeza){
    Nodo<Elemento> *lento = cabeza;
    Nodo<Elemento> *rapido = cabeza->obtSiguiente();

    // Avanza 'rapido' dos nodos y 'lento' un nodo
    while (rapido != NULL) {
        rapido = rapido->obtSiguiente();
        if (rapido != NULL) {
            lento = lento->obtSiguiente();
            rapido = rapido->obtSiguiente();
        }
    }

    Nodo<Elemento> *mitad = lento->obtSiguiente();
    lento->modSiguiente(NULL);                                                               // Termina la primera mitad
    return mitad;                                                                               // Retorna la segunda mitad
}

template <typename Elemento>
Nodo<Elemento>* Lista<Elemento>::mezclar(Nodo<Elemento> *izquierda, Nodo<Elemento> *derecha){
    if (izquierda == NULL) return derecha;
    if (derecha == NULL) return izquierda;

    Nodo<Elemento> *resultado = NULL;

    // Ordena los nodos
    if (izquierda->obtInfo() <= derecha->obtInfo()) {
        resultado = izquierda;
        resultado->modSiguiente(mezclar(izquierda->obtSiguiente(), derecha));
    } else {
        resultado = derecha;
        resultado->modSiguiente(mezclar(izquierda, derecha->obtSiguiente()));
    }

    return resultado;
}

template <typename Elemento>
void Lista<Elemento>::actualizarUltimoYTamano() {
    Nodo<Elemento>* actual = this->primero;
    this->tam = 0;                                                                               // Reinicia el tamaño

    while (actual != NULL) {
        this->tam++;
        this->ultimo = actual;                                                                  // Actualiza el último nodo
        actual = actual->obtSiguiente();
    }
}

#endif //LISTA_H
