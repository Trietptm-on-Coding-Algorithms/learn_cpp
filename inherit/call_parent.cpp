#include <iostream>

class Parent
{
public:
    Parent();
    ~Parent();
	int pa = 9;
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
    // P show
    
    std::cout << c->Parent::pa << std::endl;
    // 9

    return 0;
}