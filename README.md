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

- [ ] Implementar código do valor EXTENSIONS do parâmetro --config.
- [ ] Implementar código do valor INIT do parâmetro --config.
