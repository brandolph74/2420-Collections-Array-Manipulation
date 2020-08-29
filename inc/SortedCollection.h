#ifndef SORTED_DOUBLE_COLLECTION_H
#define SORTED_DOUBLE_COLLECTION_H
#include "Collection.h"

class SortedCollection: public Collection{
public:
   SortedCollection();                            //default constructor for sorted collection derived class

/**TODO: override any methods necessary
 * to keep this collection of doubles in
 * sorted order.  Hint - Whenever you
 * add an item add it in the "correct"
 * spot to maintain sorted order and
 * remember there are several ways to add
 * items to the collection.
 */
/*~SortedCollection()                                         //gave SortedCollection it's own destructor just in case of memory errors
    {

        delete []myArray;

    } */


 void add(double item);
 //SortedCollection sortMyArray();             //scrapped sort function, just uses sort()
SortedCollection& operator=(const SortedCollection& classToCopy);
SortedCollection(SortedCollection& origClass);
SortedCollection& operator+(double item);
SortedCollection& operator+(const SortedCollection& other);
};
#endif
