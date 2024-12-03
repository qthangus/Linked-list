#include <iostream>
#include "fstream"
#include "function.h"
#include "function.cpp"
using namespace std;
int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    cout << "Menu" << endl;
    cout << "1.Remove duplicates" << endl;
    cout << "2.Reverse the list" << endl;
    cout << "3.Insert even numbers" << endl;
    cout << "4.Sorted list" << endl;
    cout << "5. List of sum" << endl;
    cout << "6.1 list -> 2 lists" << endl;
    cout << "7.2 lists -> 1 list" << endl;
    int choice;
    cin >> choice;
    if(choice == 7){
    node pfirst = nullptr;
    node psecond = nullptr;
    int number;
    char c;
    while(in >> number){
        insertlast(pfirst,number);
        c = in.peek();
        if(c == '\n') break;
    }
    while(in >> number){
        insertlast(psecond,number);
    }
    node phead = merge(pfirst,psecond);
    output(phead,out);
    }
    else{
        node phead = nullptr;
        int number;
        while(in >> number) insertlast(phead,number);
        switch(choice){
            case 1: deleteduplicate(phead);
            output(phead,out);
            break;
            case 2: reverse(phead);
            output(phead,out);
            break;
            case 3: inserteven(phead);
            output(phead,out);
            break;
            case 4: int data;
            cin >> data;
            insertordered(phead, data);
            break;
            case 5: outputsum(phead, out);
            break;
            default:
            node psecond = twolink(phead);
            output(phead,out);
            cout << endl;
            output(psecond,out);
        }
    node cur = phead;
    while(phead != nullptr){
        phead = phead->pnext;
        delete cur;
        cur = phead;
    }
    }
}
