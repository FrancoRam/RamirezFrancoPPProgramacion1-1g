/*
 ============================================================================
 Name        : primerParcialProgramacion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

float aplicarAumento(float precioSinAumento);
int ordenarVacunas(int pVec[], int tam,int criterio); //AGREGAR CRITERIO (0 ASC -  1 DESC)
int reemplazarCaracteres(char pVec[], char caracter1, char caracter2);
//---------------------------------------


int main(void) {

	setbuf(stdout, NULL);

	typedef struct{
		int id;
		char nombre[20];
		char tipo;
		float efectividad;
	}eVacuna;

	eVacuna vacunas[5]={
			{100,"vacuna1",'a',10},
			{100,"vacuna2",'f',11},
			{100,"vacuna3",'x',33},
			{100,"vacuna4",'z',15},
			{100,"vacuna5",'d',60}
	};



	float productoSinAumento=10.00;
	float productoConAumento;
	productoConAumento = aplicarAumento(productoSinAumento);

	printf("%f", productoConAumento);


	return EXIT_SUCCESS;
}

float aplicarAumento(float precioSinAumento)
{
	float ret;
	ret = (precioSinAumento*1.05);

	return ret;
}

int ordenarVacunas(int pVec[], int tam,int criterio) //AGREGAR CRITERIO (0 ASC -  1 DESC)
{
	int ret=-1;
	int aux;
	if(pVec!=NULL && tam>0 && (criterio == 1 || criterio == 0))
	{
		for(int i=0; i<tam-1; i++)
		{
			for(int j=i+1; j<tam;j++)
			{
				if(criterio==0) //ORDENAMIENTO ASCENDENTE
				{
					if(pVec[i]>pVec[j])
					{
						aux=pVec[i];
						pVec[i]=pVec[j];
						pVec[j]=aux;
					}
				}
				else			//ORDENAMIENTO DESCENDENTE
				{
					if(pVec[i]<pVec[j])
					{
						aux=pVec[i];
						pVec[i]=pVec[j];
						pVec[j]=aux;
					}
				}

			}
		}
		ret=0;
	}
	return ret;
}

int reemplazarCaracteres(char pVec[], char caracter1, char caracter2)
{
	int ret=-1;
	int flag=0;
	if(pVec!=NULL && ((caracter1>=65 && caracter1<=90) || (caracter2>=97 && caracter2<=122)))
	{
		for(int i=0; i<sizeof(pVec);i++)
		{
			if(pVec[i]== caracter1)
			{
				strcpy(pVec[i], caracter2);
				flag=1;
				ret=0;
			}

		}

		if(flag==0)
		{
			printf("\nno se pudo realizar el reemplazo");
		}
	}
	return ret;
}
