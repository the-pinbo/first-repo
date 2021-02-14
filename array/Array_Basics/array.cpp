#include<iostream>

int main ()
{
    int arr[] {1, 2, 3, 4,};

    for(auto a : arr)
        std::cout<<a<<std::endl;
    printf("%d\n",arr[1]);
    
    printf("Enter the size of array:\n");
    int n {};
    std::cin>>n;

    int arr1[n];

    for(auto& x: arr1)
        {
            std::cout<<x<<std::endl;
            printf("initializing the vlaues of array\nEnter the value\n");
            std::cin>>x;
            std::cout<<x<<std::endl;
        }
    
    for(auto& x: arr1)
        printf("%d\n",x);

}