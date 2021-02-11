#include<iostream>

size_t ncr(size_t n, size_t r)
{
    if(n==r||r==0)
        return 1;
    else 
        return ncr(n-1,r-1) + ncr(n-1,r);
}

int main ()
{
    std::cout<<ncr(3,2)<<std::endl;
    return 0;
}