#include <iostream>
#include <cstdlib>
using namespace std;
template<class T>
struct Node
{
    Node*next;
    T d;
};
template<class T>
class CircularLinkedList
{
private:
    Node<T>*cursor;
public:
    CircularLinkedList();
    void add(T d);
    T front();
    T back();
    void advance();
    void remove();
    void print();
};
template<class T>
CircularLinkedList<T>::CircularLinkedList()
{
    cursor=NULL;
}
template<class T>
void CircularLinkedList<T>::add(T d)
{
    Node<T>*temp=new Node<T>;
    temp->d=d;
    if(cursor==NULL)
    {
        cursor=temp;
        cursor->next=cursor;
    }
    else
    {
        Node<T>*temp2;
        temp2=cursor->next;
        cursor->next=temp;
        temp->next=temp2;
    }
}
template<class T>
T CircularLinkedList<T>::front()
{
    if(cursor!=NULL)
    {
        return cursor->next->d;
    }
    else
    {
        cout<<"Error...."<<endl;
        cout<<"Terminating..."<<endl;
        exit(-1);
    }
}
template<class T>
T CircularLinkedList<T>::back()
{
    if(cursor!=NULL)
    {
        return cursor->d;
    }
    else
    {
        cout<<"Error...."<<endl;
        cout<<"Terminating..."<<endl;
        exit(-1);
    }

}
template<class T>
void CircularLinkedList<T>::advance()
{
    if(cursor!=NULL)
    {
        cursor=cursor->next;
    }
}
template<class T>
void CircularLinkedList<T>::remove()
{
    if(cursor!=NULL)
    {
        if(cursor->next==cursor)
        {
            delete cursor;
            cursor=NULL;
        }
        else
        {
            Node<T>*temp=cursor->next->next;
            Node<T>*temp2=cursor->next;
            cursor->next=temp;
            delete temp2;
            temp2=NULL;
        }
    }
}
template<class T>
void CircularLinkedList<T>::print()
{
    if(cursor!=NULL)
    {
        Node<T>*temp=cursor->next;
        do
        {
            cout<<temp->d<<"->";
            temp=temp->next;
        }
        while(temp!=cursor->next);
    }
}
void Test1()
{
    CircularLinkedList<int> C;
    C.add(9);
    C.add(123);
    C.add(2345);
    C.add(1);
    for(int i=0;i<10000;i++)
    {
        C.add(i);
    }
    C.remove();
    C.remove();
    C.print();
}
void Test2()
{
    CircularLinkedList<int> C2;
    C2.remove();
    C2.add(123);
    C2.print();
    C2.advance();
    C2.print();
    cout<<C2.front()<<endl;
    cout<<C2.back()<<endl;
    C2.add(1);
    cout<<C2.front()<<endl;
    cout<<C2.back()<<endl;

}
int main()
{

    return 0;
}
