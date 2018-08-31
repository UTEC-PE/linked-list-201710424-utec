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

        void print_reverse(Node<T>* head){
          if (!this->head) {
            throw("Lista vacia."); // Si la lista está vacía, no se imprime nada. No deberíamos mostrar error
          }else{
            this->head->print_reverse();
          }
        };

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
          Node<T> *temp = new Node<T>{value, this->head};
          this->nodes++;
          this->head = temp;
          if(this->head==nullptr){ // Esto nunca se va a dar porque estás igualando head a temp en el paso anterior. Revisa la implementación que no está muy bien
            this->tail = temp;
          }
          temp = nullptr;
          delete temp;
        };
        void push_back(T value){ // Igual que el caso anterior, revisa la implementación que no está bien
          Node<T> *temp = new Node<T>{value, nullptr};
          this->nodes++;
          if(head==nullptr){
            this->head = temp;
          }
          else{
            this->tail->next=temp;
          }
          this->tail=temp;
          temp = nullptr;
          delete temp;
        };
        void pop_front(){ // No te olvides de dar delete para liberar memoria
          if(!this->head){
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
            Node<T> *temp = new Node<T>; // No es necesario dar new
            temp = this->head;
            while (temp->next!=tail) {
              temp = temp->next;
            }
            temp->next = nullptr;
            this->tail = temp;
            this->nodes--;
            temp = nullptr;
            delete temp;
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
          this->nodes = this->nodes + other.nodes;
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
              }else{
                temp = nullptr;
                delete temp;
                break;
              }
            }
          }
        };
        void print_reverse(){
          if(!this->head){
            cout << "Lista vacia \n";
          }else{
            head->print_reverse();
          }
        };
        void clear(){ // Esto está mal, deberías dar delete a todos los elementos de la lista y no solo apuntar a nullptr
          this->head=nullptr;
          this->tail=nullptr;
          this->nodes=0;
        };
        Iterator<T> begin();
        Iterator<T> end();

        /*~List(){ 
          if (this->head) {
            this->head->killSelf();
          }
          delete[] head;
          delete[] tail;
        };*/
};
#endif
