#include <iostream>
#include "Cars.h"


using namespace std;

void menu(){
    cout << "1. All cars\n";
    cout << "2. Add a car\n";
    cout << "3. Find a car\n";
    cout << "4. Edit a car by index\n";
    cout << "5. Save data to file\n";
    cout << "6. Load data from file\n";
    cout << "0. Exit\n\n";


}


int main()
{
    cout << "Hello. Welcome to your car list.\n\n";


    while(1){

        int option;
        menu();
        cin >> option;

        switch(option){

            case 0:
                return 0;

            case 1:
                PrintListOfCars();
                break;


            case 2:
                //ReallocateTheList(list_of_cars, current_number_of_cars);
                //EnterCarToList(list_of_cars, current_number_of_cars);
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;
        }


    }

    return 0;
}







