#include <iostream>
#include "Cars.h"


using namespace std;

void menu(){
    cout << "1. All cars\n";
    cout << "2. Add a car\n";
    cout << "3. Find cars\n";
    cout << "4. Edit a car by index\n";
    cout << "5. Save data to file\n";
    cout << "6. Load data from file\n";
    cout << "7. Delete a car from list\n";
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
                EnterCarToList();
                break;

            case 3:
                FindCars();
                break;

            case 4:
                if(EditCarByIndex() == 0) cout << "Edited successfuly!\n" << endl;
                break;

            case 5:
                if(SaveListToFile() == 0) cout << "Saved successfuly!\n" << endl;
                break;

            case 6:
                if(LoadListFromFile() == 0) cout << "Loaded successfuly!\n" << endl;
                break;
                
            case 7:
                if(DeleteCarFromList() == 0){ cout << "Deleted successfuly!\n" << endl; }
                break;

            default:
                cout << "No such option" << endl;
                break;
        }


    }

    return 0;
}
