#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
int main(){
	
	//Kelime Arama
	int i=0,j=0,r=0,c;
	long int uzunluk,length,length1;
	FILE *yaz;
	char kelime1[36];
	char kelime3[36];
	char kelime2[79];
	char kelime4[79];
	char kelime5[79];
	char kontrol,ch;
		setlocale(LC_ALL,"Turkish");
	printf("1-G�ncelleme\n");
	printf("2-Kelime Ekleme\n");
	printf("3-Kelime Arama\n");
	printf("4-T�m Dosyay� Yazd�rma\n");
	kontrol=getch();
	if(kontrol=='1'){
		yaz=fopen("sozluk.txt","r+");
		setlocale(LC_ALL,"Turkish");
		if(yaz==NULL){
			printf("Not defteri bos");
			exit(1);
		}
		printf("-----G�ncelleme-----\n");
		printf("G�ncellenecek Kelimeyi giriniz: ");	
		gets(kelime3);
		uzunluk=strlen(kelime3);
			while(!feof(yaz)){
			fgets(kelime1,uzunluk+1,yaz);
			i=strcmp(kelime1,kelime3);
				if (i==0){
				fseek(yaz,36-uzunluk,SEEK_CUR);
				fgets(kelime2,79,yaz);
				puts(kelime2);
				length1=strlen(kelime2);
				fseek(yaz,-length1-1,SEEK_CUR);
				puts("T�rk�e k�sm�n� giriniz: ");
				gets(kelime4);
				length=strlen(kelime3);
				puts(kelime2);		
					for(j=0;j<length1-1;j++){
					fprintf(yaz," ");	
				}
				fprintf(yaz,"\n");
				fseek(yaz,-(length1+1),SEEK_CUR);
				fputs(kelime4,yaz);
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
		else if (kontrol=='2'){
		yaz=fopen("sozluk.txt","r+");
		setlocale(LC_ALL,"Turkish");
		if(yaz==NULL){
		printf("Not defteri bos");
		exit(1);
		}
		printf("-----Kelime Arama-----\n");
		printf("Kelime giriniz: ");	
		gets(kelime3);
		uzunluk=strlen(kelime3);
		while(!feof(yaz)){
		fgets(kelime1,uzunluk+1,yaz);
		i=strcmp(kelime1,kelime3);
				if (i==0){
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
	else if(kontrol=='3'){
		yaz=fopen("sozluk.txt","a+");
		setlocale(LC_ALL,"Turkish");
		if(yaz==NULL){
		printf("Not defteri bos");
		exit(1);
		}
		printf("-----Kelime Ekleme-----\n");
			while(true){
		fputs("\n",yaz);
		printf("Kelimenin ingilizcesini yaziniz: ");
		gets(kelime1);
		fputs(kelime1,yaz);
		c=strlen(kelime1);
				for(r=0;r<36-c;r++){
				fprintf(yaz," ");
			}
		printf("Kelimenin turkcesi yaziniz: ");
		gets(kelime2);
		fputs(kelime2,yaz);
		puts("Tekrar kelime eklemek i�in 1 e bas�n�z");
		ch=getch();
		if(ch=='1')
			continue;
		else
			break;
		}	
	}
	else if (kontrol=='4'){
		yaz=fopen("sozluk.txt","r");
		setlocale(LC_ALL,"Turkish");
		if(yaz==NULL){
		printf("Not defteri bos");
		exit(1);
	}	
		printf("-----T�m Dosyay� yazd�rma-----\n");
		printf("Yazd�rmak i�in t�klay�n\n ");
		getch();
		while(!feof(yaz)){
		ch=getc(yaz);
		printf("%c",ch);
	}
	fclose(yaz);
	getch();
	return 0;
	}
}
