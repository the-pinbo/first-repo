#include<iostream>

size_t fionacci_r(size_t n)
{
    if(n<=1)
        return n;
    else
        return fionacci_r(n-1)+ fionacci_r(n-2);
}

size_t fionacci_l(size_t n)
{
    if(n<=1)
        return n;
    else
    {
        size_t t1{0}, t2{1};
        size_t tn;
        while (n-->1)
        {
            tn = t1 + t2;
            t1 = t2; 
            t2 = tn;
        }
        return tn;
    }
}



int main()
{

    return 0;
}