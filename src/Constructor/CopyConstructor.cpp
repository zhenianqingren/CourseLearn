#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    string name;
    int age;
    Person() { cout << "None Paramaters" << endl; }
    Person(string Name, int Age) : name(Name), age(Age) { cout << "Common Generate" << endl; }
    Person(const Person &p) : name(p.name), age(p.age) { cout << "Copy" << endl; }
};

Person TestCopy(Person p)
{
    cout << (int *)&p << endl;
    return p;
}

// heap data release problem:  deep copy&&shallow copy
class Object
{
public:
    int*pointer;
    Object(){}
    Object(int val):pointer(new int(val)){}

    ~Object()
    {
        cout<<"Destroy"<<endl;
        if(pointer)
        {
            delete pointer;
            pointer=nullptr;
        }
    }
};

void TestDestroyAndShallowCopy(Object obj)//Copy Constuctor call
{
    Object temp=obj;
    // local obj and temp are all destroyed
}

Object AnotherCase(int val)
{
    Object object(val);
    return object;
}

void NotUseAddress(Object obj)
{

}

int main()
{
    // circumstances of copy constructor call(use & can avoid call it)
    // 1.use one existed object to initialize another one
    Person p1("A", 18);
    cout << (int *)&p1 << endl;
    Person p2(p1);
    Person p3 = p2;
    // 2.parameters pass(don't change original value)<-(use & can avoid call it)
    // 3.return local object<-(use & can avoid call it)
    Person temp = TestCopy(p1);
    cout << (int *)&temp;

    cout<<"\n\n\n";

    Object test(0);
    NotUseAddress(test);
    cout<<*(test.pointer)<<endl;



    TestDestroyAndShallowCopy(test);

    // this initialization way won't call Destroy Constructor
    Object object=AnotherCase(5);
    cout<<*(object.pointer)<<endl;

    Object Error;
    Error=AnotherCase(10);
    cout<<*(Error.pointer)<<endl;

    cout<<"End";
    getchar();
    return 0;
}