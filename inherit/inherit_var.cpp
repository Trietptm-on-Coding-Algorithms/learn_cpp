#include <stdio.h>
#include <iostream>

class Parent
{
private:
    int priv_a = 100;
    virtual void v_priv_test(){}
protected:
    int prot_a = 0;
    virtual void v_prot_test(){}
public:
    int pub_a = 0;
    Parent();
    Parent(char c);
    virtual void v_pub_test(){}
    void pub_test() {}
    static void static_pub_test(int a) { }
};

Parent::Parent() {} 
Parent::Parent(char a) {}


class Child : public Parent
{
private:
    int priv_a = 1;
protected:
    int prot_a = 1;
    
public:
    int pub_a = 1; 
    Child();
    ~Child();
};

Child::Child() {}
Child::~Child() {}



int main()
{
    Parent *p = new Parent();
    Child *c = new Child();

    c->pub_a = 3;
    ((Parent*)(c))->pub_a = 2;

    std::cout << "c->pub_a = " << c->pub_a 
              << "\n((Parent*)(c))->pub_a = " << ((Parent*)(c))->pub_a 
              << std::endl;
    // c->pub_a = 3
    // ((Parent*)(c))->pub_a = 2
    return 0;
}