// h_cpp_div.cpp

#include <iostream>

class TestDiv
{
public:
    void pub_test();
};

void TestDiv::pub_test() { std::cout << "Div\n"; }


class Test
{
public:
    void pub_test() { std::cout << "Not Div\n"; }
    virtual void v_pub_test() {}
};

int main()
{
    TestDiv * td = new TestDiv();
    Test * t = new Test();

    td->pub_test();
    t->pub_test();

    return 0;
}