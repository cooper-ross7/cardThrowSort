/**
 * Cooper Ross
 * November 11th, 2025
 * Runs cardThrowSort on numOfLists lists of size n, then outputs the average time to sort each
 * list. n begins at 5, then increases, and the process continues until maxEntries is reached.
 * If a list is not sorted within 30 minutes it cancels the sorting process, though that
 * time is still used in calculating average sort time.
 */

#include <iostream>
#include "mjgTimer.cpp"
#include "sortUtils.h"

using namespace std;

int main() {
    // To modify the program, only change these variables!    
    int numOfLists = 5; // The number of lists of size n to sort; higher values produce
                        // more accurate results but take longer
    int maxEntries = 20; // The maximum value of n to test

    List<int> myList; // List to sort
    double timer; // How long a single list took to sort
    double totalTime = 0; // The total amount of time j lists of size n took to sort
    double avgTime; // The average amount of time j lists of size n took to sort
    int simplifiedAvgTime; // Aids in getting avgTime down to 2 decimal places
    int listsSorted = 0; // The number of lists that actually get sorted, excluding those
                         // where the upper bound time limit was reached

    // i is the "n" referenced in previous documentation
    for (int i = 5; i <= maxEntries; i += 1) {
        cout << "Now sorting " << numOfLists << " lists of size " << i << "..." << endl;
        
        // Sorts numOfLists lists of size n and collects the total sort time
        for (int j = 0; j < numOfLists; j++) {
            timer = getNow();
            loadRandomList(myList, i);
            if (cardThrowSort(myList) == success) listsSorted++;
            
            timer = getElapsed(&timer);
            totalTime += timer;
        }

        // Get avgTime and do a likely overcomplicated process to shorten it to 2 decimal places
        avgTime = totalTime / numOfLists;
        avgTime *= 100;
        simplifiedAvgTime = avgTime;
        avgTime = simplifiedAvgTime / 100.0;
        totalTime = 0;

        cout << "Average sort time: " << avgTime << " seconds.\n";
        cout << listsSorted << " of " << numOfLists << " successfully sorted.\n\n";
        listsSorted = 0;
    }
}
