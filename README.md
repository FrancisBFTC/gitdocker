# GitDocker v0.2.6

Este é um projeto dedicado criar documentações automáticas durante um desenvolvimento de softwares e ao mesmo tempo realizar comandos do git para versionamento de código.

### Bug Fixes

Nenhum.

### Features/Updates

* Roda o git no modo silencioso gerando logs para cada comando git no diretório **C:/gitd**.
* Move arquivo **config.json** para diretório **C:/gitd** e leia de lá.
* Execução do comando **gitdocker --merge** a partir do GitDocker após finalização do parâmetro --init.
* Roda git push no modo --quiet (Silencioso).
* Remove git stash na função initProjectRead() na verificação de **switched**.
* Adiciona um 3ª auto-commit do GitDocker no parâmetro --merge antes do git push.

### TODO

- [ ] Remover mensagens de **aviso** se caso uma nova alternância de branches for antes das branchs pré-criadas.
