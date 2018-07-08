#include <iostream>
#include <cstdlib>
using namespace std;
template<class T>
class ST
{
private:
    T *p;
    int size;
    int index;
public:
    ST();
    ST(int s);
    void pushB(T data);
    T top();
    void pop();
    void print();
};
template<class T>
ST<T>::ST()
{

    size=10;
    index=size;
    p=new int[size];
}
template<class T>
ST<T>::ST(int s)
{
   if(s>0)
   {
        size=s;
        index=size;
        p=new int[size];
   }
   else
   {
       cout<<"Error, Size cannot be negative."<<endl;
       cout<<"Terminating..."<<endl;
       exit(-1);
   }

}
template<class T>
void ST<T>::pushB(T data)
{
    //cout<<"Index:"<<index<<endl;
    if(index>0)
    {
        //cout<<"I:"<<index<<endl;
        index=index-1;
        //cout<<"Index:"<<index<<endl;
        p[index]=data;
        //index=index-1;
    }
    else
    {

        cout<<"Stack is filled"<<endl;
    }

}
template<class T>
T ST<T>::top()
{
    if(size!=index)
    {
        return p[index];
    }
    cout<<"Stack is empty,cannot return anything terminating..."<<endl;
    exit(-1);

}
template<class T>
void ST<T>::pop()
{
    if(index!=size)
    {
        index++;
    }
}
template<class T>
void ST<T>::print()
{
    if(p!=NULL)
    {
        //cout<<"index:"<<index<<endl;
        for(int i=index;i<size;i++)
        {

            cout<<p[i]<<endl;
        }
    }
}

void TestStackArrays()
{
     ST<int> S;
    for(int i=0;i<2;i++)
    {
        S.pushB(i);
    }
    //cout<<S.top()<<endl;
    S.pop();
    S.pop();
    S.print();
    S.pushB(999);
    S.print();
    cout<<S.top()<<endl;
    S.pop();
    //cout<<"Elements have been added"<<endl;
}
int main()
{
    TestStackArrays();
    return 0;
}
