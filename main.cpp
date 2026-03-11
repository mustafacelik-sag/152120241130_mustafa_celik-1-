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
node *Undo(node* head){
    if(head == NULL) return NULL;
    if(head -> next == NULL){
        delete head;
        return NULL;
    }
    node *secondlast = head;
    while(secondlast->next->next != NULL){
        secondlast = secondlast -> next;
    }
    delete secondlast -> next;
    secondlast->next = NULL;

    return head;
}
int main()
{
    string name;
    node *head = NULL;
    while(1 > 0){

    cout << "Enter name:(Type EXIT to leave, UNDO to undo.)" << endl;
    cin >> name;
    if(name != "UNDO")head = Append(name, head);
    if(name == "EXIT"){
        cout << "Thanks for using our system." << endl;
        exit(0);
    }
    Print(head);
    if(name == "UNDO"){
        head = Undo(head);
    }
    }
}
