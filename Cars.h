//
// Created by Student on 16.06.2025.
//

#ifndef LISTOFCARS_CARS_H
#define LISTOFCARS_CARS_H


using namespace std;

struct Cars{
    string maker = "";
    string model = "";
    int year = 0;
    int price = 0;
};

void EnterCarToList(struct Cars *list_of_cars, int length);
void PrintListOfCars(void);
void ReallocateTheList(struct Cars *list_of_cars, int length);


#endif //LISTOFCARS_CARS_H
