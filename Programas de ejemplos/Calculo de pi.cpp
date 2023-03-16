#include <stdio.h>
#include <conio.h>
#include <math.h>

float calculopi(int area, int radio){
	return (area/(pow(radio,2)));
}

int main (){
	double area = 78.539816339744830961566084581988;
	int radio = 5;
	
	printf(" El numero pi es: %.16lf ",calculopi(area,radio));
	
	getch();
}
