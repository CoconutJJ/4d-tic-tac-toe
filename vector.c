#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define DIAG_ANGRAD 0.615479
/**
 * VECTOR structure definition 
 */
typedef struct Vector {
    double * vector;
    int space;
} VECTOR;


double round_dec(double x, int dec_places) {
    double multiplier = (double) (1 * pow(10, dec_places));
    return floor(x * multiplier) / multiplier;
}

VECTOR * createVector(double * vector, int sz) {
    
    VECTOR * new_vector = malloc(sizeof(VECTOR));

    new_vector->vector = malloc(sz * sizeof(double));
    
    for (int i = 0; i < sz; i++) {
        new_vector->vector[i] = vector[i];
    }

    new_vector->space = sz;

    return new_vector;
}

int sameDim(VECTOR * vector_1, VECTOR * vector_2) {
    if (vector_1->space == vector_2->space) {
        return 1;
    } else {
        return 0;
    }
}


void destroyVector (VECTOR * vector) {
    free(vector->vector);
    free(vector);
}

double vectorMag (VECTOR * vector) {
    double sum = 0;
    for (int i = 0; i < vector->space; i++) {
        sum = sum + pow(vector->vector[i], 2.0);
    }

    return sqrt(sum);
}

double dot(VECTOR * vector_1, VECTOR * vector_2) {
    double sum = 0;
    if (sameDim(vector_1, vector_2)) {
        for (int i = 0; i < vector_1->space; i++) {
            sum += vector_1->vector[i] * vector_2->vector[i];
        }
    } else {
        fprintf(stderr, "error: dot: dot product between vectors must occupy same dimension");
        exit(EXIT_FAILURE);
    }
    return sum;
}

int isDiag(VECTOR * vector) {

    VECTOR * base = createVector(vector->vector, vector->space);

    base->vector[(vector->space - 1)] = 0;
    double base_mag = vectorMag(base);
    double vector_mag = vectorMag(vector);

    if (base_mag == (double) 0 || vector_mag == (double) 0){
        fprintf(stderr, "warn: isDiag: zero vector detected");
        return 0;
    }
    double angle = acos(dot(base, vector) / (vectorMag(base) * vectorMag(vector)));
    printf("Angle: %lf \n", angle);
    if (round_dec(angle, 3) == round_dec(DIAG_ANGRAD, 3)) {
        return 1;
    } else {
        return 0;
    }
}


int isPerpendicular(VECTOR * vector_1, VECTOR * vector_2) {
    if (sameDim(vector_1, vector_2)) {
        if (dot(vector_1, vector_2) == (double) 0) {
            return 1;
        } else {
            return 0;
        }
    } else {
        fprintf(stderr, "error: isPerpendicular: dot product between vectors must occupy same dimension");
        exit(EXIT_FAILURE);
    }
}
