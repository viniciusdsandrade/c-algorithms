#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <locale.h>
#include "global.h"

#define MAX_EXERCISES 11

int exercicio01(void) {
    /**
    1. Suponha que criamos uma estrutura para armazenar produtos de um supermercado:
<p>
    <p>  typedef struct Produto{
      <p>   char nome[80];
      <p>   double preco;
      <p>   int quantidade;
   <p>  }Produto;
<p>
   <p>  Implemente duas fun��es, uma que devolve o vetor ordenado por pre�os e outra que devolve
    o vetor ordenado pela quantidade de itens no estoque. Os prot�tipos s�o:
<p>
   <p>  void ordenaPreco(Produto vet[], int n);
   <p> void ordenaQuantidade(Produto vet[], int n);
     */

    printf("Digite a quantidade de produtos: ");
    int n;
    scanf("%d", &n);

    Produto *produtos = lerProdutos(n);

    ordenaPreco(produtos, n);
    printf("Produtos ordenados por pre?o:\n");
    imprimeProduto(produtos, n);

    ordenaQtd(produtos, n);
    printf("Produtos ordenados por quantidade:\n");
    imprimeProduto(produtos, n);

    return 0;
}

int exercicio02(void) {
    /**
     2. Suponha que criamos uma estrutura para armazenar Datas:
<p>
    <p>  typedef struct Data{
   <p>      int dia;
    <p>     int mes;
     <p>    int ano;
    <p> }Data;
     <p>

   <p>  Implemente um algoritmo que receba um vetor de Datas como par�metro e que retorne as datas em ordem cronol�gica.

    <p>  Prot�tipo da fun��o : void ordena(struct Data vet[], int tam);

    <p> Dica: Ordene o vetor separadamente por cada um dos campos.
    */

    printf("Digite a quantidade de datas: ");
    int n;
    scanf("%d", &n);

    Data datas[100];

    for (int i = 0; i < n; ++i) {
        printf("Digite os dados da %d� data:\n", i + 1);
        datas[i] = leData();
    }

    ordena(datas, 3);

    printf("Datas ordenadas:\n");
    for (int i = 0; i < n; ++i) {
        imprimeData(datas[i]);
    }

    return 0;
}

int exercicio03(void) {
    /**
    3. Suponha que criamos uma estrutura para armazenar dados de pessoas e uma outra estrutura
    para armazenar dados de v�rias pessoas como uma base de dados.
<p>
  <p>   typedef struct Pessoa{
   <p>      int rg;
  <p>       int cpf;
   <p>      char nome[80];
   <p>  }Pessoa;
<p>
   <p>  typedef struct Base{
   <p>     int armazenado; //Deve sempre corresponder ao n�mero de pessoas na base
   <p>      Pessoa pessoas[100];
   <p>  }Base;
<p>
   <p>  Crie fun��es para cada uma das opera��es abaixo:
<p>
   <p>  a) Cria base: esta fun��o devolve uma Base onde o campo armazenado ? inicializado
    com 0.
  <p>   Base cria_base();
<p>
  <p>   b) Inclui Pessoa: esta fun��o recebe como par�metro um dado do tipo Pessoa e o inclui
    na base (tamb�m passada por par�metro) caso j� n�o exista na base uma pessoa com
    o mesmo RG. A fun��o devolve 1 caso a incluso tenha ocorrido, devolve 0 caso a
    Base esteja cheia e devolve -1 caso j� exista uma pessoa com o RG informado.
  <p>   int insere_base(Pessoa p, Base base);
<p>
  <p>   c) Exclui Pessoa: esta fun��o recebe como par�metro um dado do tipo int representando
    o RG de uma pessoa e o exclui da base caso esteja presente. A fun��o devolve 1 caso a
    exclus�o tenha ocorrido, e devolve 0 caso n�o exista uma pessoa com o RG informado.
   <p>  int remove_base(int rg, Base base);
    */

    Base base = cria_base();
    Pessoa pessoas[100];

    printf("Digite a quantidade de pessoas: ");
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("Digite os dados da %d� pessoa:\n", i + 1);
        pessoas[i] = lePessoa();

    }
    //Corrigir

    return 0;
}

int exercicio04(void) {
    /*
     * 4. Suponha que criamos uma estrutura para armazenar dados de pessoas e uma outra estrutura
     *
     * typedef struct Pessoa{
     *     int rg;
     *     int cpf;
     *     char nome[80];
     * }Pessoa;
     *
     * Pessoa cadastro[100];
     *
     * Suponha que o vetor esteja ordenado em ordem crescente por valor de RG.
     * Implemente uma fun��o de busca por RG, que opera como a busca bin�ria, e que caso exista uma
     * pessoa no cadastro com o RG a ser buscado, devolve o �ndice deste no cadastro, e devolve -1
     * caso n�o exista uma pessoa com o RG a ser buscado
     * */

    Pessoa cadastro[100];
    int n;

    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("Digite os dados da %d� pessoa:\n", i + 1);
        cadastro[i] = lePessoa();
    }

    int rg;
    printf("Digite o RG a ser buscado: ");
    scanf("%d", &rg);

    int indice = buscaBinaria(cadastro, 3, rg);

    if (indice != -1) {
        printf("Pessoa encontrada no �ndice %d", indice);
    } else {
        printf("Pessoa n�o encontrada!");
    }
    return 0;
}

int exercicio05(void) {
/**  Refa�a as fun��es de busca sequencial e busca bin�ria vistas em aula assumindo que o
vetor possui chaves que podem aparecer repetidas. Neste caso, voc� deve retornar em um
outro vetor todas as posi��es onde a chave foi encontrada.

<p> Prot�tipo da fun��o:
<p> void busca(int vet[], int tam, int chave, int posicoes[], int n)

<p> Voc� deve devolver em posicoes[] as posi��es de vet que possuem a chave, e devolver
em n o n�mero de ocorr�ncias da chave.
<p> OBS: Na chamada desta fun��o, o vetor posi��es deve ter espa�o suficiente
<p>(por exemplo, tam) para guardar todas as poss�veis ocorr�ncias da chave.
 */

    int vet[10] = {1, 2, 3, 4, 5, 6, 7, 7, 7, 10};
    int posicoes[10];
    int n = 0;
    buscar(vet, 10, 7, posicoes, (int)* &n);

    printf("O n�mero 7 aparece %d vezes no vetor.\n", n);
    printf("As posi��es onde o n�mero 7 aparece s�o: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", posicoes[i]);
    }
    printf("\n");

    return 0;
}

int exercicio06(void) {

    /**
     6. O que ser? impresso pelo programa abaixo?
     <p>#include <stdio.h>
    <p> struct T{
     <p>    int x;
     <p>    int y;
    <p> };
     <p> typedef struct T T;
    <p> void f1(T *a);
    <p> void f2(int *b);
   <p>  int main(){
   <p>  T a, b, *c, *d;
    <p> c = &a;
   <p>  a.x = 2;
    <p> a.y = 4;
     <p>b.x = 2;
    <p> b.y = 2;
    <p> d = c;
   <p>  f1(d);
   <p>  b = *d;
   <p>      printf("x: %d --- y: %d\n",b.x,b.y);
   <p>  }
   <p>  void f1(T *a){
    <p>    f2(&(a->x));
    <p>    f2(&(a->y));
   <p>  }
   <p>  void f2(int *b){
   <p>     *b = 2*(*b);
  <p>  }
  <p>  */
    return 0;
}

int exercicio07(void) {

    /**
    struct Aluno leAluno ( ) ;
    <p> Esta fun��o faz a leitura dos dados de um registro Aluno e devolve o
    registro lido.
<p>
    <p>void imprimeAluno (struct Aluno a) ;
    <p>Esta fun��o recebe como par?metro um registro Aluno e imprime os
    dados do registro.
<p>
   <p> void listarTurma (struc t Aluno turma [ ], int n ) ;
   <p> Esta fun��o recebe como par�metros um vetor do tipo Aluno
   <p> representando uma turma, e tamb�m um inteiro n indicando o
   <p> tamanho do vetor. A fun��o imprime os dados de todos os alunos.
    */

    int numAlunos;
    printf("Digite o n�mero de alunos: ");
    scanf("%d", &numAlunos);
    Aluno *alunos = leAlunos(numAlunos);

    for (int i = 0; i < 5; i++) {
        imprimeAluno(alunos[i]);
    }

    listarTurma(alunos, 5);

    free(alunos);
    return 0;
}

int exercicio08(void) {
    /**
     Crie um novo tipo de registro para armazenar alunos com RA e idade.
     <p> fa�a a leitura de 5 alunos em uma fun��o.
     <p> Fun��o Calcule e imprima a m�dia das idades dos alunos.
     */

    int numAlunes;
    printf("Digite o n?mero de alunos: ");
    scanf("%d", &numAlunes);
    Alune *alunes = leAlunes(numAlunes);

    printf("A m?dia das idades ?: %.2f", mediaAlunes(alunes, 5));

    free(alunes);
    return 0;
}

int exercicio09(void) {
    /**
    
    <p>Crie um novo tipo de registro para armazenar coordenadas no plano
    cartesiano.
    <p>Crie uma Fun��o para imprimir um ponto do tipo criado.
    <p>Crie uma Fun��o para cada uma destas opera��es: soma de dois
    pontos, subtra��o de dois pontos, multiplica��o por um escalar.
    */

    printf("Digite as coordenadas do ponto 1:\n");
    Ponto p1 = lePonto();

    printf("Digite as coordenadas do ponto 2:\n");
    Ponto p2 = lePonto();

    printf("Ponto 1:\n");
    imprimePonto(p1);

    printf("Ponto 2:\n");
    imprimePonto(p2);

    printf("Soma dos pontos:\n");
    imprimePonto(somaPonto(p1, p2));

    printf("Subtra��o dos pontos:\n");
    imprimePonto(subtraiPonto(p1, p2));

    printf("Multiplica��o do ponto 1 por um escalar:\n");
    imprimePonto(multiplicaPonto(p1, 2));

    printf("Multiplica��o do ponto 2 por um escalar:\n");
    imprimePonto(multiplicaPonto(p2, 2));

    return 0;
}

int exercicio10(void) {
    /**
    Defina uma vari�vel do tipo registro que tenha dois campinas, senodo o  1 um vetor de 3 elementos do tipo inteiro
    e o 2 campo um valor inteiro. Fa�a:
    <p>
    <p>a) Crie uma fun��o para leitura dos valores do 1 campo(vetor)
   <p>b) Some os valores do vetor e coloque o resultao no 2 campo
    <p>c) Crie uma fun��o para imprimir os valores de registro
     */

    Reg minhaReg;

    minhaReg = leReg();

    minhaReg = somaVetorSegundoAtributo(minhaReg);

    imprimeReg(minhaReg);

    return 0;
}

int exercicio11(void) {

    /** Crie uma fun��o que recebe duas strings de tamanhos quaisqueres e que devolve a concatena��o destas
     * lembre-se que uma fun��o n�o pode devolver um vetor, mas ela pode devolver um ponteiro,
     *
     * o prot�tipo da fun��o ser�
     *
     * <p>char * concatena(char *s1, char *s2);
     */

    char *s1 = "Hello";
    char *s2 = "World";

    char *s3 = concatena(s1, s2);

    printf("%s", s3);

    free(s3);

    return 0;
}

int exercicio12(void){

    return 0;
}

int displayMenuAndGetChoice(void) {
    printf("Exerc�cio 01:\n");
    printf("Exerc�cio 02:\n");
    printf("Exerc�cio 03:\n");
    printf("Exerc�cio 04:\n");
    printf("Exerc�cio 05:\n");
    printf("Exerc�cio 06:\n");
    printf("Exerc�cio 07:\n");
    printf("Exerc�cio 08:\n");
    printf("Exerc�cio 09:\n");
    printf("Exerc�cio 10: \n");
    printf("Exerc�cio 11: \n");
    printf("Exerc�cio 12: \n");
    printf("Digite o n�mero do Exerc�cio que deseja executar: ");

    int escolha;
    scanf("%d", &escolha);
    return escolha;
}

void executeExercise(int choice) {
    switch (choice) {
        case 1:
            exercicio01();
            break;
        case 2:
            exercicio02();
            break;
        case 3:
            exercicio03();
            break;
        case 4:
            exercicio04();
            break;
        case 5:
            exercicio05();
            break;
        case 6:
            exercicio06();
            break;
        case 7:
            exercicio07();
            break;
        case 8:
            exercicio08();
            break;
        case 9:
            exercicio09();
            break;
        case 10:
            exercicio10();
            break;
        case 11:
            exercicio11();
            break;
        case 12:
            exercicio12();
            break;
        default:
            printf("Op��o inv�lida!\n");
            break;
    }
}

bool getExitChoice() {
    int sair;
    do {
        printf("Deseja sair? Digite (1) para Sim ou (0) para N�o: ");
        scanf("%d", &sair);
    } while (sair != 0 && sair != 1);
    return sair;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    bool sair = false;
    do {
        int escolha = displayMenuAndGetChoice();

        if (escolha >= 1 && escolha <= MAX_EXERCISES) {
            executeExercise(escolha);
        } else {
            printf("Op��o inv�lida!\n");
        }
        sair = getExitChoice();
    } while (!sair);
    printf("Obrigado por utilizar o programa!\n");
    return 0;
}