/* 
 * File:   main.cpp
 * Author: Samuel
 *
 * Created on 20 de agosto de 2019, 08:46 PM
 */

#include <cstdlib>

#include "Activity_List.h"

#include<stdlib.h>
#include<iostream>
#include <fstream>
#include <string.h>
#include <cstring>

#include<windows.h>

using namespace std;

Activity_List list;

/*
 * 
 */
void graficar() {
    ofstream file;
    file.open("d.dot");
    file << "digraph Grafico{ bgcolor=gray " << endl;
    file << " subgraph cluster0{ bgcolor=deepskyblue" << endl;
    file << "node[ style=filled,shape=record, fillcolor=\"antiquewhite:aquamarine\"];" << endl;
    if (is_empty()) {

    } else {
        Node* aux_day = list.head;
        int i = 0;
        int j = 0;
        while (aux_day != 0) {//recorriendo por dias
            cout << aux_day->day << endl;
            file << "list" << i << "-" << j << "[label=\"|{Id carreta |{" << aux_day->activity << "}} | \"];" << endl;
            file << "list" << i << "-" << j << " -> " << "list" << i + 1 << "-" << j < ";" << endl;

            Node* aux_act = aux_day->abajo;
            while (aux_act != 0) {// recorriendo actividades por cada dia
                file << "list" << i << "-" << j << "[label=\"|{Id carreta |{" << aux_day->activity << "}} | \"];" << endl;
                file << "list" << i << "-" << j << " -> " << "list" << i << "-" << j + 1 << ";" << endl;
                cout << aux_act->activity << endl;
                aux_act = aux_act->abajo;
                j++;
            }
            aux_day = aux_day->sig;
            i++;
        }
        file << "label = \"Lista de actividades\";}" << endl;
        file << "}" << endl;

        file.close();


        system("dot -Tpng d.dot -o d.png");
        string titulo = "d.png";
        ShellExecute(NULL, "open", "d.png", NULL, NULL, SW_SHOWNORMAL);


    }
}

string abrir_archivo(string direccion) {
    string cadena = "";
    ifstream fe(direccion);
    while (!fe.eof()) {
        string linea = "";
        getline(fe, linea);
        string day = "";
        cadena = cadena + linea;
        list.insert(day, linea);
    }
    fe.close();
    return cadena;
}


int main(int argc, char** argv) {
    while (true) {
        cout << "-+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+-" << endl;
        cout << "1. Leer archivo" << endl;
        cout << "2. Graficar lista" << endl;
        int d;
        cin>>d;
        switch(d){
            case 1:
                cout<<"ingrese la direccion"<<endl;
                string dir;
                cin>>dir;
                abrir_archivo();
                break;
            case 2:
                graficar();
                break;
        }

    }


    return 0;
}

