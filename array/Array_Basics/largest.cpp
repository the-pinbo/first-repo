#include<stdio.h>
#include<iostream>

// bool selection_sort()
// {
//     if (this->length > 0)
//     {
//         for (size_t i = 0; i < this->length - 1; ++i)
//         {
//             this->swap(i,this->min_i());
//         }
//         return true;
//     }else
//         return false;
// }

bool insersion_sort(int * ptr , size_t length)
{
        for (size_t i = 1; i < length; ++i)
        {
            int temp = ptr[i];
            size_t j {i-1};
            while (j>=0 && ptr[j]>temp)
            {
                ptr[j+1] = ptr[j];
                --j;
            }
            ptr[j+1] = temp;
        }
}

// bool bubble_sort()
// {
//     for(size_t j{length}; j>1; --j)
//         {
//             for (size_t i = 0; i < j - 1; i++)
//                 {
//                     if (ptr[i] > ptr[i+1])
//                     {
//                         this->swap(i,i+1);
//                     }   
//                 }
//         }
// }

int main()
{
    int arr[] {1,2,9,4,5};
    int largest = 0;
    insersion_sort(arr,5);
    for (size_t i = 0; i < 5; i++)
    {
        std::cout<<arr[i]<<" "<<std::endl;
    }
    
    for(int i = 0; i<5; ++i)
    {
        if(arr[i] > largest)
            largest = arr[i];
    }
    printf("The largest number in the array is %d ", largest);
    return 0;
}