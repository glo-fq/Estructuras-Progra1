#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#define DEFAULT_MAX_SIZE 1024
#include"List.h"
#include<stdexcept>
using namespace std;//::runtime_error;

template<typename E>
class ArrayList: public List<E>
{
    protected:
        E *elements;
        int size;
        int max;
        int pos;
        int i=2;


    public:

        //COSTRUCTOR de la clase ArrayList; crea un arreglo según el máximo de elementos ingresados en el main por el usuario
        ArrayList(int max=DEFAULT_MAX_SIZE) {
        elements=new E[max];
        this->max=max;
        size=0;
        pos=0;
        }
        //DESTRUCTOR
        virtual ~ArrayList() {
        delete []elements;
        }

        /** Coloca un elemento en la posición en la que se encuentra.
         ** Mueve todos los elementos un campo a la derecha; en caso de acabarse el tamaño del arreglo, lo reemplaza con uno nuevo del doble del tamaño gracias a las variable int i.
         * \ Recibe el elemento determinado "E".
         * \ No retorna
         */
        void insert(E element){
            int posIni=getPos();
            if(size==max && i<=2090){
                ArrayList<E> Temp(max*i);
                goToPos(getSize()-1);
                //cout<<"\n";
                for(int i=size-1;i!=-1;i--){
                    Temp.insert(elements[i]);
                }
                clear();
                exit();
                this->max=max*i;
                elements=new E[max];

                for(int j=0;j<Temp.getSize();j++){
                    Temp.goToPos(j);
                    //cout<<"\n"<<Temp.getElement();
                    elements[j]=Temp.getElement();
                    //cout<<"\n"<<elements[j];
                }
                Temp.clear();
                Temp.exit();
                i+=2;
            }
            goToPos(posIni);
            for (int w=size; w!=pos ;w--){
                elements[w]=elements[w-1];
            }
            elements[pos]=element;
            size++;
        }

        /** Agrega elementos al final del arreglo.
         ** En caso de acabarse el tamaño del arreglo, lo reemplaza con uno nuevo del doble del tamaño gracias a las variable int i.
         * \ Recibe el elemento determinado "E".
         * \ No retorna
         */
        void append(E element){
            if(size==max && i<=2090){
                ArrayList<E> Temp(max*i);
                goToPos(getSize()-1);
                for(int i=size-1;i!=-1;i--){
                    Temp.insert(elements[i]);
                }
                exit();
                elements=new E[max*i];
                for(int j=0;j<Temp.getSize();j++){
                    Temp.goToPos(j);
                    elements[j]=Temp.getElement();
                }
                Temp.exit();
                i+=2;
            }
            elements[size]=element;
            size++;
        }
        /** Remueve un elemento del arreglo
         * \ No recibe parámetros
         * \ Retorna el elemento E removido.
         */
        E Remove()throw(runtime_error){
            if(size==0){
                throw runtime_error("Empty List");
            }
            if (pos==size){
                throw runtime_error("No current element");
            }
            E result=elements[pos];
            for(int m=pos; m<size-1; m++){
                elements[m]=elements[m+1];
            }
            size--;
            return result;
        }

        /** Método encargado de vaciar por completo el arreglo .
         * \ No recibe parámetros.
         * \ No retorna.
         */
        void clear(){
        size=0;
        pos=0;
        delete[]elements;
        elements=new E[max];
        }

        /** Método encargado de eliminar por completo un Array.
         * \ No recibe parámetros.
         * \ No retorna.
         */
        void exit(){
        delete []elements;
        }

        /** Método que devuelve el elemento de la posición en la que se encuentra.
         * \ Retorna el elemento actual.
         * \ No recibe parámetros.
         */
        E getElement()throw(runtime_error){
        if(size==0){
            throw runtime_error("Empty list");
        }
        if (size==pos){
            throw runtime_error("No Current Element");
        }
        return elements[pos];
        }

        /** Método que envía la posición al inicio.
         * \ No retorna.
         * \ No recibe parámetros.
         */
        void goToStart(){
        pos=0;
        }

        /** Método que envía la posición al final.
         * \ No retorna.
         * \ No recibe parámetros.
         */
        void goToEnd(){
        pos=size;
        }
        /** Método que envía la posición a donde se indica.
         * \ Retorna la posición (int)
         * \ Recibe la posición a la que se desea ir.
         */
        void goToPos(int nPos) throw(runtime_error){
        if(nPos<0 || nPos>size){
            throw runtime_error("Index out of bounds");
            }
            pos=nPos;
        }

        /**Método que avanza la posición un lugar.
         * \ No retorna.
         * \ No recibe parámetros.
         */
        void next(){
        if(pos<size){
            pos++;
            }
        }

        /** Método que retrocede la posición un lugar.
         * \ No retorna.
         * \ No recibe parámetros.
         */
        void previous(){
        if(pos>=size){
            pos--;
            }
        }

        /** Método que devuelve la posición al inicio.
         * \ Retorna bool.
         * \ No recibe parámetros.
         */
        bool atStart(){
            return pos==0;
        }

        /**Método que coloca la posición al final.
         * \ Retorna bool.
         * \ No recibe parámetros.
         */
        bool atEnd(){
            return pos==size;
        }

        /**Método que obtiene la posición actual.
         * \ Retorna int; la posición.
         * \ No recibe parámetros.
         */
        int getPos(){
            return pos;
        }

        /** Método que obtiene la cantidad de elementos del arreglo
         * \ Retorna int, el size.
         * \ No recibe parámetros.
         */
        int getSize(){
            return size;
        }

        /** Retorna verdadero si el elemento enviado por parámetro se encuentra dentro de la lista, de otro modo retorna falso.
         *  retorna bool.
         * Recibe el elemento "E". NOTA: este contains deja la pos actual en donde se encuentra el elemento, para evitarlo solo es de crear una variable con la pos inicial y cambiarla al final. No se ha hecho por comodidad de trabajo
         */
        bool contains(E element){
            int j=0;
            while(j<getSize()){
                goToPos(j);
                if (getElement()==element){
                        return true;
                }
                j++;
            }
            return false;
        }

        /** Retorna la posición de la primera ocurrencia del elemento enviado por parámetro. Si elemento no se encuentra en la lista, se retorna -1 como resultado.
         * \ Recibe el elemento "E".
         * \ Retorna un int, con la posición determinada.
         */
        int indexOf(E elemento){
            for (int j=0;j<getSize();j++){
                goToPos(j);
                if(getElement()==elemento){
                        return getPos();
                }
            }
            return -1;
        }

        /** Agrega al final de la lista actual los elementos de la lista enviada por parámetro, en el mismo orden. La lista enviada por parámetro no debe ser modificada.
         * \ Recibe una lista.
         * \ No retorna.
         */
        void extend(List<E>&L){
            L.goToStart();
            for(int i=L.getPos();i<L.getSize();L.goToPos(++i)){
                append(L.getElement());
            }
        }
};

#endif // ARRAYLIST_H
