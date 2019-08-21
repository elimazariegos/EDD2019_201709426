/* 
 * File:   Activity_List.cpp
 * Author: Samuel
 * 
 * Created on 20 de agosto de 2019, 09:06 PM
 */

#include "Activity_List.h"
#include "Node.h"
#include<stdlib.h>
#include<iostream>
#include <fstream>
#include <string.h>
#include <cstring>

using namespace std;

void Activity_List::insert(string day, string activity) {
    //aqui codificas
    Node* node_day = exist_day(day);// verificar si existe el dia que se esta ingresando
    Node* niu = new Node();//creando un nuevo apuntador
    niu->day = day;//asignado dia al apuntador
    niu->activity = activity;//asignando actividad al apuntador

    if (node_day == 0) {//si no existe el dia crea un con el el metodo insert_day
        node_day = insert_day(day);
    }
    Node* aux = node_day;//creando aun apuntador auxiliar para recorrer lalista simple

    while (aux->abajo != 0) {//recorriendo lista doble
        aux = aux->abajo;
    }
    aux->abajo = niu;//asignando el nuevo apuntador hacia abajo
    niu->arriba = aux;//apuntando el nuevo hacia el anterior

}

Node* Activity_List::insert_day(string day_) {// metodo para insertar dia si no existe
    Node* niu = new Node();//creandi un nuevo apuntador
    niu->day = day_;//agregando el dia al apuntador
    niu->sig = niu->abajo = niu->arriba = 0;// mandando null a los diferentes apuntadores
    if (is_empty()) {
        head = niu;//si esta vacio la cabeza sera el nuevo 
        return head;//retornar la cabeza
    } else {//si no esta vacia
        Node* aux = head;
        while (aux->sig != 0) {
            aux = aux->sig;
        }
        aux->sig = niu;
        return aux->sig;
    }
}

Node* Activity_List::exist_day(string day) {//metodo para verificar si existe el dia
    if (is_empty()) {
        return 0;//si esta vacia retorna nulo
    } else {
        Node* aux = head;
        while (aux != 0) {
            if (aux->day == day) {
                return aux;//sino recorre la lista hasta encontrar el dia y  si no existe retorna nulo
            }
            aux = aux->sig;
        }
    }
}

bool Activity_List::is_empty() {//metodo para ver si esta vacia la lista verificando si la cabeza es nula
    return head == 0;
}

void Activity_List::print() {// metodo para imprimir 
    if (is_empty()) {

    } else {
        Node* aux_day = head;
        while (aux_day != 0) {//recorriendo por dias
            cout << "---------------------------" << endl;
            cout << "---------------------------" << endl;
            cout << aux_day->day << endl;
            cout << "---------------------------" << endl;
            Node* aux_act = aux_day->abajo;
            while (aux_act != 0) {// recorriendo actividades por cada dia
                cout << aux_act->activity << endl;
                aux_act = aux_act->abajo;
            }
            aux_day = aux_day->sig;
        }
    }
}