#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
int main(){
	//Tüm Dosyayý yazdýrma!!
	FILE *yaz;
	char ch;
	setlocale(LC_ALL,"Turkish");
	yaz=fopen("sozluk.txt","r");
	if(yaz==NULL){
		printf("Klasor bos!");
		exit(1);
	}
	while(!feof(yaz)){
		ch=getc(yaz);
		printf("%c",ch);
	}
	fclose(yaz);
	getch();
	return 0;
}
