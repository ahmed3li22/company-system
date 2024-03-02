#include<iostream>
using namespace std;

int main() {

	const int MAX = 10000;

	string names[MAX];       // Array to store employee names
	int ages[MAX];           // Array to store employee ages
	double salaries[MAX];    // Array to store employee salaries
	char genders[MAX];       // Array to store employee genders
	int added = 0;           // Counter to keep track of the number of employees added

	while (true) {
		int choice = -1;
		cout << "\nChoose the operation:\n";
		cout << "1) New employee\n";
		cout << "2) All employees\n";
		cout << "3) Delete emolyee\n";
		cout << "4) Update Salary\n";

		cin >> choice;

		// Check if choice is valid
		if (!(1 <= choice && choice <= 4)) {
			cout << "Invalid choice. choose correct choice from the menu\n";
			continue;
		}

		if (choice == 1) {  // Add new employee
			cout << "Enter name: ";
			cin >> names[added];

			cout << "Enter age: ";
			cin >> ages[added];

			cout << "Enter salary: ";
			cin >> salaries[added];

			cout << "Enter gender (M/F): ";
			cin >> genders[added];
			++added;  // Increment the counter for the next employee
		} else if (choice == 2) {  // Print all employees
			cout << "****************************\n";
			for (int i = 0; i < added; ++i) {
				if (ages[i] != -1)  // Skip deleted employees (marked with -1 age)
					cout << names[i] << " " << ages[i] << " " << salaries[i]
							<< " " << genders[i] << "\n";
			}
		} else if (choice == 3) {  // Delete employees by age
			cout << "Enter start and end age: ";
			int start, end;
			cin >> start >> end;

			for (int i = 0; i < added; ++i) {
				if (start <= ages[i] && ages[i] <= end)
					ages[i] = -1;  // Mark employee for deletion by setting age to -1
			}
		} else {  // Update salary by name
			cout << "Enter the name and salary: ";
			string name;
			int salary;
			cin >> name >> salary;

			bool is_found = false;
			for (int i = 0; i < added; ++i) {
				if (ages[i] != -1 && names[i] == name) {  // Check if employee exists and is not marked for deletion
					is_found = true;
					salaries[i] = salary;  // Update salary
					break;
				}
			}
			if (!is_found)
				cout << "No employee with this name!\n";
		}
	}
	return 0;
}
