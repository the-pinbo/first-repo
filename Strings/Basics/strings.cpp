#include<iostream>
#include<string.h>

int main()
{   
    
    strcpy()
    char name[25] = "Inba";
    char* name_ptr = "Inba";
    std::cout<<"The size of name is "<<sizeof(name)<<std::endl;
    std::cout<<"Enter the name"<<std::endl;
    std::cin>>name;
    std::cout<<name<<std::endl;
    size_t i{};
    while (name[i] != '\0')
    {
        std::cout<<name[i++];
    }
    std::cout<<"Enter the name"<<std::endl;
    gets(name);
    std::cout<<std::endl;
    std::cout<<"The size of name_ptr is "<< sizeof(name_ptr)<<std::endl;
    return 0;
}