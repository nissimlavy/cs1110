#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void initialize(int[], int[]);
void printBookings(int[], int[], int);
int findFlight(int[], int, int);

int main()
{
    int count = 10;
    int txnType;
    int flightNum;
    int numOfSeats;

    int bookings[20];
    int flightNo[20];


    ifstream flightTxn;
    flightTxn.open("flightTxn.txt");


    initialize(flightNo, bookings);
    printBookings(flightNo, bookings, count);

    flightTxn >> txnType >> flightNum >> numOfSeats;
    while(flightTxn){
        int index = findFlight(flightNo, count, flightNum);
        if (index == -1) {
            cout << "Invalid flight number" << endl;
        } else if(txnType == 1){
            bookings[index] += numOfSeats;
            cout << numOfSeats << " seats booked on flight " << flightNum << endl;
        } else if (txnType == 2) {
            if (numOfSeats > bookings[index]){
                cout << numOfSeats << " seats were not cancelled from flight " << flightNum << " (excess of seats booked)" << endl;
           } else{
                bookings[index] -= numOfSeats;
                cout << numOfSeats << " seats cancelled from flight " << flightNum << endl;
            }
        } else {
            cout << "Invalid transaction type" << endl;
        }
        flightTxn >> txnType >> flightNum >> numOfSeats;
    }

    printBookings(flightNo, bookings, count);

    cout << "Program Finished" << endl;
    return 0;
}

void initialize(int flightNo[], int bookings[]){

    ifstream flightNums;
    flightNums.open("flightNums.txt");

    for(int i = 0; i < 10; i++){
        flightNums >> flightNo[i];
        bookings[i] = 0;
    }

    return;
}

void printBookings(int flightNo[], int bookings[], int count){

    cout << "NUM" << setw(10) << "FLIGHTNUM" << setw(10) << "BOOKINGS" << endl;
    for(int i = 0; i < count; i++){
        cout << i << setw(10) << flightNo[i] << setw(10) << bookings[i] << endl;
    }

    return;
}

int findFlight(int flightNo[], int count, int flightNum){

    int index;
    for(int i = 0; i < count; i++){
        if(flightNo[i] == flightNum) {
            index = i;
            break;
        } else {
            index = -1;
        }
    }
    return index;
}

