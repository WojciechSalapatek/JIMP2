//
// Created by wojciechsalapatek on 10.03.18.
//

#include <iostream>
#include "SimpleForwardList.h"

ForwardList *CreateNode(int value){
    ForwardList *node = new ForwardList;
    node->value = value;
    node->next = nullptr;
    node->head = node;
    return node;


}

void DestroyList(ForwardList *list){
    if (list== nullptr) return;
    ForwardList *iterator = list->head;
    while(iterator != nullptr){
        ForwardList *tmp = iterator;
        iterator = iterator->next;
        delete tmp;
    }
}

ForwardList *PushFront(ForwardList *list, int value){
    if (list == nullptr) return nullptr;
    ForwardList *head = list->head;
    ForwardList *newNode = new ForwardList;
    newNode->value = value;
    newNode->next = head;
    newNode->head = newNode;
    list->head = newNode;
    return newNode;
}
void Append(ForwardList *list, ForwardList *tail){
    if(list == nullptr) return;
    ForwardList *it = list->head;
    while(it->next != nullptr) it=it->next;
    it->next = tail;
}