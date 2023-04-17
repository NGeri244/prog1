#include <iostream> 
#include <fstream>
#include <cstring> 
#include <stdio.h> 
#include <sstream>
#include <string> 
#include <list>
#include <algorithm>


using namespace std;

enum t_weapon_global { KALAPACS = 0, KETELUFEJSZE = 1, FEJSZE = 2, POROLY = 3 }weapon_global;
string weaponToString(int w) {
	switch (w) {
	case KALAPACS: return "KALAPACS"; break;
	case KETELUFEJSZE: return "KETELUFEJSZE"; break;
	case FEJSZE: return "FEJSZE"; break;
	case POROLY: return "POROLY"; break;
	default: return "";
	}
}
class Orc {

private:
	int id;
	string name;
	int name_change;
	int vitality;
public:	enum weapon {
	KALAPACS, KETELUFEJSZE, FEJSZE, POROLY

}weapon;
	int damage;
	  int shield;
public: bool died;


public:
	Orc(int oId, string oName, int oVitality, int oDamage, int oShield, string oWeapon)
	{
		name_change = 0;
		if (oId >= 0 && name_change <= 3 && oName.find(" ") != std::string::npos && sizeof(oName) >= 3 && oVitality <= 100 && oDamage >= 20 && oDamage <= 50 && oShield >= 10 && oShield <= 20)
		{
			id = oId;
			name = oName;
			name_change++;
			if (oVitality <= 0)
			{
				oVitality = 0;
				died = true;
			}
			else
			{
				died = false;
			}
			vitality = oVitality;
			damage = oDamage;
			shield = oShield;
			if (oWeapon == "KALAPACS")
			{
				weapon = KALAPACS;

			}
			else if (oWeapon == "KETELUFEJSZE")
			{
				weapon = KETELUFEJSZE;
			}
			else if (oWeapon == "FEJSZE")
			{
				weapon = FEJSZE;
			}
			else
			{
				weapon = POROLY;
			}
		}
		else { cout << "Ellenorizd az adatokat!" << endl; }

	};

	void Damaged(int dmg) {
		vitality = vitality - dmg;
		cout << vitality;
	};

	void Attack(Orc exampleorc) {
		if (exampleorc.vitality > 0)
		{
			Damaged(exampleorc.damage);
		}
		else
		{
			cout << "Hullagyalazasra meg egy orc sem kepes!";
		}
	};
	void ToString() {
		cout << "ID: " << id << " | " << "Name: " << name << " | " << "Vitality: " << vitality << " | " << "Damage: " << damage << " | " << "Shield: " << shield << " | " << "Dead: " << string(died ? "Yes" : "No") << " | ";
		switch (weapon)
		{
		case Orc::KALAPACS:
			cout << "Weapon: KALAPACS" << endl;
			break;
		case Orc::KETELUFEJSZE:
			cout << "Weapon: KETELUFEJSZE" << endl;
			break;
		case Orc::FEJSZE:
			cout << "Weapon: FEJSZE" << endl;
			break;
		case Orc::POROLY:
			cout << "Weapon: POROLY" << endl;
			break;
		}
	};
	int getId() {
		return id;


	};
	int getVitality() {
		return vitality;
	}
	int GetDamage() { return damage; }
	string getName() { return name; }
	int getWeapon() { return weapon; }
};
Orc getElement(list<Orc> _list, int _i) {
	list<Orc>::iterator it = _list.begin();
	for (int i = 0; i < _i; i++) {
		++it;
	}
	return *it;
}
class Horda {

public:list<Orc> orcok;
private:string name;
	   int namechange;
public:
	Horda(string Hordanev) {

		if (Hordanev != "" && sizeof(Hordanev) >= 3 && namechange < 1)
		{
			name = Hordanev;

		}

	};
	void AddOrc(Orc orc_) {
		orcok.push_back(orc_);
	}
	list<Orc> DeadOrcs() {
		list<Orc> dead;
		for (auto i : orcok) {

			if (i.getVitality() <= 0) { dead.push_back(i); }
		}
		return dead;
	};

	Orc StrongestOrc() {
		int max = 0, index = 0;
		for (int i = 0; i < orcok.size(); i++) {
			if (getElement(orcok, i).damage > max) {
				max = getElement(orcok, i).damage;
				index = i;
			}
		}
		return getElement(orcok, index);

	}
	list<Orc> WeakOrcs(int vit) {
		list<Orc> weaklist;
		for (int i = 0; i < orcok.size(); i++) {
			Orc o = getElement(orcok, i);
			if (o.getVitality() < vit && !o.died) {
				weaklist.push_back(o);

			}
		}

		return weaklist;

	}
	std::list <Orc> OrcsWithGivenWeapon(t_weapon_global weapon) {
		std::list <Orc> ret_lista;
		for (int i = 0; i < orcok.size(); i++) {
			Orc o = getElement(orcok, i);
			if (o.getWeapon() == weapon)ret_lista.push_back(o);
		}
		return ret_lista;
	}

};
t_weapon_global toWeapon(string a) {
	if (a == "KALAPACS")return KALAPACS;
	else if (a == "KETELUFEJSZE") return KETELUFEJSZE;
	else if (a == "FEJSZE")return FEJSZE;
	else return POROLY;
}
Horda importHorda(Horda h, string fileName) {
	int index = 0, vitality, damage, shield;
	char* name, * weapon;
	try {
		ifstream file("C:/Users/nagyg/Documents/inof/orc/ork.csv");
		string line;
		getline(file, line);
		while (getline(file, line)) {
			char* token, * context;

			// Az első hívásnak a sztringgel kell lennie, amelyen dolgozunk
			char lin[100];
			strcpy_s(lin, line.length() + 1, line.c_str());
			token = strtok_s(lin, ";", &context);
			name = token;
			token = strtok_s(nullptr, ";", &context);
			vitality = atoi(token);
			token = strtok_s(nullptr, ";", &context);
			weapon = token;
			token = strtok_s(nullptr, ";", &context);
			damage = atoi(token);
			token = strtok_s(nullptr, ";", &context);
			shield = atoi(token);
			string weapon_s(weapon + '\0');
			string name_s(name + '\0');
			h.AddOrc(Orc(index, name, vitality, damage, shield, weapon));
			index++;
		}
		file.close();
		return h;
	}
	catch (std::exception& e) {
		cout << &e << endl;
	}
}
int main()
{
	Horda h1("Horda: ");
	h1 = importHorda(h1, "C:/Users/nagyg/Documents/inof/orc/ork.csv");
	cout << "Legerosebb: " << endl;
	h1.StrongestOrc().ToString();
	cout << "Halott: " << endl;
	for (auto i : h1.DeadOrcs()) {
		i.ToString();
	}
	
	cout << "Gyengek: " << endl;
	for (auto i : h1.WeakOrcs(20)) {
		i.ToString();
	}
	string fegyver;
	cout << "Adjon meg egy fegyvernevet(KALAPACS,KETELUFEJSZE,FEJSZE,POROLY):" << endl;
	cin >> fegyver;
	printf("Orcok %s fegyverrel:\n",fegyver);
	for (auto i : h1.OrcsWithGivenWeapon(toWeapon(fegyver))) {
		i.ToString();
	}
}
