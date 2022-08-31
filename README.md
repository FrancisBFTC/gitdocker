<a name="title"></a>
# GitDocker v0.2.4

Esta versão se relaciona com a implementação do comando `@branch` para criar branchs e efetuar push ao repositório remoto e a criação do parâmetro CLI **--recursive** para uma chamada recursive do GitDocker. No entanto, esta versão é instável e contém alguns bugs.

### Bug Fixes

Nenhum.

### Features/Updates

* O Comando `@branch` foi implementado através da função **branchCommand()**.
* Novas variáveis booleanas e contadores adicionados - O **contain_branch**, **switched** e **branched**, **count_branch** e **index_branch**.
* Novo array JSON adicionado no info.json - O **branchs[ ]**
* A função **branchCommand()** pega o valor após o comando `@branch` e verifica se existe no **info.json**, caso sim, ele efetua o **git checkout** para navegar até a branch, caso não, ele cria uma nova branch com **git checkout -b** e armazena a nova branch no info.json.
* Na função **commitCommand()** é verificado se uma branch foi selecionada ou criado, caso sim, ele armazena em um Array o nome da branch.
* Na função **initProjectRead()** no final da execução é feita uma verificação se há um comando branch, se sim, Então é efetuado um commit automático do GitDocker se outros arquivos como: info.json e é executado o git push com a origem sendo o nome da branch salvo em commitCommand() pelo array.
* Foi implementado o parâmetro **--recursive** que efetua uma série de execuções do GitDocker afim de executar o git commit para os próximos commits não efetuados. O método do --recursive é modificar o arquivo atual. No entanto, isso não é feito para outros arquivos a não ser o arquivo principal.

### TODO

- [ ] Corrigir Bug do comando `@branch` quando adicionado várias branchs em uma única execução, este bug cria todas as branchs porém não efetua os commits na branch específica.
- [ ] Corrigir bug do git checkout , Ao navegar para uma branch anterior, um problema aparece devido a falta do git stash e impede a execução.

## Versões do Projeto

Segue abaixo uma lista de versões de desenvolvimento do GitDocker:

* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.1#title"> Versão 0.0.1 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.2#title"> Versão 0.0.2 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.3#title"> Versão 0.0.3 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.4#title"> Versão 0.0.4 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.8#title"> Versão 0.0.8 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.0#title"> Versão 0.1.0 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.1#title"> Versão 0.1.1 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.2#title"> Versão 0.1.2 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.3#title"> Versão 0.1.3 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.4#title"> Versão 0.1.4 </a>

### <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.0#title"> Versão 0.2.0 </a>

* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.1#title"> Versão 0.2.1 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.2#title"> Versão 0.2.2 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.3#title"> Versão 0.2.3 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.4#title"> Versão 0.2.4 </a>
