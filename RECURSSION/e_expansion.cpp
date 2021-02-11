#include<iostream>

long double exp (long double x, size_t n)
{
    static double p {1}, f{1};

    if(n==0)
        return 1;
    else
    {
        long double term = exp(x,n-1);
        p *= x;
        f *= n;
        return term + p/f;
    }
}

// Taylor Series using Horner's Rule
long double exp_horner (long double x, size_t n)
{
    static double s {1};

    if(n==0)
        return s;
    else
    {
        s = 1+ s*(x/n);
        return exp_horner(x,n-1);   

    }
}

long double exp_loop (long double x, size_t n)
{
    static double p{1}, f{1};
    size_t i{1};
    double s{1};
    while (i <=n )
    {
        p *= x;
        f *= i++;
        s += p/f; 
    }
    return s; 
}

long double exp_loop_horner (long double x, size_t n)
{
    double s{1};
    while (n>0)
    {
        s = 1+ s*(x/n--);
    }
    return s; 
}


int main()
{
   
   std::cout<<exp(1,7)<<std::endl;
   std::cout<<exp_horner(1,7)<<std::endl;
   std::cout<<exp_loop(1,7)<<std::endl;
   std::cout<<exp_loop_horner(1,7)<<std::endl;
    return 0;
}
