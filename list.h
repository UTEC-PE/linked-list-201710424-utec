#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

        void print_reverse(Node<T>* head);

    public:
        List(){
          head = NULL;
          tail = NULL;
        };

        T front(){
          return head->data;
        };
        T back(){
          return tail->data;
        };
        void push_front(T value){
          Node<T> *temp = new Node<T>;
          temp->data = value;
          temp->next = head;
          if(head==NULL){
            head = temp;
            tail = temp;
            temp = NULL;
          }
          else{
            head=temp;
          }
        };
        void push_back(T value){
          Node<T> *temp = new Node<T>;
          temp->data = value;
          temp->next = NULL;
          if(head==NULL){
            head = temp;
            tail = temp;
            temp = NULL;
          }
          else{
            tail->next=temp;
            tail=temp;
          }
        };
        void pop_front(){
          head->data = head->next->data;
          head = head->next;
        };
        void pop_back(){
        };
        T get(int position);
        void concat(List<T> &other);
        bool empty();
        int size();
        void print();
        void print_reverse();
        void clear();
        Iterator<T> begin();
        Iterator<T> end();

        ~List(){
          delete this;
        };
};
#endif
