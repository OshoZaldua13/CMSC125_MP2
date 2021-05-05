#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Class{ // wa ko kabaw unsa akong i-variable
private:
    string inputFile;
    int arrivalTime[50], burstTime[50], priority[50];

public:
    Class();
    void readFile();
    void printFile();
};

int main(){
    Class c; //get it? Class, c? naay Class c rn? char

    c.readFile(); //read og file duhh
    c.printFile(); //print file duhhh

    return 0;
}

Class::Class(){ //constructor
    for(int i=0;i<50;i++){
        arrivalTime[i] = burstTime[i] = priority[i] = 0; //butangan nato tanan daan og zero para walay error
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
    }
}

void Class::printFile(){
    for(int i=0;i<20;i++)
        cout << priority[i] << " ";
}
