 #ifndef CS_CLASSES
#define CS_CLASSES

//macros
/*
INV_SIZE inventory size
E_HP enemy hp
P_HP player hp
SW_DMG sword damage
AR_HBS armor points
POT_BONUS potion bonus

*/

class Item; 
class Player; 
class Enemy;
class Room;
std::string names1[10] = {"Iron","Cobalt","Palladium","Platinum","Naquadah","Steel","Golden","Titanium","Vanadium","Elbor"};
std::string names2[10] = {"Catalyst","Vengeance","Revenge","Shard","Spark","Omnilyx","Fate","Intervention","Crook","Invitron"};
Room generateNewRoom();
std::string genName();

typedef struct {
	int slot;
	bool equipped;
} edata;

struct gameflags {
	int yourturn:1;
	int endgame:1;
	int cango:1;
	
} flags;

class Item { // parameters - 6
	public:
	int damage;
	int healthBonus;
	int healthBoost;
	std::string name;
	bool exist;
	edata iedata;
	Item() {
		
	}
	void init(int dmg, int hbs, int hbt, std::string nm, bool exst, edata iedt) {
		damage = dmg;
		healthBonus = hbs;
		healthBoost = hbt;
		name=nm;
		exist=exst;
		iedata = iedt;
	}
};

class Player { //player class
	public:
	int hp;
	int dmg;
	int maxHp;
	bool alive;
	Item inventory[INV_SIZE];
	Item equippedWeapon;
	Item equippedArmor;
	Player(int _hp, int _dmg, int _maxHp, bool _alive) : hp(_hp), dmg(_dmg), maxHp(_maxHp), alive(_alive) {
		for (Item &c : inventory) {
			c.init(0,0,0,"",0,{0,0});
		}
		equippedWeapon.init(0,0,0,"",0,{0,0});
		equippedArmor.init(0,0,0,"",0,{0,0});
	}
	
	void equip(int8_t slot) {
		if (slot >= 0 && slot < INV_SIZE) {
			if (inventory[slot].damage > 0) {
				inventory[slot].iedata.equipped = 1;
				inventory[slot].iedata.slot = slot;
				equippedWeapon = inventory[slot];
				dmg += equippedWeapon.damage;
				std::cout << "You equip " << equippedWeapon.name << " with " << equippedWeapon.damage << " damage" << std::endl;
			} else if (inventory[slot].healthBoost > 0){ 
				inventory[slot].iedata.equipped = 1;
				inventory[slot].iedata.slot = slot;
				equippedArmor = inventory[slot];
				maxHp += equippedArmor.healthBoost;
				
				std::cout << "You equip " << equippedArmor.name << " with " << equippedArmor.healthBoost << " health boost" << std::endl;
			} else {
				std::cout << "This cannot be equipped" << std::endl;
			}
		}
	}
	
	void dequip(std::string type) {
		if (type == "weapon") {
			inventory[equippedWeapon.iedata.slot].iedata.slot = 0;
			inventory[equippedWeapon.iedata.slot].iedata.equipped = 0;
			equippedWeapon.init(0,0,0,"",0,{0,0});
		}
		if (type == "armor") {
			inventory[equippedArmor.iedata.slot].iedata.slot = 0;
			inventory[equippedArmor.iedata.slot].iedata.equipped = 0;
			equippedArmor.init(0,0,0,"",0,{0,0});
		}
	}
	
	void damage(int val) {
		this->hp -= val;
		if (hp <= 0) {
			alive = 0;
			std::cout << "You died.";
			flags.endgame = 1;
		}
		std::cout << "You've been damaged by " << val << " points!" << std::endl;
	}
	
	
	void heal(int val) {
		hp += val;
		if(hp > maxHp) hp = maxHp;
		std::cout << "You've been healed by " << val << " points!" << std::endl;
	}
	
	void drink(int slot) {
		if (slot >= 0 && slot < INV_SIZE) {
			if (inventory[slot].healthBonus > 0) {
				heal(inventory[slot].healthBonus);
				inventory[slot].init(0,0,0,"",0,{0,0});
			} else 
				std::cout << "Not a healing item." << std::endl;
		} else std::cout << "Invalid slot." << std::endl;
	}
	
	void salvage(int8_t slot){
		if (slot>=0 && slot <= INV_SIZE) {
			inventory[slot].init(0,0,0,"",0,{0,0});
		} else {
			std::cout << "You've meant to drop an item, not the stone next to you!" << std::endl;
		}
	}
	
	void status() {
		std::cout<<"Health: "<< this->hp << "\nDamage: " << this->dmg << std::endl;
	}
	void viewInventory() {
		for(int i = 0;i < INV_SIZE; i++) {
			if (inventory[i].exist) {
				std::cout<<"Slot "<< i << ":\n" << "Name: " << inventory[i].name << "\nDamage:" << inventory[i].damage << "\nHealth bonus: " << inventory[i].healthBonus << "\nHealth boost: " << inventory[i].healthBoost;
				if (inventory[i].iedata.equipped) {
					std::cout << " This item is equipped" << std::endl;
				} else {}
			} else {
				std::cout<<"Slot "<< i << ": Empty\n";
			}
		}
	}
};


class Enemy { // enemy class
	public:
	int hp;
	int dmg;
	bool alive;
	Enemy() {
        
	}
	void init(int a, int b, bool c) {
		hp = a;
		dmg = b;
		alive = c;
		if (alive == 1)
			std::cout << "A new enemy in room with " << a << " hp and " << b << " strength!" << std::endl;
	}
	void damage(int val) {
		this->hp-=val;
		std::cout << "You deal "<< val << " damage to the enemy!" << std::endl;
		if (hp <= 0) {
			init(0,0,0);
			std::cout << "Enemy down!" << std::endl;
		}
	}
};
class Room { //room class
	public:
	Enemy crowd[4]; //used in attack row
	Item stash[4]; //available after fight
	void lookEnemys(){
		for(int i = 0; i<4; i++) {
			if (crowd[i].alive == 1)
				std::cout << "Enemy "<< i << ":\n" << "HP: " << this->crowd[i].hp << "\nDamage: " << this->crowd[i].dmg << std::endl << std::endl;
		}
	}
	void lookItems() {
		for(int i = 0; i<4; i++) {
			if (stash[i].exist == 1)
				std::cout << "Item "<< i << ":\n" << "Name: " << this->stash[i].name << "\nHealth bonus: " << this->stash[i].healthBonus << "\nHealth Boost: " << this->stash[i].healthBoost << "\nDamage: " << this->stash[i].damage << std::endl << std::endl;
		}
	}
};
inline std::string genName() { // make name
	return names1[rand()%10] + " " + names2[rand()%10];
}

Room generateNewRoom() { // make room
	Room room;
	int8_t enemyCount=rand()%4;
	int8_t itemCount=rand()%4;
	Enemy enemy;
	for(int i = 0;i < 4; i++) {
		if (i <= enemyCount) {
			enemy.init(rand()%E_HP+1,rand()%12+1,1);
			room.crowd[i] = enemy;
		} else {
			enemy.init(0,0,0);
			room.crowd[i] = enemy;
		}
	}
	for(int i = 0;i < 4; i++) {
		if (i <= itemCount)
			switch(rand()%4)
			{
				case 0:
					room.stash[i].init(rand()%SW_DMG,0,0,genName(),1,{0,0});
				break;
				case 1:
					room.stash[i].init(100,0,0,"Dynamite",1,{0,0});
				break;
				case 2:
					room.stash[i].init(0,rand()%POT_BONUS,0,"Booze",1,{0,0});
				break;
				case 3:
					room.stash[i].init(0,0,rand()%AR_HBS,genName(),1,{0,0});
				break;
			} else room.stash[i].init(0,0,0,"",0,{0,0});
	}
	return room;
}
#endif
