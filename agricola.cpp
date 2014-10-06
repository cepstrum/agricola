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

stuct playerBoardVariables{
		int rooms;
		int farmers;
		int pastures;
		int stable;
		int fences; 
		char roomType;
};

void newRoundBoardResourceReplenish(int *takeOneGrain, int *dayLabourer, int *threeWood, int *oneClay, int *oneReed, int *catchFish){
	*takeOneGrain = 1;
	*dayLabourer = 2; 
	*threeWood += 3;
	*oneClay += 1;
	*oneReed += 1;
	*catchFish +=1;	
}

void takeOneGrainF(int *playerTurn,int *player1_grain, int *player2_grain, int *takeOneGrain){
	if (*playerTurn == 1){
		*player1_grain += 1;
	}
	else if (*playerTurn == 2){
		*player2_grain += 1;
	}
	*takeOneGrain = 0; 
}

int makeChoice(int *takeOneGrain, int *dayLabourer, int *threeWood, int *oneClay, int *oneReed, int *catchFish){
	int choice; 
	cout << "Please make a choice: ";
	cout << "1. take one grain" << "(" << *takeOneGrain << ") " ;
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
	//board action resources
	int takeOneGrain = 1;
	int dayLabourer = 2; 
	int threeWood = 3;
	int oneClay = 1;
	int oneReed = 1; 
	int catchFish = 1;
	//set whose turn
	int playerTurn = 1;

	//newRoundBoardResourceReplenish(&takeOneGrain, &dayLabourer, &threeWood, &oneClay, &oneReed, &catchFish);
	 

	int players = numberOfPlayers();
	resources player1Resources = {0,0,0,0,0,0,0,0,0,0}; // player1 resources struct
	resources player2Resources = {0,0,0,0,0,0,0,0,0,0}; // player 2 resources struct
	playerBoardVariables player1BV = {2,2,0,0,'w'};
	playerBoardVariables player2BV = {2,2,0,0,'w'};
	
	int choice;
	choice = makeChoice(&takeOneGrain, &dayLabourer, &threeWood, &oneClay, &oneReed, &catchFish);
	if (choice == 1){
		takeOneGrainF(&playerTurn,&player1_grain, &player2_grain, &takeOneGrain);
	}
	makeChoice(&takeOneGrain, &dayLabourer, &threeWood, &oneClay, &oneReed, &catchFish);
}


