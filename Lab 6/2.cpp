#include <iostream>
#include <string>
using namespace std;

struct City {
    string name;
    double distance;
    City* next;
};

void addCity(City*& head, string name, double distance) {
    City* newCity = new City{name, distance, nullptr};

    if (head == nullptr) {
        head = newCity;
        return;
    }

    City* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newCity;
}

void showFarthestCities(City* head) {
    if (head == nullptr || head->next == nullptr) return;


    City* max1 = head;
    City* max2 = head->next;


    if (max2->distance > max1->distance) {
        City* temp = max1;
        max1 = max2;
        max2 = temp;
    }

    head = head->next->next;

    while (head != nullptr) {
        if (head->distance > max1->distance) {
            max2 = max1;
            max1 = head;
        }
        else if (head->distance > max2->distance) {
            max2 = head;
        }
        head = head->next;
    }

    cout << "The furthest cities: "
         << max1->name << " and " << max2->name << endl;
}

void deleteCities(City*& head) {
    while (head != nullptr) {
        City* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    City* list = nullptr;

    addCity(list, "Lviv", 540);
    addCity(list, "Odesa", 475);
    addCity(list, "Kharkiv", 480);

    showFarthestCities(list);

    addCity(list, "Warsaw", 800);

   
    

    deleteCities(list);

    return 0;
}
