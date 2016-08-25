
#ifdef _WIN32
#define WIN32_MEAN_AND_LEAN
#include <io.h>
#include <time.h>
#include <Windows.h>
//#undef interface
#else
#include <unistd.h>
#include <sys/time.h>
#endif


double CurrentTimeInSeconds()
{
#ifdef _WIN32
    static unsigned __int64 freq = 0;
    if(freq == 0) {
        LARGE_INTEGER i;
        QueryPerformanceFrequency(&i);
        freq = i.QuadPart;
    }
    LARGE_INTEGER t;
    QueryPerformanceCounter(&t);
    return t.QuadPart / (double) freq;
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1000000.0;
#endif
}
