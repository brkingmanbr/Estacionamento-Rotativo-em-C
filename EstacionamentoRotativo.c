/*
+4. Estacionamento controle de vagas
+ 
+Crie um programa para controle de vagas de estacionamento 
+rotativo que contém 20 vagas.
+
+O valor a ser pago por cada clientes será contabilizado baseando
+na quantidade de tempo em que o veículo ficou estacionado. 
+
+Preocupe-se em não permitir que um carro estacione em uma vaga já ocupado.
+
+Para carros que ficarem estacionados por um período menor que 1 hora
+deverá ser cobrado o tempo fracionado.
+ 
+No final do dia será importante um relatório com as placas e quantidade
+de tempo que cada veículo manteve estacionado  e o total de valor faturado no dia.
+*/
#include <stdio.h>
#include <ctype.h>

int estacione(char placa[], long int hora);
float SairDoEstacionamento(char placa[], char horaDaSaida[]);
int vaga(char placa[]);
long int pegaHora(char hora[]);
int proximaPosicaoLivreNoRegistro();
int placaNoRelatorio(char placa[]);
void fecharEstacionamento();

	
	char relatorioPlacas[100][8];
	long int relatorioTempo[100];
	float relatorioTotal;
	
	int vagas[20];
	int carros[20][8];
    long int horaEntrada[20];

	const float PrecoDoMinuto = 0.07; // 4,20 a Hora
    
int main(int argc, char **argv)
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
			scanf("%s", &placa);
			printf("Digite que horas são no formato 24 Hrs\n");
			scanf("%s", hora);
			printf("%d", pegaHora(hora));
			if(estacione(placa, pegaHora(hora)) != 20){
				
			printf("\nEstacione na vaga: %d", estacione(placa, pegaHora(hora)));
			 }else{
			  printf("\nNão temos vagas volte mais tarde");
			}		
			
			
		}
		if(resposta == 2){
			printf("Digite sua placa por favor\n");
			scanf(" %s", &placa);
			printf("Digite que horas são no formato 24 Hrs");
			scanf(" %s", hora);
			printf("Pelo tempo que voce ficou deverá pagar: %f", SairDoEstacionamento(placa, hora));
			
		}
	}
	printf("Foi  Rodou");
	//caso a resposta seja = 3
	fecharEstacionamento();	
	
	return 0;
}

int estacione(char placa[], long int hora){
	int cont = 0;
	int vagaDisponivel, x;
	int achou = 0;
	do{	
		if(vagas[cont] == 0){
			achou = 1;
			vagaDisponivel = cont;
			vagas[cont] = 1;
			for(x = 0; x < 8; x++){
				carros[cont][x] = placa[x];
			}
			horaEntrada[cont] = hora;
		}
		cont+= 1;			
	}while(achou == 0 && cont < 20);
if(cont == 20 && achou == 0) vagaDisponivel = 20;	
	
 return vagaDisponivel;	
}

float SairDoEstacionamento(char placa[], char horaDaSaida[]){
	
	int tempoEstacionado;
	float valorAPagar;
	long int HorasEstacionado;
	int local = vaga(placa);
	vagas[local] = 0;
	int cont;
	for(cont = 0; cont < 8; cont++){
		carros[local][cont] = 0;
	}
	tempoEstacionado = horaEntrada[local] - pegaHora(horaDaSaida);
	if(tempoEstacionado < 60){
		valorAPagar = PrecoDoMinuto * tempoEstacionado;
	}else{
		HorasEstacionado = tempoEstacionado/60;
		valorAPagar = (PrecoDoMinuto*60) * (HorasEstacionado + 1);
	}
	int x;
	int posicao = placaNoRelatorio(placa);
	for(x = 0; x < 8; x++) relatorioPlacas[posicao][x] = placa[x];
	relatorioTempo[posicao] = tempoEstacionado;
	relatorioTotal += valorAPagar;

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
		if(placa[x] == '\0' && carros[i][x] == '\0'){
			vagaOndeEsta = i;
		}else{
			x = 0;
		}
			
	}		
 return vagaOndeEsta;	
}

int placaNoRelatorio(char placa[]){
	int OndeEstaNoRelatorio;
	int i = 0;
	int x = 0;
	int k = 0;
	for(i = 0; i < 100; i++){
		for( k = 0; k < 8; k++){
			if(placa[x] == relatorioPlacas[i][x] && placa[x] != '\0' && relatorioPlacas[i][x] != '\0') x++;
		}
		if(placa[x] == '\0' && relatorioPlacas[i][x] == '\0'){
			OndeEstaNoRelatorio = i;
		}else{
			x = 0;
		}
			
	}

	if(i == 100 && OndeEstaNoRelatorio == 0) OndeEstaNoRelatorio = proximaPosicaoLivreNoRegistro();
	return OndeEstaNoRelatorio;	
}

long int pegaHora(char hora[]){
    long int H;
    long int M;
	
	printf("Antes de tudo H = %ld  M = %ld hora[] = %s", H, M, hora);
if(hora[3] == '\0'){
	H = hora[0]*10;
	printf("H = %ld ",H);
	H = H + hora[1];
	printf("H = %ld ",H);
	M = hora[2]*10;
	printf("M = %ld ",M);
	M = M + hora[3];
	printf("M = %ld ",M);
	}
	else
	{
	H = hora[0];
	printf("H = %ld ",H);
	M = hora[1]*10;
	printf("M = %ld ",M);
	M = M + hora[2];
	printf("M = %ld ",M);
	}
	
	printf("H = %ld  M = %ld", H, M);
	return (H*60)+M;
}

int proximaPosicaoLivreNoRegistro(){
	int x;
	for(x = 0; relatorioTempo != 0; x++);
	return x;
}

void fecharEstacionamento(){
		printf("Foi  Rodou msm");
		}
