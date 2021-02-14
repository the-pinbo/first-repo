#include<iostream>

int main ()
{
    int* arr_ptr [3];

    for (size_t i = 0; i < 3; i++)
    {
        arr_ptr[i] = new int [5];
    }

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            arr_ptr[i][j] = i+j;
        }
        
    }

     for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            std::cout<<arr_ptr[i][j]<<" ";
        }
        std::cout<<std::endl;
        
    }

    std::cout<<arr_ptr<<" Address of the base element of the pointer array.\n";
    std::cout<<*arr_ptr<<" Address of the first 1d array which arr_ptr[0] is pointing to.\n";
    std::cout<<**arr_ptr<<" First element of the array.\n";

     for (size_t i = 0; i < 3; i++)
    {
        delete[] arr_ptr[i];  
    }

    int ** d_arr_ptr;
    d_arr_ptr = new int*[3];

     for (size_t i = 0; i < 3; i++)
    {
        *(d_arr_ptr + i) = new int [5];
        // d_arr_ptr[i] = new int [5];
    }

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            d_arr_ptr[i][j] = i+j;
        }
        

    }


    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            std::cout<<*(*(d_arr_ptr + i) + j)<<" ";
        }
        std::cout<<std::endl;
        
    }

     for (size_t i = 0; i < 3; i++)
    {
        delete[] d_arr_ptr[i];  
    }

    delete[] d_arr_ptr;

    return 0;
}