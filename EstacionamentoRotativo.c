#include <stdio.h>
#include <ctype.h>

int estacione(char placa[], char hora[]);
double SairDoEstacionamento(char placa[], char horaDaSaida[]);
int vaga(char placa[]);
int pegaHora(char hora[]);
int proximaPosicaoLivreNoRegistro();
int ondeEstaEstacionado(char placa[]);
void fecharEstacionamento();
void exibirRelatorio();
	
	char relatorioPlacas[100][8];
	int relatorioTempo[100];
	double relatorioTotal;
	
	int vagas[20];
	int carros[20][8];
    int horaEntrada[20];

	double PrecoDoMinuto = 0.07; // 4,20 a Hora
    
void main(int argc, char **argv)
{
	int resposta;
	resposta = 0;
	char placa[8];
    char hora[5];    	
	while(resposta != 3){
	printf("\nOlá seja bem vindo!!");
	printf("\nDigite 1 para: Estacionar um carro");
	printf("\nDigite 2 para: Retirar um carro do Estacionamento");
	printf("\nDigite 3 para: Fechar o Estacionamento");
	scanf("%i", &resposta);
	
		if(resposta == 1){
			printf("Digite sua placa por favor\n");
			scanf("%s", placa);
			printf("Digite que horas são no formato 24 Hrs\n");
			scanf("%s", hora);

			if(estacione(placa, hora) != 20){
			printf("\nEstacione na vaga: %d", estacione(placa, hora));
			 }else{
			  printf("\nNão temos vagas volte mais tarde");
			}		
		}
		if(resposta == 2){
			printf("Digite sua placa por favor\n");
			scanf(" %s", placa);
			printf("Digite que horas são no formato 24 Hrs");
			scanf(" %s", hora);
			printf("Pelo tempo que voce ficou deverá pagar: %lf", SairDoEstacionamento(placa, hora));
			
		}
		if(resposta == 4){
			printf("TESTE");
			printf("placa");
			scanf(" %s", placa);
			printf("Na vaga: %d", ondeEstaEstacionado(placa));
		}
		
	}
	fecharEstacionamento();	
}

int estacione(char placa[], char hora[]){
	int cont = 0;
	int vagaDisponivel, x;
	int achou = 0;
	
	while(achou == 0 && cont < 20){	
		if(vagas[cont] == 0){
			achou = 1;
			vagaDisponivel = cont;
			vagas[cont] = 1;
			for(x = 0; x < 8; x++){
				carros[cont][x] = placa[x];
			}
			horaEntrada[cont] = pegaHora(hora);
		}
		cont+= 1;			
	}
if(cont == 20 && achou == 0) vagaDisponivel = 20;	
	
 return vagaDisponivel;	
}

double SairDoEstacionamento(char placa[], char horaDaSaida[]){
	
	int tempoEstacionado;
	double valorAPagar;
	int local = vaga(placa);
	int posicao;
	vagas[local] = 0;
	
	tempoEstacionado = pegaHora(horaDaSaida) - horaEntrada[local];
    printf("Tempo estacionado %d", tempoEstacionado);
	printf("Entrada %d", horaEntrada[local]);
	printf("Saida %d", pegaHora(horaDaSaida));
	printf("placa no relatorio %d", ondeEstaEstacionado(placa));
	if(tempoEstacionado <= 60){
		valorAPagar = PrecoDoMinuto * tempoEstacionado;
        printf("\nValor 1 %.2f", valorAPagar);
	}else{
		valorAPagar = (PrecoDoMinuto*60) * (tempoEstacionado/60);
	}
	int cont;
	int x;
	for(cont = 0; cont < 8; cont++){
		carros[local][cont] = 0;
	}
	posicao = proximaPosicaoLivreNoRegistro();
	for(x = 0; x < 8; x++){
        relatorioPlacas[posicao][x] = placa[x];
    }
	relatorioTempo[posicao] = tempoEstacionado;
	relatorioTotal = relatorioTotal + valorAPagar;
	return valorAPagar;
}

int vaga(char placa[]){
	int vagaOndeEsta;
	int i = 0;
	int x = 0;
	int k;
	for(i = 0; i < 20; i++){
		for(k = 0; k < 8; k++){
			if(placa[x] == carros[i][x] && placa[x] != '\0' && carros[i][x] != '\0') x++;
		}
		if(placa[x+1] == '\0' && carros[i][x+1] == '\0'){
			vagaOndeEsta = i;
		}else{
			x = 0;
		}			
	}
	printf("%d", vagaOndeEsta);
 return vagaOndeEsta;	
}

int ondeEstaEstacionado(char placa[]){
	int vagaEmQueEsta;
	int i = 0;
	int x = 0;
	int k = 0;
	int achou;
	for(i = 0; achou = 0 && i < 20; i++){
		for( k = 0; k < 8; k++){
			while(placa[k] == carros[i][k] && placa[k] != '\0' && carros[i][k] != '\0') x++;
			printf("I: %d K: %d X: %d", i, k, x);
		}
		if(placa[k] == '\0' && carros[i][k] == '\0' && x == 8){
			achou = 1;
			vagaEmQueEsta = i;			
			printf("Vaga em que está: %d", vagaEmQueEsta);
		}else{
			x = 0;
		}
	}
	return vagaEmQueEsta;	
}

int pegaHora(char hora[]){
   int H, M, saida;
	
if(hora[4] == '\0'){
    H = (hora[0] - 48) * 10;
	H = H + (hora[1] - 48);
	M = (hora[2] - 48 )*10;
	M = M + (hora[3] - 48);
	}
	else
	{
	H = hora[0] - 48;
	M = (hora[1] - 48)*10;
	M = M + (hora[2] - 48);
	}
	saida = (H*60)+ M;
	return saida;
}

int proximaPosicaoLivreNoRegistro(){
	int x;
	for(x = 0; relatorioTempo != 0; x++);
	return x;
}

void fecharEstacionamento(){
    exibirRelatorio();
}

void exibirRelatorio(){
    int x, y;
    for(x = 0; x < 100; x++){
        printf(" Placa: ");
        for(y = 0; y < 8; y++){
            printf("%c", relatorioPlacas[x][y]);
        }
        printf("   Tempo: %ld\n\n", relatorioTempo[x]);        
    }
    printf("Total de lucros do dia: %f", relatorioTotal);
}
