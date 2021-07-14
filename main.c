#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int m = 25;
int n = 15;

float rand_f() {
    return (float)0.01f * (float)((rand() % (20000 + 1)) - 10000);
}

float* array1_create() {
    float* pole1 = (float*)malloc(m * n * sizeof(float));
    for (int i = 0; i < n * m; i++) {
        pole1[i] = rand_f();
    }
    return pole1;
}

float* array2_create() {
    float* pole2 = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        pole2[i] = rand_f();
    }
    return pole2;
}

char** barvy_create() {
    char** barvy = (char**)malloc(m * sizeof(char));
    for (int i = 0; i < m; i++) {
        int r = rand() % 5;
        if (r == 0) {
            barvy[i] = "red";
        }
        if (r == 1) {
            barvy[i] = "green";
        }
        if (r == 2) {
            barvy[i] = "blue";
        }
        if (r == 3) {
            barvy[i] = "black";
        }
        if (r == 4) {
            barvy[i] = "white";
        }
    }

    return barvy;
}

float cos_sim(float* pole1, float* pole2) {
    float pom1 = 0.0f, pom2 = 0.0f, pom3 = 0.0f;
    for (int i = 0; i < n; i++) {
        pom1 += pole1[i] * pole2[i];
        pom2 += powf(pole1[i], 2);
        pom3 += powf(pole2[i], 2);
    }
    return (pom1 * 1.0f) / (sqrtf(pom2) * sqrtf(pom3));
}

int main() {
    srand(time(NULL));

    float max = -1.0f;
    int a;

    for (int i = 0; i < m; i++) {
        float cos = cos_sim(array1_create(), array2_create());
        if (cos > max) {
            max = cos;
            a = i;
        }
    }

    char** barvy = barvy_create();

    printf("index: %d\n", a);
    printf("barva: %s\n", barvy[a]);
}
