#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Budgeting {
	private:
		int budget;
		const string filename = "Text.txt";
	public: 

		int expenses;
		Budgeting() {
			ifstream inFile(filename);
			if (inFile.is_open()) {
				inFile >> budget;
				if (inFile.fail()) {
					budget = 5000;
				}
				inFile.close();	
			}
			else {
				budget = 5000;
			}
		}
		void DisplayOptions() {
			cout << "Welcome to our Budget Allocator!\nWhat would you do today?\n";
			cout << "1. View Budget \n2. Adjust Budget \n3. Wait \n4. Exit\n ";
			
		}
		void ViewBudget() {
			
			cout << "Your budget is: " << budget << "\n";
		}

		void AddCurrentExpenses (){

			cout << "What is your expenses \n";
			cin >> expenses;

			budget -= expenses;

			cout << "Your updated budget is " <<  budget << "\n" ;
		}

		void AdjustBudget() {

			cout << "Set new budget: ";
			cin >> budget;

			ofstream outFile(filename);
			if (outFile.is_open()) {
				outFile << budget;
				outFile.close();
				cout << "Your new budget is " << budget << "\n";
			}
			else {
				cout << "Unable to set budget to file";
			}
		}
		void OnRun() {
			int option;
			do {
				DisplayOptions();
				cin >> option;
			
				switch(option) {
				case 1:
					// Option
					ViewBudget();
					break; 
				case 2:
					// Option
					AdjustBudget();
					break;
				case 3:
					// Option
					AddCurrentExpenses();
					break;
				case 4:
					cout << "Exiting now";
					break;
				default:
					"Invalid choice Try again";
					break;
				}

			} while (option != 4);
		}
	
};

int main(){
	Budgeting budgeting;
	budgeting.OnRun();
}