# Collection and Sorted Collection

An array is great for storing a list of values.  However, one challenge when working
with arrays is they have a fixed size.  If you declare an array of size 10 and
later need to actually store 11 elements you have to create a new array and copy
everything over.  C++ (and other langauges) create classes that handle this and
other operations behind the scenes.
In this assignment, we will be creating our own class to manage an array of
doubles.  The class shoule allow the array to grow everytime more space is
needed.  It should automatically create larger arrays as needed and copy over
the existing values.  We will also be creating a subclass that keeps
the values in "sorted-order" as they are inserted so that the smallest value is first,
the next smallest is second and so on.

## Goals:
The purpose of this project is to continue working with C++ classes, incorporate
dynamic memory management, and use inheritance to add new functionality to a class.

## Requirements:
Code construction can be divided into three primary tasks:

### 1. **Collection class**

Create a class named **Collection** that will store double values in an array.
You will need to implement the following public methods.


+ Default constructor.
+ Single-argument constructor that takes and integer parameter and uses it to set
the initial capacity of the array
+ getSize - returns the number of elements in the array. Unlike c-strings where
we had a null-terminator to mark the end of the array, in this case you will
need a variable to keep track of the number of elements currently in the array.
+ getCapacity - returns the maximum number of elements allowed in the current
array.  Again you will probably want to store this value in a variable and update
it each time you grow the array to a new size.
+ add - Adds the double to the end of the array.  If the array is full it should
create a new array that is twice as large and copy all of the existing elements
over.
+ get - Gets the value stored at the specified position. Throws and out_of_range
exception if the index is outside the bounds of the array.
+ find - Returns the index of the specified value in the array or -1 if the
value is not found.
+ getFront - Returns the first value in the array. Throws an out_of_range
exception if the array is empty.
+ getEnd - Returns the last value in the array.  Throws and out_of_range
exception if the array is empty.
+ removeFront - Removes the first value in the array and moves everything else
over.  If the array is empty this method has no effect.
+ removeEnd - Removes the last value in the array.  If the array is empty this
method has no effect.
+ remove - Removes the specified value from the array.  If there are multiple
instances of the same value in the array it removes the first instance. If the
value does not occur in the array this method has no effect.
+ operator[] - Allows the class to be accessed like an array (i.e. returns the
value stored in the specifed position as a reference.
+ operator- - Removes the specified number of items from the end of the array.
if the number of items to remove is more than there are items in the array all
the existing items in the array are removed. Returns a reference to this
instance so that the operator can be chained.
+ operator+ - Adds the double to the end of the array.  If the array is full it
should create a new array that is twice as large and copy all of the existing
elements over. Returns a reference to this instance so that the operator can be
chained.
+ operator+(const Collection& other) - Adds all of the elements from the other
Collection.  When the array fills up, it will need to be resized and copied like
always. Returns a reference to this instance so that the operator can be chained.
+ operator<< - Adds the double to the end of the array.  If the array is full it
should create a new array that is twice as large and copy all of the existing
elements over. Returns a reference to this instance so that the operator can be
chained.
+ friend operator<<(std::ostream& out, const Collection& other) - Outputs the
values in the array to the provided output stream.


### 2. **Collection Class Memory-Management**

In addition the to public methods required to pass the test cases, you will also
need to implement a copy-constructor, overloaded assignment operator, and destructor
to perform deep-copies of the storage array.

### 3.  **SortedCollection Class with Inheritance**

Finally, you will need to create a SortedCollection class which inherits from
the Collection class.  It will need to override any methods needed to make the
class store values in sorted order (i.e. from smallest to largest).  The key here
is to realize that the only methods which need to change are those in which new
items are added to the array.  All the other methods behave identically in both
classes and thus do not need to be re-implemented but can simply be inherited.
