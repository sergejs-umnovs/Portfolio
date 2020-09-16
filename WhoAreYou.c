#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define RND rand()%10

// 
// Программа, которая связывает множество строк в одну.
// Ради шутки


int main() {
	while(1){
    srand(time(0));
    char goodAttrib[10][20] = {"shining", "brave", "gentle", "gorgeous", "epic", "light", "happy", "creative", "manly", "feminine"};
    char badAttrib[10][20] = {"nasty", "nervous", "scary", "raging", "stupid", "crazy", "ruthless", "egoistic", "deceiving", "gay"};
    char you[10][20] = {"queen", "hobo", "wizard", "hero", "bastard", "pilot", "builder", "gamer", "dinosaur", "alien"};
    char activity[10][20] = {"watch", "invent", "draw", "program", "kick", "jump with", "solder", "smoke", "burn", "****"};
    char objectOfAct[10][20] = {"Napoleon", "Donald Trump", "Spongebob", "yo mama", "other programmers", "memes", "your keyboard", "a mongol", "goo", "Minecraft"};
    char whileAct[10][20] = {"teaching", "collecting", "breaking", "running at", "destroying", "launching", "raping", "cooking", "losing", "accomplishing"};
    char whileObj[10][20] = {"penguins", "men", "pyramids", "your friends", "a russian", "your pc", "dams", "Skynet", "pigs", "ghosts"};
	
	char undoneAct[10][20] = {"banned", "come out of", "read", "stolen", "mined", "calculated", "installed", "conquered", "disassembled", "scrambled"};
	char undoneObj[10][20] = {"sheep", "elephants", "a weirdo", "rock'n'roll", "toilet", "drugs", "a wraith", "DOTA 2", "unions", "an essay"};
	char toDoFirst[10][20] = {"make", "devastate", "wash", "stomp", "play", "grow", "smash", "close", "archive", "pass by"};
	char toDoObj[10][20] = {"tanks", "peridots", "candies", "mugs", "scissors", "money", "The Pope", "yourself", "your dad", "a dog"};
	char resultActivity[10][22] = {"dominate", "rise and shine", "drive your van", "finish your program", "wake up", "crucify men", "get ready", "smite all atheists", "program in HTML", "stop it"};
    printf("You are a %s, but %s %s.\nYou like to %s %s while %s %s.\nYou haven't %s %s yet so you will need to %s %s to %s.\n\n", goodAttrib[RND], badAttrib[RND], you[RND], activity[RND], objectOfAct[RND], whileAct[RND], whileObj[RND], undoneAct[RND], undoneObj[RND], toDoFirst[RND], toDoObj[RND], resultActivity[RND]);
	getch();
	}
    return 0;
}

//char [10][20] = {"", "", "", "", "", "", "", "", "", ""};