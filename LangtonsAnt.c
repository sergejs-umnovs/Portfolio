#include <stdio.h>
//#include <windows.h>
#include <conio.h>
#include <math.h>


#define SCRH 21
#define SCRW 81
#define RIGHT -1
#define LEFT 1
#define PI 3.1415

//
// Simulation of the Langton's ant, but in the console
// Generates 256 scenarios of ant's behaviour
//

char screen[SCRH][SCRW] = {}; // screen buffer 
typedef struct { // ant's struct
    void (*think)();
    void (*move)();
    void (*turn)();
    int pos[2];
    int movVec[2];
    int angle;
    } Ant, *Aptr;
    
void moveAnt(Aptr); // function prototypes
void thinkAnt(Aptr);
void turnAnt(Aptr, int);

struct Dirs { // behaviour control bit field
	int bit1:1;
	int bit2:1;
	int bit3:1;
	int bit4:1;
	int bit5:1;
	int bit6:1;
	int bit7:1;
	int bit8:1;
} directionControl;

int main() {
	Ant ant = {thinkAnt,moveAnt,turnAnt,{10, 40},{-1, 0}, 90}; // initialize the ant
	for(int D = 0; D < 256; D++) { // behaviour scenario selecting loop
		for(int i=0;i<SCRH;i++) { // clear the screen
			for(int j=0;j<SCRW;j++) {
				screen[i][j] = '%';
				}
			}
		ant.pos[0] = 10; // move the ant to the middle of the screen
		ant.pos[1] = 40;
		
		ant.movVec[0] = -1;
		ant.movVec[1] = 0;
		
		ant.angle = 90;
		
		while((ant.pos[0] <= 20 && ant.pos[0] >= 0) && (ant.pos[1] <= 80 && ant.pos[1] >= 0)){ // make it think, terminate if it goes out of screen bounds
			ant.think(&ant);
			ant.move(&ant);
			//Sleep(100);
		}
		for(int i=0;i<SCRH;i++) {
			for(int j=0;j<SCRW;j++) {
				printf("%c",screen[i][j]); //print screen buffer
				}
				printf("\n");
			}
		printf("\n");
		directionControl.bit1=D&(1<<0)?1:0; //modify bit field
		directionControl.bit2=D&(1<<1)?1:0;
		directionControl.bit3=D&(1<<2)?1:0;
		directionControl.bit4=D&(1<<3)?1:0;
		directionControl.bit5=D&(1<<4)?1:0;
		directionControl.bit6=D&(1<<5)?1:0;
		directionControl.bit7=D&(1<<6)?1:0;
		directionControl.bit8=D&(1<<7)?1:0;
	}
	getch(); // pause the program
	return 0;
}
    
void moveAnt(Aptr target) { // movement function
    target->pos[0] += target->movVec[0]; // compute position using vectors
    target->pos[1] += target->movVec[1];
    }
    
void turnAnt(Aptr target, int direction) { // rotation fucntion
    target->angle += 90*direction;
    target->movVec[0] = round(sinf(target->angle*PI/180)); // makes movement vectors. a fast, but resource-demanding solution
    target->movVec[1] = round(cosf(target->angle*PI/180));
    }
void thinkAnt(Aptr target) { // ant control
        int y = target->pos[0],x = target->pos[1];
        switch (screen[y][x]) {
		case '%':
            	target -> turn(target, LEFT+2*directionControl.bit1);
            	screen[y][x]='.';
            	break;
            	case '.':
            	target -> turn(target, LEFT+2*directionControl.bit2);
            	screen[y][x]='1';
            	break;
		case '-':
		target -> turn(target, LEFT+2*directionControl.bit3);
		screen[y][x]='%';
		break;
		case '1':
        	target -> turn(target, LEFT+2*directionControl.bit4);
            	screen[y][x]='2';
            	break;
		case '2':
          	target -> turn(target, LEFT+2*directionControl.bit5);
            	screen[y][x]='8';
            	break;
		case '8':
            	target -> turn(target, LEFT+2*directionControl.bit6);
            	screen[y][x]='z';
            	break;
		case 'z':
            	target -> turn(target, LEFT+2*directionControl.bit7);
            	screen[y][x]='m';
            	break;
		case 'm':
            	target -> turn(target, LEFT+2*directionControl.bit8);
            	screen[y][x]='%';
            	break;
        }
}

