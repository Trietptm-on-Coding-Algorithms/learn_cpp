#include <iostream>

class FastFoodRestaurant
{
public:
    int ffr = 0;
    virtual int sell_hamburger(int n, int money) {}
    virtual void free_drink() {}
};

class ChinaRestaurant
{
public:
    int cr = 1;

    virtual void show_healthlevel() {}
    virtual void test() {}
};

class XCJ : public FastFoodRestaurant, public ChinaRestaurant
{
private:
    const int hamburger_prize = 10;

public:
    virtual int sell_hamburger(int n, int money);
    virtual void free_drink();

    virtual void show_healthlevel();
};

int XCJ::sell_hamburger(int n, int money)
{
    int n_money = n * hamburger_prize;
    if (money > n_money) {
        std::cout << "Balance : " << money - n_money << std::endl;
        return money - n_money;   
    } else {
        std::cout << "You don't have enough money!\n" ;
        return -1;
    }
}

void XCJ::free_drink()
{
    std::cout << "Drink whenever you want\n" ;
}

void XCJ::show_healthlevel()
{
    std::cout << "Health Level: B\n" ;
}

int main()
{
    
    XCJ * cd_xcj = new XCJ();

    cd_xcj->show_healthlevel();
    cd_xcj->free_drink();

    int balance = cd_xcj->sell_hamburger(2, 18);

    std::cout << cd_xcj->ChinaRestaurant::cr << std::endl;
    // 1

    cd_xcj->test();
    cd_xcj->ChinaRestaurant::test();

    delete cd_xcj;
    
    return 0;
}