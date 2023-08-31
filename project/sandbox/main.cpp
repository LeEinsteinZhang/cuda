__global__ void vec_add(double *x, double *y, double *z, int n) {
    int i = get_tid();

    if (i < n) {
        z[i] = x[i] + y[i];
    }
}

int main(void) {
    int N = 1000000;
    int bs = 256;
    int gs = (N + bs - 1) / bs;

    vec_add <<<gs, bs>>> (x, y, z, N);
}
