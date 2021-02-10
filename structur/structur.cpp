#include<iostream>

struct compno
{
    int x, y;
    char mod;
};


int main ()
{
    compno z {0,0};
    printf("The size of a complex number: %d\n",sizeof(z));//Padding of a structure

}