/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edd_t2_201709426;

/**
 *
 * @author Samuel
 */
public class Bolsa {

    Nodo_Bolsa inicio = null;

    boolean esta_vacio() {
        return inicio == null;
    }

    void insertar(Object valor) {
        if (esta_vacio()) {
            inicio = new Nodo_Bolsa(inicio, valor);
        } else {
            Nodo_Bolsa aux = inicio;
            do {
                aux = aux.siguiente;
            } while (aux != inicio);
            aux.siguiente = new Nodo_Bolsa(inicio, valor);
        }
    }

    int contar() {
        int conteo  = 0;
        if (!esta_vacio()) {
            Nodo_Bolsa aux = inicio;
            do{
                conteo++;
                aux = aux.siguiente;
            }while(aux != inicio);
        }
        return conteo;
    }
}
