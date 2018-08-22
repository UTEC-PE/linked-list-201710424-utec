#include "list.h"
#include <iostream>

int main(){
  List<int> *listita = new List<int>;
  listita->push_back(3);
  listita->push_front(2);
  listita->push_back(4);
  listita->push_front(1);
  listita->pop_front();
  cout << listita->front() <<"\n";
  cout << listita->back() <<"\n";
  return 0;
}
