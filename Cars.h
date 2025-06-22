
#ifndef LISTOFCARS_CARS_H
#define LISTOFCARS_CARS_H


using namespace std;

struct Cars{
    char maker[20];
    char model[20];
    int year = 0;
    int price = 0;
};


int IsListEmpty(void);
int IsListFull(void);
void EnterCarToList(void);
void PrintListOfCars(void);
void PrintCarsBy(int option);
void FindCars(void);
int EditCarByIndex(void);
int SaveListToFile(void);
int LoadListFromFile(void);
int DeleteCarFromList(void);

#endif //LISTOFCARS_CARS_H
