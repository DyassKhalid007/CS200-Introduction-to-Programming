#include <iostream>
using namespace std;
template<class T>
struct Node
{
    Node*next;
    T data;
};
template<class T>
class LinkedList
{
private:
    Node<T>*link;
public:
    LinkedList();
    LinkedList(T d);
    void InsertAtHead(T d);
    void InsertAtTail(T d);
    bool empty()const;
    T FrontElement();
    T BackElement();
    void DeleteFromFront();
    void DeleteFromBack();
    void show();
    void reverse();
    ~LinkedList();
};
template<class T>
LinkedList<T>::LinkedList()
{
    link=NULL;
}
template<class T>
LinkedList<T>::LinkedList(T d)
{
    link=new Node<T>;
    link->data=d;
    link->next=NULL;
}
template<class T>
void LinkedList<T>::InsertAtHead(T d)
{
    if(link==NULL)
    {
        link=new Node<T>;
        link->next=NULL;
        link->data=d;
    }
    else
    {
        Node<T>*temp=new Node<T>;
        temp->data=d;
        temp->next=link;
        link=temp;
    }
}
template<class T>
void LinkedList<T>::InsertAtTail(T d)
{
    if(link==NULL)
    {
        link=new Node<T>;
        link->data=d;
        link->next=NULL;
    }
    else
    {
        Node<T>*temp=link;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        Node<T>*temp2=new Node<T>;
        temp2->next=NULL;
        temp2->data=d;
        temp->next=temp2;
    }
}
template<class T>
bool LinkedList<T>::empty()const
{
    if(link==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template<class T>
T LinkedList<T>::FrontElement()
{
    return link->data;
}
template<class T>
T LinkedList<T>::BackElement()
{
    if(link!=NULL)
    {
        Node<T>*temp=link;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        return temp->data;
    }
}
template<class T>
void LinkedList<T>::DeleteFromFront()
{
    if(link!=NULL)
    {
        Node<T>*temp=link;
        link=link->next;
        delete temp;
        temp=NULL;
    }
}
template<class T>
void LinkedList<T>::DeleteFromBack()
{
    //cout<<"I entered the function"<<endl;
    if(link!=NULL)
    {
        //cout<<"I entered the first conditional"<<endl;

        if(link->next==NULL)
        {
            delete link;
            link=NULL;
        }
        else
        {

            Node<T>*temp=link->next;
            Node<T>*temp2=link;
            while(temp->next!=NULL)
            {
                temp=temp->next;
                temp2=temp2->next;
            }
            //cout<<"Value to be removed:"<<temp2->data<<endl;
            temp2->next=NULL;
            delete temp;
            temp=NULL;
        }
    }
}
template<class T>
void LinkedList<T>::show()
{
    if(link!=NULL)
    {
        Node<T>*temp=link;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
    }


}
template<class T>
void LinkedList<T>::reverse()
{
    if(link!=NULL)
    {
        if(link->next!=NULL)
        {
            Node<T>*temp=link;
            LinkedList<T> newL;
            while(!empty())
            {
                newL.InsertAtTail(BackElement());
                DeleteFromBack();

            }


            link=newL.link;

        }
    }
}
template<class T>
LinkedList<T>::~LinkedList()
{
    if(link!=NULL)
    {
        while(!empty())
        {
            DeleteFromFront();
        }
    }
}
void TestLinkedList()
{
    LinkedList<int> L;
    for(int i=0;i<5000;i++)
    {
        L.InsertAtHead(i);
    }
    L.show();
    cout<<endl;
    cout<<endl;
    L.reverse();
    L.show();

}
int main()
{
    TestLinkedList();
    return 0;
}
