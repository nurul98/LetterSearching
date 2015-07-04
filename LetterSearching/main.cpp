#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <chrono>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

const int MAX_LETTERS = 20;
const int BUFSIZE = 200;

int rand(void);

char word[MAX_LETTERS];
char letter;
int i;

void getWord(char arr[])
{
	cout <<endl<<"  The word entered is "<< arr;
}

int findLetter(const char arr[], char c)
{
	int i,counter=0;

	if (strchr(arr, c) != NULL)
	{
		cout <<endl<<"  " << c << " was found in " << arr << ".\n";

		for (i = 0; i < MAX_LETTERS; i++)
		{
			if (arr[i] == c)
			{
				counter++;
			}
		}
	}
	else
	{
		cout <<endl<< "  " << c << " was not found in " << arr << ".\n";
	}
	
	return counter;
}

int main()
{
	int letter_counter = 0;

	cout << endl;
	time_t t = time(0); //obtain the current time_t value
	tm now = *localtime(&t); //convert it to tm
	char tmdescr[BUFSIZE] = { 0 };
	const char fmt[] = "%A, %d %B %Y";
	if (strftime(tmdescr, sizeof(tmdescr) - 1, fmt, &now)>0)
		cout << "            --------Nurul Fazilah     571114     " << tmdescr << "-----------" << endl << endl;
	else
		cerr << " strftime failed. Errno code: " << errno << endl;

	srand((unsigned)time(NULL));
	
	cout << endl << endl << endl << "  Enter a word and press <Enter>: ";
	cin >> word;
	getWord(word);

	cout << endl << endl << endl << "  Enter a letter and press <Enter>: ";
	cin >> letter;
	
	while (letter!='#')
	{
		letter_counter=findLetter(word, letter);
		cout << "  Number of "<<letter<< " is " << letter_counter;
		cout << endl << endl << endl << "  Enter a letter and press <Enter>: ";
		cin >> letter;
	}

	cout << endl << endl << endl << "  Thank you. You exit the program..";
	
	cin.clear();
	cin.ignore();
	cin.get();

	return 0;
}