#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    struct Node* next = nullptr;

    void print_reverse(){
      if (this->next) {
        this->next->print_reverse();
      }
      cout << this->data <<"\n";
    };

    void killSelf(){
      if (this->next) {
        this->next->killSelf();
      }
      delete this;
    };
};

#endif
