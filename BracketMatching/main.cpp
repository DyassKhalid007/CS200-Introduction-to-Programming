#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
bool BMatching(vector<string>array)
{
    stack<char> s;
    for(int i=0;i<array.size();i++)
    {
        if(array[i]=='('||array[i]=='['||array[i]=='{')
            {
                s.push(array[i]);
            }
            else if(array[i]==')'||array[i]==']'||array[i]=='}')
            {
                if(s.empty())
                {
                    return true;
                }
                if(s.top()=='('&&array[i]==')')
                {
                    s.pop();
                }
                else if(s.top()=='['&&array[i]==']')
                {
                    s.pop();
                }
                else if(s.top()=='{'&&array[i]=='}')
                    {
                        s.pop();
                    }

            }
    }
    return s.empty();

}
int main()
{
    vector<string> array;

        cout<<"Please enter the parenthesis you want to enter into the array:";
        string a;
        cin>>a;
        array.push_back(a);
    cout<<BMatching(array);
    return 0;
}
