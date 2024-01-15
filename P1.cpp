//Insert,Print,DeleteAny,Revers,size,mid,loopDitect,InsertBefor,AfterInsert
// Created by Sift Ali on 1/15/2024.
//

#include <iostream>

using  namespace std;

class LL{
    class  Node{
    public:
        string data;
        Node* next;
        Node(string data){
            this->data=data;
            this->next= nullptr;
        }
    };
public:
    Node* head;

    LL(){
        this->head= nullptr;
    }

//////////eMPTY////////

    void ListIsEmpty() {
        if (head == nullptr) {
            cout << "List is Empty" << endl;
            exit(EXIT_FAILURE);
        } else {
            return;
        }
    }

//////////////Insert//////

    void Insert(string value) {
        Insert(head, value);
    }

    void Insert(Node*& current, string value) {
        if (current == nullptr) {
            current = new Node(value);
        } else {
            Insert(current->next, value);
        }
    }

///////size////

    void size(){
        ListIsEmpty();
        cout << "Size: " << calculateSize(head) << endl;

    }

    int calculateSize(Node* currentNode) {
        if (currentNode == nullptr) {
            return 0;
        } else {
            return 1 + calculateSize(currentNode->next);
        }
    }

///////////////Mid/////////////

    void mid() {
        ListIsEmpty();

        Node* midNode = mid(head, head);
        cout << "Middle Node: " << midNode->data << endl;

    }

    Node* mid(Node*& slow,Node*& fast) {
        //  if (fast==nullptr || fast->next== nullptr)
        if (!fast || !fast->next){
            return slow;
        }
        return mid(slow->next, fast->next->next);
    }

///////////////Loop detection////

    void LoopDetection() {
        ListIsEmpty();
        bool result = Loop(head, head->next->next);
        if(result) cout<<"Loop Detected "<<endl;
        else cout<<"Loop Not Detected "<<endl;
    }

    bool Loop(Node*& slow,Node*& fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }
        if (slow == fast || slow == fast->next){
            return true;
        }

        return Loop(slow->next, fast->next->next);
    }

///////////////Revers/////////////

    void Revers( ) {
        ListIsEmpty();
        cout<<"Revers LinkedList : ";
        ReversPrint(head);
        cout<<endl;
    }

    void ReversPrint(Node*& currentNode) {
        if (currentNode == nullptr) {
            return;
        } else {
            ReversPrint(currentNode->next);
            if(currentNode->next!= nullptr) cout<<"->";
            cout<<currentNode->data;
        }
    }

///////////// Deletion//////////

    void Delete(string value) {
        ListIsEmpty();
        head= Delete(head,value);

    }

    Node* Delete(Node*& current,string value) {
        if (current == nullptr) {
            cout << "Node with value " << value << " not found" << endl;
            return nullptr;
        }

        if (current->data == value) {
            Node *temp = current->next;
            delete current;
            return temp;
        }
        current->next = Delete(current->next, value);
        return current;

    }


///////////// Insert After//////

    void InsertAfter(string targetValue, string newValue) {
        ListIsEmpty();
        head = InsertAfter(head, targetValue, newValue);
    }

    Node* InsertAfter(Node* current, string targetValue, string newValue) {
        if (current == nullptr) {
            cout << "Node with value " << targetValue << " not found" << endl;
            return nullptr;
        }

        if (current->data == targetValue) {
            Node* newNode = new Node(newValue);
            newNode->next = current->next;
            current->next = newNode;
            return current;
        }

        current->next = InsertAfter(current->next, targetValue, newValue);
        return current;
    }


////////////// Insert Befor ////////

    void InsertBefore(string targetValue, string newValue) {
        ListIsEmpty();
        head = InsertBefore(head, targetValue, newValue);
    }

    Node* InsertBefore(Node* current, string targetValue, string newValue) {
        if (current == nullptr) {
            cout << "Node with value " << targetValue << " not found" << endl;
            return nullptr;
        }

        if (current->data == targetValue) {
            Node* newNode = new Node(newValue);
            newNode->next = current;
            return newNode;
        }

        current->next = InsertBefore(current->next, targetValue, newValue);
        return current;
    }

//////////////Last Node Deletion////////////

    void LastNodeDeletion() {
        ListIsEmpty();
        LastNodeDeletion(head);
    }

    void LastNodeDeletion(Node*& current) {
        if (current->next == nullptr) {
            delete current;
            current= nullptr;
        } else {
            LastNodeDeletion(current->next);
        }
    }

/////////////// clear////////////////

    void clearList(){
        ListIsEmpty();
        clearList(head);
        head = nullptr;
        cout << "Linked List Cleared" << endl;
    }

    void clearList(Node*& currentNode) {
        if (currentNode == nullptr) {
            return;
        } else {
            Node* nextNode = currentNode->next;
            delete currentNode;
            clearList(nextNode);
        }
    }

///////////////PRINT//////////////////

    void PrintList( ) {
        ListIsEmpty();
        cout<<"Print LinkeList : ";
        PrintList(head);
        cout<<endl;
    }

    void PrintList(Node*& currentNode) {
        if (currentNode == nullptr) {
            return;
        } else {
            cout<<currentNode->data;
            if(currentNode->next!= nullptr) cout<<"->";
            PrintList(currentNode->next);
        }
    }
};

int main(){
    LL list;
    list.Insert("1");
    list.Insert("2");
    list.Insert("3");
    list.Insert("4");
    list.Insert("5");
    list.Insert("6");
    list.PrintList();
    list.Revers();
    list.mid();
    list.size();

    // Creating a loop from the last node to the second node
    //   list.head->next->next->next->next->next = list.head->next;
    list.LoopDetection();
    //  list.clearList();
    // list.PrintList();
    list.LastNodeDeletion();
    list.PrintList();
    //list.Delete("1");
    list.InsertBefore("5","0");
    list.InsertAfter("1","1.5");
    list.PrintList();
}