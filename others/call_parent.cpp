#include <iostream>

class Parent
{
public:
    Parent();
    ~Parent();

    virtual void show() { std::cout << "P show\n"; }
};

Parent::Parent() {}
Parent::~Parent() {}


class Child : public Parent
{
public:
    Child();
    ~Child();

    void show();
};

Child::Child() {}
Child::~Child() {}

void Child::show()
{
    this->Parent::show();
}

int main()
{
    Child *c = new Child();
    c->show();
    return 0;
}
