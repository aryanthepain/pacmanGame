//author: aryanthepain
#ifndef STACK_H
#define STACK_H
#include <bits/stdc++.h>
#include "list.h"
using namespace std;
#endif

bool empty(Node *head){
	if(head->next)
		return false;
	return true;
}

int top(Node *head){
	return getPos(head, 0);
}


void push(Node *head, int x){
	insertAtFirst(head, x);
	return;
}

void pop(Node *head){
	deleteFirst(head);
	return;
}

void print(Node *head){
	while(!empty(head)){
		cout<<top(head)<<" ";
		pop(head);
	}
	
	cout<<""<<endl;
	
	return;
}
int size(Node *head);

int menu()
{
    cout << "Press the number corresponding to the function you want to execute\n(-1 to exit)" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Top" << endl;
    cout << "4. Size" << endl;
    cout << "5. check if stack is empty" << endl;
    cout << "6. Print Stack(delete stack)" << endl;

    int n;
    cin >> n;

    return n;
}

int main(){
	cout << "Functions on stacks" << endl;
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    
	while (true)
    {
        int me = menu();
        if (me == -1)
        {
            cout << "Please give full marks :). Exiting..." << endl;
            if (head)
            {
                deleteList(head);
                free(head);
            }

            return 0;
        }
        switch (me)
        {
        case 1:
        {
            cout << "Enter the number:" << endl;
            int n;
            cin >> n;
            push(head, n);
            break;
		}
        case 2:
        {
            cout << "Deleting first element" << endl;
            pop(head);
            break;
        }
        case 3:
        {
            cout << "First element: "<<top(head) << endl;
            break;
        }
        case 4:
        {
            cout << "Size: "<<size(head) << endl;
            break;
        }
        case 5:
        {
            cout << "The current stack is: ";
            if(!empty(head))
            	cout<<"not ";
           	cout<<"empty"<<endl;
            break;
        }
        case 6:
        {
            print(head);
            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }	

	return 0;
}
