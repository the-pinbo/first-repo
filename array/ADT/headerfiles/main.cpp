#include"ADT.hpp"
int main()
{
    std::cout<<"Hello this is my first C++ class"<<std::endl;
    ADT array(5,10);
    array.selection_sort();
    array.display();
    return 0;
}