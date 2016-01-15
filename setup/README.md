# Windows
* [Code::Blocks](http://www.codeblocks.org) IDE
* [CodeLite](http://www.codelite.org/) IDE
* [BloodShed](http://www.bloodshed.net/devcpp.html) IDE
* [NotePad++](https://notepad-plus-plus.org/) Editor simples e direto.
* [Sublime 3](http://www.sublimetext.com/3) Editor moderno.
* [MinGW](http://www.mingw.org/) Componentes GNU de compilação

As IDEs geralmente possui uma versão binária para download que já inclui o compilador.

# Ubuntu
```shell
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get install build-essential
$ apt-get install geany
```

* [geany](http://www.geany.org/) é parecido com o NodePad++, existem muitas [alternativas](http://askubuntu.com/questions/48299/what-ides-are-available-for-ubuntu).
* [fedora](https://getfedora.org/pt_BR/) é outra boa distro.
* Você consegue virtualizar o linux no windows usando o [virtualBox](https://www.virtualbox.org/)

## github
Você pode copiar todo o repositório clicando no botão "Download ZIP", ou instalar o git e digitar:
```shell
$ git clone https://github.com/degumes/lp.git
```
Para receber novas atualizações:
```shell
$ git pull origin master
```
Git é um gerenciador de versões para seus códigos. Ele pode te ajudar nos [CTRL+Zs e backups](https://git-scm.com/book/pt-br/v1/Primeiros-passos).

## testando
Nesta pasta 'setup' você irá encontrar alguns códigos para testar sem ambiente. Um dos arquivos é o "nada.c":
```c
int main(){
    return 0;
}

```
Para compilar:
```shell
gcc -Wall -g nada.c -o nada.bin
```
* **-Wall** Ativa avisos extras
* **-g** Insere no executável símbolos para serem usados pelo debuger
* **-o** O nome do executável gerado (*output*) será "nada.bin"

Ou simplesmente "`gcc nada.c`", a saída será "a.out".
