#ifndef ORDER
#define ORDER

#include <string>

class PrepareTheOrder{
protected:
    static const int maxNumberOfProducts = 10;
    std::string possibilities [5];
    std::string products[maxNumberOfProducts];
    int prices[maxNumberOfProducts];
    int sumOfPrices;
    int numberOfProducts = 0;

public:
    PrepareTheOrder();
    void takeTheOrder();
    void deliveryMethod();
    void paymentMethod();
    void addProductToTheOrder();
    void deleteProductFromTheOrder();
    void printTheOrder();
    void placeTheOrder();
};

#endif // ORDER
