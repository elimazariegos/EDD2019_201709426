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
public class Nodo_Bolsa {

    Nodo_Bolsa siguiente;
    Object valor;
    
    public Nodo_Bolsa() {
    }

    public Nodo_Bolsa(Nodo_Bolsa siguiente, Object valor) {
        this.siguiente = siguiente;
        this.valor = valor;
    }
     
}
