#include "cat.h"

Cat::Cat() {}
Cat::Cat(string name, string originOfCat, unsigned int averageAge, string furType, unsigned int numberOfCat, unsigned int sellingPrice, unsigned int size, string specialCharacter, string coatColor, string hairLossLevel, string appearance)
    : Pet(name, originOfCat, averageAge, furType, numberOfCat, sellingPrice, size), specialCharacter(specialCharacter), coatColor(coatColor), hairLossLevel(hairLossLevel), appearance(appearance) {}
Cat::Cat(const Cat& cat) : Pet(cat), specialCharacter(cat.specialCharacter), coatColor(cat.coatColor), hairLossLevel(cat.hairLossLevel), appearance(cat.appearance) {}
Cat::~Cat() {}
void Cat::displayInformation() {
    Pet::displayInformation();
    cout << "Special Character: " << specialCharacter << endl;
    cout << "Coat Color: " << coatColor << endl;
    cout << "Hair Loss Level: " << hairLossLevel << endl;
    cout << "Appearance: " << appearance << endl;
}