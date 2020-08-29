#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>

class Collection {
public:
  Collection();
  Collection(int size);
  virtual int getSize() const;
  virtual int getCapacity() const;
  virtual void add(double item);
  virtual double get(int ndx) const;
  virtual int find(double needle) const;
  virtual double getFront() const;
  virtual double getEnd() const;
  virtual void removeFront();
  virtual void removeEnd();
  virtual void remove(double item);
  virtual double& operator[](int ndx);

  ~Collection()
  {

      delete []myArray;

  }

  Collection(Collection& origClass);
  virtual Collection& operator=(const Collection& classToCopy);

  virtual Collection& operator-(int count);
  virtual Collection& operator+(double item);
  virtual Collection& operator+(const Collection& other);
  virtual Collection& operator<<(double item);
  friend std::ostream& operator<<(std::ostream& out, const Collection& other);

   double* myArray;    //creating the array that is part of the object
   int arraySize;          //keeps track of how many active members are in the array
   int arrayCapacity;    //keeps track of the total amount of members alllowed in the array
};
#endif
