#include<iostream>
#include<stdlib.h>

// call by value
bool swap_value(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    return true;
}

// address

bool swap_address(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return true;
}

// Referense

bool swap_referense(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
    return true;
}


int main ()
{
    int x{10}, y{20};
    swap_value(x,y);
    std::cout<<x<<"\t"<<y<<std::endl;
    swap_address(&x,&y);
    std::cout<<x<<"\t"<<y<<std::endl;
    swap_referense(x,y);
    std::cout<<x<<"\t"<<y<<std::endl;
    return 0;

}