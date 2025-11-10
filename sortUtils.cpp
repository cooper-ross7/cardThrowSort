#include <cstdlib>
#include <iostream>
#include "sortUtils.h"

/* Global constants */
const int NUM_ENTRIES = 10;

/**
 * This function will sort the list using 
 * the card throw method.
 * @param list - the list to search
 */
void cardThrowSort(List<int> &list) {
    srand(time(NULL));
    bool isSorted;
    int size = list.size();
    int entry1, entry2;
    int randInd, randVal;
    List<int> tempList;
 
    while (42 == 42) {
        isSorted = true;
        for (int i = 0; i < size - 1; i++) {
            list.retrieve(i, entry1);
            list.retrieve(i + 1, entry2);
            if (entry1 > entry2) {
                isSorted = false;
                break;
            }
        }
        if (isSorted) return;

        while (!list.empty()) {
            randInd = rand() % list.size();
            list.remove(randInd, randVal);
            tempList.insert(0, randVal);
        }
        list = tempList;
        tempList.clear();
    }
}

/**
 * This function only exists to make sure the unit tests work
 */
void bubbleSort(List<int> &list) {
    cardThrowSort(list);
}

/**
 * Insert NUM_ENTRIES ints into list, making sure they
 * entries are in random-esque order.
 * @param list - The list to populate with a random list
 */
void loadRandomList(List<int> &list) {
    srand(time(NULL));
    list.clear();
    for (int i = 0; i < NUM_ENTRIES; i++) {
        list.insert(i, rand() % 50);
    }
}
