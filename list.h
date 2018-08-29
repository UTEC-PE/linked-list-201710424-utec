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
          head = nullptr;
          tail = nullptr;
          this->nodes=0;
        };

        T front(){
          if (!this->head) {
            throw("Lista vacia.");
          }else
            return head->data;
        };
        T back(){
          if (!this->tail) {
            throw("Lista vacia.");
          }else
            return tail->data;
        };
        void push_front(T value){
          Node<T> *temp = new Node<T>;
          temp->data = value;
          temp->next = head;
          this->nodes++;
          head = temp;
          if(head==nullptr){
            tail = temp;
          }
          temp = nullptr;
          delete temp;
        };
        void push_back(T value){
          Node<T> *temp = new Node<T>;
          temp->data = value;
          temp->next = nullptr;
          this->nodes++;
          if(head==nullptr){
            head = temp;
          }
          else{
            tail->next=temp;
          }
          tail=temp;
          temp = nullptr;
          delete temp;
        };
        void pop_front(){
          if(this->head==nullptr){
            throw("Lista vacia.");
          }else if(this->head==this->tail){
            this->head=nullptr;
            this->tail=nullptr;
            this->nodes--;
          }else{
            this->head = this->head->next;
            this->nodes--;
          }
        };
        void pop_back(){
          if(this->head==nullptr){
            throw("Lista vacia.");
          }else if(this->head==this->tail){
            this->head=nullptr;
            this->tail=nullptr;
            this->nodes--;
          }else{
            Node<T> *temp = new Node<T>;
            temp = this->head;
            while (temp->next!=tail) {
              temp = temp->next;
            }
            temp->next = nullptr;
            this->tail = temp;
            this->nodes--;
            temp = nullptr;
          }
        };
        T get(int position){
          if (!this->head) {
            throw("Lista vacia.");
          }else{
            Node<T> *temp = this->head;
            for (int i = 0; i < position; i++) {
              temp = temp->next;
            }
            return temp->data;
          }
        };
        void concat(List<T> &other){
          this->tail->next = other.head;
          this->tail = other.tail;
        };
        bool empty(){
          return !this->head;
        };
        int size(){
          return this->nodes;
        };
        void print(){
          if(!this->head){
            cout << "Lista vacia.\n";
          }else{
            Node<T> *temp = this->head;
            while (temp->next || temp == this->tail) {
              cout<< temp->data << "\n";
              if (temp != this->tail) {
                temp = temp->next;
              }else break;
            }
          }
        };
        void print_reverse(){
          if(!this->head){
            cout << "Lista vacia \n";
          }else{
            Node<T> *temp_2 = this->tail;
            Node<T> *temp_1 = this->head;
            while (temp_1->next || temp_2 == this->head){
              if (temp_1 == temp_2) {
                cout << temp_2->data <<"\n";
                break;
              }else if (temp_1->next != temp_2) {
                temp_1 = temp_1->next;
              }else if(temp_1->next){
                cout <<temp_2->data <<"\n";
                temp_2 = temp_1;
                temp_1 = this->head;
              }
            }
          }
        };
        void clear(){
          this->head=nullptr;
          this->tail=nullptr;
          this->nodes=0;
        };
        Iterator<T> begin();
        Iterator<T> end();

        /*~List(){
          delete[] this;
        };*/
};
#endif
