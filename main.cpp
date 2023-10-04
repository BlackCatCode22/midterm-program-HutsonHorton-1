#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


//Create Animal Class
//theName theSpecies
class Animal{

private:
    string name;
    string species;
    string theWeight;
    inline static int numOfAnimals = 0;


public:

        Animal(string animalName, string animalSpecies)  {
        //The name/species is passed through the constructor and is passed through to the private field name/species
        name = animalName;
        species = animalSpecies;

        numOfAnimals++;


        }
            //Set a getter for the animal subclasses' name
            string getAnimalName(){
                return name;

            }

        int getnumOfAnimals(){
        return numOfAnimals;
        }
        string getAnimalSpecies(){
        return species;}

};

//Create Hyena Class, This will be a stepping stone for the rest of the animal subclasses
class Hyena:public Animal{
private:
    int weight;
    inline static int numOfHyenas = 0;
    string UniqueIdentifier = "HY";



public:
    Hyena(string animalName, string animalSpecies):Animal("Hyena Name","species"){
        numOfHyenas++;

    }

// numOfHyenas getter
    int getnumOfHyenas(){
    return numOfHyenas;

    UniqueIdentifier + std::to_string(numOfHyenas);
    }

};

//Lion Class
class Lion:public Animal{
private:
    int weight;
    inline static int numOfLions = 0;


public:
    Lion(string animalName, string animalSpecies):Animal("Lion Name","species"){
        numOfLions++;

    }

// numOfLions getter
    int getnumOfLions(){
    return numOfLions;
    }

};
//Tiger Class
class Tiger:public Animal{
private:
    int weight;
    inline static int numOfTigers = 0;


public:
    Tiger(string animalName, string animalSpecies):Animal("Tiger Name","species"){
        numOfTigers++;

    }

// numOfLions getter
    int getnumOfTigers(){
    return numOfTigers;
    }

};
//Bear Class

class Bear:public Animal{
private:
    int weight;
    inline static int numOfBears = 0;


public:
    Bear(string animalName, string animalSpecies):Animal("Bears Name","species"){
        numOfBears++;

    }

// numOfLions getter
    int getnumOfBears(){
    return numOfBears;
    }

};



int main()
{
//Create Example Animals, cout various information to verify program is working as intended


Animal myAnimal = Animal("Scar","lion");
Animal myAnimal2 = Animal("Zig","hyena");
Animal myAnimal3 = Animal("ScaEd","hyena");
Lion myLion01 = Lion("Scar", "Lion");
Lion myLion02 = Lion("Mufasa", "Lion");
Tiger myTiger01 = Tiger("Tiger Name", "Tiger");
Tiger myTiger02 = Tiger("Tiger Name02", "Tiger");
Hyena myHyena01 = Hyena("Zig", "Hyena");
Hyena myHyena02 = Hyena("Zig1", "Hyena");
Bear myBear01 = Bear("BearBear", "Bear");
Bear myBear02 = Bear("BearBearBear", "Bear");
Bear myBear03 = Bear("BearBearBearBear", "Bear");

cout << "The total number of Animals is: " << myAnimal3.getnumOfAnimals() << endl;
cout << "The total number of Hyenas is: " << myHyena01.getnumOfHyenas() << endl;
cout << "The total number of Lions is: " << myLion01.getnumOfLions() << endl;
cout << "The total number of Tigers is: " << myTiger01.getnumOfTigers() << endl;
cout << "The total number of Bears is: " << myBear01.getnumOfBears() << endl;
cout << "The Hyena's name is: " << myHyena01.getAnimalName() << endl;



string filePath = "arrivingAnimals.txt";
ifstream inputFile("arrivingAnimals.txt");
    if(!inputFile.is_open()) {
        cerr << "Error: Unable to Open File " << filePath << endl;
        return 1;

    }

    vector<Animal> animalList;

    string line;
    while(getline(inputFile, line)) {
        int  spacePos = line.find(' ');
        spacePos = line.find(' ');
        spacePos = line.find(' ');
        spacePos = line.find(' ');
        if(spacePos != string::npos){
                string name = line.substr(0, spacePos);
                string species = line.substr(spacePos + 1,spacePos + 7);

                Animal animal(name, species);
                animalList.push_back(animal);

        }
    }
    for (const Animal& animal : animalList) {
        cout << "\n\nName: " << animal.getAnimalName() << endl;
        cout << "Species: " << animal.getAnimalSpecies() << endl;
             }











return 0;
}



