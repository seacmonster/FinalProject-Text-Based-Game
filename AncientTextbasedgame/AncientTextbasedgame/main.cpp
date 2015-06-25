//Colin Bondy
//Text Based Game Final Project


#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "Character.h"

using namespace std;

void character_creation(); //Where you name your character and choose a class
void story(Character &Mainplayer); //Not much story but there is where the battle, challenge, and final fight functions are called
void random_encouter(Character &Mainplayer); //Generates a random encoutners between orcs, goblins, men, and trolls.
void random_challenge(Character &Mainplayer); //Random challenges that require certain stat level
void Finalfight(Character &Mainplayer); //FInal fight/ Inner struggle
int playerrollhit(Character &Mainplayer); //Generates Characters combat value based on stats
//int playerrolldamage(Character &Mainplayer); //This was for combat function but due to time constraint had to simplify combat system significantly.

int main()
{
	srand(time(NULL));	
	character_creation();
	return 0;
}

void character_creation()
{
	string firstname, lastname, character_class;
	int strength = 0, health = 0, dexterity = 0, charisma = 0, damagereduction = 0, monsterskilled = 0, challengescompleted;
	ifstream characterin;
	characterin.open("Character_save.txt"); //Opens Character save to be input into the program

	if (characterin.fail()) //Shows user if file cannot be found or opened
	{
		cout << "No Save data detected" << endl;
		cout << "Starting New game" << endl;
	}

	else
	{
		cout << "Previous save data has been detected would you like to continue?\n";
		cout << "Y or N\n";
		char answer;
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
				characterin >> firstname; //reads first name
				characterin >> lastname; //reads second name
				characterin >> character_class; //reads second name
				characterin >> strength; //reads strength
				characterin >> health; //reads health
				characterin >> dexterity; //reads dexterity
				characterin >> charisma; //reads charisma
				characterin >> damagereduction; // reads DR
				characterin >> monsterskilled; //reads counter for monsters killed
				characterin >> challengescompleted; //reads in counter for challneges
				Character Mainplayer(firstname, lastname, character_class, strength, health, dexterity, charisma, damagereduction); //Inputs stats
				Mainplayer.set_counter(monsterskilled);
				Mainplayer.set_challengescounter(challengescompleted);
				story(Mainplayer);
		}
		else
		{
			cout << endl;
		}
	}

	cout << "What is your character's first name? ";
	cin >> firstname;
	cout << "Last name? ";
	cin >> lastname;

	cout << "Which class would you like to be\n";
	cout << "Fighter: A skilled melee warrior (Strength 14, health 16, dexterity 12, charisma 8)\n";
	cout << "Rogue: A stealthy warrior (Strength 10, health 13, dexterity 16, charisma 11)\n";
	cout << "Tank: A tough melee warrior (Strength 12, health 20, dexterity 10, charisma 8)\n";
	cout << "Dabbler: A Jack of all arts (Strength 12, health 14, dexterity 12, charisma 12)\n";
	cin >> character_class;

	if (character_class == "Fighter" || character_class == "fighter")
	{
		strength = 14; health = 16; dexterity = 12; charisma = 8; damagereduction = 4;
		Character Mainplayer(firstname, lastname, character_class, strength, health, dexterity, charisma, damagereduction);
		story(Mainplayer);
		return;
	}

	if (character_class == "Rogue" || character_class == "rogue")
	{
		strength = 10; health = 13; dexterity = 16; charisma = 11; damagereduction = 2;
		Character Mainplayer(firstname, lastname, character_class, strength, health, dexterity, charisma, damagereduction);
		story(Mainplayer);
		return;
	}

	if (character_class == "Tank" || character_class == "tank")
	{
		strength = 12; health = 20; dexterity = 10; charisma = 8; damagereduction = 5;
		Character Mainplayer(firstname, lastname, character_class, strength, health, dexterity, charisma, damagereduction);
		story(Mainplayer);
		return;
	}
	
	if (character_class == "Dabbler" || character_class == "dabbler")
	{
		strength = 12; health = 14; dexterity = 12; charisma = 12; damagereduction = 3;
		Character Mainplayer(firstname, lastname, character_class, strength, health, dexterity, charisma, damagereduction);
		story(Mainplayer);
		return;
	}
	
	else
	{
		cout << "You are no fun" << endl;
		cout << "We do not accept jokers here or incorrect spellings" << endl;
		cout << "Goodbye Punk";
		exit(EXIT_SUCCESS);
	
	}


}

void story(Character &Mainplayer) //Story area
{

	if (Mainplayer.killcount() == 0 || Mainplayer.challengecount() < 3 ) //Had a lot of difficulty getting these to loop correctly because one value was wrong
	{
		if (Mainplayer.killcount() == 0)
		{
			cout << "\n\nWelcome to the impossible Combat Adventure " << Mainplayer.first_name() << " " << Mainplayer.last_name() << endl;
			cout << "You live in a wild land filled with monsters of all sorts.\nIt is your job to clean up the land.\n\n";
			cout << "Your game will automatically save after each successful fight\n";
			cout << "Press enter to conintue your adventure\n";
			cin.ignore();
			cin.get();
			cout << "You enter the plains to purge the land as your King has commanded.\n\n";
		
		}


		do{
			random_encouter(Mainplayer);

		

		} while (Mainplayer.killcount() < 6);
		
		cout << endl;
		int i = 0;
		do{
			random_encouter(Mainplayer);

			random_challenge(Mainplayer);
			
			i++;
		} while (i < 3);
	


	}

	if (Mainplayer.challengecount() > 2)
	{
		for (int i = 0; i < 3; i++)
		{
			random_encouter;
		}

		do{
			random_challenge(Mainplayer);

		} while (Mainplayer.challengecount() < 2); 
	}

	if (Mainplayer.challengecount() > 3) 
	{
		cout << "You have become a renown warrior all across the land";
		cout << "The King beseeches you to seek out Fred the Mighty Ogre";
		Finalfight(Mainplayer);
	}
}


int playerrollhit(Character &Mainplayer) //Rolls the players attack value to determine who wins
{
	Character player;
	int rollhit = (rand() % 20 + ((player.get_dexterity() % 10) / 2) + ((player.get_strength() % 10) / 2) +4); //Arbitrary +4 to make the game a little easier due to simplified combat
	return rollhit;

}
//int playerrolldamage(Character &Mainplayer)   //This was for combat function but due to time constraint had to simplify combat system significantly.
//{
//	Character player;
//	int damage = rand() & 8 + ((player.get_strength() % 10) / 2);
//	return damage;
//}

void random_encouter(Character &Mainplayer) //Random encounter function for battles
{
	//Scrapped code for more intensive combat system
	//int Goblins = 6; //Values equal fighting potential of that monster
	//int Orcs = 10;
	//int Troll = 12;
	//int deepdrawf = 9;
	//int eviladventurer = 14;


	int encounterchance = rand() % 12+1; //Rolls encoutner

	if (encounterchance >= 1 & encounterchance <= 6)
	{
		cout << "You've encountered Goblins and Fight them\n";
		if (playerrollhit(Mainplayer) > (rand() % 18 - 4))
		{
			cout << "You defeat the Goblins\n";
			Mainplayer.add_counterk();
			Mainplayer.hincrease();
			Mainplayer.save_data();
			cout << "Press Enter to continue.";
			cin.ignore();
			cin.get();
		}
		else
		{
			cout << "You are defeated" << endl;
			Mainplayer.uded();
			cout << "Press Enter to continue.";
			cin.ignore();
			cin.get();
			exit(EXIT_SUCCESS);
		}
	}


	if (encounterchance >= 7 & encounterchance <= 9)
	{
		cout << "You've encountered Orcs and Fight them\n";
		if (playerrollhit(Mainplayer) > (rand() % 20 - 2))
		{
			cout << "You defeat the Orcs\n";
			Mainplayer.add_counterk();
			Mainplayer.dincrease();
			Mainplayer.cincrease();
			Mainplayer.save_data();
			cout << "Press Enter to continue.";
			cin.ignore();
			cin.get();
		}
		else
		{
			cout << "You are defeated by Orcs" << endl;
			Mainplayer.uded();
			cout << "Press Enter to continue.";
			cin.ignore();
			cin.get();
			exit(EXIT_SUCCESS);

		}
	}

	if (encounterchance >= 10 & encounterchance <= 11)
	{
		cout << "You've encountered a Troll and Fight them\n";
		if (playerrollhit(Mainplayer) > (rand() % 20))
		{
			cout << "You defeat the Troll\n";
			Mainplayer.add_counterk();
			Mainplayer.sincrease();
			Mainplayer.hincrease();
			Mainplayer.save_data();
			cout << "Press Enter to continue.";
			cin.ignore();
			cin.get();
		}
		else
		{
			cout << "You are defeated the mighty Troll" << endl;
			Mainplayer.uded();
			cout << "Press Enter to continue.";
			cin.ignore();
			cin.get();
			exit(EXIT_SUCCESS);
		}
	}

	if (encounterchance ==  12 )
	{
		cout << "An Evil Adventureer Attacks YOU\n";
		if (playerrollhit(Mainplayer) > (rand() % 20 + 2))
		{
			cout << "You slay the Evil man\n";
			Mainplayer.add_counterk();
			Mainplayer.sincrease();
			Mainplayer.hincrease();
			Mainplayer.dincrease();
			Mainplayer.dincrease();
			Mainplayer.cincrease();
			Mainplayer.drincrease();
			Mainplayer.save_data();
			cout << "Press Enter to continue.";
			cin.ignore();
			cin.get();
		}
		else
		{
			cout << "The Evil Man takes your stuff and leaves you to die" << endl;
			Mainplayer.uded();
			cout << "Press Enter to continue.";
			cin.ignore();
			cin.get();
			exit(EXIT_SUCCESS);
		}
	}


}


void random_challenge(Character &Mainplayer) //4 random challenges based around stats
{
	int challenge = rand() % 4 + 1;
	
	
	if (challenge == 1)
	{
		cout << "A large stone blocks your path\n";
		if (Mainplayer.get_strength() > rand() % 5 + 12)
		{
			cout << "You move the boulder aside with ease and continue on\n";
			Mainplayer.add_counterc();
			Mainplayer.sincrease();
			Mainplayer.save_data();
			cout << "Press Enter to continue.";
			cin.ignore();
			cin.get();
			return;
		}
		else
		{
			cout << "You fail to move the boulder and look for another way" << endl;
			cout << "Press Enter to continue.";
			cin.ignore();
			cin.get();
			return;
		}
	}

	if (challenge == 2)
	{
		cout << "You need an outfit for a formal gathering and attempt to haggle\n";
		if (Mainplayer.get_charisma() > rand() % 6 + 10)
		{
			cout << "You convince the merchant to pay you for taking his finest outfit\n";
			Mainplayer.add_counterc();
			Mainplayer.cincrease();
			Mainplayer.save_data();
			cout << "Press Enter to continue.";
			cin.ignore();
			cin.get();
			return;
		}
		else
		{
			cout <<"You decide to attend the event in your armor and get kicked out"<< endl;
			cout << "You search for some Goblins to cheer you up.";
			cout << "Press Enter to continue.";
			cin.ignore();
			cin.get();
			return;
		}
	}
	
	if (challenge == 3)
	{
		cout << "You see a large band of mercenaries from a distant\n";
		if (Mainplayer.get_dexterity() > rand() % 5 + 13)
		{
			cout << "You sneak by them unnoticed\n";
			Mainplayer.add_counterc();
			Mainplayer.dincrease();
			Mainplayer.save_data();
			cout << "Press Enter to continue.";
			cin.ignore();
			cin.get();
			return;
		}
		else
		{
			cout << "They spot you and take your loot" << endl;
			cout << "Press Enter to continue.";
			cin.ignore();
			cin.get();
			return;
		}
	}

	
	if (challenge == 4)
	{
		cout << "An old woman ask you to carry her to the next town\n";
		cout << "Being the good adventurer you are you carry her.\n";
		if (Mainplayer.get_strength() > rand() % 5 + 13)
		{
			cout << "You carry her safely\n";
			Mainplayer.add_counterc();
			Mainplayer.sincrease();
			Mainplayer.save_data();
			cout << "Press Enter to continue.";
			cin.ignore();
			cin.get();
			if (Mainplayer.challengecount() == 4)
			return;
		}
		else
		{
			cout << "You drop her and she dies" << endl;
			cout << "Press Enter to continue.";
			cin.ignore();
			cin.get();
			return;
		}
	}
}

void Finalfight(Character &Mainplayer) //End game
{
	
	cout << "You roam the land for months in search of Fred the Mighty Ogre to fulfill your quest and protect to the land\n";
	cout << "After years of searching you find yourself unable to find fred.\n";
	cout << "Out of frustration you head down to a small pond to cry\n";
	cout << "As you look in the reflective pool you see not the relfection of yourself but Fred\n";
	cout << "You have become that which you swore to destroy\n";
	cout << "Do you fight yourself? (Y/N)\n";
	char fight;
	cin >> fight;
	if (fight == 'Y' || fight == 'y')
	{
		cout << "Fred the Ogre emerges from the small pond and fights you.\n";
		cout << "After an intense battle you slay him\n";
		cout << "THE END\n\n";
		Mainplayer.You_win();
		exit(EXIT_SUCCESS);

	}
	else
	{
		cout << "Game over\n";
		cout << "You lose\n";
		Mainplayer.uded();
		exit(EXIT_SUCCESS);

	}
}