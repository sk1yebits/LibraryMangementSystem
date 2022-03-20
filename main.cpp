#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

class Library {
    public:
        void panel();
        void addBook();
        void viewBook();
};

void Library::panel() {
    system("cls");
    cout << "\n\n\t\t\t\tAdmin Panel";
    cout << "\n\n 1. Add New Book";
    cout << "\n 2. View Books";
    cout << "\n 3. Update Book (Coming Soon)";
    cout << "\n 4. Delete Book (Coming Soon)";
    cout << "\n 5. Exit.";
};

void Library::addBook() {
    system("cls");
    fstream file;
    int copies;
    string bName, aName, bId;
    cout << "\n\n\t\t\t ADD New Book";
    cout << "\n\n Book ID: ";
    cin >> bId;
    cout << "\n\n Book Name: ";
    cin >> bName;
    cout << "\n\n Author Name: ";
    cin >> aName;
    cout << "\n\n No. of Copies: ";
    cin >> copies;
    file.open("D://book.txt", ios::out | ios::app);
    file << " " << bId << " " << bName << " " << aName << " " << copies << "\n";
    file.close();
};

void Library::viewBook() {
    system("cls");
    fstream file;
    int copies;
    string bName, bId, aName;
    cout << "\n\n\t\tShow All Books\n\n";
    file.open("D://book.txt", ios::in);
    if (!file)
        cout << "\n\n File Openning Error...";
    else
    {
        cout << "+---------+-----------+-------------+--------+\n";
        cout << "| Book ID | Book Name | Author Name | Copies |\n";
        cout << "+---------+-----------+-------------+--------+\n";

        while (file >> bId >> bName >> aName >> copies)
        {
            cout << "|\t"<< bId <<"| \t" << bName << "  | \t" << aName << " | \t" << copies << "   | \n";
        }
    }
}

void main()
{
    int choise;
    Library lib;
    lib.panel();
    cout << "\n\n\tEnter Choise: ";
    cin >> choise;
        switch (choise)
        {
            case 1:
                lib.addBook();
                break;
            case 2:
                lib.viewBook();
                break;
            case 3:
                cout << "\nUpdate Book..";
                break;
            case 4:
                cout << "\nDelete book..";
                break;
            case 5:
                exit(0);
                break;
            default:
                break;
        };
}

