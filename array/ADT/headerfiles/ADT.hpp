#include<iostream>

class ADT
{
private:
    size_t length, size;
    int* ptr;
public:
    ADT(size_t size, size_t length);
    ADT();
    ~ADT();
    void display();
    size_t at(int element);
    bool add(int element);
    bool insert(int element , size_t index);
    bool insert(int element);
    bool is_sorted();
    bool del(size_t index);
    bool lin_search(int key);
    bool swap(size_t index1, size_t index2);
    bool binary_search(int key);
    bool set(size_t index, int element);
    int get(size_t index);
    bool push(int element);
    int pop();
    int min();
    size_t min_i();
    int max();
    int sum(size_t lower_bound, size_t upper_bound , int basevalue );
    int sum(int basevalue);
    int avg(size_t lower_bound, size_t upper_bound);
    bool reverse();
    bool left_shift(size_t number);
    bool right_rotate(size_t number);
    bool selection_sort();
    bool bubble_sort();
    bool insersion_sort();
    bool split_p_n();
    bool merge(ADT& array);
    size_t append(ADT& array);
    ADT concat(ADT& array);
    ADT Union(ADT& array);
    ADT intersection(ADT& array);


};

ADT ADT::intersection(ADT& array)
{
    size_t MAX = (this->size > array.size)?(this->size):(array.size);
    ADT a_arr(MAX,0);
    size_t i{0}, j{0},k{0};
    this->bubble_sort();
    array.bubble_sort();
    while(i<this->length && j<array.length)
    {
        if(this->ptr[i]>array.ptr[j])
        {
            j++;
        }
        else if (this->ptr[i] < array.ptr[j])
        {
            i++;
        }
        else
        {
            a_arr.ptr[k++] = this->ptr[i++];
            j++;
        } 
    }
    return a_arr;
}

ADT ADT::Union(ADT& array)
{
    ADT u_arr(this->size + array.size,0);
    size_t i{0}, j{0},k{0};
    this->bubble_sort();
    array.bubble_sort();
    while(i<this->length && j<array.length)
    {
        if(this->ptr[i]>array.ptr[j])
        {
            u_arr.ptr[k++] = this->ptr[j++];
        }
        else if (this->ptr[i] < array.ptr[j])
        {
            u_arr.ptr[k++] = this->ptr[i++];
        }
        else
        {
            u_arr.ptr[k++] = this->ptr[i++];
            j++;
        } 
    }
    return u_arr;
}

ADT ADT::concat(ADT& array)
{
    ADT c_arr(this->size + array.size,0);
    size_t i{0}, j{0};
    while(i<this->length)
    {
        c_arr.ptr[i++] = this->ptr[i++];
        c_arr.length++;
    }
    while(j< array.length)
    {
        c_arr.ptr[i++] = this->ptr[j++]; 
        c_arr.length++;
    }
    return c_arr;
}

size_t ADT::append(ADT& array)
{
    size_t i{0}, j{length - 1};
    while (this->length<=this->size && i < array.length)
    {
        this->ptr[j++] = array.ptr[i++];
        this->length++;
    }
    return i;
}

bool ADT::merge(ADT& array)
{
    size_t i{}, j{}, k{};
    ADT M_arr(this->size + array.size, 0);
    while (i< this->length && j< array.length)
    {
        if (this->ptr[i] > array.ptr[j])
        {
            M_arr.ptr[k++] = this->ptr[i++];
            M_arr.length++;
        }
        else
        {
             M_arr.ptr[k++] = this->ptr[j++];
             M_arr.length++;
        } 
    }
    while (i < this->length)
    {
        M_arr.ptr[k++] = this->ptr[i++];
        M_arr.length++;
    }
    while (j < array.length)
    {
        M_arr.ptr[k++] = this->ptr[j++];
        M_arr.length++;
    }
    return true;
}

bool ADT::split_p_n()
{
    if (this->length>0)
    {
        size_t i{0}, j{this->length-1};
        while (i>=j)
        {
            while (ptr[i++]<0)
            {
                continue;
            }

            while (ptr[j--]>=0)
            {
                continue;
            }

            this->swap(i,j); 
        }
        return true;

    }

    else
    {
        return false;
    }
    
}

bool ADT::is_sorted()
{
    for (size_t i = 0; i < this->length -1; ++i)
    {
        if (ptr[i] > ptr[i+1])
        {
            return false;
        }  
    }
    return true;
}

bool ADT::insersion_sort()
{
    if (this->length > 0)
    {
        for (size_t i = 1; i < this->length; ++i)
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
        return true;
    }else
        return false;

}

bool ADT::bubble_sort()
{
    if (this->length > 0)
    {
        for(size_t j{length}; j>1; --j)
        {
            for (size_t i = 0; i < j - 1; i++)
            {
                if (ptr[i] > ptr[i+1])
                {
                    this->swap(i,i+1);
                }   
            }
        }
        return true;
    }else
        return false;
}

size_t ADT::min_i()
{
    if (this->length ==1)
    {
        return 0;
    }
    else if (this->length > 0)
    {
        int min = ptr[0];
        size_t index {0};
        for (size_t i = 1; i < this->length; ++i)
        {
            if(ptr[i] < min)
            {
                min = ptr[i];
                index = i;
            }
            
        }
        return index;
    }
    else
    {
        std::cerr<<"Empty Array."<<std::endl;
        exit(1);
    }
    
    
}

// NOT WORKING!!!!
bool ADT::selection_sort()
{
    if (this->length > 0)
    {
        for (size_t i = 0; i < this->length - 1; ++i)
        {
            this->swap(i,this->min_i());
        }
        return true;
    }else
        return false;
}

bool ADT::right_rotate(size_t number)
{
    if(number > 0) 
    {
        int arr[number];
        for(size_t i{}, j{length-number}; i<number; ++i,++j)
        {
            arr[i] = ptr[j];
        }
        for(size_t j {length-1}, i{j-number}; j >= number; --j,--i)
        {
            ptr[j] = ptr[i];
        }
        for (size_t i = 0; i < number; i++)
        {
            ptr[i] = arr[i];
        }
        
        return true;
    }else
        return false;
}

size_t ADT::at(int element)
{
    for (size_t i = 0; i < length; i++)
    {
        if (element == ptr[i])
        {
            return i;
        } 
    }
    return 0;
}

bool ADT::left_shift(size_t number)
{
    if (number > 0)
    {
        for(size_t j {number-1},i{0}; j< length; ++j,++i)
        {
            ptr[i] = ptr[j];
        }
        length -= number;
        for(size_t i{length};i <= length + number; ++i)
        {
            ptr[i] = 0;
        }
        return true;
    }else
        return false;
}

bool ADT::reverse()
{
  for (size_t i {0}, j {this->length-1} ; i < this->length/2; ++i, --j)
  {
    swap(i,j);
  }
/*
  int arrc[length];
  for(size_t i {0}, j{length-1}; i<length; ++i,--j)
  {
      arrc[i] = ptr[j];
  }
  for(size_t i {}; i<length; ++i)
  {
      ptr[i] = arrc[i];
  }
*/
  return true;
}

int ADT::min()
{
    if (this->length > 0)
    {
        auto min = ptr[0];
        for (size_t i = 0; i < this->length; ++i)
        {
            if(ptr[i] < min)
                min = ptr[i];
        }
        return min;
    }
    else
    {
        std::cerr<<"Empty Array."<<std::endl;
        exit(1);
    }
    
    
}

int ADT::max()
{
    if (this->length > 0)
    {
        auto max = ptr[0];
        for (size_t i = 0; i < this->length; ++i)
        {
            if(ptr[i] > max)
                max = ptr[i];
        }
        return max;
    }
    else
    {
        std::cerr<<"Empty Array."<<std::endl;
        exit(1);
    }
    
    
}

int ADT::avg(size_t lower_bound, size_t upper_bound)
{
     return sum(lower_bound,upper_bound,0)/(upper_bound-lower_bound+1);
}

int ADT::sum(size_t lower_bound , size_t upper_bound, int basevalue )
{
    int sum {basevalue};
    for (size_t i = lower_bound; i <= upper_bound; ++i)
    {
        sum += ptr[i];
    }
    return sum;
}

int ADT::sum(int basevalue)
{
    return sum(0, this->length-1, basevalue);   
}

int ADT::pop()
{
    if(length > 0)
    {
        int element = ptr[--length];
        return element;
    }
    else
    {
        std::cerr<<"Empty Array."<<std::endl;
        return false;
    }
}

bool ADT::push(int element)
{
    if(this->length <  this->size)
    {
        ptr[this->length++] = element;
        return true;
    }
    else
    {
        std::cerr<<"Array is full."<<std::endl;
        return false;
    }
}

bool ADT::set(size_t index, int element)
{
    if(index < length)
    {
        ptr[index] = element;
        return true;
    }
    else
    {
        std::cerr<<"Invalid index."<<std::endl;
        return false;
    }
}

int ADT::get(size_t index)
{
    if(index >= 0 && index < this->length)
    {
        return ptr[index];
    }
    else
        exit(1);
}

ADT::ADT(): size{10}, length{5}
{
    ptr = new int [size];
    for (size_t i = 0; i < length; i++)
    {
        ptr[i] = i+1;
    }
}

ADT::ADT(size_t size, size_t length) 
:size {size}, length {length}
{   
    ptr = new int [size];
    std::cout<<"Enter the elements: "<<std::endl;
    for (size_t i = 0; i < length; i++)
            std::cin>>ptr[i];
    for (size_t i = length; i < size; i++)
            ptr[i] = 0;
}

ADT::~ADT()
{
    std::cout<<"Deleting array with [ ";
    for (size_t i = 0; i < size; i++,length--)
    {
        std::cout<<ptr[i];
    }
    std::cout<<" ] elements."<<std::endl;
    delete[] ptr;
}

void ADT::display()
{
    std::cout<<"Elements of the array [ ";
    for (size_t i = 0; i < length; i++)
    {
        std::cout<<ptr[i]<<" ";
    }
    std::cout<<" ]"<<std::endl;
}

bool ADT::add(int element)
{
    if(this->length < this->size)
    {
        ptr[this->length++] = element;
        this->display();
        return true;
    }
    else
    {
        std::cerr<<"No Space in the array.\n";
        return false;
    }
}

bool ADT::insert(int element , size_t index)
{
    if(this->length < this->size)
    {
        for (size_t i = length++; i > index; --i)
        {
            ptr[i] = ptr[i-1];
        }
        ptr[index] = element;
        this->display();
        return true;
    }
    else
    {
        std::cerr<<"No Space in the array.\n";
        return false;
    }
}
bool ADT::insert(int element)
{
    if(this->length < this->size)
    {   
        this->bubble_sort();
        size_t i {length++ -1};
        while (ptr[i]>element)
        {
            ptr[i+1] = ptr[i];
            i--;
        }
        ptr[++i] = element;     
        this->display();
        return true;
    }
    else
    {
        std::cerr<<"No Space in the array.\n";
        return false;
    }
}

bool ADT::del(size_t index)
{
    if(index >= this->length)
    {
        std::cerr<<"Invalid index\n";
        return false;
    }
    else
    {
        for (size_t i = index; i < this->length; ++i)
        {
            ptr[i] = ptr[i+1];
        }
        ptr[this->length--] = 0;
        this->display();
        return true;
    }
    
}

bool ADT::swap(size_t index1, size_t index2)
{
    if(index1<= this-> length && index2 <= this-> length)
    {
        if(index2 == index1)
            return true;
        else
        {
            int temp = ptr[index1];
            ptr[index1] = ptr[index2];
            ptr[index2] = temp;
            return true;
        }
    }
    else
        return false;
}

bool ADT::lin_search(int key)
{
    for (size_t i = 0; i < this->length; ++i)
    {
        if (key == ptr[i])
        {
            std::cout<<"Element "<<key<<" found at the index "<<i<<std::endl;
            if(i != 0)
            {
                std::cout<<"For optimization:"<<std::endl;
                std::cout<<"Enter 1 for transposition.\nEnter 2 for Move to head\n\nPRESS ANY KEY TO EXIT OPTIMIZATION\n"<<std::endl;
                char choice{};
                std::cin>>choice;
                if(choice=='1')
                    this->swap(i-1,i);
                else if (choice == '2')
                    this->swap(0,i);
                this->display();
            }
            return true;
        }
        
    }
    std::cout<<"Element "<<key<<" was not found "<<std::endl;
    return false;
}

bool ADT::binary_search(int key)
{
    size_t lower_bound {0}, upper_bound {this->length-1};
    while (lower_bound <= upper_bound)
    {
        size_t mid = (lower_bound + upper_bound)/2;
        if(key == ptr[mid])
        {
            std::cout<<"Element "<<key<<" found at the index "<<mid<<std::endl;
            return true;
        }
        else if(key > ptr[mid])
            lower_bound = mid + 1;
        else if(key < ptr[mid])
            upper_bound = mid -1;
    }
    std::cout<<"Element "<<key<<" was not found "<<std::endl;
    return false;
    /*
    // recursssion 
    if(lower_bound <= upper_bound)
    {
        if(ptr[mid] == key)
        {
            std::cout<<"Element "<<key<<" found at the index "<<mid<<std::endl;
            return true; 
        }
        elseif(key < ptr[mid])
            return binary_sort(lower_bound, mid - 1 ,key);
        elseif(key > ptr[mid])
            return binary_sort(mid +1 , upper_bound,key);
    }
    else 
        return false;
    */
}
