#include "Menu.h"
#include "Order.h"
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

void Product::productAdded(){
    cout << productName << " has been added to your order." << endl;
    cout << endl;
}

void Product::chooseProduct(){
    cout << "Please select a product: " << endl;
    printf("%-6s | %-30s | %s\n", "Number", "Product", "Price");
    printf("----------------------------------------------------\n");
    for(int i = 0; i < numberOfProducts; i++){
        printf("%-6d | %-30s | %d $\n", i+1, possibleProducts[i].c_str(), possiblePrices[i]);
    }
    cout << endl << "Select 123 to cancel" << endl;
    int choice;
    cout << endl;
    cin >> choice;
    cout << endl << "Your choice: " << choice << endl << endl;

    if(choice == 123){
        return;
    }
    else if (choice < 1 || choice > numberOfProducts) {
        cout << "Incorrect selection. Please try again." << endl << endl;
        chooseProduct();
    }

    else{
        price = possiblePrices[choice-1];
        productName = possibleProducts[choice-1];
        productAdded();
    }
}

void Product::fillTheMenu(int numberOfPro, string possiblePro [], int possiblePri[]){
    numberOfProducts = numberOfPro;
    for(int i = 0; i < numberOfPro; i++){
        possiblePrices[i] = possiblePri[i];
        possibleProducts[i] = possiblePro[i];
    }
}


void Soup::createTheMenu(){
    string tempProducts [] = {"Tomato & Basil soup", "Mushroom soup", "Chicken soup"};
    int tempPrices [] = {5, 7, 6};
    int tempNumber = sizeof(tempPrices)/sizeof(*tempPrices);
    fillTheMenu(tempNumber, tempProducts, tempPrices);
}


void MainCourse::createTheMenu(){
    string tempProducts [] = {"Fish with potatoes", "Spaghetti bolognese", "Chicken with rice", "Pasta with cheese"};
    int tempPrices [] = {15, 14, 14, 13};
    int tempNumber = sizeof(tempPrices)/sizeof(*tempPrices);
    fillTheMenu(tempNumber, tempProducts, tempPrices);
}

void Dessert::createTheMenu(){
    string tempProducts [] = {"Cupcake", "Apple pie", "Cocoa cake with cream", "Carrot cake", "Yeast dough"};
    int tempPrices [] = {3, 5, 4, 3};
    int tempNumber = sizeof(tempPrices)/sizeof(*tempPrices);
    fillTheMenu(tempNumber, tempProducts, tempPrices);
}


void Drink::createTheMenu(){
    string tempProducts [] = {"Cola", "Ice tea", "Orange juice", "Apple juice", "Water"};
    int tempPrices [] = {3, 3, 2, 2, 2};
    int tempNumber = sizeof(tempPrices)/sizeof(*tempPrices);
    fillTheMenu(tempNumber, tempProducts, tempPrices);
}
