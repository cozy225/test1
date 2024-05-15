#pragma once 
#include <iostream>
using namespace std;

template <class T>
struct Node{
    T value;
    Node* next;


    Node(T val){
        value=val;
        next=nullptr;
    }
};

template <class T>
class ClsLinkedList{

protected:
Node<T>* root;
Node<T>* tail;
int count;

//NEED TO HANDEL
void indexOutOfBound(){

}


public:
ClsLinkedList():root(nullptr),tail(nullptr),count(0){}
ClsLinkedList(T val):count(0){
    Node<T>* newNode=new Node<T>(val);
    root=newNode;
    tail=newNode;
    count++;

}
ClsLinkedList(const ClsLinkedList& other):count(other.count){
   if(!other.root){
    root=nullptr;
    tail=nullptr;
    return;
   }
   root=new Node<T>(other.root->value);
   Node<T>* current =root;
   Node <T>* otherCurrent=other.root->next;
   while (otherCurrent){
        current->next=new Node<T>(otherCurrent->value);
        current=current->next;
        otherCurrent=otherCurrent->next;
   }
   tail=current;
   
   
}

ClsLinkedList& operator=(const ClsLinkedList& other) {
    if (this == &other) return *this; // Self-assignment guard
    // Clear current content
    clear();
    // Copy elements from other list
    if (!other.root) return *this;
    root = new Node<T>(other.root->value);
    Node<T>* current = root;
    Node<T>* otherCurrent = other.root->next;
    while (otherCurrent) {
        current->next = new Node<T>(otherCurrent->value);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
    tail = current;
    count = other.count;
    return *this;
}


Node<T>* getRoot()const{
    return root;
}
int getCount(){
    return count;
}


void addBeginn(T val){
    Node<T>* newNode=new Node<T>(val);
    newNode->next=root;
    root=newNode;
    count++;
    
}
void addToIndex(T val, short index){
    if(root==nullptr){
        std::cout<<"The list is empty!"<<std::endl;
        std::cout<<"The Element will be added to the first index!";
        addBeginn(val);
        return;
    }
    if(index<=0){
        addBeginn(val);
        std::cout<<"\nThe Element will be added to the first index!\n";
        return; 
    }
    Node<T>* currentNode=root; 
    Node<T>* newNode=new Node<T>(val);
    int currentIndex=0;

    
    while(currentNode->next!=nullptr&&currentIndex<index-1){
        currentNode=currentNode->next;
        currentIndex++;
    }
    if(currentNode->next==nullptr){
        std::cout<<"Index out of bounds. Element added on index:"<<currentIndex+1<<std::endl;
        
        currentNode->next=newNode;
        return ;
    }
    newNode->next=currentNode->next;
    currentNode->next=newNode;
    count++;
}
void addEnd(T val){
    Node<T>* newNode=new Node<T>(val);

    if(!root){
        // If the list is empty, both root and tail point to the new node
        root=newNode;
        tail=newNode;
    }else{
        // Otherwise, append the new node to the end of the list
        tail->next=newNode;
        tail=newNode;
    }
    count++;
}

static void display(Node<T>* node) {
    if(node==nullptr){
        std::cout<<"The list is empty!!!"<<std::endl;
        return;
    }
    while(node!=nullptr){
        std::cout<<node->value<<"\t";
        node=node->next;
    }
    
}
void display()const {
    if(root==nullptr){
        std::cout<<"The list is empty!!!"<<std::endl;
        return;
    }
    Node<T>* currentNode=root;
    while (currentNode!=nullptr){
        std::cout<<currentNode->value<<"\t";
        currentNode=currentNode->next;
    }
    
}
short search(T key)const{
    if(root==nullptr){
        std::cout<<"The list is empty!!!"<<std::endl;
        return -1;
    }
    short index=0;
    Node<T>* currentNode=root;
    while(currentNode!=nullptr){
        if(currentNode->value==key){
            return index;
        }else{
            currentNode=currentNode->next;
            index++;
        }
    }
    std::cout<<"Element not found!!"<<std::endl;
 
    return -1;
}
void sort(){    //Needs anthor (better)algorithm;

}

void pop_back(){
    if(!root){
        std::cout<<"The list is empty!"<<std::endl;
        return;
    }
    // If the list has only one node, remove it and update root and tail
    if(!root->next){
        delete root;
        root=nullptr;
        tail=nullptr;
        count=0;
        return;
    }
    Node<T>* last=root;
    Node<T>* current=root;
    while(last!=tail){
        current=last;
        last=last->next;
    }
    current->next=nullptr;
    tail=current;
    delete last;
    count--;


    
}
void pop_front(){
    if(!root){
        std::cout<<"The list is empty!!"<<std::endl;
        return;
    }
    if(!root->next){
    delete root;
    root=nullptr;
    tail=nullptr;
    count=0;
    return;
    
    }
    Node<T>* temp=root;
    root=root->next;
    delete temp;
    count--;
}
void deleteByIndex(short index){
    if(!root){
        std::cout<<"The list is empty!!"<<std::endl;
        return;
    }
    if(index==0){
        pop_front();
        return;
    }
  
Node<T>* current=root;
int currentIndex=0;
while (!current->next||currentIndex<index-1){
    current=current->next;
    currentIndex++;
   if(current->next==nullptr){
    std::cout<<"Index out of bounds."<<std::endl;
    return;
    }     
}

Node<T>* temp=current->next;
current->next=temp->next;
delete temp;
count--;

}
void deleteByValue(T val){
int index=search(val);
deleteByIndex(index);
}



void clear(){
    Node<T>* current=root;
    while (current){
        Node<T>* temp=current;
        current=current->next;
        delete temp;
    }
    root =nullptr;
    tail=nullptr;       
    count=0;
    
}
~ClsLinkedList(){
    clear();
}
};

    