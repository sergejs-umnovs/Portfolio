#include <conio.h>
#include <stdio.h>
#include <windows.h>

// 
// Программа для вывода на экран цветного изображения, работает только в консоли windows
// 
// Создайте файл с названием "sprite.txt" в той же папке, где находится скомпилированная программа, скопируйте и вставьте
// RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1-RGI1RGI111RGI1RGI111RGI1RGI1-RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1-11RGI1RGI1RGI1RGI1RGI1RGI111-RGI1RGI1111111RGI1RGI1c 
// в этот файл. При запуске у Вас должна отобразиться картинка
// Я знаю, это почти нечитабельно, но я так сам решил

int main() {
	DWORD color = 0; //										- WinAPI аналог int для хранения цвета								- 
	FILE *fp = fopen("sprite.txt", "r"); //					- открываем файл
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // 	- чтобы окрасить символ, нужна рукоятка консоли
	for (;;) { //											- делаем бесконечный цикл
		switch(fgetc(fp)) {	//								- отслеживаем все символы с помощью switch
		
		case 'R':
		color |= BACKGROUND_RED; //							- если следующий символ - 'R', то подмешиваем красный к переменной цвета
		//printf("%d\n", color);
		break;
		
		case 'G':
		color |= BACKGROUND_GREEN; //						- если следующий символ - 'G', то подмешиваем зелёный к переменной цвета
		//printf("%d\n", color);
		break;
		
		case 'B':
		color |= BACKGROUND_BLUE; //						- если следующий символ - 'B', то подмешиваем синий к переменной цвета
		//printf("%d\n", color);
		break;
		
		case 'I':
		color |= BACKGROUND_INTENSITY; //					- если следующий символ - 'I', то делаем цвет светлым
		//printf("%d\n", color);
		break;
		
		case '1':
		SetConsoleTextAttribute(handle, color); //			- если следующий символ - '1', то выводим цветной символ
		printf("%c",' '); /*								- в WinAPI есть 2 типа цветов символов, один из которых отвечает за цвет заднего фона, а второй - за цвет
		//printf("%d\n", color);							символов. Чтобы отобразить просто фон, нужно вывести символ ' '*/
		color = 0; //										- сбрасываем цвет, делая его чёрным
		break;
		
		case '-': //										- если следующий символ - '-', то переходим на следующую строку в терминале
		printf("\n");
		break;
		
		case 'c': //										- если следующий символ - 'с', то это значит, что файл закончился и следует прервать цикл
		break;
		}
		
	}
	getch();
	return 0;
}