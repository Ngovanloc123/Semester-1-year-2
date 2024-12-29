#include "LinkedList.cpp"

int main() {
    LinkedList PetList = new Node;
    if (PetList == NULL) {
        cout << "Out of space!" << endl;
        return 0;
    }

    Position p = PetList;
    Pet pet("Bulldog", "England", 10, "Short", 3, 2000, 3);
    p = PetList->insert(pet, p);

    Pet pet2("Persian", "Iran", 15, "Long", 2, 1500, 2);
    p = PetList->insert(pet2, p);
    PetList->display();
    PetList->eraseByName("Persian");
    PetList->display();
    return 0;
}