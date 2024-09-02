// author: Aryanthepain
#ifndef LIST_H
#define LIST_H
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

void insertAtPos(Node *head, int x, int i);

int size(Node *head);

void insertAtFirst(Node *head, int x);

void insertAtLast(Node *head, int x);

void deleteAtPos(Node *head, int i);

void deleteFirst(Node *head);

void deleteLast(Node *head);

void traverse(Node *head);

void search(Node *head, int x);

void update(Node *head, int i, int x);

void deleteList(Node *head);

void sort(Node *head);

void reverse(Node *head);

void mergeLists(Node *first, Node *second);

int getPos(Node *head, int i);

#endif
