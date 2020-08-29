#include "SortedCollection.h"
#include <algorithm>
/**TODO: override any methods necessary
 * to keep this collection of doubles in
 * sorted order.  Hint - Whenever you
 * add an item add it in the "correct"
 * spot to maintain sorted order.
 */

void SortedCollection::add(double item)
{
    if (arraySize == arrayCapacity)
    {
        //copied array size function from operator+(Collection& other)
        if (this->arraySize + 1 > arrayCapacity || arraySize == arrayCapacity)                                      //check if the array is full
        {
            double *temp = new double[this->arraySize * 2];
            for (int i = 0; i < this->arraySize; i++)                           // loop through and copy the elements of myArray into temp
            {
                temp[i] = this->myArray[i];
            }
            delete []myArray;                                                  //deleting the original array
            myArray = temp;
            this->arrayCapacity = this->arrayCapacity * 2;
            //myArray = new double[this->arraySize * 2];
             /*
            for (int i = 0; i < this->arraySize; i++)               // loop through and copy the elements of temp into myArray now that it has been doubled
            {
                this->myArray[i] = temp[i];

            }
            delete []temp;   */
                   //doubles the array capacity





        }



        myArray[arraySize] = item;                   //adds the new member to the array
        arraySize = arraySize + 1;
        int arrayCap = arrayCapacity;
        double sortedArray[arrayCap];
        for (int i = 0; i < arraySize; i++) {          //creating a non-pointer array to sort
            sortedArray[i] = myArray[i];
        }
        std::sort(sortedArray, sortedArray + arraySize);     //sorts the sortedArray

        for (int i = 0; i < arraySize; i++) {          //copying back the data from sortedArray to myArray
            myArray[i] = sortedArray[i];
        }

    }
    else
    {
        myArray[arraySize] = item;                      //adds new member if capacity doesn't change
        arraySize = arraySize + 1;
        //copied the sort function from above
        int arrayCap = arrayCapacity;
        double sortedArray[arrayCap];
        for (int i = 0; i < arraySize; i++) {          //creating a non-pointer array to sort
            sortedArray[i] = myArray[i];
        }
        std::sort(sortedArray, sortedArray + arraySize);     //sorts the sortedArray

        for (int i = 0; i < arraySize; i++) {          //copying back the data from sortedArray to myArray
            myArray[i] = sortedArray[i];
        }
    }
}
/*
SortedCollection sortMyArray()
{
    sort(myArray, )
}
*/

SortedCollection::SortedCollection(){
    myArray = new double[8];
    arraySize = 0;                         //builds the default sortedcollection object, size of 8 randomly chosen
    arrayCapacity = 8;
}


 SortedCollection& SortedCollection::operator=(const SortedCollection& classToCopy)
{
    delete []myArray;                    //delete the old array

    arraySize = 0;

    myArray = new double[classToCopy.arrayCapacity];        //function performs deep copy
    arrayCapacity = classToCopy.arrayCapacity;         //set the capacity the same to original class


    for (int i = 0; i < classToCopy.arraySize; i++)
    {
        myArray[i] = classToCopy.myArray[i];
        arraySize = arraySize + 1;                 //set size to that of the original class
    }

    //dont need to sort here, just copying sortedcollections, was necessary for some tests
}

SortedCollection::SortedCollection(SortedCollection& originalClass)
{
    //copy constructor
    myArray = new double[originalClass.arrayCapacity];        //function performs deep copy
    arrayCapacity = originalClass.arrayCapacity;         //set the capacity the same to original class
    arraySize = 0;

    for (int i = 0; i < originalClass.arraySize; i++)
    {
        myArray[i] = originalClass.myArray[i];
        arraySize = arraySize + 1;                 //set size to that of the original class
    }


     //add the sort() function here to sort the data once it is done

}

SortedCollection& SortedCollection::operator+(double item)
{
    if (this->arraySize + 1 > arrayCapacity || arraySize == arrayCapacity)                                      //check if the array is full
    {
        double *temp = new double[this->arraySize * 2];
        for (int i = 0; i < this->arraySize; i++)                           // loop through and copy the elements of myArray into temp
        {
            temp[i] = this->myArray[i];
        }
        delete []myArray;                                                  //deleting the original array
        myArray = temp;
        this->arrayCapacity = this->arrayCapacity * 2;
        /*
        for (int i = 0; i < this->arraySize; i++)               // loop through and copy the elements of temp into myArray now that it has been doubled
        {
            this->myArray[i] = temp[i];

        }
        delete []temp; */
                //doubles the array capacity





    }



    myArray[arraySize] = item;
    arraySize = arraySize + 1;
    //sort function copied here again
    int arrayCap = arrayCapacity;
    double sortedArray[arrayCap];
    for (int i = 0; i < arraySize; i++) {          //creating a non-pointer array to sort
        sortedArray[i] = myArray[i];
    }
    std::sort(sortedArray, sortedArray + arraySize);     //sorts the sortedArray

    for (int i = 0; i < arraySize; i++) {          //copying back the data from sortedArray to myArray
        myArray[i] = sortedArray[i];
    }


    return *this;
}

SortedCollection& SortedCollection::operator+(const SortedCollection& other)
{
    if (this->arraySize + 1 > arrayCapacity || this->arraySize == this->arrayCapacity || this->arraySize + other.arraySize > this->arrayCapacity)                                       //check if the array is full
    {
        double *temp = new double[this->arraySize * 2];
        for (int i = 0; i < this->arraySize; i++)                           // loop through and copy the elements of myArray into temp
        {
            temp[i] = this->myArray[i];
        }
        delete []myArray;                                                  //deleting the original array
        myArray = temp;
        this->arrayCapacity = this->arrayCapacity * 2;
         /*
        for (int i = 0; i < this->arraySize; i++)               // loop through and copy the elements of temp into myArray now that it has been doubled
        {
            this->myArray[i] = temp[i];

        }
        delete []temp;
        this->arrayCapacity = this->arrayCapacity * 2;         //doubles the array capacity
        */




    }
    int arraySizeconst = this->arraySize;
    int counterForOther = 0;
    for (int i = this->arraySize; i <= (arraySizeconst + other.arraySize - 1); i++)                       //unfinished algorithm for adding the other array's contents to this->myArray
    {
        this->myArray[i] = other.myArray[counterForOther];
        this->arraySize = arraySize + 1;
        counterForOther++;
    }

    int arrayCap = arrayCapacity;
    double sortedArray[arrayCap];
    for (int i = 0; i < arraySize; i++) {          //creating a non-pointer array to sort
        sortedArray[i] = myArray[i];
    }
    std::sort(sortedArray, sortedArray + arraySize);     //sorts the sortedArray

    for (int i = 0; i < arraySize; i++) {          //copying back the data from sortedArray to myArray
        myArray[i] = sortedArray[i];
    }


    return *this;
}