#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

char basico[] = "basico"; //0
char compacto[] = "compacto"; //1
char luxo[] = "luxo"; //2
char minivan[] = "minivan"; //3
char utilitario[] = "utilitario"; //4

int verificatipo (char tipo[11]);

void verificalocacoes (int coluna1, int coluna2, int coluna3, int coluna4, int coluna5);
void verificaluxo (int locadora[5][10]);
void verificaclientes (int pagamento [20][2]);
void verificamenoslocado (int locadora[5][10], int pagamento [20][2]);

int main () {
		int locadora [5][10] = {0};
		int pagamento [20][2] = {0};
		int i, j;
		int num_loc;
		int cont = 0;
		int coluna1 = 0, coluna2 = 0, coluna3 = 0, coluna4 = 0, coluna5 = 0;
		int placa;
		int placa2;
		int tam;
		int verf;
		char tipo [11];
		int tipo_n;
		int cod;
		int num_pag;
		int cont2 = 0;
		int carrosluxo [10] = {0};

		printf ("Digite a quantidade de locacoes: ");
		scanf("%d", &num_loc);

		while (cont < num_loc) {
				printf("\nDigite o tipo de carro: ");
				scanf("%s", &tipo);
				printf ("\nDigite a placa do carro: ");
				scanf("%d", &placa);

				tipo_n = verificatipo(tipo);

				if (tipo_n == 0){
						locadora [0][coluna1] = placa;
						coluna1++;
				} else if (tipo_n == 1){
						locadora [1][coluna2] = placa;
						coluna2++;
				} else if (tipo_n == 2){
						locadora [2][coluna3] = placa;
						coluna3++;
				} else if (tipo_n == 3){
						locadora [3][coluna4] = placa;
						coluna4++;
				} else if (tipo_n == 4){
						locadora [4][coluna5] = placa;
						coluna5++;
				}
				system ("cls");
				cont++;
		}

		printf ("\nDigite o numero de pagamentos: ");
		scanf("%d", &num_pag);

		i=0;

		while (cont2 < num_pag){
				printf ("\nDigite a placa do carro: ");
				scanf ("%d", &pagamento[i][0]);		//placa
				printf ("\nDigite o codigo do cliente: ");
				scanf ("%d", &pagamento[i][1]);		//codigo

				i++;
				system ("cls");
				cont2++;
		}

		verificalocacoes (coluna1, coluna2, coluna3, coluna4, coluna5);
		verificaluxo(locadora);
		verificaclientes(pagamento);
		verificamenoslocado(locadora, pagamento);

		return 0;
}


int verificatipo (char tipo[11]){
		int verif0 = 1, verif1 = 1, verif2 = 1, verif3 = 1, verif4 = 1;
		int i;

		for (i=0; i < 11; i++){
				tipo[i] = tolower(tipo[i]);
  	}

		verif0 = strcmp(tipo, basico);
		verif1 = strcmp(tipo, compacto);
		verif2 = strcmp(tipo, luxo);
		verif3 = strcmp(tipo, minivan);
		verif4 = strcmp(tipo, utilitario);

		if (verif0 == 0){
				return 0;
		} else if (verif1 == 0){
				return 1;
		} else if (verif2 == 0){
				return 2;
		} else if (verif3 == 0){
				return 3;
		} else if (verif4 == 0){
				return 4;
		}
		return 0;
}

void verificalocacoes (int coluna1, int coluna2, int coluna3, int coluna4, int coluna5){
		printf ("--------- Locacoes de cada tipo de carro --------------\n");
		printf("Basico: %d\n", coluna1);
		printf("Compacto: %d\n", coluna2);
		printf("Luxo: %d\n", coluna3);
		printf("Minivan: %d\n", coluna4);
		printf("Utilitario: %d\n", coluna5);
}

void verificaluxo (int locadora[5][10]){
		int i,j, o;
		int aux =0 ;
		int k =0;
		int igual = 0;
		int salvaplaca[10] = {0};
		int cont = 0;

		for (i=0; i < 10; i++){
				for (j=0; j < 10; j++){
						if (locadora[2][i] == locadora [2][j]){
								aux++;
						}
				}
				if (igual == locadora[2][i]){
						continue;
				}
				if (aux > 5){
						salvaplaca[k] = locadora[2][i];
						igual = locadora[2][i];
						k++;
				}
				aux = 0;
		}

		printf ("\n--------- Carro de luxo mais locado -------------------\n");

		for (o=0; o < 10; o++){
				if (salvaplaca[o] != 0){
						printf("\nPlaca do carro: %d\n", salvaplaca[o]);
						cont++;
				}
		}
		if (cont == 0){
				printf("\nNao ha mais de cinco carros de luxo locados\n");
		}
}

void verificaclientes (int pagamento [20][2]){
		int i, j;
		int cont = 0;
		int maior = 0;
		int cliente;

		for (i=0; i < 20; i++){
				for (j=0; j < 20; j++){
						if(pagamento[i][1] == pagamento[j][1] && pagamento[i][1] != 0){
								cont++;
						}
				}
				if (cont > maior){
						maior = cont;
						cliente = pagamento[i][1];
				}
				cont = 0;
		}

		printf ("\n--------- Cliente com mais locacoes -------------------\n");
		printf("\nCodigo do cliente: %d\n", cliente);
}

void verificamenoslocado (int locadora[5][10], int pagamento [20][2]){
		int i, j;
		int aux = 0;
		int menor = 100;
		int menorplaca = 0;
		int k = 0;
		int tipo;

		for (i=0; i < 20; i++){
				for (j=0; j < 20; j++){
						if(pagamento[i][0]== pagamento[j][0] && pagamento[i][0] != 0){
								aux++;
							}
				}
				if (aux !=0 && aux < menor){
						menor = aux;
						menorplaca = pagamento[i][0];
				}
				aux = 0;
		}

		for (i=0; i < 5; i++){
				for (j=0; j < 10; j++){
						if (locadora[i][j] == menorplaca){
								tipo = i;
								break;
						}
				}
		}

		printf("\n--------- Carro menos locado --------------------------\n");

		if(tipo == 0){
				printf("Tipo: %s\tPlaca: %d\n", basico, menorplaca);
		} else if (tipo == 1){
				printf("Tipo: %s\tPlaca: %d\n", compacto, menorplaca);
		} else if (tipo == 2){
				printf("Tipo: %s\tPlaca: %d\n", luxo, menorplaca);
		} else if (tipo == 3){
				printf("Tipo: %s\tPlaca: %d\n", minivan, menorplaca);
		} else if (tipo == 4){
				printf("Tipo: %s\tPlaca: %d\n", utilitario, menorplaca);
		}
}
