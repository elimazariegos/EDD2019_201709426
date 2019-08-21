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
    Node* node_day = exist_day(day);
    Node* niu = new Node();
    niu->day = day;
    niu->activity = activity;

    if (node_day == 0) {
        node_day = insert_day(day);
    }
    Node* aux = node_day;

    while (aux->abajo != 0) {
        aux = aux->abajo;
    }
    aux->abajo = niu;
    niu->arriba = aux;

}

Node* Activity_List::insert_day(string day_) {
    Node* niu = new Node();
    niu->day = day_;
    niu->sig = niu->abajo = niu->arriba = 0;
    if (is_empty()) {
        head = niu;
        return head;
    } else {
        Node* aux = head;
        while (aux->sig != 0) {
            aux = aux->sig;
        }
        aux->sig = niu;
        return aux->sig;
    }
}

Node* Activity_List::exist_day(string day) {
    if (is_empty()) {
        return 0;
    } else {
        Node* aux = head;
        while (aux != 0) {
            if (aux->day == day) {
                return aux;
            }
            aux = aux->sig;
        }
    }
}

bool Activity_List::is_empty() {
    return head == 0;
}

void Activity_List::print() {
    if (is_empty()) {

    } else {
        Node* aux_day = head;
        while (aux_day != 0) {
            cout << "---------------------------" << endl;
            cout << "---------------------------" << endl;
            cout << aux_day->day << endl;
            cout << "---------------------------" << endl;
            Node* aux_act = aux_day->abajo;
            while (aux_act != 0) {
                cout << aux_act->activity << endl;
                aux_act = aux_act->abajo;
            }
            aux_day = aux_day->sig;
        }
    }
}