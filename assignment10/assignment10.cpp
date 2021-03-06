#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#define N 10

using namespace std;

void printCust(string);
void sortName(string);
void sortSales(string);

class Name {
    public:

        string first;
        string last;
};

class State {
    public:

        string state;
};

class SalesHist {
    public:

        double sale1, sale2, sale3;
        double total(){
            return sale1 + sale2 + sale3;
        }
};

class Units{
    public:

        int u;
};

class cust {
    public:

	    Units units;
	    Name name;
	    State st;
	    SalesHist salesHist;
};



void printcust(cust cu[N], int nelts) {

	for(int i = 0; i < nelts; i++) {

		cout << cu[i].name.first << "\t" << cu[i].name.last << "\t"
        	<< cu[i].st.state
            << "\t" << cu[i].salesHist.sale1 << "\t" << cu[i].salesHist.sale2 << "\t" << cu[i].salesHist.sale3 << "\t"
            << cu[i].units.u << endl;

   }

}

void sortname(cust cu[N], int nelts) {

    string lasttemp, firsttemp, statetemp;
    int unittemp, sale1temp, sale2temp, sale3temp;
    
    for(int pass = 1; pass <=nelts; pass++)

        for(int i = 0; i < nelts-1; i++)

			// sort by last name

            if (cu[i].name.last > cu[i+1].name.last) {
                lasttemp = cu[i].name.last;
                cu[i].name.last = cu[i+1].name.last;
                cu[i+1].name.last = lasttemp;

                firsttemp = cu[i].name.first;
                cu[i].name.first = cu[i+1].name.first;
                cu[i+1].name.first = firsttemp;
                
                statetemp = cu[i].st.state;
                cu[i].st.state = cu[i+1].st.state;
                cu[i+1].st.state = statetemp;
                
                unittemp = cu[i].units.u;
                cu[i].units.u = cu[i+1].units.u;
                cu[i+1].units.u = unittemp;
                
				sale1temp = cu[i].salesHist.sale1;
               	cu[i].salesHist.sale1 = cu[i+1].salesHist.sale1;
               	cu[i+1].salesHist.sale1 = sale1temp;
               
              	sale2temp = cu[i].salesHist.sale2;
              	cu[i].salesHist.sale2 = cu[i+1].salesHist.sale2;
             	cu[i+1].salesHist.sale2 = sale2temp;
               
               	sale3temp = cu[i].salesHist.sale3;
               	cu[i].salesHist.sale3 = cu[i+1].salesHist.sale3;
               	cu[i+1].salesHist.sale3 = sale3temp;

            }
	return;
}



void sortsales(cust cu[N], int nelts) {
   string lasttemp, firsttemp, statetemp;
   int sale1temp, sale2temp, sale3temp, unittemp;

   for(int pass = 1; pass < nelts; pass++)

       for(int i = 0; i < nelts-1; i++)

           if (cu[i].salesHist.total() > cu[i+1].salesHist.total()) {
               
             //  cout << cu[i].salesHist.total() << " > " << cu[i+1].salesHist.total() << endl;
               
               sale1temp = cu[i].salesHist.sale1;
               cu[i].salesHist.sale1 = cu[i+1].salesHist.sale1;
               cu[i+1].salesHist.sale1 = sale1temp;
               
               sale2temp = cu[i].salesHist.sale2;
               cu[i].salesHist.sale2 = cu[i+1].salesHist.sale2;
               cu[i+1].salesHist.sale2 = sale2temp;
               
               sale3temp = cu[i].salesHist.sale3;
               cu[i].salesHist.sale3 = cu[i+1].salesHist.sale3;
               cu[i+1].salesHist.sale3 = sale3temp;
    
               firsttemp = cu[i].name.first;
               cu[i].name.first = cu[i+1].name.first;
               cu[i+1].name.first = firsttemp;
    
               lasttemp = cu[i].name.last;
               cu[i].name.last = cu[i+1].name.last;
               cu[i+1].name.last = lasttemp;
    
               statetemp = cu[i].st.state;
               cu[i].st.state = cu[i+1].st.state;
               cu[i+1].st.state = statetemp;
    
               unittemp = cu[i].units.u;
               cu[i].units.u = cu[i+1].units.u;
               cu[i+1].units.u = unittemp;
            }
    return;

}

int main() {
    cust cu[5];
    ifstream file;

    file.open("input.txt");
    int i = 0;
    
    file >> cu[i].name.first >> cu[i].name.last >> cu[i].st.state >> cu[i].salesHist.sale1 >> cu[i].salesHist.sale2 >> cu[i].salesHist.sale3 >> cu[i].units.u;
    while(file) {
		i++;
        file >> cu[i].name.first >> cu[i].name.last >> cu[i].st.state >> cu[i].salesHist.sale1 >> cu[i].salesHist.sale2 >> cu[i].salesHist.sale3 >> cu[i].units.u;
		
        
   }
   
	//cout << cu[0].name.first << endl;

    printcust(cu, i);
    cout << endl << endl;
    sortname(cu, i); // sort by last name
    printcust(cu, i);
    cout << endl << endl;
    sortsales(cu, i);
    printcust(cu, i);


    cout << endl << "PROGRAM FINISHED" << endl;
    return 0;
}
