#include <iostream>
#include <random>
#include <algorithm>
#include <fstream>

using namespace std;
/**
 * Estructura de datos que contiene las variables usadas por el peon.
 */
struct Peon{
    string ficha;
    char color;
    int posicion;
    bool enJuego;
    bool primerMovimiento;
    bool esReina;
};

/**
 * Estructura de datos que contiene las variables usadas por la torre.
 */
struct Torre{
    string ficha;
    char color;
    int posicion;
    bool enJuego;
};


/**
 * Estructura de datos que contiene las variables usadas por el alfil.
 */
struct Alfil{
    string ficha;
    char color;
    int posicion;
    bool enJuego;
};

/**
 * Estructura de datos que contiene las variables usadas por el caballo.
 */
struct Caballo{
    string ficha;
    char color;
    int posicion;
    bool enJuego;
};

/**
 * Estructura de datos que contiene las variables usadas por el rey.
 */
struct King{
    string ficha;
    char color;
    int posicion;
    bool enJuego;
};

/**
 * Estructura de datos que contiene las variables usadas por la reina.
 */
struct Queen{
    string ficha;
    char color;
    int posicion;
    bool enJuego;
};

/**
 * Estructura de datos que representa las variables de un jugador, este puede ser la máquina también.
 */
struct Jugador{
    string nombre;
    char color;
    Peon peones[8];
    Torre torres[2];
    Caballo caballos[2];
    Alfil alfiles[2];
    Queen reina;
    King rey;

};

/**
 * Estructura de datos que contiene las variables del tablero.
 */
struct Tablero {
    string tablero[8][8];
};

/**
 * Estructura de datos que representa las variables de un juego.
 */
struct Juego{
    Tablero tablero;
    int turno;
    Jugador jugadorBlanco;
    Jugador jugadorNegro;

};

//Prototipos
/**
 * Funcion de la máquina de estados del juego
 * @param null
 * @return null
 */
void menuJuego();

/**
 * Función que controla el menú del juego
 * @param estado actual del juego
 * @return nuevo estado del juego
 */
int menuPrincipal(int estado);

/**
 * Función que muestra el menú de los jugadores y sus opciones
 * @param estado
 * @return nuevo estado con la ventana de selección de jugadores.
 */
int menuJugadores(int estado);

/**
 * Función que muestra el ranking del juego.
 * @param estado actual
 * @return nuevo estado con la ventana de ranking.
 */
int ranking(int estado);

/**
 * Función que comienza el juego con un solo jugador y la CPU.
 * @param estado actual
 * @return estado de un solo jugador.
 */
int unJugador(int estado);

/**
 * Función que comienza el juego con dos jugadores.
 * @param estado
 * @return estado con dos jugadores.
 */
int dosJugadores(int estado);

/**
 * Función que crea un nuevo jugador.
 * @param nombre
 * @return un jugador con su color y fichas creadas.
 */
Jugador nuevoJugador(string nombre, char color);

/**
 * Función que imprime el tablero ingresado.
 * @param tablero a imprimir
 */
void imprimirTablero(const Tablero& tablero);

/**
 * Función que retorna un tablero vacio.
 * @return tableroVacio[8][8]
 */
Tablero tableroVacio();

/**
 * Función que reemplaza las casillas vacías con las posiciones iniciales
 * @param tableroVacio[8][8]
 * @return arreglo del tablero con las fichas posicionadas.
 */
Tablero posicionarFichas(const Jugador& jugador1, const Jugador& jugador2, Tablero tableroVacio);

/**
 * Función que retorna un tablero vacio.
 * @return tableroVacio[8][8]
 */
Tablero tableroVacio();

/**
 * Función que reemplaza las casillas vacías con las posiciones iniciales
 * @param tableroVacio[8][8]
 * @return arreglo del tablero con las fichas posicionadas.
 */
Tablero posicionarFichas(const Jugador& jugador1, const Jugador& jugador2, Tablero tableroVacio);

/**
 * Función que verifica si la ficha seleccionada se puede mover
 * @param ficha a mover representada por su posicion.
 * @param tableroActual[8][8]
 * @return booleano indicando si la ficha se puede mover
 */
bool verificarCasilla(const Tablero& tableroActual, int casillaOrigen, int turno);

/**
 * Función que actualiza el tablero actual.
 * @param ficha a mover representada por su posicion.
 * @param tableroActual[8][8]
 * @return tablero actualizado.
 */
Tablero actualizarTablero(Tablero tablero, int casillaOrigen, int casillaDestinno, int turno);

/**
 * Función que crea un nuevo peón.
 * @param color representado por un caracter entre 'W' y 'B'
 * @return el peón creado.
 */
Peon crearPeon(char color);

/**
 * Función que crea una nueva torre.
 * @param color representado por un caracter entre 'W' y 'B'
 * @return La torre creada.
 */
Torre crearTorre(char color);

/**
 * Función que crea un nuevo caballo.
 * @param color representado por un caracter entre 'W' y 'B'
 * @return el caballo creado.
 */
Caballo crearCaballo(char color);

/**
 * Función que crea un nuevo alfil.
 * @param color representado por un caracter entre 'W' y 'B'
 * @return el alfil creado.
 */
Alfil crearAlfil(char color);

/**
 * Función que crea un nuevo rey.
 * @param color representado por un caracter entre 'W' y 'B'
 * @return el rey creado.
 */
King crearRey(char color);

/**
 * Función que crea una nueva reina.
 * @param color representado por un caracter entre 'W' y 'B'
 * @return la reina creada.
 */
Queen crearReina(char color);


/**
 * Las siguientes 4 funciones mueven la ficha a la casilla deseada, la función verifica que el movimiento sea válido y de no ser así
 * no mueve la ficha hasta que el movimiento sea válido.
 * @param string casilla2, una string con lo que se encuentre en la casillaDestino
 * @param int casillaDestino
 * @param int casillaOrigen
 * @param turno;]
 * @return booleano que indica si se puede mover o no.
 */
bool moverPeon(string casilla2, int casillaOrigen, int casillaDestino, int turno);

bool moverTorre(string casilla2, int casillaOrigen, int casillaDestino, int turno);

bool moverCaballo(string casilla2, int casillaOrigen, int casillaDestino, int turno);

bool moverAlfil(string casilla2, int casillaOrigen, int casillaDestino, int turno);

/**
 * Función que mueve las fichas de la CPU de manera aleatoria, únicamente presente en modo de un jugador.
 *@return tablero con la nueva posicion;
 */
Tablero CPU(Tablero tablero);


/**
 * Función que verifica si un rey se encuentra en jaque. De encontrarse en jaque, la única ficha que se podrá mover es el rey.
 * @return booleano true or false.
 */
bool jaqueMate(Tablero tablero);

/**
 * Funcion que registra un ganador
 * @param nombre
 * @param turnos
 */
void registrarGanador(string nombre, int turnos);

/**
 * Funcion que imprime los últimos 5 ganadores
 */
void leerGanadores();



int main() {
    Tablero tablero;
    menuJuego();
    return 0;
}


void menuJuego(){
    int estado = 1;
    while(estado != 0){
        switch(estado) {
            case 1:
                estado = menuPrincipal(estado);
                break;
            case 2:
                estado = menuJugadores(estado);
                break;
            case 3:
                estado = ranking(estado);
                break;
            case 4:
                estado = unJugador(estado);
                break;
            case 5:
                estado = dosJugadores(estado);
                break;
        }
        system("clear");
    }


}

int menuPrincipal(int estado){
    int opcionMenu;
    cout<<"-----------Ajedrez-----------"<<endl;
    cout<<"1. Jugar"<<endl;
    cout<<"2. Ranking"<<endl;
    cout<<"3. Salir"<<endl;
    cin>>opcionMenu;
    switch(opcionMenu){
        case 1:
            estado = 2;
            break;
        case 2:
            estado = 3;
            break;
        case 3:
            cout<<"Gracias por jugar :D"<<endl;
            estado = 0;
            break;
        default:
            estado = 1;
    }
    return estado;
}

int ranking(int estado){
    int opcion;
    cout<<"-----------Ranking-----------"<<endl;
    cout<<"Jugador----------------Turnos"<<endl;
    leerGanadores();
    cout<<"1. Volver"<<endl;

    cin>>opcion;
    if (opcion == 1){
        estado = 1;
    }
    return estado;
}

int menuJugadores(int estado){
    int opcionJugadores;
    cout<<"-----------Jugar-----------"<<endl;
    cout<<"1. Un Jugador"<<endl;
    cout<<"2. Dos Jugadores"<<endl;
    cout<<"3. Menu principal"<<endl;
    cin>>opcionJugadores;
    switch(opcionJugadores){
        case 1:
            estado = 4;
            break;
        case 2:
            estado = 5;
            break;
        case 3:
            estado = 1;
            break;
        default:
            return estado;
    }
    return estado;
}

int unJugador(int estado){
    string nombre;
    Tablero tablero;
    Juego juego;
    Jugador jugador;
    char colorJugador;
    char colorCPU;
    Jugador cpu;
    juego.tablero = tablero;
    int x = rand() % 2;
    if(x==1){
        colorJugador = 'W';
        colorCPU = 'B';
    } else{
        colorJugador = 'B';
        colorCPU = 'W';
    }
    cout<<"Si desea salir del juego pulse 0"<<endl;
    cout<<"El color que se le ha asignado es: ";
    if (colorJugador == 'W'){
        cout<<"blanco"<<endl;
    }
    else{
        cout<<"negro"<<endl;
    }
    cout<<"Ingrese su nombre: "<<endl;
    cin>>nombre;
    system("clear");



    jugador = nuevoJugador(nombre, colorJugador);
    cpu = nuevoJugador("CPU", colorCPU);
    tablero = tableroVacio();
    tablero = posicionarFichas(jugador, cpu, tablero);

    int casillaOrigen = 0;
    int casillaDestino;
    int turno = 1;
    bool jaque = false;
    while(!jaque){

        if(turno % 2 == 0){
            tablero = CPU(tablero);
        }
        else{
            do{
                imprimirTablero(tablero);
                cout<<"Indique la ficha que desea mover: "<<endl;
                cin>>casillaOrigen;
                system("clear");
            }while(!verificarCasilla(tablero,casillaOrigen,turno));

            //Devuelve al inicio en caso de que sea 0
            if (casillaOrigen==0){
                estado = 1;
                return estado;
            }

            else{
                imprimirTablero(tablero);
                cout<<"Indique la casilla donde se va a mover: "<<endl;
                cin>>casillaDestino;
                tablero = actualizarTablero(tablero, casillaOrigen, casillaDestino, turno);
                system("clear");
            }
        }
        jaque = jaqueMate(tablero);
        turno += 1;
    }

    system("clear");
    cout<<"Fin del juego"<<endl;
    registrarGanador(jugador.nombre, turno);
    return 3;
}

int dosJugadores(int estado){
    string nombre1;
    string nombre2;
    Tablero tablero;
    Juego juego;
    Jugador jugador1;
    char colorJugador = 'W';
    char color2 = 'B';
    Jugador jugador2;
    juego.tablero = tablero;

    cout<<"Si desea salir del juego pulse 0"<<endl;

    cout<<"Ingrese el nombre del jugador 1: "<<endl;
    cin >> nombre1;
    cout<<"Ingrese el nombre del jugador 2"<<endl;
    cin >> nombre2;

    system("clear");



    jugador1 = nuevoJugador(nombre1, colorJugador);
    jugador2 = nuevoJugador(nombre2, color2);
    tablero = tableroVacio();
    tablero = posicionarFichas(jugador1, jugador2, tablero);

    int casillaOrigen = 0;
    int casillaDestino;
    int turno = 1;
    bool jaque = false;
    int jugador = 1;
    while(!jaque){

        do{
            imprimirTablero(tablero);
            cout<<"Jugador "<<jugador<<":"<<endl;
            cout<<"Indique la ficha que desea mover: "<<endl;
            cin>>casillaOrigen;
            system("clear");
        }while(!verificarCasilla(tablero,casillaOrigen,turno));


        if (casillaOrigen==0){
            estado = 1;
            return estado;
        } else{
            imprimirTablero(tablero);
            cout<<"Indique la casilla donde se va a mover: "<<endl;
            cin>>casillaDestino;
            tablero = actualizarTablero(tablero, casillaOrigen, casillaDestino, turno);
            system("clear");
        }
        turno += 1;
        jaque = jaqueMate(tablero);
        if (jugador==1){
            jugador = 2;
        }
        else{
            jugador = 1;
        }
    }

    system("clear");
    cout<<"Fin del juego"<<endl;
    if(turno % 2 == 0){
        registrarGanador(jugador2.nombre, turno);
    } else{
        registrarGanador(jugador1.nombre, turno);
    }
    return 3;
}



Peon crearPeon(char color) {
    Peon peon{};
    peon.color = color;
    if (color == 'B'){
        peon.ficha = "[p]";
    }
    else{
        peon.ficha = "[P]";
    }

    peon.primerMovimiento = false;
    peon.enJuego = true;
    peon.esReina = false;
    return peon;
}

Torre crearTorre(char color){
    Torre torre{};
    torre.color = color;
    if (color == 'B'){
        torre.ficha = "[t]";
    }
    else{
        torre.ficha = "[T]";
    }

    torre.enJuego = true;
    return torre;
}

Caballo crearCaballo(char color){
    Caballo caballo{};
    caballo.color = color;
    if (color == 'B'){
        caballo.ficha = "[c]";
    }
    else{
        caballo.ficha = "[C]";
    }

    caballo.enJuego = true;
    return caballo;
}

Alfil crearAlfil(char color){
    Alfil alfil{};
    alfil.color = color;
    if (color == 'B'){
        alfil.ficha = "[a]";
    }
    else{
        alfil.ficha = "[A]";
    }

    alfil.enJuego = true;
    return alfil;
}

Queen crearReina(char color){
    Queen reina{};
    reina.color = color;
    if (color == 'B'){
        reina.ficha = "[q]";
    }
    else{
        reina.ficha = "[Q]";
    }

    reina.enJuego = true;
    return reina;
}

King crearRey(char color){
    King rey{};
    rey.color = color;
    if (color == 'B'){
        rey.ficha = "[k]";
    }
    else{
        rey.ficha = "[K]";
    }

    rey.enJuego = true;
    return rey;
}


Jugador nuevoJugador(string nombre, char color){
    Jugador jugador;

    jugador.nombre = nombre;
    jugador.color = color;
    int fila1;
    int fila2;
    if (color=='B'){
        fila1 = 20;
        fila2 = 10;
    }
    else{
        fila1 = 70;
        fila2 = 80;
    }

    for (int i = 0; i < 8 ;i++){
        jugador.peones[i]  = crearPeon(jugador.color);
        jugador.peones[i] .posicion = fila1 + i;
    }

    jugador.torres[0]  = crearTorre(jugador.color);
    jugador.torres[0].posicion = fila2 + 1;
    jugador.torres[1]  = crearTorre(jugador.color);
    jugador.torres[1].posicion = fila2 + 8;

    jugador.caballos[0]  = crearCaballo(jugador.color);
    jugador.caballos[0].posicion = fila2 + 2;
    jugador.caballos[1]  = crearCaballo(jugador.color);
    jugador.caballos[1].posicion = fila2 + 7;


    jugador.alfiles[0]  = crearAlfil(jugador.color);
    jugador.alfiles[0].posicion = fila2 + 3;
    jugador.alfiles[1]  = crearAlfil(jugador.color);
    jugador.alfiles[1].posicion = fila2 + 6;


    jugador.reina = crearReina(jugador.color);
    jugador.reina.posicion = fila2 + 4;

    jugador.rey = crearRey(jugador.color);
    jugador.rey.posicion = fila2 + 5;

    return jugador;
}

void imprimirTablero(const Tablero& tablero){
    cout<<"0 1  2  3  4  5  6  7  8";
    cout<<endl;
    for(int i=0; i<8; i++){
        cout<<i+1;
        for (int j=0; j<8; j++) {
            cout<<tablero.tablero[i][j];
        }
        cout<<endl;
    }

}

bool verificarCasilla(const Tablero& tablero, int casillaOrigen, int turno){
    char pos[2];
    int fila;
    int columna;
    int turnox = turno;
    string casilla1;

    //Casilla origen en entero y se convierte en un string
    sprintf(pos, "%d", casillaOrigen);

    //Caracteres ASCII trasformado en número, se le resta 1 adicional a la posición para que encaje en el arreglo [8][8]
    fila = pos[0] - 49;
    columna = pos[1] - 49;


    //Casilla1 representada por "[x]"
    casilla1 = tablero.tablero[fila][columna];


    //Devolver al inicio en caso de que sea un 0
    if(casillaOrigen == 0){
        return true;
    }


    //Si juegan las blancas y la casilla que seleccionó es mayúscula
    if (turnox % 2 != 0 && ((int) casilla1[1]) < 90) {

        //Límite inferio de las mayúsculas
        if(((int) casilla1[1]) > 64){
            return true;
        }

        else{
            return false;
        }
    }

    // Juegan las negras y la casilla que seleccionó es minúscula
    else if(turnox % 2 == 0 && ((int) casilla1[1]) < 122) {

        //Limite inferior minúsculas
        if(((int) casilla1[1]) > 90) {
            return true;
        }
        else{
            return false;
        }
    }

    else{
        return false;
    }
}



Tablero actualizarTablero(Tablero tablero, int casillaOrigen, int casillaDestino, int turno) {
    char pos[2];
    int fila1;
    int columna1;
    int fila2;
    int columna2;
    int turnox = turno;
    string casilla1;
    string casilla2;
    int ficha;

    //Dividir el entero en dos números
    sprintf(pos, "%d", casillaOrigen);
    fila1 = pos[0] - 49;
    columna1 = pos[1] - 49;
    casilla1 = tablero.tablero[fila1][columna1];

    sprintf(pos, "%d", casillaDestino);
    fila2 = pos[0] - 49;
    columna2 = pos[1] - 49;
    casilla2 = tablero.tablero[fila2][columna2];
    ficha = (int) casilla1[1];


    //Verifica si es un peon
    if (ficha == 80 || ficha == 112){


        if(moverPeon(casilla2, casillaOrigen, casillaDestino, turnox)){
            //Posiciona la ficha en la casilla destino
            tablero.tablero[fila2][columna2] = casilla1;

            //Deja vacía la casilla origen
            tablero.tablero[fila1][columna1] = "[ ]";

            //Verifica si un peon blanco está en límite superio
            if(casillaDestino - 10 < 9 ){
                tablero.tablero[fila2][columna2] = "[Q]";
            }

            //Verifica si un peon negro está en límite inferior
            else if(80 - casillaDestino < 0){
                tablero.tablero[fila2][columna2] = "[q]";
            }
            return tablero;
        }
        else{
            return tablero;
        }
    }

    //Verifica si es un caballo
    else if(ficha == 99 || ficha == 67){
        if(moverCaballo(casilla2, casillaOrigen, casillaDestino, turnox)){
            tablero.tablero[fila2][columna2] = casilla1;
            tablero.tablero[fila1][columna1] = "[ ]";
            return tablero;
        }
        else{
            return tablero;
        }
    }

    //Verifica si es una torre
    else if(ficha == 84 || ficha == 116){
        int resta;
        int casilla = 0;
        if (casillaOrigen > casillaDestino) {
            resta = casillaOrigen - casillaDestino;
            if (resta % 10 == 0) {
                //Contador casilla
                casilla = casillaOrigen - 10;
                //Movimiento vertical hacia arriba
                while (casilla >= casillaDestino) {


                    sprintf(pos, "%d", casilla);
                    fila2 = pos[0] - 49;
                    columna2 = pos[1] - 49;
                    casilla2 = tablero.tablero[fila2][columna2];

                    if (moverTorre(casilla2, casillaOrigen, casilla, turnox)) {
                        tablero.tablero[fila1][columna1] = "[ ]";
                        fila1 -= 1;
                        tablero.tablero[fila1][columna1] = casilla1;

                        //Verifica si ya comió alguna ficha
                        if ((int) casilla2[1] != 32) {
                            return tablero;
                        }
                    } else {
                        return tablero;
                    }
                    casilla -= 10;
                }
            }

            else {

                casilla = casillaOrigen - 1;
                //Movimiento horizontal izquierda
                while (casilla >= casillaDestino) {
                    sprintf(pos, "%d", casilla);
                    fila2 = pos[0] - 49;
                    columna2 = pos[1] - 49;
                    casilla2 = tablero.tablero[fila2][columna2];

                    if (moverTorre(casilla2, casillaOrigen, casilla, turnox)) {
                        tablero.tablero[fila1][columna1] = "[ ]";
                        columna1 -= 1;
                        tablero.tablero[fila1][columna1] = casilla1;

                        //Verifica si ya comió alguna ficha
                        if ((int) casilla2[1] != 32) {
                            return tablero;
                        }
                    } else {
                        return tablero;
                    }
                    casilla -= 1;

                }
                return tablero;
            }
        }

        else{
            resta = casillaDestino - casillaOrigen;
            if(resta % 10 == 0){
                casilla = casillaOrigen + 10;

                //Movimiento vertical hacia abajo
                while (casilla <= casillaDestino) {

                    sprintf(pos, "%d", casilla);
                    fila2 = pos[0] - 49;
                    columna2 = pos[1] - 49;
                    casilla2 = tablero.tablero[fila2][columna2];

                    if (moverTorre(casilla2, casillaOrigen, casilla, turnox)) {
                        tablero.tablero[fila1][columna1] = "[ ]";
                        fila1 += 1;
                        tablero.tablero[fila1][columna1] = casilla1;

                        //Verifica si ya comió alguna ficha
                        if ((int) casilla2[1] != 32) {
                            return tablero;
                        }
                    } else {
                        return tablero;
                    }
                    casilla += 10;
                }
            }
            //Movimiento horizontal derecha
            else{
                casilla = casillaOrigen + 1;
                while(casilla <= casillaDestino){

                    sprintf(pos, "%d", casilla);
                    fila2 = pos[0] - 49;
                    columna2 = pos[1] - 49;
                    casilla2 = tablero.tablero[fila2][columna2];

                    if(moverTorre(casilla2, casillaOrigen, casilla, turnox)){
                        tablero.tablero[fila1][columna1] = "[ ]";
                        columna1 += 1;
                        tablero.tablero[fila1][columna1] = casilla1;

                        //Verifica si ya comió alguna ficha
                        if((int)casilla2[1] != 32){
                            return tablero;
                        }
                    }
                    else{
                        return tablero;
                    }
                    casilla += 1;
                }
            }

        }
    }

    //Verifica si es un alfil
    else if(ficha == 65 || ficha == 97){
        int resta;
        int casilla = 0;
        if (casillaOrigen > casillaDestino) {
            resta = casillaOrigen - casillaDestino;
            //Movimiento diagonal derecha-arriba
            if (resta % 9 == 0) {
                casilla = casillaOrigen - 9;


                while (casilla >= casillaDestino) {

                    sprintf(pos, "%d", casilla);
                    fila2 = pos[0] - 49;
                    columna2 = pos[1] - 49;
                    casilla2 = tablero.tablero[fila2][columna2];

                    if (moverAlfil(casilla2, casillaOrigen, casilla, turnox)) {
                        tablero.tablero[fila1][columna1] = "[ ]";
                        fila1 -= 1;
                        columna1 += 1;
                        tablero.tablero[fila1][columna1] = casilla1;

                        //Verifica si ya comió alguna ficha
                        if ((int) casilla2[1] != 32) {
                            return tablero;
                        }
                    } else {
                        return tablero;
                    }
                    casilla -= 9;
                }
            }

            //Moviento diagonal izquierda-arriba
            else if(resta % 11 == 0){
                casilla = casillaOrigen - 11;
                while (casilla >= casillaDestino) {
                    sprintf(pos, "%d", casilla);
                    fila2 = pos[0] - 49;
                    columna2 = pos[1] - 49;
                    casilla2 = tablero.tablero[fila2][columna2];

                    if (moverAlfil(casilla2, casillaOrigen, casilla, turnox)) {
                        tablero.tablero[fila1][columna1] = "[ ]";
                        fila1 -= 1;
                        columna1 -= 1;
                        tablero.tablero[fila1][columna1] = casilla1;

                        //Verifica si ya comió alguna ficha
                        if ((int) casilla2[1] != 32) {
                            return tablero;
                        }
                    } else {
                        return tablero;
                    }
                    casilla -= 11;

                }
                return tablero;
            }
            else{
                return tablero;
            }
        }
        else{
            resta = casillaDestino - casillaOrigen;
            //Moviemiento derecha-abajo
            if(resta % 9 == 0){
                casilla = casillaOrigen + 9;
                while (casilla <= casillaDestino) {

                    sprintf(pos, "%d", casilla);
                    fila2 = pos[0] - 49;
                    columna2 = pos[1] - 49;
                    casilla2 = tablero.tablero[fila2][columna2];

                    if (moverAlfil(casilla2, casillaOrigen, casilla, turnox)) {
                        tablero.tablero[fila1][columna1] = "[ ]";
                        fila1 += 1;
                        columna1 -=1;
                        tablero.tablero[fila1][columna1] = casilla1;

                        //Verifica si ya comió alguna ficha
                        if ((int) casilla2[1] != 32) {
                            return tablero;
                        }
                    } else {
                        return tablero;
                    }
                    casilla += 9;
                }
            }

            //Movimiento izquierda abajo
            else if (resta % 11 == 0){
                casilla = casillaOrigen + 11;
                while(casilla <= casillaDestino){

                    sprintf(pos, "%d", casilla);
                    fila2 = pos[0] - 49;
                    columna2 = pos[1] - 49;
                    casilla2 = tablero.tablero[fila2][columna2];

                    if(moverAlfil(casilla2, casillaOrigen, casilla, turnox)){
                        tablero.tablero[fila1][columna1] = "[ ]";
                        columna1 += 1;
                        fila1 += 1;
                        tablero.tablero[fila1][columna1] = casilla1;

                        //Verifica si ya comió alguna ficha
                        if((int)casilla2[1] != 32){
                            return tablero;
                        }
                    }
                    else{
                        return tablero;
                    }
                    casilla += 11;
                }
            }
            else{
                return tablero;
            }
        }
    }

    //Verifica si es reina
    else if(ficha == 81 || ficha == 113){
        int resta;
        int casilla = 0;

        //Movimiento hacia arriba
        if (casillaOrigen > casillaDestino) {
            resta = casillaOrigen - casillaDestino;
            //Movimiento vertical-arriba
            if (resta % 10 == 0) {
                casilla = casillaOrigen - 10;
                while (casilla >= casillaDestino) {

                    sprintf(pos, "%d", casilla);
                    fila2 = pos[0] - 49;
                    columna2 = pos[1] - 49;
                    casilla2 = tablero.tablero[fila2][columna2];

                    if (moverTorre(casilla2, casillaOrigen, casilla, turnox)) {
                        tablero.tablero[fila1][columna1] = "[ ]";
                        fila1 -= 1;
                        tablero.tablero[fila1][columna1] = casilla1;

                        //Verifica si ya comió alguna ficha
                        if ((int) casilla2[1] != 32) {
                            return tablero;
                        }
                    } else {
                        return tablero;
                    }
                    casilla -= 10;
                }
            }
            //Movimiento diagonal derecha-arriba
            else if (resta % 9 == 0) {
                casilla = casillaOrigen - 9;
                while (casilla >= casillaDestino) {

                    sprintf(pos, "%d", casilla);
                    fila2 = pos[0] - 49;
                    columna2 = pos[1] - 49;
                    casilla2 = tablero.tablero[fila2][columna2];

                    if (moverAlfil(casilla2, casillaOrigen, casilla, turnox)) {
                        tablero.tablero[fila1][columna1] = "[ ]";
                        fila1 -= 1;
                        columna1 += 1;
                        tablero.tablero[fila1][columna1] = casilla1;

                        //Verifica si ya comió alguna ficha
                        if ((int) casilla2[1] != 32) {
                            return tablero;
                        }
                    } else {
                        return tablero;
                    }
                    casilla -= 9;
                }
            }
            //Movimiento diagonal izquierda-arriba
            else if(resta % 11 == 0){
                casilla = casillaOrigen - 11;
                while (casilla >= casillaDestino) {
                    sprintf(pos, "%d", casilla);
                    fila2 = pos[0] - 49;
                    columna2 = pos[1] - 49;
                    casilla2 = tablero.tablero[fila2][columna2];

                    if (moverAlfil(casilla2, casillaOrigen, casilla, turnox)) {
                        tablero.tablero[fila1][columna1] = "[ ]";
                        fila1 -= 1;
                        columna1 -= 1;
                        tablero.tablero[fila1][columna1] = casilla1;

                        //Verifica si ya comió alguna ficha
                        if ((int) casilla2[1] != 32) {
                            return tablero;
                        }
                    } else {
                        return tablero;
                    }
                    casilla -= 11;

                }
                return tablero;
            }
            //Movimiento horizontal
            else if(resta < 8){
                casilla = casillaOrigen - 1;
                while (casilla >= casillaDestino) {
                    sprintf(pos, "%d", casilla);
                    fila2 = pos[0] - 49;
                    columna2 = pos[1] - 49;
                    casilla2 = tablero.tablero[fila2][columna2];

                    if (moverTorre(casilla2, casillaOrigen, casilla, turnox)) {
                        tablero.tablero[fila1][columna1] = "[ ]";
                        columna1 -= 1;
                        tablero.tablero[fila1][columna1] = casilla1;

                        //Verifica si ya comió alguna ficha
                        if ((int) casilla2[1] != 32) {
                            return tablero;
                        }
                    } else {
                        return tablero;
                    }
                    casilla -= 1;

                }
                return tablero;
            }
            else{
                return tablero;
            }
        }
        //Movimiento hacia abajo
        else{
            resta = casillaDestino - casillaOrigen;
            //Moviemietno vertical-abajo
            if(resta % 10 == 0){
                casilla = casillaOrigen + 10;
                while (casilla <= casillaDestino) {

                    sprintf(pos, "%d", casilla);
                    fila2 = pos[0] - 49;
                    columna2 = pos[1] - 49;
                    casilla2 = tablero.tablero[fila2][columna2];

                    if (moverTorre(casilla2, casillaOrigen, casilla, turnox)) {
                        tablero.tablero[fila1][columna1] = "[ ]";
                        fila1 += 1;
                        tablero.tablero[fila1][columna1] = casilla1;

                        //Verifica si ya comió alguna ficha
                        if ((int) casilla2[1] != 32) {
                            return tablero;
                        }
                    } else {
                        return tablero;
                    }
                    casilla += 10;
                }
            }
            //Movimiento diagonal derecha
            else if(resta % 9 == 0){
                casilla = casillaOrigen + 9;
                while (casilla <= casillaDestino) {

                    sprintf(pos, "%d", casilla);
                    fila2 = pos[0] - 49;
                    columna2 = pos[1] - 49;
                    casilla2 = tablero.tablero[fila2][columna2];

                    if (moverAlfil(casilla2, casillaOrigen, casilla, turnox)) {
                        tablero.tablero[fila1][columna1] = "[ ]";
                        fila1 += 1;
                        columna1 -=1;
                        tablero.tablero[fila1][columna1] = casilla1;

                        //Verifica si ya comió alguna ficha
                        if ((int) casilla2[1] != 32) {
                            return tablero;
                        }
                    } else {
                        return tablero;
                    }
                    casilla += 9;
                }
            }
            //Diagonal izquierda
            else if (resta % 11 == 0){
                casilla = casillaOrigen + 11;
                while(casilla <= casillaDestino){

                    sprintf(pos, "%d", casilla);
                    fila2 = pos[0] - 49;
                    columna2 = pos[1] - 49;
                    casilla2 = tablero.tablero[fila2][columna2];

                    if(moverAlfil(casilla2, casillaOrigen, casilla, turnox)){
                        tablero.tablero[fila1][columna1] = "[ ]";
                        columna1 += 1;
                        fila1 += 1;
                        tablero.tablero[fila1][columna1] = casilla1;

                        //Verifica si ya comió alguna ficha
                        if((int)casilla2[1] != 32){
                            return tablero;
                        }
                    }
                    else{
                        return tablero;
                    }
                    casilla += 11;
                }
            }

            //Horizontal-izquierda
            else if (resta < 8){
                casilla = casillaOrigen + 1;
                while(casilla <= casillaDestino){

                    sprintf(pos, "%d", casilla);
                    fila2 = pos[0] - 49;
                    columna2 = pos[1] - 49;
                    casilla2 = tablero.tablero[fila2][columna2];

                    if(moverTorre(casilla2, casillaOrigen, casilla, turnox)){
                        tablero.tablero[fila1][columna1] = "[ ]";
                        columna1 += 1;
                        tablero.tablero[fila1][columna1] = casilla1;

                        //Verifica si ya comió alguna ficha
                        if((int)casilla2[1] != 32){
                            return tablero;
                        }
                    }
                    else{
                        return tablero;
                    }
                    casilla += 1;
                }
            }
            else{
                return tablero;
            }

        }
    }

    //Verifica si es un rey
    else{
        int resta;
        //Movimiento hacia arriba
        if (casillaOrigen > casillaDestino) {
            resta = casillaOrigen - casillaDestino;

            //Movimiento vertical
            if (resta % 10 == 0) {
                if (moverTorre(casilla2, casillaOrigen, casillaOrigen, turnox)) {
                    tablero.tablero[fila1][columna1] = "[ ]";
                    fila1 -= 1;
                    tablero.tablero[fila1][columna1] = casilla1;
                } else {
                    return tablero;
                }
            }

            //Movimiento diagonal derecha
            else if (resta % 9 == 0) {
                if (moverAlfil(casilla2, casillaOrigen, casillaOrigen, turnox)) {
                    tablero.tablero[fila1][columna1] = "[ ]";
                    fila1 -= 1;
                    columna1 += 1;
                    tablero.tablero[fila1][columna1] = casilla1;
                } else {
                    return tablero;
                }
            }

            //Movimiento diagonal izquierda
            else if(resta % 11 == 0){
                if (moverAlfil(casilla2, casillaOrigen, casillaOrigen, turnox)) {
                    tablero.tablero[fila1][columna1] = "[ ]";
                    fila1 -= 1;
                    columna1 -= 1;
                    tablero.tablero[fila1][columna1] = casilla1;

                } else {
                    return tablero;
                }
                return tablero;
            }

            //Movimiento horizontal-derecha
            else if(resta < 8){
                if (moverTorre(casilla2, casillaOrigen, casillaOrigen, turnox)) {
                    tablero.tablero[fila1][columna1] = "[ ]";
                    columna1 -= 1;
                    tablero.tablero[fila1][columna1] = casilla1;

                } else {
                    return tablero;
                }
                return tablero;
            }
            else{
                return tablero;
            }
        }

        //Movimiento hacia abajo
        else{
            resta = casillaDestino - casillaOrigen;
            //Movimiento vertical
            if(resta % 10 == 0){
                if (moverTorre(casilla2, casillaOrigen, casillaOrigen, turnox)) {
                    tablero.tablero[fila1][columna1] = "[ ]";
                    fila1 += 1;
                    tablero.tablero[fila1][columna1] = casilla1;

                } else {
                    return tablero;
                }
            }

            //Movimiento diagonal derecha
            else if(resta % 9 == 0){
                if (moverAlfil(casilla2, casillaOrigen, casillaOrigen, turnox)) {
                    tablero.tablero[fila1][columna1] = "[ ]";
                    fila1 += 1;
                    columna1 -=1;
                    tablero.tablero[fila1][columna1] = casilla1;

                } else {
                    return tablero;
                }
            }

            //Movimiento diagonal izquierda
            else if (resta % 11 == 0){
                if(moverAlfil(casilla2, casillaOrigen, casillaOrigen, turnox)){
                    tablero.tablero[fila1][columna1] = "[ ]";
                    columna1 += 1;
                    fila1 += 1;
                    tablero.tablero[fila1][columna1] = casilla1;
                }
                else{
                    return tablero;
                }

            }

            //Movimiento horizontal izquierda
            else if (resta < 8){
                if(moverTorre(casilla2, casillaOrigen, casillaOrigen, turnox)){
                    tablero.tablero[fila1][columna1] = "[ ]";
                    columna1 += 1;
                    tablero.tablero[fila1][columna1] = casilla1;
                }
                else{
                    return tablero;
                }
            }
            else{
                return tablero;
            }

        }
    }
    return tablero;
}


Tablero posicionarFichas(const Jugador& jugador1, const Jugador& jugador2, Tablero tablero){
    if (jugador1.color == 'B'){

        for(int c = 0; c < 8; c++) {
            tablero.tablero[1][c] = jugador1.peones[c].ficha;
        }

        tablero.tablero[0][0] = jugador1.torres[0].ficha;
        tablero.tablero[0][7] = jugador1.torres[1].ficha;

        tablero.tablero[0][1] = jugador1.caballos[0].ficha;
        tablero.tablero[0][6] = jugador1.caballos[1].ficha;

        tablero.tablero[0][2] = jugador1.alfiles[0].ficha;
        tablero.tablero[0][5] = jugador1.alfiles[1].ficha;

        tablero.tablero[0][3] = jugador1.reina.ficha;
        tablero.tablero[0][4] = jugador1.rey.ficha;

        for(int c = 0; c < 8; c++) {
            tablero.tablero[6][c] = jugador2.peones[c].ficha;
        }

        tablero.tablero[7][0] = jugador2.torres[0].ficha;
        tablero.tablero[7][7] = jugador2.torres[1].ficha;

        tablero.tablero[7][1] = jugador2.caballos[0].ficha;
        tablero.tablero[7][6] = jugador2.caballos[1].ficha;

        tablero.tablero[7][2] = jugador2.alfiles[0].ficha;
        tablero.tablero[7][5] = jugador2.alfiles[1].ficha;

        tablero.tablero[7][3] = jugador2.reina.ficha;
        tablero.tablero[7][4] = jugador2.rey.ficha;
    }
    else{

        for(int c = 0; c < 8; c++) {
            tablero.tablero[1][c] = jugador2.peones[c].ficha;
        }

        tablero.tablero[0][0] = jugador2.torres[0].ficha;
        tablero.tablero[0][7] = jugador2.torres[1].ficha;

        tablero.tablero[0][1] = jugador2.caballos[0].ficha;
        tablero.tablero[0][6] = jugador2.caballos[1].ficha;

        tablero.tablero[0][2] = jugador2.alfiles[0].ficha;
        tablero.tablero[0][5] = jugador2.alfiles[1].ficha;

        tablero.tablero[0][3] = jugador2.reina.ficha;
        tablero.tablero[0][4] = jugador2.rey.ficha;

        for(int c = 0; c < 8; c++) {
            tablero.tablero[6][c] = jugador1.peones[c].ficha;
        }

        tablero.tablero[7][0] = jugador1.torres[0].ficha;
        tablero.tablero[7][7] = jugador1.torres[1].ficha;

        tablero.tablero[7][1] = jugador1.caballos[0].ficha;
        tablero.tablero[7][6] = jugador1.caballos[1].ficha;

        tablero.tablero[7][2] = jugador1.alfiles[0].ficha;
        tablero.tablero[7][5] = jugador1.alfiles[1].ficha;

        tablero.tablero[7][3] = jugador1.reina.ficha;
        tablero.tablero[7][4] = jugador1.rey.ficha;
    }

    return tablero;
}


Tablero tableroVacio(){
    Tablero tablero;
    for(int i=0; i<8; i++){
        for (int j=0; j<8; j++) {
            tablero.tablero[i][j]="[ ]";
        }
    }
    return tablero;
}


bool moverPeon(string casilla2, int casillaOrigen, int casillaDestino, int turno){

    int resta;
    if(casillaOrigen > casillaDestino){
        resta = casillaOrigen-casillaDestino;
    } else{
        resta = casillaDestino-casillaOrigen;
    }
    //Verifica que el número esté en el rango de 11 a 88
    if(casillaDestino < 11 || casillaDestino >89){
        return false;
    }

    //Verifica si la casilla destino está vacía
    else if ((int) casilla2[1] == 32){
        //Verfica que el movimiento sea vertical y ascendente
        if(resta==10){
            return true;
        }

        else if(resta == 20){

            if(casillaOrigen > 69 && casillaOrigen < 80){
                return true;
            }

            //Juegan las blancas y la casilla destino es una negra
            else if(turno%2 != 0 && (int) casilla2[1] > 96) {
                return true;
            }
            //Juegan las negras y las casill
            else if(turno%2 == 0 && (int) casilla2[1] > 96) {
                return true;
            }

            else if(casillaOrigen > 20 && casillaOrigen < 30){
                return true;
            }
            else{
                return false;
            }
        }

    }
    else{

        if(casillaDestino+11 == casillaOrigen || casillaDestino+9 == casillaOrigen || casillaDestino-11 ==casillaOrigen || casillaDestino-9 ==casillaOrigen){

            //Si juegan las blancas y la casilla destino es una minúscula(blanca)
            if(turno%2 != 0 && (int) casilla2[1] > 96){
                return true;
            }
            //Si juegan las negras y la casilla destino es una mayúscula
            else if(turno%2 == 0 && (int) casilla2[1] < 96) {
                return true;
            }

            else{
                return false;
            }
        }
    }
    return false;
}

bool moverCaballo(string casilla2, int casillaOrigen, int casillaDestino, int turno){
    int resta;

    //Verifica si la casilla está vacía
    if((int) casilla2[1] == 32){
        if(casillaDestino < casillaOrigen){
            resta = casillaOrigen -casillaDestino;

            //Verifica que el movimiento sea en L;
            if(resta == 21 || resta == 12 || resta == 19 || resta == 8){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            resta = casillaDestino - casillaOrigen;
            if(resta == 21 || resta == 12 || resta == 19 || resta == 8){
                return true;
            }
            else if(turno % 2 == 0 && (int)casilla2[1] > 96){
                return true;
            }
            else{
                return false;
            }
        }
    }
    //Si la casilla está ocupada verifica si es un movimiento válida
    else{
        //Si juegan las blancas y la casilla es minúscula
        if(turno % 2 != 0 && (int)casilla2[1] > 96){
            return true;
        }

        //Si juegan las negras y la casilla es mayúscula
        else if(turno % 2 == 0 && (int)casilla2[1] < 96){
            return true;
        }
        else{
            return false;
        }
    }
}

bool moverTorre(string casilla2, int casillaOrigen, int casillaDestino, int turno){
    int resta;
    if (casillaDestino < casillaOrigen){
        resta = casillaOrigen-casillaDestino;
    }
    else{
        resta = casillaDestino-casillaOrigen;
    }
    if (resta % 10 == 0){
        if((int) casilla2 [1] == 32){
            return true;
        }

        //Casilla ocupada por una minúscula y el turno es impar
        else if((int) casilla2[1] > 96 && turno %2 != 0){
            return true;
        }

        //Casilla ocupada por una mayúscula y el turno es par
        else if ((int) casilla2[1] < 96 && turno %2 == 0){
            return true;
        }

        else{
            return false;
        }
    }

    else if (resta <= 7) {

        //Si la casilla está vacía
        if ((int) casilla2[1] == 32) {
            return true;
        }
        //Casilla ocupada por una minúscula y turno impar
        else if ((int) casilla2[1] > 96 && turno % 2 != 0) {
            return true;
        }
        //Casilla ocupada por una mayúscual y turno par
        else if ((int) casilla2[1] < 96 && turno %2 == 0){
            return true;
        }
        else {
            return false;
        }
    }
    else{
        return false;
    }
}

bool moverAlfil(string casilla2, int casillaOrigen, int casillaDestino, int turno){
    int resta;
    if (casillaDestino < casillaOrigen){
        resta = casillaOrigen-casillaDestino;
    }
    else{
        resta = casillaDestino-casillaOrigen;
    }

    //Movimiento diagonal derecha
    if (resta % 3 == 0){
        //Si está vacia
        if((int) casilla2 [1] == 32){
            return true;
        }

        //Si es negra y turno impar
        else if((int) casilla2[1] > 96 && turno %2 != 0){
            return true;
        }

        //Si es negra y turno par
        else if ((int) casilla2[1] < 96 && turno %2 == 0){
            return true;
        }
        else{
            return false;
        }
    }
    //Movimiento diagonal Izquierda
    else if (resta % 11 == 0) {
        //Casilla vacia
        if ((int) casilla2[1] == 32) {
            return true;
        }

        //Juegan blancas casillad estino negra
        else if ((int) casilla2[1] > 96 && turno % 2 != 0) {
            return true;
        }

        //Juegan negran casilla destino blanca
        else if ((int) casilla2[1] < 96 && turno %2 == 0){
            return true;
        }
        else {
            return false;
        }
    }
    else{
        return false;
    }
}

bool jaqueMate(Tablero tablero){

    bool reyblanco = false;
    bool reyNegro = false;
    int columna = 0;
    int fila = 0;
    char ficha = 'n';

    for (int i = 0; i < 8; i++) {
        for(int j = 0; j < 8 ;j++){
            fila = i;
            columna = j;
            ficha = tablero.tablero[fila][columna][1];
            if (ficha == 'k'){
                reyNegro = true;
            }
            else if (ficha == 'K'){
                reyblanco = true;
            }
        }
    }

    if(reyblanco && reyNegro){
        return false;
    }


    else{
        if(!reyblanco){
            cout<<"El jugador 2 es el ganador"<<endl;
        }
        else{
            cout<<"El jugador 1 es el ganador"<<endl;
        }
        return true;
    }
}


void registrarGanador(string nombre, int turnos){
    fstream historial;
    //Abre el archivo y añade información
    historial.open("/Users/cristianrost/CLionProjects/Ajedrez/Historial.txt", ios::app);

    historial <<nombre<<"                     "<<turnos<<endl;
    historial.close();
}

void leerGanadores(){
    const int k = 6;
    ifstream file("/Users/cristianrost/CLionProjects/Ajedrez/Historial.txt");
    string l[k];
    int size = 0 ;

    //Obtiene todas las líneas del archivo
    while(file.good()){
        getline(file, l[size%k]);
        size++;
    }

    //Imprime las últimas 5 líneas
    int start = size > k ? (size%k) : 0 ;
    int count = min(k, size);
    for(int i = 0; i< count ; i++){
        cout << l[(start+i)%k] << '\n' ;
    }
}

Tablero CPU(Tablero tablero) {
    default_random_engine eng(random_device{}());
    uniform_int_distribution<int> dis(11, 88);
    Tablero final;
    int randomOrigen;
    int randomDestino;
    bool iguales = true;

    while (iguales) {
        do {
            randomOrigen = dis(eng);
        } while (!verificarCasilla(tablero, randomOrigen, 2));
        randomDestino = dis(eng);
        final = actualizarTablero(tablero, randomOrigen, randomDestino, 2);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                //Encontró una casilla diferente al tablero incial
                if (tablero.tablero[i][j] != final.tablero[i][j]) {
                    iguales = false;
                }
            }
        }
    }
    return final;
}