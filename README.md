# GitDocker v0.2.0

Este é um projeto dedicado criar documentações automáticas durante um desenvolvimento de softwares e ao mesmo tempo realizar comandos do git para versionamento de código.

### Descrição da v0.2.0

Na introdução da versão v0.2.0 foi iniciado a implementação dos comandos commit e description no qual é filtrado as mensagens após os comandos através de uma nova função getString(). Também foi adicionado uma nova extensão no config.json que permite ter um arquivo principal com a sintaxe da linguagem do GitDocker.

### Bug Fixes

Nenhum.

### Features/Updates

- Inicio da implementação do comando `@commit` filtrando uma mensagem através da função getString().
- Inicio da implementação do comando `@description` filtrando uma mensagem através da função getString().
- Criação de um novo arquivo chamado **lang.gitdock** que terá um script básico inicial para o parâmetro --init.
- Criação de uma nova extensão no **config.json** que permite ler um bloco com o script do GitDocker.

### TODO

- [ ] Criação de novos valores JSON no **info.json** para leitura e escrita de informações, Ex.: Commits & Descriptions.
- [ ] Concluir a implementação do comando `@commit` considerando apenas o último commit escrito.
- [ ] Concluir a implementação do comando `@description` filtrando todas as últimas descrições escritas para mesclagem com o último commit.
