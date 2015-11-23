/*
4. Estacionamento controle de vagas
 
Crie um programa para controle de vagas de estacionamento 
rotativo que contém 20 vagas.

O valor a ser pago por cada clientes será contabilizado baseando
na quantidade de tempo em que o veículo ficou estacionado. 

Preocupe-se em não permitir que um carro estacione em uma vaga já ocupado.

Para carros que ficarem estacionados por um período menor que 1 hora
deverá ser cobrado o tempo fracionado.
 
No final do dia será importante um relatório com as placas e quantidade
de tempo que cada veículo manteve estacionado  e o total de valor faturado no dia.
*/

#include <stdio.h>
#include <ctype.h>

int estacione(char placa[]);
int vaga(char placa[]);
	
	int vagas[20];
	int carros[20][8];
	
int main(int argc, char **argv)
{
	char resposta;
	char placa[8];
	float valor_a_pagar;
	
	printf("Olá seja bem vindo!!");
	printf("\nDigite 1 para: Estacionar");
	printf("\nDigite 2 para: Sair do estacionamento");
	scanf(" %c", resposta);
	
	
	if(resposta = '1'){
		printf("Digite sua placa por favor\n");
		scanf(" %s", placa);
		printf("Estacione na vaga: %d", estacione(placa));
		
	}
	if(resposta = '2'){
		printf("Digite sua placa por favor\n");
		scanf(" %s", placa);
		
	}

}

int estacione(char placa[]){
	int cont, vagaDisponivel, x, i;
	int achou = 0;
	do{
		if(vagas[cont] = 0){
			achou = 1;
			vagaDisponivel = cont;
			vagas[cont] = 1;
			for(x = 0; x < 8; x++){
				carros[cont][x] = placa[x];
			}
		}
		cont++;			
	}while(achou = 0);	
 return vagaDisponivel;	
}

int vaga(char placa[]){
	int vagaOndeEsta;
	int i = 0;
	int x = 0;
	
	for(i = 0; i < 20; i++){
		while(placa[x] == carros[i][x] && placa[x] != '\0' && carros[i][x] != '\0'){
			x++;
		}
		if(placa[x] == '\0' && carros[i][x] == '\0'){
			vagaOndeEsta = i;
		}
			
	}
 return vagaOndeEsta;	
}

