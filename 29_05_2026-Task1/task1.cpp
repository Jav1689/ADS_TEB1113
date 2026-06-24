#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
struct Student {
    int ID;
    string name;
    string course;
    int age;
};

void displayAllRecords(Student students[], int size);
void searchStudentByID(Student students[], int size, int searchID);
void updateStudentRecord(Student students[], int size, int updateID);

int main() {
    Student students[5];

    students[0] = { 24007271, "Javier Lee", "IT", 26 };
    students[1] = { 24007272, "John Doe", "CS", 22 };
    students[2] = { 24007273, "Jane Smith", "Business", 24 };
    students[3] = { 24007274, "Mike Johnson", "Engineering", 25 };
    students[4] = { 24007275, "Sarah Wilson", "Medicine", 23 };

    int choice;
    int searchID, updateID;

    do {
        cout << "1. Display All Records\n";
        cout << "2. Search Student by ID\n";
        cout << "3. Update Student Record\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayAllRecords(students, 5);
            break;

        case 2:
            cout << "Enter Student ID to search: ";
            cin >> searchID;
            searchStudentByID(students, 5, searchID);
            break;

        case 3:
            cout << "Enter Student ID to update: ";
            cin >> updateID;
            updateStudentRecord(students, 5, updateID);
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

// Function to display all student records
void displayAllRecords(Student students[], int size) {
    cout << left << setw(12) << "ID"
        << setw(20) << "Name"
        << setw(15) << "Course"
        << setw(10) << "Age" << endl;

    for (int i = 0; i < size; i++) {
        cout << left << setw(12) << students[i].ID
            << setw(20) << students[i].name
            << setw(15) << students[i].course
            << setw(10) << students[i].age << endl;
    }
}

// Function to search for a student by ID
void searchStudentByID(Student students[], int size, int searchID) {
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (students[i].ID == searchID) {
            cout << "ID: " << students[i].ID << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Course: " << students[i].course << endl;
            cout << "Age: " << students[i].age << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent with ID " << searchID << " not found!\n";
    }
}

// Function to update a student record
void updateStudentRecord(Student students[], int size, int updateID) {
    bool found = false;
    int choice;

    for (int i = 0; i < size; i++) {
        if (students[i].ID == updateID) {
            found = true;
            cout << "ID: " << students[i].ID << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Course: " << students[i].course << endl;
            cout << "Age: " << students[i].age << endl;

            cout << "\nWhat do you want to change?\n";
            cout << "1. Name\n";
            cout << "2. Course\n";
            cout << "3. Age\n";
            cout << "4. All\n";
            cout << "Enter your choice: ";
            cin >> choice;

            cin.ignore(); // Clear the input buffer

            switch (choice) {
            case 1:
                cout << "Enter new name: ";
                getline(cin, students[i].name);
                break;

            case 2:
                cout << "Enter new course: ";
                getline(cin, students[i].course);
                break;

            case 3:
                cout << "Enter new age: ";
                cin >> students[i].age;
                break;

            case 4:
                cout << "Enter new name: ";
                getline(cin, students[i].name);
                cout << "Enter new course: ";
                getline(cin, students[i].course);
                cout << "Enter new age: ";
                cin >> students[i].age;
                break;

            default:
                cout << "Invalid choice! No changes made.\n";
            }
            cout << "ID: " << students[i].ID << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Course: " << students[i].course << endl;
            cout << "Age: " << students[i].age << endl;

            break;
        }
    }

    if (!found) {
        cout << "\nStudent with ID " << updateID << " not found!\n";
    }
}