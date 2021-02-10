#include<iostream>

long double talor(long double x, size_t n)
{
    static long double p {1};
    static size_t f {1};
    if(n==0)
        return 1;
    else
    {
        long double sum {talor(x,n-1)};
        p *= x;
        f *= n;
        return sum + p/f;
    }
}
