<a name="title"></a>
# GitDocker

Este é um projeto dedicado criar documentações automáticas durante um desenvolvimento de softwares e ao mesmo tempo realizar comandos do git para versionamento de código.

<a name="menu"></a>
  * <a href="#what"> O que é este sistema? </a>
  * <a href="#how"> Como funciona? </a>
  * <a href="#comp"> Compilando Projeto </a>
  * <a href="#param"> Parâmetros do GitDocker </a>
    * <a href="#param-init">  Parâmetro --init </a>
    * <a href="#param-show">  Parâmetro --show-config </a>
  * <a href="#comm"> Exemplos de Comandos Interpretáveis</a>
    * <a href="#comm-path"> Comando Path</a>
    * <a href="#comm-init"> Comando Init</a>
    * <a href="#comm-comm"> Comando Commit</a>
    * <a href="#comm-desc"> Comando Description</a>
  * <a href="#colab"> Colaborações </a>
  * <a href="#ver"> Versões do Projeto </a>

<a name="what"></a>
## O que é este sistema?

É um sistema que terá geradores README automatizados, geradores de mensagens de commit e geradores de descrições de commit, tudo automaticamente. Todos os processos do git, do git push ao merge, serão uma sequência de tarefas automáticas que o programador fará diariamente, isso facilitará o processo de documentação do software. O programador se preocupará apenas em adicionar comentários de linha no código-fonte com comandos interpretáveis pelo aplicativo de controle de versão. A outra ideia que também facilitará é o processo de contagem de versões. A cada build que o programador fizer em seu sistema, o contador de versões poderá incrementar em um arquivo de versão todos os números que ele programou. Um exemplo: em pequenas modificações e correções de bugs, o último número será incrementado, mas o programador poderá configurar suas próprias regras de versão definindo limites numéricos de forma programada, ou definindo em tempo real quando o número da 2ª versão pode ser incrementado , e pode ser repensado nisso como um arquivo de configuração para interpretar comandos em comentários de linha.

Este aplicativo pode ser integrado em qualquer software de compilação ou sistema operacional. E o programador, enquanto desenvolve, pode criar a documentação de seu software, simultaneamente.

<a name="how"></a>
## Como funciona?

O executável de controle de versão leria todo o código-fonte procurando diretivas nos comentários, interpretaria e criaria arquivos de dados pré-formatados e JSONs para serem lidos por um ShellScript (ou código em C) enquanto o enviavam para o github. A princípio o aplicativo irá identificar a extensão da linguagem, fará uma comparação de um vetor enorme (ou estrutura JSON) para identificar a linguagem e descobrir qual símbolo é utilizado para comentários, após isso ele irá analisar todos os comentários, procurando tags de documentação, fazendo a interpretação e processamento necessário para documentação e controle de versão, tudo direto no próprio código-fonte, a partir de qualquer linguagem de programação. Assim este estará disponível e acessível a todos os tipos de programadores, contendo convenções que serão conhecidas e ensinadas através de tutoriais.

<a name="comp"></a>
## Compilando Projeto

Antes de tudo certifique-se que você está na plataforma Windows pois atualmente na data de hoje (22/08/2022) não foi implementado ainda a compatibilidade com plataforma Linux, para isto ainda utilizarei diretivas de compilação e um outro MakeFile/Build e alterarei este README. Porém atualmente no repositório contém um arquivo chamado `Build.bat` que terá as linhas de comando para compilar o projeto usando o parâmetro adicional -std=C++11 e aqui há um detalhe **muito importante**: este parâmetro é essencial pra executar uma dependência do projeto que é um json-parser clonado de outro repositório, então se você decidir executar o `GitDocker.dev` para abrir a IDE DevC++, certifique-se de configurar sua IDE pra executar o g++ usando -std=C++11, as instruções para isto está logo abaixo:

 1. Abra o projeto com DevC++
 2. Vá na aba **Ferramentas**
 3. Escolha **Opções do Compilador**
 4. Na janela que abrir, clique em **Programas**
 5. Nos campos de textos do gcc e g++ adicione -std=c++11, ficando assim

   ```
    gcc -std=c++11
    g++ -std=c++11
   ```
   
 6. Clique em OK.

Caso optar por executar o `Build.bat`, ignore estas etapas. Agora vamos configurar a dependência do GitDocker que é um json-parser. Usamos esta dependência no projeto pois a maior parte das configurações do GitDocker são feitos por arquivos JSON, como também o software gera/altera estes tipos de arquivos, para configurar é bem simples, primeiro clone em sua máquina usando o git o repositório json do nlohmann, desta forma:

```
 git clone https://github.com/nlohmann/json.git
```

Após isto, entra na pasta `json` clonada do repositório e dentro dela entre na pasta `include`, copie a pasta `nlohmann/` e cole na sua pasta `include` do G++, que fica no diretório: `C:\Program Files (x86)\Dev-Cpp\MinGW64\include` ou `C:\Program Files\Dev-Cpp\MinGW64\include` e também dentro do diretório `C:\Program Files (x86)\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include` ou `C:\Program Files\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include`, isto claramente se você estiver instalado seu G++ junto com a IDE DevC++ que foi o meu caso, se não for, procure a pasta include do seu G++ e cole a pasta copiada.

Agora é só compilar o projeto pelo Build.bat e ser feliz! 

<a name="param"></a>
## Parâmetros do GitDocker

O Gitdocker contém parâmetros para configurar o projeto, criar documentações e versionamento de código junto ao git em tempo de desenvolvimento, antes de tudo navegue até a pasta do seu projeto utilizando o comando CD e só após execute o gitdocker com seus parâmetros. Abaixo serão listados os parâmetros disponíveis:

<a name="param-init"></a>
### Parâmetro --init

Através do parâmetro --init ou -i é possível ler comandos iniciais em um arquivo de código-fonte principal. Dentro deste arquivo poderá ter qualquer comando processável pelo Gitdocker, tanto em comentários de linha como em comentários de blocos. A função do --init é inicializar as configurações pra um projeto, como: Definir commits e descriptions principais, gerar READMEs, definir quais arquivos do projeto serão interpretados e diversas outras coisas. Antes de qualquer processamento do gitdocker, é necessário executar primeiramente este parâmetro:

``` 
 gitdocker --init [arquivo.extensão] 
```

ou

``` 
 gitdocker -i [arquivo.extensão] 
```

_Nota : o argumento **[arquivo.extensão]** pode ser qualquer arquivo ou diretório completo onde **'arquivo'** é o nome do seu arquivo e **'.extensão'** é a extensão do seu arquivo, Exemplo: program.cpp_

<a name="param-show"></a>
### Parâmetro --show-config

O --show-config como o próprio nome diz, apresenta ao usuário informações de configurações JSON com um visual formatado. No diretório **'/configs'** existe um arquivo chamado `config.json`, neste arquivo pode ser configurado pelo usuário as regras de versões do seu projeto atual e novas extensões de linguagens de programação. No entanto este arquivo já contém extensões de algumas linguagens, que são identificadas pelo gitdocker para filtrar símbolos de comentários e processar os comandos, para visualizar estas configurações basta digitar:

``` 
 gitdocker --show-config 
```

ou

``` 
 gitdocker -sc 
```
<a name="comm"></a>
## Exemplos de Comandos Interpretáveis

Os comandos interpretáveis são palavras-chaves escritas em comentários de código-fonte no qual o executável GitDocker irá ler e processar uma determinada tarefa. Todos os comandos tem um prefixo @ antes da palavra-chave e podem ser precedidos de um ou mais parâmetros ou nenhum parâmetro. Cada comando no GitDocker tem sua própria tarefa, efetuando ações desde a documentação de projeto personalizado até o versionamento de código automatizado com a utilização da ferramenta git, no entanto é necessário ler um arquivo inicial através do parâmetro de linha de comando --init, que irá ler e processar todos os comandos digitados no arquivo. Abaixo vamos as descrições e exemplos dos comandos disponíveis. 

<a name="comm-path"></a>
### Comando PATH

O comando @path serve pra registrar arquivos ou diretórios em um objeto JSON. Os dados são armazenados neste objeto para serem lidos posteriormente. A função do comando @path é registrar para o GitDocker saber quais arquivos ele deve processar dentro de um projeto, lendo os diversos comandos de commit, descriptions e outros em arquivos de código-fonte. No entanto, o comando @path pode ser omitido e a partir daí o GitDocker vai considerar apenas os arquivos que foram modificados ou adicionados no projeto. O grande problema disso, é que existem milhares de tipos de arquivos possíveis em diversos projetos onde não existe um código-fonte, como Exemplo: Um executável, uma imagem, um vídeo, etc.. e mesmo descartando esta lista, ainda existem arquivos que contém dados e DSLs (Uma linguagem de domínio específico) que não possuem blocos de comentários e que após modificados, o GitDocker tentará ler mas não encontrará nada, perdendo um bom tempo de processamento, ainda mais se o projeto for muito grande. Então pra resolver este problema, entra o comando @path. 

Este comando atualmente possui 3 tipos de parâmetros:

    1. O nome de um arquivo ou diretório.
    2. Parâmetro [all] que especifica todos os arquivos.
    3. Parâmetro [all: ...] onde as reticências são extensões de arquivos separados por vírgula.

**Nota:** _O Parâmetro [all] irá ler todos os arquivos de um determinado diretório, este diretório pode ser configurado no arquivo config.json (Implementado a partir da versão 0.1.2). Neste diretório pode ficar apenas arquivos de código-fonte, evitando assim problemas e conflitos._

### 1. Registrando arquivos

Vamos supor que você tenha um projeto numa pasta chamada **MyProject** e lá contém o arquivo **main.c** no diretório raiz e existem 2 arquivos na pasta **Includes**: O arquivo **data.h** e **datas.inc**. O seu projeto tem esta seguinte estrutura de pastas:

<img src="https://imgur.com/OR1IOTy.png" alt="Estrutura de pastas de MyProject">

O main.c é o seu código-fonte principal que será compilado pra executável, o data.h e datas.inc são arquivos de cabeçalho de dados para serem incluídos o programa em C. Note que nós temos um novo arquivo que não mencionei - O **gitdock.cpp** (Aliás poderia ser de qualquer extensão desde que seja configurado no config.json, veja na seção ...). Este arquivo é recomendável ser adicionado no projeto pra não houver ambíguidades, pois é a partir dele que o GitDocker vai ler as configurações iniciais. 

Neste arquivo **gitdock.cpp** vamos colocar o comando @path seguindo a imagem abaixo:

<img src="https://imgur.com/HITsmdb.png" alt="Comando path no arquivo gitdock.cpp">

Nesta linha diz que vamos registrar num objeto JSON interno do GitDocker o arquivo **main.c** e este arquivo posteriormente será processado. Poderemos também fazer da seguinte maneira:

<img src="https://imgur.com/rxHQzH9.png" alt="3 Comandos path no arquivo gitdock.cpp">

Perceba que agora nós temos 2 comentários de linha, cada qual com um comando @path lendo um arquivo diferente, ou seja, os arquivos **data.h** e **datas.inc**, especificando também a pasta onde eles estão (Includes). Abaixo dos comentários de linha existe o comentário de bloco usando o comando @path pro arquivo **main.c** e mais abaixo a declaração de 2 Funções em C. Esta imagem é pra demonstrar que não importa a forma que os comentários estão organizados, o comando @path será processado da mesma forma, mesmo inserindo espaços ou tabs entre o @path e o arquivo (Exceto no próprio arquivo, não utilize arquivos com espaços). A declaração de funções e outros códigos serão ignorados pelo GitDocker justamente porque ele só processa os comandos em comentários.

No exemplo da 1ª imagem (Com 1 comando @path), agora vamos executar o GitDocker utilizando o parâmetro --init da seguinte maneira:

```
gitdocker --init gitdock.cpp
```

O --init vai inicializar o projeto lendo o arquivo gitdock.cpp, dentro dele vai ler o parâmetro do comando @path, que é o arquivo main.cpp e o resultado seria:

<img src="https://imgur.com/N9yof38.png" alt="Strings de 1 Log do comando path no CMD">

Mas no caso da 2ª imagem (Com 3 comandos @path), fazendo o mesmo procedimento que antes no terminal: `gitdocker --init gitdock.cpp`, teríamos este resultado:

<img src="https://imgur.com/HvnswO8.png" alt="Strings de 3 Logs do comando path no CMD">

Perceba que na 1ª imagem do terminal do VSCode nós temos uma mensagem de log do @path dizendo que está registrando o arquivo main.cpp e abaixo é apresentado um objeto JSON com o nome do arquivo especificado. Cada vez que é usado o comando @path, um novo índice é adicionado neste array JSON com um novo arquivo, é assim que funciona o registro de arquivos pelo GitDocker. Na 2ª imagem feito no próprio CMD, temos 3 logs do @path e 3 arquivos do objeto JSON do @path. Também temos outro índice do mesmo objeto chamado de "exts", que é um array json que inicialmente é nulo, como visto na tela (Falaremos sobre isso posteriormente).

O que significa que, os arquivos que tiverem registrados neste objeto JSON, serão lidos pelo GitDocker e processados com outros comandos, descartando os arquivos que foram modificados lidos pela ferramenta git.

### 2. Lendo TODOS os arquivos

Para registrar todos os arquivos existentes no projeto, é preciso especificar o parâmetro `[all]` após o comando @path. Quando o GitDocker identificar este parâmetro, ele apresenta uma mensagem na tela e define um booleano como **true**, desta forma, as outras linhas que contém o @path serão ignorados e apenas considerado aquele que tem o parâmetro `[all]`, veja abaixo como é utilizado:

<img src="https://imgur.com/R3Tzaal.png" alt="Arquivo com o parâmetro [all]">

Após inserir o comando no arquivo, agora digite `gitdocker --init gitdock.cpp` no Terminal e veja o resultado:

<img src="https://imgur.com/GEEJRxA.png" alt="Resultado no CMD do parâmetro [all]">

O parâmetro `[all]` não registra todos os arquivos porque como você pode ver, os objetos JSON são nulos, porém ele define como verdadeiro uma variável que vai permitir que o GitDocker leia todos os arquivos daquele projeto.

**Nota:** _A partir da versão 0.1.3 será implementado o valor JSON **ignore** que especifica todas as extensões de arquivo que serão ignorados naquele projeto, como: .EXE, .OBJ, etc..._

Quando utilizamos mais de uma linha do comando @path que contém o parâmetro `[all]`, na tela do terminal é apresentado um aviso, veja abaixo:

```C
 /*
   @path [all]
   @path [all]
 */
```

<img src="https://imgur.com/oyIkxRJ.png" alt="Resultado no CMD com mais de 1 parâmetro [all]">

### 3. Lendo todos os arquivos de extensões específicas

O parâmetro `[all]` também pode receber valores entre as chaves, porém é preciso adicionar **:** (dois pontos) após o nome do parâmetro, Exemplo: `[all: ...]`; No lugar das reticências é inserido nomes de extensões separados por vírgulas, no qual estes nomes devem ter o **pontinho** antes da extensão, Exemplo: 

`[all: .ex1, .ex2, .ex3]`

O GitDocker cria um vetor com todas estas extensões e armazena em um array de um objeto JSON - o objeto **paths**. No **paths** podem ser armazenados tantos os arquivos do comando @path como visto anteriormente, como também **extensões de arquivos**, se for arquivos o nome do array onde é armazenado é o **path** e se for extensões o nome do array onde é armazenado é o **ext**, então vamos a um exemplo:

<img src="https://imgur.com/mC1wVnc.png" alt="Utilizando [all: ...] para armazenar extensões">

E abaixo veremos o resultado deste parâmetro:

<img src="https://imgur.com/RmHBshR.png" alt="Resultado do [all: ...] para armazenar extensões">

Como pode ver acima o log do @path mostra que foi registrado 3 extensões para leitura, a mesma quantidade que foi especificada após o `[all:]` e o array JSON **exts** contém as extensões que foram definidas, já o array JSON **paths** é nulo, porque não foi registrado nenhum arquivo. Neste exemplo, o GitDocker procura no diretório e ler todos os arquivos que contem a extensão **.h** ou **.cpp** ou **.c**, ignorando todos os outros.

Digamos que você queira ler um arquivo específico, que será uma espécie de **excessão**, onde a extensão deste arquivo não foi definida no array, poderá fazer da seguinte forma:

<img src="https://imgur.com/rcLRLWK.png" alt="Registrando 1 arquivo e outras extensões com [all: ...]">

E no resultado abaixo você pode ver que temos 2 arrays JSON preenchidos - o **paths** e o **exts**:

<img src="https://imgur.com/bD9hEx5.png" alt="Resultado do Registro anterior">

Então o arquivo que estiver no array **paths** será uma excessão, onde o GitDocker vai ler apenas este arquivo com dada extensão, após finalizar a leitura, vai procurar todos os arquivos que contém uma das extensões definidas no array **exts**. Para isto ser possível, uma variável booleana é definida pra avisar o GitDocker que extensões serão lidas, pois o método de leitura de um arquivo definido com extensões definidas são diferentes.

Você também pode dividir um conjuntos de extensões em linhas separadas pelo comando @path e armazenar todas as extensões em um mesmo array JSON, da seguinte forma:

```
/*
  @path [all: .html, .css, .js]
  @path [all: .php, .py]
  @path [all: .cs, .cpp, .c, .h]
*/
```

E terá o seguinte resultado:

<img src="https://imgur.com/Pu6XeU1.png" alt="Leitura de vários conjuntos de extensões">

<a name="comm-init"></a>
### Comando Init

O comando `@init` serve para inicializar as configurações impostas por comandos anteriores, por exemplo: Se você definiu arquivos a serem lidos pelo comando `@path`, o init irá ler cada um destes arquivos e processá-los; Se você definiu uma mensagem de commit global, o init irá processar este commit ou uma description digamos assim. Então o init de fato dá o arranque/setup nas configurações, então vamos supor que você criou um arquivo chamado **init.js** desta forma:

<img src="https://imgur.com/mhw5bfL.png" alt="Arquivo init.js com 2 comandos path e 1 init">

E logo em seguida você cria 2 arquivos: um chamado **home.js** e o outro chamado **index.js** na pasta **Includes**, cada um ficando da seguinte forma:

#### Arquivo home.js
<img src="https://imgur.com/AIuw1Vz.png" alt="Arquivo home.js com 2 comandos: branch e commit">

#### Arquivo index.js
<img src="https://imgur.com/at9NeyK.png" alt="Arquivo index.js com 1 comando branch">

Os comandos branch e commit são ilustrativos apenas para testes (Serão implementados a partir da versão 0.1.4). Então após o path armazenar no seu objeto JSON os diretórios de arquivos, o init ficará encarregado de ler estes arquivos caso a variável **path_defined** for verdadeira e caso o objeto JSON **paths** for diferente de nulo. Após isto será chamada uma função de interpretação dos comandos, a mesma função que chamou o comando init e assim, os comandos que tiverem no **home.js** e **index.js** serão interpretados. Veja abaixo o resultado de log:

<img src="https://imgur.com/fbbHZUE.png" alt="Tela de logs do comando path e init">

Assim como apresenta na tela, os logs do comando path foram apresentados e após isto, os logs do comando init foram apresentados, onde cada processamento de arquivo pelo init é identificado 1 ou mais comandos, no qual é mostrado na tela a mensagem dos nomes dos comandos em ordem, porém esta mensagem foi programada temporariamente para testar o projeto, pois cada comando terá seu próprio log do que eles está fazendo.

Outra situação é se você decide colocar a extensão de um dos arquivos do comando path para um arquivo inexistente, como exemplo **index.html**:

<img src="https://imgur.com/rXxQnmQ.png" alt="Alterando a extensão para arquivo inexistente">

Então você terá este resultado:

<img src="https://imgur.com/lJ7gJ6u.png" alt="Resultado de arquivo inexistente">

O comando path até registra o arquivo pois ele não sabe se aquele arquivo existe ou não, justamente porque ele não é responsável por processar o arquivo, apenas armazenar o seu nome, porém o init por tentar efetuar a leitura dos arquivos ele logo identifica que o arquivo definido no path não existe e já apresenta a mensagem de erro. Mas se você tentar ler um arquivo EXE desta forma:

<img src="https://imgur.com/7x7WSEU.png" alt="Adicionando no path program.exe">

Como alterando o home.js para **program.exe**, mesmo que este arquivo exista no diretório, o GitDocker dará um erro como este:

<img src="https://imgur.com/N4xsWYc.png" alt="A extensão do EXE não é válida">

Isto porque na versão v0.1.2 foi implementado um objeto **INIT** com o array **ignore**, no qual este objeto vai guardar algumas regras e configurações para o comando init e o path, como o próprio ignore que serve pra armazenar uma lista de extensões que serão ignoradas pelo GitDocker. Lembrando de um possível problema que foi citado nesta mesma documentação sobre ler arquivos que **não** são códigos-fontes, isto traria sérios conflitos pelo fato do GitDocker processar comentários em códigos-fontes. Atualmente na data que estou escrevendo esta documentação, na versão 0.1.2, o array JSON **ignore** possui 4 extensões: **.exe, .obj, .o, .dll**; que são arquivos binários não processáveis pelo GitDocker. Você mesmo poderá efetuar suas próprias modificações no JSON, inserindo mais extensões a serem bloqueadas. Da mesma forma que o parâmetro `[all]` poderá usufluir desta mesma funcionalidade.

Abaixo mostrarei uma parte do arquivo **config.json** apresentando o objeto **INIT**:

<img src="https://imgur.com/mQPv4pM.png" alt="Objeto INIT no arquivo config.json">

**Nota:**  _Em outras sessões serão abordados mais a fundo sobre **Configurações no config.json**_

### Processando todos os arquivos pelo INIT

Se você pretende ler todos os arquivos de um determinado diretório, a partir da versão v0.1.4 foi implementado uma nova variável json - o **dir**. O comando `@init` processa todos os arquivos se inserido antes o comando `@path [all]` e inicia a leitura a partir do que está configurado em **dir** no arquivo **config.json**. Para inserir um diretório raiz do projeto, basta inserir **'./'** no dir e para ler uma pasta que está no diretório raiz, como exemplo: Includes; basta inserir no **'./Includes/'** no dir, abaixo mostrarei esta configuração no config.json:

<img src="https://imgur.com/zTim4pO.png" alt="Diretório raiz no dir do config.json">

Veja que novas extensões foram adicionadas na variável "ignore" onde os arquivos com estas extensões são ignorados pelo comando `@init` e no "dir" colocamos './' para ler arquivos do diretório raiz. No arquivo que será lido pelo parâmetro **--init** via CLI, adicione o seguinte script:

<img src="https://imgur.com/CBHiXXd.png" alt="Script gitdocker no arquivo init.js">

E como resultado você terá os seguintes logs no terminal:

<img src="https://imgur.com/iriNlwh.png" alt="Logs no terminal do comando init e parâmetro all">

Perceba que os 2 objetos Path e Ext são nulos, pois não é registrado nenhum arquivo, porém no sistema interno uma variável booleana é setada para realizar a leitura de todos os arquivos, o init loga no terminal os arquivos processados que estão no diretório principal e em sub-pastas. O init apresenta um erro mostrando que o init.js não pode ser processado, pois o arquivo atual que já está sendo lido é o init.js e ele não pode ser lido novamente, portanto é ignorado, porém sobre a mensagem de erro será corrigida em outras versões.

### Processando extensões específicas pelo INIT

Agora que já sabemos configurar o objeto INIT do config.json, vamos criar uma outra execução que vai ler todos os arquivos da pasta **./Includes/** que contém a extensão **.html**, então no config.json faça assim:

<img src="https://imgur.com/58jvgu7.png" alt="JSON do dir com a pasta Includes">

E no arquivo init.js, altere o parâmetro de `[all]` para `[all: .html]` que significa - _Leia todos os arquivos com a extensão .html_:

<img src="https://imgur.com/zTq6rBw.png" alt="Inicialização do path com [all: ...]">

A nossa pasta Includes está com os seguintes arquivos:

<img src="https://imgur.com/X6uuJdp.png" alt="Arquivos da pasta Includes">

Então nós temos este resultado:

<img src="https://imgur.com/XHmhJTK.png" alt="Log da Inicialização do path com [all: ...]">

O Objeto Ext agora tem a extensão .html e o init log apresenta apenas arquivos HTML processados. Mas você também pode ler outras extensões, como exemplo: .asm e .cpp, veja nas imagens abaixo:

<img src="https://imgur.com/Onklvf8.png" alt="Extensões .asm e .cpp da pasta Includes">
<br>
<img src="https://imgur.com/WG0SQQ2.png" alt="Log das extensões .asm e .cpp do init">

E da mesma forma se quiser ler todos os arquivos da pasta **Includes**, é só alterar o parâmetro `[all: .asm, .cpp]` por apenas `[all]` e terá este resultado:

<img src="https://imgur.com/XSPukZV.png" alt="Todos os arquivos da pasta Includes">

**Nota**: _Os comandos `@path` e `@init` não são processados em outros arquivos diferentes daqueles que são inicializados por --init, no nosso caso eles serão apenas processados no arquivo em questão como no exemplo: init.js_

<a name="comm-comm"></a>
## Comando Commit

Quando você está desenvolvendo um software muitas das vezes você precisa armazenar seu projeto numa plataforma de versionamento como Github. O seu código ao decorrer do tempo acaba possuindo inúmeras alterações e diferenças com o código original e depois de muito tempo desenvolvendo, você não se lembra mais de quais foram as mudanças, porque mudou e quando mudou. Para resolver este problema, o git oferece subcomandos para definir mensagens e descrições, onde você pode descrever qual foi a sua atualização atual do seu software e assim subir para a plataforma GitHub o seu código atualizado e descrito, desta forma isso facilita não só na filtragem de alterações de código ao longo do tempo como também na segurança de poder recuperar aquilo que você perdeu devido a um bug atual.

Então o git e o github oferece suporte a versionamento de código, armazenamento em nuvem e gerenciamento de projetos de forma organizada, no entanto, quando você está trabalhando com diversos arquivos em inúmeras linguagens, onde existem não só 1 ou 2, mas N arquivos incontáveis, o processo de versionamento se torna árduo e cansativo, então vamos supor uma seguinte situação: 

* Você está desenvolvendo um projeto no tempo de 3 meses.
* Seu projeto já contém de 20 a 50 arquivos.
* A cada dia de codificação você altera 10 arquivos de código-fonte.
* Você precisa descrever com detalhes cada alteração de cada 1 destes 10 arquivos.
* No final do dia, você executa o git push para subir remotamente todos os seus arquivos modificados e descritos para a plataforma GitHub.

Nesta situação você precisaria executar 10 comandos `git add` e +10 comandos `git commit`, com apenas 1 `git push` e 1 `git status` para analisar quais arquivos foram modificados, totalizando 22 comandos. Cada desenvolvedor tem sua própria duração de tempo de digitação, isso é relativo, alguns são mais rápidos, outros são mais lentos mas vamos considerar que você leva 5 segundos pra digitar o comando git add juntamente com seus arquivos e 10 segundos pra digitar o git commit (O tempo é maior pois existem mensagens a serem pensadas e escritas), o git push + o git status levou um tempo total de 5 segundos. O cálculo para saber o tempo total de todos os comandos seria: _(5 x 10) + (10 x 10) + 5_, dando um total de 155 segundos ou 2 minutos e 35 segundos, aproximadamente 3 minutos apenas para subir seu projeto pro GitHub, descartando o fato que existem vários outros comandos e o tempo de duração pode ser bem maior se o seu diretório utilizado no Git add for maior ou a mensagem de descrição do commit for demasiadamente grande. Ou melhor, quando você está trabalhando com vários diretórios grandes e completamente distintos entre si, no qual é preciso executar onerosamente vários git status pra relembrar e copiar os diretórios trabalhados. Com o tempo de trabalho, você vai estar cansado o suficiente pra cometer erros de digitação, errar o versionamento, etc.. Isso aumenta seu tempo de produção de software.

O comando `@commit`, como também o comando `@description` vai resolver este problema, diminuindo consideravelmente seu tempo de desenvolvimento de softwares, lançando seus projetos cada vez mais rápido, documentando e versionando simultaneamente de forma automatizada. Logo, com estes comandos, o GitDocker vai gerar de forma inteligente as mensagens em um arquivo json chamado **info.json** e te dará a possibilidade de descrever suas funções e códigos direto no código-fonte, ou seja, não será preciso fechar seu editor, abrir seu terminal e digitar inúmeros comandos pra descrever seu sistema modificado, apenas usuflua dos comentários de códigos (Se você for organizado, é algo que você praticamente já faz) e descreva suas novas funções normalmente, o GitDocker fará o resto.

### Como criar um commit com o GitDocker

Primeiramente vamos utilizar uma vantagem do GitDocker que é a funcionalidade de **Adicionar novas extensões** e através disso, é possível ter suas próprias aberturas e fechaduras de comentários de linha em uma extensão de arquivo própria, um bom exemplo é o arquivo com extensão **.gitdock**, adicionado recentemente no projeto na versão 0.2.0, então veja abaixo como o objeto **EXTENSIONS** do arquivo **config.json** está configurado:

<img src="https://imgur.com/3NjpoS1.png" alt="Configurações no config.json">

O Objeto **EXTENSIONS** contém um array chamado **lang**, onde cada índice deste array é um objeto que contém as variáveis **exts** e **comments**. A variável **exts** contém um conjunto de extensões que utiliza os símbolos de comentários da variável **comments**, através disso é possível adicionar/configurar novas linguagens de programação com novos blocos de comentários, desta forma o GitDocker vai processar o código-fonte de qualquer linguagem e como lemos inicialmente um arquivo com o --init, este arquivo poderia ser do próprio GitDocker, então foi adicionado uma extensão .gitdock com os símbolos de comentários de linha `**` e comentários de bloco `(` e `)`, ou seja, tudo que tiver entre estes parênteses ou após os 2 asteriscos, serão interpretados, como nossos comandos `@path`, `@init`, `@commit`, etc... Então criaremos um novo arquivo chamado **commit.gitdock** com o seguinte conteúdo:

<img src="https://imgur.com/CjAvUWu.png" alt="Arquivo commit.gitdock">

Utilizamos o comando `@commit` e uma mensagem após ele descrevendo a nossa funcionalidade. Geralmente mensagens de commits são curtas e objetivas, como uma espécie de título da funcionalidade adicionada. Na sua pasta ou projeto, certifique-se de que é um repositório do git, isto é, você deve clonar primeiramente o seu repositório criado no github com `git clone link-do-meu-repositorio.git` para esta pasta e abrir o CMD/Terminal nesta pasta, porém se você criou uma pasta qualquer apenas para testes, é possível utilizar os comandos iniciais do GitDocker (Exceto o comando `@branch`, entre outros) sem afetar no funcionamento e para isto na sua pasta raiz digite o seguintes comandos - `git init` e `git status` e pressione enter para cada um:

<img src="https://imgur.com/DJa9y0R.png" alt="Arquivo commit.gitdock">

O 1ª comando **git init** inicializa seu repositório com arquivos do git numa pasta oculta chamada **.git** onde a ferramenta vai fazer suas operações em cima desta pasta. O 2ª comando vai verificar o estado dos arquivos, se eles são **modificados** (Já existentes, porém alterados) ou arquivos **untrackeds** (Novos arquivos criados), onde estes estados de arquivos aparecerá em vermelho. Então o próprio git nos dá a dica de digitar o git add arquivo para mover a área de **staged**, ou seja, você adiciona os arquivos modificados ou untrackeds num objeto do git, preparando-os para serem commitados. Você pode adicionar cada arquivo individualmente, por exemplo: **git add commit.gitdock** (Aqui adicionei o arquivo commit.gitdock na área de staged); Ou pode adicionar todos os arquivos de uma vez só utilizando `git add *` e só após fornece o commit. Além de ser mais rápido, há uma desvantagem, pois se você fez inúmeras alterações em vários arquivos, a mensagem de commit será 1 só se adicionar todos os arquivos pelo git add de uma só vez, porém adicionando cada arquivo individualmente, você terá mais controle em cada alteração, criando novas mensagens de commit distintas entre si, identificando em qual arquivo alterou e o porquê.

Temos um arquivo modificado como apresenta na tela, que é o **commit.gitdock** e nele há o conteúdo do comando `@commit Nova funcionalidade adicionada`. Tudo o que devemos fazer agora é executar a initialização deste arquivo pelo GitDocker da seguinte forma:

<img src="https://imgur.com/UVTRD0k.png" alt="Executando commit com o GitDocker">

Aqui nós temos um commit gerado pelo comando `gitdocker --init commit.gitdock` que apresenta um log do `@commit` mostrando a mensagem de commit que foi adicionada e abaixo deste log, há outras mensagens da própria ferramenta git, pois o GitDocker executa o git para adicionar na staged area e commitar. Se comprovarmos usando o comando `git log`, vemos a nossa mensagem adicionada pelo `@commit`:

<img src="https://imgur.com/ujvMP93.png" alt="Comprovando a mensagem pelo git log">

Mas e se optarmos por executar novamente o comando `gitdocker --init commit.gitdock`? O que vai acontecer? É isto que vamos ver:

<img src="https://imgur.com/sy809H0.png" alt="Executando novamente o commit do GitDocker">

Temos uma log de informação dizendo que a mensagem de commit já foi adicionada. Isso por causa de 2 motivos:

1. O arquivo não foi modificado e já foi commitado uma vez.
2. A mensagem de commit foi armazenada em um arquivo JSON.

Sobre o 1ª motivo, mesmo se decidíssemos alterar o arquivo commit.gitdock, mesmo apenas adicionando uma linha, este arquivo ficaria no estado de **modificado** pelo git, possibilitando assim um novo commit pela ferramenta **git**, porém ainda não seria possível efetuar o commit pelo GitDocker justamente porque há um arquivo chamado **info.json** que armazena todas as mensagens de commits do GitDocker e descrições (Que no caso a descrição atual foi vazia), porém se executar neste exato momento o comando `git status`, vai ver que o arquivo **commit.gitdock** sumiu da lista de arquivos vermelhos (modificados), então é claro que deveríamos alterá-lo primeiro pra efetuar um novo commit.

Sobre o 2ª motivo, poderíamos comprovar por uma imagem como fica organizado as mensagens de commit no **info.json**:

<img src="https://imgur.com/re4etL9.png" alt="Arquivo info.json">

O **info.json** é um arquivo que vai guardar informações relacionadas ao software que está sendo desenvolvido. Ele poderá ser reescrito e lido constantemente pelos comandos `@commit`, `@description`, entre outros. Por este motivo, Ele fornece objetos e propriedades específicas para estas informações, incluindo o objeto **INFOS** que vai armazenar a data de compilação, os commits e descrições, a descrição principal do software, a versão do software, os hashes de integridade e vários outros valores. Cada índice do array **commits** vai armazenar uma mensagem de commit na propriedade **msg** e cada índice também contém um array chamado **desc** que armazena todas as descrições do último commit.

Isso significa que a cada comando `@commit` processado no GitDocker, antes ele vai armazenar neste array JSON commit, então primeiro o GitDocker verifica se a mensagem já foi criada no json, caso não, ele cria no json e efetua o commit com esta mensagem e suas últimas descrições usando a ferramenta git, porém isso é feito uma vez em uma única execução do GitDocker, quando é executado novamente, os commits anteriores são ignorados e é processado o novo comando commit adicionado no arquivo que está sendo lido pelo GitDocker. Cada arquivo deve possuir apenas 1 commit por execução, o commit posterior será executado na próxima execução do GitDocker. Um commit pode ter inúmeras descrições, no qual é lido no array JSON **desc**, logo todas as descrições abaixo do último commit processado, será relacionado a este commit. Veremos abaixo a criação de outro commit pelo arquivo **commit.gitdock**:

<img src="https://imgur.com/ZmEBuaA.png" alt="Outro commit no arquivo commit.gitdock">

Inserimos um novo comando `@commit` abaixo do que já criamos anteriormente, porém como já é esperado, o commit anterior não será processado e enviará uma mensagem na tela, apenas o último commit:

<img src="https://imgur.com/sgiSyzm.png" alt="Resultado do outro commit">

Então a mensagem **Nova funcionalidade adicionada** já foi feita no commit anterior e armazenada no **info.json**, logo ela é ignorada e apenas consideradas os outros commits. Veremos agora como está no arquivo **info.json**:

<img src="https://imgur.com/qhVVAuG.png" alt="Como esta no info.json">

Como pode ser visto, um novo array desc vazio foi criado e um novo msg no array commit. Daí em diante, o GitDocker estará apontando pro final da lista para adicionar novos commits e novas descriptions.


<a name="comm-desc"></a>
## Comando Description

TODO: Aqui vem a descrição do comando Description.

<a name="colab"></a>
## Colaborações

Antes de tudo, dê um Fork no Projeto e clone o repositório em sua máquina, crie uma nova branch seguindo o padrão de versões do gitdocker:

**Criando uma branch -->**

<code>
git checkout -b gitdocker-v0.0.x
</code>
<br><br>

Obs.: 'x' deve ser um número acima da última versão criada do gitdocker. Se por exemplo o gitdocker está na versão v1.0.1, sabemos que sua branch deve ser v1.0.2 e assim por diante.

Nesta nova versão adicione suas funções, Exemplo: Um novo parâmetro da CLI e uma nova função, efetua os testes, tudo funcionando então dê o git push ao Github. Entre no meu repositório do Gitdocker na Branch Main e abra a sessão de Pull Request, crie uma nova Pull Request, escolha seu repositório atualizado e escreva um comentário dizendo quais foram as suas alterações.

Com isto irei analisar o código e verificar se posso fazer o merge com a branch main.

<a name="ver"></a>

## Versões do Projeto

Segue abaixo uma lista de versões de desenvolvimento do GitDocker:

* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.1"> Versão 0.0.1 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.2"> Versão 0.0.2 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.3"> Versão 0.0.3 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.4"> Versão 0.0.4 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.8"> Versão 0.0.8 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.0"> Versão 0.1.0 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.1"> Versão 0.1.1 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.2"> Versão 0.1.2 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.3"> Versão 0.1.3 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.4"> Versão 0.1.4 </a>

### <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.0"> Versão 0.2.0 </a>

* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.1"> Versão 0.2.1 </a>

