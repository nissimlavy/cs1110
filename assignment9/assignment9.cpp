#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int countwords(string);
string rev(string);
int main()
{
   ifstream file;
   file.open("input.txt");
   string line;
   int wc;
   string strrev;
   while(!file.eof()){
       getline(file, line);
       wc = countwords(line);
       strrev = rev(line);
       cout << strrev << endl;
   }
  
   return 0;
}

int countwords(string line){
    int count = 0;
    int pos = 0;
    for(int i=0; i < line.length(); i+=pos){
        pos = line.find(" ", i);
        count++;
    }
    return count;
}

string rev(string line){
    int pos=0;
    string newline, str;
    
    for (int i = 0; i < line.length(); i=pos){
        pos = line.find(" ",i+1);
        str = line.substr(i, pos-i);
        newline = str + newline;
        
        if(newline.find('.',0) != -1){
            newline.erase(newline.find('.',0),1);
        }
    
    }
    return newline;
}
