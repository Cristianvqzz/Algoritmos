//
// Created by daortiz on 11/10/24.
//

#ifndef TIEMPO_H
#define TIEMPO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>


double microsegundos();
double alg_time(int n,int k,void (*inicializar) (int v[],int n),void (*ordenar) (int v[],int n));

#endif //TIEMPO_H
