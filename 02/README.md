# Menu
A entrada padrão é algo complicado, existe inúmeros detalhes que só fazem
sentido quando você desce a muito baixo nível. Pior que esta é a forma básica de
interação, sem isto seus programas iniciais ficam muito insonsos. Olha o que o
compilador diz sobre o gets:

```shell
warning:the 'gets' function is dangerous and should not be used.
```

Não existe definições específica para entrada de dados pelo teclado, ou algo que
entenda linhas ou comando. Tudo é um fluxo de caracteres que é armazenado num
buffer e as funções de leitura e escrita atuam sobre ele. Pode acontecer de uma
função deixar resíduos no buffer e a próxima executar de forma anômala. Uma
alternativa é limpar o buffer e outra e usar entradas formatadas que escapem
desse lixo. O exemplo a seguir mostra o último caso:

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    char menuSwitch = 'm';
    char pedeTempo;
    while(menuSwitch != 'q'){
        system("clear");
        printf("tecle q para sair\n");
        printf("tecle b pra selecionar baskara\n");
        scanf(" %c", &menuSwitch);\\entada formatada " %c"
        switch (menuSwitch) {
            case 'q':
                printf("Tchau\n");
                break;
            case 'b':
                printf("Baskara ainda não implementado\n");
                printf("qualquer letra para voltar\n");
                scanf(" %c",&pedeTempo);\\entada formatada " %c"
                break;
        }
    }
}
```
A segunda leitura serve apenas para dar tempo pro usuário ler o menu, senão iria
voltar pro loop while e o `system("clear")` apagaria a mensagem. O espaço antes
do `%c` no `scanf` é importante, exige que a entrada seja formada lendo apenas o
caractere no final de um espaço ou equivalente. Experimente retirar o clear para
monitorar todos os passos e depois o espaço alternadamente, depois os dois pra
ver como o algoritmo reage.

* [FAQ stdio](http://c-faq.com/stdio/index.html)
* [NCurses](https://www.gnu.org/software/ncurses/)
* [Ncurses tutorial pt-br](https://www.vivaolinux.com.br/artigo/Utilizando-a-biblioteca-NCURSES-Parte-II)

# Multiplos Arquivos de Código
Você pode declarar e definir uma variável numa mesma linha de código, assim:
`int a = 3;`, ou declarar numa parte e definir num outro momento, numa linha
`int a;` e noutra posterior `a=3;`. Isto também vale para as funções e estes
trechos de códigos podem estar até mesmo em arquivos diferentes.

No diretório "parts" há um exemplo. As funções `c()` e `bhaska()` devem ser
definidas antes de serem usadas no `main()`, por isso é necessário inseri-las
pela diretiva `#include`. Estas definições explicitam quais as entradas e saídas
que devem ser manipuladas.

As definições também dever ser inseridas em algum momento. É possível apenas passar todos os códigos fontes de uma vez:
```shell
$ gcc -lm menu2.c c.c bhaska.c
```
Ou primeiro compilar os módulos em objetos e depois os linkar durante a
compilação do `main()`.
```shell
$ gcc -c c.c bhaska.c
$ gcc -lm  c.o bhaska.o menu2.c
```
Os arquivos objetos são binários, não são legíveis. A utilidade desse método é
criar bibliotecas que possam ser distribuídas publicamente sem mostrar o código
fonte. Você repassa o cabeçalho definido a interface do módulo mas sua
implementação fica obscurecida.

`lm` é uma diretiva do gcc para inserir constantes numéricas usadas em operações
matemáticas. A diretiva `c` diz para apenas compilar, não linkar, gerando o
código objeto que depois será linkado no `menu2.c`.

# Documentação
Uma convenção adotada nas linguagens orientadas a objeto é criar arquivos
separados para as classes e interfaces e nestes arquivos existir a documentação
necessária para cada método, atributo e parâmetro. Gradualmente a comunidade C
também foi adotando esta prática e se mostra bastante eficiente, convenções
sobre os comentários permitem gerar manuais sobre o código de forma automática e
algumas IDEs conseguem mostrar essas ajudas enquanto se programa a implementação.

[Javadoc ](http://www.oracle.com/technetwork/articles/java/index-jsp-135444.html)
é uma espécie de processador de comentários dos códigos do JDK para documentação
, referência e ajuda que está . Para C/C++ e diversas outras linguagens existe
um superset:

[DOXYGEN](https://www.stack.nl/~dimitri/doxygen/manual/docblocks.html)

Consegue gerar pdf, html, manpage, gráfico das estruturas. Mas o importante,
mesmo não instalando a ferramenta, seria seguir o padrão de comentário. O
Javadoc e doxygen são compatíveis e similares.
