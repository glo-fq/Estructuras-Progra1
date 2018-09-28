#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#define DEFAULT_MAX_SIZE 1024
#include "Stack.h"

using std::runtime_error;
using std::cout;

template<typename E>
class ArrayStack:public Stack<E>
{
    private:
        E *elements;
        int top;
        int max;
        int StackExpander;

    public:
        ArrayStack(int max=DEFAULT_MAX_SIZE) {
            elements=new E[max];
            this->max=max;
            top=0;
            StackExpander=2;

        }
        ~ArrayStack(){
            delete [] elements;//en la hoja va sin [], tener en cuenta
        }

        /** \ Encargada de insertar un elemento en el tope de la pila.   --LI--
         * \ Recibe el elemento que va a insertar (E element).
         * \ No retorna.
         */
        void push(E element){//throw(runtime_error){
//            cout<<"\tMAX VALUE: "<<max;
            if(max==top && StackExpander<2092){//este es el push cuando llega al max y se hace push.
                ArrayStack<E> *Temp;
                Temp=new ArrayStack<E>(max);
                for(int i=getSize()-1; i>=0; i--){
                        top--;
//                        cout<<"\nLo que saco de la pila: "<<elements[top];
                        Temp->push(elements[top]);
//                        cout<<"\nLo que entra en la pila: "<<Temp->topValue();
                }
                delete []elements;
//                cout<<"\nExpander: "<<StackExpander;
//                cout<<"\nTam del nuevo arreglo: "<<max*StackExpander;
                this->max=max*StackExpander;    //Es importante cambiar el valor de max antes de meterlo en el nuevo arreglo, sino el arreglo iría con el nuevo valor y el max seguiría siendo el ingresado al inicio.
                elements= new E[this->max];
                for(int j=Temp->getSize()-1; j>=0; j--){
                        push(Temp->topValue());
                        Temp->pop();
                }
                delete Temp;
                //StackExpander = StackExpander+2; con esto crea más memoria; diría que es más eficiente dado que realiza el proceso menos veces
                //cout<<"\nExpander+=2: "<<StackExpander;
            }
            elements[top]=element;
//            cout<<"\nTop Inicial: "<<top<<"\n";
            top++;
//            cout<<"\nTop ++: "<<top<<"\n";

        }

        /** \ Se encarga de eliminar el elemento del tope de la pila.   --FO--
         * \ No recibe parámetros.
         * \ Retorna el valor que fue eliminado.
         */
        E pop()throw(runtime_error){
            if(top==0){
                throw runtime_error("Stack Underflow.");
            }
            top--;
            return elements[top];
        }

        /** \ Indica el valor que se encuentra en el tope de la pila.
         * \ No recibe parámetros.
         * \ Retorna el elemento del tope de la pila.
         */
        E topValue() throw(runtime_error){
            if(top==0){
                throw runtime_error("Empty Stack.");
            }
            return elements[top-1];
        }

        /** Método encargado de limpiar la pila.
         * \ No recibe parámetros
         * \ No retorna.
         */
         void clear(){
            delete [] elements;
            elements=new E[max];
            top=0;
         }

         /** \ Método que indica si la pila está o no vacía.
          * \ No recibe parámetros.
          * \ Retorna true or false.
          */
          bool isEmpty(){
            return top==0;
          }

         /** Método que devuelve la cantidad de elementos de la pila.
        * Retorna int.
        */
        int getSize(){
            return top;
        }

        /** \ Este método imprime en una sola línea los contenidos de la pila;
         * empezando por el elemento que se encuentra en el tope de la pila.
         * \ No recibe parámetros.
         * \ No retorna.
         */
         void print()throw(runtime_error){
            if (top==0){
                throw runtime_error("Empty stack, can't print.");
            }
            int TopInicial=top;
            cout<<"\nElementos de la pila: ";
            for(int c=getSize()-1; c>=0 ;c--){
                cout<<"  "<<topValue();
                top--;
            }
            top=TopInicial;
         }





};

#endif // ARRAYSTACK_H
