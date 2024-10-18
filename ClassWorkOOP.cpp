#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student {
private:
    string fullName;
    string birthDate;
    string contactNumber;
    string city;
    string country;
    string institutionName;
    string institutionCity;
    string institutionCountry;
    string groupNumber;
public:
    void input() {
        cout << "Enter full name: "; getline(cin, fullName);
        cout << "Enter birth date (DD.MM.YYYY): "; getline(cin, birthDate);
        cout << "Enter contact number: "; getline(cin, contactNumber);
        cout << "Enter city: "; getline(cin, city);
        cout << "Enter country: "; getline(cin, country);
        cout << "Enter institution name: "; getline(cin, institutionName);
        cout << "Enter institution city: "; getline(cin, institutionCity);
        cout << "Enter institution country: "; getline(cin, institutionCountry);
        cout << "Enter group number: "; getline(cin, groupNumber);
    }

    void print() {
        cout << "====================== Student ======================" << endl;
        cout << "\t Full Name: " << fullName << endl;
        cout << "\t Birth Date: " << birthDate << endl;
        cout << "\t Contact Number: " << contactNumber << endl;
        cout << "\t City: " << city << endl;
        cout << "\t Country: " << country << endl;
        cout << "\t Institution Name: " << institutionName << endl;
        cout << "\t Institution City: " << institutionCity << endl;
        cout << "\t Institution Country: " << institutionCountry << endl;
        cout << "\t Group Number: " << groupNumber << endl;
    }
};

class Point {
private:
    double x, y, z;
public:
    void input() {
        cout << "Enter coordinates of the point (x y z): ";
        cin >> x >> y >> z;
    }

    void print() {
        cout << "Point: (" << x << ", " << y << ", " << z << ")" << endl;
    }

    void saveToFile(const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << x << " " << y << " " << z;
            outFile.close();
            cout << "Point saved to file." << endl;
        }
        else {
            cout << "Error:" << endl;
        }
    }

    void loadFromFile(const string& filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            inFile >> x >> y >> z;
            if (inFile.fail()) {
                cout << "Error:" << endl;
            }
            inFile.close();
        }
        else {
            cout << "Error:" << endl;
        }
    }
};

int main() {
    Student student;
    student.input();
    student.print();

    int choice;

    do {
        cout << "Menu:\n";
        cout << "1. Input and save a point\n";
        cout << "2. Load and print the point from file\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Point point;
            point.input();
            point.print();
            point.saveToFile("point.txt");
            break;
        }
        case 2: {
            Point anotherPoint;
            anotherPoint.loadFromFile("point.txt");
            anotherPoint.print();
            break;
        }
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
