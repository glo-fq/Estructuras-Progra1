#include <iostream>
#include <windows.h>
//#include<SDL2/SDL.h>
//how to install SDL2: https://www.youtube.com/watch?v=QV6bOYbT_-I
using namespace std;

int main(){
    //SDL_Init(SDL_INIT_EVERYTHING);



    cout <<
    " _____               _        _           " << endl <<
    "|  ___| __ __ _  ___| |_ __ _| | ___  ___ " << endl <<
    "| |_ | '__/ _` |/ __| __/ _` | |/ _ \\/ __|" << endl <<
    "|  _|| | | (_| | (__| || (_| | |  __/\\__ \\" << endl <<
    "|_|  |_|  \\__,_|\\___|\\__\\__,_|_|\\___||___/" << endl
    << endl;

    cout <<
    "  +----------------------------------+" << endl <<
    "  | Seleccione el fractal que desea: |" << endl <<
    "  |----------------------------------|" << endl <<
    "  |                                  |" << endl <<
    "  | 1. Curva del dragon              |" << endl <<
    "  | 2. Curva de Sierpinski           |" << endl <<
    "  | 3. Curva de Levy C               |" << endl <<
    "  | 4. Arbol binario                 |" << endl <<
    "  | 5. Planta fractal                |" << endl <<
    "  |                                  |" << endl <<
    "  |----------------------------------|" << endl <<
    "  | 6. SALIR                         |" << endl <<
    "  +----------------------------------+" << endl;

    return 0;

}
