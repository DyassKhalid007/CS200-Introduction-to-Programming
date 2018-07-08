#include <iostream>
#include <cstdlib>
using namespace std;
typedef int Data;
struct Node
{
    Node*left;
    Node*right;
    Data d;
};
class BST
{
private:

public:
    Node*root;
    BST();
    BST(Node*temp,Data d);
    Node*insert(Node*temp,Data d);
    Node*search(Node*temp,Data d);
    Node*findMin(Node*temp);
    Node*findMax(Node*temp);
    Node* deleteN(Node*temp,Data d);
    int height(Node*temp);
};
BST::BST()
{

    root=NULL;


}
BST::BST(Node*temp,Data d)
{
    root=NULL;
    if(root==NULL)
    {
        root=new Node;
        root->left=root->right=NULL;
        root->d=d;
       // cout<<root->d<<endl;
    }
}
Node*BST::insert(Node*temp,Data d)
{
    if(temp==NULL)
    {
       Node*newN=new Node;
       newN->left=newN->right=NULL;
       newN->d=d;
       return newN;
    }
    else
    {
        if(d>temp->d)
        {
            temp->right=insert(temp->right,d);
        }
        else if(d<temp->d)
        {
            temp->left=insert(temp->left,d);
        }
    }
}
Node*BST::search(Node*temp,Data d)
{
    if(temp==NULL)
    {
        return temp;
    }
    if(temp->d==d)
    {
        return temp;
    }
    else if(d>temp->d)
    {
        search(temp->right,d);
    }
    else if(d<temp->d)
    {
        search(temp->left,d);
    }
}
Node*BST::findMin(Node*temp)
{
    if(temp->left==NULL)
    {
        return temp;
    }
    else
    {
        findMin(temp->left);
    }

}
Node*BST::findMax(Node*temp)
{
    if(temp->right==NULL)
    {
        return temp;
    }
    else
    {
        findMax(temp->right);
    }
}
Node*BST::deleteN(Node*temp,Data d)
{
    if(temp==NULL)
    {
        return temp;
    }
    else if(d>temp->d)
    {
        temp->right=deleteN(temp->right,d);
    }
    else if(d<temp->d)
    {
        temp->left=deleteN(temp->left,d);
    }
    else
    {
        if(temp->left==NULL&&temp->right==NULL)
        {
            delete temp;
            temp=NULL;
            return temp;
        }
        else if(temp->left==NULL)
        {
            Node*temp2=temp;
            temp=temp->right;
            delete temp2;
            return temp;
        }
        else if(temp->right==NULL)
        {
            Node*temp2=temp;
            temp=temp->left;
            delete temp2;
            return temp;
        }
        else
        {
            Node*temp2=findMax(temp->right);
            temp->d=temp2->d;
            temp->right=deleteN(temp->right,temp2->d);
        }
    }
}
int BST::height(Node*temp)
{
    if(temp==NULL)
    {
        return -1;
    }
    return max(height(temp->left),height(temp->right))+1;
}
void printPreorder(Node*temp)
{

    if(temp!=NULL)
    {
        cout<<temp->d<<"->";
        printPreorder(temp->left);
        printPreorder(temp->right);
    }
}

int main()
{
    Node*t;
    BST B(t,9);
    Node*temp=B.root;
    B.insert(temp,99);
    B.insert(temp,-5689);
    for(int i=0;i<50;i++)
    {
        B.insert(temp,i);
    }
    temp=B.findMin(temp);
    cout<<temp->d<<endl;
    temp=B.root;
    //cout<<temp->d<<endl;
    B.deleteN(temp,33);
    printPreorder(temp);
    cout<<endl;
    cout<<B.height(temp)<<endl;

    return 0;
}
