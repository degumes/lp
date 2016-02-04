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

As definições também dever ser inseridas em algum momento. É possível apenas
passar todos os códigos fontes de uma vez:
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

Separar declaração e definição de variáveis e funções em arquivos externos
auxilia a leitura organizando melhor o código, num fica a implementação interna
das funcionalidades, noutro arquivo fica destacado quais os parâmetros e
retornos que se espera.

# Documentação

Existem vários padrões para se documentar o código fonte, as IDEs tipicamente
conseguem formatar esses comentários e apresentam funcionalidades de navegação e
consulta. Javadoc e Doxygen são 2 desses estilos bem difundidos, são compatíveis
entre si e conseguem gerar documentos externos contendo as informações sobre as
funções e estruturas.

*[Doxygen](http://www.stack.nl/~dimitri/doxygen/)
*[Visual Studio Doxygen](https://visualstudiogallery.msdn.microsoft.com/11a30c1c-593b-4399-a702-f23a56dd8548)
*[CodeBlocks](http://wiki.codeblocks.org/index.php/DoxyBlocks)
