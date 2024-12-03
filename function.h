#pragma once
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* pnext;
};
typedef Node* node;
node create(int data);
void insertlast(node &phead, int data);
void deletevalue(node& phead, int value);
void output(node phead, ofstream& out);
void deleteduplicate(node& phead);
void reverse(node& phead);
void inserteven(node& phead);
void insertordered(node& phead, int data);
void outputsum(node phead, ofstream& out);
node twolink(node& phead);
node merge(node& pfirst, node& psecond);
void output(node phead, ofstream& out);