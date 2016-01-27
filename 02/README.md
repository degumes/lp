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
desse lixo. O exemplo a seguir mostra uma alternativa:

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
        scanf(" %c", &menuSwitch);
        switch (menuSwitch) {
            case 'q':
                printf("Tchau\n");
                break;
            case 'b':
                printf("Baskara ainda não implementado\n");
                printf("qualquer letra para voltar\n");
                scanf(" %c",&pedeTempo);
                break;
        }
    }
}
```
A segunda leitura serve apenas para dar tempo pro usuário ler o menu, senão iria
 voltar pro loop while e o `system("clear")` apagaria a mensagem. O espaço antes
 do `%c` no `scanf` é importante, exige que a entrada seja formada lendo apenas
 o caractere no final de um espaço ou equivalente. Experimente retirar o clear e o espaço de um da  cada vez e depois dos dois pra ver como o algoritmo reage.

* [FAQ stdio](http://c-faq.com/stdio/index.html)
* [NCurses](https://www.gnu.org/software/ncurses/)
* [Ncurses tutorial pt-br](https://www.vivaolinux.com.br/artigo/Utilizando-a-biblioteca-NCURSES-Parte-II)

# Multiplos Arquivos de Código


# Documentação
