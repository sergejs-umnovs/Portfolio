#include <iostream>
#include <string>
#include <ctime>
#define INV_SIZE 7
#define E_HP 50
#define P_HP 100
#define SW_DMG 25
#define AR_HBS 75
#define POT_BONUS 76
#include "items.h"

// Текстовая игра, правда незаконченная, я её писал чисто для понимая ООП в С++

int main() {
	flags.yourturn = 1;
	flags.cango = 1;
	flags.endgame = 0;
	srand(time(0));
	std::string action; //action buffer
	Player player(P_HP,2,P_HP,1);
	Room room;
	std::cout << "Welcome\nType 'help' to see list of all commands\nType 'go' to begin\n";
	while (std::getline(std::cin,action)) {
		if (action == "go" && flags.cango) {
			room = generateNewRoom();
			flags.cango = 0;
		}
		if (action == "give") {
			player.inventory[0].init(1000,0,0,"QED",1,{0,0});
			player.inventory[1].init(0,0,1000,"Tin hat",1,{0,0});
			player.inventory[2].init(0,1000,0,"Kumys",1,{0,0});
			std::cout << "***THE GODS HAVE GRANTED YOU STRENGTH***\n";
		}
		if (action == "pickup") {
			room.lookItems();
			int choice = 0;
			int slot = 0;
			std::cin >> choice;
			if (choice >= 0 && choice <= 3)  {
				player.viewInventory();
				std::cin >> slot;
				if(slot >= 0 && slot <= INV_SIZE) {
					player.inventory[slot] = room.stash[choice];
				}
			}
		}
		
		if (action == "inv") player.viewInventory();
		
		if (action == "drink") {
			int slot = 0;
			std::cin >> slot;
			player.drink(slot);
		}
		
		if (action == "equip") {
			int slot = 0;
			player.viewInventory();
			std::cin >> slot;
			player.equip(slot);
		}
		if (action == "dequip") {
			player.viewInventory();
			std::string t;
			
		}
		if (action == "help") {
			std::cout << "go\n - enter a new room\n\n"
			<< "help\n - display this message\n\n"
			<< "pickup -> item number in room stash -> slot number in your inventory\n - pick up an item from room stash and store it in your inventory\n\n"
			<< "equip -> inventory slot num\n - equip an item from your inventory\n\n"
			
			
			;
		}
		if (action == "status") {
			player.status();
			std::cout << "Equipped Weapon: " << player.equippedWeapon.name << " Damage: " << player.equippedWeapon.damage << std::endl;
			std::cout << "Equipped Armor: " << player.equippedArmor.name << " Health Boost: " << player.equippedArmor.healthBoost << std::endl;
		}
		if (action == "look") {
			room.lookEnemys();
			room.lookItems();
		}
		if (action == "kill") player.damage(696969);
		if (action == "attack") {
			std::cout << "Which foe to attack?\n";
			room.lookEnemys();
			int choice = 0;
			atkpoint:
			std::cin >> choice;
			if (choice >= 0 && choice <= 3) {
				room.crowd[choice].damage(player.dmg);
			flags.yourturn = 0;
			if (player.equippedWeapon.name == "Dynamite") {
				player.dmg -= player.equippedWeapon.damage;
				player.equippedWeapon.init(0,0,0,"",0,{0,0});
			}
			} else {
				std::cout << "Choose a number between 0 and 3\n";
				goto atkpoint;
			}
		}
		
		if (!flags.yourturn) {
			for(int i = 0; i < 4; i++) {
				if (room.crowd[i].alive == 1)
					player.damage(room.crowd[i].dmg);
			}
			flags.yourturn = 1;
			flags.cango = 1;
		}
		if (flags.endgame) break;
		
	}
	std::cout << "Game over\n";
	return 0;
}
