
#include <iostream>
#include <string>


#ifndef Character_H
#define Character_H

using namespace std;

//Character class
class Character
{
public: //Class functions
	Character();
	Character(string fname, string lname, string character_type, int str, int ht, int dex, int cha, int dr);
	string first_name();
	string last_name();
	string get_character_class();
	int get_strength();
	int get_health();
	int get_dexterity();
	int get_charisma();
	int get_damagereduction();
	int killcount();
	int challengecount();
	void sincrease();
	void hincrease();
	void dincrease();
	void cincrease();
	void drincrease();
	void set_counter(int mkilled);
	void set_challengescounter(int Ccompleted);
	void add_counterk();
	void add_counterc();
	void save_data();
	void uded();
	void You_win();

private: //Variables needed for functions
	int strength = 0;
	int health = 0;
	int dexterity = 0;
	int charisma = 0;
	int damagereduction = 0;
	string firstname = "I";
	string lastname = "Am";
	string character_class = "Noob";
	int monsterskilled = 0;
	int challengescompleted = 0; //Did not initially set this to zero cause lots of problems

};

#endif