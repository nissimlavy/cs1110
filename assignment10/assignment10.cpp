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

void printcust(cust cu[N], int nelts)
{
for(int i=0;i<nelts;i++)
   {

       cout << cu[i].name.first << "\t" << cu[i].name.last << "\t"
            << cu[i].st.state
            << "\t" << cu[i].salesHist.sale1 << "\t" << cu[i].salesHist.sale2 << "\t" << cu[i].salesHist.sale3 << "\t"
            << cu[i].units.u << endl;

   }

}

void sortname(cust cu[N], int nelts){

    string temp,temp2,temp3;
    int temp4=0,temp5=0;
    
    for(int pass=1;pass<nelts;pass++)

        for(int i=0;i<nelts-1;i++)

            if (cu[i].name.last>cu[i+1].name.last){
                temp=cu[i].name.last;
                cu[i].name.last=cu[i+1].name.last;
                cu[i+1].name.last=temp;

                temp2=cu[i].name.first;
                cu[i].name.first=cu[i+1].name.first;
                cu[i+1].name.first=temp2;
                
                temp3=cu[i].st.state;
                cu[i].st.state=cu[i+1].st.state;
                cu[i+1].st.state=temp3;
                
                temp4=cu[i].units.u;
                cu[i].units.u=cu[i+1].units.u;
                cu[i+1].units.u=temp4;
                
                temp5=cu[i].salesHist.total();
                cu[i].salesHist.total()==cu[i+1].salesHist.total();
                cu[i+1].salesHist.total()==temp5;

            }
return;
}



void sortsales(cust cu[N], int nelts)
{
   string temp,temp2,temp3;
   int hold=0,temp4=0;

   for(int pass=1; pass < nelts; pass++)

       for(int i=0; i< nelts-1; i++)

           if (cu[i].salesHist.total()<cu[i+1].salesHist.total()) {
               hold=cu[i+1].salesHist.total();
               cu[i].salesHist.total()==cu[i+1].salesHist.total();
               cu[i+1].salesHist.total()==hold;
    
               temp2=cu[i].name.first;
               cu[i].name.first=cu[i+1].name.first;
               cu[i+1].name.first=temp2;
    
               temp=cu[i].name.last;
               cu[i].name.last=cu[i+1].name.last;
               cu[i+1].name.last=temp;
    
               temp3=cu[i].st.state;
               cu[i].st.state=cu[i+1].st.state;
               cu[i+1].st.state=temp3;
    
               temp4=cu[i].units.u;
               cu[i].units.u=cu[i+1].units.u;
               cu[i+1].units.u=temp4;
            }
    return;

}


int main()
{
    cust cu[N];
    ifstream file;

    file.open("input.txt");
    int i=0;
    while(!file.eof()){

        file >> cu[i].name.first >> cu[i].name.last >> cu[i].st.state >> cu[i].salesHist.sale1 >> cu[i].salesHist.sale2 >> cu[i].salesHist.sale3 >> cu[i].units.u;

        i++;
   }

    printcust(cu, i);
    cout<<endl<<endl;
    sortname(cu, i); // sort by last name
    printcust(cu, i);
    cout<<endl<<endl;
    sortsales(cu, i);
    printcust(cu, i);


    cout << "PROGRAM FINISHED" << endl;
    return 0;
}
