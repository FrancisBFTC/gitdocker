<a name="title"></a>
# GitDocker v0.2.5

Nesta versão foi corrigida o bug das branchs, feito uma melhor organização no algoritmo, implementado o merge e novas verificações. A partir desta versão um repositório de testes foi adicionado para executar as operações do GitDocker, veja em [gitdocker_auto_tests](https://github.com/FrancisBFTC/gitdocker_auto_tests/) as branchs e commits criadas pelo GitDocker.

### Bug Fixes

* Quando havia mais de 1 branch não existente em um mesmo commit, todas elas eram criadas de forma que prevalecia apenas o 1ª commit, então foi resolvido adicionando o algoritmo da adição de branchs na função runCommit() que só cria uma branch caso um commit for efetuado.
* Foi removido a execução do git checkout (sem -b) da função branchCommand(), agora ela só define uma variável booleana **switched** que identifica a alternância de branchs. A alternância é feito de fato no final da função initProjectRead(), juntamente com o `git add *` antes e o `git stash` que salva arquivos antes da navegação. 
* A implementação anterior também resolve o bug de navegação de branchs, porém foi feito também um parâmetro CLI adicional pra executar o **git merge**, filtrando dados JSON do array **merge** do arquivo **info.json**. 
* Na função branchCommand() durante a criação de uma nova branch é salvo no índice 0 do array json **merge** o nome da nova branch e durante a alternância de branchs existentes, é salvo no índice 1 do array json **merge** o nome da branch alternada. 
* Na função commitCommand() é salvo o nome da última branch antecedente ao commit da variável branch_str para branchname. branch_str recebe o nome de cada branch lida no código, enquanto que branchname só pega o nome mais recente de branch_str quando um commit será efetuado.
* Na função initProjectRead() é feito uma verificação após a filtragem de extensões, caso a extensão for aprovada, significa que o arquivo sendo lido pelo parâmetro --init contém uma extensão existente no JSON e só então é processado o fileInterpreter(), a alternância de branchs, o git push e o recursive, caso não for aprovada, é mostrada uma mensagem ao usuário.

### Features/Updates

* Formatação de arquivos JSON na escrita substituindo caracteres na função writeJSONFile().
* Novas informações de ajuda no GitDocker na função showInfoHelp().
* Processamento do **git merge** pelo novo parâmetro CLI --merge em branchs salvas para merge do arquivo **info.json**.
* Novo array json no arquivo **info.json** - o **merge[ ]**.
* O **Build.bat** pode compilar o executável fora do projeto, numa pasta chamada **gitd**, Obs.: Adicione este diretório nas variáveis de ambiente

### TODO

- [x] Concluir implementação do parâmetro --config.

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
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.5#title"> Versão 0.2.5 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.6#title"> Versão 0.2.6 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.7#title"> Versão 0.2.7 </a>

### <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.3.0#title"> Versão 0.3.0 </a>
