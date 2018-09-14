#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
#include <time.h>

using namespace std;

int xorOp(int a, int b);
int main()
{
    int resp;
    do{

			printf("1.-Binario \n 2.-Gray\n 3.-Real\n 4.-Entero\n   5-SALIR\n");
             scanf("%d",&resp);
             srand (time(NULL));
			 switch(resp)
			 {
                case 1:
                        system("cls");
                        int binario[10];
                            for (int j = 0; j < 10; j++)
                            {
                                cout << "Individuo No. " << j+1 << endl;
                                for (int i = 0; i < 10; i++)
                                        binario[i] = rand() % 2;

                                for (int i = 0; i < 10; i++)
                                {
                                    if(i == 0)
                                        printf("\t|%d|", binario[i]);
                                    else if(i < 9){
                                        printf("%d|", binario[i]);
                                    }
                                    else
                                        printf("%d|\n", binario[i]);
                                }
                                printf("\n");
                            }
                break;
                case 2:
                        int binario1[10];
                        int gray[10];

                        for (int j = 0; j < 10; j++)
                            {
                                cout << "Individuo No. " << j+1 << endl;
                                for (int i = 0; i < 10; i++)
                                        binario1[i] = rand() % 2;

                                gray [0] = binario1[0];

                                for (int i = 1; i < 10; i++)
                                {
                                    gray[i] = xorOp(binario1[i-1], binario1[i]);
                                }
                                for (int i = 0; i < 10; i++)
                                {
                                    if(i == 0)
                                        printf("\t|%d|", binario1[i]);
                                    else if(i < 9){
                                        printf("%d|", binario1[i]);
                                    }
                                    else
                                        printf("%d|\n", binario1[i]);
                                }

                                for (int i = 0; i < 10; i++)
                                {
                                    if(i == 0)
                                        printf("\t|%d|", gray[i]);
                                    else if(i < 9){
                                        printf("%d|", gray[i]);
                                    }
                                    else
                                        printf("%d|\n", gray[i]);
                                }
                            }
                break;
                case 3:
                        float flotante[10];
                        for (int j = 0; j < 10; j++)
                            {
                                cout << "Individuo No. " << j+1 << endl;
                                for (int i = 0; i < 10; i++)
                                        flotante[i] = (float) (rand() % (100))/((rand() % (10))+1);

                                for (int i = 0; i < 10; i++)
                                {
                                    if(i == 0)
                                        printf("\t|%.02f|", flotante[i]);
                                    else if(i < 9){
                                        printf("%.02f|", flotante[i]);
                                    }
                                    else
                                        printf("%.02f|\n", flotante[i]);
                                }
                                printf("\n");
                            }
                break;
                case 4:
                        int entero[10];
                        for (int j = 0; j < 10; j++)
                            {
                                cout << "Individuo No. " << j+1 << endl;
                                for (int i = 0; i < 10; i++)
                                        entero[i] =rand() % 100;

                                for (int i = 0; i < 10; i++)
                                {
                                    if(i == 0)
                                        printf("\t|%d|", entero[i]);
                                    else if(i < 9){
                                        printf("%d|", entero[i]);
                                    }
                                    else
                                        printf("%d|\n", entero[i]);
                                }
                                printf("\n");
                            }
                break;
			 }
             }while(resp!=5);
		 return 0;
}

int xorOp(int a, int b){
	if(a == b)
		return 0;
	else
		return 1;
}

