#include <stdio.h>
#include <math.h>
#include <conio.h>
#define PI 3.141592

// 
// Program, which generates instructions for drawing a pixelated line
// Needed it for building in Minecraft

int main() {
    float angle, tg, count = 0;										// all the neccessary variables
    int i, width;											// 
	printf("Enter angle between ground and line (in degrees) and line horizontal width : ");	// 
    scanf("%f %d", &angle, &width);									// input
    angle = angle * PI/180;										// convert degrees to radians
    tg = tanf(angle);											// 
    for (i = 1; i <= width; i++){									// cycle, that generates the instructions
        count += tg;											// add an angle tangent to a discrete height variable
        printf("%d block is %d blocks in height\n", i, (int)floor(count));				// print instruction line
        count = count - floor(count);									// subtract the rounded value from the discrete height variable
	getch();
    }													// pause program
    return 0;
}
