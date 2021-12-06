#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <Windows.h>
#include <algorithm>
using namespace std;


//===================Variables & Constants=================================================================================================================================================================================================//
string banner0 = R"( __   __        _______        ______          _______        _______                                                         )";
string banner1 = R"(|  | |  |      |       |      |    _ |        |       |      |       |                                                        )";
string banner2 = R"(|  |_|  |      |    ___|      |   | ||        |   _   |      |  _____|                                                        )";
string banner3 = R"(|       |      |   |___       |   |_||_       |  | |  |      | |_____                                                         )";
string banner4 = R"(|       | ___  |    ___| ___  |    __  | ___  |  |_|  | ___  |_____  | ___                                                    )";
string banner5 = R"(|   _   ||   | |   |___ |   | |   |  | ||   | |       ||   |  _____| ||   |                                                   )";
string banner6 = R"(|__| |__||___| |_______||___| |___|  |_||___| |_______||___| |_______||___|                                                   )";
string banner7 = R"( _______  ___   __    _  _______  ___        _______  ______   __   __  _______  __    _  _______  __   __  ______    _______ )";
string banner8 = R"(|       ||   | |  |  | ||   _   ||   |      |   _   ||      | |  | |  ||       ||  |  | ||       ||  | |  ||    _ |  |       |)";
string banner9 = R"(|    ___||   | |   |_| ||  |_|  ||   |      |  |_|  ||  _    ||  |_|  ||    ___||   |_| ||_     _||  | |  ||   | ||  |    ___|)";
string banner10 = R"(|   |___ |   | |       ||       ||   |      |       || | |   ||       ||   |___ |       |  |   |  |  |_|  ||   |_||_ |   |___ )";
string banner11 = R"(|    ___||   | |  _    ||       ||   |___   |       || |_|   ||       ||    ___||  _    |  |   |  |       ||    __  ||    ___|)";
string banner12 = R"(|   |    |   | | | |   ||   _   ||       |  |   _   ||       | |     | |   |___ | | |   |  |   |  |       ||   |  | ||   |___ )";
string banner13 = R"(|___|    |___| |_|  |__||__| |__||_______|  |__| |__||______|   |___|  |_______||_|  |__|  |___|  |_______||___|  |_||_______|)";



string Banner[] = { banner0, banner1 ,banner2, banner3, banner4, banner5, banner6, banner7, banner8, banner9, banner10, banner11, banner12, banner13 };


enum en_DIRS { NORTH, EAST, SOUTH, WEST };
//enum en_ROOMS { SPORTSHOP, CASINO, CARPARK, LOBBY, RESTAURANT, CORRIDOR, STOREROOM, POOL, GARDEN, POND, PUMPROOM };
enum en_ROOMS {
	BRIDGE, CAPTAIN_QUARTERS, CORM4, COMMANDER_QUARTERS, ARMORY, MED_BAY, CORM3, MY_QUARTERS, MESS_HALL, HANGAR1, SHUTTLE_BAY1, CORL3, CB1, CORM2, CB2, CORR3, SHUTTLE_BAY2, HANGAR2,
	CORL2, CB1_BATHROOM, CORM1, CB2_BATHROOM, CORR2, CORL1, CORL0, CORM0, CORR0, CORR1, ENG_STORAGE, ENGINEERING, TRANSPORTER_ROOM, ENGINE_CORE, CURINVENTORY, EQUIPMENT
};
enum en_VERBS { GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK, NAVIGATE, THINK, FIGHT, COMBINE, EQUIP, EQUIPPED, CHEAT};
enum en_NOUNS {
	STORE_DOOR, MAGNET, METER, ROULETTE, MONEY, FISHROD, HANGAR1_KEYCARD, COMMANDER_TABLET, PLUNGER, CAPTAIN_ID, TROLL_DOLL, EMPTY_GUN, BULLETS, LOADED_GUN, SHUTTLE1, SHUTTLE2, ALIENSHIP1, CARGOBOX1, CARGOBOX2,
	CARGOBOX3, CARGOBOX4, CARGOBOX5, CARGOBOX6, FORK, SPOON, BATTERIES, DEAD_LASERGUN, LASERGUN, BRIDGE_DOOR, HANGAR1_DOOR, KEYPAD, BROKENDOOR, TRANSPORTERDOOR, TRANSPORTER
};

string NOUN_NAMES[] = { "DOOR", "MAGNET", "METER", "ROULETTE", "MONEY", "ROD", "KEYCARD", "PAD", "PLUNGER", "ID", "DOLL", "GUN", "BULLETS", "LOADEDGUN",
"SHUTTLE1", "SHUTTLE2", "SPACECRAFT", "BOX1", "BOX2", "BOX3", "BOX4", "BOX5", "BOX6", "FORK", "SPOON", "BATTERIES", "LASERGUN", "POWEREDLASERGUN","BRIDGEDOOR","HANGARDOOR1","KEYPAD", "BROKENDOOR", "TRANSPORTERDOOR" , "TRANSPORTER"};

const int NONE = -1;
const int DIRS = 4;
const int ROOMS = 34;
const int VERBS = 15;
const int NOUNS = 34;
bool win;

//const int waitTime = 100;
//int typeTime = 25;

const int waitTime = 10;
int typeTime = 1;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class Room;
class Words;
class Nouns;
void set_directions(vector<Words>* vector);
void set_verbs(vector<Words>* vector);
//void set_nouns(vector<Noun>* vector);
int RandLocation();
void section_command(string Cmd, string& wd1, string& wd2);
//void look_around(vector<Room>& roomvector, int loc, Room& rms, vector<Words>* dir, vector<Noun>* nns);
//bool parser(int& loc, vector<Room>& roomvector, Room& rms, string wd1, string wd2, vector<Words>& dir, vector<Words>* vbs, vector<Noun>* nns);
ostream& operator<<(ostream& os, Room& givenRoom);
Room Index(vector<Room>* roomvector, int index);
int Transporter(vector<Room>* roomvector);
void Report(string report, bool newLine);

//===================Classes===============================================================================================================================================================================================================//

class Words
{
public:
	Words(string word, int code);
	~Words();
	string GetWord();
	void SetWord(string newWord);
	int GetCode();
	void SetCode(int newCode);
private:
	string word;
	int code;
};

string Words::GetWord()
{
	return word;
}

void Words::SetWord(string newWord)
{
	word = newWord;
}

int Words::GetCode()
{
	return code;
}

void Words::SetCode(int newCode)
{
	code = newCode;
}

Words::Words(string word = "", int code = -1) :
	word(word),
	code(code)
{}

Words::~Words()
{
	
}

class Room
{
public:
	Room(string description = " ", int north = 0, int east = 0, int south = 0, int west = 0);
	~Room();
	void SetExit(int dir, int room);
	int GetExit(int dir);
	void SetDescription(string newDescription);
	string GetDescription();

private:
	string description;
	int exits_to_room[DIRS];
};

void Room::SetDescription(string newDescription)
{
	description = newDescription;
}

string Room::GetDescription()
{
	return description;
}


Room::Room(string description, int north, int east, int south, int west) :
	description(description)
{
	exits_to_room[NORTH] = north;
	exits_to_room[EAST] = east;
	exits_to_room[SOUTH] = south;
	exits_to_room[WEST] = west;
}

void Room::SetExit(int dir, int room)
{
	exits_to_room[dir] = room;
}

int Room::GetExit(int dir)
{
	return exits_to_room[dir];
}
Room::~Room()
{
	
	
}



class Noun : public Words {
public:
	Noun(string word = "", string description = "", int code = -1, int location = -1, bool can_carry = -1, string examine = "", bool can_equip = true);
	~Noun();
	string GetExamine();
	void SetExamine(string newExamine);
	//string GetWord();
	//void SetWord(string newWord);
	string GetDescription();
	void SetDescription(string newDescription);
	//int GetCode();
	//void SetCode(int newCode);
	int GetLocation();
	void SetLocation(int newLocation);
	bool GetCan_Carry();
	void SetCan_Carry(bool newCarry);
	bool GetCan_Equip();
	void SetCan_Equip(bool newEquip);
private:
	string examine;
	//string word;
	string description;
	//int code;
	int location;
	bool can_carry;
	bool can_equip;
};

string Noun::GetExamine()
{
	return examine;
}

void Noun::SetExamine(string newExamine)
{
	examine = newExamine;
}

//string Noun::GetWord()
//{
//	return word;
//}
//
//void Noun::SetWord(string newWord)
//{
//	word = newWord;
//}

string Noun::GetDescription()
{
	return description;
}

void Noun::SetDescription(string newDescription)
{
	description = newDescription;
}

//int Noun::GetCode()
//{
//	return code;
//}
//void Noun::SetCode(int newCode)
//{
//	code = newCode;
//}
int Noun::GetLocation()
{
	return location;
}
void Noun::SetLocation(int newLocation)
{
	location = newLocation;
}
bool Noun::GetCan_Carry()
{
	return can_carry;
}
void Noun::SetCan_Carry(bool newCarry)
{
	can_carry = newCarry;
}
bool Noun::GetCan_Equip()
{
	return can_equip;
}
void Noun::SetCan_Equip(bool newEquip)
{
	can_equip = newEquip;
}

Noun::Noun(string word, string description, int code, int location, bool can_carry, string examine, bool can_equip) :
	//word(word),
	description(description),
	//code(code),
	location(location),
	can_carry(can_carry),
	can_equip(can_equip),
	examine(examine)
{
	SetWord(word);
	SetCode(code);
	if (examine == "")
	{
		examine = description;
	}

}

Noun::~Noun()
{
	
}

//===================User Defined Functions==========================================================================================================================================================================================//
inline void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void setCursorPosition(int x, int y)
{
	x = x + 114;
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
	ShowConsoleCursor(false);
}

void StartScreen()
{
	SetConsoleTextAttribute(hConsole, 1);
	for (int k = 0; k < 127; k++)
	{
		for (int i = 0; i < 14; i++)
		{
			setCursorPosition(100 - k, 8 + i);
			for (int j = 0; j < k; j++)
			{

				cout << Banner[i][j];
			}
		}
		Sleep(25);
	}

	
	system("color 10");
	Sleep(25);
	system("color 01");
	Sleep(25);
	system("color 10");
	Sleep(25);
	system("color 01");
	Sleep(25);
	system("color 10");
	Sleep(25);
	system("color 01");
	Sleep(25);
	setCursorPosition(27, 25);
	Report("Press Any Key to Login...", 0);
	system("pause > nul");
	

}


void Report(string report, bool newLine = true)
{
	ShowConsoleCursor(true);
	if (newLine)
	{
		cout << endl << time(NULL) << ": ";
	}

	for (int i = 0; i < report.length(); i++)
	{
		cout << report[i];
		Sleep(typeTime);
	}

	Sleep(waitTime);
}

void Login()
{
	cout << endl;
	string loading = "-\|/- ";
	SetConsoleTextAttribute(hConsole, 2);
	Report("-*H.E.R.O.S. SHIP COMPUTER SYSTEM -- NSS OPPOSITION NS1473-- MAIN BATTLE GROUP*-", 0);
	cout << endl;
	Report("SYSTEM ACCESS REQUESTED............", 1);


	Report("ACCESS KEY REQUIRED: ", 1);



	for (int i = 0; i < 10; i++)
	{


		cout << "*";
		Sleep((rand() % 400 + 1) * 2);

	}

	cout << endl;

	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "\b";
			cout << loading[i];
			Sleep(200);

		}
	}

	system("Color 20");
	system("Color 02");
	system("Color 20");
	system("Color 02");

	system("cls");
	Report("KEY VERIFIED");

	cout << endl;

	Report("INITIALIZING CONNECTION");

	for (int i = 0; i < 15; i++)
	{
		Sleep(100);
		cout << ".";
	}
	for (int i = 0; i < 15; i++)
	{
		Sleep(50);
		cout << ".";
	}


	for (int i = 0; i < 1000; i++)
	{
		cout << endl;

		for (int i = 0; i < 75; i++)
		{

			cout << rand() % 2;


		}
	}

	system("cls");
	for (int i = 0; i < 3; i++)
	{
		Sleep(150);
		cout << "*SYSTEM ACCESS GRANTED*";
		Sleep(150);
		system("cls");
	}

}

void Communication()
{
	system("Color 09");
	Report("-*H.E.R.O.S. COMMUNICATION NETWORK*-", 0);

	cout << endl;

	Report("INCOMING COMMUNICATION FROM COMMAND.......");

	cout << endl;	
	Report("This is Commander Nemlock.");

	Report("The ship has been infiltrated by a hostile alien race, designation: Trolls...Again...");
	Report("They are not pleased with your performance as 'The New King.'");
	Report("They demand you come to the Bridge and face the Usurper.");
	Report("Find a decent weapon, EQUIP it and make your way to the Bridge, but be carefull, the ship has taken damage and there may be some rogue trolls roaming around.");
	Report("The following are what you can do on this mission:");
	cout << endl;
	cout << "LOOK - look around your environment." << endl;
	cout << "GET - get a target item to put into your inventory." << endl;
	cout << "DROP - remove target from inventory and leave on the floor." << endl;
	cout << "USE - use target item." << endl;
	cout << "EXAMINE - take a closer look at target item." << endl;
	cout << "OPEN - open target." << endl;
	cout << "CLOSE - close target." << endl;
	//cout << "NAVIGATE - open Cartography.app." << endl;
	cout << "INVENTORY - open Inventory.app" << endl;
	cout << "THINK - think of things that you can do (you're doing it now)." << endl;
	cout << "FIGHT - fight target." << endl;
	cout << "COMBINE - combine two things into one." << endl;
	cout << "EQUIP- equip target item." << endl;
	cout << "EQUIPPED - see what you have equipped" << endl;
	//cout << "UNEQUIP - unequip currently equipped item.";
	cout << "NORTH - go North." << endl;
	cout << "EAST - go East." << endl;
	cout << "SOUTH - go South." << endl;
	cout << "WEST - go West." << endl;
	Report("PRESS ANY KEY TO START ADVENTURE.EXE");
	system("pause > nul");
}

void Adventure()
{
	system("cls");
	system("color 02");
	Report("LOADING H.E.R.O.S. ADVENTURE.EXE", 0);
	for (int i = 0; i < 15; i++)
	{
		Sleep(25);
		cout << ".";
	}

	system("cls");
	for (int i = 0; i < 3; i++)
	{
		Sleep(100);
		cout << "*H.E.R.O.S. ADVENTURE LOADED SUCCESSFULLY*";
		Sleep(100);
		system("cls");
	}
	system("cls");
	system("color 17");
	Report("-*H.E.R.O.S. ADVENTURE.EXE*-", 0);
	
	cout << endl;
}

void Inventory()
{
	system("cls");
	system("color 02");
	Report("LOADING H.E.R.O.S. INVENTORY.EXE", 0);	
	for (int i = 0; i < 15; i++)
	{
		Sleep(25);
		cout << ".";
	}

	system("cls");
	for (int i = 0; i < 3; i++)
	{
		Sleep(100);
		cout << "*H.E.R.O.S. INVENTORY LOADED SUCCESSFULLY*";
		Sleep(100);
		system("cls");
	}
	system("cls");
	system("color 06");
	Report("-*H.E.R.O.S. INVENTORY*-", 0);
	cout << endl;
	Report("INVENTORY CONTENTS:", 1);
	cout << endl;
	
}

void Equipment()
{
	system("cls");
	system("color 02");
	Report("LOADING H.E.R.O.S. EQUIPMENT MANAGER.EXE", 0);
	for (int i = 0; i < 15; i++)
	{
		Sleep(25);
		cout << ".";
	}

	system("cls");
	for (int i = 0; i < 3; i++)
	{
		Sleep(100);
		cout << "*H.E.R.O.S. EQUIPMENT MANAGER LOADED SUCCESSFULLY*";
		Sleep(100);
		system("cls");
	}
	system("cls");
	system("color 0E");
	Report("-*H.E.R.O.S. EQUIPMENT MANAGER*-", 0);
	cout << endl;
	Report("EQUIPMENT:", 1);
	cout << endl;
	
}
void set_rooms(vector<Room>* vector) //Builds a vector of Room objects
{
	Room Bridge("the Bridge", NONE, NONE, CORM4, NONE);
	Room CaptainQuarters("the Captain's quarters", NONE, CORM4, NONE, NONE);
	Room CorridorM4("Corridor M4", NONE, COMMANDER_QUARTERS, CORM3, CAPTAIN_QUARTERS);
	Room CommanderQuarters("the Commander's quarters", NONE, NONE, NONE, CORM4);
	Room Armory("the Armory", NONE, NONE, CORL3, NONE);
	Room MedBay("the Medical Bay", NONE, CORM3, NONE, NONE);
	Room CorridorM3("Morridor M3", CORM4, MY_QUARTERS, CORM2, MED_BAY);
	Room MyQuarters("my quarters", NONE, NONE, NONE, CORM3);
	Room MessHall("the Mess Hall", NONE, NONE, CORR3, NONE);
	Room Hangar1("Hangar 1", NONE, NONE, NONE, NONE);
	Room ShuttleBay1("Shuttle Bay 1", NONE, CORL3, NONE, NONE);
	Room CorridorL3("Corridor L3", ARMORY, CB1, CORL2, SHUTTLE_BAY1);
	Room CargoBay1("Cargo Bay 1", NONE, CORM2, CB1_BATHROOM, CORL3);
	Room CorridorM2("Corridor M2", CORM3, CB2, CORM1, CB1);
	Room CargoBay2("Cargo Bay 2", NONE, CORR3, CB2_BATHROOM, CORM2);
	Room CorridorR3("Corridor R3", MESS_HALL, SHUTTLE_BAY2, CORR2, CB2);
	Room ShuttleBay2("Shuttle Bay 2", NONE, HANGAR2, NONE, CORR3);
	Room Hangar2("Hangar 2", NONE, NONE, NONE, SHUTTLE_BAY2);
	Room CorridorL2("Corridor L2", CORL3, NONE, CORL1, NONE);
	Room CargoBayBathroom1("the Cargo Bay 1 bathroom", CB1, NONE, NONE, NONE);
	Room CorridorM1("Corridor M1", CORM2, NONE, CORM0, NONE);
	Room CargoBayBathroom2("the Cargo Bay 2 bathroom", CB2, NONE, NONE, NONE);
	Room CorridorR2("Corridor R2", CORR3, NONE, CORR1, NONE);
	Room CorridorL1("Corridor L1", CORL1, CORL0, NONE, NONE);
	Room CorridorL0("Corridor L0", NONE, CORM0, NONE, CORL1);
	Room CorridorM0("Corridor M0", CORM1, CORR0, ENGINEERING, CORL0);
	Room CorridorR0("Corridor R0", NONE, CORR1, NONE, CORM0);
	Room CorridorR1("Corridor R1", CORR2, NONE, NONE, CORR0);
	Room EngStorage("the Engineering storage room", NONE, ENGINEERING, NONE, NONE);
	Room Engineering("Engineering", CORM0, NONE, ENGINE_CORE, NONE);
	Room TransporterRoom("the transporter room", NONE, NONE, NONE, NONE);
	Room EngineCore("the engine core", ENGINEERING, NONE, NONE, NONE);
	Room Inventory("the magical pocket dimension", NONE, NONE, NONE, NONE);
	Room Equip("the slot of using", NONE, NONE, NONE, NONE);
	//Room Destroyed("the dark abbys", NONE, NONE, NONE, NONE);

	vector->insert(vector->end(), { Bridge, CaptainQuarters, CorridorM4, CommanderQuarters, Armory, MedBay, CorridorM3, MyQuarters, MessHall, Hangar1, ShuttleBay1, CorridorL3, CargoBay1,CorridorM2,CargoBay2,
		CorridorR3, ShuttleBay2, Hangar2, CorridorL2, CargoBayBathroom1, CorridorM1, CargoBayBathroom2, CorridorR2, CorridorL1,
		CorridorL0, CorridorM0,CorridorR0, CorridorR1, EngStorage, Engineering, TransporterRoom, EngineCore , Inventory, Equip });
}

void set_directions(vector<Words>* vector)
{
	Words North("NORTH", NORTH);
	Words East("EAST", EAST);
	Words South("SOUTH", SOUTH);
	Words West("WEST", WEST);

	vector->insert(vector->end(), { North, East, South, West });
}

void set_verbs(vector<Words>* vector)
{
	Words Get("GET", GET);
	Words Drop("DROP", DROP);
	Words Use("USE", USE);
	Words Open("OPEN", OPEN);
	Words Close("CLOSE", CLOSE);
	Words Examine("EXAMINE", EXAMINE);
	Words Inventory("INVENTORY", INVENTORY);
	Words Look("LOOK", LOOK);
	Words Navigate("NAVIGATE", NAVIGATE);
	Words Think("THINK", THINK);
	Words Fight("FIGHT", FIGHT);
	Words Combine("COMBINE", COMBINE);
	Words Equip("EQUIP", EQUIP);
	Words Equipped("EQUIPPED", EQUIPPED);
	Words Cheat("CHEAT", CHEAT);
	//Words Unequip("UNEQUIP", UNEQUIP);

	vector->insert(vector->end(), { Get, Drop, Use, Open, Close, Examine, Inventory, Look, Navigate, Think, Fight, Combine, Equip, Equipped, Cheat });
}

void set_nouns(vector<Noun>* vector)
{
	Noun StoreDoor("DOOR", "a closed store room door", STORE_DOOR, ENG_STORAGE, false, "it's a sturdy door.");
	Noun Magnet("MAGNET", "a magnet", MAGNET, RandLocation(), true, "it's a horseshoe magnet with painted North and South indicators.");
	Noun Meter("METER", "a parking meter", METER, HANGAR1, false, "the time has run out, maybe we should have he spaceship towed!");
	Noun Roulette("ROULETTE", "a roulette wheel", ROULETTE, MESS_HALL, false, "it's the reason I have no credits saved up.");
	Noun Money("MONEY", "some money", MONEY, COMMANDER_QUARTERS, true, "tree fiddy!", true);
	Noun FishRod("ROD", "a fishing rod", FISHROD, ARMORY, true, "it's just a fishing rod.", true);
	Noun Hangar1Keycard("KEYCARD", "a keycard labeled 'Hangar 1'", HANGAR1_KEYCARD, RandLocation(), true, "this can be used to unlock Hangar 1!");
	Noun CommanderTable("PAD", "the Commander's personal data pad", COMMANDER_TABLET, COMMANDER_QUARTERS, true, "the code 7319");
	Noun Plunger("PLUNGER", "my precious plunger", PLUNGER, CB1_BATHROOM, true, "the only thing in my life worth living for", true);
	Noun CaptainID("ID", "the captain's ID", CAPTAIN_ID, CAPTAIN_QUARTERS, true);
	Noun TrollDoll("DOLL", "a troll doll", TROLL_DOLL, RandLocation(), true, "a naked troll doll with spikey lime green hair", true);
	Noun EmptyGun("GUN", "an unloaded gun", EMPTY_GUN, RandLocation(), true, "a 9mm relic, it needs ammo");
	Noun Bullets("BULLETS", "a box of bullets", BULLETS, RandLocation(), true, "9mm hollowpoints.");
	Noun LoadedGun("LOADEDGUN", "a loaded Gun", LOADED_GUN, NONE, true, "a problem solver.", true);
	Noun Shuttle1("SHUTTLE1", "shuttle1", SHUTTLE1, SHUTTLE_BAY1, false);
	Noun Shuttle2("SHUTTLE2", "shuttle2", SHUTTLE2, SHUTTLE_BAY2, false);
	Noun AlienShip("SPACECRAFT", "an alien spacecraft", ALIENSHIP1, HANGAR1, false);
	Noun Cargobox1("BOX1", "a cargo box labeled 'Box1'", CARGOBOX1, CB1, false, "ineffecteve masks inside.");
	Noun Cargobox2("BOX2", "a cargo box labeled 'Box2'", CARGOBOX2, CB1, false, "nothing of interest inside.");
	Noun Cargobox3("BOX3", "a cargo box labeled 'Box3'", CARGOBOX3, CB1, false, "some dirty laundry inside.");
	Noun Cargobox4("BOX4", "a cargo box labeled 'Box4'", CARGOBOX4, CB2, false, "nothing of interest inside.");
	Noun Cargobox5("BOX5", "a cargo box labeled 'Box5'", CARGOBOX5, CB2, false, "rotten food inside.");
	Noun Cargobox6("BOX6", "a cargo box labeled 'Box6'", CARGOBOX6, CB2, false, "nothing of interest inside.");
	Noun Fork("FORK", "a fork", FORK, MESS_HALL, true, "", true);
	Noun Spoon("SPOON", "a spoon", SPOON, MESS_HALL, true, "", true);
	Noun Batteries("BATTERIES", "a few batteries", BATTERIES, RandLocation(), true);
	Noun DeadLasergun("LASERGUN", "a depleated alien lasergun", DEAD_LASERGUN, true);
	Noun Lasergun("POWEREDLASERGUN", "an alien lasergun", LASERGUN, NONE, true, "the setting is on 'kill", true);
	Noun BridgeDoor("BRIDGEDOOR", "a door labeled \"BRIDGEDOOR\"", BRIDGE_DOOR, CORM4, false, "it's locked and the keypad is broken");
	Noun Hangar1Door("HANGAR1DOOR", "a door labeled \"HANGAR1DOOR\"", HANGAR1_DOOR, SHUTTLE_BAY1, false, "it's locked");
	Noun Keypad("KEYPAD", "the Transporter Room Keypad", KEYPAD, ENGINEERING, false);
	Noun BrokenDoor("BROKENDOOR", "the Transporter Room Door", BROKENDOOR, TRANSPORTER_ROOM, false, "the door is jammed, there must be another way in...");
	Noun TransporterDoor("TRANSPORTERDOOR", "a door labeled \"TRANSPORTERDOOR\"", TRANSPORTERDOOR, ENGINEERING, false, "it's locked, there is a keypad next to the door, there must be a code...");
	Noun Transporter("TRANSPORTER", "the ship transporter", TRANSPORTER, TRANSPORTER_ROOM, false, "this device can teleport me anywhere on the ship.");

	vector->insert(vector->end(), { StoreDoor, Magnet, Meter, Roulette, Money, FishRod, Hangar1Keycard,CommanderTable,Plunger,CaptainID,TrollDoll,EmptyGun,Bullets,LoadedGun,
		Shuttle1,Shuttle2,AlienShip,Cargobox1,Cargobox2, Cargobox3, Cargobox4, Cargobox5, Cargobox6, Fork, Spoon, Batteries, DeadLasergun, Lasergun, BridgeDoor, Hangar1Door, Keypad, BrokenDoor, TransporterDoor, Transporter });
}

int RandLocation()
{
	return (rand() % (ROOMS - 2) + 1);
}
void section_command(string Cmd, string& wd1, string& wd2)
{
	string sub_str;
	vector<string> words;
	char search = ' ';
	short int i, j;

	for (i = 0; i < Cmd.size(); i++)
	{
		if (Cmd.at(i) != search)
		{
			sub_str.insert(sub_str.end(), Cmd.at(i));
		}
		if (i == Cmd.size() - 1)
		{
			words.push_back(sub_str);
			sub_str.clear();
		}
		if (Cmd.at(i) == search)
		{
			words.push_back(sub_str);
			sub_str.clear();
		}
	}
	for (i = words.size() - 1; i > 0; i--)
	{
		if (words.at(i) == "")
		{
			words.erase(words.begin() + i);
		}
	}
	for (i = 0; i < words.size(); i++)
	{
		for (j = 0; j < words.at(i).size(); j++)
		{
			if (islower(words.at(i).at(j)))
			{
				words.at(i).at(j) = toupper(words.at(i).at(j));
			}
		}
	}

	if (words.size() == 0)
	{
		cout << "No command given" << endl;
	}
	if (words.size() == 1)
	{
		wd1 = words.at(0);
	}
	if (words.size() == 2)
	{
		wd1 = words.at(0);
		wd2 = words.at(1);
	}
	if (words.size() > 2)
	{
		cout << "Command too long.  Only type one or two words (direction or verb and noun)" << endl;
	}
}

void look_around(vector<Room>& roomvector, int loc, Room& rms, vector<Words>* dir, vector<Noun>* nns)
{
	vector<Room>::iterator changeRoomIter = roomvector.begin();
	vector<Words>::iterator changeWordIter = dir->begin();
	vector<Noun>::iterator changeNounIter = nns->begin();
	int i;
	cout << "I am in " << rms.GetDescription() << "." << endl;
	cout << endl;
	for (i = 0; i < DIRS; i++)
	{
		if (rms.GetExit(i) != NONE)
		{
			Report("There is an exit ");
			Report(changeWordIter[i].GetWord(), 0);
			Report(" to ", 0);
			Report(changeRoomIter[rms.GetExit(i)].GetDescription(), 0);
			Report(".", 0);
			
			//cout << "There is an exit " << changeWordIter[i].GetWord() << " to " << changeRoomIter[rms.GetExit(i)].GetDescription() << "." << endl;
		}
	}
	cout << endl;
	//The look command should check which objects (nouns) are in the current room and report them to the player.
	for (i = 0; i < NOUNS; i++)
	{
		if (changeNounIter[i].GetLocation() == loc)
		{
			Report("I see ");
			Report(changeNounIter[i].GetDescription(), 0);
			Report(".", 0);
			
			//cout << "I see " << changeNounIter[i].GetDescription() << "." << endl;
		}
	}
}

bool parser(int& loc, vector<Room>& roomvector, Room& rms, string wd1, string wd2, vector<Words>& dir, vector<Words>* vbs, vector<Noun>* nns)
{
	static bool doorIsOpen = false; //false is closed door.
	static bool hangarDoorIsOpen = false; //false is closed door.
	static bool transporterDoorIsOpen = false; //false is closed door.
	vector<Room>::iterator changeRoomIter = roomvector.begin();
	vector<Words>::iterator changeVerbIter = vbs->begin();
	vector<Noun>::iterator changeNounIter = nns->begin();

	int i;
	for (i = 0; i < DIRS; i++)
	{
		if (wd1 == dir[i].GetWord())
		{
			if (rms.GetExit(dir[i].GetCode()) != NONE)
			{
				loc = rms.GetExit(dir[i].GetCode());
				Room NewHere = Index(&roomvector, loc);
				system("cls");
				Report("I am now in ");
				Report(NewHere.GetDescription(), 0);
				Report(".", 0);
				cout << endl;
				//cout << "I am now in " << NewHere.GetDescription() << "." << endl;
				//A special case for the corridor storeroom door.
				if (loc == ENG_STORAGE || loc == ENGINEERING)
				{
					changeNounIter[STORE_DOOR].SetLocation(loc);
				}
				if (loc == ENGINEERING || loc == TRANSPORTER_ROOM)
				{
					changeNounIter[TRANSPORTERDOOR].SetLocation(loc);
				}
				if (loc == HANGAR1 || loc == SHUTTLE_BAY1)
				{
					changeNounIter[HANGAR1_DOOR].SetLocation(loc);
				}
				return true;
			}
			else
			{
				Report("No exit that way.");
				cout << endl;
				//cout << "No exit that way." << endl;
				return true;
			}
		}
	}

	int VERB_ACTION = NONE;
	int NOUN_MATCH = NONE;

	for (i = 0; i < VERBS; i++)
	{

		if (wd1 == changeVerbIter[i].GetWord())
		{
			VERB_ACTION = changeVerbIter[i].GetCode();
			break;
		}
	}

	if (wd2 != "")
	{
		for (i = 0; i < NOUNS; i++)
		{

			if (wd2 == changeNounIter[i].GetWord())
			{
				NOUN_MATCH = changeNounIter[i].GetCode();
				break;
			}
		}
	}
	if (VERB_ACTION == NONE)
	{
		Report("No valid command entered.");
		cout << endl;
		//cout << "No valid command entered." << endl;
		return true;
	}
	if (VERB_ACTION == CHEAT)
	{
		for (i = 0; i < NOUNS; i++)
		{
			int cheatloc;
			cheatloc = changeNounIter[i].GetLocation();
			Report(changeNounIter[i].GetDescription());
			cout << endl << cheatloc;
		}
	}
	if (VERB_ACTION == GET)
	{
		if (NOUN_MATCH != NONE)
		{

			if (loc == changeNounIter[NOUN_MATCH].GetLocation())
			{
				if (changeNounIter[NOUN_MATCH].GetCan_Carry())
				{
					changeNounIter[NOUN_MATCH].SetLocation(CURINVENTORY);
					Report("Picked up ");
					Report(wd2, 0);
					Report("!", 0);
					cout << endl;
					//cout << "Picked up " << wd2 << "!" << endl;
				}
				else
				{
					Report("I cannot carry that!");
					cout << endl;
					//cout << "I cannot carry that!" << endl;
				}
			}
			else
			{
				Report("I don't see that item!");
				cout << endl;
				//cout << "I don't see that item!" << endl;
			}
		}
		else
		{
			Report("I don't see that item!");
			cout << endl;
			//cout << "I don't see that item!" << endl;
		}
	}
	if (VERB_ACTION == DROP)
	{
		if (CURINVENTORY == changeNounIter[NOUN_MATCH].GetLocation())
		{
			changeNounIter[NOUN_MATCH].SetLocation(loc);
			Report(wd2);
			Report(" dropped!", 0);
			cout << endl;
			//cout << wd2 << " dropped!" << endl;
		}
		else
		{
			Report("You don't have ");
			cout << endl;
			//cout << "You don't have " << wd2 << endl;
		}
	}
	if (VERB_ACTION == INVENTORY)
	{
		Inventory();		
		for (i = 0; i < NOUNS; i++)
		{
			int current = changeNounIter[i].GetLocation();
			if (CURINVENTORY == changeNounIter[i].GetLocation())
			{
				//cout << NOUN_NAMES[i] << " : " << changeNounIter[i].GetDescription() << endl;
				Report(NOUN_NAMES[i]);
				Report(" : ", 0);
				Report(changeNounIter[i].GetDescription(), 0);
				cout << endl;
			}
			
			
		}
		Report("PRESS ANY KEY TO CONTINUE ADVENTURE.EXE");
		system("pause > nul");
		Adventure();
	}
	if (VERB_ACTION == EQUIPPED)
	{
		Equipment();
		for (i = 0; i < NOUNS; i++)
		{

			if (EQUIPMENT == changeNounIter[i].GetLocation())
			{
				//cout << NOUN_NAMES[i] << " : " << changeNounIter[i].GetDescription() << endl;
				Report(NOUN_NAMES[i]);
				Report(" : ", 0);
				Report(changeNounIter[i].GetDescription(), 0);
				cout << endl;
			}
			
		}
		Report("PRESS ANY KEY TO CONTINUE ADVENTURE.EXE");
		system("pause > nul");
		Adventure();
	}

	if (VERB_ACTION == EXAMINE)
	{
		if (loc == changeNounIter[NOUN_MATCH].GetLocation() || CURINVENTORY == changeNounIter[NOUN_MATCH].GetLocation())
		{
			if (changeNounIter[NOUN_MATCH].GetExamine() != "")
			{
				Report("You look close at ");
				Report(wd2, 0);
				Report(" and notice... ", 0);
				Report(changeNounIter[NOUN_MATCH].GetExamine(), 0);
				cout << endl;
				//cout << "You look close at " << wd2 << " and notice... " << changeNounIter[NOUN_MATCH].GetExamine() << endl;
			}
			else
			{
				Report("You look close at ");
				Report(wd2, 0);
				Report(" and notice... ", 0);
				Report(changeNounIter[NOUN_MATCH].GetDescription(), 0);
				cout << endl;
				//cout << "You look close at " << wd2 << " and notice... " << changeNounIter[NOUN_MATCH].GetDescription() << endl;
			}

		}
		else
		{
			Report("I don't see that item!");
			cout << endl;
			//cout << "I don't see that item!" << endl;
		}
	}

	
	//if (VERB_ACTION == NAVIGATE)
	//{
	//	cout << wd1 << " is in development" << endl;
	//}
	if (VERB_ACTION == THINK)
	{
		cout << "LOOK - look around your environment." << endl;
		cout << "GET - get a target item to put into your inventory." << endl;
		cout << "DROP - remove target from inventory and leave on the floor." << endl;
		cout << "USE - use target item." << endl;
		cout << "EXAMINE - take a closer look at target item." << endl;
		cout << "OPEN - open target." << endl;
		cout << "CLOSE - close target." << endl;
		//cout << "NAVIGATE - open Cartography.app." << endl;
		cout << "INVENTORY - open Inventory.app" << endl;
		cout << "THINK - think of things that you can do (you're doing it now)." << endl;
		cout << "FIGHT - fight target." << endl;
		cout << "COMBINE - combine two things into one." << endl;
		cout << "EQUIP- equip target item." << endl;
		cout << "EQUIPPED - see what you have equipped" << endl;
		//cout << "UNEQUIP - unequip currently equipped item.";
		cout << "NORTH - go North." << endl;
		cout << "EAST - go East." << endl;
		cout << "SOUTH - go South." << endl;
		cout << "WEST - go West." << endl;

	}
	if (VERB_ACTION == FIGHT)
	{

		Report("You apprach the Usuper, with the most confidence you have ever mustered.");
		if (EQUIPMENT == changeNounIter[PLUNGER].GetLocation())
		{
			Report("You present your precious PLUNGER");
			Report("The Usurper doesn't react.");
			Report("Couldn't get lucky with that twice");
			Sleep(5000);
		}
		if (EQUIPMENT == changeNounIter[FISHROD].GetLocation())
		{
			Report("You pull out the FISHROD");
			Report("You cast at the Usurper's smug face.");
			Report("It has little effect.");
			Sleep(5000);
		}
		if (EQUIPMENT == changeNounIter[TROLL_DOLL].GetLocation())
		{
			Report("You pull out the TROLL_DOLL");
			Report("The Usurper looks to 'excited' so you quickly put it away.");
			Sleep(5000);
		}
		if (EQUIPMENT == changeNounIter[SPOON].GetLocation())
		{
			Report("You pull out the SPOON");
			Report("You throw it at the Usurper.");
			Report("It bounces off.");
			Sleep(5000);
		}
		if (EQUIPMENT == changeNounIter[MONEY].GetLocation())
		{
			Report("You pull out the Commander's MONEY");
			Report("You offer it to the Usurper.");
			Report("It doesn't appear he takes bribes.");
			Sleep(5000);
		}
		if (EQUIPMENT == changeNounIter[FORK].GetLocation())
		{
			Report("You pull out the FORK");
			Report("You throw it at the Usurper.");
			Report("It sticks in his eye and he cries out in pain!");
			Sleep(5000);
			win = true;
		}
		if (EQUIPMENT == changeNounIter[LOADED_GUN].GetLocation())
		{
			Report("You pull out the LOADEDGUN");
			Report("You point it at the Usurper.");
			Report("You fire and the Usurper falls down in a heap.");
			Sleep(5000);
			win = true;
		}
		if (EQUIPMENT == changeNounIter[LASERGUN].GetLocation())
		{
			Report("You pull out the LASERGUN");
			Report("You point it at the Usurper.");
			Report("The Userper vaporizes.");
			Sleep(5000);
			win = true;
		}
		
		if (win)
		{
			Report("You have once again saved the day!!!");
			Report("You remain the Troll King");

		}
		else
		{
			Report("You have failed, and will always be a failure, it's not like you could just 'Play Again'");
			win = true;
		}
	}
	if (VERB_ACTION == COMBINE)
	{
		if (NOUN_MATCH != NONE)
		{
			if (CURINVENTORY == changeNounIter[NOUN_MATCH].GetLocation() && (NOUN_MATCH == EMPTY_GUN || NOUN_MATCH == BULLETS || NOUN_MATCH == DEAD_LASERGUN || NOUN_MATCH == BATTERIES))
			{
				string wd3;
				int NOUN_MATCH2;
				Report("What would you like to combine ");
				Report(wd2, 0);
				Report(" with?", 0);
				cout << endl;
				cin >> wd3;
				transform(wd3.begin(), wd3.end(), wd3.begin(), toupper);

				if (wd3 != "")
				{
					for (i = 0; i < NOUNS; i++)
					{

						if (wd3 == changeNounIter[i].GetWord())
						{
							NOUN_MATCH2 = changeNounIter[i].GetCode();
							break;
						}
					}
				}

				if ((NOUN_MATCH == EMPTY_GUN && NOUN_MATCH2 == BULLETS) || (NOUN_MATCH == BULLETS && NOUN_MATCH2 == EMPTY_GUN))
				{
					changeNounIter[NOUN_MATCH].SetLocation(NONE);
					changeNounIter[NOUN_MATCH2].SetLocation(NONE);
					changeNounIter[LOADED_GUN].SetLocation(CURINVENTORY);
					Report("LOADEDGUN added to INVENTORY!");
					cout << endl;
				}
				else if ((NOUN_MATCH == DEAD_LASERGUN && NOUN_MATCH2 == BATTERIES) || (NOUN_MATCH == BATTERIES && NOUN_MATCH2 == DEAD_LASERGUN))
				{
					changeNounIter[NOUN_MATCH].SetLocation(NONE);
					changeNounIter[NOUN_MATCH2].SetLocation(NONE);
					changeNounIter[LASERGUN].SetLocation(CURINVENTORY);
					Report("POWEREDLASERGUN added to INVENTORY!");
					cout << endl;
				}
				else
				{
					Report("Those items do not combine with each other!");
					cout << endl;
				}
			}
			else

			{
				Report("I cannot COMBINE that with anything!");
				cout << endl;
			}
		}
		else
		{
			Report("I don't know what that is!");
			cout << endl;
		}
	}
	if (VERB_ACTION == EQUIP)
	{

		if (changeNounIter[NOUN_MATCH].GetCan_Equip())
		{
			if (CURINVENTORY == changeNounIter[NOUN_MATCH].GetLocation())
			{
				changeNounIter[NOUN_MATCH].SetLocation(EQUIPMENT);
				Report(wd2);
				Report(" equipped!", 0);
				cout << endl;
				//cout << wd2 << " dropped!" << endl;
			}
			else
			{
				Report("You don't have ");
				cout << endl;
				//cout << "You don't have " << wd2 << endl;
			}
		}
		else
		{
			Report("I cannot carry that!");
			cout << endl;
		}


	}

	if (VERB_ACTION == LOOK)
	{
		look_around(roomvector, loc, rms, &dir, nns);
		return true;
	}

	//Actions for usage of VERB OPEN
	if (VERB_ACTION == CLOSE)
	{
		if (NOUN_MATCH == STORE_DOOR)
		{
			if (loc == ENGINEERING || loc == ENG_STORAGE)
			{
				if (doorIsOpen == true)
				{
					doorIsOpen = false;
					changeRoomIter[ENGINEERING].SetExit(WEST, NONE);
					changeRoomIter[ENG_STORAGE].SetExit(EAST, NONE);
					changeNounIter[STORE_DOOR].SetDescription("a closed store room door");

					Report("I have closed the door.");
					cout << endl;
					//cout << "I have closed the door." << endl;
					return true;
				}
				else if (doorIsOpen == true)
				{
					Report("The door is already closed.");
					cout << endl;
					//cout << "The door is already closed." << endl;
					return true;
				}
			}
			else
			{
				Report("There is no door to close here.");
				cout << endl;
				//cout << "There is no door to close here." << endl;
				return true;
			}
		}
		else if (NOUN_MATCH == HANGAR1_DOOR)
		{
			if (loc == SHUTTLE_BAY1)
			{
				if (hangarDoorIsOpen == true)
				{
					if (CURINVENTORY == changeNounIter[HANGAR1_KEYCARD].GetLocation())
					{


						hangarDoorIsOpen = false;
						changeRoomIter[SHUTTLE_BAY1].SetExit(WEST, NONE);
						changeRoomIter[HANGAR1].SetExit(EAST, NONE);
						changeNounIter[HANGAR1_DOOR].SetDescription("a closed door to Hangar 1");

						Report("I have closed the door.");
						cout << endl;
						//cout << "I have closed the door." << endl;
						return true;
					}
					else
					{
						Report("I don't have a way to close the door.");
						cout << endl;
						//cout << "I don't have a way to close the door." << endl;
					}
				}
				else if (hangarDoorIsOpen == true)
				{
					Report("The door is already closed.");
					cout << endl;
					//cout << "The door is already closed." << endl;
					return true;
				}
			}
			else
			{
				Report("There is no door to close here.");
				cout << endl;
				//cout << "There is no door to close here." << endl;
				return true;
			}
		}
		else if (NOUN_MATCH == TRANSPORTERDOOR)
		{
			if (loc == ENGINEERING)
			{
				if (transporterDoorIsOpen == true)
				{
					if (CURINVENTORY == changeNounIter[COMMANDER_TABLET].GetLocation())
					{
						transporterDoorIsOpen = false;
						changeRoomIter[ENGINEERING].SetExit(EAST, NONE);
						changeRoomIter[TRANSPORTER_ROOM].SetExit(WEST, NONE);
						changeNounIter[TRANSPORTERDOOR].SetDescription("a closed door to the Transport Room");

						Report("I have closed the door.");
						cout << endl;
						//cout << "I have closed the door." << endl;
						return true;
					}
					else
					{
						Report("I don't have a way to close the door.");
						cout << endl;
						//cout << "I don't have a way to close the door." << endl;
					}
				}
				else if (transporterDoorIsOpen == true)
				{
					Report("The door is already closed.");
					cout << endl;
					//cout << "The door is already closed." << endl;
					return true;
				}
			}
			else
			{
				Report("There is no door to close here.");
				cout << endl;
				//cout << "There is no door to close here." << endl;
				return true;
			}
		}
		else
		{
			Report("Closing that is not possible!");
			cout << endl;
			//cout << "Closing that is not possible" << endl;
			return true;
		}
	}

	if (VERB_ACTION == USE)
	{
		if (NOUN_MATCH == TRANSPORTER)
		{
			if (loc == TRANSPORTER_ROOM)
			{
				if (CURINVENTORY == changeNounIter[MAGNET].GetLocation())
				{
					loc = Transporter(&roomvector);
					Room NewHere = Index(&roomvector, loc);
					system("cls");
					Report("I am now in ");
					Report(NewHere.GetDescription(), 0);
					Report(".", 0);
					//cout << "I am now in " << NewHere.GetDescription() << "." << endl;
					//A special case for the corridor storeroom door.
					if (loc == ENG_STORAGE || loc == ENGINEERING)
					{
						changeNounIter[STORE_DOOR].SetLocation(loc);
					}
					if (loc == ENGINEERING || loc == TRANSPORTER_ROOM)
					{
						changeNounIter[TRANSPORTERDOOR].SetLocation(loc);
					}
					if (loc == HANGAR1 || loc == SHUTTLE_BAY1)
					{
						changeNounIter[HANGAR1_DOOR].SetLocation(loc);
					}
					return true;
				}
				else
				{
					Report("It doesn't seem to work, the screen just says MAGNETIC IMBALANCE ERROR.");
					cout << endl;
					//cout << "It doesn't seem to work, the screen just says MAGNETIC IMBALANCE ERROR." << endl;
				}
			}
			else
			{
				Report("I don't see that here!");
				cout << endl;
				//cout << "I don't see that here" << endl;
			}
		}
		else if (NOUN_MATCH == ROULETTE)
		{
			if (loc == MESS_HALL)
			{
				Report("You spin the wheel and... lose like always.");
				cout << endl;
				//cout << "You spin the wheel and... lose like always." << endl;
			}
			else
			{
				Report("I don't see that here!");
				cout << endl;
				//cout << "I don't see that here" << endl;
			}
		}
		else if (NOUN_MATCH == SHUTTLE1)
		{
			if (loc == SHUTTLE_BAY1)
			{
				Report("I don't have any keys!");
				cout << endl;
				//cout << "I don't have the keys" << endl;
			}
			else
			{
				Report("I don't see that here!");
				cout << endl;
				//cout << "I don't see that here" << endl;
			}
		}
		else if (NOUN_MATCH == SHUTTLE2)
		{
			if (loc == SHUTTLE_BAY2)
			{
				Report("I don't have any keys!");
				cout << endl;
				//cout << "I don't have the keys" << endl;
			}
			else
			{
				Report("I don't see that here!");
				cout << endl;
				//cout << "I don't see that here" << endl;;
			}
		}
		else if (NOUN_MATCH == ALIENSHIP1)
		{
			if (loc == HANGAR1)
			{
				Report("I don't know how to fly that!");
				cout << endl;
				//cout << "I don't know how to fly that!" << endl;
			}
			else
			{
				Report("I don't see that here!");
				cout << endl;
				//cout << "I don't see that here" << endl;
			}
		}
		else
		{
			Report("I don't know what I'm doing!");
			cout << endl;
			//cout << "I don't know what I'm doing!" << endl;
		}
	}

	if (VERB_ACTION == OPEN)
	{
		if (NOUN_MATCH == STORE_DOOR)
		{
			if (loc == ENGINEERING || loc == ENG_STORAGE)
			{
				if (doorIsOpen == false)
				{
					doorIsOpen = true;
					changeRoomIter[ENGINEERING].SetExit(WEST, ENG_STORAGE);
					changeRoomIter[ENG_STORAGE].SetExit(EAST, ENGINEERING);
					changeNounIter[STORE_DOOR].SetDescription("an open store room door");

					Report("I have opened the door!");
					cout << endl;
					//cout << "I have opened the door." << endl;
					return true;
				}
				else if (doorIsOpen == true)
				{
					Report("The door is already open!");
					cout << endl;
					//cout << "The door is already open." << endl;
					return true;
				}
			}
			else
			{
				Report("There is no door to open here.");
				cout << endl;
				//cout << "There is no door to open here." << endl;
				return true;
			}
		}
		else if (NOUN_MATCH == HANGAR1_DOOR)
		{
			if (loc == SHUTTLE_BAY1)
			{
				if (hangarDoorIsOpen == false)
				{
					if (CURINVENTORY == changeNounIter[HANGAR1_KEYCARD].GetLocation())
					{


						hangarDoorIsOpen = true;
						changeRoomIter[SHUTTLE_BAY1].SetExit(WEST, HANGAR1);
						changeRoomIter[HANGAR1].SetExit(EAST, SHUTTLE_BAY1);
						changeNounIter[HANGAR1_DOOR].SetDescription("an open door to Hangar 1");

						Report("I have opened the door!");
						cout << endl;
						//cout << "I have opened the door." << endl;
						return true;
					}
					else
					{
						Report("I don't have a way to unlock the door.");
						cout << endl;
						//cout << "I don't have a way to unlock the door." << endl;
					}
				}
				else if (hangarDoorIsOpen == true)
				{
					Report("The door is already open!");
					cout << endl;
					//cout << "The door is already open." << endl;
					return true;
				}
			}
			else
			{
				Report("There is no door to open here.");
				cout << endl;
				//cout << "There is no door to open here." << endl;
				return true;
			}
		}
		else if (NOUN_MATCH == TRANSPORTERDOOR)
		{
			if (loc == ENGINEERING)
			{
				if (transporterDoorIsOpen == false)
				{
					if (CURINVENTORY == changeNounIter[COMMANDER_TABLET].GetLocation())
					{
						transporterDoorIsOpen = true;
						changeRoomIter[ENGINEERING].SetExit(EAST, TRANSPORTER_ROOM);
						changeRoomIter[TRANSPORTER_ROOM].SetExit(WEST, ENGINEERING);
						changeNounIter[TRANSPORTERDOOR].SetDescription("an open door to the Transport Room");

						Report("I have opened the door!");
						cout << endl;
						//cout << "I have opened the door." << endl;
						return true;
					}
					else
					{
						Report("I don't have a way to unlock the door.");
						cout << endl;
						//cout << "I don't have a way to unlock the door." << endl;
					}
				}
				else if (transporterDoorIsOpen == true)
				{
					Report("The door is already open!");
					cout << endl;
					//cout << "The door is already open." << endl;
					return true;
				}
			}
			else
			{
				Report("There is no door to open here.");
				cout << endl;
				//cout << "There is no door to open here." << endl;
				return true;
			}
		}
		else
		{
			Report("Opening that is not possible");
			cout << endl;
			//cout << "Opening that is not possible" << endl;
			return true;
		}
	}
	return false;
}

ostream& operator<<(ostream& os, Room& givenRoom)
{
	os << "Room - ";
	os << "description: " << givenRoom.GetDescription();
	return os;
}

Room Index(vector<Room>* roomvector, int index)
{
	vector<Room> rooms = *roomvector;
	vector<Room>::const_iterator readRoomIter = rooms.begin();
	for (int i = 0; readRoomIter != rooms.end(); readRoomIter++, i++)
	{
		if (i == index)
		{
			return *readRoomIter;
		}
	}
}

int Transporter(vector<Room>* roomvector)
{
	vector<Room> rooms = *roomvector;
	vector<Room>::const_iterator readRoomIter = rooms.begin();
	int destination;
	for (int i = 0; readRoomIter != (rooms.end() - 2); readRoomIter++, i++)
	{
		cout << i << ". " << rooms[i].GetDescription() << endl;
	}
	Report("SELECT YOUR DESTINATION: ");
	//cout << "Select your destination: ";
	cin >> destination;
	return destination;

}

void Bridge()
{
	system("cls");
	Report("You materialize on the bridge.");
	Report("You again see the commander in a compromising situation");
	Report("The Usurper stands at the ready");
	Report("Check your inventory and equipment and FIGHT him when ready!");
}

//===================Main Function================================================================================================================================================================================================//
int main()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, NULL);
	StartScreen();
	Login();
	Communication();
	Adventure();
	
	bool firstbridge = true;
	win = false;

	srand(time(NULL)); //Seed RNG with current time
	string command; //string for user input
	string word_1;  //first word of parsed user input
	string word_2;  //second word of parsed user input

	vector<Room> rooms;
	vector<Words> directions;
	vector<Words> verbs;
	vector<Noun> nouns;

	set_rooms(&rooms);
	set_directions(&directions);
	set_verbs(&verbs);
	set_nouns(&nouns);

	int location = CB1_BATHROOM;

	while (word_1 != "QUIT" && win == false)
	{
		Room Here = Index(&rooms, location);
		command.clear();
		cout << endl;
		if (BRIDGE == location && firstbridge == true)
		{
			Bridge();
			firstbridge = false;
		}
		Report("What shall I do? ");
		cout << endl;
		getline(cin, command);
		cout << endl;
		word_1.clear();
		word_2.clear();
		section_command(command, word_1, word_2);

		if (word_1 != "QUIT")
		{
			parser(location, rooms, Here, word_1, word_2, directions, &verbs, &nouns);
		}
	}
	return 0;
}