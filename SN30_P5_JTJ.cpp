//// Name: 30
//// Project: Project #5
//// Project Description: Create a Guessing Game that will be a total for 5 games with 4 rounds per game. Give the user options to play the game, append their points to a file,
//// print all the answers and clues for the entire game to the screen, and allow the user to print all the contents of the file that has their game stats. Have fun!!!!
//// Due Date: 11/21/2023
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX = 120; 
void PlayGame(int gamePlayed, int& points, string answers[], string& userName); //// Plays the game.
void SaveRecentStats(string userName, int points); //// Appends game stats to a file.
void PrintAnsClues(string answers[]); ////Prints all answers and clues.
void PrintStatsFile(string statuserName, int statpoints); //// Prints contents of information in file for "SaveRecentStats" function.
int GetSelection();
//// Global constant and function declarations above here.

int main() {
	
	string name; //// String for parameters in main.
	string name2; //// Had to declare a different string from string "name" due to the paramters of function 4. Had to switch them up to get the points to add up corrctly.
	int p2 = 0; //// Same issue as string "name2' above.
	int p = 0; //// Points for paramters in main.
    int size = 0; // JTJ (Dr. Jenkins).
	string AnswersAndClues[MAX]; //// Dr. Jenkins helped me here, was unsure whether or not to use char arrays or string arrays.
	ifstream ifileAnswersAndClues;
	ifileAnswersAndClues.open("P5_in.txt");
	for (int i = 0; i < MAX && ifileAnswersAndClues >> AnswersAndClues[i]; ++i){
		size++;
	}
    int totalGames = size / 24;
    int game = 0;
//// Declarations of the main, and file-into-array above here, lines 16 - 28.
    
	int desicion = GetSelection();
	while (desicion != 0 && game < totalGames){
		switch (desicion){
			case 1:
				cout << "You have selected option 1, Play a Guessing Game" << endl;
				PlayGame(game, p, AnswersAndClues, name);
                game++;
				break;
			case 2:
				cout << "You have selected option 2, Append the Most Recent Game Stats to a file" << endl;
				SaveRecentStats(name, p);
				p = 0;
				break;
			case 3:
				cout << "You have selected option 3, Print all Answers and Associated Clues" << endl;
				PrintAnsClues(AnswersAndClues);
				break;
			case 4:
				cout << "You have selected option 4, Print the contents of the Stats File" << endl;
				PrintStatsFile(name2, p2);
				break;
			case 0:
				cout << "Now exiting game." << endl;
			default:
				cout << "Error, re-enter a valid number" << endl;
				return GetSelection();
		} //// End of switch statement for function menu/display.
		desicion = GetSelection();
	} //// End of while loop.
	return 0;
}

int GetSelection(){
	int choice = 0;
	cout << "Make a choice: " << endl;
	cout << "1: Play a Guessing Game" << endl;
	cout << "2: Append the Most Recent Game Stats to a file" << endl;
	cout << "3: Print all Answers and Associated Clues" << endl;
	cout << "4: Print the contents of the Stats File" << endl;
	cout << "0: Exit Application" << endl;
	cin >> choice;
	return choice;
}

void PlayGame(int gamePlayed, int& points, string answers[], string& userName) { //// Got help with this function with Dr. Jenkins. //// Worked closely with SN07.
	string userGuess;
	points = 0;
	int i, j, x;
    int offset = (gamePlayed * 6 * 4); //// Dr. Jenkins helped here with the offset.
	cout << "Please enter player's first and last name with no spaces: ";
	cin >> userName;
	cout << "Great! Now here are how your points will be accumulated: Each game is 4 rounds, and you will be given 5 ";
	cout << "clues per round to correctly guess If you correctly guess the answer after the first clue, you get 100 points.";
	cout << " After the second, 75, after the third, 50, after the fourth, 25, and after the fifth, 10. If you still do not";
	cout << " guess the correct answer after all 5 clues have been given, 0 points shall be given. There will be a total";
	cout << " of 5 games. Let's start guessing!" << endl;
	
		for (x = offset ; x < 24 + offset; x += 6){
			for (i = x + 1, j = 1; i < (x + 6); ++i, ++j){
				cout << "Clue " << j << ": " << answers[i] << endl;
				cout << "Guess: "; cin >> userGuess;
					    if (userGuess == answers[x] && j == 1){
						    cout << "Good Job!" << endl;
						    points += 100;
						    break;
		                }
		                    else if (userGuess == answers[x] && j == 2){
		                    	cout << "Good Job!" << endl;
		                    	points += 75;
		                    	break;
							}
								else if (userGuess == answers[x] && j == 3){
									cout << "Good Job!" << endl;
									points += 50;
									break;
								}
									else if (userGuess == answers[x] && j == 4){
										cout << "Good Job!" << endl;
										points += 25;
										break;
									}
										else if (userGuess == answers[x] && j == 5){
											cout << "Good Job!" << endl;
											points += 10;
											break;
										}
				            				else{
					        					cout << "Nope." << endl;
		                    				}
			}
		    cout << "End Round " << x / 6  + 1 << endl;
		}
	cout << "End of Guessing Game!!!!" << endl;
}

void SaveRecentStats(string userName, int points){
    ofstream ofileStatsFile;
	ofileStatsFile.open("P5stats.txt", ios:: app); //// Dr. Jenkisn helped here, was missing the "ios:: app".
	ofileStatsFile << userName << " " << points << endl;
    ofileStatsFile.close();
}

void PrintAnsClues(string answers[]){
	cout << "SN30" << endl;
	cout << endl;
	for (int i = 0; i < MAX; i += 6){
		cout << answers[i] << endl;
		for (int x = i + 1; x < (i + 6); x++){
				cout << setw(25) << answers[i] << "_" << answers[x] << endl;
		}
	}
}

void PrintStatsFile(string statuserName, int statpoints){
	ifstream ifileStatsFile;
	ifileStatsFile.open("P5stats.txt");
	cout << "SN30" << endl;
    while (ifileStatsFile >> statuserName >> statpoints)
        cout << statuserName << " " << statpoints << endl;
    	ifileStatsFile.close();
}