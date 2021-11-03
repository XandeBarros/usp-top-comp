#include"vizinhos.hpp"

using namespace std;
/*
A ideia pensada para o solução desse problema é a seguinte:
A Matriz B em determinadas posições acessa locais de memória que a Matriz A não existe e nesses pontos eles devem ser nulos, 
para evitar que a Matriz B termine usando algum lixo que tenha nesses espaços a ideia é alocar uma Matriz maior 
(duas linhas e duas colunas a mais) no qual as bordas serão nulas e o meio será o espaço útil 21 x 21.
0 0 0 ... 0 0 0
0 1 2 ... 2 1 0
.   espaço    .
.  útil das   .
.   matrizes  .
0 1 2 ... 2 1 0
0 0 0 ... 0 0 0

Dessa forma quando a Matriz B estiver no seu espaço útil 1 x 1 ela não terá problemas com possíveis lixos na memória.
Os espaços de memória também foram alocados dinamicamente usando a própria sintaxe de alocação dinâmica do C++ usando a palavra
chave new e ponteiros.
Devido a esse fato também foi criado uma função membro que desaloca essa memória, tanto da Matriz A como da Matriz B.

Usando os paradigmas da Programação Orientada a Objetos, os atributos só podem ser acessados e editados por meio de
getters e setters. Portando seguindo os passos Definir Matriz A -> Mostrar Matriz A -> Definir Matriz B -> Mostrar Matriz B 
é a melhor forma de implementar o código. Lembrando de ao final do código também desalocar a memória.

Para a execução do código portanto deve ser chamado o método setMatrizA(arg) passando como argumento a matriz 21 x 21 
que o senhor citou que já possui, por exemplo, vizinho.setMatrizA(MatrizA), caso queira ver se tudo ocorreu bem e os 
valores estão de fato lá pode-se então usar o método getMatrizA() e ver elementos da Matriz A da Classe. 
Então deve ser chamado método setMatrizB() que vai calcular a matriz B com os devidos pesos e para ver o resultado 
basta chamar o metédo getMatrizB() que irá mostrar a Matriz B no terminal e por fim antes de fechar o código use o 
método desalocarMemoria() para desalocar a memória usada na Matriz A e B na Classe.
*/

Vizinhos::Vizinhos() { // Construtor da Classe, apenas define o tamanho da memória a ser alocada, 23 x 23 onde as bordas serão nulas
  linhas = colunas = 23;
}

int Vizinhos::setMatrizA(int matriz[21][21]) {// Aloca a Memória da Matriz A da Classe e copia a Matriz A da sua main para a classe;
  matrizA = new int*[colunas]();
  for(int i = 0; i < colunas; i++) {
    matrizA[i] = new int[linhas]();
  }

  for(int col = 1; col < colunas - 1; col++) {
    for(int lin = 1; lin < linhas - 1; lin++) {
      matrizA[col][lin] = matriz[col - 1][lin - 1];
    }
  }

  return 1;
}

int Vizinhos::getMatrizA() { // Mostra a Matriz A da Classe;
  cout << "Matriz A: " << endl << endl;
  for(int col = 1; col < colunas - 1; col++) {
    for(int lin = 1; lin < linhas - 1; lin++) {
      cout << matrizA[col][lin] << " ";
    }
    cout << endl;
  }
  cout << endl << endl;
  return 1;
}

int Vizinhos::setMatrizB() { // Aloca a Memória da Matriz B e a define usando os pesos de cada elemento vizinho definido no PDF;
  matrizB = new float*[colunas];
  for(int i = 0; i < colunas; i++) {
    matrizB[i] = new float[linhas];
  }

  for(int col = 1; col < colunas - 1; col++) {
    for(int lin = 1; lin < linhas - 1; lin++) { 
      matrizB[col][lin] = (0.1 * matrizA[col - 1][lin - 1]) + (0.15 * matrizA[col][lin - 1]) + (0.1 * matrizA[col + 1][lin - 1]) + (0.15 * matrizA[col - 1][lin]) + (0.15 * matrizA[col + 1][lin]) + (0.1 * matrizA[col - 1][lin + 1]) + (0.15 * matrizA[col][lin + 1]) + (0.1 * matrizA[col + 1][lin + 1]);
    }
  }

  return 0;
}

int Vizinhos::getMatrizB() { // Mostra a Matriz B;
  cout << "Matriz B: " << endl << endl;
  for(int col = 1; col < colunas - 1; col++) {
    for(int lin = 1; lin < linhas - 1; lin++) {
      cout << fixed << setprecision(2) << (matrizB[col][lin]) << " | ";
    }
    cout << endl;
  }
  cout << endl << endl;
  return 1;
}

int Vizinhos::desalocarMemoria() { // Desaloca a Matriz A e a Matriz B;
  for(int i = 0; i < linhas; i++) {
    delete [] matrizA[i], matrizB[i];
  }
  delete [] matrizA, matrizB;

  cout << "Memória desalocada com sucesso!" << endl;
  return 1;
}
