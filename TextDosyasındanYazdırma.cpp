#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
int main(){
	//T�m Dosyay� yazd�rma!!
	int c,i;
	FILE *yaz;
	char ch;
	yaz=fopen("sozluk.txt","r");
	if(yaz==NULL){
		printf("Klasor bos!");
		exit(1);
	}
	while(!feof(yaz)){
		ch=getc(yaz);//Char char t�m text dosyas�n� al�r.printf() ile yazd�r�r.!!
		printf("%c",ch);
	}
	getch();
	fclose(yaz);
	return 0;
}
