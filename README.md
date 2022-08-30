<a name="title"></a>
# GitDocker v0.2.2

Este é um projeto dedicado criar documentações automáticas durante um desenvolvimento de softwares e ao mesmo tempo realizar comandos do git para versionamento de código.

### Bug Fixes

* Quando havia 1 commit sem description no arquivo principal, ocorria um erro JSON, devido a String filename na função runCommit() estar fora das condicionais, para resolver foi inserido filename dentro das condicionais.
* Ocorria uma tentativa de commits mesmo em arquivos que não eram modificados, a ferramenta git executava o comando **git status** para mostrar os arquivos modificados, para resolver foi adicionado novas funções, veja em **Features**.
* Comandos no arquivo principal após o comando `@init` eram ignorados e não processados, para resolver o booleano **block_symbol** é definido pra **true** após a execução da função  **initCommand()**. 

### Features/Updates

* Nova função adicionada - A **checkStateFiles()**; Verificando arquivos untrackeds e modifieds armazenando-os em um array. A função é chamada em initProjectRead() antes do fileInterpreter() e dentro do fileInterpreter() após execução do `@init`.
* Novos booleanos adicionados - O **modified** que é definido quando algum arquivo modificado é encontrado; O **untracked** que é definido quando algum arquivo criado é encontrado e o **is_modified** para arquivos individuais.
* Nova função adicionada - A **verifyModification()**, que retorna um booleano verdadeiro para **is_modified** caso o arquivo lido em questão está no array de modificados, caso não está, retorna falso. A função é chamada dentro do fileInterpreter() antes de qualquer execução e após a execução da função initCommand().
* Nova verificação adicionada em **commitCommand()**, que após os 2 testes de **commited == false** e **exist_commit == false**, é verificado se **is_modified == true** para assim armazenar as mensagens de commit no JSON. Caso **is_modified == false**, é apresentando um erro na tela mostrando que o arquivo atual não foi modificado. O comando `@description` também só executado caso todos estes testes sejam aprovados, pois depende de um booleano de commitCommand().

### TODO

- [ ] Criar parâmetro --config na CLI.
- [ ] Criar parâmetro --search na CLI.
- [ ] Iniciar criação do comando `@branch`.


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
