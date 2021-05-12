#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Class{ // wa ko kabaw unsa akong i-class name
private:
    string inputFile;
    int arrivalTime[50], burstTime[50], priority[50];
    int numberOfProcesses;

public:
    Class();
    void readFile();
    void printFile(int[]);
    void setNumberOfProcesses();
    void FCFS();
    void SJF();
    void performProcesses();
};

int main(){
    Class c; //get it? Class, c? naay Class c rn? char

    c.readFile(); //read og file duhh
    // c.printFile(); //print file duhhh

    c.performProcesses();

    return 0;
}

Class::Class(){ //constructor
    for(int i=0;i<50;i++){
        arrivalTime[i] = burstTime[i] = priority[i] = 0; //butangan nato tanan daan og zero para walay error
        numberOfProcesses = 0;
    }
}

void Class::readFile(){
    char fileName[100]; //para pwede lahi2 ang file name niya dili pa i-edit ang code everytime lahi na ang filename

    cout << "Enter file name:\n"; //prompt
    // cin >> fileName; //diri ibutang ang file name

    fstream fs;

    cin.getline(fileName, 100); //ambot unsay nahitabo diri
    fs.open(fileName); //open na niya ang file

    if(!fs.is_open()){ //check if naa bay ingana nga file
        cout << "FILE DOES NOT EXIST\n"; //if wala print ni
        exit(EXIT_FAILURE); //then of course exit ang program
    }

    char word[50]; //another character array para pagbasa sa each word sa file
    char wholeFile[100]; //ibutang diri tanan niyang na read

    //limaon nato kay para ditso ta sa mga processing time and stuff
    fs >> word; 
    fs >> word;
    fs >> word;
    fs >> word;
    fs >> word;
    fs >> word;
    //lima btw kay lima man ka words ang na sa input niya ato to silang i-skip tanan

    int i = 0; //index

    while(fs.good()){ //check niya if wala pa ba siya sa end sa file
        fs >> word; //dili lang nato apilon unsa nga process kay sunod naman daan, so pwede ra ang index ang atong gamiton
        fs >> word; //input para sa arrival time
        arrivalTime[i] = atoi(word); //ibutang sa arrival time array, gi-atoi kay char array man niya ang arrival time array kay int array
        fs >> word; //input para sa burst time
        burstTime[i] = atoi(word); //gibutang sa burst time array
        fs >> word; //input para sa priority
        priority[i] = atoi(word); //gibutang sa priority array
        i++; //increment index duhhh
        numberOfProcesses++; //para makabaw ta pila kabuok processes
    }
}

void Class::printFile(int arr[]){
    for(int i=0;i<numberOfProcesses;i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Class::FCFS(){
    int arr[50] = {0}; //new array para ibutang ang each waiting time sa each process

    for(int i=0;i<numberOfProcesses;i++) //diri gibutang ang mga waiting time
        for(int j=0;j<i;j++)
            arr[i] = arr[i] + burstTime[j];

    int arr1[50] = {0}; //para ni sa turnaround time sa each process

    for(int i=0;i<numberOfProcesses;i++)
        for(int j=0;j<i+1;j++) //diri gibutang ang mga turnaround time
            arr1[i] = arr1[i] + burstTime[j];

    float turnaroudTime = arr1[0]; //ang unang value sa turnaround array kay 0 ang iyang i-plus inig una mamali na nuon
    float waitingTime = 0; //total waiting time na ni

    for(int i=1;i<numberOfProcesses;i++){
        waitingTime+=arr[i]; //gi add sa tanan
        turnaroudTime+=arr1[i]; //gi add sa tanan
    }
    turnaroudTime/=numberOfProcesses; //averaging sa turnaround time
    waitingTime/=numberOfProcesses; //averaging sa waitng time

    cout << waitingTime << endl;
    cout << turnaroudTime << endl;
}

void Class::SJF(){
    int arr[50] = {0}; //ibalhin nato ang burst time kay ato man ni i-sort and we dont want to change the input
    
    for(int i=0;i<numberOfProcesses;i++)
        arr[i] = burstTime[i]; //transfered

    sort(arr, arr+numberOfProcesses); //sort

    //after sorting is the same ra sa FCFS
    int arr1[50] = {0};
    int arr2[50] = {0};

    for(int i=0;i<numberOfProcesses;i++) //diri gibutang ang mga waiting time
        for(int j=0;j<i;j++)
            arr1[i] = arr1[i] + arr[j];

    for(int i=0;i<numberOfProcesses;i++)
        for(int j=0;j<i+1;j++) //diri gibutang ang mga turnaround time
            arr2[i] = arr2[i] + arr[j];
    
    float turnaroudTime = arr2[0]; //ang unang value sa turnaround array kay 0 ang iyang i-plus inig una mamali na nuon
    float waitingTime = 0; //total waiting time na ni

    for(int i=1;i<numberOfProcesses;i++){
        waitingTime+=arr1[i]; //gi add sa tanan
        turnaroudTime+=arr2[i]; //gi add sa tanan
    }
    turnaroudTime/=numberOfProcesses; //averaging sa turnaround time
    waitingTime/=numberOfProcesses; //averaging sa waitng time

    cout << waitingTime << endl;
    cout << turnaroudTime << endl;
}

void Class::performProcesses(){
    FCFS();
    SJF();
}
