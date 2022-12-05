#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int max_row = 15;

string first_names[max_row] = {};
string surnames[max_row] = {};
string ids[max_row] = {};
string contacts[max_row] = {};

//OPENING FILE TO BE USED TO STORE EMPLOYEE DATA
void OpenFile() {
    string line;
    ifstream myfile("./employees.txt");

    if (myfile.is_open()) {
        
        int i = 0;
        while (getline(myfile, line)) {
            int l = line.length();
            ids[i] = line.substr(0, 3);
            first_names[i] = line.substr(4, 1 - 4);
            surnames[i] = line.substr(4, 1 - 4);
            contacts[i] = line.substr(4, 1 - 4);
            i++;
        }
    } else
    {
        cout << "Unable to open file!" << endl;
    }
}

//ADDING EMPLOYEES
void addEmployee() {
    char first_name[50];
    char surname[50];
    char id[10];
    char contact[25];

    cin.ignore();

    cout << "Add an employee\n\n" << endl;

    cout << "Enter the first name of the employee: ";
    cin.getline(first_name, 50);

    cout << "Enter the surname of the employee: " ;
    cin.getline(surname, 50);

    cout << "Enter the phone number of the employee in the company: ";
    cin.getline(contact, 25);

    cout << "Enter the employee's ID: ";
    cin.getline(id, 10);

    for (int i = 0; i < max_row; i++) {
        if (ids[i] == "\0") {
            first_names[i] = first_name;
            surnames[i] = surname;
            contacts[i] = contact;
            ids[i] = id;
            break;
        }
        
    }
}

//SAVING THE RECORDED DATA IN TEXT FILE
void saveToFile() {
    ofstream myfile;
    myfile.open("./employee.txt");

    for (int i = 0; i < max_row; i++) {
        if (ids[i] == "\0") {
            break;
        } else {
            myfile << ids[i] + "," + first_names[i] + surnames[i] + contacts[i] << endl;
        }        
    }
}

//UPDATING EMPLOYEES
void updateEmployee(string search_id) {
    char first_name[50];
    char surname[50];
    char contact[25];
    int counter;

    for (int i = 0; i < max_row; i++)
    {
        if (ids[i] == search_id)
        {
            counter++;

            cout << "Update an employee:\n" << endl;

            cout << "Update the first name of the employee: ";
            cin.getline(first_name, 50);

            cout << "Update the surname of the employee: " ;
            cin.getline(surname, 50);

            cout << "Update the phone number of the employee in the company: ";
            cin.getline(contact, 25);

            first_names[i] = first_name;
            surnames[i] = surname;
            contacts[i] = contact;

            cout << "Employee has been successfully updated !!!" << endl;
            break;
        }
        
    }
}

//DELETE EMPLOYEE RECORDS
void deleteEmployee(string search_id) {
    int counter = 0;
    for (int i = 0; i < max_row; i++) {
        if (ids[i] == search_id) {
            counter++;
            ids[i] = "";
            first_names[i] = "";
            surnames[i] = "";
            contacts[i] = "";

            cout << "Employee record has been successful Deleted !!!" << endl;
            break;
        }
    }
}

//SEARCHING AND EMPLOYEE RECORD BY ID
void searchEmployee(string search_id) {
    system("CLS");
    cout << "Current record(s)\n" << endl;
    cout << "===========================================================================================================================================" << endl;
    
    int counter = 0;
    for (int i = 0; i < max_row; i++) {
        if (ids[i] == search_id) {
            counter = 0;
            counter++;
            cout << "   " << counter << "     " << ids[i] << "         " << first_names[i] << "         "  << surnames[i] << "         " << contacts[i] << endl;
            break;
        }
        
    }

    if (counter == 0)
    {
        cout << "Employee record not found!" << endl;
    }

    cout << "===============================" << endl;
}

void displayRecords() {
    system("CLS");
    cout << "current record(s)" << endl;
    cout << "======================" << endl;

    int counter = 0;

    cout << " No. |   EMPLOYEE ID   |        NAME       |      SURNAME     |        contact     |" << endl << 
    "--------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < max_row; i++)
    {
        if (ids[i] != "\0")
        {
            counter++;
            cout << "   " << counter << "     " << ids[i] << "            " << first_names[i] << "       \t" 
            << surnames[i] << "     \t" << contacts[i] << endl;
        }     
    }
            
    if (counter == 0)
    {
        cout << "NO Records to display!" << endl;
    }

    cout << "===============================" << endl;
}


int main() {
    std::cout << "MENU\n";
    int option;
    string search_id;
    system("CLS");
    OpenFile();

    cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n" << endl;
    cout << "\t} : } : } : } : } : } : } : } : } :   WELCOME TO THE EMPLOYEE MANAGEMENT APP     : { : { : { : { : { : { : { : { : {\n\n" << endl;
    cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n" << endl;

    do {
        cout << "\t\t1. Add an employee" << endl;
        cout << "\t\t2. Update an employee" << endl;
        cout << "\t\t3. Delete an employee record" << endl;
        cout << "\t\t4. Search for an employee record" << endl;
        cout << "\t\t5. Display an employee record" << endl;
        cout << "\t\t6. Exit and save changes" << endl;
        cout << "\t\t===========================" << endl;

        cout << "\t\tSelect option >> ";
        cin >> option;

        switch (option) {
            case 1:
                addEmployee();
                system("CLS");
                break;
            case 2:
                cin.ignore();
                cout << "Enter the ID of the employee record you want to update >> ";
                getline(cin, search_id);
                updateEmployee(search_id);
                system("CLS");
                break;
            case 3:
                cin.ignore();
                cout << "Enter the ID of the employee record you want to delete >> ";
                getline(cin, search_id);
                deleteEmployee(search_id);
                cin.ignore();
                system("CLS");
                break;
                
            case 4:
                cin.ignore();
                cout << "Search by ID >> ";
                getline(cin, search_id);
                searchEmployee(search_id);
                break;
            case 5:
                displayRecords();
                break;
        }
    } while (option != 6);

    saveToFile();

    cout << "Exiting and saving...." << endl;
    return 0;
}