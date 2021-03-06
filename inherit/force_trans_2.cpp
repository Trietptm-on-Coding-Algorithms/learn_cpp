#include <iostream>

class Performer
{
public:
    int a = 90;
    virtual void perform() = 0;
};

class T
{
public:
    int a = 100;

    virtual void test() 
    {
        std::cout << "test " << this->T::a << "\n" ;
    }
};

class LoadingPerformer : public Performer, public T
{
public :
    virtual void perform();
    virtual void test();
};

void LoadingPerformer::perform()
{
    std::cout << "perform " << this->Performer::a << "\n" ;
}

void LoadingPerformer::test()
{
    std::cout << "LoadingPerform test\n" ;
}

int main()
{
    LoadingPerformer *lp = new LoadingPerformer();
    Performer * p = (Performer*) lp;
    T * t = (T*) lp;

    p->perform();
    t->test();

    // perform 90
    // LoadingPerform test

    LoadingPerformer 
        *lp_from_t = (LoadingPerformer*) t, 
        *lp_from_p = (LoadingPerformer*) p;
    
    lp_from_t->perform();
    lp_from_p->test();
        
    // perform 90
    // LoadingPerform test

    return 0;
}

