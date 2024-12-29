#pragma once
#include "pet.h"

class Cat : public  Pet {
    private: 
        string specialCharacter;
        string coatColor;
        string hairLossLevel;
        string appearance;
    public:
        Cat();
        Cat(string name, string originOfCat, unsigned int averageAge, string furType, unsigned int numberOfCat, unsigned int sellingPrice, unsigned int size, string specialCharacter, string coatColor, string hairLossLevel, string appearance);
        Cat(const Cat& cat);
        ~Cat();
        void displayInformation();
};
