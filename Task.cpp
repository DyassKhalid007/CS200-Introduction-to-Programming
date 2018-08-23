//doubly linked list
#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node*next;
  Node*prev;
};
class DLL
{
private:
  Node*head;
public:
  DLL();
  DLL(int d);
  Node*getNode(int d);
  void insert(int d);
  void print();
  void reverse_print();
  bool isPresent(int d);
  void clear();
  Node*getHead();
  void remove(int d);
  void reverse();
  DLL&operator=(DLL&D);//assignment operator overloading
  bool isEmpty();
  void swap(Node *a,Node*b);
  ~DLL();
};
DLL::DLL()
{
  head = NULL;
}
DLL::DLL(int d)
{
  head = getNode(d);
}
Node*DLL::getNode(int d)
{
  Node*temp = new Node;
  temp->data = d;
  temp->next = NULL;
  temp->prev = NULL;
  return temp;
}
void DLL::insert(int d)
{
  if(!head)
  {
    head = getNode(d);
  }
  else if(!head->next)
  {
    Node*temp = getNode(d);
    head->next = temp;
    temp->prev = head;
  }
  else
  {
    Node*temp = head;
    while(temp->next)
    {
      temp = temp->next;
    }
    Node*temp2 = getNode(d);
    temp->next = temp2;
    temp2->prev = temp;
  }
}
void DLL::print()
{
  if(head)
  {
    Node*temp = head;
    while(temp)
    {
      cout<<temp->data<<"->";
      temp = temp->next;
    }
  }
}
void DLL::reverse_print()
{
  if(head)
  {
    Node*temp = head;
    while(temp->next)
    {
      temp = temp->next;
    }
    //Last node is reached
    //Now using prev
    while(temp)
    {
      cout<<temp->data<<"->";
      temp = temp->prev;
    }

  }
}
bool DLL::isPresent(int d)
{
  Node*temp = head;
  while(temp)
  {
    if(temp->data == d)
    {
      return true;
    }
    temp = temp->next;
  }
  return false;
}
Node*DLL::getHead()
{
  return head;
}
DLL &DLL::operator =(DLL&D)
{
  if(this == &D)
  {
    return *this;
  }
  this->clear();
  Node*temp = D.getHead();
  while(temp)
  {
    this->insert(temp->data);
    temp = temp->next;
  }
}
void DLL::clear()
{
  Node*temp = head;
  while(temp)
  {
    temp = temp->next;
    delete head;
    head = temp;
  }
  head = NULL;
}
DLL::~DLL()
{
  clear();
}
void DLL::remove(int d)
{
  if(isPresent(d))
  {
    if(head->data==d&&head->next)
    {
      Node*temp = head;
      temp = temp->next;
      delete head;
      temp->prev = NULL;
      head = temp;
    }
    else if(head->data==d&&!head->next)
    {
      delete head;
      head = NULL;
    }
    else
    {
      Node*temp = head;
      while(true)
      {
        if(temp->data == d)
        {
          break;
        }
        temp = temp->next;
      }
      if(!temp->next)
      {
        Node*temp2 = temp;
        temp2 = temp2->prev;
        temp2->next = NULL;
        delete temp;
      }
      else
      {
        Node*temp2 = temp->prev;
        Node*temp3 = temp->next;
        temp2->next = temp3;
        temp3->prev = temp2;
      }
    }
  }
}
bool DLL::isEmpty()
{
  if(head)
  {
    return false;
  }
  return true;
}
void DLL::reverse()
{
  if(head)
  {
    Node*temp = head;
    Node*temp2 =head;
    while(temp2->next)
    {
      temp2 = temp2->next;
      Node*temp3 = temp->next;
      temp->next = temp->prev;
      temp->prev = temp3;
      // swap(temp->next,temp->prev);
      temp = temp2;
    }
    // swap(temp2->next,temp2->prev)
    Node*temp3 = temp2->next;
    temp2->next = temp2->prev;
    temp2->prev = temp3;
    head = temp2;
  }
}
void DLL::swap(Node*a,Node*b)
{
  Node*temp = a;
  a = b;
  b = temp;
}

int main()
{
  DLL D;
  for(int i=0;i<1000;i++)
  {
    D.insert(i);
  }
  // cout<<D.isPresent(1000)<<endl;
  // D.clear();
  // D.reverse_print();
  D.reverse();
  D.print();
  return 0;
}
