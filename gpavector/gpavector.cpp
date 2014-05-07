#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::string;
using namespace std;
 
void printv(vector<double>gpaRay, vector<string>names, int size);
void sortv(vector<double> & gpaRay, vector<string> & names, int size);
int smallest(vector<double>gpaRay, int start, int size);
 
 
 
int main(){
 
    ifstream in ("gpa.txt");
    if(!in.is_open ()){ 
        cout << "ERROR:\n " << endl;
        cout << "Exiting\n ";
        exit(-1);
    }
 
    string name;
    double gpa;
    vector<string>names;    
    vector<double>gpaRay;
 
    while(!in.eof()){
        in >> name >> gpa;
        gpaRay.push_back(gpa);
        names.push_back(name);
    }
 
 
    sortv(gpaRay,names,4);
    printv(gpaRay,names,4);
    in.close();
 
    return 0;
}
 
void printv(vector<double>gpaRay, vector<string>names, int size){
    for(int i = 0; i < size; i++){
        cout << names[i] << " " << gpaRay[i] <<endl;
    }
    cout << endl;
}
 
void sortv(vector<double>& gpaRay, vector<string> & names, int size){
 
    for (int i = 0; i < size; i++){
        int j = smallest(gpaRay,i,size);
 
        double temp = gpaRay[i];
        gpaRay[i] = gpaRay[j];
        gpaRay[j] = temp;
 
        string tempname = names[i];
        names[i] = names[j];
        names[j] = tempname;
    }
}
 
int smallest(vector<double>gpaRay, int start, int size){
    int small = start;
    for(int i = start+1; i < size; i++){
        if(gpaRay[i] < gpaRay[small]){
            small = i;
        }
    }
    return small;
}