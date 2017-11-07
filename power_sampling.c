#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

double rndm() {
    return (double)rand()/(double)RAND_MAX;
}

double power_sample(double xmin, double xmax, int degree) {
    double pmin = pow(xmin, degree + 1);
    double pmax = pow(xmax, degree + 1);
    double v = pmin + (pmax - pmin)*rndm();
    return pow(v, 1.0/(degree + 1));
}

int main() {
    unsigned int seed = 32345U;
    srand(seed);

    int xmin = 1;
    int xmax = 100;

    double* hist = malloc((xmax-xmin + 1)*sizeof(double));
    memset(hist, 0, (xmax-xmin + 1)*sizeof(double));

    // sampling
    int nsamples = 100000000;
    for(int k = 0; k != nsamples; ++k) {
        double v = power_sample(xmin, xmax, 2);
        int idx = (int)v;
        hist[idx] += 1.0;
    }

    // normalization
    for(int k = xmin; k != xmax; ++k) {
        hist[k] /= (double)nsamples;
    }

    // output
    for(int k = xmin; k != xmax; ++k) {
        double x = k + 0.5;
        printf(" %e     %e\n", x, hist[k]);
    }

    free(hist);

    return 0;
}
