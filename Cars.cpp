#include <iostream>
#include <stdio.h>
#include "Cars.h"


using namespace std;

#define MAX_NUMBER_OF_CARS 100
Cars list_of_cars[MAX_NUMBER_OF_CARS];
int current_number_of_cars = 1;

void PrintListOfCars(void) {

    for(int i = 0; i<MAX_NUMBER_OF_CARS; i++) {
        if(list_of_cars[i].year) {
            cout << list_of_cars[i].maker << "\t" << list_of_cars[i].model << "\t" << list_of_cars[i].year << "\t" << list_of_cars[i].price << endl;
        }

    }
    cout << endl;
}


void EnterCarToList(void) {

    if(current_number_of_cars < 100) {
            int i = 0;

            cout << "Maker: ";
            cin >> list_of_cars[current_number_of_cars - 1].maker;

            cout << "Model: ";
            cin >> list_of_cars[current_number_of_cars - 1].model;

            cout << "Year: ";
            cin >> list_of_cars[current_number_of_cars - 1].year;

            cout << "Price: ";
            cin >> list_of_cars[current_number_of_cars - 1].price;

            cout << "\nAdded succesfuly!" << endl;
    }
}