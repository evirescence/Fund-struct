// Fund.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;



struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};


class clist {
    private: Node* head;

    public: 
        clist(): head(nullptr) {}

        void initialise(int ar[],int size) {
            for (int i = 0; i < size; ++i) {
                append(ar[i]);
            };
        };

        void append(int num) {
            Node* nw = new Node(num);
            if (head == 0) {
                head = nw;
                head->next = head;
            }
            else {
                Node* t = head;
                while (t->next != head) t = t->next;
                t->next = nw;
                nw->next = head;
            }
        };

        void remove(int num) {
            if (head == 0) return;

            Node* t = head;
            Node* prev = nullptr;
            Node* dlt = nullptr;
            bool check = 0;

            do {
                if (t->data == num) {
                    if (prev != 0) {
                        prev->next = t->next;
                    }
                    else {
                        Node* tail = head;
                        while (tail->next != head) {
                            tail = tail->next;
                        }
                        tail->next = t->next;
                        head = t->next;
                    }
                    dlt = t;
                    if (!prev)  t = t->next;
                    else t = prev;
                    check = 1;
                    delete dlt;
                }
                if (prev != 0) {
                    prev = t;
                    t = t->next;
                }
                else prev = t;
            } while (t != head);
            if (!check) cout << "No element found";
        }

        void remove_pre(int num) {
            if (head == 0) return;

            Node* t = head;
            Node* prev = nullptr;
            Node* dlt = nullptr;
            bool count = 0;

            do {
                if (prev) {
                    if (t->data == num) {
                        dlt = prev;
                        if (dlt == head) {
                            Node* tail = head;
                            while (tail->next != head) tail = tail->next;
                            tail->next = head->next;
                            head = head->next;
                        }
                        else {
                            Node* pprev = head;
                            while (pprev->next != dlt) pprev = pprev->next;
                            pprev->next = t;
                        }
                        count = 1;
                        delete dlt;
                    }
                }
                else if (t->data == num and head->next != head) {
                    Node* tail = head;
                    Node* pprev = head;
                    while (tail->next != head) { pprev = tail; tail = tail->next; }
                    pprev->next = head;
                    delete tail;
                }
                else if (t->data == num and head->next == head){ cout << "This list has only one element"; return; }
                prev = t;
                t = t->next;
            } while (t != head);
            if (!count) cout << "No element found";
        }

        void search(int num) {
            if (head == 0) return;
            Node* t = head;
            bool check = 0;
            do {
                if (t->data == num) { cout << " <" << t << "> " << t->data << " -> " << endl; check = 1; }
                t = t->next;
            } while (t != head);
            if (!check) cout << "No element found";
        }

        void print() {
            if (head == 0) { cout << "this list doesn't have any elements";  return;};
            Node* t = head;
            do {
                cout << " <" << t << "> " << t->data << " -> ";
                t = t->next;
            } while (t != head);
            cout << endl;
        };

        void unite(clist& second) {
            if (second.head == 0) return;
            if (head == 0) { head = second.head; return; };

            Node* tail1 = head;
            while (tail1->next != head) {
                tail1 = tail1->next;
            };

            Node* tail2 = second.head;
            while (tail2->next != second.head) {
                tail2 = tail2->next;
            };

            tail1->next = second.head;
            tail2->next = head;
            second.head = nullptr;
        }


        ~clist() {
            if (head == 0) return;

            Node* t = head;
            do {
                Node* nw = t->next;
                delete t;
                t = nw;
            } while (t != head);
        };
    
};


//int main()
//{
//    clist list;
//    int asw = 0;
//    string vals;
//
//    do {
//        cout << "1. Initialisation" << endl;
//        cout << "2. Append" << endl;
//        cout << "3. Remove by value" << endl;
//        cout << "4. Remove previous by value" << endl;
//        cout << "5. Search" << endl;
//        cout << "6. Print" << endl;
//        cout << "7. Unite" << endl;
//        cin >> asw;
//
//        switch (asw) {
//        case 1: {
//            cout << "Input the values" << endl;
//            cin >> vals;
//
//            int arr[20];
//            int n;
//            int count = 0;
//            char* ptr;
//            ptr = strtok(vals, " , ");
//
//
//            while (iss >> n && count < 20) {
//                arr[count] = n;     // Добавляем число в массив
//                count++;
//            }
//
//
//            list.initialise(arr, count);
//            list.print(); break;
//            }
//
//
//            
//            
//
//
//
//        }
//    } while (asw != 0);
//}

