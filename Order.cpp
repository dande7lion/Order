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
    dishes[0] = "Soup";
    dishes[1] = "Main course";
    dishes[2] = "Dessert";
    dishes[3] = "Drink";
}

void PrepareTheOrder::takeTheOrder(){

    cout << "What do you want to do?" << endl;
    for(int i = 0; i < 5; i++){
        printf("%d. %s\n", i+1, possibilities[i].c_str());
    }
    cout << endl;
    int choice;
    cin >> choice;
    cout << endl;
    string exitDecision;

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
            cout << "Are you sure you want to exit? " << "[yes/no]" << endl;
            cin >> exitDecision;
            if(exitDecision == "yes")
                exit(0);
            else{
                cout << endl;
                takeTheOrder();
            }
            break;

        default:
            cout << "Incorrect selection. Please try again." << endl;
            takeTheOrder();

    }
}

void PrepareTheOrder::placeTheOrder(){
    deliveryMethod();
    paymentMethod();
    cout << endl << "Summary of your order:" << endl;
    printTheOrder();
    cout << endl << "Delivery method: " << deliveryChoice << endl;
    if(deliveryChoice == "Home delivery"){
        cout << "Delivery address: " << deliveryAddress << endl;
    }
    cout << "Your phone number: " << phoneNumber << endl << "Payment method: " << paymentChoice << endl;
    cout << endl << "Thank you for using our services!" << endl;

}

void PrepareTheOrder::printTheOrder(){
    if(numberOfProducts == 0) {
        cout << "Your order is empty! Add products using the appropriate options." << endl << endl;
        takeTheOrder();
    }
    cout << endl << "Your order: " << endl;
    int sumOfPrices = 0;
    printf("%-30s | %s\n", "Product", "Price");
    printf("--------------------------------------------\n");
    for(int i = 1; i <= numberOfProducts; i++){
        printf("%-30s | %d $\n", products[i-1].c_str(), prices[i-1]);
        sumOfPrices += prices[i-1];
    }
    cout << endl << "Order cost: " << sumOfPrices << '$' << endl;
}

void PrepareTheOrder::deleteProductFromTheOrder(){

}

void PrepareTheOrder::addProductToTheOrder(){
    Soup soup; MainCourse mainCourse; Dessert dessert; Drink drink;
    cout << "Select a category: " << endl;
    for(int i = 0; i < 4; i++){
        printf("%d. %s\n", i+1, dishes[i].c_str());
    }
    cout << endl << "Select 123 to cancel" << endl;
    cout << endl;
    int choice;
    cin >> choice;
    cout << endl;

    switch(choice){

        case 123:
            takeTheOrder();
            return;

        case 1:
            soup.createTheMenu();
            soup.chooseProduct();
            products[numberOfProducts] = soup.productName;
            prices[numberOfProducts] = soup.price;
            numberOfProducts++;
            break;

        case 2:
            mainCourse.createTheMenu();
            mainCourse.chooseProduct();
            products[numberOfProducts] = mainCourse.productName;
            prices[numberOfProducts] = mainCourse.price;
            numberOfProducts++;
            break;

        case 3:
            dessert.createTheMenu();
            dessert.chooseProduct();
            products[numberOfProducts] = dessert.productName;
            prices[numberOfProducts] = dessert.price;
            numberOfProducts++;
            break;

        case 4:
            drink.createTheMenu();
            drink.chooseProduct();
            products[numberOfProducts] = drink.productName;
            prices[numberOfProducts] = drink.price;
            numberOfProducts++;
            break;

        default:
            cout << "Incorrect selection. Please try again." << endl;
            addProductToTheOrder();
            break;
    }

    placeTheOrder();
}

void PrepareTheOrder::deliveryMethod(){
    cout << endl << "Choose a delivery method: " << endl;
    string delivery[2];
    delivery[0] = "Personal pickup";
    delivery[1] = "Home delivery";
    for(int i = 0; i < 2; i++){
        cout << i+1 << ". " << delivery[i] << endl;
    }
    cout << endl << "Select 123 to cancel " << endl << endl;
    int choice;
    cin >> choice;
    if(choice == 1){
        deliveryChoice = "Personal pickup";
        cout << "Please enter your phone number: " << endl;
        cin >> phoneNumber;
        cout << endl << "Our address is 13 Example Street, London." << endl << "We will send you a message when your order is ready (usually half an hour after placing it)." << endl;
    }

    else if(choice == 2){
        deliveryChoice = "Home delivery";
        cout << "Please enter your enter delivery address: " << endl;
        cin.ignore();
        getline(cin, deliveryAddress);
        cout << endl << "Please enter your phone number: " << endl;
        cin >> phoneNumber;
    }

    else if(choice == 123){
        cout << endl;
        takeTheOrder();
    }

    else {
        cout << "Incorrect selection. Please try again." << endl;
        deliveryMethod();
    }
}


void PrepareTheOrder::paymentMethod(){
    cout << endl << "Choose a payment method: " << endl;
    string payment[2];
    payment[0] = "Cash";
    payment[1] = "Bank transfer";
    for(int i = 0; i < 2; i++){
        cout << i+1 << ". " << payment[i] << endl;
    }
    cout << endl << "Select 123 to cancel " << endl << endl;
    int choice;
    cin >> choice;
    if(choice == 1){
        paymentChoice = "Cash";
        cout << "You will be asked to pay when picking up the order." << endl;
    }

    else if(choice == 2){
        paymentChoice = "Bank transfer";
        cout << endl << "Please make a transfer to this account: " << endl << "Account number: 12312312312312313123" << endl <<
        "Title: " << "Order 1" << endl;
    }

    else if(choice == 123){
        cout << endl;
        takeTheOrder();
    }

    else {
        cout << "Incorrect selection. Please try again." << endl;
        paymentMethod();
    }
}

