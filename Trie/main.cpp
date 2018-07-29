#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

const int ALPHABETS=26;
struct Trie
{
    Trie*childern[ALPHABETS];
    bool isEndOfWorld;
};
Trie* getNode()
{
    Trie* pNode=new Trie;
    pNode->isEndOfWorld=false;
    for(int i=0;i<ALPHABETS;i++)
    {
        pNode->childern[i]=NULL;
    }
    return pNode;
}
void insert(Trie*root,string key)
{
    Trie*newT=root;
    for(int i=0;i<key.length();i++)
    {
        int index=key[i]-'a';
        if(newT->childern[index]==NULL)
        {
            newT->childern[index]=getNode();
        }
        newT=newT->childern[index];
    }
    newT->isEndOfWorld=true;
}
bool search(Trie*root,string key)
{
    Trie*newT=root;
    for(int i=0;i<key.length();i++)
    {
        int index=key[i]-'a';
        if(newT->childern==NULL)
        {
            return false;
        }
        newT=newT->childern[index];
    }
    return(newT!=NULL&&newT->isEndOfWorld);
}
void free_all(Trie* curs)
{
    int i;
    if(!curs) return;   // safe guard including root node.

    // recursive case (go to end of trie)
    for (i = 0; i < ALPHABETS; i++)
       free_all(curs->childern[i]);


    // base case
    delete(curs);
}



int main()
{
    string word;
    ifstream infile;
    int i=0;
    infile.open("A2.txt");
    if (!infile)
    {
    cerr << "Unable to open file dictionary.txt";
    exit(1);   // call system to stop
    }
    Trie*root=getNode();
    while(infile>>word)
    {
        cout<<word<<endl;
        insert(root,word);
    }
    while(1)//infinite loop for searching
    {
        cout<<"Please enter your word:";
        cin>>word;
        cout<<search(root,word)<<endl;

    }
    free_all(root);




}



