<a name="title"></a>
# GitDocker v0.2.7

Nesta versão foi implementado um valor específico do parâmetro --config, juntamente com as configurações de versões máximas e correções de alguns bugs:

### Bug Fixes

* Evita mensagens de aviso quando é alternado uma branch antes das que já foram criadas. Foi corrigido adicionando uma verificação de commit existente em commitCommand() quando commited é verdadeiro.
* Torna o **git checkout -b** que cria branches para modo silecionso.


### Features/Updates

* Organiza o código do parâmetro --merge para a função **mergeExecute()**.
* Adiciona mensagens de logs de sucesso para os comandos `@branch`, `@commit` e o --merge log, considerando que o git executa no modo silencioso.
* Cria o parâmetro --config aceitando 2 valores - O **RULES** e o **EXTENSIONS** que são objetos JSON.
* Cria a função **configExecute()** para processar o código do parâmetro --config. Atualmente esta função pode alterar valores  de chaves do config.json, sendo eles o max_major, max_minor e o max_patch, que são valores para regras de versões máximas.
* Cria parâmetros para definir os valores das chaves via linha de comando: O parâmetro --major que define a chave **max_major**, o parâmetro --minor que define a chave **max_minor** e o parâmetro --patch que define a chave **max_patch**. Os 3 valores da versão semântica.

### TODO

- [x] Implementar código do valor EXTENSIONS do parâmetro --config.
- [x] Implementar código do valor INIT do parâmetro --config.

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
