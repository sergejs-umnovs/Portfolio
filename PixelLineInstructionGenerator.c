#include <stdio.h>
#include <math.h>
#include <conio.h>
#define PI 3.141592

// 
// Программа для генерации инструкции по рисованию пиксельных отрезков
// Нужна была мне для строительства в Minecraft

int main() {
    float angle, tg, count = 0;										// все необходимые переменные
    int i, width;											// 
	printf("Enter angle between ground and line (in degrees) and line horizontal width : ");	// 
    scanf("%f %d", &angle, &width);									// ввод
    angle = angle * PI/180;										// преобразование градусов в радианы
    tg = tanf(angle);											// 
    for (i = 1; i <= width; i++){									// цикл, в котором генерируется инструкция
        count += tg;											// добавляем тангенс угла к переменной дискретной высоты
        printf("%d block is %d blocks in height\n", i, (int)floor(count));				// выводим строку инструкций с целым числом блоков
        count = count - floor(count);									// отнимаем целую часть от переменной дискретной высоты
	getch();											// ставим программу на "паузу"
    return 0;
}
