#include <iostream>
using namespace std;
class Square
{
private:
    int length;
public:
    explicit Square(int x=0):length{x}{};
    void show();
};
void Square::show()
{
    cout<<length<<endl;
}
//Let's see how can we initialize more two or more members
class Rectangle
{
private:
    int lenght;
    int width;
public:
    Rectangle(int x=0,int y=0):lenght{x},width{y}{};
    void show();
};
void Rectangle::show()
{
    cout<<"Length:"<<lenght<<endl;
    cout<<"Width:"<<width<<endl;
}
void TestInitializationList()
{
    Square S;
    S.show();
    Square P(8);
    P.show();
    //Let's see how can we initialize more two or more members
    cout<<endl;
    Rectangle R(0,8);
    R.show();
}
//Now lets see the initialization of constants
class Nothing
{
private:
    const int alphabets=26;//With C++11 this is possible otherwise we can initialize them with initialization list
public: //or with static const int
    Nothing();

};
Nothing::Nothing()
{
    cout<<alphabets<<endl;
}
//Use of explicit before constructors prevent implicit conversions
void TestExplicit()
{
    Square S;
    //S=9;//This is an implicit conversion and will call the constructor S(int) explicit prevent this
}
int main()
{
    TestInitializationList();

}
