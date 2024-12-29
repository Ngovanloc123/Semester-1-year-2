#pragma once
#include "pet.h"

class Dog : public  Pet { 
    private: 
        string purposeOfRaising;
        string levelOfTraining;
        string needForExercise;
    public: 
        Dog();
        Dog(string name, string originOfDog, unsigned int averageAge, string furType, unsigned int numberOfDog, unsigned int sellingPrice, unsigned int size, string purposeOfRaising, string levelOfTraining, string needForExercise);
        Dog(const Dog& dog);
        ~Dog();
        void displayInformation();
};