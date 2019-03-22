/*
Section: 402
Assignment: Lab3
Author: Ryan Bezold
Last Modified: 1/30/2019
*/

#include<IOStream>
#include<string>
#include<iomanip>
#include<Windows.h>


using namespace std;

//Define prices and taxes
const float TaxRate = 0.06, HotDog = 2.5, DeluxHD = 3.5, LargeDrink = 2.25, SmallDrink = 1.5;

int main()
{


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << fixed << setprecision(2);
	float TaxedTotal = 0;
	float change;
	float tax;
	float cashIN;
	float total = 0;
	string choice;
	char option;
	bool Continue = true;
	bool GetCash = true;
	// print logo
	SetConsoleTextAttribute(hConsole, 14);
	cout << "-----Ryan's Hot Dogs and Drinks -------" << endl;
	
	// loop until exit program
	while (Continue)
	{
		//print menu
		SetConsoleTextAttribute(hConsole, 14);
		cout << "H - HotDog     \t\t$2.50   D - Delux HotDog\t$3.50 " << endl;
		cout << "S - Small Drink\t\t$1.50   L - Large Drink \t$2.25 " << endl;
		cout << "H - Finish Order\t\tX - Exit System" << endl;
		

		// get choice
		SetConsoleTextAttribute(hConsole, 13);
		cout << "Enter option ========>";
		SetConsoleTextAttribute(hConsole, 11);
		cin >> choice;
		option = toupper(choice[0]);
		
		switch (option)
		{
			case 'H':
				total = total + HotDog;
				SetConsoleTextAttribute(hConsole, 10);
				cout << "Current Sub Total: $ " << total << endl << endl;
				break;
			case 'D':
				total = total + DeluxHD;
				SetConsoleTextAttribute(hConsole, 10);
				cout << "Current Sub Total: $ " << total << endl << endl;
				break;
			case 'S':
				total = total + SmallDrink;
				SetConsoleTextAttribute(hConsole, 10);
				cout << "Current Sub Total: $ " << total << endl << endl;
				break;
			case 'L' :
				total = total + LargeDrink;
				SetConsoleTextAttribute(hConsole, 10);
				cout << "Current Sub Total: $ " << total << endl << endl;
				break;
			case 'F' :

				SetConsoleTextAttribute(hConsole, 10);
				cout << "Sub Total: $" << total << endl;
				tax = TaxRate * total;
				cout << "Tax:       $" << tax << endl;
				TaxedTotal = total * TaxRate + total;
				cout << "Total:     $" << TaxedTotal << endl;
				
				while (GetCash)
				{
					SetConsoleTextAttribute(hConsole, 10);
					cout << "Enter Cash: ";
					SetConsoleTextAttribute(hConsole, 11);
					cin >> cashIN;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore();
						SetConsoleTextAttribute(hConsole, 12);
						cout << "Invalid Input" << endl;
						SetConsoleTextAttribute(hConsole, 7);

					}
					else
					{
						GetCash = false;
					}
				}
				change = cashIN - TaxedTotal;
				SetConsoleTextAttribute(hConsole, 10);
				cout << "Change:    $" << change << endl;
				SetConsoleTextAttribute(hConsole, 7);
				system("PAUSE");
				cout << endl;

				//zero out values for next order
				TaxedTotal = 0;
				change = 0;
				cashIN = 0;
				total = 0;
				GetCash = true;
				break;
			case 'X':
				Continue = false;
				SetConsoleTextAttribute(hConsole, 7);
				system("PAUSE");
				break;
				
				

		}
		
	}

	


}