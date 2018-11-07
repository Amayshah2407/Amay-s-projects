//
//  main.cpp
//  friend function
//
//  Created by Amay shah  on 04/08/18.
//  Copyright © 2018 Amay shah . All rights reserved.
//

#include <iostream>
using namespace std;
class second;
class first
{

    float a;
public:
    void getdata1()
    {
        cout << "enter value of a";
        cin >> a;
    }
    friend void add(first,second);
};
class second
{

    float b;
public:
    void getdata2()
    {
        cout << "enter value of b";
        cin >> b;
    }
    friend void add(first,second);
};

void add(first f1,second s1)
{
    int c=f1.a+s1.b;
    cout<<"addition is "<<c<<endl;
}
int main(int argc, const char * argv[]) {

    first obj1;
    obj1.getdata1();
    second obj2;
    obj2.getdata2();
    add(obj1,obj2);
    
    return 0;
}
