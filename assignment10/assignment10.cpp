#include <iostream>
#include <fstream>
#include <string>

#define N 10

using namespace std;
printCust(string);
sortName(string);
sortSales(string);
int main() {

	ifstream file;
	file.open("file.txt");
	
	cust arr[N];
	string line;
	
	//file >> cust.name.first >> cust.name.last >> cust.state.state >> cust.salesHist.sales[1] >> cust.salesHist.sales[2] >> cust.salesHist.sales[3] >> cust.units.units;
	while(!file.eof()){
		getline(file, line)
		printCust(line);
		sortName(line);
		printCust(line);
		sortSales(line);
		printCust(line);
	}
	
	cout << "PROGRAM FINISHED" << endl;
	return 0;
	
}

class cust {
	public:
		
		double totalSales;
		
		class name {
			public:
				
				string first;
				string last;
			};
			
		class state {
			public:
				
				string state;
		};
		
		class salesHist {
			public:
			
				double sales[];
		};
		
		class units{
			public:
			
				int units;
		};

};
