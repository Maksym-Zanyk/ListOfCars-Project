#include <iostream>
#include "Cars.h"
#include <cstring>
#include <stdlib.h>
#define MAX_NUMBER_OF_CARS 100

using namespace std;


Cars list_of_cars[MAX_NUMBER_OF_CARS];
int current_number_of_cars = 0;

//Czy lista jest pusta
int IsListEmpty(void) {
	if(current_number_of_cars == 0) return 1;
	else return 0;
}

//Czy list jest pełna
int IsListFull(void) {
	if(current_number_of_cars == MAX_NUMBER_OF_CARS) return 1;
	else return 0;
}


//Wyświetlić pozycję po kryterium
void PrintCarsBy(int option) {      //all(0), maker(1), model(2), year(3), price(4)

	switch(option) {
	case 0:
		for(int i = 0; i<current_number_of_cars; i++) {
			cout << i+1 << ".\t";
			cout << list_of_cars[i].maker << "\t";
			cout << list_of_cars[i].model << "\t";
			cout << list_of_cars[i].year  << "\t";
			cout << list_of_cars[i].price << endl;
		}
		break;

	case 1:
	    char maker[20];
        cout << "Maker: ";
        cin >> maker;
        
		for(int i = 0; i<current_number_of_cars; i++) {
			if(strcmp(list_of_cars[i].maker, maker) == 0) {
				cout << i+1 << ".\t";
				cout << list_of_cars[i].maker << "\t";
				cout << list_of_cars[i].model << "\t";
				cout << list_of_cars[i].year  << "\t";
				cout << list_of_cars[i].price << endl;
			}

		}
		break;
	
	case 2:
	    char model[20];
        cout << "Model: ";
        cin >> model;
        
		for(int i = 0; i<current_number_of_cars; i++) {
			if(strcmp(list_of_cars[i].model, model) == 0) {
				cout << i+1 << ".\t";
				cout << list_of_cars[i].maker << "\t";
				cout << list_of_cars[i].model << "\t";
				cout << list_of_cars[i].year  << "\t";
				cout << list_of_cars[i].price << endl;
			}

		}
		break;
	
	case 3:
	    int year;
        cout << "Year: ";
        cin >> year;
        
		for(int i = 0; i<current_number_of_cars; i++) {
			if(list_of_cars[i].year == year) {
				cout << i+1 << ".\t";
				cout << list_of_cars[i].maker << "\t";
				cout << list_of_cars[i].model << "\t";
				cout << list_of_cars[i].year  << "\t";
				cout << list_of_cars[i].price << endl;
			}

		}
		break;
	
	case 4:
	    int price;
        cout << "Price: ";
        cin >> price;
        
		for(int i = 0; i<current_number_of_cars; i++) {
			if(list_of_cars[i].price == price) {
				cout << i+1 << ".\t";
				cout << list_of_cars[i].maker << "\t";
				cout << list_of_cars[i].model << "\t";
				cout << list_of_cars[i].year  << "\t";
				cout << list_of_cars[i].price << endl;
			}

		}
		break;
	
	default:
	    cout << "No such option" << endl;
	    break;
	}
	
	cout << endl;
}


//Wyświetlić całą listę
void PrintListOfCars(void) {

	if(!IsListEmpty()) {
		PrintCarsBy(0);     //parametr "0" -- wyświetl wszystko
	}
	else {
		cout << "Your list is empty " << endl;
	}
	cout << endl;
}

//Wpisać jedną pozycję
void EnterCarToList(void) {

	if(!IsListFull()) { //jeżeli lista nie jest pełna

		cout << "Maker: ";
		cin >> list_of_cars[current_number_of_cars].maker;

		cout << "Model: ";
		cin >> list_of_cars[current_number_of_cars].model;

		cout << "Year: ";
		cin >> list_of_cars[current_number_of_cars].year;

		cout << "Price: ";
		cin >> list_of_cars[current_number_of_cars].price;

		cout << "\nAdded succesfuly!" << endl;
		current_number_of_cars++;
	}
	else {
		cout << "\nYour list is full." << endl;
	}

	cout << endl;
}

//Wyszukać pozycje po kryterium:
void FindCars(void) {

    if(!IsListEmpty()){   //jeżeli lista nie jest pusta
        int option;
        cout << "Search cars by: maker(1), model(2), year(3), price(4) - ";
        cin >> option;
        
        PrintCarsBy(option);
    }
    else{
        cout << "The list is empty\n" << endl;
    }
}

//Edycja pozyzji po indeksu 
int EditCarByIndex(void){
    int index;
    cout << "Enter index of a car to edit: ";
    cin >> index;
    index--;
    
    if(list_of_cars[index].year == 0) {     //jeżeli pozycja nie była dodana przez użytkownika
        cout << "No such car in your list" << endl;
        return 1;
    }
    
    int option;
    cout << "Edit: maker(1), model(2), year(3), price(4) - ";
    cin >> option;
    
    switch(option){
        case 1:
            cout << "New maker: ";
            cin >> list_of_cars[index].maker;
            break;
            
        case 2:
            cout << "New model: ";
            cin >> list_of_cars[index].model;
            break;
            
        case 3:
            cout << "New year: ";
            cin >> list_of_cars[index].year;
            break;
            
        case 4:
            cout << "New price: ";
            cin >> list_of_cars[index].price;
            break;
            
        default:
            cout << "No such option\n" << endl;
            break;
            
    }
    
    return 0;
}


//Kopiowanie listy z pliku .txt
int LoadListFromFile(void){
    FILE *fptr;

    fptr = fopen("List-Of-Cars.txt", "r");
    

    if (fptr == 0)
    {
        cout << "ERROR with opening the file\n" << endl;
        return 1;
    }

    for(int i=0; i<MAX_NUMBER_OF_CARS; i++){
        fscanf(fptr,"%[^\t]\t%[^\t]\t%d\t%d\n", list_of_cars[i].maker, list_of_cars[i].model, &list_of_cars[i].year, &list_of_cars[i].price);
        
        if(list_of_cars[i].year == 0){
    		break;
		}
		else{
			current_number_of_cars++;
		}
    }
    
    fclose(fptr);
    return 0;
}

//Zapisywanie listy do pliku .txt
int SaveListToFile(void){

    FILE *fptr;

    fptr = fopen("SavedCars.txt", "w");

    if (fptr == NULL)
    {
        cout << "ERROR with opening the file\n" << endl;
        return 1;
    }
    
    for(int i=0; i<current_number_of_cars; i++){
        fprintf(fptr,"%s\t%s\t%d\t%d\n", list_of_cars[i].maker, list_of_cars[i].model, list_of_cars[i].year, list_of_cars[i].price);
    }

    
    fclose(fptr);
    return 0;

}


int DeleteCarFromList(void){
	int index;
    cout << "Enter index of a car to delete: ";
    cin >> index;
    index--;
    
    if(list_of_cars[index].year == 0) {     //je¿eli pozycja nie by³a dodana przez u¿ytkownika
        cout << "No such car in your list\n" << endl;
        return 1;
    }

	list_of_cars[index].maker[0] = '\0';	
	list_of_cars[index].model[0] = '\0';
	list_of_cars[index].year = 0;
	list_of_cars[index].price = 0;
			
	for(int i=index; i<current_number_of_cars; i++){
		list_of_cars[i] = list_of_cars[i+1];
	}		
	

	current_number_of_cars--;
	
	return 0;	
}
