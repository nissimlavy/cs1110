/**************************************/
/* Nissim Lavy		Assignemnt 6  */
/* CIS 1110		3/27/14	      */
/**************************************/

#include <iostream>
#include <fstream>

using namespace std;

void printBookings(int[], int);
double income(int[], int, double);
int empty(int[], int);

int main() {

    int bookings[10] = {0};
   
    int numFlights = 10;
    int txnType;
    int flightNum;
    int numOfSeats;
    int emp;
    double inc;
   
    double seatPrice = 120;
   
    ifstream file;
    file.open("flightinfo.txt");
   
    printBookings(bookings, numFlights);
   
	while (file){
        file >> txnType >> flightNum >> numOfSeats;
       
        if (txnType == 1){
            bookings[flightNum] += numOfSeats;
            cout << "Added " << numOfSeats << " to flight number " << flightNum << endl;
        } else {
            if (numOfSeats > bookings[flightNum]){
                cout << "Error, Trying to cancel more seats than possible(" << numOfSeats << " seats) from flight " << flightNum << ". Request rejected." << endl;
            } else{
                bookings[flightNum] -= numOfSeats;
                cout << "Removed " << numOfSeats << " from flight number " << flightNum << endl;
            }
        }
    }
 
	cout << endl; 
 
    printBookings(bookings, numFlights);
    emp = empty(bookings, numFlights);
    inc = income(bookings, numFlights, seatPrice);

    cout << "the number of flights that have no bookings is: " << emp << endl;
    cout << "the total value of all ticket sales for the day is: " << inc << endl;


    cout << endl << "Program Finished" << endl;
    return 0;
}

void printBookings(int bookings[], int numFlights){

    cout << "Flight Num\t" << "Bookings" << endl;

    for (int i = 0; i < numFlights; i++){
        cout << i << "\t\t" << bookings[i] << endl;
    }
	
	cout << endl;
}

double income(int bookings[], int numFlights, double chargePerSeat){

    int totalSeatNum = 0;

    for (int i = 0; i < numFlights; i++){
        totalSeatNum += bookings[i];
    }
	
	return totalSeatNum * chargePerSeat;  
}

int empty(int bookings[], int numFlights) {

    int noBooking = 0;
   
    for (int i = 0; i < numFlights; i++){
        if (bookings[i] == 0)
            noBooking++;
    }
   
    return noBooking;
}
