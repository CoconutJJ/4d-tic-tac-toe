#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct Vector VECTOR;

double round_dec(double x, int dec_places);

VECTOR * createVector(double * vector, int sz);

int sameDim(VECTOR * vector_1, VECTOR * vector_2);

void destroyVector (VECTOR * vector);

double vectorMag (VECTOR * vector);

double dot(VECTOR * vector_1, VECTOR * vector_2);

int isDiag(VECTOR * vector);

int isPerpendicular(VECTOR * vector_1, VECTOR * vector_2);

#endif // !VECTOR_H