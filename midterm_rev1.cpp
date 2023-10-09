#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Animal {
private:
    string name;
    string species;
    static int numOfAnimals;

public:
    Animal(string animalName, string animalSpecies) : name(animalName), species(animalSpecies) {
        numOfAnimals++;
    }

    string getAnimalName() const {
        return name;
    }

    string getAnimalSpecies() const {
        return species;
    }

    static int getTotalNumOfAnimals() {
        return numOfAnimals;
    }
};

int Animal::numOfAnimals = 0;

class Hyena : public Animal {
private:
    int weight;
    static int numOfHyenas;

public:
    Hyena(string animalName, string animalSpecies, int animalWeight)
        : Animal(animalName, animalSpecies), weight(animalWeight) {
        numOfHyenas++;
    }

    static int getNumOfHyenas() {
        return numOfHyenas;
    }
};

int Hyena::numOfHyenas = 0;

class Lion : public Animal {
private:
    int weight;
    static int numOfLions;

public:
    Lion(string animalName, string animalSpecies, int animalWeight)
        : Animal(animalName, animalSpecies), weight(animalWeight) {
        numOfLions++;
    }

    static int getNumOfLions() {
        return numOfLions;
    }
};

int Lion::numOfLions = 0;

class Tiger : public Animal {
private:
    int weight;
    static int numOfTigers;

public:
    Tiger(string animalName, string animalSpecies, int animalWeight)
        : Animal(animalName, animalSpecies), weight(animalWeight) {
        numOfTigers++;
    }

    static int getNumOfTigers() {
        return numOfTigers;
    }
};

int Tiger::numOfTigers = 0;

class Bear : public Animal {
private:
    int weight;
    static int numOfBears;

public:
    Bear(string animalName, string animalSpecies, int animalWeight)
        : Animal(animalName, animalSpecies), weight(animalWeight) {
        numOfBears++;
    }

    static int getNumOfBears() {
        return numOfBears;
    }
};

int Bear::numOfBears = 0;

int main() {
    // Create Example Animals
    Lion myLion01 = Lion("Scar", "Lion", 300);
    Lion myLion02 = Lion("Mufasa", "Lion", 320);

    Tiger myTiger01 = Tiger("Tiger Name", "Tiger", 200);
    Tiger myTiger02 = Tiger("Tiger Name02", "Tiger", 220);

    Hyena myHyena01 = Hyena("Zig", "Hyena", 50);
    Hyena myHyena02 = Hyena("Zig1", "Hyena", 55);

    Bear myBear01 = Bear("BearBear", "Bear", 500);
    Bear myBear02 = Bear("BearBearBear", "Bear", 700);
    Bear myBear03 = Bear("BearBearBearBear", "Bear", 600);

    // Output number of Animals/Species
    cout << "Total number of Animals: " << Animal::getTotalNumOfAnimals() << endl;
    cout << "The total number of Lions is: " << Lion::getNumOfLions() << endl;
    cout << "The total number of Tigers is: " << Tiger::getNumOfTigers() << endl;
    cout << "The total number of Hyenas is: " << Hyena::getNumOfHyenas() << endl;
    cout << "The total number of Bears is: " << Bear::getNumOfBears() << endl;

    // Output Bear information
    cout << "Bear's name is: " << myBear01.getAnimalName() << endl;

      // Read and print animal data from a file
    vector<Animal> animalList;
    string line;

    ifstream inputFile("animalNames.txt"); // Replace with your file's name

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            size_t pos = line.find(',');
            if (pos != string::npos && pos < line.length()) {
                string animalName = line.substr(0, pos);
                string animalSpecies = line.substr(16, 7);
                Animal animal(animalName, animalSpecies);
                animalList.push_back(animal);
            }
        }
        inputFile.close();

        // Print the list of animals
        for (const Animal& animal : animalList) {
            cout << "Name: " << animal.getAnimalName() << " Species: " << animal.getAnimalSpecies() << endl;
        }

        cout << "Total number of animals: " << Animal::getTotalNumOfAnimals() << endl;
    } else {
        cout << "Unable to open the file." << endl;
    }




    return 0;
}

