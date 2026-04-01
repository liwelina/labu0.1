#include <iostream>
#include <string>
using namespace std;

struct Car {
    string name;
    int year;
    double price;
    Car* next;
};


void addCar(Car*& head, string name, int year, double price) {
    Car* newCar = new Car{name, year, price, nullptr};

    if (head == nullptr) {
        head = newCar;
        return;
    }

    Car* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newCar;
}


void showCars(Car* head) {
    int currentYear = 2026;

    while (head != nullptr) {
        if (currentYear - head->year > 10 && head->price < 5000) {
            cout << head->name << " "
                 << head->year << " "
                 << head->price << endl;
        }
        head = head->next;
    }
}


void deleteCars(Car*& head) {
    while (head != nullptr) {
        Car* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Car* list = nullptr;

    addCar(list, "BMW", 2008, 4500);
    addCar(list, "Audi", 2018, 7000);
    addCar(list, "Mercedes", 2010, 3000);

    cout << "Car:";
    showCars(list);

    deleteCars(list);

    return 0;
}