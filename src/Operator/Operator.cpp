#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    string name;
    int age;

public:
    Person() {}
    Person(string Name, int Age) : name(Name), age(Age) {}
    Person operator+(Person&p);
};

Person operator+(Person&p,int num)
{
    return Person("!!!",p.age+num);
}

ostream&operator<<(ostream&cout,const Person&p)
{
    cout<<p.name<<" "<<p.age<<endl;
    return cout;
}

class Integer
{
    friend ostream&operator<<(ostream&cout,const Integer&Int);
private:
    int val;
public:
    Integer(){}
    Integer(int x):val(x){}

    // front++
    Integer&operator++()
    {
        this->val++;
        return *this;
    }
    // post++  int represents occupancy parameter ,which can differentiate front++ from post++
    Integer operator++(int)
    {
        Integer fi=*this;
        this->val++;
        return fi;
    }


};

ostream&operator<<(ostream&cout,const Integer&Int)
{
    cout<<Int.val<<endl;
    return cout;
}

class Object
{
public:
    int*pointer;
    Object(){pointer=nullptr;}
    Object(int val):pointer(new int(val)){}

    Object&operator=(const Object&object)
    {
        if(pointer)
        {
            delete pointer;
            pointer=nullptr;
        }
        pointer=new int(*object.pointer);
        return *this;
    }


    ~Object()
    {
        if (pointer)
        {
            delete pointer;
            pointer=nullptr;
        }
        
    }
};



int main()
{
    Person p1("A",18);
    Person p2("B",18);
    Person p3=p1+p2;//==p1.operator+(p2)
    Person p4=p1+100;

    cout<<p3.name<<" "<<p3.age<<endl;
    cout<<p4.name<<" "<<p4.age<<endl;

    cout<<p1<<p2<<endl;
    cout<<"\n\n\n"<<endl;

    Integer i(1);
    Integer j(-10);
    cout<<++(++i)<<i<<endl;
    cout<<j++<<j;

    cout<<"\n\n\n";
    Object o1(0);
    Object o2(1);
    cout<<*(o1.pointer)<<" "<<*(o2.pointer)<<endl;
    Object o3;
    o3=o2=o1;
    cout<<*(o1.pointer)<<" "<<*(o2.pointer)<<" "<<*(o2.pointer)<<endl;
    getchar();
    return 0;
}

Person Person::operator+(Person&p)
{
    return Person("???",this->age+p.age);
    //anonymous object will be destroyed after the line is executed
}