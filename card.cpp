#include <iostream>
#include <string>

using namespace std;


int main()
{
	cout << "\tWelcome to Inventory!" << endl;

	//items
	int NUM_CARDS = 52;
	int NUM_RANK = 13;
	int NUM_SUIT = 4;
	string rank[NUM_RANK] = {"2", "3", "4",
		"5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
	char suit[NUM_SUIT] = { 'c', 'h', 's', 'd' };//BUNLARI DIREK BUYUK HARF VE YA ASCHI KODUYKA YAZIN 

	int choice;         //menu choice

	do
	{
		cout << endl << "Inventory" << endl;
		cout << "---------" << endl << endl;
		cout << "0 - Quit" << endl;
		cout << "1 - Shuffle deck";
		cout << endl;
		cout << "2 - Display deck";
		cout << endl;
		cout << endl << "Choice: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 0:
			cout << "Good-bye." << endl;
			break;
		case 1:
			//cout << "Shuffled:" << endl;
			break;
		case 2:
			cout << "Deck: " << endl;
			for (int i = 0; i < NUM_RANK; i++)
			{
				for (int j = 0; j < NUM_SUIT; j++)
				{
					cout << rank[i] << suit[j] << " ";
				}
				cout << endl;
			}
			break;
		default:
			cout << "Sorry, " << choice;
			cout << " isn't a valid choice." << endl;
		}
	} while (choice != 0);

	return 0;
}