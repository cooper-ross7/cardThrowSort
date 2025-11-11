#ifndef _SORTUTILS_H
#define _SORTUTILS_H

#include "doublylinked.cpp"

Error_code cardThrowSort(List<int> &);
Error_code bubbleSort(List<int> &);
void loadRandomList(List<int> &, int numEntries = 10);

#endif
