#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
float game();
string test_choice();
void opener();
void finished(float);

int main() {
	opener();
	float score = game();
	finished(score);
	
	return 0;
}

float game() {
	string test = test_choice();
	cout << "Enter in the letter choice (A, B, C, D, E) or T or F for true or false." << endl;
	cout << '\n' << "Press the Enter key to start!" << "\n";
	cin.ignore();
	cin.get();
	int score = 0;
	int poss_score = 0;
	float perc_score;
	char answer;
	char guess;
	char cont;
	string line;
	ifstream myfile(test);
	cout << string(50, '\n');
	if (myfile.is_open())
	{	
		while (getline(myfile, line))
		{
			int i = 0;
			if (line[i] == 'A' && line[i + 1] == 'n' && line[i + 2] == 's') {
				bool stop = false;
				int j = 6;
				while (!stop) {
					if (isalpha(line[j])) {
						answer = line[j];
						break;
					}
					else
						j++;

				}
				cout << "\n";
				cout << "Your guess: ";
				cin >> guess;
				cout << "\n";
				guess = toupper(guess);
				if (guess == answer) {
					score++;
					poss_score++;
					cout << "Correct! ";
					cout << "The answer is " << answer << "." << endl;
				}
				else {
					cout << "Wrong, the answer was " << answer << "." << endl;
					poss_score++;
				}
				
				cout << "You have gotten " << score << " out of " << poss_score << " correct." << endl;;
				cout << '\n' << "Press the Enter key to continue...";
				cin.ignore();
				cin.get();
				cout << string(50, '\n');
			}
			else
				cout << line << endl;
		}
		perc_score = static_cast<float>(score) / static_cast<float>(poss_score) * 100;
		myfile.close();
	}	
	else cout << "Unable to open file";
	return perc_score;
}

void opener() {
	string line;
	ifstream myfile("Welcome.txt");
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			cout << line << endl;
		}
		myfile.close();
	}
	cout << '\n';
	cin.get();	
}

void finished(float score) {
	string line;
	ifstream myfile("finished.txt");
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			cout << line << endl;
		}
		myfile.close();
	}
	cout << '\n';
	cout << '\n';
	cout << "Your overall grade: " << fixed << setprecision(1) << score << "%" << endl;
	cin.get();
}

string test_choice() {
	string c;
	string choice;
	cout << "Which chapter would you like to choose?" << endl;
	cout << "Choices: 8, 9, 10 , or 11" << endl;
	bool stop = false;
    while (!stop) {
		cout << "Chapter: ";
		cin >> choice;
        while (!isdigit(choice[0])){
            cout << "\n" << "That's not even a number!" << endl;
			cout << "Your only choices are 8, 9, 10, or 11" << endl;
            cout << "Chapter: ";
		    cin >> choice;
        }    
        int choice1 = stoi (choice);
		cout << endl;
		switch (choice1) {
		case 8: c = "chapter8.txt";
			stop = true;
			break;
		case 9: c = "chapter9.txt";
			stop = true;
			break;
		case 10: c = "chapter10.txt";
			stop = true;
			break;
		case 11: c = "chapter11.txt";
			stop = true;
			break;
        default: cout << "Your only choices are 8, 9, 10, or 11" << endl;
        }	
    }
	return c;
}


