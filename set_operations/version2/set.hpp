#ifndef __SET_HPP__
#define __SET_HPP__

#include <iostream>
#include <set>

using namespace std;

class MySet{

public:
  MySet() { }
  MySet(set<int> x);
  
  MySet* myunion(MySet *s);
  MySet* intersect(MySet *s);
  MySet* diff(MySet *s);
  MySet* complement(MySet *universe);
  
  set<int> getElements();
  void setElement(int x);
  int cardinality();
  bool check(int x);
  bool subset(MySet* s);
  
  void print();
  
private:
  set<int> _elem;
};


#endif 
