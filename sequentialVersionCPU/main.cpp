
#include "benchmark/benchmark_api.h"
#include <omp.h>

#define MAD_4(x, y)     x = (y*x) + y;      y = (x*y) + x;      x = (y*x) + y;      y = (x*y) + x;
#define MAD_16(x, y)    MAD_4(x, y);        MAD_4(x, y);        MAD_4(x, y);        MAD_4(x, y);
#define MAD_64(x, y)    MAD_16(x, y);       MAD_16(x, y);       MAD_16(x, y);       MAD_16(x, y);

void fma(int* out, int A, int i) {
	int x = A;
	int y = i;

	MAD_64(x, y);   MAD_64(x, y);
    MAD_64(x, y);   MAD_64(x, y);
    MAD_64(x, y);   MAD_64(x, y);
    MAD_64(x, y);   MAD_64(x, y);
    MAD_64(x, y);   MAD_64(x, y);
    MAD_64(x, y);   MAD_64(x, y);
    MAD_64(x, y);   MAD_64(x, y);
    MAD_64(x, y);   MAD_64(x, y);

    MAD_64(x, y);   MAD_64(x, y);
    MAD_64(x, y);   MAD_64(x, y);
    MAD_64(x, y);   MAD_64(x, y);
    MAD_64(x, y);   MAD_64(x, y);
    MAD_64(x, y);   MAD_64(x, y);
    MAD_64(x, y);   MAD_64(x, y);
    MAD_64(x, y);   MAD_64(x, y);
    MAD_64(x, y);   MAD_64(x, y);

	out[i] = y;
}

const int ITERATIONS = 1000000;

void cpuSequentialOperation() {
    int out[ITERATIONS];
    for(int i=0; i<ITERATIONS; ++i) fma(out, 4, i);
}

void cpuParallelOmpOperation() {
    int out[ITERATIONS];
#pragma omp parallel for
    for(int i=0; i<ITERATIONS; ++i) {
        fma(out, 4, i);
    }
}

void cpuSequential(benchmark::State& state) {
    while (state.KeepRunning()) {
        cpuSequentialOperation();
    }
}
BENCHMARK(cpuSequential);

void cpuParalleOmp(benchmark::State& state) {
    while (state.KeepRunning()) {
        cpuParallelOmpOperation();
    }
}
BENCHMARK(cpuParalleOmp);

BENCHMARK_MAIN();


