//
// Created by daortiz on 11/10/24.
//

#include "tiempo.h"

double microsegundos() {
    struct timeval t;

    if(gettimeofday(&t, NULL) < 0) {
        return 0.0;
    }
    return (t.tv_usec + t.tv_sec * 1000000.0);
}
double alg_time(int n,int k,void (*inicializar) (int v[],int n),void (*ordenar) (int v[],int n)) {
    double t,t1,t2,ta,tb;
    int *v;

    v = malloc(n*sizeof(int));
    inicializar(v,n);
    t1 = microsegundos();
    ordenar(v,n);
    t2 = microsegundos();
    t = t2 - t1;

    if (t < 500) {
        printf("%-12d*",k);
        ta = microsegundos();
        for (int i = 0; i < k; i++) {
            inicializar(v,n);
            ordenar(v,n);
        }
        tb = microsegundos();
        t1 = tb - ta;
        if (t1 < 500) {
            printf("k no valida t1 < 500 \n");
            return 0.0;
        }
        ta = microsegundos();
        for (int i = 0; i < k; i++) {
            inicializar(v,n);
        }
        tb = microsegundos();
        t2 = tb - ta;
        t = t1 - t2;
        if (t < 500) {
            printf("k no valida t < 500 \n");
            return 0.0;
        }
        t /= k;
    }else {
        printf("%-12d*",1);
    }
    free(v);
    return t;
}