#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  Node *left;
  Node *right;
  int data;
  Node(int data) : data{data}, left{nullptr}, right{nullptr}
  {
    ;
  }
};

class Tree
{
public:
  Node *root;
  Tree(/* args */) : root{nullptr}
  {
    int x;
    cout << "Enter root data: " << flush;
    cin >> x;
    root = new Node(x);
    queue<Node *> q;
    q.emplace(root);
    Node *ptr;
    while (!q.empty())
    {
      ptr = q.front();
      q.pop();
      cout << "Is there a left child for " << ptr->data << " [0/1]: " << flush;
      bool flag{false};
      cin >> flag;
      if (flag)
      {
        cout << "Enter left child data of " << ptr->data << ": " << flush;
        cin >> x;
        ptr->left = new Node(x);
        q.emplace(ptr->left);
      }
      cout << "Is there a right child for " << ptr->data << " [0/1]: " << flush;
      bool flag{false};
      cin >> flag;
      if (flag)
      {
        cout << "Enter right child data of " << ptr->data << ": " << flush;
        cin >> x;
        ptr->right = new Node(x);
        q.emplace(ptr->right);
      }
    }
  }

  void preorder_r(Node *root)
  {
    if (root)
    {
      cout << root->data << " ";
      preorder_r(root->left);
      preorder_r(root->right);
    }
  }
  void preorder()
  {
    // preorder_r(root);
    stack<Node *> st;
    st.push(this->root);
    Node *curr{this->root};

    while (true)
    {
      while (curr)
      {
        cout << curr->data << " " << flush;
        st.push(curr);
        curr = curr->left;
      }
      if (st.empty())
        break;
      curr = st.top()->right;
      st.pop();
    }
  }
  void preorderGFG()
  {
    if (this->root == nullptr)
      return;
    stack<Node *> st;
    st.push(this->root);
    Node *curr{this->root};
    while (!st.empty())
    {
      cout << curr->data << " " << flush;
      st.pop();
      if (curr->right)
        st.push(curr->right);
      if (curr->left)
        st.push(curr->left);
    }
  }
  void preorderGFG2()
  {
    if (this->root == nullptr)
      return;
    stack<Node *> st;
    st.push(this->root);
    Node *curr{this->root};
    while (!st.empty() or curr)
    {
      while (curr)
      {
        cout << curr->data << " " << flush;
        if (curr->right)
          st.push(curr->right);
        curr = curr->left;
      }
      curr = st.top();
      st.pop();
    }
  }

  void inorder_r(Node *root)
  {
    if (root)
    {
      inorder_r(root->left);
      cout << root->data << " ";
      inorder_r(root->right);
    }
  }
  void inorder()
  {
    stack<Node *> st;
    st.push(this->root);
    Node *curr{this->root};
    while (true) // or curr != nullptr or st.empty() != true
    {
      while (curr)
      {
        st.push(curr);
        curr = curr->left;
      }
      if (st.empty())
        break;
      curr = st.top();
      st.pop();
      cout << curr->data << " " << flush;
      curr = curr->right;
    }
  }

  void postorder_r(Node *root)
  {
    if (root)
    {
      postorder_r(root->left);
      postorder_r(root->right);
      cout << root->data << " ";
    }
  }
  void postorder()
  {
    stack<Node *> st;
    stack<Node *> stRo;

    st.push(this->root);
    Node *curr{this->root};
    while ((!st.empty() or curr))
    {
      while (curr)
      {
        st.push(curr);
        curr = curr->left;
      }
      curr = st.top();
      st.pop();
      cout << curr->data << " " << flush;
      if (curr->right)
      {
        stRo.push(curr);
        curr = curr->right;
        continue;
      }
      if (!stRo.empty())
      {
        cout << stRo.top()->data << " " << flush;
        stRo.pop();
      }
    }
  }

  void levelorder(Node *root)
  {
    queue<Node *> q;
    q.emplace(root);
  }
  void levelorder()
  {
    // levelorder(root);
    queue<Node *> q;
    q.emplace(this->root);
    Node *curr_ptr = nullptr;
    while (!q.empty())
    {
      curr_ptr = q.front();
      q.pop();
      if (curr_ptr)
      {
        cout << curr_ptr->data << " ";
        q.emplace(curr_ptr->left);
        q.emplace(curr_ptr->right);
      }
    }
  }
};
