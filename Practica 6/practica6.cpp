#include <iostream>
#include <bitset>
#include <time.h>
#include <string>
#define PUNTO_CRUZA 2

using namespace std;
void llenado(bitset<10> *set);
char * cruzaAcentuada(char * padre1, char * padre2);
//cruzas
bitset<10> UnPunto(bitset<10> &padre1, bitset<10> &padre2, int punto_cruza);
bitset<10> DosPunto(bitset<10> &padre1, bitset<10> &padre2);
bitset<10> Uniforme(bitset<10> &padre1, bitset<10> &padre2);

int main(int argc, char const *argv[])
{
	bitset<10> padre1;
	bitset<10> padre2;
	bitset<10> hijo1;
	bitset<10> hijo2;
	char padre1_2 [29] = {'a',' ','a',' ','a',' ','a',' ','a',' ','a',' ','a','!','b',' ','b',' ','b',' ','b',' ','b',' ','b',' ','b',' '};
	char padre2_2 [29] = {'c',' ','c',' ','c',' ','c','!','d',' ','d',' ','d',' ','d',' ','d',' ','d','!','e',' ','e',' ','e',' ','e',' '};
	char *hijo1_2 = (char *)malloc(sizeof(char)*29);
	char *hijo2_2 = (char *)malloc(sizeof(char)*29);
	srand (time(NULL));
	llenado(&padre1);
	llenado(&padre2);
	int op = 0;
	while(op != 5)
	{
	    system("CLS");
        cout << " Seleccione una opcion" <<'\n';
		cout << "1) Cruza por un punto" << endl;
		cout << "2) Cruza de dos punto" << endl;
		cout << "3) Cruza uniforme" << endl;
		cout << "4) Cruza acentuada" << endl;
		cout << "#:   ";
		cin >> op;
		switch(op){
			case 1:
			    system("CLS");
				cout << "Padre 1: ";
				std::cout << " " << padre1 << '\n';
				cout << "Padre 2: ";
				std::cout << " " << padre2 << '\n';
				cout << endl;
				cout << "Punto de cruza: 4" << endl;
				hijo1 = UnPunto(padre1, padre2, 5);
				hijo2 = UnPunto(padre2, padre1, 5);
				cout << "Hijo 1: ";
				std::cout << " " << hijo1 << '\n';
				cout << "Hijo 2: ";
				std::cout << " " << hijo2 << '\n';
				cout << endl;
				system("PAUSE");
			break;
			case 2:
			    system("CLS");
				cout << "Padre 1: ";
				std::cout << " " << padre1 << '\n';
				cout << "Padre 2: ";
				std::cout << " " << padre2 << '\n';
				cout << endl;
				cout << "Puntos de cruza:" << endl;
				hijo1 = DosPunto(padre1, padre2);
				hijo2 = DosPunto(padre2, padre1);
				cout << "Hijo 1: ";
				std::cout << " " << hijo1 << '\n';
				cout << "Hijo 2: ";
				std::cout << " " << hijo2 << '\n';
				cout << endl;
				system("PAUSE");
			break;
			case 3:
			    system("CLS");
				cout << "Padre 1: ";
				std::cout << " " << padre1 << '\n';
				cout << "Padre 2: ";
				std::cout << " " << padre2 << '\n';
				cout << endl;
				cout << "Mascara definida: 1001010110 " << endl;
				hijo1 = Uniforme(padre1, padre2);
				hijo2 = Uniforme(padre2, padre1);
				cout << "Hijo 1: ";
				std::cout << " " << hijo1 << '\n';
				cout << "Hijo 2: ";
				std::cout << " " << hijo2 << '\n';
				cout << endl;
				system("PAUSE");
			break;
			case 4:
			    system("CLS");
				cout << "Padre 1: ";
				cout << padre1_2 << endl;
				cout << "Padre 2: ";
				cout << padre2_2 << endl;
				hijo1_2 = cruzaAcentuada(padre1_2,padre2_2);
				hijo2_2 = cruzaAcentuada(padre2_2,padre1_2);
				cout << endl;
				cout << "Hijo 1: ";
				cout << hijo1_2 << endl;
				cout << "Hijo 2: ";
				cout << hijo2_2 << endl;
				cout << endl;
				system("PAUSE");
			break;
		 	default:
		 		cout << "Opcion incorrecta " << endl;
		}

	}

	return 0;
}

void llenado(bitset<10> *set){
		*set = rand() % 1023;
}

bitset<10> UnPunto(bitset<10> &padre1, bitset<10> &padre2, int punto_cruza) {
    bitset<10> aux = padre1;
    for (int i = 0; i <= punto_cruza; i++)
    	aux.set(punto_cruza - i, padre2[punto_cruza - i]);
    return aux;
}

bitset<10> DosPunto(bitset<10> &padre1, bitset<10> &padre2){
    bitset<10> aux1 = padre1;
    bitset<10> aux2 = padre2;
    bitset<10> r1;
    bitset<10> r2;
    bitset<10> res3;
    bitset<10> result;
    bitset<10> mascara1 (string("1100000000"));
    bitset<10> mascara2 (string("0011110000"));
    bitset<10> mask3 (string("0000001111"));
    r1 = aux1 & mascara1;
    r2 = aux2 & mascara2;
    res3 = aux1 & mask3;
    int total = r1.to_ulong() + r2.to_ulong() + res3.to_ulong();
    result = total;
    return result;
}

bitset<10> Uniforme(bitset<10> &padre1, bitset<10> &padre2){

	bitset<10> aux1 = padre1;
    bitset<10> aux2 = padre2;
    bitset<10> r1;
    bitset<10> r2;
    bitset<10> mascara1 (string("1001010110"));
    bitset<10> mascara2 (string("0110101001"));
    r1 = aux1 & mascara1;
    r2 = aux2 & mascara2;
    bitset<10> result;
    int total = r1.to_ulong() + r2.to_ulong();
    result = total;
    return result;
}

char * cruzaAcentuada(char * padre1, char * padre2){
	int band = 0;
	int i = 0;
	char *aux = (char *)malloc(sizeof(char)*29);
	while(i <= 29){
		if (band == 0)
		{
			if(*padre1 != '!' && *padre2 != '!'){
				aux[i] = *padre1;
			}
			else{
				aux[i] = ' ';
				band = 1;
			}
			padre1++;
			padre2++;
		}
		else
		{
			if(*padre1 != '!' && *padre2 != '!'){
				aux[i] = *padre2;
			}
			else{
				aux[i] = ' ';
				band = 0;
			}
			padre1++;
			padre2++;
		}
		i++;
	}

	return aux;
}
