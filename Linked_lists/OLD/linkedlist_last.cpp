#include<iostream>

class Node
{
public:
    int data;
    Node* next;
    Node(int data = 0);
    ~Node();

};

Node::Node(int data): data(data), next(nullptr)
{
    std::cout<<"New node created with data: "<<this->data<<std::endl;
}

Node::~Node()
{
    std::cout<<"Deleting the Node"<<std::endl;
}

class linkedlist
{
public:
    Node* first;
    Node* last;
    size_t count;
    linkedlist();
    bool add_node(int data);
    ~linkedlist();
    void display();
    bool insert(size_t index,Node& node);
    bool insert(Node& node);
    bool ass_insert(Node& node);
    bool del(size_t pos);
    bool is_sorted();
    size_t rm_dup();
    bool reverse();
    void reverse_recur(Node* ptr1, Node* ptr2);
    linkedlist concatenate(linkedlist& list);

};


linkedlist::linkedlist():first{nullptr}, last{nullptr}, count(0)
{
}

linkedlist linkedlist::concatenate(linkedlist& list)
{
    linkedlist conc_list;
    Node* i_ptr{this->first};
    for (size_t i = 0 ; i < this->count; i++)
    {
        conc_list.insert(*i_ptr);
        i_ptr = i_ptr->next;
    }
    i_ptr = {list.first};
    for (size_t i = 0 ; i < list.count; i++)
    {
        conc_list.insert(*i_ptr);
        i_ptr = i_ptr->next;
    }
    conc_list.first = this->first;
    conc_list.last = this->last;
    return conc_list;
}



void linkedlist::reverse_recur(Node* ptr1, Node* ptr2)
{
    if (ptr1)
    {
        reverse_recur(ptr1->next,ptr1);
        ptr1->next = ptr2;
    }
    else
    {
        auto temp {this->first};
        this->first = this->last;
        this->last = temp;
    }
    
}


bool linkedlist::reverse()
{
    // Node* ptr1{first};
    // Node* ptr2{ptr1->next};
    // Node* ptr3{ptr2->next};
    // if (this->count <= 1)
    // {
    //     return true;
    // }
    // ptr1->next = nullptr;
    // while (ptr2->next != nullptr )
    // {
    //     ptr2->next = ptr1;
    //     ptr1 = ptr3;
    //     if (ptr3 != nullptr)
    //     {
    //         ptr2 = ptr3->next;
    //         ptr3 = ptr2->next;
    //     }
    //     else
    //     {
    //         ptr2 = nullptr;
    //         break;
    //     }
    // }
    // Node* t_ptr{this->last};
    // this->last = this->first;
    // this->first = this->last;
    // return true;

    Node* ptr1{first};
    Node* ptr2{nullptr};
    Node* ptr3{nullptr};
    while (ptr1)
    {
        ptr3 = ptr2;
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }
    Node* t_ptr{this->last};
    this->last = this->first;
    this->first = this->last;
    return true;
}

size_t linkedlist::rm_dup()
{
    size_t dup_count {0};
    Node* ptr2{first};
    Node* ptr1{first->next};
    while (ptr1)
    {
        if (ptr1->data == ptr2->data)
        {
            ptr2 = ptr1->next;
            ptr1->~Node();
            this->count--;
            ptr1 = ptr2->next;
            dup_count++;
        }
        else
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }  
    }
    return dup_count;
}

bool linkedlist::is_sorted()
{
    Node* ptr2{first};
    Node* ptr1{first->next};
    for (size_t i = 0; i < this->count-1; i++)
    {
        if (ptr1->data < ptr2->data)
        {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return true;

    // // More effecient code.
    //     Node* ptr{first};
    //     int data = ptr->data;
    //     ptr = ptr->next;
    //     while (ptr)
    //     {
    //         if (ptr->data < data)
    //         {
    //             return false;
    //         }
    //         data = ptr->data;
    //         ptr = ptr->next;
    //     }
    //     return true;
    
}
bool linkedlist::del(size_t pos)
{
    if (pos < this->count)
    {
            if(pos == 0)
        {
            Node* ptr {this->first};
            this->first = this->first->next;
            ptr->~Node();
        }
        else
        {
            Node* ptr1 {first};
            for (size_t i = 0; i < pos; ++i)
            {
                ptr1 = ptr1->next;
            }
            Node* ptr2 {ptr2->next};
            ptr1 ->next = ptr2->next;
            ptr2 ->~Node();
        }
        return true;
    }
    return false;
}

void linkedlist::display()
{
    Node* ptr {first};
    for (size_t i = 0; i < count; i++)
    {
        std::cout<<"[ "<<ptr->data<<" ]"<<std::endl;
        ptr = ptr->next;
    }
}

bool linkedlist::ass_insert(Node& node)
{
    Node* ptr {first};
    int min {first->data};
    while (ptr->next && ptr->next->data < node.data)
    {
        ptr = ptr->next;
    }
    if (!ptr->next)
    {
        if (ptr->data < node.data)
        {
            ptr->next = &node;
            last = &node;
        }
        else
        {
            node.next = ptr;
            first = &node;
        }
        count ++;
        return true;
    }
    else
    {
        node.next = ptr->next;
        ptr->next = &node;
        count++;
        return true;
    }
    
}

bool linkedlist::insert(size_t index,Node& node)
{
    if(index == 0)
    {
        first = &node;
        last = first;
    }
    else
    {
        Node* ptr {first};
        for(size_t i{}; i < index - 1; ++i)
        {
            ptr = ptr->next;
        }
        node.next = ptr->next;
        ptr->next = &node;
    }
    count++;
    return true;
}

bool linkedlist::insert(Node& node)
{
    if(last == nullptr && first == nullptr)
    {
        first = &node;
        last = first;
    }
    else
    {
        last->next = &node;
        last = &node;
    }
    count++;
    return true;
}

bool linkedlist::add_node(int data)
{
    if(last==nullptr && first== nullptr)
    {
        first = new Node(data);
        last = first;
        count++;
    }
    else
    {
        last->next = new Node(data);
        last = last->next;
        count++;
    }
    return true;
}

linkedlist::~linkedlist()
{
}

int main ()
{
    linkedlist ll;
    Node n1(1);
    ll.insert(n1);
    ll.add_node(5);
    ll.add_node(6);
    ll.add_node(9);
    Node n2(2);
    ll.ass_insert(n2);
    ll.display();
    return 0;
}