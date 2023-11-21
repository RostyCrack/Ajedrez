#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

struct Puntuacion{
    string nombre;
    int puntaje;
};
int main()
{
    //Escribir
    ofstream escribir;//Interfaz
    //Abrir el archivo
    escribir.open("/Users/cristianrost/Downloads/ArchivoTexto/Puntuacion.txt", ios::trunc);
    string fileName = "hola.txt";
    string fileNameEjercicio = "Puntuacion.txt";

    string palabra;

    ifstream leer(fileName);
    if(leer.is_open()){
       while(getline(leer,palabra)){
        cout<<palabra<<endl;
       }
        leer.close();
    }
    Puntuacion puntuacion[100];
    int tamano = 0;
    string palabraLinea;
    ifstream leerPuntaje(fileNameEjercicio);
    if(leerPuntaje.is_open()) {
        while(getline(leerPuntaje,palabra)){
            int espacio=0,fin=0;
            //Recorrido Palabra
            for(int i=0; i<palabra.size(); i++){
                if(isspace(palabra[i])){
                    espacio = i;
                }
            }
            puntuacion[tamano].nombre = palabra.substr(0,espacio);
            puntuacion[tamano].puntaje = atoi(palabra.substr(espacio+1).c_str());
            tamano++;
        }
        leerPuntaje.close();
    } else{
        cout<<"El archivo no se abrio"<<endl;
    }
    for(int i=0;i<tamano;i++){
        cout<<puntuacion[i].nombre<<" "<<puntuacion[i].puntaje<<endl;
    }
    return 0;
}
