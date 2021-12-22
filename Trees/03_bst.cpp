#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  Node *lchild;
  int data;
  Node *rchild;
  Node(int data) : data{data}, lchild{nullptr}, rchild{nullptr}
  {
    ;
  }
};

class Tree
{
private:
  Node *root;

public:
  Tree();
  ~Tree();
  void createTree();
  bool search(Node *root, int key);
  void insert(int key);
  Node *insert(Node *root, int key);
  void del(int key);
  Node *del(Node *root, int key);
  int floor(Node *root, int key);
  int ceil(Node *root, int key);
};

int Tree::floor(Node *root, int key)
{
  Node *curr = this->root, *prev{nullptr};
  while (curr)
  {
    if (curr->data == key)
      return curr->data;
    if (curr->data > key)
      curr = curr->lchild;
    else if (curr->data < key)
    {
      prev = curr;
      curr = curr->rchild;
    }
  }
  return prev ? prev->data : INT32_MIN;
}
int Tree::ceil(Node *root, int key)
{
  Node *curr = this->root, *prev{nullptr};
  while (curr)
  {
    if (curr->data == key)
      return curr->data;
    if (curr->data < key)
      curr = curr->rchild;
    else if (curr->data > key)
    {
      prev = curr;
      curr = curr->lchild;
    }
  }
  return prev ? prev->data : INT32_MAX;
}

void Tree::insert(int key)
{
  Node *curr = this->root, *prev = nullptr;
  while (curr)
  {
    prev = curr;
    if (curr->data == key)
      return;
    if (curr->data > key)
      curr = curr->lchild;
    else if (curr->data < key)
      curr = curr->rchild;
  }
  curr = prev->data > key ? prev->lchild : prev->rchild;
  curr = new Node(key);
}
Node *Tree ::insert(Node *root, int key)
{
  if (root == nullptr)
    return new Node(key);
  if (root->data < key)
    root->rchild = insert(root->rchild, key);
  else if (root->data > key)
    root->lchild = insert(root->lchild, key);
  return root;
}

void Tree::del(int key)
{
  Node *curr{this->root}, *prev{nullptr};
  while (curr)
  {
    if (curr->data == key)
      break;
    prev = curr;
    if (curr->data > key)
      curr = curr->lchild;
    else if (curr->data < key)
      curr = curr->rchild;
  }
  if (curr == nullptr)
  {
    cerr << "Invalid key" << endl;
    return;
  }
  if (curr->rchild == nullptr)
  {
    root->data = largestLeft(curr)->data;
  }
  else if (curr->lchild == nullptr)
  {
    root->data = smallestRight(curr)->data;
  }
  else
  {
    delete curr;
    if (prev->data > key)
      prev->lchild = nullptr;
    else
      prev->rchild = nullptr;
  }
  delete curr;
}

Node *smallestRight(Node *node)
{
  Node *curr{node->rchild}, *prev{nullptr};
  while (curr->lchild)
  {
    prev = curr;
    curr = curr->lchild;
  }
  prev->lchild = nullptr;
  return curr;
}

Node *largestLeft(Node *node)
{
  Node *curr{node->rchild}, *prev{nullptr};
  while (curr->rchild)
  {
    prev = curr;
    curr = curr->rchild;
  }
  prev->rchild = nullptr;
  return curr;
}
Node *Tree::del(Node *root, int key)
{
  if (root == nullptr)
    return;
  if (root->data > key)
    root->lchild = del(root->lchild, key);
  else if (root->data < key)
    root->rchild = del(root->rchild, key);
  else
  {
    if (root->lchild == nullptr)
    {
      Node *temp = root->rchild;
      delete root;
      return temp;
    }
    if (root->rchild == nullptr)
    {
      Node *temp = root->lchild;
      delete root;
      return temp;
    }
    Node *temp = getSuccessor(root);
    root->data = temp->data;
    root->rchild = del(root->rchild, temp->data);
  }
  return this->root;
}

Node *getSuccessor(Node *curr)
{
  curr = curr->rchild;
  while (curr && curr->lchild)
    curr = curr->lchild;
  return curr;
}