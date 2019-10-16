/*Proyecto Final.c*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int validarletrasnumeros(char cadena[]);
int validarsimbolos(char cadena[]);
int validarnumero(char numero[]);

int main()
{
	system("color 02");
	
	int i,j,k,n,t,validacion,validarsimbol,opcion,numerovalido;
	
	char letras[37]={'a','b','c','d', 
	'e','f','g','h','i','j','k','l','m', 
	'n','o','p','q','r','s','t', 
	'u','v','w','x','y','z','1', 
	'2','3','4','5', 
	'6','7','8','9','0',' '}; 

	char morse[37][6]={{".-"},{"-..."}, 
	{"-.-."},{"-.."},{"."},{"..-."} 
	,{"--."},{"...."},{".."}, 
	{".---"},{"-.-"},{".-.."} 
	,{"--"},{"-."},{"---"},{".--."}, 
	{"--.-"},{".-."}, 
	{"..."},{"-"},{"..-"}, 
	{"...-"}, 
	{".--"},{"-..-"}, 
	{"-.--"},{"--.."}, 
	{".----"},{"..---"}, 
	{"...--"},{"....-"}, 
	{"....."},{"-...."}, 
	{"--..."},{"---.."}, 
	{"----."}, 
	{"-----"},{"//"}}; 

	char cadena[100000]; 
	char pa[10000][10];
	char opc[5];

	do{
		printf("\t==Programa que transforma de texto a codigo Morse o viceversa==\n\n\n");
		printf("\t============ Codigo Morse =============\n\n");
		printf("\t___________________________________________\n");
		printf("\t|a .-     |  b -...  |  c -.-.  |  d -..   |\n");
		printf("\t|e .      |  f ..-.  |  g --.   |  h ....  |\n");                   
		printf("\t|i ..     |  j .---  |  k -.-   |  l .-..  |\n");
		printf("\t|m --     |  n -.    |  o ---   |  p .--.  |\n");
		printf("\t|q --.-   |  r .-.   |  s ...   |  t -     |\n");
		printf("\t|u ..-    |  v ...-  |  w .--   |  x -..-  |\n");
		printf("\t|y -.--   |  z --..  |  0 ----- |  1 .---- |\n");
		printf("\t|2 ..---  |  3 ...-- |  4 ....- |  5 ..... |\n");
		printf("\t|6 -....  |  7 --... |  8 ---.. |  9 ----. |\n");
		printf("\t|__________________________________________|\n");
		printf("\n\t==Instrucciones==\n");
		printf("\n\t1- Escribir un texto este se escribira a codigo Morse");
		printf("\n\t2- Escribir el codigo Morse dando un espacio por cada codigo para devolver en texto");
		printf("\n\t3- Salir\n");
	do{
		printf("\n\tSeleccione una opcion: ");
		scanf("%s",&opc);
		getch();
		t=validarnumero(opc);
		
	}
	while(t==0);
	numerovalido=atoi(opc);
	switch(numerovalido)
	   {
		case 1:{
				FILE *texto; 
	            texto=fopen("Texto-Morse.txt", "a");
	            if(texto==NULL){
		        printf("Error al crear el archivo");
	            }
				fflush(stdin);
				fprintf(texto,"Texto a Morse\n");
			do{
				fflush(stdin);
				printf("\n\tEl texto siguiente sera convertido a codigo Morse: ");
				gets(cadena);
				fputs(cadena, texto);
				printf("\n");
				validacion = validarletrasnumeros(cadena);
			  }
				while(validacion ==0);
				printf("\tEn codigo Morse es: ");
				for(i=0;i<cadena[i];i++)
				{
				for(j=0;j<37;j++)
				if(cadena[i]==letras[j])
				printf("   %s",morse[j]);
				fprintf(texto, "  %s ",morse[j]);
				}
				getch();
				system("cls");
				
				}	
		break;
			
		case 2:
			{
			 FILE *morsetext; 
	         morsetext=fopen("Morse-texto.txt", "a");
	         if(morsetext==NULL)
			 {
		     printf("Error al crear el archivo");
	         }
			    fprintf(morsetext,"De Morse a texto\n");
			do{
				fflush(stdin);
				printf("\n\tEl siguiente codigo Morse sera transformado a texto: ");
				gets(cadena);
				fputs(cadena, morsetext);
				printf("\n");
				validarsimbol=validarsimbolos(cadena);
	 		  }
			 	while(validarsimbol==0);
				printf("\tEn texto es: ");
				n=0, k=0;
			for(i=0; cadena[i]!='\0'; i++)
			{
				if(cadena[i+1] == '\0')
				{
					pa[n][k] = cadena[i];
					pa[n][k+1] = '\0';
					n++;
				}
				else
				{
					if(cadena[i] != ' ')
					{
					pa[n][k] = cadena[i];
					k++;					 
				}
				else
				{
					pa[n][k] = '\0';
					k=0;
					n++;
				}	
				
				}
			}
			for(i=0; i<n; i++)
			{
			for(j=0; j<37; j++)
			{
				if(strcmp(pa[i], morse[j])==0)
				{
					printf(" %c",letras[j]);
					fprintf(morsetext, "  %c ", letras[j]);
					fflush(stdin);
				}
			}
			
			}
			getch();
			system("cls");
			
			}
					 
		break;
	  }
	}
	while(numerovalido!= 3);
	return 0; 
} 



/*FUNCIONES PARA VADILACION*/

/*Funcion para validar letras*/
int validarletrasnumeros(char cadena[])
{
	int i;
	for(i=0; i<strlen(cadena); i++)
	{
		if(!(cadena[i]>=97 && cadena [i]<=122 || cadena[i]>=48 && cadena [i]<=57|| cadena [i]==32 ))
		{
			printf("\tPorfavor solo ingresa letras minusculas o numeros\n");
			getch();
			return 0;
		}
	}
	return 1;
}

/*Funcion para validar simbolos*/

int validarsimbolos(char cadena[])
{
	int i;
	for(i=0; i<strlen(cadena); i++)
	{
		if(!(cadena[i]>=45 && cadena [i]<=47 ||cadena [i]==32))
		{
			printf("\tPorfavor solo ingresa los simbolos correspondientes\n");
			return 0;
		}
	}
	return 1;
}

/*Funcion para validar números*/
int validarnumero(char numero[])
{
	int i;
	for(i=0;i<strlen(numero);i++)
	{
		if(!(isdigit(numero[i])))
		{
			printf("\n\tIngresa solo numeros para la opcion deseada\n");
			getch();
			return 0;
		}
	}
	return 1;
}
	




