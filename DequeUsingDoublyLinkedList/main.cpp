#include <iostream>
#include <cstdlib>
using namespace std;
template<class T>
struct Node
{
    Node*next;
    Node*previous;
    T data;
};
template<class T>
class DECK
{
private:
    Node<T>*front;
    Node<T>*back;
    int s;
public:
    DECK();
    void InsertAtFront(T d);
    void RemoveFromFront();
    T EFront();
    int size()const;
    void InsertAtBack(T d);
    void RemoveFromBack();
    T EBack();
    bool isEmpty()const;
    void print();
};
template<class T>
DECK<T>::DECK()
{
    s=0;
    front=new Node<T>;
    back=new Node<T>;
    front->next=back;
    back->next=NULL;
    front->previous=NULL;
    back->previous=front;
}
template<class T>
void DECK<T>::InsertAtFront(T d)
{
    s++;
    Node<T>*temp=new Node<T>;
    temp->data=d;
    if(front->next==back)
    {
        front->next=temp;
        temp->previous=front;
        temp->next=back;
        back->previous=temp;
    }
    else
    {
        Node<T>*temp2=front->next;
        front->next=temp;
        temp->previous=front;
        temp->next=temp2;
        temp2->previous=temp;
    }
}
template<class T>
void DECK<T>::RemoveFromFront()
{
    if(front->next!=back)
    {
        s--;
        Node<T>*temp=front->next;
        Node<T>*temp2=front->next->next;
        front->next=temp2;
        temp2->previous=front;
        delete temp;
        temp=NULL;
    }
}
template<class T>
T DECK<T>::EFront()
{
    if(front->next!=back)
    {
        return front->next->data;
    }
    else
    {
        cout<<"Error..."<<endl;
        cout<<"Terminating..."<<endl;
        exit(-1);
    }
}
template<class T>
void DECK<T>::print()
{
    if(front->next!=back)
    {
    Node<T>*temp=front->next;
    while(temp!=back)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    }
    else
    {
        cout<<"Deque is empty"<<endl;
    }
}
template<class T>
void DECK<T>::InsertAtBack(T d)
{
    s++;
    Node<T>*temp=new Node<T>;
    temp->data=d;
    if(front->next==back)
    {
        front->next=temp;
        temp->previous=front;
        temp->next=back;
        back->previous=temp;
    }
    else
    {
        Node<T>*temp2=back->previous;
        temp2->next=temp;
        temp->previous=temp2;
        temp->next=back;
        back->previous=temp;
    }
}
template<class T>
void DECK<T>::RemoveFromBack()
{
    if(front->next!=back)
    {
        s--;
        Node<T>*temp=back->previous;
        Node<T>*temp2=back->previous->previous;
        temp2->next=back;
        back->previous=temp2;
        delete temp;
        temp=NULL;
    }
}
template<class T>
T DECK<T>::EBack()
{
    if(front->next!=back)
    {
        return back->previous->data;
    }
    else
    {
        cout<<"Error..."<<endl;
        cout<<"Empty DEQUE..."<<endl;
        cout<<"Terminating..."<<endl;
    }
}
template<class T>
int DECK<T>::size()const
{
    return s;
}
template<class T>
bool DECK<T>::isEmpty()const
{
    if(front->next==back)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Test1()
{
    DECK<int> D;
    cout<<D.isEmpty()<<endl;
  for(int i=0;i<9;i++)
  {
      D.InsertAtFront(i);
  }
    cout<<D.size()<<endl;
    cout<<D.isEmpty()<<endl;
}
void Test2()
{
    DECK<int> D;
    D.InsertAtFront(9);
    D.InsertAtFront(99);
    D.InsertAtFront(123);
    D.RemoveFromFront();
    D.print();
    cout<<D.size()<<endl;

}
void Test3()
{
    DECK<int> D;
    D.InsertAtBack(99);
    D.InsertAtBack(123);
    D.InsertAtBack(123456);
    for(int i=0;i<1000;i++)
    {
        D.InsertAtBack(i);
    }
    D.print();
}
void Test4()
{
    DECK<int> D;
    D.InsertAtBack(99);
    D.RemoveFromBack();
    D.InsertAtBack(123);
    D.print();
    D.RemoveFromBack();
    for(int i=0;i<1000;i++)
    {
        D.InsertAtBack(i);
    }
    D.RemoveFromBack();
    D.RemoveFromBack();
    D.RemoveFromBack();
    D.RemoveFromFront();
    D.RemoveFromFront();
    D.RemoveFromFront();
    D.print();
    cout<<endl;
    cout<<D.EBack();
}
int main()
{
    Test4();
    return 0;
}
