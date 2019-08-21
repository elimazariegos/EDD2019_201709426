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
using namespace std;

Activity_List list;

/*
 * 
 */
int main(int argc, char** argv) {
    while (true) {
        cout <<"-+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+-" <<endl;
        cout << "ingrese el dia" << endl;
        string d;
        cin>>d;
        cout << "ingrese la actividad" << endl;
        string a;
        cin>>a;
        
        cout <<"-+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+-" <<endl;
        list.insert(d, a);
        list.print();
    }


    return 0;
}

