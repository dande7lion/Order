#ifndef ORDER
#define ORDER

#include <string>
#include <cstdio>

class PrepareTheOrder{
protected:
    static const int maxNumberOfProducts = 10;
    std::string possibilities [5];
    std::string dishes[4];
    std::string products[maxNumberOfProducts];
    int prices[maxNumberOfProducts];
    int numberOfProducts = 0;
    std::string deliveryAddress;
    int phoneNumber;
    std::string deliveryChoice;
    std::string paymentChoice;

public:
    PrepareTheOrder();
    void takeTheOrder();
    void deliveryMethod();
    void paymentMethod();
    void addProductToTheOrder();
    void removeProductFromTheOrder();
    void printTheOrder();
    void placeTheOrder();
    bool isEmpty();
};

#endif // ORDER
