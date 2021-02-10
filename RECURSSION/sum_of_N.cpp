#include<iostream>

size_t sum(size_t n)
{
    if(n>0)
        return sum(n-1) + n;
    else
        return 0;
}

size_t sum_l(size_t n)
{
    int sum {};
    while (n)
    {
        sum += n--;
    }
    return sum;
}


int main()
{
    std::cout<<sum(5)<<std::endl;
    std::cout<<sum_l(5)<<std::endl;

    return 0;
}