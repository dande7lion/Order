#ifndef MENU
#define MENU

#include <string>

class Product {
protected:
    double price;
    int numberOfProducts;
    std::string productName;
    static const int maxNumber = 5;
    std::string possibleProducts [maxNumber];
    int possiblePrices [maxNumber];

public:
    void chooseProduct();
    void productAdded();
    void fillTheMenu(int, std::string [], int []);
    virtual void createTheMenu() = 0;
};

class Soup : public Product {
public:
    virtual void createTheMenu();
};

class MainCourse : public Product {
public:
    virtual void createTheMenu();
};

class Dessert : public Product {
public:
    virtual void createTheMenu();
};

class Drink : public Product {
public:
    virtual void createTheMenu();
};


#endif // MENU
