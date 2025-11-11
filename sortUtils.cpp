#include <cstdlib>
#include <iostream>
#include "sortUtils.h"
#include "mjgTimer.h"

using namespace std;

/* Global constants */
const int NUM_ENTRIES = 10;

bool checkIfSorted(List<int> &list);
void throwCards(List<int> &list);

/**
 * This function will sort a given list using 
 * the card throw method
 * @param list - the list to search
 * @return upperBoundReached if 30 minutes pass without the list successfully sorting, success otherwise
 */
Error_code cardThrowSort(List<int> &list) {
    srand(time(NULL));
    double time = getNow();

    while (!checkIfSorted(list)) {
        if (1800 < getElapsed(&time)) return upperBoundReached;
        throwCards(list);
    }
    return success;
}

/**
 * This function will check if the list is sorted or not
 * @return true if sorted, else false
 */
bool checkIfSorted(List<int> &list) {
    int numOfIndices = list.size() - 1;
    int entry1, entry2;
    
    for (int i = 0; i < numOfIndices; i++) {
        list.retrieve(i, entry1);
        list.retrieve(i + 1, entry2);
        if (entry1 > entry2) return false;
    }
    return true;
}

/**
 * This function randomizes the list, or "throws the card in the air"
 */
void throwCards(List<int> &list) {
    int randInd, randVal;
    List<int> tempList;
    
    while (!list.empty()) {
        randInd = rand() % list.size();
        list.remove(randInd, randVal);
        tempList.insert(0, randVal);
    }
    list = tempList;
    tempList.clear();
}

/**
 * This function only exists to make sure the unit tests work
 */
Error_code bubbleSort(List<int> &list) {
    return cardThrowSort(list);
}

/**
 * Insert NUM_ENTRIES ints into list, making sure they
 * entries are in random-esque order.
 * @param list - The list to populate with a random list
 */
void loadRandomList(List<int> &list, int numEntries) {
    srand(time(NULL));
    list.clear();
    for (int i = 0; i < numEntries; i++) {
        list.insert(i, rand() % 25);
    }
}
