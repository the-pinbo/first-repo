#include<iostream>
#include<stdlib.h>

struct rectangle
{
    int length;
    int bredth;
};


int main ()
{
    printf("The size of int ptr is %d\n",sizeof(int*));
    printf("The size of char ptr is %d\n",sizeof(char*));
    printf("The size of floar ptr is %d\n",sizeof(float*));
    printf("The size of douuble ptr is %d\n",sizeof(double*));
    // primitive data types
    int* Iptr = new int;
    delete Iptr;
    Iptr = (int*) malloc(sizeof(int));
    free(Iptr);
    // array 

    int*arrptr = new int [5];
    std::cout<<arrptr[1]<<std::endl;
    delete[] arrptr;
    arrptr = (int*)malloc(5*sizeof(int));
    std::cout<<arrptr[1]<<std::endl;
    free(arrptr);

    // Struct
    rectangle* Rptr = new rectangle;
    Rptr->bredth = 10;
    Rptr->length = 12; 
    std::cout<<Rptr->length*Rptr->bredth<<std::endl;
    delete Rptr;

    return 0;
}