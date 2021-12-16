#include<iostream>

class Node
{
public:
    int data;
    Node* next;
    size_t count;
    Node* last_ptr();
    Node(int data);
    size_t search(int key);
    size_t display();
    int display_r();
    bool add_node(int data);
    int sum();
    ~Node();
    int min();
    bool move_to_head(int key, Node*& head);
    bool insert(size_t index, Node& node, Node*& head);
};

Node* Node::last_ptr()
{
    Node* ptr {this};
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    return ptr;
}

bool Node::insert(size_t index, Node& node, Node*& head)
{
    if(index == 0)
    {
        node.next = head;
        head = &node;
    }
    else
    {
        Node* ptr {head};
        for(size_t i{}; i < index - 1; ++i)
        {
            ptr = ptr->next;
        }
        node.next = ptr->next;
        ptr->next = &node;
    }
    return true;
}


bool Node::move_to_head(int key, Node*& head)
{
    size_t pos = search(key);
    if (!pos)
    {
        return false;
    }
    else
    {
        Node* ptr {this};
        for (size_t i {0}; i < pos-2; ++i)
        {
            ptr = ptr->next;
        }
        Node* node_ptr {ptr->next};
        ptr->next = node_ptr->next;
        node_ptr->next = head;
        head = node_ptr;
    }
    return true;
}


size_t Node::search(int key)
{
    size_t pos {0};
    Node* ptr {this};
    while (ptr)
    {
        if(ptr->data == key )
        {
            return ++pos;
        }
        else
        {
            ptr = ptr->next;
            pos++;
        }
    }
    return 0;
}

int Node::min()
{
    Node* ptr {this};
    int min = ptr->data;
    while (ptr)
    {
        if(ptr->data < min )
        {
            min = ptr->data;
        }
        ptr = ptr->next;
    }
    return min;
}

int Node::sum()
{
    Node* ptr {this};
    int sum {};
    while (ptr)
    {
        sum += ptr->data;
        ptr = ptr->next;
    }
    return sum;
}

int Node::display_r()
{
    Node* ptr {this};
    if(ptr == nullptr)
        return 0;
    else
    {
        std::cout<<" . Element is: "<<ptr->data<<std::endl;
        return ptr->next->display_r() + 1;
    }
}
size_t Node::display()
{
    size_t pos {0};
    Node* ptr {this};
    while (ptr)
    {
        std::cout<<++pos<<" . Element is: "<<ptr->data<<std::endl;
        ptr = ptr->next;
    }
    return pos;
}

bool Node::add_node(int data)
{
    Node* ptr {this};
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = new Node(data);
    return 1;
}

Node::Node(int data): data(data), next(nullptr), count(0)
{
    std::cout<<"New node created with data: "<<this->data<<std::endl;
    std::cout<<"Address of the new node: "<<this<<std::endl;
    std::cout<<"Next is pointing to: "<<this->next<<std::endl;
    std::cout<<"Total number of elements is "<<++count<<std::endl;
}

Node::~Node()
{
    std::cout<<"Deleting the Node"<<std::endl;
    delete next;
}

int main()
{
    Node* head = new Node(10);
    head->add_node(20);
    head->add_node(30);
    head->add_node(-10);
    Node insertion(50);
    Node* last = head->last_ptr();
    head->insert(3,insertion,head);
    std::cout<<head->display()<<" Number of elements in the Linked List"<<std::endl;
    return 0;
}