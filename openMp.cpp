#include <iostream>
#include <vector>
#include <omp.h>

// g++ -std=c++11 -fopenmp -o main openMp.cpp

int main() {
    #pragma omp parallel num_threads(5)
    {
        const int thread_id = omp_get_thread_num();

        // executed by every thread
        printf("initialize thread : %d\n", thread_id);

        // one section is executed by one thread
        #pragma omp sections
        {
            #pragma omp section
            {
                printf("section one is executed by thread : %d\n", thread_id);
            }

            #pragma omp section
            {
                printf("section two is executed by thread : %d\n", thread_id);
            }
        }

        // single construct is executed by only one thread
        #pragma omp single
        {
            printf("single construct is executed by thread number : %d\n", thread_id);
        }
    }

    int M = 1000, N = 1000, K = 1000;
    std::vector<std::vector<int>> A(M, std::vector<int>(K, 1));
    std::vector<std::vector<int>> B(K, std::vector<int>(N, 1));
    std::vector<std::vector<int>> C(M, std::vector<int>(N, 0));

    // parallelize the outer loop
    #pragma omp parallel for // shared(A, B, C, M, K, N, std::cout) default(none)
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < K; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }  
    }

    return 0;
}