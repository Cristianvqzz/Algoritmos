//Daniel Ortiz Sierra daniel.ortiz@udc.es
//Cristian Vázquez Seijas cristian.vazquez.seijas@udc.es
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "tiempo.h"
#include <stdbool.h>

#define NUMTABLAS 1 //Modificar para mostrar más tablas de cada algortimo
void inicializar_semilla();
void aleatorio(int v[],int n);
void ascendente(int v[], int n);
void descendente(int v[], int n);
void intercambiar(int* i,int* j);
void ord_ins (int v[], int n);
void ord_rap_aux (int v[],int iz,int dr);
void ord_rap (int v[],int n);
void test(int n,void (*alg_ord) (int v[],int n));
void tabla(int n,int k,void (*alg_ord) (int v[],int n),void (*inicializar) (int v[],int n));

int main(void) {
    inicializar_semilla();
    int i,j,m;

    test(20,ord_ins);
    test(20,ord_rap);
    printf("\nOrdenacion por insercion:\n");
    printf("inicializacion aleatoria\n");
    for(i = 0; i < NUMTABLAS; i++) {
        for(j = 500, m = 0;m < 8 ;m++, j *= 2) {
            tabla(j,1000,ord_ins,aleatorio);
        }
        printf("\n\n");
    }

    printf("inicializacion Ascendente\n");
    for(i = 0; i < NUMTABLAS; i++) {
        for(j = 500, m = 0;m < 8 ;m++, j *= 2) {
            tabla(j,1000,ord_ins,ascendente);
        }
        printf("\n\n");
    }
  
    printf("inicializacion Descendente\n");
    for(i = 0; i < NUMTABLAS; i++) {
        for(j = 500, m = 0;m < 8 ;m++, j *= 2) {
            tabla(j,100,ord_ins,descendente);
        }
        printf("\n\n");
    }

    printf("Ordenacion Rapida\n");
    
    printf("inicializacion aleatoria\n");
    for(i = 0; i < NUMTABLAS; i++) {
        for(j = 500, m = 0;m < 8 ;m++, j *= 2) {
            tabla(j,100,ord_rap,aleatorio);
        }
        printf("\n\n");
    }
  
    printf("inicializacion Ascendente\n");
    for(i = 0; i < NUMTABLAS; i++) {
        for(j = 500, m = 0;m < 8 ;m++, j *= 2) {
            tabla(j,100,ord_rap,ascendente);
        }
        printf("\n\n");
    }

    printf("inicializacion Descendente\n");
    for(i = 0; i < NUMTABLAS; i++) {
        for(j = 500, m = 0;m < 8 ;m++, j *= 2) {
            tabla(j,100,ord_rap,descendente);
        }
        printf("\n\n");
    }

    return 0;
}

void inicializar_semilla() {
    srand(time(NULL));
}
void aleatorio(int v[],int n) {
    int i, m = 2*n+1;
    for (i=0; i<n; i++) {
        v[i] = (rand() % m) - n;
    }
}
void ascendente(int v[], int n) {
    int i;
    for (i=0; i<n; i++) {
        v[i] = i;
    }
}
void descendente(int v[], int n) {
    int i;
    for (i = 0; i< n; i++) {
        v[i] = n - i - 1;
    }
}
void intercambiar(int* i,int* j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}
void ord_ins (int v[], int n) {
    int x,i,j;
    for (i = 1; i < n; i++) {
        x = v[i];
        j = i-1;
        while (j >= 0 && v[j] > x) {
            v[j+1] = v[j];
            j = j-1;
        }
        v[j+1] = x;
    }
}
void ord_rap_aux (int v[],int iz,int dr) {
    int x,pivote,i,j;
    if(iz < dr) {
        x = iz + rand()%(dr-iz+1);
        pivote = v[x];
        intercambiar(&v[iz],&v[x]);
        i = iz + 1;
        j = dr;

        while (i <= j) {
            while (i <= dr && v[i] < pivote ) {
                i = i + 1;
            }
            while (v[j] > pivote) {
                j = j - 1;
            }
            if (i <= j) {
                intercambiar(&v[i],&v[j]);
                i = i + 1;
                j = j - 1;
            }
        }
        intercambiar(&v[iz],&v[j]);
        ord_rap_aux (v,iz,j-1);
        ord_rap_aux (v,j + 1,dr);
    }
}
void ord_rap (int v[],int n) {
    ord_rap_aux(v,0,n-1);
}
void mostrarVec(int v[],int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ",v[i]);
    }
    printf("\n");
}
bool ordenado(int v[],int n) {
    int i;
    for (i = 0; i < n-1; i++) {
        if (v[i] > v[i+1]) return false;
    }
    return true;
}
void test(int n,void (*alg_ord) (int v[],int n)) {
    int v[n];
    if(alg_ord == ord_ins) printf("\nTest de Ordenacion por insercion\n");
    else printf("\nTest de Ordenacion rapida\n");

    printf("Vector Aleatorio\n");
    aleatorio(v,n);
    mostrarVec(v,n);
    printf("Odenado?:%s\n",ordenado(v,n) ? "SI" : "NO");
    if(!ordenado(v,n)) {
        printf("\nOrdenando...\n");
        alg_ord(v,n);
        mostrarVec(v,n);
        printf("Odenado?:%s",ordenado(v,n) ? "SI" : "NO");
    }

    printf("\nVector ordenado Ascendentemente\n");
    ascendente(v,n);
    mostrarVec(v,n);
    printf("Odenado?:%s\n",ordenado(v,n) ? "SI" : "NO");
    if(!ordenado(v,n)) {
        printf("\nOrdenando...\n");
        alg_ord(v,n);
        mostrarVec(v,n);
        printf("Odenado?:%s\n",ordenado(v,n) ? "SI" : "NO");
    }

    printf("\nVector Ordenado Descendentemente\n");
    descendente(v,n);
    mostrarVec(v,n);
    printf("Odenado?:%s",ordenado(v,n) ? "SI" : "NO");
    if(!ordenado(v,n)) {
        printf("\nOrdenando...\n");
        alg_ord(v,n);
        mostrarVec(v,n);
        printf("Odenado?:%s",ordenado(v,n) ? "SI" : "NO");
    }
}
void tabla(int n,int k,void (*alg_ord) (int v[],int n),void (*inicializar) (int v[],int n)) {
    double t;
    double sobrestimada,exacta,subestimada;
    if(alg_ord == ord_ins) {
        if(inicializar == aleatorio) {
            subestimada = pow(n,1.8);
            exacta = pow(n,2);
            sobrestimada = pow(n,2.2);
        }else if(inicializar == ascendente) {
            subestimada = pow(n,0.8);
            exacta = n;
            sobrestimada = pow(n,1.2);
        }else if(inicializar == descendente) {
            subestimada = pow(n,1.8);
            exacta = pow(n,2);
            sobrestimada = pow(n,2.2);
        }else {
            printf("Inicializacion no valida");
            return;
        }
    }else if(alg_ord == ord_rap) {
        if(inicializar == aleatorio) {
            subestimada = n;
            exacta = n * log(n);
            sobrestimada = pow(n,1.5);
        }else if(inicializar == ascendente) {
            subestimada = n;
            exacta = n * log(n);
            sobrestimada = pow(n,1.5);
        }else if(inicializar == descendente) {
            subestimada = n;
            exacta = n * log(n);
            sobrestimada = pow(n,1.5);
        }else {
            printf("Inicializacion no valida");
            return;
        }
    }else {
        printf("Algoritmo de ordenacion no valido");
        return;
    };

    t = alg_time(n,k,inicializar,alg_ord);
    printf("%12d%15.3f%15.7f%15.7f%15.7f\n",n,t,t/subestimada,t/exacta,t/sobrestimada);
}
