#include <iostream>
#include <string>
using namespace std;


// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor

int converteSensor(float medida, float min, float max){

    float sub = max - min;
    float sub2 = medida - min;
    float porcentagem = sub/sub2;

    std::cout << "A porcentagem correspondente: " << porcentagem;

}

int main(){
    cout << "Teste Ex 1" << endl;
	cout << converteSensor(100,100,400) << endl;
  //valor esperado: 0
  
	cout << converteSensor(400,100,400) << endl;
  //valor esperado: 1
  
	cout << converteSensor(250,100,400) << endl;
  //valor esperado: 0.5

    cout << converteSensor(80,50,90) << endl;
  //valor esperado: 0.75

    cout << converteSensor(625,250,1000) << endl;
  //valor esperado: 0.5

}

// 2 - Faça uma função que simule a leitura de um sensor lendo o 
// valor do teclado ao final a função retorna este valor

int leComando(){

    int zero_ou_um; 
    cin >> zero_ou_um; 
        
}

int main(){
 
    cout << "Digite o Comando (0 ou 1):";
	int cmd = leComando();
	cout << "Comando Recebido: " << cmd << endl;

}

// 3 - Faça uma função que armazena uma medida inteira qualquer 
// em um vetor fornecido. Note que como C não possui vetores 
// nativos da linguagem, lembre-se que você precisa passar o 
// valor máximo do vetor assim como a última posição preenchida
// Evite também que, por acidente, um valor seja escrito em 
// uma área de memória fora do vetor

int insereVetor(){
  
  int tamanho = 1;
  std::cout << "Insira o tamanho do vetor";
  std::cin >> tamanho;

  int arr[tamanho], i, elemento;
  std::cout << "Entre com os elementos";

  for(i=0; i<tamanho; i++){

    std::cin >> arr[i]; 

  }

  std::cout << "insira o ultimo elemento do array";
  std::cin >> elemento;

  arr[i] = elemento;

  std::cout << "Seu vetor: ";
  for(i=0; i<tamanho; i++){

    std::cout << arr[i] << " ";
  }

  std::cout << endl;

  return 0;

}

int main(){

  int start = 0;
  while(start == 0){
    cout << "Digite algum numero para começar";  
  }
  insereVetor();

}



// 4 - Faça uma função que recebe um vetor com 4 posições que contém 
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção 
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a 
// segunda é esta maior distância.

int maiorDist(int direta, int esquerda, int frente, int tras){
     
  int pos[4];
  pos[0] = direta;
  pos[1] = esquerda;
  pos[2] = frente;
  pos[3] = tras;

  if(pos[0] > pos[1] && pos[0] > pos[2] && pos[0] > pos[3]){
      std::cout << "Direta é maior distancia com " << direta;
  }

  if(pos[1] > pos[0] && pos[1] > pos[2] && pos[1] > pos[3]){
      std::cout << "Esquerda é maior distancia com " << esquerda;
  }

  if(pos[2] > pos[1] && pos[2] > pos[0] && pos[2] > pos[3]){
      std::cout << "A frente é maior distancia com " << frente;
  }

  if(pos[3] > pos[1] && pos[3] > pos[2] && pos[3] > pos[0]){
    std::cout << "Tras é maior distancia com " << tras;
  }
}

int main(){

  cout << maiorDist(100, 400, 300, 200); << endl;

  cout << maiorDist(25, 35, 45, 55); << endl;

  cout << maiorDist(4, 1, 300, 7); << endl;

}

// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e 
// retorna verdadeiro ou falso

boolean(){

  int boo;

  while(boo == 0) {

    std::cout << "Digite 1 para parar o mapeamento!";
    std::cin >> boo;
  }

  if(boo == 1){
    cout << "Mapeamento interrompido"
  }
  else{
    boo = 0;
  }

}

int main(){`

  cout << "Digite 0 para inciar o programa";
  cin >> boo;
  boolean();

}

// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 
//
//      Complete a função com a chamada das funções já criadas
int dirige(int *v,int maxv){
	int maxVetor = maxv;
	int *vetorMov = v;
	int posAtualVetor = 0;
	int dirigindo = 1;		
	while(dirigindo){		
		int medida = /// .. Chame a função de de leitura da medida para a "Direita"
		medida = converteSensor(medida,0,830);
		posAtualVetor = // Chame a função para armazenar a medida no vetor
        ///////////////////////////////////////////////////////////////////////////		
		// Repita as chamadas acima para a "Esquerda", "Frente", "Tras"
		// ................
		///////////////////////////////////////////////////////////////////////////
		dirigindo = leComando();		
	}
	return posAtualVetor;
}


// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
// na maior distância a cada movimento
void percorre(int *v,int tamPercorrido){		
	int *vetorMov = v;
	int maiorDir = 0;
	
	for(int i = 0; i< tamPercorrido; i+=4){
		char *direcao = direcaoMenorCaminho(&(vetorMov[i]),&maiorDir);
		printf("Movimentando para %s distancia = %i\n",direcao,maiorDir);
	}
}

int main(int argc, char** argv) {
	int maxVetor = 100;
	int vetorMov[maxVetor*4];
	int posAtualVet = 0;
	
	posAtualVet = dirige(vetorMov,maxVetor);
	percorre(vetorMov,posAtualVet);
	
	return 0;
}