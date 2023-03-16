#include <stdio.h>
#include <conio.h>
#include <math.h>

double calculoConstante(double sidereo, double solar){
	return (sidereo/solar);
}

int main (){
	double siderealRate = 366.2422;
	double solarRate = 365.2422;
	
	printf(" La constante es: %.15lf ",calculoConstante(siderealRate, solarRate));
	
	getch();
}
