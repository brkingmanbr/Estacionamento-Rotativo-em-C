#include <stdio.h>
#include <ctype.h>

int estacione(char placa[], int hora);
int vaga(char placa[]);
int pegaHora(char hora[]);
	
	int vagas[20];
	int carros[20][8];
    int horaEntrada[20];
    
int main(int argc, char **argv)
{
	char resposta;
	char placa[8];
	float valor_a_pagar;
    char horaSaida[5];
    char hora[5];    	
	printf("Olá seja bem vindo!!");
	printf("\nDigite 1 para: Estacionar");
	printf("\nDigite 2 para: Sair do estacionamento");
	scanf(" %c", resposta);
	
	
	if(resposta = '1'){
        printf("Digite sua placa por favor\n");
		scanf(" %s", placa);
		printf("Digite que horas são no formato 24 Hrs");
		scanf(" %s", hora);
		
		if(estacione(placa, pegahora(hora)) < 20){
            int x = estacione(placa, pegahora(hora));
  		printf("Estacione na vaga: %d", x);
         }else{
          printf("Não temos vagas volte mais tarde");
        }		
		
		
	}
	if(resposta = '2'){
		printf("Digite sua placa por favor\n");
		scanf(" %s", placa);
		
	}

}

int estacione(char placa[], int hora){
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
			horaEntrada[cont] = hora;
		}
		cont++;			
	}while(achou = 0 || cont = 19);
if(cont = 19 && achou = 0) vagaDisponivel = 20;	
	
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

int pegaHora(char hora[]){
    int hora;
    int minutos;
    int cont;
if(hora[] = '\0'){
    int hora =  concat(hora[0],hora[1]);
    int minutos =  concat(hora[2],hora[3]);
}else{
    int hora =  concat(hora[0]);
    int minutos =  concat(hora[1],hora[2]);
}
    return (hora*60)+minutos;
}