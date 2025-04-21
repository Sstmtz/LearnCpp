// Raw Pointer

// Early return skips delete
void science(double *data, int N) {
    double *temp = new double[N * 2];
    do_setup(data, temp, N);
    if (not needed(data, temp, N)) {
        return; // *
    }
    calculate(data, temp, N);
    delete[] temp; // *
}

// If second new throws, y is leaked
void science(double *x, int N) {
    double *y = new double[N];
    double *z = new double[N]; // *
    calculate(x, y, z, N);
    delete[] z;
    delete[] y; // *
}

float *science(float *x, float *y, int N) {
    float *z = new float[N];
    saxpy(2.5, x, y, z, N);
    // Can x and y be deleted?
    delete[] x;
    delete[] y;
    return z; // Caller is expected to delete[] z
}
