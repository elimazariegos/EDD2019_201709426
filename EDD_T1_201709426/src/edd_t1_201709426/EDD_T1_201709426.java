/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edd_t1_201709426;

import java.util.Scanner;

/**
 *
 * @author Samuel
 */
public class EDD_T1_201709426 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        while (1 == 1) {
            System.out.println("1. Dia de cualquier fecha");
            System.out.println("2. Algoritmo “Criba de Eratóstenes” ");
            System.out.println("3. Salir ");
            Scanner entrada = new Scanner(System.in);
            int valor = entrada.nextInt();
            if (valor == 1) {
                System.out.println("ingrese el dia");
                int dia = entrada.nextInt();
                System.out.println("ingrese el mes");
                int mes = entrada.nextInt();
                System.out.println("ingrese el ano ");
                int ano = entrada.nextInt();
                dia_(dia, mes, ano);
            } else if (valor == 2) {
                System.out.println("ingrese el numero");
                int numero = entrada.nextInt();
                criba_de_eratostenes(numero);
            } else {
                System.exit(0);
            }

        }
    }

    public static void dia_(int dia, int mes, int ano) {
        int dia_res = 0;
        int[] cod_siglo = {4, 2, 0, 6};
        int[] cod_mes = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

        if (ano >= 1700) {
            int s = (ano / 100) + 1;
            dia_res = dia + mes + ano + (ano * (1 / 4)) + s;
            dia_res = dia_res % 7;
            switch (dia_res) {
                case 0:
                    System.out.println("domingo");
                    break;
                case 1:
                    System.out.println("lunes");

                    break;
                case 2:
                    System.out.println("martes");
                    break;
                case 3:
                    System.out.println("miercoles");
                    break;
                case 4:
                    System.out.println("jueves");
                    break;
                case 5:
                    System.out.println("viernes");
                    break;
                case 6:
                    System.out.println("sabado");
                    break;
            }

        }

    }

    public static void criba_de_eratostenes(int numero) {
        int i = 0;
        int[] primos = new int[numero];
        while (i < numero) {
            primos[i] = 1;
            i++;
        }
        i = 2;
        int j = 2;
        while (i < numero) {
            while (i * j < numero) {
                primos[i * j] = 0;
                j++;
            }
            i++;
        }
        if (primos[numero - 1] == 0) {
            System.out.println("no es primo");
        } else {
            System.out.println("es primo");
        }
    }

}
