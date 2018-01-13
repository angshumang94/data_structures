#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Date{
    int val;
    string s;
};

void bubble_sort(vector<int> &,int);
void bubble_sort(vector<string> &,int);
void bubble_sort(vector<Date> &,int);

int parsedate(string);


int main(){

    int option;

    string line;
    cout << "Enter input type" << endl;
    cout << "1. Integer\n2. String\n3. Date" << endl;
    cin >> option;
    cout << "Enter input file name" <<endl;
    cin >> line;

    ifstream file (line);

    vector<int> integer;
    vector<string> str;
    vector<Date> dt;

    istringstream l;

    if(file.is_open()){

        while(getline(file,line)){

            string text;
            Date d;

            l.str(line);
            l >> text;

            switch(option){
                case 1:
                    integer.push_back(stoi(text));
                    break;
                case 2:
                    str.push_back(text);
                    break;
                case 3:
                    d.val = parsedate(text);
                    d.s = text;
                    dt.push_back(d);
                    break;
                default:
                    break;
            }
    
            

            l.clear();

        }


    }
    file.close();


    cout << "Enter output file name" <<endl;
    cin >> line;

    ofstream opfile(line);


    switch(option){
                case 1:
                    bubble_sort(integer,integer.size());
                    if(opfile.is_open()){
                        for(int i =0  ; i < integer.size(); i++){
                            opfile <<integer[i] << endl;
                        }
                    }
                    break;
                case 2:
                    bubble_sort(str,str.size());
                    if(opfile.is_open()){
                        for(int i =0  ; i < str.size(); i++){
                            opfile <<str[i] << endl;
                        }
                    }
                    break;
                case 3:
                    bubble_sort(dt,dt.size());
                    if(opfile.is_open()){
                        for(int i =dt.size()  ; i >= 0 ; i--){
                            opfile <<dt[i].s << endl;
                        }
                    }
                    break;
                default:
                    break;
            }
        opfile.close();
    
}


void bubble_sort(vector<int> &arr,int size){

    int temp;
    for(int i = 0; i < size - 1 ;i++ ){
        for(int j = size - 1 ; j > i ; j--){
            if(arr[j] < arr[j-1]){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }

    for(int i =0  ; i < arr.size(); i++){
        cout <<arr[i] << endl;
    }
}

void bubble_sort(vector<Date> &arr,int size){

    Date temp;
    for(int i = 0; i < size - 1 ;i++ ){
        for(int j = size - 1 ; j > i ; j--){
            if(arr[j].val < arr[j-1].val){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }

    for(int i =arr.size()  ; i >= 0 ; i--){
        cout <<arr[i].s << endl;
    }
}

void bubble_sort(vector<string> &arr,int size){

    string temp;
    for(int i = 0; i < size - 1 ;i++ ){
        for(int j = size - 1 ; j > i ; j--){
            if(arr[j] < arr[j-1]){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }

    for(int i =0  ; i < arr.size(); i++){
        cout <<arr[i] << endl;
    }
}



int parsedate(string text){
    string date;
    int size = text.size();
    string month = text.substr(3,size - 8);

    
        if(month == "January")
            month = "01";
        else if(month == "February")
            month = "02";
            
        else if(month == "March")
            month = "03";
            
        else if(month == "April")
            month = "04";
            
        else if(month == "May")
            month = "05";
            
        else if(month == "June")
            month = "06";
            
        else if(month == "July")
            month = "07";
            
        else if(month == "August")
            month = "08";
            
        else if(month == "September")
            month = "09";
            
        else if(month == "October")
            month = "10";
            
        else if(month == "November")
            month = "11";
            
        else if(month == "December")
            month = "12";

    date.append(text,size-4,4);
    date.append(month);
    date.append(text,0,2);

    return stoi(date);
}