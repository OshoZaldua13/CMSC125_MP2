#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>

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
    void SRPT();
    void Priority();
    void RoundRobin();
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

void Class::SRPT(){
    int overallTime = 0;
    for(int i=0;i<numberOfProcesses+1;i++)
        overallTime+=burstTime[i];

    cout << overallTime;

    int AT = 0;
    while(AT<overallTime){
        for(int i=0;i<numberOfProcesses;i++){
            if(arrivalTime[i]<=AT){

            }
        }
        AT++;
    }
}

void Class::Priority(){
    int arr[50] = {0};
    int prio = 0;

    for(int i=0;i<numberOfProcesses;){
        for(int j=0;j<numberOfProcesses;j++){
            if(priority[j]==prio){
                arr[i] = burstTime[j];
                i++;
            }
        }
        prio++;
    }

    //after na sort ang mga priorities char kay same ra gihapon sa fcfs
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

void Class::RoundRobin(){
    int arr[100][2]; // new array para sa gantt chart
    int ganttChart[100][2]; //jk kani ang gantt chart nga tinuod kato sa taas kay part ra sa paghimo og gantt chart
    for(int i=0;i<100;i++)
        for(int j=0;j<2;j++)
            arr[i][j] = ganttChart[i][j] = 0;

    int arr1[50]={0}; //ato icopy ang burst time diri kay ato mang hilabtan
    for(int i=0;i<numberOfProcesses;i++) 
        arr1[i] = burstTime[i];

    int zero = 1; //ilhanan if nahuman na ba
    int gi = 0; //gantt chart index
    for(int i=0;zero!=0;i++){
        zero = 0; //balik zero para matarong og plus
        int quantum = 4;
        int j = i%20; //ang index 
        if(arr1[j]-quantum<0) //inig minus kay zero na gali katong remainder ang iminus para zero ra ang differnece
            quantum = arr1[j]%quantum;

        if(arr1[j]!=0){ 
            arr[gi][0] = quantum; //gantt chart-ish is here bb
            arr[gi][1] = j;
            gi++;
        }
        for(int k=0;k<numberOfProcesses;k++) //gi check if na zero na ba tanan
            zero+=arr1[k];
        arr1[j]-=quantum; // diri ang pagminus
    } 

    //diri gihimo ang gantt chart base sa mga time nga nagamit nila sa quantum
    for(int i=0;i<gi+1;i++){
        for(int j=0;j<i;j++)
            ganttChart[i][0]+=arr[j][0];
        ganttChart[i][1] = arr[i][1];
    }

    //mana man og initialize ang gantt chart diri nga part is kuhaaun na nato ang waiting time ug turnaround time sa each process
    //first is pangitaon nako ang time nga i-minus sa waiting time which is ang time nga nag process sila pero wala nahuman
    int minusWaitingTime[50] = {0};
    int flag[50] = {0};
    for(int i=0;i<gi;i++){
        minusWaitingTime[arr[i][1]]+=arr[i][0];
        flag[arr[i][1]] = i; //para makabaw ta unsa ato iminus later kay maapil man og add ang something idk how to describe it
    }

    //pero naapil man nila og add ang waiting time sa last so kailangan nato i-minus para masakto
    for(int i=0;i<numberOfProcesses;i++)
        minusWaitingTime[i]-=arr[flag[i]][0];

    //naa naman nako ang i-minus sa waiting time ako rang kuhaun ang waiting time sa isa ka process then i-minus ra ez;
    int waitingTimeProcess[50] = {0};
    for(int i=0;i<numberOfProcesses;i++)
        waitingTimeProcess[i] = ganttChart[flag[i]][0] - minusWaitingTime[i];

    //so after ana i add ra nako tanan then i-average orayt ez pz im so happy hihihi
    float waitingTime = 0;
    for(int i=0;i<numberOfProcesses;i++)
        waitingTime+=waitingTimeProcess[i];
    waitingTime/=numberOfProcesses;
    cout << waitingTime << endl; //yey baby it works

    //okay turnaround time na pud mga langga
    for(int i=1;i<gi+1;i++)
        ganttChart[i-1][0] = ganttChart[i][0]; //updated the gantt chart para ang turnaround time na ang sulod

    for(int i=0;i<gi;i++)
        flag[ganttChart[i][1]] = i; //updated ang flag kung asa ang mga index sa turnaround time
    
    int turaroundTimeProcess[50] = {0};
    for(int i=0;i<numberOfProcesses;i++)
        turaroundTimeProcess[i] = ganttChart[flag[i]][0]; //kani mao nani ang turnaround times 

    //i-plus na lang tanan then i-average then mana  huhu very happy
    float turnaroundTime = 0;
    for(int i=0;i<numberOfProcesses;i++)
        turnaroundTime+=turaroundTimeProcess[i];
    turnaroundTime/=numberOfProcesses;
    cout << turnaroundTime << endl; //hay salamat mana jud ang round roben
}

void Class::performProcesses(){
    RoundRobin();
}
