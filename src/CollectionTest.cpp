#include <iostream>
#include <string>
#include <chrono>
#include <stdexcept>
#include "Collection.h"
#include "SortedCollection.h"

using std::string;
using std::cout;
using std::endl;
using std::out_of_range;
using std::chrono::high_resolution_clock;
using std::chrono::duration;


bool TestConstructors();
bool TestAdd();
bool TestFind();
bool TestRemoves();
bool TestOperators();
bool TestExceedSize();
bool TestDeepCopies();
bool TestSortedCollection();
void TestOptional();
void TestTiming();
template <typename T>
bool checkCase(string name, T a, T e);

int main()
{
   int required = 0;
   required += TestConstructors();
   required += TestAdd();
   required += TestFind();
   required += TestRemoves();
   required += TestOperators();
   required += TestExceedSize();
   required += TestDeepCopies();
   required += TestSortedCollection();
   if (required != 8){
      cout << "You have not passed all required tests" << endl;
      cout << "Passed " << required << "/" << 8 << " tests" << endl;
      cout << "Score: 0" << endl;
      exit(1);
   }
   else{
      cout << "******************************************" << endl;
      cout << "Passed 8/8 required tests" << endl;
      cout << "******************************************" << endl;
   }
   TestOptional();
   TestTiming();
   return 0;
}

bool TestConstructors(){
   cout << "---------------Constructors--------------" << endl;
   bool passed = true;
   Collection c1;
   passed &= checkCase("Constructors 1", c1.getSize(), 0);
   passed &= checkCase("Constructors 2", c1.getCapacity(), 8);
   Collection c2(4);
   passed &= checkCase("Constructors 3", c2.getSize(), 0);
   passed &= checkCase("Constructors 4", c2.getCapacity(), 4);
   return passed;
}

bool TestAdd(){
   cout << "---------------Add--------------" << endl;
   bool passed = true;
   Collection c1;
   c1.add(5.5);
   passed &= checkCase("Add 1", c1.get(0), 5.5);
   passed &= checkCase("Add 2", c1.getSize(), 1);
   passed &= checkCase("Add 3", c1.getCapacity(), 8);
   c1.add(3.25);
   passed &= checkCase("Add 4", c1.get(1), 3.25);
   passed &= checkCase("Add 5", c1.getSize(), 2);
   c1.add(4.75);
   passed &= checkCase("Add 6", c1.get(2), 4.75);
   passed &= checkCase("Add 7", c1.getSize(), 3);
   return passed;
}

bool TestFind(){
   cout << "---------------Find--------------" << endl;
   bool passed = true;
   Collection c1;
   c1.add(5.5);
   passed &= checkCase("Find 1", c1.find(5.5), 0);
   passed &= checkCase("Find 2", c1.find(4.5), -1);
   c1.add(35.5);
   passed &= checkCase("Find 3", c1.find(5.5), 0);
   passed &= checkCase("Find 4", c1.find(35.5), 1);
   c1.add(2.25);
   c1.add(21.5);
   c1.add(15.0);
   passed &= checkCase("Find 5", c1.find(5.5), 0);
   passed &= checkCase("Find 6", c1.find(15.0), 4);
   passed &= checkCase("Find 7", c1.find(2.25), 2);
   passed &= checkCase("Find 8", c1.find(37.5), -1);
   return passed;
}

bool TestRemoveEnd(){
   cout << "---------------RemoveEnd--------------" << endl;
   bool passed = true;
   Collection c1;
   c1.add(3.5);
   c1.removeEnd();
   passed &= checkCase("RemoveEnd 1", c1.getSize(), 0);
   passed &= checkCase("RemoveEnd 2", c1.find(3.5), -1);
   c1.add(3.0);
   c1.add(1.5);
   passed &= checkCase("RemoveEnd 3", c1.getSize(), 2);
   c1.removeEnd();
   passed &= checkCase("RemoveEnd 4", c1.getSize(), 1);
   passed &= checkCase("RemoveEnd 5", c1.find(1.5), -1);
   passed &= checkCase("RemoveEnd 6", c1.get(0), 3.0);
   c1.add(6.75);
   c1.add(3.25);
   passed &= checkCase("RemoveEnd 7", c1.getSize(), 3);
   c1.removeEnd();
   passed &= checkCase("RemoveEnd 8", c1.getSize(), 2);
   passed &= checkCase("RemoveEnd 9", c1.find(3.25), -1);
   passed &= checkCase("RemoveEnd 10", c1.get(0), 3.0);
   passed &= checkCase("RemoveEnd 11", c1.get(1), 6.75);
   return passed;
}

bool TestRemoveFront(){
   cout << "---------------RemoveFront--------------" << endl;
   bool passed = true;
   Collection c1;
   c1.add(3.5);
   c1.removeFront();
   passed &= checkCase("RemoveFront 1", c1.getSize(), 0);
   passed &= checkCase("RemoveFront 2", c1.find(3.5), -1);
   c1.add(3.0);
   c1.add(1.5);
   passed &= checkCase("RemoveFront 3", c1.getSize(), 2);
   c1.removeFront();
   passed &= checkCase("RemoveFront 4", c1.getSize(), 1);
   passed &= checkCase("RemoveFront 5", c1.find(3.0), -1);
   passed &= checkCase("RemoveFront 6", c1.get(0), 1.5);
   c1.add(6.75);
   c1.add(3.25);
   passed &= checkCase("RemoveFront 7", c1.getSize(), 3);
   c1.removeFront();
   passed &= checkCase("RemoveFront 8", c1.getSize(), 2);
   passed &= checkCase("RemoveFront 9", c1.find(1.5), -1);
   passed &= checkCase("RemoveFront 10", c1.get(0), 6.75);
   passed &= checkCase("RemoveFront 11", c1.get(1), 3.25);
   return passed;
}

bool TestRemove(){
   cout << "---------------Remove--------------" << endl;
   bool passed = true;
   Collection c1;
   c1.add(3.5);
   c1.remove(3.5);
   passed &= checkCase("Remove 1", c1.getSize(), 0);
   passed &= checkCase("Remove 2", c1.find(3.5), -1);
   c1.add(3.0);
   c1.add(1.5);
   passed &= checkCase("Remove 3", c1.getSize(), 2);
   c1.remove(3.0);
   passed &= checkCase("Remove 4", c1.getSize(), 1);
   passed &= checkCase("Remove 5", c1.find(3.0), -1);
   passed &= checkCase("Remove 6", c1.get(0), 1.5);
   c1.add(6.75);
   c1.add(3.25);
   passed &= checkCase("Remove 7", c1.getSize(), 3);
   c1.remove(6.75);
   passed &= checkCase("Remove 8", c1.getSize(), 2);
   passed &= checkCase("Remove 9", c1.find(6.75), -1);
   passed &= checkCase("Remove 10", c1.get(0), 1.5);
   passed &= checkCase("Remove 11", c1.get(1), 3.25);
   return passed;
}

bool TestRemoves(){
   cout << "---------------Removes--------------" << endl;
   bool passed = true;
   passed &= TestRemoveEnd();
   passed &= TestRemoveFront();
   passed &= TestRemove();
   return passed;
}

bool TestSubscript(){
   cout << "---------------Operator[]--------------" << endl;
   bool passed = true;
   Collection c1;
   c1.add(5.5);
   passed &= checkCase("Operator[] 1", c1[0], 5.5);
   c1.add(3.25);
   passed &= checkCase("Operator[] 2", c1[1], 3.25);
   c1.add(4.75);
   c1.add(6.25);
   c1.add(3.75);
   passed &= checkCase("Operator[] 3", c1[4], 3.75);
   passed &= checkCase("Operator[] 4", c1[2], 4.75);
   passed &= checkCase("Operator[] 5", c1[3], 6.25);
   c1[0] = 1.0;
   c1[3] = 2.0;
   passed &= checkCase("Operator[] 6", c1.get(0), 1.0);
   passed &= checkCase("Operator[] 7", c1.get(3), 2.0);
   return passed;
}

bool TestMinus(){
   cout << "---------------Operator(-)--------------" << endl;
   bool passed = true;
   Collection c1;
   c1.add(25.5);
   c1 - 1;
   passed &= checkCase("Operator- 1", c1.getSize(), 0);
   passed &= checkCase("Operator- 2", c1.find(25.5), -1);
   c1.add(4.75);
   c1.add(16.25);
   c1.add(13.75);
   c1 - 1;
   passed &= checkCase("Operator- 3", c1.getSize(), 2);
   passed &= checkCase("Operator- 4", c1.find(13.75), -1);
   passed &= checkCase("Operator- 5", c1.find(16.25), 1);
   c1.add(3.0);
   c1.add(1.5);
   c1.add(25.5);
   c1.add(13.75);
   c1 - 3;
   passed &= checkCase("Operator- 6", c1.getSize(), 3);
   passed &= checkCase("Operator- 7", c1.find(13.75), -1);
   passed &= checkCase("Operator- 8", c1.find(3.0), 2);
   c1.add(1.5);
   c1.add(25.5);
   c1.add(13.75);
   c1 - 2 - 2;
   passed &= checkCase("Operator- 9", c1.getSize(), 2);
   c1 - 2;
   passed &= checkCase("Operator- 10", c1.getSize(), 0);
   return passed;
}

bool TestPlus(){
   cout << "---------------Operator+--------------" << endl;
   bool passed = true;
   Collection c1;
   c1 + 25.5;
   passed &= checkCase("Operator+ 1", c1.getSize(), 1);
   passed &= checkCase("Operator+ 2", c1.get(0), 25.5);
   c1 + 4.75;
   c1 + 16.25 + 13.75;
   passed &= checkCase("Operator+ 3", c1.getSize(), 4);
   passed &= checkCase("Operator+ 4", c1.find(4.75), 1);
   passed &= checkCase("Operator+ 5", c1.get(2), 16.25);
   Collection c2;
   c2.add(1.5);
   c2.add(22.5);
   c2.add(13.75);
   c1 + c2;
   passed &= checkCase("Operator+ 6", c1.getSize(), 7);
   passed &= checkCase("Operator+ 7", c1.get(5), 22.5);
   passed &= checkCase("Operator+ 8", c1.get(3), 13.75);
   return passed;
}

bool TestOperators(){
   cout << "---------------Operators--------------" << endl;
   bool passed = true;
   passed &= TestSubscript();
   passed &= TestMinus();
   passed &= TestPlus();
   return passed;
}

bool TestExceedSize(){
   cout << "---------------Auto-Grow--------------" << endl;
   bool passed = true;
   Collection c1(2);
   c1 + 2.5 + 23.25;
   passed &= checkCase("Auto-Grow 1", c1.getSize(), 2);
   passed &= checkCase("Auto-Grow 2", c1.getCapacity(), 2);
   c1 + 4.0;
   passed &= checkCase("Auto-Grow 3", c1.getSize(), 3);
   passed &= checkCase("Auto-Grow 4", c1.getCapacity(), 4);
   passed &= checkCase("Auto-Grow 5", c1.get(0), 2.5);
   passed &= checkCase("Auto-Grow 6", c1.get(2), 4.0);
   Collection c2(2);
   c2 + 6.5 + 83.25;
   c2.add(2.0);
   passed &= checkCase("Auto-Grow 7", c2.getSize(), 3);
   passed &= checkCase("Auto-Grow 8", c2.getCapacity(), 4);
   passed &= checkCase("Auto-Grow 9", c2.get(0), 6.5);
   passed &= checkCase("Auto-Grow 10", c2.get(2), 2.0);
   c1 + c2;
   passed &= checkCase("Auto-Grow 11", c1.getSize(), 6);
   passed &= checkCase("Auto-Grow 12", c1.getCapacity(), 8);
   passed &= checkCase("Auto-Grow 13", c1.get(0), 2.5);
   passed &= checkCase("Auto-Grow 14", c1.get(2), 4.0);
   passed &= checkCase("Auto-Grow 15", c1.get(3), 6.5);
   passed &= checkCase("Auto-Grow 16", c1.get(5), 2.0);
   Collection c3;
   for(int i = 0; i < 100; i++){
     c3.add(i);
   }
   passed &= checkCase("Auto-Grow 17", c3[0], 0.0);
   passed &= checkCase("Auto-Grow 18", c3[99], 99.0);
   passed &= checkCase("Auto-Grow 19", c3.getSize(), 100);
   return passed;
}

bool TestDeepCopies(){
   cout << "---------------Deep Copies--------------" << endl;
   bool passed = true;
   Collection c1;
   c1 + 2.5 + 23.25;
   Collection c2(c1);
   passed &= checkCase("Deep Copies 1", c2.getSize(), 2);
   passed &= checkCase("Deep Copies 2", c2.getCapacity(), 8);
   c2[1] = 18.5;
   passed &= checkCase("Deep Copies 3", c1[1], 23.25);
   passed &= checkCase("Deep Copies 4", c2[1], 18.5);
   Collection c3;
   for(int i = 0; i < 10; i++){
     c3.add(i);
   }
   c3 = c1;
   passed &= checkCase("Deep Copies 5", c3.getSize(), 2);
   passed &= checkCase("Deep Copies 6", c3.getCapacity(), 8);
   c3[1] = 20.75;
   passed &= checkCase("Deep Copies 7", c1[1], 23.25);
   passed &= checkCase("Deep Copies 8", c3[1], 20.75);
   return passed;
}

bool TestSortedCollection(){
   cout << "---------------SortedCollection--------------" << endl;
   bool passed = true;
   SortedCollection sc1;
   passed &= checkCase("SortedCollection 1", sc1.getSize(), 0);
   passed &= checkCase("SortedCollection 2", sc1.getCapacity(), 8);
   sc1.add(4.25);
   passed &= checkCase("SortedCollection 3", sc1.getSize(), 1);
   passed &= checkCase("SortedCollection 4", sc1.get(0), 4.25);
   sc1.add(1.5);
   sc1.add(3.25);
   sc1.add(6.75);
   passed &= checkCase("SortedCollection 5", sc1[0], 1.5);
   passed &= checkCase("SortedCollection 6", sc1[2], 4.25);
   passed &= checkCase("SortedCollection 7", sc1[3], 6.75);
   passed &= checkCase("SortedCollection 8", sc1.find(3.25), 1);
   sc1.removeEnd();
   passed &= checkCase("SortedCollection 9", sc1.getSize(), 3);
   passed &= checkCase("SortedCollection 10", sc1[2], 4.25);
   passed &= checkCase("SortedCollection 11", sc1.find(6.75), -1);
   SortedCollection sc2;
   sc2 + 4.0 + 7.0 + 2.0 + 5.0;
   passed &= checkCase("SortedCollection 12", sc2.getSize(), 4);
   passed &= checkCase("SortedCollection 13", sc2.get(0), 2.0);
   passed &= checkCase("SortedCollection 14", sc2.get(1), 4.0);
   passed &= checkCase("SortedCollection 15", sc2.get(3), 7.0);
   passed &= checkCase("SortedCollection 16", sc2.find(5.0), 2);
   sc2.removeFront();
   passed &= checkCase("SortedCollection 17", sc2.getSize(), 3);
   passed &= checkCase("SortedCollection 18", sc2[0], 4.00);
   passed &= checkCase("SortedCollection 19", sc2.find(2.0), -1);
   SortedCollection sc3(sc2);
   sc3 + sc1;
   passed &= checkCase("SortedCollection 20", sc3.getSize(), 6);
   passed &= checkCase("SortedCollection 21", sc3.getCapacity(), 8);
   passed &= checkCase("SortedCollection 22", sc3.get(0), 1.5);
   passed &= checkCase("SortedCollection 23", sc3.get(2), 4.0);
   passed &= checkCase("SortedCollection 24", sc3.get(5), 7.0);
   passed &= checkCase("SortedCollection 25", sc2.get(0), 4.0); //Check Deep copy
   sc3.remove(4.0);
   passed &= checkCase("SortedCollection 26", sc3.getSize(), 5);
   passed &= checkCase("SortedCollection 27", sc3.find(4.0), -1);
   passed &= checkCase("SortedCollection 28", sc3.get(2), 4.25);
   sc3 + 1.0 + 9.0 + 3.0 + 1.5;
   passed &= checkCase("SortedCollection 29", sc3.getSize(), 9);
   passed &= checkCase("SortedCollection 30", sc3.getCapacity(), 16);
   passed &= checkCase("SortedCollection 31", sc3.get(0), 1.0);
   passed &= checkCase("SortedCollection 32", sc3.get(8), 9.0);
   return passed;
}

   //TestOptional();//Remove from empty array, Remove non-existing value, Additional access methods, Find on an empty array, Get out_of_bounds, [] out_of_bounds
void TestOptional(){
   cout << "---------------OptionalTests--------------" << endl;
   int correct = 0;
   Collection c1;
   //Remove from empty array
   c1.removeFront(); //silently ignore
   c1.removeEnd(); //silently ignore
   c1.remove(3.5); //silently ignore
   correct += checkCase("RemoveEmpty", c1.getSize(), 0);
   correct += checkCase("FindEmpty", c1.find(3.5), -1);
   c1.add(3.5);
   c1.remove(2.0); //Remove non-existing value
   correct += checkCase("FindEmpty", c1.getSize(), 1);
   c1 + 2.25 + 4.5;
   correct += checkCase("GetFront", c1.getFront(), 3.5);
   correct += checkCase("GetEnd", c1.getEnd(), 4.5);
   try{
      c1.get(5);
      checkCase("Out_of_range 1", "no exception", "out_of_range exception");
   }
   catch(const out_of_range& e){
      correct += checkCase("Out_of_range 1", 1, 1);
   }
   try{
      c1[3];
      checkCase("Out_of_range 2", "no exception", "out_of_range exception");
   }
   catch(const out_of_range& e){
      correct += checkCase("Out_of_range 2", 1, 1);
   }
   c1 - 6; //Just remove what can be removed.
   correct += checkCase("Operator- with extra", c1.getSize(), 0);
   try{
      c1.getFront();
      checkCase("Out_of_range 3", "no exception", "out_of_range exception");
   }
   catch(const out_of_range& e){
      correct += checkCase("Out_of_range 3", 1, 1);
   }
   try{
      c1.getEnd();
      checkCase("Out_of_range 4", "no exception", "out_of_range exception");
   }
   catch(const out_of_range& e){
      correct += checkCase("Out_of_range 4", 1, 1);
   }

   cout << "******************************************" << endl;
   cout << "Passed "  << correct << "/10 Optional tests" << endl;
   cout << "******************************************" << endl;
}

void TestTiming(){
   cout << "These tests are just to illustrate why Big O matters" << endl;
   cout << "Adding 30000 items to unsorted collection - add (to the end) is O(1)" << endl;
   Collection c1;
   auto start = high_resolution_clock::now();
   for(int i=0; i<30000; i++){
      c1.add(i);
   }
   auto end = high_resolution_clock::now();
   duration<double, std::milli> elapsed = end-start;
   cout << "Done in " << elapsed.count() << " ms" << endl;

   cout << "Adding 30000 items to sorted collection - add (in reverse order) is O(n)" << endl;
   SortedCollection sc1;
   start = high_resolution_clock::now();
   for(int i=29999; i>=0; i--){
      sc1.add(i);
   }
   end = high_resolution_clock::now();
   elapsed = end-start;
   cout << "Done in " << elapsed.count() << " ms" << endl;

   cout << "Removing 30000 items from end - removeEnd is O(1)" << endl;
   start = high_resolution_clock::now();
   for(int i=0; i<30000; i++){
      sc1.removeEnd();
   }
   end = high_resolution_clock::now();
   elapsed = end-start;
   cout << "Done in " << elapsed.count() << " ms" << endl;

   cout << "Removing 10000 items from front - removeFront is O(n)" << endl;
   start = high_resolution_clock::now();
   for(int i=0; i<30000; i++){
      c1.removeFront();
   }
   end = high_resolution_clock::now();
   elapsed = end-start;
   cout << "Done in " << elapsed.count() << " ms" << endl;

}

template <typename T>
bool checkCase(string name, T actual, T expected){
    bool condition = actual == expected;
    if(!condition){
            cout << "Failed: " << name;
            cout << " Expected: " << expected;
            cout << "Actual: " << actual << endl;
    }
    else{
            cout << name << ": passed" << endl;
    }
    return condition;
}
