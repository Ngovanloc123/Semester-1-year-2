#include "dog.h"

Dog::Dog() {}
Dog::Dog(string name, string originOfDog, unsigned int averageAge, string furType, unsigned int numberOfDog, unsigned int sellingPrice, unsigned int size, string purposeOfRaising, string levelOfTraining, string needForExercise)
    : Pet(name, originOfDog, averageAge, furType, numberOfDog, sellingPrice, size), purposeOfRaising(purposeOfRaising), levelOfTraining(levelOfTraining), needForExercise(needForExercise) {}
Dog::Dog(const Dog& dog) : Pet(dog), purposeOfRaising(dog.purposeOfRaising), levelOfTraining(dog.levelOfTraining), needForExercise(dog.needForExercise) {}
Dog::~Dog() {}
void Dog::displayInformation() {
    Pet::displayInformation();
    cout << "Purpose of Raising: " << purposeOfRaising << endl;
    cout << "Level of Training: " << levelOfTraining << endl;
    cout << "Need for Exercise: " << needForExercise << endl;
}