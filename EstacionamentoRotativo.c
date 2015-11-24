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

int estacione(char placa[], int hora);
float SairDoEstacionamento(char placa[], char horaDaSaida[]);
int vaga(char placa[]);
int pegaHora(char hora[]);
int proximaPosicaoLivreNoRegistro();
int placaNoRelatorio(char placa[]);
	
	char relatorioPlacas[100][8];
	int relatorioTempo[100];
	float relatorioTotal;
	
	int vagas[20];
	int carros[20][8];
    int horaEntrada[20];

	const float PrecoDoMinuto = 0.07; // 4,20 a Hora
    
int main(int argc, char **argv)
{
	char resposta;
	do{
	resposta = '0';
	char placa[8] = {0,0,0,0,0};
    char hora[5] = {0,0,0,0,0};    	
	printf("Olá seja bem vindo!!");
	printf("\nDigite 1 para: Estacionar um carro");
	printf("\nDigite 2 para: Retirar um carro do Estacionamento");
	printf("\nDigite 3 para: Fechar o Estacionamento");
	scanf(" %c", resposta);
	
	
	if(resposta = '1'){
        printf("Digite sua placa por favor\n");
		scanf(" %s", placa);
		printf("Digite que horas são no formato 24 Hrs");
		scanf(" %s", hora);
		
		if(estacione(placa, pegaHora(hora)) < 20){
            
  		printf("Estacione na vaga: %d", estacione(placa, pegaHora(hora)));
         }else{
          printf("Não temos vagas volte mais tarde");
        }		
		
		
	}
	if(resposta = '2'){
		printf("Digite sua placa por favor\n");
		scanf(" %s", placa);
		printf("Digite que horas são no formato 24 Hrs");
		scanf(" %s", hora);
		printf("Pelo tempo que voce ficou deverá pagar: %f", SairDoEstacionamento(placa, hora));
		
	}
	system("cls");
	}while(resposta != '3');

}

int estacione(char placa[], int hora){
	int cont = 0;
	int vagaDisponivel, x;
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
		cont+= 1;			
	}while(achou == 0 && cont == 19);
if(cont == 19 && achou == 0) vagaDisponivel = 20;	
	
 return vagaDisponivel;	
}

float SairDoEstacionamento(char placa[], char horaDaSaida[]){
	
	int tempoEstacionado;
	float valorAPagar;
	int local = vaga(placa);
	vagas[local] = 0;
	for(int cont = 0; cont < 8; cont ++){
		carros[local][cont] = 0;
	}
	tempoEstacionado = horaEntrada[local] - pegaHora(horaDaSaida);
	if(tempoEstacionado < 60){
		valorAPagar = PrecoDoMinuto * tempoEstacionado;
	}else{
		int HorasEstacionado = tempoEstacionado/60;
		valorAPagar = (PrecoDoMinuto*60) * (HorasEstacionado + 1);
	}
	
	int posicao = placaNoRelatorio(placa);
	for(int x = 0; x < 8; x++) relatorioPlacas[posicao][x] = placa[x];
	relatorioTempo[posicao] = tempoEstacionado;
	relatorioTotal += valorAPagar;

	return valorAPagar;
}

int vaga(char placa[]){
	int vagaOndeEsta;
	int i = 0;
	int x = 0;
	
	for(i = 0; i < 20; i++){
		for(int k = 0; k < 8; k++){
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
	
	for(i = 0; i < 100; i++){
		for(int k = 0; k < 8; k++){
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

int pegaHora(char hora[]){
    int H;
    int M;
	
if(hora[3] == '\0'){
    H = (hora[0]*10)+hora[1];
    M = (hora[2]*10)+hora[3];
}else{
    H = hora[0];
    M = (hora[1]*10)+hora[2];
}
    return (H*60)+M;
}

void fecharEstacionamento(){
	system("cls");
	
	
}

int proximaPosicaoLivreNoRegistro(){
	int x;
	for(x = 0; relatorioTempo != 0; x++);
	return x;
}