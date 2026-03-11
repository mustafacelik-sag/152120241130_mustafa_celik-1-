#include <iostream>

using namespace std;
struct node{
    string data;
    node* next;
};
node *Append(string text, node *head){
    node *p = new node;
    p->data = text;
    p->next = head;
    return p;
}
void Print(node *head){
    cout << "Entered names:" << endl;
    while(head != NULL){
        cout << head->data << endl;
        head = head->next;
    }
}
void Undo(node *head){
    if(head != NULL){
        Undo(head->next);
    }
    else delete head;
}
int main()
{
    string name;
    node *head = NULL;
    while(1 > 0){
    if(name == "EXIT"){
        cout << "Thanks for using our system." << endl;
        exit(0);
    }
    cout << "Enter name:(Type EXIT to leave, UNDO to undo.)" << endl;
    cin >> name;
    head = Append(name, head);
    Print(head);
    if(name == "UNDO"){
        Undo(head);
    }

    }
}
