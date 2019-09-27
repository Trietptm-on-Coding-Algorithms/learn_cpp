// CODE 1-1
#include <stdio.h>
#include <iostream>

class Test
{
private:
    int priv_a = 100;
    virtual void v_priv_test(){}
protected:
    int prot_a = 0;
    virtual void v_prot_test(){}
public:
    int pub_a = 0;
    Test(int a);
    Test(char c);
    virtual void v_pub_test(){}
	void pub_test() {}
    static void static_pub_test(int a) { }
};

Test::Test(int a) {} 
Test::Test(char a) {}

int main()
{
    Test *t = new Test(1), *tt = new Test('a');

    std::cout << *(int *)(t + 0) << std::endl;
	// 100
    
    // 下面代码为后面说明提供例子
    t->v_pub_test();
    t->pub_test();
	Test::static_pub_test(0x99);
    
    return 0;
}

/*
(Test *) t
---------------
0x00 	vtabe
0x08	priv_a
0x0c	prot_a
0x10	pub_a
--------------

t -> vtable
--------------
0x00	v_priv_test
0x08	v_prot_test
0x10	v_pub_test
--------------

t -> vtable == tt -> vtable
*/