#include <omp.h>
#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

#define TIME_START start = std::chrono::steady_clock::now();
#define TIME_END(NAME)                                                                     \
    end = std::chrono::steady_clock::now();                                                \
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); \
    cout << (NAME) << ", duration = " << duration << "ms" << endl;

main()
{

    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    auto duration = 0L;

    int i, j;
    int (*x)[10000] = new int[10000][10000];

    TIME_START
    for (i = 0; i < 10000; i++)
    {
        for (j = 0; j < 10000; j++)
        {
            x[i][j] = i + j;
        }
    }
    TIME_END("normal")

    TIME_START
    #pragma omp parallel for
    for (i = 0; i < 10000; i++)
    {
        for (j = 0; j < 10000; j++)
        {
            x[i][j] = i + j;
        }
    }
    TIME_END("OpenMP")
}