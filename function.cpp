#include <iostream>
#include <fstream>
#include "function.h"
using namespace std;
node create(int data){
    node p = new Node;
    p->data = data;
    p->pnext = nullptr;
    return p;
}
void insertlast(node &phead, int data){
    node cur = phead;
    node prev = nullptr;
    while(cur != nullptr){
        prev = cur;
        cur = cur->pnext;
    }
    if(!prev){
        phead = create(data);
    }
    else{
        node pnex = create(data);
        prev->pnext = pnex;
    }
}
void deletevalue(node& phead, int value) {
    if (!phead) 
    return;
    node cur = phead;
    node prev = nullptr;
    while (cur != nullptr) {
        if (cur->data == value) {
                if (!prev) {
                    node tmp = phead;
                    phead = phead->pnext;
                    delete tmp;
                    cur = phead; 
                }
                else {
                    prev->pnext = cur->pnext;
                    delete cur;
                    cur = prev->pnext;
                }
            } else {
                prev = cur;
                cur = cur->pnext;
            }
        }
    }
void deleteduplicate(node& phead){
    if (!phead)
    return;
    node cur = phead;
    while(cur != nullptr){
        deletevalue(cur->pnext, cur->data);
        cur = cur->pnext;
    }
}
void reverse(node& phead){
    if(!phead) return;
    node cur = phead->pnext;
    node prev = phead;
    while(cur != nullptr){
    prev->pnext = cur->pnext;
    cur->pnext = phead;
    phead = cur;
    cur = prev->pnext;
    }
    return;
}
void inserteven(node& phead){
    if(!phead) return;
    node cur = phead;
    node prev = nullptr;
    int insert = 2;
    while(cur != nullptr){
    if(cur == phead){
        node newnode = create(insert);
        newnode->pnext = phead;
        phead = newnode;
        prev = cur;
        cur = cur->pnext;
        insert+=2;
    }   
    node newnode = create(insert);
    prev->pnext = newnode;
    newnode->pnext = cur;
    prev = cur;
    cur = cur->pnext;
    insert+=2;
    }
}
void insertordered(node& phead, int data){
    if(!phead) 
    {phead = create(data);
    return;
    }
    node cur = phead;
    node prev = nullptr;
    while(cur != nullptr){
        if(cur->data < data) {
            prev = cur;
            cur = cur->pnext;       
        }
        else{
            if(!prev){
                node newnode = create(data);
                newnode->pnext = phead;
                phead = newnode;
                break;
            }
            else{
            node newnode = create(data);
            prev->pnext = newnode;
            newnode->pnext = cur;
            break;
            }
        }
    }
}
void outputsum(node phead, ofstream& out){
    int sum = 0;
    while(phead != nullptr){
        sum += phead->data;
        out << sum << " ";
        phead = phead->pnext;
    }
}
node twolink(node& phead){
    node cur = phead->pnext;
    node newcur = cur;
    node oldcur = phead;
    while(!oldcur || !newcur){
        oldcur->pnext = newcur->pnext;
        oldcur = oldcur->pnext;
        if(!oldcur) break;
        newcur->pnext = oldcur->pnext;
        newcur = newcur->pnext;
    }
    return cur;
}
node merge(node& pfirst, node& psecond) {
    if (!pfirst) return psecond;
    if (!psecond) return pfirst;

    node phead = pfirst;
    node prev = nullptr;

    while (pfirst && psecond) {
        if (prev) prev->pnext = pfirst;

        prev = pfirst;
        pfirst = pfirst->pnext;

        prev->pnext = psecond;
        psecond = psecond->pnext;

        prev = prev->pnext;
    }

    if (psecond) prev->pnext = psecond;
    if(pfirst) prev->pnext = pfirst;
    return phead;
}
void output(node phead, ofstream& out){
    node cur = phead;
    if(!phead) out << "The list is empty";
    while(cur != nullptr){
    out << cur->data << " ";
    cur = cur->pnext;
    }
}