#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *CreateNode(int init_data)
{
    Node *node = new Node;
    node->data = init_data;
    node->data = NULL;
    return node;
}

struct LinkedList{
    Node *head;
    Node* tail;
};

void CreateList(LinkedList& l){
    l.head = NULL;
    l.tail = NULL;
}

void AddHead(LinkedList& l, Node* node){
    if(l.head == NULL){
        l.head = node;
        l.tail = node;
    }
    else{
        node->next = l.head;
        l.head = node;
    }
}

void AddTail( ){

}

int main(){

}