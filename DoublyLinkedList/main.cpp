#include <iostream>
using namespace std;
template<class T>
struct Node
{
    Node*head;
    Node*tail;
    T d;
};
template<class T>
class DoublyLinkedList
{
private:
    Node<T>*linkF;//front
    Node<T>*linkB;//back
public:
    DoublyLinkedList();
    DoublyLinkedList(T d);
    void AddF(T d);
    void AddB(T d);
    void show();
    bool isEmpty()const;
    T FrontElement();
    T BackElement();
    ~DoublyLinkedList();
};
template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    linkB=new Node<T>;
    linkF=new Node<T>;
    linkF->head=linkB;
    linkF->tail=NULL;
    linkB->tail=linkF;
    linkB->head=NULL;
}
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(T d)
{
    linkB=new Node<T>;
    linkF=new Node<T>;
    linkF->head=linkB;
    linkF->tail=NULL;
    linkB->tail=linkF;
    linkB->head=NULL;
    Node<T>*temp=new Node<T>;
    temp->d=d;
    linkF->head=temp;
    linkB->tail=temp;
    temp->tail=linkF;
    temp->head=linkB;

}
template<class T>
void DoublyLinkedList<T>::AddF(T d)
{
    Node<T>*temp=linkF->head;
    Node<T>*temp2=new Node<T>;
    temp2->d=d;
    linkF->head=temp2;
    temp->tail=temp2;
    temp2->tail=linkF;
    temp2->head=temp;
}
template<class T>
void DoublyLinkedList<T>::AddB(T d)
{
    Node<T>*temp=linkB->tail;
    Node<T>*temp2=new Node<T>;
    temp->head=temp2;
    linkB->tail=temp2;
    temp2->tail=temp;
    temp2->head=linkB;
    temp2->d=d;

}
template<class T>
bool DoublyLinkedList<T>::isEmpty() const
{
    if(linkF->head==linkB)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template<class T>
T DoublyLinkedList<T>::FrontElement()
{
    return linkF->head->d;
}
template<class T>
T DoublyLinkedList<T>::BackElement()
{
    return linkB->tail->d;
}
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    if(linkF->head!=linkB)
    {
        Node<T>*temp=linkF;
        while(temp->head!=NULL)
        {
            temp=temp->head;
            delete linkF;
            linkF=temp;
        }
        delete linkB;
        delete linkF;
    }
}
template<class T>
void DoublyLinkedList<T>::show()
{
    if(linkF->head!=linkB)
    {
        Node<T>*temp=linkF->head;
        while(temp!=linkB)
        {
            cout<<temp->d<<"->";
            temp=temp->head;
        }
    }
}
int main()
{
    DoublyLinkedList<int> D;
    for(int i=0;i<=1000;i++)
    {
        D.AddB(i);
    }
    D.show();
    return 0;
}
