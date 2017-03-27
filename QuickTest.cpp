//g++ QuickTest.cpp ./2111/CSC2110/libCSC2110.a
#include "Sort.h"
#include "2111/CSC2110/ListArray.h"
using CSC2110::ListArray;
#include "2111/CSC2110/ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "2111/CSC2110/CD.h"
using CSC2110::CD;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }

   delete iter;
}

int main()
{
   ListArray<CD>* list = CD::readCDs("cds.txt");

   CD** cds = list->toArray();
   int size = list->size();
   CD** sorted = Sort<CD>::quickSort(cds, size, &CD::compare_items);
   for (int i = 0; i < size; i++)
   {
      CD* cd = sorted[i];
      cd->displayCD();
   }

   deleteCDs(list);
   delete list;
}
