//
//  main.cpp
//  heirachial
//
//  Created by Amay shah  on 04/08/18.
//  Copyright © 2018 Amay shah . All rights reserved.
//

#include <iostream>
using namespace std;
class first
{
protected:
    float a,b;
public:
    void getdata()
    {
        cout << "enter value of a and b";
        cin >> a >> b;
    }
};
class addition: public first
{
protected:
    float c;
public:
    void add()
    {
        c=a+b;
    }
    void show()
    {
        cout << "addition is " << c << endl;
    }
};
class subtraction: public first
{
protected:
    float d;
public:
    void sub()
    {
        d=a-b;
    }
    void show1()
    {
        cout << "subtraction is " << d << endl;
    }
};
int main(int argc, const char * argv[]) {
    addition a1;
    a1.getdata();
    a1.add();
    a1.show();
    subtraction s1;
    s1.getdata();
    s1.sub();
    s1.show1();
    return 0;
}
