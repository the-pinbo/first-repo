#include<iostream>

int main()
{
    char name[] =" finding";
    size_t H = 0, x = 1;

    size_t i {};

    while (name[i]!= '\0')
    {
        x = 1;
        size_t index = name[i] -'a';
        x = x<<index;
        if (H&x)
        {
            std::cout<<"Duplicate element found: "<<name[i]<<std::endl;

        }
        else
        {
            H = x|H;
        } 
        i++;
    }
    
    return 0;
}