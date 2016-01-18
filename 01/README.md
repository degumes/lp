# Bibliotecas
Existe uma biblioteca padrão que acompanha o compilador, para qualquer
arquitetura que a linguagem foi portada as mesmas capacidades desta biblioteca
estão disponíveis. Elas não são especificadas na linguagem, são embutidas pelo
GCC durante a compilação.

Para inserir algumas [dessas](https://en.wikipedia.org/wiki/C_standard_library)
bibliotecas inicie o arquivo de código fonte da seguinte forma:

```c
#include <nomeBib.h>// nomeBib não é uma nome de biblioteca de verdade
#include <outraBib.h>// repare no uso do < >
#include <stdio.h>// inclui o printf()
#include <math.h>// inclui o cos()
#include <limits.h>// maior inteiro, memor diferença entre reais
```

`< >` significa que o compilador deve buscar este nome nas suas bases próprias,
se fosse algo como `"./lib/myBib.h"` ele buscaria o cabeçalho "myBib.h" na pasta
"lib" do mesmo diretório que está o código fonte.

O `<math.h>` inclui algumas tabelas numéricas pra calcular exponenciais e
funções trigonométricas, para compilar corretamente inclua o termo `-lm` (L
minusculo, não 1), desta forma:

```shell
$ gcc -Wall -g -lm sources.c -o program.bin
```

# argc \*argv
A função principal `main` é chamada passando duas variáveis pelo ambiente de
execução, o `argc` com o valor da quantidade de argumento, e o `*argv` passando um
vetor com estes argumentos. O primeiro argumento é o próprio nome do executável.

Por exemplo, o algoritmo `papagaio.c` repete todos os argumentos enviados para ele, suponha que você tenha compilado e executado desta forma:
```shell
$ gcc -Wall -g papagaio.c -o papagaio.bin

$ ./papagaio.bin vamos passear?
vamos passear?

$ ./papagaio.bin santa tartaruga
santa tartaruga

$ ./papagaio.bin FIIUUU FIIIUU
FIIUUU FIIIUU
$
```

`return 0;` significa que será retornado o valor zero para o ambiente que fez a
chamada para `main`, em sistemas unix isto significa que o programa terminou da
forma planejada.

# Declarações
Funções e variáveis precisam ser declaradas apenas antes de serem invocadas.
Como no exemplo a seguir:
```c
#include <stdio.h>

int main(){
    int existe;

    void imprimeIN(){
        printf("%d\n",existe);
    }

    void imprimeOUT(){
        imprimeIN();
    }

    existe = 1;//experimente compilar sem esta linha

    imprimeOUT();

    return 0;
}
```

A variável local `existe` é herdada pelas funções, ela não é passada como argumento. Ela é primeira declarada e depois definida, enquanto que as funções `imprimeIN` e `imprimeOUT` são declaradas e definidas ao mesmo tempo.

O estilo adotado no exemplo anterior pode causas dificuldades na leitura em
programas maiores, recomenda-se deixar as declarações das funções, estruturas e
tipos, com seus respectivos comentários, antes da função `main`, assim estes
blocos estão mais destacáveis. Neste caso a variável `existe` também precisa
passar a ser global para que as funçõe a encontrem.

Mas se as funções forem muito complexas vão existir muitas linhas de código
antes da função principal. O exemplo a seguir tenta contornar isso e as funções
passam a variável existe diretamente.
```c
#include <stdio.h>

/**
* @brief Função interna que imprime "existe"
* @param e Inteiro a ser imprimido
*/
void imprimeIN(int e);

/**
* @brief Função externa que executa a interna
* @param Inteiro a ser repassado para a função interna
*/
void imprimeOUT(int e);

/**
* @brief Função principal
*/
int main(){
    int existe = 1;//experimente compilar sem esta linha

    imprimeOUT(existe);

    return 0;
}

void imprimeIN(int e){
    printf("%d\n",e);
}

void imprimeOUT(int e){
    imprimeIN(e);
}
```
Note que a variável `existe` passou a ser local à `main`. As definições das
funções passaram para depois da função principal não poluindo o código. A
primeira parte das declarações tenta expor de forma clara quais são as funções,
quais parâmetros recebem e qual tipo retorna, muitas IDE reconhecem esse padrão
e mostram essas informações na coluna lateral para que você faça esta consulta
sem precisar navegar até o começo do arquivo.
