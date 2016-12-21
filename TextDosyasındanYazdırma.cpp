#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
int main(){
	//Tüm Dosyayý yazdýrma!!
	int c,i;
	FILE *yaz;
	char ch;
	yaz=fopen("sozluk.txt","r");
	if(yaz==NULL){
		printf("Klasor bos!");
		exit(1);
	}
	while(!feof(yaz)){
		ch=getc(yaz);//Char char tüm text dosyasýný alýr.printf() ile yazdýrýr.!!
		printf("%c",ch);
	}
	getch();
	fclose(yaz);
	return 0;
}
