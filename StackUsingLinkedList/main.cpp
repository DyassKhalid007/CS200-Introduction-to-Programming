#include <iostream>
using namespace std;
template<class T>
struct Node
{
    Node*next;
    T data;
};
template<class T>
class ST
{
private:
    Node<T>*head;
    int size;
    int index;
public:
    ST();
    ST(int s);
    void pushB(T d);
    T top();
    void pop();
    bool isEmpty()const;
    ST(const ST<T>&S);
    ~ST();
    void print();
};
template<class T>
ST<T>::ST()
{
    head=NULL;
    size=10;
    index=size;
}
template<class T>
ST<T>::ST(int s)
{
    head=NULL;
    size=s;
    index=size;
}
template<class T>
void ST<T>::pushB(T d)
{
    if(index>0)
    {
        if(head==NULL)
        {
            head=new Node<T>;
            head->next=NULL;
            head->data=d;
        }
        else
        {
            Node<T>*temp=new Node<T>;
            temp->data=d;
            temp->next=head;
            head=temp;
        }
        index--;
    }
    else
    {
        cout<<"Stack is full"<<endl;
    }
}
template<class T>
T ST<T>::top()
{
    if(head!=NULL&&index!=size)
    {
        return head->data;

    }
}
template<class T>
void ST<T>::pop()
{
    if(head!=NULL&&index!=size)
    {
        Node<T>*temp=head;
        head=head->next;
        delete temp;
        temp=NULL;
        index++;
    }
}
template<class T>
bool ST<T>::isEmpty()const
{
    if(head!=NULL&&size!=index)
    {
        return false;
    }
    else
    {
        return true;
    }
}
template<class T>
ST<T>::ST(const ST<T>&S)
{
    if(S.head!=NULL)
    {
        size=S.size;
        index=S.index;
        ST<T> tempS(size);
        tempS.index=index;
        while(!S.isEmpty())
        {
            tempS.pushB(S.top());
            S.pop();
        }
        tempS.print();
    }


}
template<class T>
ST<T>::~ST()
{
    if(head!=NULL)
    {
        Node<T>*temp=head;
        while(head!=NULL)
        {
            head=head->next;
            delete temp;
            temp=head;
        }
        delete head;
        head=NULL;
    }
}

template<class T>
void ST<T>::print()
{
    if(head!=NULL)
    {
        Node<T>*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
    }
    else
    {
        cout<<"Stack is empty"<<endl;
    }
}



void TestStackList()
{
    ST<double> S(100);
    for(int i=0;i<=10;i++)
    {
        S.pushB(i);

    }
    ST<double>SS;
    SS=S;

   // cout<<S.top()<<endl;
}
int main()
{
    TestStackList();
}
