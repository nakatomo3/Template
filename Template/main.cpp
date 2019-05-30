#include<stdio.h>
#include"main.h"

int main(void) {

	//Init();

	Vector3 pos = Vector3(1, 2);
	Vector3 posB = Vector3(5, 6);
	Vector3 posC = pos.UnitVector();

	//printf("%f", pos.x);


	getchar();
	return 0;
}