#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct process{
    int pid;
    string line;
};

void radix_sort(vector<process> &,int);

void merge_sort(vector<process> &,int);
void mergesort(vector<process> &, vector<process> &, int , int );
void mergeback(vector<process> &, vector<process> &, int , int );

void quick_sort(vector<process> &, int , int );
int partition(vector<process> &, int , int );




int main(int argc,  char **argv){



    ifstream file (argv[1]); // input file

    vector<process> vline; //vector to be sorted
    string line;

    istringstream l;

    if(file.is_open()){

        while(getline(file,line)){

            int l1,l2,pid;
            l.str(line);
            l >> l1 >> l2 >> pid;
            process p;
            p.pid = pid;
            p.line = line;
            vline.push_back(p);

            l.clear();

        }


    }
    file.close();

int option = 0 ;

cout << "Enter the preferred sort" << endl;
cout << "1. Radix sort\n2. Merge sort\n3. Quick sort" << endl;
cin >> option;

switch(option){

    case 1:
        radix_sort(vline,vline.size());
        break;
    case 2:
        merge_sort(vline,vline.size());
        break;
    case 3:
        quick_sort(vline,0,vline.size() - 1);
        break;
    default:
        break;
}

// Print sorted array //

for(int i = vline.size() - 1 ; i >= 0  ; i--){
        cout <<vline[i].pid << " --- " << vline[i].line << endl;
    }


}

void radix_sort(vector<process> &arr,int size){

    
    int max = arr[0].pid;
    int radix;

    for(int i =1; i< size; i++){
        if(max < arr[i].pid)
            max = arr[i].pid;

    }

    for(radix = 1; max/radix > 0 ; radix *=10 ){

        vector<process> temp(size);
        int hash[10] = {};
        
        for(int i=0 ; i < size ; i++){
            hash[(arr[i].pid/radix)%10]++;
        }

        for(int i=1 ; i<10 ;i++){
            hash[i] += hash[i-1];

        }

        for(int i = size-1 ; i >= 0 ; i--){
            temp[hash[(arr[i].pid/radix)%10]-1] = arr[i];
            hash[(arr[i].pid/radix)%10]--;
        }

        for(int i =0; i < size ; i++){
            arr[i] = temp[i];
        }
    }

}

void merge_sort(vector<process> &arr,int size){

    vector<process> temp(size);

    mergesort(arr,temp,0,size-1);


}

void mergesort(vector<process> &arr, vector<process> &temp, int l, int r){

    if(l < r){

        mergesort(arr,temp,l,(l+r)/2);
        mergesort(arr,temp,(l+r)/2 + 1, r);

        mergeback(arr,temp,l,r);
    }
}

void mergeback(vector<process> &arr, vector<process> &temp, int l, int r){

    int mid = (l+r)/2;
    int i = l;
    int j = mid + 1;
    int iter = l;

    while(i <= mid && j <= r){

        if(arr[i].pid < arr[j].pid){
            temp[iter] = arr[i];
            i++;
        }
        else{
            temp[iter] = arr[j];
            j++;
        }

        iter++;
    }

    while(i <= mid){
        temp[iter] = arr[i];
        iter++;
        i++;
    }

    while(j <= mid){
        temp[iter] = arr[j];
        iter++;
        j++;
    }

    for(int i =l ; i<=r ; i++ ){
        arr[i] = temp[i];
    }


}


void quick_sort(vector<process> &arr, int l, int r){

    if(l<r){
        int pivot = partition(arr,l,r);

        quick_sort(arr,l,pivot-1);
        quick_sort(arr,pivot+1,r);
    }
}


int partition(vector<process> &arr, int l, int r){

    

        int i = l;
        int j = r;
        process temp;
        int pivot = arr[(l+r)/2].pid;
        temp = arr[l];
        arr[l] = arr[(l+r)/2];
        arr[(l+r)/2] = temp;
        


        while(i<j){

            while(arr[i].pid <= pivot){
                i++;
            }

            while(arr[j].pid > pivot){
                j--;
            }
            if(i<j){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }


        }

        temp = arr[j];
        arr[j] = arr[l];
        arr[l] = temp;

        return j;
}



