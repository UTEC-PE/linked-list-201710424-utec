#include "list.h"
#include <iostream>

int main(){
  List<int> listita;
  listita.push_back(3);
  listita.push_front(2);
  listita.push_back(4);
  listita.push_front(1);
  listita.push_back(5);
  //listita.clear();
  listita.pop_front();
  listita.pop_back();
  cout << listita.front() <<"\n";
  cout << listita.back() <<"\n";
  //cout << listita.empty() <<"\n";
  //cout << listita.size() <<"\n";
  listita.print();
  listita.print_reverse();
  cout << listita.get(1) <<"\n";
  List<int> listota;
  listota.push_back(3);
  listota.push_front(2);
  listota.push_back(4);
  listota.push_front(1);
  listota.push_back(5);
  listota.concat(listita);
  listota.print();
  return 0;
}
