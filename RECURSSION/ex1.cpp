#include<iostream>

void func1(int n)
{
    if(n>0)
    {
        printf("%d",n);
        func1(n-1);
    }
    else
        return;
}


void func2(int n)
{
    if(n>0)
    {
        printf("%d",n);
        func2(n-1);
    }
    else
        return;
}



int main ()
{
    func1(3);
    func2(3);
    return 0;
}