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
// Программа-симуляция муравья Лэнгтона (YouTube в курсе), только в консоли
// Выдаёт 256 сценариев поведения
//

char screen[SCRH][SCRW] = {}; //экранный буфер
typedef struct { //структура муравья
    void (*think)();
    void (*move)();
    void (*turn)();
    int pos[2];
    int movVec[2];
    int angle;
    } Ant, *Aptr;
    
void moveAnt(Aptr); //прототипы функций
void thinkAnt(Aptr);
void turnAnt(Aptr, int);

struct Dirs { //битовое поле контроля направлений
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
	Ant ant = {thinkAnt,moveAnt,turnAnt,{10, 40},{-1, 0}, 90}; // инициализируем муравь
	for(int D = 0; D < 256; D++) { // цикл, который задаёт сценарии
		for(int i=0;i<SCRH;i++) { // чистим экран
			for(int j=0;j<SCRW;j++) {
				screen[i][j] = '%';
				}
			}
		ant.pos[0] = 10; // возвращаем муравья в центр
		ant.pos[1] = 40;
		
		ant.movVec[0] = -1;
		ant.movVec[1] = 0;
		
		ant.angle = 90;
		
		while((ant.pos[0] <= 20 && ant.pos[0] >= 0) && (ant.pos[1] <= 80 && ant.pos[1] >= 0)){ // следя за его позицией, заставляем его думать и передвигаться
			ant.think(&ant);
			ant.move(&ant);
			//Sleep(100);
		}
		for(int i=0;i<SCRH;i++) {
			for(int j=0;j<SCRW;j++) {
				printf("%c",screen[i][j]); //выводим экранный буфер
				}
				printf("\n");
			}
		printf("\n");
		directionControl.bit1=D&(1<<0)?1:0; //модифицируем битовое поле
		directionControl.bit2=D&(1<<1)?1:0;
		directionControl.bit3=D&(1<<2)?1:0;
		directionControl.bit4=D&(1<<3)?1:0;
		directionControl.bit5=D&(1<<4)?1:0;
		directionControl.bit6=D&(1<<5)?1:0;
		directionControl.bit7=D&(1<<6)?1:0;
		directionControl.bit8=D&(1<<7)?1:0;
	}
	getch(); // ставим на паузу
	return 0;
}
    
void moveAnt(Aptr target) { //функция передвижения
    target->pos[0] += target->movVec[0]; //вычисляем с помошью векторной суммы
    target->pos[1] += target->movVec[1];
    }
    
void turnAnt(Aptr target, int direction) { // функция поворота, используется в thinkAnt
    target->angle += 90*direction;
    target->movVec[0] = round(sinf(target->angle*PI/180)); // преобразует поворот в направление. быстрое решение, но ресурсозатратное
    target->movVec[1] = round(cosf(target->angle*PI/180));
    }
void thinkAnt(Aptr target) { // контроль поведения муравья
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

