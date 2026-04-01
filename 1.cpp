#include <iostream>
using namespace std;

struct Element {
    int value;
    Element* next;
};


void addToEnd(Element*& head, int value) {
    Element* newEl = new Element{value, nullptr};

    if (head == nullptr) {
        head = newEl;
        return;
    }

    Element* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newEl;
}

void addToStart(Element*& head, int value) {
    head = new Element{value, head};
}


void addToMiddle(Element*& head, int value) {
    if (head == nullptr) return;

    Element* newEl = new Element{value, head->next};
    head->next = newEl;
}


void showList(Element* head) {
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}


double findAverage(Element* head) {
    int sum = 0, count = 0;

    while (head != nullptr) {
        sum += head->value;
        count++;
        head = head->next;
    }

    return (double)sum / count;
}


void deleteFirstEven(Element*& head) {
    if (head == nullptr) return;

    if (head->value % 2 == 0) {
        Element* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Element* temp = head;
    while (temp->next != nullptr) {
        if (temp->next->value % 2 == 0) {
            Element* del = temp->next;
            temp->next = del->next;
            delete del;
            return;
        }
        temp = temp->next;
    }
}

// очистка пам'яті
void deleteList(Element*& head) {
    while (head != nullptr) {
        Element* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Element* list = nullptr;

    addToStart(list, 5);
    addToEnd(list, 10);
    addToMiddle(list, 7);
    addToEnd(list, 8);

    cout << "List: ";
    showList(list);

    cout << "Average: " << findAverage(list) << endl;

    deleteFirstEven(list);

    cout << "After delete: ";
    showList(list);

    deleteList(list);

    return 0;
}