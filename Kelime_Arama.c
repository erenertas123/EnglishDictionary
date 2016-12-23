#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
int main(){
	
	//Kelime Arama
	int i=0,uzunluk;
	FILE *yaz;
	char kelime1[36];
	char kelime3[36];
	char kelime2[79];
	yaz=fopen("sozluk.txt","r+");
	setlocale(LC_ALL,"Turkish");
	if(yaz==NULL){
		printf("Not defteri bos");
		exit(1);
	}
	printf("Kelime giriniz: ");	
	gets(kelime3);
	uzunluk=strlen(kelime3);
	while(!feof(yaz)){
		fgets(kelime1,uzunluk+1,yaz);
		i=strcmp(kelime1,kelime3);
			if (i==0)
			{
			fseek(yaz,36-uzunluk,SEEK_CUR);
			fgets(kelime2,79,yaz);
			puts(kelime2);
			break;
			}
			
	}
		if(i!=0){
			printf("Aranan Kelime yok.");
		}
	fclose(yaz);
	getch();
	return 0;
}
