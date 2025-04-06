#ifndef NODO_H_
#define NODO_H_
#include<cstddef>           //para el manejo de punteros



/*-------------------------definicion de la clase nodo-------------------------------------*/

template <typename Elemento>
class Nodo{
    
    private:
        Elemento info;
        Nodo<Elemento> *prox;
    
    public:
        Nodo();
        Nodo(Elemento dato);               
        Elemento obtInfo() const;
        Nodo<Elemento> *obtSiguiente() const;
        void modInfo(Elemento dato);                    
        void modSiguiente(Nodo<Elemento> *obtSig);

};

/*-------------------------implementacion de los metodos-------------------------------------*/


/* metodo constructor */
template <typename Elemento>                        
Nodo<Elemento>::Nodo(){
    this->info = info;      //colocar Elemeto() porque sirve para cualquier tipo de dato
    this->prox = NULL;
}


/*inserta un dato en el nodo creado*/
template <typename Elemento>
Nodo<Elemento>::Nodo(Elemento dato){
        this->info = dato;
        this->prox = NULL;
}


/*obtiene el dato del campo info del nodo*/
template <typename Elemento>
Elemento Nodo<Elemento>::obtInfo() const{
    return this->info;
}


/*obtiene la direccion del nodo siguiente*/
template <typename Elemento>
Nodo<Elemento>* Nodo<Elemento>::obtSiguiente() const{
    return this->prox;
}


/*reescribe el dato que esta en el campo info*/
template <typename Elemento>
void Nodo<Elemento>::modInfo(Elemento dato){
    this->info = dato;
}


/*modifica la direccion a la que apunta*/
template <typename Elemento>
void Nodo<Elemento>::modSiguiente(Nodo<Elemento> *obtSig){
    this->prox = obtSig;

}
#endif //NODO_H
