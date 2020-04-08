#include "Order.h"
#include "Menu.h"
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

PrepareTheOrder::PrepareTheOrder(){
    possibilities[0] = "Add product to the order";
    possibilities[1] = "Delete product from the order";
    possibilities[2] = "See your order";
    possibilities[3] = "Place the order";
    possibilities[4] = "Exit";
}

void PrepareTheOrder::takeTheOrder(){

    cout << "What do you want to do?" << endl;
    for(int i = 0; i < 4; i++){
        printf("%d. %s\n", i+1, possibilities[i].c_str());
    }
    cout << endl;
    int choice;
    cin >> choice;
    cout << endl;

    switch(choice){

        case 1:
        addProductToTheOrder();
        break;

        case 2:
        deleteProductFromTheOrder();
        break;

        case 3:
        printTheOrder();
        break;

        case 4:
        placeTheOrder();
        break;

        case 5:
        exit(0);

        default:
        cout << "Incorrect selection. Please try again." << endl;

    }

}

void PrepareTheOrder::placeTheOrder(){

}

void PrepareTheOrder::printTheOrder(){

}

void PrepareTheOrder::deleteProductFromTheOrder(){

}

void PrepareTheOrder::addProductToTheOrder(){

}

void PrepareTheOrder::deliveryMethod(){

}

void PrepareTheOrder::paymentMethod(){

}
