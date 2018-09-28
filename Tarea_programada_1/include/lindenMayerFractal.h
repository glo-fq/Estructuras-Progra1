#ifndef LINDENMAYERFRACTAL_H
#define LINDENMAYERFRACTAL_H
#include"ArrayList.h"
#include "Stack.h"
#include<stdlib.h>

//using namespace std;

class lindenMayerFractal {
    private:
        int toInt(string str){
            int value= atoi(str.c_str());
            return value;
        }

    public:
        /** Default constructor */
        lindenMayerFractal() {}
        /** Default destructor */
        virtual ~lindenMayerFractal() {}

        /** \ Método que genera la lista correspondiente para el fractal Curva del Dragón
         * \param int repeticiones - cantidad de iteraciones para generar la curva
         * \return ArrayList<string> con la lista de instrucciones
         */
        ArrayList<string> generarCurvaDragon(int repeticiones)throw(runtime_error){
            ArrayList<string> lista= new ArrayList();
            lista.append("D");
            if(repeticiones<=0){
                throw runtime_error("Ingrese cantidad válida de repeticiones");
            }
            if(repeticiones==1){
                return lista;
            }
            bool bandera=true;
            //ArrayList<string> listaNueva= ArrayList((lista.getSize()*2)+1);
            for(int i=0; i<repeticiones; i++){      //2<2
                int sizeOriginal= lista.getSize();  //size=3
                for(int j=0;j<sizeOriginal+1 ;j++){   //4<4
                        lista.goToPos(j*2)  //6
                        if(bandera==true && j%2==0){  //["d","D","i","D","d","I","i"]
                            lista.insert("D");
                        }
                        if(bandera==false && j%2==1){ //
                            lista.insert("I");
                        }
                        bandera=!bandera; //true
                    }
            }
            return lista;
        }

        /** \ Método que interpreta la lista de Curva del Dragón para ser leída por tortuga()
         * \param ArrayList<string> lista generada por método generarCurvaDragon
         * \return ArrayList<string> con la lista interpretada lista para Turtle
         */
        ArrayList<string> interpretarCurvaDragon(ArrayList<string> lista){ //inicializa pos(0) con A e interpreta las letras D=90 I=-90
            ArrayList<string> interpretedList = new ArrayList();
            int sizeOriginal= lista.getSize();  //["A","D","A","D","A","I","A","D","A","D","A","I","A","I","A"]
            //for insert A
            for(int i=0; i<sizeOriginal+1;i++){ //8<8
                lista.goToPos(i*2);             //["A","90","A","90","A","-90","A","90","A","90","A","-90","A","-90","A"]
                lista.insert("A");
            }
            //for interprete.
            for(int j=0; j<lista.getSize();j++){ // 10<15
                lista.goToPos(j);
                if(lista.getElement()=="A"){
                    interpretedList.append("A");
                }
                if(lista.getElement()=="D"){
                    interpretedList.append("90");
                }
                if(lista.getElement()=="I"){
                    interpretedList.append("-90");
                }

            }

        }


//        ArrayList<string> generarCurvaSierpinski(int repeticiones)throw (runtime_error){
//            ArrayList<string> lista= new ArrayList();
//            lista.append("D");
//            lista.append("D");
//            if(repeticiones<0){
//                throw runtime_error("Ingrese cantidad válida de repeticiones");
//            }
//            if(repeticiones==1){
//                return lista;   //["D","D"]
//            }
//            for(int i=0; i<repeticiones; i++){
//                    int sizeOriginal= lista.getSize();
//                    for(int j=0;j<sizeOriginal+1 ;j++){
//                        lista.goToPos(j*2)
//                        if(bandera==true && j%2==0){
//                            lista.insert("D");
//                        }
//                        if(bandera==false && j%2==1){
//                            lista.insert("I");
//                        }
//                        bandera=!bandera;
//                    }
//            }
//
//        }
        ArrayList<string> generarCurvaLevyC(int repeticiones) throw (runtime_error){
            ArrayList<string> lista = ArrayList<string>();
            lista.append("A");
            if(repeticiones <= 0){
                throw runtime_error("Ingrese cantidad válida de repeticiones");
            }
            if(repeticiones == 1) {
                return lista;
            }
            for(int i = 0; i < repeticiones; i++) {
                //Por si ocupo cambiar el tipo de for y usar variable j en vez de ir cambiando posición
                int sizeOriginal = lista.getSize();
                for(lista.goToStart(); !lista.atEnd(); lista.next()){
                    if(lista.getElement() == "A") {
                        lista.Remove();
                        lista.insert("D");
                        lista.next();
                        lista.insert("A");
                        lista.next();
                        lista.insert("I");
                        lista.next();
                        lista.insert("I");
                        lista.next();
                        lista.insert("A");
                        lista.next();
                        lista.insert("D");
                    }
                }
            }
            return lista;

        }






};

#endif // LINDENMAYERFRACTAL_H
