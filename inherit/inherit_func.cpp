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
    void pub_test();
    static void static_pub_test(int a);
};

Parent::Parent() {} 
Parent::Parent(char a) {}
void Parent::pub_test() {}
void Parent::static_pub_test(int a) {}


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
    void v_priv_test() { this->prot_a = 0;}
    void pub_test() {}
    static void static_pub_test() {}
    virtual void v_new_pub_test() {}
};

Child::Child() {}
Child::~Child() {}


int main()
{
    Parent *p = new Parent();
    Child *c = new Child();

    c->pub_test();
    c->static_pub_test();

    return 0;
}