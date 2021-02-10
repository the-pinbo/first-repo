#include<stdlib.h>
#include<iostream>

void printarr(int arr [], int n)
{
    for (int i = 0; i < n; ++i)
        std::cout<<arr[i]<<std::endl;
    // Canot use a range baseed for loop 
}

int* new_array(int size)
{
    return(new int[size]);
}

int main()
{
    int Arr[5] {1,2,3,4,5};
    printarr(Arr, 5);
    int size {5};
    int a[size] {};
    for(auto x: a)
        std::cout<<x<<std::endl;
    auto arr = new_array(5);
    printarr(arr,5);
    return 0;
}