#include<iostream>

size_t fact_r(size_t n)
{
    if(n>0)
        return fact_r(n-1)*n;
    else
        return 1;
}

size_t fact_l(size_t n)
{
    if(n==0||n==1)
        return 1;
    size_t factorial {1};
    while (n)
    {
        factorial *= n--;
    }
    return factorial;
}


int main()
{
    std::cout<<fact_l(5)<<std::endl;
    std::cout<<fact_r(5)<<std::endl;

    return 0;
}