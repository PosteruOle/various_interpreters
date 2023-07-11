#include <iostream>
#include <set>
#include "set.hpp"

MySet::MySet(set<int> x){
   _elem=x;
}

void MySet::print(){
    cout << "{";
    auto it=_elem.begin();
    if(_elem.size()==0){
      cout << "}\n";
      return;
    }
    for(it=_elem.begin();it!=--_elem.end();it++){
       cout << *it << ", ";
    }
    cout << *it << "}" << endl;
}

int MySet::cardinality(){
   return _elem.size();
}

set<int> MySet::getElements(){
   return _elem;
}

MySet* MySet::myunion(MySet* s){
   set<int> tmp=s->getElements();
   
   for(auto it=_elem.begin();it!=_elem.end();it++){
      tmp.insert(*it);
   }

   MySet* result=new MySet(tmp);
   return result;
} 

MySet* MySet::intersect(MySet *s){
   set<int> tmp;
   set<int> pom=s->getElements();
   for(auto it=_elem.begin();it!=_elem.end();it++){
      if(pom.find(*it)!=pom.end())
        tmp.insert(*it);
   }
   MySet* result=new MySet(tmp);
   return result;
}

void MySet::setElement(int x){
    _elem.insert(x);
}

MySet* MySet::diff(MySet *s){
    set<int> tmp;
    set<int> pom=s->getElements();
    for(auto it=_elem.begin();it!=_elem.end();it++){
       if(pom.find(*it)==pom.end())
         tmp.insert(*it);
    }
    MySet* result=new MySet(tmp);    
    return result;
}

bool MySet::check(int x){
    
    for(auto it=_elem.begin(); it!=_elem.end();it++){
       if(*it==x)
         return true;
    } 
    return false;
}

MySet* MySet::complement(MySet *universe){
    set<int> tmp;
    set<int> pom=universe->getElements();
    for(auto it=pom.begin();it!=pom.end();it++){
       if(_elem.find(*it)==_elem.end())
         tmp.insert(*it);
    }
    MySet* result=new MySet(tmp);
    return result;
}

bool MySet::subset(MySet* s){
    set<int> tmp=s->getElements();
    for(auto it=_elem.begin();it!=_elem.end();it++){
       if(tmp.find(*it)==tmp.end())
         return false;
    }
    return true;
}
