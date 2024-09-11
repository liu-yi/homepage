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
    int (*x)[4000] = new int[4000][4000];

    TIME_START
    for (i = 0; i < 4000; i++)
    {
        for (j = 0; j < 4000; j++)
        {
            x[i][j] = i + j;
        }
    }
    TIME_END("normal")

    TIME_START
    for (j = 0; j < 4000; j++)
    {
        for (i = 0; i < 4000; i++)
        {
            x[i][j] = i + j;
        }
    }
    TIME_END("abnormal")
}