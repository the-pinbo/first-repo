#include<iostream>

int main()
{
    char str1[] = "decimal", str2[] = "medical";
    size_t size1 {}, size2{};
    for ( size1 = 0; str1[size1] != '\0'; ++size1)
    {
        ;
    }
    for ( size2 = 0; str2[size2] != '\0'; ++size2)
    {
        ;
    }
    char h[26] {};

    if(size2 != size1)
    {
        std::cout<<"Not Anagram!!!"<<std::endl;
    }
    else
    {
        for (size_t i = 0; i < size1; i++)
        {
            h[str1[i] - 'a']++;
        }
        for (size_t i = 0; i < size2; i++)
        {
            h[str2[i] - 'a']--;

            if(h[str2[i] - 'a'] < 0)
            {
                std::cout<<"Not an Anagram!!!"<<std::endl;
                break;
            }
        }
        std::cout<<"The two strings are Anagrams.."<<std::endl;
    }
    return 0;
}