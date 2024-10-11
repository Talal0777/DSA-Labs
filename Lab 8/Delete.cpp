#include <iostream>
using namespace std;

struct Student {
    string name;
    int sap_id;
    Student* next;
};

void insert(Student*& head, string name, int sap_id) {
    Student* new_student = new Student();
    new_student->name = name;
    new_student->sap_id = sap_id;
    new_student->next = nullptr;

    if (head == nullptr) {
        head = new_student;
    } else {
        Student* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_student;
    }
}

void delete_students(Student*& head) {
    if (head != nullptr && head->next != nullptr) {
        Student* temp = head->next;
        head->next = head->next->next;
        delete temp;
    }

    if (head != nullptr) {
        Student* current = head;
        for (int i = 1; i < 3 && current->next != nullptr; i++) {
            current = current->next;
        }

        if (current->next != nullptr && current->next->next != nullptr) {
            Student* temp = current->next->next;
            current->next->next = current->next->next->next;
            delete temp;
        }
    }
}

void print_list(Student* head) {
    while (head != nullptr) {
        cout << "Name: " << head->name << ", SAP ID: " << head->sap_id << endl;
        head = head->next;
    }
}

int main() {
    Student* head = nullptr;
    int n;
    cout << "Enter the number of students (at least 5): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int sap_id;
        cout << "Enter name and SAP ID of student " << i + 1 << ": ";
        cin >> name >> sap_id;
        insert(head, name, sap_id);
    }

    cout << "Linked list before deletion:" << endl;
    print_list(head);

    delete_students(head);

    cout << "Linked list after deletion:" << endl;
    print_list(head);

    return 0;
}
