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
        void updateBook();
		void del_book();
};

void Library::panel() {
    system("cls");
    cout << "\n\n\t\t\t\tAdmin Panel";
    cout << "\n\n 1. Add New Book";
    cout << "\n 2. View Books";
    cout << "\n 3. Update Book";
    cout << "\n 4. Delete Book";
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

void Library::updateBook() {
	system("cls");
	fstream file, file1;
	int no_copy, no_co, count = 0;
	string b_name, b_na, a_name, a_na, b_idd, b_id;
	cout << "\n\n\t\t\t\tUpdate Book Record";
	file1.open("D://book1.txt", ios::app | ios::out);
	file.open("D://book.txt", ios::in);
	if (!file)
		cout << "\n\n File Openning Error...";
	else
	{
		cout << "\n\n Book ID : ";
		cin >> b_id;
		file >> b_idd >> b_name >> a_name >> no_copy;
		while (!file.eof())
		{
			if (b_id == b_idd)
			{
				system("cls");
				cout << "\n\n\t\t\t\tUpdate Book Record";
				cout << "\n\n New Book Name : ";
				cin >> b_na;
				cout << "\n\n\t\t\tAuthor Name : ";
				cin >> a_na;
				cout << "\n\n No. of Copies : ";
				cin >> no_co;
				file1 << " " << b_id << " " << b_na << " " << a_na << " " << no_co << "\n";
				count++;
			}
			else
				file1 << " " << b_idd << " " << b_name << " " << a_name << " " << no_copy << "\n";
			file >> b_idd >> b_name >> a_name >> no_copy;
		}
		if (count == 0)
			cout << "\n\n Book ID Not Found...";
	}
	file.close();
	file1.close();
	remove("D://book.txt");
	rename("D://book1.txt", "D://book.txt");
}

void Library::del_book()
{
	system("cls");
	fstream file, file1;
	int no_copy, count = 0;
	string b_id, b_idd, b_name, a_name;
	cout << "\n\n\t\t\t\tDelete Book Record";
	file1.open("D://book1.txt", ios::app | ios::out);
	file.open("D://book.txt", ios::in);
	if (!file)
		cout << "\n\n File Openning Error...";
	else
	{
		cout << "\n\n Book ID : ";
		cin >> b_id;
		file >> b_idd >> b_name >> a_name >> no_copy;
		while (!file.eof())
		{
			if (b_id == b_idd)
			{
				system("cls");
				cout << "\n\n\t\t\t\tDelete Book Record";
				cout << "\n\n One Book is Deleted Successfully...";
				count++;
			}
			else
				file1 << " " << b_idd << " " << b_name << " " << a_name << " " << no_copy << "\n";
			file >> b_idd >> b_name >> a_name >> no_copy;
		}
		if (count == 0)
			cout << "\n\n Book ID Not Found...";
	}
	file.close();
	file1.close();
	remove("D://book.txt");
	rename("D://book1.txt", "D://book.txt");
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
				lib.updateBook();
                break;
            case 4:
				lib.del_book();
                break;
            case 5:
                exit(0);
                break;
            default:
                break;
        };
}

