
#include <iostream>
#include <string>
#include <fstream>
#include "Character.h"

using namespace std;


Character::Character() //No argument constructor 
{

}

Character::Character(string fname, string lname, string character_type, int str, int ht, int dex, int cha, int dr) //Sorts stats for character creation
{
	firstname = fname;
	lastname = lname;
	character_class = character_type;
	strength = str;
	health = ht;
	dexterity = dex;
	damagereduction = dr;
	charisma = cha;

}


string Character::first_name() //Gets first name
{
	return firstname;
}


string Character::last_name() //Gets last name
{
	return lastname;
}

string Character::get_character_class() //Class
{
	return character_class;
}

int Character::get_strength() //Strength
{
	return strength;
}

int Character::get_health() //Health
{
	return health;
}

int Character::get_dexterity() //Dexterity
{
	return dexterity;
}

int Character::get_charisma() //Charisma
{
	return charisma;
}

int Character::get_damagereduction() //Damage reduction
{
	return damagereduction;
}

int Character::killcount() //Keeps track of kills
{
	return monsterskilled;
}

int Character::challengecount() //Keeps track of challenges
{
	return challengescompleted;
}

void Character::sincrease() //Increases Strength
{
	strength++;
}

void Character::hincrease() //Increases Heatlth
{
	health++;
}

void Character::dincrease() //Increases Dexterity
{
	dexterity++;
}

void Character::cincrease() //Increases Charisma
{
	charisma++;
}

void Character::drincrease() //Increases Damage Reduction
{
	damagereduction++;
}


void Character::set_counter(int mkilled) //Sets counter from loading save
{
	monsterskilled = mkilled;
}

void Character::set_challengescounter(int Ccompleted) //Sets counter from loading save
{
	challengescompleted = Ccompleted;
}

void Character::add_counterk() //Icrements Monsters Killed
{
	monsterskilled++;
}

void Character::add_counterc() //Increments challenges completed
{
	challengescompleted++;
}

void Character::save_data() //saves game
{
	ofstream character_save;
	character_save.open("Character_save.txt");
	character_save << firstname << " " << lastname << " " << character_class << " " << strength << " " << health << " " << dexterity << " " << charisma << " " << damagereduction << " " << monsterskilled << " " << challengescompleted;
	character_save.close();
}

void Character::uded() //Outputs text file when you die
{
	ofstream dead_character;
	dead_character.open("DeadCharacter.txt");
	dead_character << firstname << " " << lastname << "\nClass: " << character_class << "\nStrength: " << strength << "\nHealth: " << health << "\nDexterity: " << dexterity << "\nCharisma: " << charisma << "\nArmor: " << damagereduction << "\n You managed to kill " << monsterskilled << " monsters before dying\n" << "You completed " << challengescompleted << " challenges";
	dead_character.close();
}

void Character::You_win() //Outputs text file when you win
{
	ofstream youwon;
	youwon.open("CongratsYouWon.txt");
	youwon << firstname << " " << lastname << "\nClass: " << character_class << "\nStrength: " << strength << "\nHealth: " << health << "\nDexterity: " << dexterity << "\nCharisma: " << charisma << "\nArmor: " << damagereduction << "\n You managed to kill " << monsterskilled << " monsters\n" << "You completed " << challengescompleted << " challenges\n";
	youwon << "Great Job on completing the game. I hoped you like it. - Colin Bondy" << endl;
	youwon.close();
}