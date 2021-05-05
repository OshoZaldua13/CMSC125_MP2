#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Class{ // wa ko kabaw unsa akong i-variable
private:
    string inputFile;

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
    // for(int i=0;i<100;i++)
    //     inputFile[i] = ""; //set each index to a blank character para at least naa konoy sulod pero bisag wa gud
    // inputFile[100] = "\0"; //para mabal-an nga its then end of the string na
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

    fs >> word; //input og isa ka word

    while(fs.good()){ //check niya if wala pa ba siya sa end sa file
        cout << word << " "; //ato i-print para check sa if nigana ba
        inputFile.append(word);
        fs >> word; //input na pud og laing word
    }
}

void Class::printFile(){
    for(int i=0;i<inputFile.length();i++)
        cout << inputFile[i];
}
