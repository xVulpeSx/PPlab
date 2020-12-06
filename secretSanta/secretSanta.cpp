#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<utility>
#include<time.h>

using namespace std;

struct Person
{
    string name;
    string email;
};

struct SecretSanta
{
    Person santa;
    Person reciver;
};


void setup(vector<Person> input, vector<Person> &toBeSetUped){
    for(int i= 0; i< input.size(); i++){
        toBeSetUped.push_back(input[i]);
    }
}

bool missionAccomplished(vector<SecretSanta> santaOrder){
    for(int i=0; i < santaOrder.size(); i++){
        if(santaOrder[i].santa.email == santaOrder[i].reciver.email){
            return false;
        }
    }
    return true;
}

void reset(vector<Person> group, vector<Person> & reciving, vector<Person> & giving, vector<SecretSanta> & santaOrder){
    setup(group, reciving);
    setup(group, giving);
    santaOrder.clear();
}

int rng(int lower, int higher){
    return rand() % higher + lower;
}

SecretSanta getPair(vector<Person> & giving, vector<Person> & reciving){
    int randomGiver, randomReciver;
    SecretSanta santaPair;

    for(int i = 0; i < 1000/giving.size(); i++){
        randomGiver = rng(0,giving.size());
        randomReciver = rng(0,reciving.size());
        if(giving[randomGiver].email != reciving[randomReciver].email){
            santaPair.santa = giving[randomGiver];
            santaPair.reciver = reciving[randomReciver];

            giving.erase(giving.begin() + randomGiver);
            reciving.erase(reciving.begin() + randomReciver);

            return santaPair;
        }
    }

    santaPair.santa = giving[rng(0,giving.size())];    
    santaPair.reciver = reciving[rng(0,reciving.size())];

    giving.erase(giving.begin() + randomGiver);
    reciving.erase(reciving.begin() + randomReciver);
    
    return santaPair;    
}

int main(){

    srand(time(NULL));

    vector<Person> group, giving, reciving;
    vector<SecretSanta> santaOrder;

    Person principal;
    string line;

    ofstream writeFile;
    ifstream readFile("input.txt");

    writeFile.open("output.txt");

    while (getline(readFile, line)){
        principal.name = line;
        getline(readFile, line);
        principal.email = line;
        group.push_back(principal);
    }
    do{
        cout << "MisionFail :<\n";

        reset(group, reciving, giving, santaOrder);

        while(giving.size() == reciving.size() && giving.size() != 0){
            cout << giving.size() << endl;  
            santaOrder.push_back(getPair(giving, reciving));
            cout << giving.size() <<" next!" << endl;  
        }
        cout << "out!\n";
    }while(!missionAccomplished(santaOrder));

    cout << "OSOBA KTOREJ SIE ROBI --> MAIL OSOBY KTORA ROBI --> IMIE OSOBY KTORA ROBI" << endl;

    for(int i = 0 ; i < santaOrder.size()-1; i++){
        writeFile << santaOrder[i].reciver.name << " " << santaOrder[i].santa.email << " " << santaOrder[i].santa.name << endl;
        cout << santaOrder[i].reciver.name << " " << santaOrder[i].santa.email << " " << santaOrder[i].santa.name << endl;
    }

    int i = santaOrder.size()-1;
    writeFile << santaOrder[i].reciver.name << " " << santaOrder[i].santa.email << " " << santaOrder[i].santa.name;
    cout << santaOrder[i].reciver.name << " " << santaOrder[i].santa.email << " " << santaOrder[i].santa.name;

    readFile.close();
    writeFile.close();
    return 0;
}