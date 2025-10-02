#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main() {
    LinkedList<int> myList;

    cout << "Appending 10, 20, 30 to the list...\n";
    myList.append(10);
    myList.append(20);
    myList.append(30);
    cout << "Current List: " << myList;

    cout << "Replacing element at position 1 with 25...\n";
    myList.replace(1, 25);
    cout << "Current List: " << myList;

    cout << "Getting element at position 2: ";
    cout << myList.getElement(2) << endl;

    cout << "Clearing the list...\n";
    myList.clear();
    cout << "Current List: " << myList;

    cout << "Is list empty? " << (myList.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
