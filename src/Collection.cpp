#include "Collection.h"
#include <stdexcept>
#include <algorithm>
#include <array>
using std::out_of_range;

Collection::Collection(){
    myArray = new double[8];
    arraySize = 0;                         //builds the default collection object, size of 8 randomly chosen
    arrayCapacity = 8;
}
Collection::Collection(int size)
{
    myArray = new double[size];             //function uses variables of object Collection to set the size of myArray to argument size
    arraySize = 0;
    arrayCapacity = size;
}

Collection::Collection(Collection& originalClass)
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




}

Collection& Collection::operator=(const Collection& classToCopy)
{
    delete []myArray;                    //delete the old array

    arraySize = 0;

    myArray = new double[classToCopy.arraySize];        //function performs deep copy
    arrayCapacity = classToCopy.arrayCapacity;         //set the capacity the same to original class


    for (int i = 0; i < classToCopy.arraySize; i++)
    {
        myArray[i] = classToCopy.myArray[i];
        arraySize = arraySize + 1;                 //set size to that of the original class
    }


}



int Collection::getSize() const{
    return arraySize;                                                       //returns the size of the array
}
int Collection::getCapacity() const{
   return arrayCapacity;                                                   //returns the capacity of the array
}
double Collection::get(int ndx) const{
   /*if (ndx > arraySize) {
       throw out_of_range("Out of bounds. ");
   } */
    return myArray[ndx];                                                    //returns the double value based on the index sent as an argument
}
double Collection::getFront() const{                                          //gets the front member of the array
   if (myArray[0] == 0)
   {
       throw out_of_range("Out of bounds. ");                                  //checks if out of bounds
   }
    return myArray[0];                                                         //front of the array is automatically 0
}
double Collection::getEnd() const{
    if (arraySize == 0)
    {
       throw out_of_range("Out of bounds. ");                                 //catches if array is empty
    }
   return myArray[arraySize - 1];                                             //returns the end of the array, - 1 due to arrays starting at 0
}
int Collection::find(double needle) const{
    int position = 0;       //holder for any found positions, defaults to -1
    if (arraySize == 0 )      //checks if the first position is 0, returns -1;
    {
        return -1;
    }

    for (int i = 0; i <= arraySize - 1; i++)         //initialize the loop to go through the array contents
    {
                         //create that temporary string to hold the value, most likely unneccessary
        if (myArray[i] == needle)                          //checking
        {
            position = i;                       //scrapped
            return i;
        }
    }

    return -1;
}
void Collection::add(double item){
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
              myArray = new double[this->arraySize * 2];

              for (int i = 0; i < this->arraySize; i++)               // loop through and copy the elements of temp into myArray now that it has been doubled
              {
                  this->myArray[i] = temp[i];

              }
              delete []temp;
              this->arrayCapacity = this->arrayCapacity * 2;         //doubles the array capacity





          }



          myArray[arraySize] = item;
          arraySize = arraySize + 1;

      }
      else
      {
          myArray[arraySize] = item;
          arraySize = arraySize + 1;
      }

}


void Collection::removeFront(){
    if (arraySize > 0)                          //checks if array is populated
    {
        //double temp;
        //temp = myArray[0];
        int counter = 1;                       //counter to iterate through the array, stars at 1 because front is removed
                                //set front to 0 since it is removed
        while (counter < arraySize)           //iterate until it gets to the last array member
        {
            myArray[counter - 1] = myArray[counter];                //perform the swap
            counter++;                                              //update counter
        }
        myArray[arraySize - 1] = 0;                                //because front value is removed, all members shift down by 1, thus we must set the last member to 0
        arraySize = arraySize - 1;                                 //decrease the array size because front member was removed
    }
    else
    {
        //throw out_of_range("nothing in the array to remove");
    }
}
void Collection::removeEnd(){
    if (arraySize > 0)                                         //checks if array is empty
    {
                                  // sets the end to 0 since it was removed
        arraySize = arraySize - 1;                            //reduce the array size by 1
    }


}
void Collection::remove(double item){
    if (arraySize > 0)                          //checks if array is populated
    {
        int flag = 0;                          //flag used to determine if the loop needs to be executed
        int counter;                           //counter not initialized in remove, initializes when the for loop below flags the index of item
        for (int i = 0; i < arraySize; i++)
        {
            if (myArray[i] == item)                       //loop that checks the array for item, flags if it is in
            {
                counter = i;
                flag = 1;
                break;
            }
        }



        //double temp;
        //temp = myArray[0];
                               //counter to iterate through the array, stars at 1 because front is removed

        if (flag == 1) {
            myArray[counter] = 0;
            while (counter < arraySize && flag == 1)           //iterate until it gets to the last array member
            {
                if (counter !=
                    arraySize - 1)                             //check if counter is at the last index that has a value
                {
                    myArray[counter] = myArray[counter + 1];                //perform the swap
                    counter++;
                }
                if (counter == arraySize -
                               1)                                //checks if counter is at last index, will turn it 0 since we know that index exists in the array in this loop
                {
                    myArray[arraySize - 1] = 0;
                    counter++;
                }
                //update counter
            }
            if (flag == 1)                                //uses flag
            {
                arraySize = arraySize - 1;                                 //arraySize is decreased by 1 if the sentinel value is triggered
            }
        }
    }

}
double& Collection::operator[](int ndx){
   //TODO:remove tmp and return a refernce
   //to the actual value in the collection

   return this->myArray[ndx];
}

Collection& Collection::operator-(int count){
    if (arraySize > 0)                                         //checks if array is empty
    {
        while (count > 0)
        {
            if((arraySize) - count >= 0)
            {
                myArray[arraySize - count] = 0;
                arraySize = arraySize - 1;
                count--;
            }
             else
            {
                 count--;
            }// sets the end to 0 since it was removed
                                        //reduce the array size by 1
        }

    }
    else
    {
        throw out_of_range("nothing in the array to remove");                 //else statement if array is empty
    }
    return *this;
}
Collection& Collection::operator+(double item){
   /* if (arraySize == arrayCapacity)
    {
        double temp[arraySize * 2];
        *temp = *myArray;
        *myArray = *temp;
        arrayCapacity = arrayCapacity * 2;

    }  */



    //double *temp = new double[this->arraySize *2];
    //std::copy(this[0], this[arraySize -1], temp);

                                                      //copied array size function from operator+(Collection& other)
        if (this->arraySize + 1 > arrayCapacity || arraySize == arrayCapacity)                                      //check if the array is full
        {
            double *temp = new double[this->arraySize * 2];
            for (int i = 0; i < this->arraySize; i++)                           // loop through and copy the elements of myArray into temp
            {
                temp[i] = this->myArray[i];
            }
            delete []myArray;                                                  //deleting the original array
            myArray = new double[this->arraySize * 2];

            for (int i = 0; i < this->arraySize; i++)               // loop through and copy the elements of temp into myArray now that it has been doubled
            {
                this->myArray[i] = temp[i];

            }
            delete []temp;
            this->arrayCapacity = this->arrayCapacity * 2;         //doubles the array capacity





        }



        myArray[arraySize] = item;
        arraySize = arraySize + 1;

   return *this;
}
Collection& Collection::operator+(const Collection& other){
     if (this->arraySize + 1 > arrayCapacity || this->arraySize == this->arrayCapacity || this->arraySize + other.arraySize > this->arrayCapacity)                                       //check if the array is full
    {
        double *temp = new double[this->arraySize * 2];
        for (int i = 0; i < this->arraySize; i++)                           // loop through and copy the elements of myArray into temp
        {
            temp[i] = this->myArray[i];
        }
        delete []myArray;                                                  //deleting the original array
        myArray = new double[this->arraySize * 2];

        for (int i = 0; i < this->arraySize; i++)               // loop through and copy the elements of temp into myArray now that it has been doubled
        {
            this->myArray[i] = temp[i];

        }
        delete []temp;
        this->arrayCapacity = this->arrayCapacity * 2;         //doubles the array capacity





    }
     int arraySizeconst = this->arraySize;
     int counterForOther = 0;
     for (int i = this->arraySize; i <= (arraySizeconst + other.arraySize - 1); i++)                       //unfinished algorithm for adding the other array's contents to this->myArray
    {
        this->myArray[i] = other.myArray[counterForOther];
        this->arraySize = arraySize + 1;
        counterForOther++;
    }



    return *this;
}
Collection& Collection::operator<<(double item){
   return *this;
}
std::ostream& operator<<(std::ostream& out, const Collection& other){
   return out;
}

