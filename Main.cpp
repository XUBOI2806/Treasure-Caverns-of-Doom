/**************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Main Class Definition File
 **************************************************/

 // Including Header file
#include "Main.h"

// Main function
int main() {
	// seed randoms
	srand(unsigned(time(NULL)));

	playGame();
	// wait and exit
	return 0;
}

/// <summary>
/// Creates the lcoations of the dungeon
/// </summary>
/// <returns>A list of locations with monsters and items</returns>
vector<Location*> createMap() {
	// get Locations Data
	vector<Location*> locations = retrieveLocationsData("Dungeon.txt");
	// create and initialise monsters in locations
	initialiseMonsters(locations);
	// create and initialise items in locations
	initialiseItems(locations);
	// returns the map
	return locations;
}

/// <summary>
/// Plays the game
/// </summary>
void playGame() {
	string input;
	Player* player;
	// get the locations 
	vector<Location*> locations = createMap();;
	// display the rules
	displayTextData("Rules.txt");
	// crreate player
	player = createPlayer();
	// move player to the starting location
	moveLocation(locations, 0, player);
}

/// <summary>
/// Moves player to a certain location
/// </summary>
/// <param name="locations"></param>
/// <param name="locationNumber"></param>
/// <param name="player"></param>
void moveLocation(vector<Location*> locations, int locationNumber, Player* player) {
	// get location data from the location number
	Location* location = locations[locationNumber];
	// set player into the location
	location->setPlayer(player);
	// get details of player
	player->getDetails();
	if (player->hasArtefacts()) {
		gameOver(player);
	}
	// display info
	cout << " You entered the " << location->getName() << endl;
	// get location details
	location->displayInformation();
	// display possible options that can be done
	vector<char> optionList = displayOptions(location);
	// ask for the action that the player wants to take
	askForAction(optionList, locations, locationNumber);
}

/// <summary>
/// Creates a player with the user's chosen input name
/// </summary>
/// <returns>The player object with the chosen name</returns>
Player* createPlayer() {

	string name = askForPlayerName();
	Player* player = new Player(name);
	Item* item1 = new Provisions();
	player->addItemToInventory(item1);
	return player;
}

/// <summary>
/// Asks for the players chosen name
/// </summary>
/// <returns>The players name</returns>
string askForPlayerName()
{
	string name;
	cout << " Humble Warrior, what shall you be named as?" << endl;
	cout << " Name: ";
	cin >> name;

	system("CLS");
	return name;
}

/// <summary>
/// Waits for the players input before clearing the screen and displaying the information required
/// </summary>
/// <param name="locations"></param>
/// <param name="locationNumber"></param>
void waitForPlayer(vector<Location*> locations, int locationNumber) {
	system("pause");
	system("CLS");
	locations[locationNumber]->getPlayer()->getDetails();
	locations[locationNumber]->displayInformation();
	vector<char> optionList = displayOptions(locations[locationNumber]);
	askForAction(optionList, locations, locationNumber);
}

/// <summary>
/// Asks for the users next action and checks if it is a viable option
/// </summary>
/// <param name="optionList"></param>
/// <param name="locations"></param>
/// <param name="locationNumber"></param>
void askForAction(vector<char> optionList, vector<Location*> locations, int locationNumber)
{
	Location* location = locations[locationNumber];
	char option;
	bool optionBool = false;
	cout << " What action should you choose to make?" << endl << " ";
	cin >> option;
	for (int i = 0; i < optionList.size(); i++) {
		if (optionList.at(i) == option) {
			Option optionMade = (Option)option;
			runAction(optionMade, locations, locationNumber, optionList);
			optionBool = true;
		}
	}
	if (optionBool == false) {
		system("CLS");
		locations[locationNumber]->getPlayer()->getDetails();
		location->displayInformation();
		cout << " (Seclected option is invalid. Please select a valid option below.)" << endl << endl;
		displayOptions(location);
		askForAction(optionList, locations, locationNumber);
	}
}

/// <summary>
/// Displays the Options available to the user
/// </summary>
/// <param name="location"></param>
/// <returns>A vector of options</returns>
vector<char> displayOptions(Location* location) {
	vector<char> optionList;
	string options;
	Monster* monster = location->getMonster();
	// Checks if there is a monster alive in the location
	if (monster->isAlive()) {
		options += "[A]ttack [F]lee ";
		optionList.push_back('A');
		optionList.push_back('F');
		cout << " A " << monster->getName() << " has appeared!" << endl;
		monster->getDetails();
	}
	// Move to another location or any available action
	else {
		vector<char> exits = location->getExits();
		vector<int> exitNumbers = location->getExitNumbers();
		// Checks available exits and adds the options
		for (int i = 0; i < 3; i++) {
			char exit = exits[i];
			options += "Location";
			options += to_string(exitNumbers[i]);
			switch (exit) {
			case 'N':
			{
				options += "[N] ";
				optionList.push_back('N');
				break;
			}
			case 'S':
			{
				options += "[S] ";
				optionList.push_back('S');
				break;
			}
			case 'E':
			{
				options += "[E] ";
				optionList.push_back('E');
				break;
			}
			case 'W':
			{
				options += "[W] ";
				optionList.push_back('W');
				break;
			}
			}
		}
		// Checks if the room has been examined successfully or not
		if (location->getExamined() == false and location->getItems().size() != 0) {
			options += "e[X]amine ";
			optionList.push_back('X');
		}
		// Take available items
		if (location->getItems().size() != 0 and location->getExamined() == true) {
			options += "[T]ake ";
			optionList.push_back('T');
			cout << " " << "Items found: ";
			for (int i = 0; i < location->getItems().size() - 1; i++) {
				cout << location->getItems().at(i)->getName() << ", ";
			}
			cout << location->getItems().at(location->getItems().size() - 1)->getName() << endl;
		}
		// Drop items
		if (location->getPlayer()->getInventory().size() > 2) {
			options += "[D]rop ";
			optionList.push_back('D');
		}
		// Take provisions to heal only if the player has some and if they are hurt
		if (location->getPlayer()->hasProvisions() and location->getPlayer()->isHurt()) {
			options += "[P]rovisions ";
			optionList.push_back('P');
		}
		// Checks if the player has consumables or not
		if (location->getPlayer()->hasConsumables()) {
			options += "[C]onsumables ";
			optionList.push_back('C');
		}
	}
	// Map, Help and Quit options are always available
	options += "[M]ap [H]elp [Q]uit";
	optionList.push_back('M');
	optionList.push_back('H');
	optionList.push_back('Q');
	cout << " " << options << endl;
	return optionList;
}

/// <summary>
/// Runs the chosen action
/// </summary>
/// <param name="option"></param>
/// <param name="locations"></param>
/// <param name="locationNumber"></param>
/// <param name="optionList"></param>
void runAction(Option option, vector<Location*> locations, int locationNumber, vector<char> optionList) {
	Location* location = locations[locationNumber];
	switch (option) {
		// Quits the game
	case Option::Q:
	{
		cout << " You quit the game" << endl;
		endGame();
		break;
	}
	// Displays the help menu
	case Option::H:
	{
		system("CLS");
		displayTextData("Rules.txt");
		system("CLS");
		location->displayInformation();
		vector<char> optionList = displayOptions(location);
		askForAction(optionList, locations, locationNumber);
		break;
	}
	// Displays the map
	case Option::M:
	{
		system("CLS");
		displayTextData("Map.txt");
		system("CLS");
		location->displayInformation();
		vector<char> optionList = displayOptions(location);
		askForAction(optionList, locations, locationNumber);
		break;
	}
	// Attack option
	case Option::A:
	{
		Player* player = location->getPlayer();
		Monster* monster = location->getMonster();
		int turns = 0;
		// Checks if the monster is a dragon
		if (monster->getName() == "Dragon") {
			// removes the leather armour and swords
			player->burnItems();
		}
		// Runs a while loop until either the player or the monster dies
		while (player->isAlive() and monster->isAlive()) {
			int playerDamage = player->getAttack() + rand() % 9 + 2;
			int monsterDamage = monster->getAttack() + rand() % 9 + 2;
			// Checks if the player's damage is greater than the Monsters
			if (playerDamage >= monsterDamage) {
				monster->hurt(player->getDamage());
			}
			else {
				player->hurt(monster->getDamage());
			}
			// Checks if the turns go over 25. This usually means that neither parties are doing damage.
			if (turns == 25) {
				cout << " The monster got tired and you landed a killing blow!";
				monster->hurt(100);
			}
			turns += 1;
		}
		// Checks gameover condition
		if (player->isAlive() == false) {
			cout << " You died!" << endl;
			gameOver(player);
		}
		// Player wins the fight aftermath
		else {
			cout << " You won the fight!" << endl;
			monster->displayDrops();
			// Asks the user if they want to pick up the monster's dropped loot
			if (monster->getDrops().size() != 0) {
				cout << " Do you want to collect the loot? [Y/N]" << endl;
				char input;
				cin >> input;
				// Checks if the input is valid or not
				while (input != 'Y' && input != 'N') {
					cout << " Invalid option choice." << endl << "Please try again and enter a valid option: " << endl;
					cin >> input;
					cout << endl;
				}
				// Takes item
				if (input == 'Y') {
					for (int i = 0; i < monster->getDrops().size(); i++) {
						location->getPlayer()->addItemToInventory(monster->getDrops().at(i));
					}
					cout << " You collected all the loot!" << endl;
				}
				// Drops item
				else {
					for (int i = 0; i < monster->getDrops().size(); i++) {
						location->addItem(monster->getDrops().at(i));
					}
					cout << " The loot were dropped into the darkness...";
				}
			}
			useLantern(player);
			waitForPlayer(locations, locationNumber);
		}
		break;
	}
	// FLee action
	case Option::F:
	{
		Player* player = location->getPlayer();
		Monster* monster = location->getMonster();
		player->hurt(monster->getAttack());
		// Checks if the player is dead or not
		if (player->isAlive() == false) {
			cout << " You died" << endl;
			gameOver(player);
		}
		// display information
		else {
			cout << " You escaped the fight!" << endl;
			vector<int> exitNumbers = location->getExitNumbers();
			system("pause");
			system("CLS");
			moveLocation(locations, exitNumbers[0], player);
		}
		useLantern(player);
		break;
	}
	// Examine option
	case Option::X:
	{
		bool found = false;
		if (rand() % 11 <= 3) {
			// Adds gold and gems to the player
			cout << " You found some gems and gold!" << endl;
			// Creates gold amount and adds it to the player
			int goldAmount = rand() % 7 + 6;
			Gold gold(goldAmount);
			location->getPlayer()->addGold(gold);
			// Creates gem amount and adds it to the player
			int gemAmount = rand() % 3 + 1;
			Gem gem(gemAmount);
			location->getPlayer()->addGem(gem);
			// displays data
			cout << " You picked up " << goldAmount << " gold and " << gemAmount << " gems!" << endl;
			location->getPlayer()->getGold();
			location->getPlayer()->getGems();
			found = true;
		}
		// Checks if the player found items
		if (rand() % 11 <= 2 and location->getExamined() == false) {
			cout << " You found some items!" << endl;
			location->setExamined(true);
			found = true;
		}
		// If nothing was found display information
		if (found == false) {
			cout << " Nothing was found! Truly unfortunate..." << endl;
		}
		useLantern(location->getPlayer());
		waitForPlayer(locations, locationNumber);
		break;
	}
	// Take items action
	case Option::T:
	{
		int inventorySize = location->getPlayer()->getInventory().size();
		int monsterDropSize = location->getMonster()->getDrops().size();
		if (inventorySize + monsterDropSize <= 12) {
			for (int i = 0; i < location->getItems().size(); i++) {
				location->getPlayer()->addItemToInventory(location->getItems().at(i));
			}
			cout << " You picked up all the items!" << endl;
			location->clearItems();
		}
		else {
			cout << "Inventory is too full to collect all items. Please drop some items before adding more.";
		}
		useLantern(location->getPlayer());
		waitForPlayer(locations, locationNumber);
		break;
	}
	// Use provisions action
	case Option::P:
	{
		vector<Item*> inventory = location->getPlayer()->getInventory();
		for (int i = 0; i < inventory.size(); i++) {
			if (inventory[i]->getName() == "Provisions") {
				Provisions* provsion = static_cast<Provisions*>(inventory[i]);
				provsion->use(location->getPlayer());
				if (inventory[i]->getUses() == 0) {
					location->getPlayer()->removeItemFromInventory(i);
				}
				break;
			}
		}
		useLantern(location->getPlayer());
		waitForPlayer(locations, locationNumber);
		break;
	}
	// Consume action
	case Option::C:
	{
		vector<Item*> inventory = location->getPlayer()->getInventory();
		for (int i = 0; i < inventory.size(); i++) {
			// Checks if the user has any consumables 
			if (inventory[i]->getUses() > 0 and inventory[i]->getName() != "Provisions" and inventory[i]->getName() != "Lantern") {
				Consumable* consumable = static_cast<Consumable*>(inventory[i]);
				consumable->use(location->getPlayer());
				if (inventory[i]->getUses() == 0) {
					location->getPlayer()->removeItemFromInventory(i);
				}
				break;
			}
		}
		useLantern(location->getPlayer());
		waitForPlayer(locations, locationNumber);
		break;
	}
	// Drop item action
	case Option::D:
	{
		system("CLS");
		int input;
		int cancel = location->getPlayer()->getInventory().size() - 2;
		bool inputSuccess = false;
		do
		{
			// Let player choose what item they can drop except for the map and lantern
			location->getPlayer()->displayInventory();
			cout << " What item would you like to drop?" << endl;
			cout << " Type " << cancel << " to cancel" << endl;
			cin >> input;
			// Checks for invalid input
			if (cin.fail()) {
				cout << " Invalid option choice." << endl << " Please try again and enter a valid option... " << endl;
				system("pause");
				system("CLS");
			}
			else if (input < 0 || input>cancel) {
				cout << " Invalid option choice." << endl << "Please try again and enter a valid option... " << endl;
				system("pause");
				system("CLS");
			}
			else {
				inputSuccess = true;
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (!inputSuccess);
		// Checks if the input is the cancel option
		if (input == cancel) {
			system("CLS");
			location->displayInformation();
			vector<char> optionList = displayOptions(location);
			askForAction(optionList, locations, locationNumber);
		}
		// Else remove the item
		else {
			Item* item = location->getPlayer()->removeItemFromInventory(input + 2);
			location->addItem(item);
			cout << " The item has been removed!" << endl;
			useLantern(location->getPlayer());
			waitForPlayer(locations, locationNumber);
		}
		break;
	}
	// Move north
	case Option::N:
	{
		useLantern(location->getPlayer());
		vector<char> exits = location->getExits();
		vector<int> exitNumbers = location->getExitNumbers();
		char value = (char)Option::N;
		for (int i = 0; i < 3; i++) {
			char exit = exits[i];
			if (exit == value) {
				Player* player = location->removePlayer();
				system("CLS");
				moveLocation(locations, exitNumbers[i], player);
				break;
			}
		}
		break;
	}
	// Move South
	case Option::S:
	{
		useLantern(location->getPlayer());
		vector<char> exits = location->getExits();
		vector<int> exitNumbers = location->getExitNumbers();
		char value = (char)Option::S;
		for (int i = 0; i < 3; i++) {
			char exit = exits[i];
			if (exit == value) {
				Player* player = location->removePlayer();
				system("CLS");
				moveLocation(locations, exitNumbers[i], player);
				break;
			}
		}
	}
	// Move East
	case Option::E:
	{
		useLantern(location->getPlayer());
		vector<char> exits = location->getExits();
		vector<int> exitNumbers = location->getExitNumbers();
		char value = (char)Option::E;
		for (int i = 0; i < 3; i++) {
			char exit = exits[i];
			if (exit == value) {
				Player* player = location->removePlayer();
				system("CLS");
				moveLocation(locations, exitNumbers[i], player);
				break;
			}
		}
	}
	// Move West
	case Option::W:
	{
		useLantern(location->getPlayer());
		vector<char> exits = location->getExits();
		vector<int> exitNumbers = location->getExitNumbers();
		char value = (char)Option::W;
		for (int i = 0; i < 3; i++) {
			char exit = exits[i];
			if (exit == value) {
				Player* player = location->removePlayer();
				system("CLS");
				moveLocation(locations, exitNumbers[i], player);
				break;
			}
		}
	}
	}
}

/// <summary>
/// Use lantern function
/// </summary>
/// <param name="player"></param>
void useLantern(Player* player)
{
	player->getInventory()[0]->use();
	int uses = player->getInventory()[0]->getUses();
	// Checks if there are still any uses left
	if (uses < 1) {
		cout << " You run out of light!" << endl << " You slowly get consumed by the darkness and the monsters that reside in the dungeon..." << endl;
		player->setHealth(0);
		gameOver(player);
	}
	else {
		cout << " The lantern has " << uses << " uses left!" << endl;
	}

}

/// <summary>
/// Display Text file data
/// </summary>
/// <param name="filename"></param>
void displayTextData(string filename) {
	string line;
	ifstream file(filename);
	if (file.is_open()) {
		while (getline(file, line)) {
			cout << line << '\n';
		}
		file.close();
	}
	else cout << "Unable to open file";
	system("pause");
	system("CLS");
}

/// <summary>
/// get location data from file
/// </summary>
/// <param name="filename"></param>
/// <returns>A list of locations</returns>
vector<Location*> retrieveLocationsData(string filename) {
	vector<Location*> locations;
	string line;
	string name;
	string description;
	ifstream file(filename);
	if (file.is_open()) {
		for (int index = 0; index < 20; index++) {
			vector<char> exits;
			vector<int> exitNumbers;
			getline(file, line);
			for (int i = 0; i < 3; i++) {
				char exit = line[i];
				exits.push_back(exit);
			}
			for (int i = 0; i < 3; i++) {
				getline(file, line);
				int number = stoi(line);
				exitNumbers.push_back(number);
			}
			getline(file, name);
			bool end = false;
			string description;
			do {
				getline(file, line);
				if (!line.empty()) {
					description += line;
					description += "\n";
				}
				else {
					end = true;
				}
			} while (!end);
			Location* location = new Location(index, name, description, exits, exitNumbers);
			locations.push_back(location);
		}
		file.close();
		return locations;
	}
	else cout << "Unable to open file";
}

/// <summary>
/// Intitialise the monsters for the locations
/// </summary>
/// <param name="locations"></param>
void initialiseMonsters(vector<Location*> locations) {
	string line;
	// Runs for all locations except for the start and end
	for (int index = 1; index < 19; index++) {
		// Randomly generates a monster
		int number = rand() % 4;
		switch (number) {
		case 0:
		{
			Monster* monster = new Goblin();
			locations[index]->setMonster(monster);
			break;
		}
		case 1:
		{
			Monster* monster = new Hobogoblin();
			locations[index]->setMonster(monster);
			break;
		}
		case 2:
		{
			Monster* monster = new Ogre();
			locations[index]->setMonster(monster);
			break;
		}
		case 3:
		{
			Monster* monster = new Troll();
			locations[index]->setMonster(monster);
			break;
		}
		}
	}
	// Adds a dragon for the last dungeon
	Monster* monster = new Dragon();
	locations[19]->setMonster(monster);
}

/// <summary>
/// Intitialise the items for the locations
/// </summary>
/// <param name="locations"></param>
void initialiseItems(vector<Location*> locations) {
	// Adds an item for every room excpet for the start
	for (int index = 1; index < 20; index++) {
		int rng = rand() % 4;
		switch (rng) {
		case 0:
		{
			Item* item = new Sword();
			locations[index]->addItem(item);
			break;
		}
		case 1:
		{
			Item* item = new Provisions();
			locations[index]->addItem(item);
			break;
		}
		case 2:
		{
			Item* item = new LeatherArmour();
			locations[index]->addItem(item);
			break;
		}
		case 3:
		{
			Item* item = new PotionFlask();
			locations[index]->addItem(item);
		};
		}
	}
}

/// <summary>
/// Game over conditions
/// </summary>
/// <param name="hasWon"></param>
void gameOver(Player* player) {
	int score = player->getHealth();
	if (score > 0) {
		for (int i = 0; i < player->getInventory().size(); i++) {
			if (player->getInventory()[i]->getName() == "Lantern") {
				score += player->getInventory()[i]->getUses();
			}
			if (player->getInventory()[i]->getName() == "Provisions") {
				score += player->getInventory()[i]->getUses();
			}
		}
		cout << " You successfully escape the dungeon with the 5 artefacts!" << endl;
		cout << " You live the rest of your life in fame and glory!" << endl << " You won!";
		cout << " Your score is: " << score;
	}
	else {
		cout << endl << " Game Over" << endl << endl;
	}
	endGame();
}

/// <summary>
/// End game and stops the application
/// </summary>
void endGame()
{
	system("PAUSE");
	exit(0);
}


void testPlayer() {
	Player newPlayer;
	newPlayer.testPlayer();
}

void testMonster() {
	Monster newMonster;
	newMonster.testMonster();
}

void testGoblin() {
	Goblin newGoblin;
	newGoblin.testMonster();
}

void testHobogoblin() {
	Hobogoblin newHobogoblin;
	newHobogoblin.testMonster();
}

void testItem() {
	Item newItem;
	newItem.testItem();
}

void testDragon() {
	Dragon newDragon;
	newDragon.testMonster();
}

void testAll() {
	//Tests all classes
	cout << "\n Player Test";
	testPlayer();
	cout << "\n Monster Test";
	testMonster();
	cout << "\n Goblin Test";
	testGoblin();
	cout << "\n Hobogoblin Test";
	testHobogoblin();
	cout << "\n Item Test";
	testItem();
	cout << "\n Dragon Test";
	testDragon();
	cout << "\n Location Test";
	testLocation();
	//cout << "\n Dungeon Test";
	//testDungeon();
}

void testLocation() {
	Location newLocation;
	newLocation.testLocation();
}