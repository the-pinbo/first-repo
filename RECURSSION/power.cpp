#include<iostream>

size_t power_r(size_t n, size_t m)
{
    if(n==0)
        return 1;
    return power_r(n-1, m)*m;
}

size_t power_l(size_t n, size_t m)
{
    if(n==0)
        return 1;
    size_t power {1};
    while (n--)
    {
        power *= m;
    }
    return power;
}

int main()
{
    std::cout<<power_r(2,5)<<std::endl;
    std::cout<<power_l(2,5)<<std::endl;

    return 0;
}