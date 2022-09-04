<a name="title"></a>
# GitDocker v0.3.0

Este é um projeto dedicado criar documentações automáticas durante um desenvolvimento de softwares e ao mesmo tempo realizar comandos do git para versionamento de código.

### Bug Fixes

* Insere espaçamentos entre logs de comandos diferentes do GitDocker para melhor visualização.
* Substitui caractere de **quebra de linha** por **espaços** em modificações de arquivos durante o **recursive**.

### Features/Updates

* Implementa valor **EXTENSIONS** do parâmetro --config. É possível acrescentar um novo conjunto de extensões com um array de símbolos de comentários.
* Implementa parâmetro --lang e --reset. O --lang é responsável por especificar um número de conjunto pra ser alterado, adicionando uma nova extensão a um conjunto sem precisar adicionar novos comentários. Enquanto que o --reset efetua estas alterações **apagando** o que já está configurado.
* O parâmetro --reset pode ser executado tanto com o valor EXTENSIONS, como RULES e também INIT.
* Implementa valor **INIT** do parâmetro --config. Através deste valor podemos configurar o diretório principal de leitura dos comandos `@path` e `@init` e acrescentar novas extensões para serem ignorados durante esta leitura.
* Implementa parâmetro --dir e --ignore. O --dir pode ser passado o valor do diretório principal na linha de comando, enquanto que o --ignore pode ser passado apenas um valor de extensão a ser ignorado. Da mesma forma podemos utilizar --reset pra apagar as extensões ignoradas e inserir outros novos para substituir os antigos.
* Implementa parâmetro --version para ler a versão atual do Software GitDocker.
* Inicia a criação do parâmetro --config-project, que será responsável por configurar o projeto antes da utilização do GitDocker (Este parâmetro vai executar todos os parâmetros citado anteriormente).
* Foram criadas 6 novas variáveis Strings pra armazenar valores após os parâmetros e +10 novas variáveis booleanas que vai controlar a execução dos parâmetros na função **configExecute()**. Nesta função cada parâmetro controla uma chave JSON, Exemplo: O valor de configuração (parâmetro --config) **EXTENSIONS** será relacionado ao objeto JSON de mesmo nome "EXTENSIONS", no entanto o sub-parâmetro **--lang** será relacionado ao array **lang** do mesmo objeto. Assim como os sub-parâmetros **--dir** e **--ignore** que manipulam valores de chaves json do mesmo nome mas do objeto json **INIT** (Valor de configuração "INIT" do parâmetro --config).
* Criação de novas Strings na função **showInfoHelp()** que nos apresenta informações de utilização dos novos parâmetros.

### TODO

- [ ] Fazer reviews e testes de modificações de arquivos quando usando **--recursive**, adicionar as modificações para arquivos lidos pelo comando `@path` ou arquivos modifieds.
- [ ] Criar a função verifyCreation(), para verificar arquivos untrackeds e a variável booleana **is_untracked**, assim como a função verifyModification(). Isto corrige o bug no qual se trata da situação de criação de novos arquivos ou ler o projeto pela 1ª vez e não conseguir identificar quais arquivos devem ser commitados.
- [ ] Implementar a função do parâmetro --config-project que vai executar todos os parâmetros criados nesta versão de forma automática e vai mover por uma primeira vez a pasta **infos** e seu arquivo **info.json** para o diretório do projeto que está sendo desenvolvido.
- [ ] Criar arquivos .bat com os parâmetros de configurações no diretório **gitd** a fim de mover estes arquivos durante a primeira configuração do projeto (--config-project) para a pasta do projeto do desenvolvedor, desta forma teriam arquivos clicáveis para efetuar configurações de forma mais rápida.

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
