#include <iostream>
using namespace std;

struct resources{
	int wood;
	int clay;
	int stone;
	int reed;
	int grain;
	int vegetable;
	int sheep;
	int boar;
	int cattle;
	int food;
};

struct playerBoardVariables{
		int rooms;
		int farmers;
		int pastures;
		int stable;
		int fences; 
		char roomType;
};

struct boardActionResources{
	int takeOneGrain;
	int dayLabourer;
	int threeWood;
	int oneClay;
	int oneReed;
	int catchFish;
};


void newRoundBoardResourceReplenish(boardActionResources *mainBoard){
	mainBoard->takeOneGrain = 1;
	mainBoard->dayLabourer = 2; 
	mainBoard->threeWood += 3;
	mainBoard->oneClay += 1;
	mainBoard->oneReed += 1;
	mainBoard->catchFish +=1;	
}

void takeOneGrainF(int playerTurn, resources *player1, resources *player2, boardActionResources *mainBoard){
	if (playerTurn == 1){
		player1->grain += 1;
	}
	else if (playerTurn == 2){
		player2->grain += 1;
	}
	mainBoard->takeOneGrain = 0; 
}

int makeChoice(int playerTurn, boardActionResources *mainBoard, resources *player1, resources *player2){
	int choice; 
	cout << "Please make a choice: ";
	cout << "1. take one grain" << "(" << mainBoard->takeOneGrain << ") " ;
	cin >> choice;
	return choice;
}

int numberOfPlayers()
{
	int numberOfPlayers;
	cout << "How many players? (2-5) "; 
	cin >> numberOfPlayers;
	 
	while ((numberOfPlayers < 2) || (numberOfPlayers > 5)){
		cout << "Choose between 2-5 players ";
		cin >> numberOfPlayers;
	}
	return numberOfPlayers; 
};

int main()
{
	boardActionResources mainBoard = {0,0,0,0,0,0};
	
	
	//set whose turn
	int playerTurn = 1;

	//newRoundBoardResourceReplenish(&takeOneGrain, &dayLabourer, &threeWood, &oneClay, &oneReed, &catchFish);
	 

	int players = numberOfPlayers();
	resources player1Resources = {0,0,0,0,0,0,0,0,0,0}; // player1 resources struct
	resources player2Resources = {0,0,0,0,0,0,0,0,0,0}; // player 2 resources struct
	playerBoardVariables player1BV = {2,2,0,0,'w'};
	playerBoardVariables player2BV = {2,2,0,0,'w'};
	
	int choice;
	newRoundBoardResourceReplenish(&mainBoard);
	cout << player1Resources.grain;
	choice = makeChoice(playerTurn, &mainBoard, &player1Resources, &player2Resources);
	if (choice == 1){
		takeOneGrainF(playerTurn, &player1Resources, &player2Resources, &mainBoard);
	}
	cout << player1Resources.grain;
	makeChoice(playerTurn, &mainBoard, &player1Resources, &player2Resources);
}


