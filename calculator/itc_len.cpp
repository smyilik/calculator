#include "Header.h"

long long itc_len(string str)
{
    long long i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}