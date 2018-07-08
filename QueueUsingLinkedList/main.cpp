#include <iostream>
using namespace std;
template<class T>
struct Node
{
    T data;
    Node*link;
};
template<class T>
class QT
{
private:
    Node<T>*front;
    Node<T>*back;
    int size;
public:
    QT();
    QT(T d);
    void enqueue(T d);
    void dequeue();
    int QTSize()const;
    bool isQTEmpty();
    T Felement();
    void print();
};
template<class T>
QT<T>::QT()
{
    size=0;
    front=back=NULL;
}
template<class T>
QT<T>::QT(T d)
{
    size=0;
    front=new Node<T>;
    front->data=d;
    front->link=NULL;
    front=back;
}
template<class T>
void QT<T>::enqueue(T d)
{
    size++;

    if(front==NULL&&back==NULL)
    {
        front=new Node<T>;
        front->data=d;
        front->link=NULL;
        back=front;
    }
    else
    {
        Node<T>*temp=new Node<T>;
        back->link=temp;
        temp->data=d;
        temp->link=NULL;
        back=temp;
    }
}
template<class T>
void QT<T>::dequeue()
{
    if(front!=NULL&&back!=NULL)
    {
        Node<T>*temp=front;
        front=front->link;
        delete temp;
        temp=NULL;
        size--;
    }
}
template<class T>
int QT<T>::QTSize()const
{
    return size;
}
template<class T>
bool QT<T>::isQTEmpty()
{
    if(front==NULL&&back==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template<class T>
T QT<T>::Felement()
{
    if(front!=NULL&&back!=NULL)
    {
        return front->data;
    }
}
template<class T>
void QT<T>::print()
{
    if(front!=NULL||back!=NULL)
    {
        Node<T>*temp=front;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->link;
        }
    }
}
void TestQT()
{
    QT<int> Q;
    for(int i=0;i<99;i++)
    {
        Q.enqueue(i);
    }
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.print();

}
int main()
{
    TestQT();
    return 0;
}
