/* 
 * File:   Nodo.h
 * Author: Samuel
 *
 * Created on 20 de agosto de 2019, 08:47 PM
 */

#ifndef NODO_H
#define	NODO_H
#include<string>
#include<stdlib.h>
using namespace std;

class Node {
public:
    
    Node* sig = 0;
    Node* arriba = 0;
    Node* abajo = 0;
    
    Node();
    string day;
    string activity;
private:

};

#endif	/* NODO_H */

