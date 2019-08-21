/* 
 * File:   Activity_List.h
 * Author: Samuel
 *
 * Created on 20 de agosto de 2019, 09:06 PM
 */

#ifndef ACTIVITY_LIST_H
#define	ACTIVITY_LIST_H
#include<string>
#include<stdlib.h>

#include "Node.h"
using namespace std;

class Activity_List {
public:
    Node* head;
    void insert(string day_, string activity_);
    Node* insert_day(string day_);
    Node* exist_day(string day_);
    void print();
    bool is_empty(); 
private:

};

#endif	/* ACTIVITY_LIST_H */

