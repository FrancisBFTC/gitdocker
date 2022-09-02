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
    * <a href="#comm-bran"> Comando Branch</a>
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

Anteriormente vimos sobre o comando commit, agora vamos focar nas **Descriptions**. O comando `@description` serve para detalhar ainda mais suas mensagens de commit. Como foi dito anteriormente, a mensagem de commit é curta e objetiva, uma espécie de **Título** da nova funcionalidade, especificando o que você fez ou alterou, ou o que corrigiu. As descrições detalham estas mudanças, de forma que você possa separar por listas o que foi feito na nova funcionalidade ou mudança.

Vamos supor o seguinte exemplo: Você está desenvolvendo um software em C++ que contém 2 funcionalidades: **Comprar Produtos** e **Vender Produtos**. Na funcionalidade de **Comprar Produtos** existem 2 funções: a 1ª de criar um formulário de preenchimento e a 2ª de processar o pagamento baseado no formulário preenchido. Então você teria os seguintes comandos do GitDocker no arquivo **loja.cpp**:

<img src="https://imgur.com/z5BTXCK.png" alt="Criando commits e descrições">

A partir de agora, durante a escrita desta documentação, vamos inserir a palavra **Teste** antes de qualquer commit para dizer que aquilo se trata de um teste. Então como você pode ver, nós temos 1 comando `@commit` com sua mensagem **Funcionalidade de Compra** e 2 comandos `@description` no qual o 1ª recebe a descrição da 1ª função da funcionalidade que é **Criar formulário de compra** e a 2ª recebe a descrição da 2ª função da funcionalidade que é **Processar o pagamento**. É claro que você pode criar descrições mais complexas e detalhadas, mas como se trata de um teste, vamos ser mais objetivos. Abaixo de cada **description** nós temos um comentário dizendo `// aqui vai o seu código...`, ou seja, neste comentário é substituído pelo seu código da função correspondente e a description vai descrever esta função.

Durante o desenvolvimento das funções, você pode criar uma description pra cada trecho de código que fizer, detalhando ainda mais seu desenvolvimento. Abaixo dos comentários nós temos o terminal que executamos o comando `gitdocker --init loja.cpp` e é apresentado o log tanto do `@commit` como da `@description`, é apresentado também como ficaria o comando se feito no git após a String **Commit Command:** e abaixo disso as mensagens da execução do próprio git, que de fato executa o comando acima. Se digitássemos **git log**, iremos ver como está armazenado no git:

<img src="https://imgur.com/HqRcAM6.png" alt="Git log pra apresentar as informações">

Já a 2ª funcionalidade que é **Vender Produtos**, você teria +2 funções: A 1ª função de criar um formulário para anúncio de produtos e a 2ª função para publicar em algum feed seu anúncio da venda baseado nos dados do seu formulário, então vamos adicionar novos comandos `@commit` e `@description` no mesmo arquivo **loja.cpp**:

<img src="https://imgur.com/w7WshmW.png" alt="Criando novo commit e descrições">

Alteramos o arquivo **loja.cpp** adicionando novos commits e descriptions, sem alterar os commits e descriptions anteriores que já foram executados, temos o novo commit **Funcionalidade de Venda**, que contém 2 funções descritas: **Cria formulario para anuncios** e **Publica no feed o anuncio**, cada qual terá um código abaixo da função substituindo o comentário `// aqui vai sua 1ª/2ª função`. É claro que você também poderá ter inúmeros outros comentários antes do código, porém se não for um comando do GitDocker, estes outros comentários não serão processados pelo GitDocker, apenas os comandos acima. Veremos como é apresentado no terminal:

<img src="https://imgur.com/9SafAvU.png" alt="Apresentando no terminal as descriptions">

No terminal mostra o 1ª log de informação sobre o 1ª commit que está sendo ignorado pois já foi adicionado anteriomente e o novo commit com suas novas mensagens definidas nos comandos `@commit` e `@description` e se comprovarmos no git log veremos:

<img src="https://imgur.com/vun4HgE.png" alt="Comprovando no git log o novo commit">

## Processando commits/descriptions de outros arquivos

Agora que você já sabe como utilizar os comandos do GitDocker para efetuar commits e descriptions, iremos aproveitar todo o conteúdo estudado até aqui utilizando os comandos `@path` e `@init` para carregar outros arquivos. Agora nosso sistema terá um arquivo inicial chamado **sistema.gitdock** que terá commits e descriptions inicias descrevendo nosso sistema. A conexão com banco de dados será inserida numa pasta chamada **database** com o arquivo **conexao.h**, veja como está nossa estrutura de pastas:

<img src="https://imgur.com/AF29qt3.png" alt="Estrutura de pastas">

No arquivo **sistema.gitdock** vamos inserir o seguinte script do GitDocker:

<img src="https://imgur.com/ISUEwxd.png" alt="Inicialização com commit e description">

O GitDocker primeiro vai criar um commit do arquivo **sistema.gitdock** chamado **Sistema de compra e venda** com a descrição **este sistema efetua compras e vendas atraves de anuncios**, após isto irá carregar o arquivo **loja.cpp** que terá os commits e descriptions anteriores no qual será ignorado, pois já foi adicionado e também vai carregar o arquivo **conexao.h** da pasta **database** que terá o seguinte conteúdo:

<img src="https://imgur.com/Sem6x5g.png" alt="2 commits do banco de dados">

Perceba que nós temos 2 commits atuais: O **Conexao com o Banco de Dados** que terá a description da função **db_connect()** e o commit **criar CRUD do Banco de Dados** com as descriptions das funções **db_read()**, **db_insert()** e **db_delete()**. Porém como já sabemos, o GitDocker apenas efetua o 1ª commit não armazenado e só depois, na próxima execução que processa o próximo commit não armazenado. Aqui nós temos um 1ª commit que será a nossa função pra se conectar ao banco de dados e no nosso 2ª commit teremos um **CRUD** (**C**reate, **R**ead, **U**pdate e **D**elete) do banco de dados, porém não adicionamos a função de **Update**, isto foi proposital porque em um 1ª commit todo o arquivo já é adicionado na staged area e precisamos alterá-lo novamente para processar um 2ª commit, então vamos executar o comando `gitdocker --init sistema.gitdock` para realizar todas estas operações:

<img src="https://imgur.com/59i6pn1.png" alt="Realizando operações do sistema.gitdock">

No terminal podemos ver que na inicialização do projeto, o 1ª commit que será realizado é o do sistema.gitdock com a mensagem **Sistema de compra e venda**, após isto, o GitDocker registra através do comando `@path` os arquivos **loja.cpp** (que já adicionamos seus commits) e **database/conexao.h**, é feito o commit do sistema.gitdock e depois é processado o arquivo loja.cpp pelo comando `@init`, porém é apresentado um log de informação dizendo que os commits já existem, claro, nós adicionamos eles na explicação anterior no título <a href="#comm-desc">Comando Description</a>. O comando init começa a processar o próximo arquivo que é o **conexao.h** que vai executar o commit **Conexao com o Banco de Dados** e sua única description da função **db_connect()**. Perceba-se que uma nova mensagem amarela foi apresentada - o Log de **AVISO**, dizendo que o commit **Criar CRUD do banco de dados** será adicionado no próximo commit e é isto que acontece quando tentamos criar 2 commits em uma única execução, portanto precisamos reexecutar o gitdocker novamente para commitar o CRUD.

No entanto, dará um erro pelo próprio git se criássemos este commit mesmo sem alterar o arquivo **conexao.h**, pois ele já foi commitado e não está na staged area justamente por não ser modificado, isso é um bug desta versão 0.2.1 pois ainda precisamos criar a funcionalidade no GitDocker para filtrar arquivos modifieds e untrackeds que será implementado nas novas funções. Porém, ainda precisamos fazer funcionar se alterássemos o conexao.h, justamente por isso deixei a criação da função **db_update()** pro final, veja só:

<img src="https://imgur.com/J1wwwEB.png" alt="Atualizando o arquivo conexao.h com db_update()">

Adicionamos a função db_update() a descrevendo com description, e claro, devemos também adicionar uma mudança mínima (mesma que uma mera quebra de linha) nos arquivos que serão processados que é o **loja.cpp** e **sistema.gitdock** atualmente (Isto será corrigido nas próximas versões onde não precisará mais fazer mudanças mínimas), para adicioná-los no estado de modified pro GitDocker. Veja abaixo como será a execução:

<img src="https://imgur.com/yVsgJjG.png" alt="Realizando init do conexao.h com db_update()">

Perceba-se que agora commitamos o **criar CRUD do banco de dados** juntamente com suas descrições das 4 funções. É dado antes os logs de informações dizendo quais commits já foram efetuados e poderemos ver pelo comando **git status** que os arquivos commitados sumiram da área de estados modificados:

<img src="https://imgur.com/6MsS9OF.png" alt="Git status">

E com o **git log** vemos quais foram os nossos commits:

<img src="https://imgur.com/YBotx1G.png" alt="Git log dos arquivos">

E pra finalizar esta sessão, executamos novamente o GitDocker para tentar commitar os arquivos, foram eles já estão atualizados e nos dará esta mensagem:

<img src="https://imgur.com/Q6VqqTK.png" alt="Arquivos atualizados">

Os 5 commits do nosso sistema de loja já está armazenado no array JSON de forma ordenada e a ferramenta git já efetuou todos os commits, agora o que nos resta é enviar remotamente estas alterações pro GitHub, porém é claro que nós estamos numa pasta teste e não commitamos exatamente todos os arquivos. Como **config.json**, **info.json**,a deleção de um arquivo chamado **commit.gitdock** que utilizamos pra explicar as sessões anteriores e o próprio executável **GitDocker.exe** que é claro, ele não estará nesta pasta após a release, pois teremos um sistema de instalação do GitDocker que poderá executar em qualquer local do PC, juntamente com sua pasta **config/** que estará na pasta de instalação. 

E se tentarmos como teste enviar remotamente pro GitHub, adicionando todos estes arquivos da pasta de teste **MyProject** na staged area, commitando-os e executando o **git push** a mensagem que nos dará é:

<img src="https://imgur.com/n5tuwtn.png" alt="Tentando enviar remotamente">

Teremos um simples erro dizendo que não pode ler do repositório remoto, justamente porque não temos um repositório criado no GitHub, algo que foi explicado anteriormente no início da sessão do **Comando commit**, pois estamos trabalhando apenas com uma pasta de testes que apesar de termos inicializado o git com o **git init**, não criamos o repositório na plataforma GitHub. Após criar o repositório na plataforma GitHub, dê o **git clone** com o link do seu repositório remoto e a partir daí, trabalhando em cima da pasta clonada, você pode fazer o envio remoto. 

A partir daqui, nas próximas sessões, veremos sobre o novo comando que será criado - o `@branch` que vai realizar a mesma operação do **git checkout** e o **git push** para subir todos os arquivos commitados para a branch do repositório remoto, assim você poderá especificar uma nova branch (Se optar) ou a branch main e subir remotamente para a branch selecionada, isso será feito nas próximas versões de 0.2.3 à 0.2.5.

**Nota:** _Primeiramente será resolvido o bug de tentar processar arquivos que não estão no estado de modificados, deveremos filtrar arquivos untrackeds e modifieds na versão 0.2.2_

<a name="comm-bran"></a>
## Comando Branch

Quando você está trabalhando com desenvolvimento de softwares, há uma grande necessidade de dividir o seu desenvolvimento em etapas. Algumas destas etapas podem conter apenas correções de bugs anteriores, uma nova funcionalidade ou até melhorias nas funções existentes, porém muito se sabe que nem tudo são flores, porque há um cenário possível de acontecer quando se trata de desenvolvimento, este cenário é o de **perda de modificações**. Suponhamos que você está programando um biblioteca virtual para oferecer 20 funcionalidades bem específicas, ao longo do tempo tudo vai bem mas na 13ª funcionalidade o seu software começa a parar de funcionar, bugs e bugs surgem e por semanas você não consegue resolver. Se você tivesse uma espécie de "Cópia" do ponto em que este sistema estava funcionando, você poderia restaurar para este ponto para entender o que você modificou e o que possívelmente pode ter causado o problema que parece insolucionável. É aqui que entra o conceito de **branchs**.

As branchs além de possibilitar um backup de todas as suas modificações, ela organiza ainda mais o seu desenvolvimento em partes bem definidas e específicas. Imagine um livro de muitos capítulos, cada capítulo com suas próprias histórias, assim seria o seu software contendo várias branchs e cada branch com suas próprias funcionalidades. Você pode dividir cada versão do software para uma nova branch, ou um dos números consecutivos da versão, a forma de organização só depende de como você trabalha no desenvolvimento.

As branchs permitem, no seu repositório local, que diferentes modificações coexistam em um mesmo espaço, ou seja, você tem um diretório na sua máquina e este diretório ele terá diversas cópias do seu mesmo projeto mas cada cópia contendo atualizações diferentes, onde as cópias mais atualizadas podem ter as mesmas funções das cópias anteriores. Na ferramenta **git** para se criar uma branch, você precisa primeiro começar na branch principal, chamada de **main**. É a partir daí que seu desenvolvimento se inicia e para criar uma nova branch, basta executar o comando **git checkout -b nome-da-branch**, onde você substitui o **nome-da-branch** pela seu próprio nome, um nome coerente ao que você está desenvolvendo naquela versão. Automaticamente, quando você cria uma nova branch, o git navega até ela, e em cima dela você desenvolve suas novas funções. Digamos que você já criou e desenvolveu em 5 branchs, porém você precisa voltar pra 3ª branch, então apenas execute o comando **git checkout nome-da-terceira-branch**, este comando sem o parâmetro **-b** vai apenas "Navegar" até a 3ª branch, e tudo o que você vai ver é seus arquivos do projeto sendo alterados/restaurados para o mesmo estado de quando você estava desenvolvendo nesta 3ª branch.

Após criar uma nova branch e efetuar as correções/modificações em cima dela, você precisa executar o comando **git push origin nova-branch**, onde o nome **nova-branch** será substituída pelo nome da branch que você criou. Este último comando é para atualizar o seu repositório remoto com o seu repositório local, isto é, subir todas as suas modificações desta branch da sua máquina para a plataforma GitHub. Após isto, o seu repositório no GitHub terá um novo link para ser redirecionado para a nova branch, contendo seus próprios commits e te recomendando a criar uma nova **Pull Request** que são requisições com descrições das suas modificações, também sendo uma espécie de "preparação" para efetuar o **merging** ou **Mesclagem** e o início de análises dos códigos, onde você pode mesclar as modificações da sua nova branch com a branch principal **main** caso não há nenhum conflito de mesclagem, estes conflitos você pode resolver durante as análises. A branch main é aquela que está na página inicial, onde todos podem ver de forma rápida e visível, a que deve sempre está atualizada. Nesta sessão vamos entender como utilizar o comando `@branch` do GitDocker para efetuar todas estas operações do git.

## Utilizando o comando Branch

O comando `@branch` espera um valor, que é uma String colocada após o comando. Esta String pode ser a própria main, Ex.: `@branch main` ou uma nova branch como `@branch nova-funcionalidade`. Primeiramente, o GitDocker verifica se esta branch **nova-funcionalidade** existe no array **branch** do arquivo **info.json**, caso não existir, ele cria uma nova branch com este nome e todos os comandos commits/descriptions que estiverem após o comando `@branch`, é processado em cima desta nova branch, ou seja, se temos 3 commits, os 3 commits serão relacionados a **nova-funcionalidade**. Se o nome desta branch existir no arquivo **info.json**, o GitDocker vai apenas alternar para esta branch (Neste caso após os commits serem efetuados) e depois é preciso que você faça o **git merge** para branch que estava anteriormente com a branch alternada, assim os novos commits serão transferidos para a branch atual alternada. Na ferramenta git você faria **git merge branch-atual nova-funcionalidade -X theirs**, pois sem estes **-X theirs** você precisaria resolver os conflitos manualmente, agora na ferramenta GitDocker é apenas necessário fazer: **gitdocker --merge** e o próprio GitDocker vai saber qual estratégia de merge utilizar e em quais branchs.

Assim como nos comandos `@commit` e `@description`, o comando `@branch` só é possível processar uma única vez em cada execução, isto é, a cada execução do GitDocker que possuir um novo commit ativo pra ser processado após o comando branch, para processar vários novos comandos consecutivos, basta inserir um novo parâmetro CLI da versão 0.2.4 que é a **--recursive**. Este parâmetro é inserido após o nome de arquivo na execução do parâmetro **--init** e serve para processar de forma recursiva o executável do GitDocker dentro do próprio GitDocker, desta forma é possível efetuar todos os novos commits, descriptions e branchs, ignorando aqueles que já foram criados. Após commitar/descrever as alterações na versão atual do seu software (branch atual), o GitDocker realiza o git push automaticamente, enviando ao repositório do GitHub as suas novas modificações, incluindo a sua nova branch. A partir de agora veremos como commitar alterações em cima da branch main e de outras novas:

1. Primeiramente, crie um novo repositório no GitHub no botão abaixo:

<img src="https://imgur.com/nWwWTUe.png" alt="Criando um repositório">

2. Na tela que irá aparecer, dê um nome ao repositório, insira uma descrição, marque como público ou privado e adicione um README:

<img src="https://imgur.com/RQaFDDr.png" alt="Colocando nome no repositório">

3. Role a página e Clique no botão **Create repository** para criar o repositório:

<img src="https://imgur.com/g57FazR.png" alt="Criando um repositório pelo botão">

4. Perceba que nós temos nossa descrição no README, um botão de **Add File** para adicionar arquivos no próprio GitHub, o **Code** para clonar o repositório e apontado pelas setas vermelhas, o nome da nossa branch **main**, na outra seta aponta a quantidade de branchs que é **1 branch**, esta é a branch principal onde vai nossos arquivos de código-fonte principais mais atualizados:

<img src="https://imgur.com/vZbevTT.png" alt="Visual do repositório main">

<a name="step5"></a>
5. Clique no botão **Code** e irá aparecer 2 links disponíveis, o **HTTPS** e o **SSH**, poderá escolher qualquer um dos links, porém só escolha SSH se tiver configurado a chave SSH na sua máquina. Vamos escolher o link **HTTPS** que abre como padrão, clique no botão apontado pela outra seta vermelha para copiar o link:

<img src="https://imgur.com/WeyTxgt.png" alt="Link para clonar repositório">

6. Antes de tudo, certifique-se que você baixou e instalou a ferramenta **git** [clicando aqui](https://git-scm.com/downloads). Atualmente na data da escrita desta documentação o git está na versão 2.37.3 que contém novos recursos, incluindo a execução dos comandos git pelo **prompt de comando**, isto é o que nos possibilita executar os comandos git dentro do código-fonte do GitDocker, então não se esqueça de marcar esta opção quando tiver instalando o git. Em qualquer diretório, execute o **Git Bash** para abrir o terminal do git, porém decidi abrir no **Disco Local C:** clicando com o botão direito do mouse sobre a pasta do disco local C: e clicando em **Git Bash Here**:

<img src="https://imgur.com/SaNpYWB.png" alt="Abrindo o Git Bash">

7. Após abrir a tela do Terminal, digite o comando **git clone link-do-seu-repositorio.git** para clonar o seu repositório. Substitua o **link-do-seu-repositorio.git** pelo link HTTPS que você copiou no <a href="#step5">passo 5</a>, após digitar o comando e colar o link, dê enter e aparecerá estas informações:

<img src="https://imgur.com/iMivqtY.png" alt="Clonando o repositório pelo link HTTPS">

8. Se aparecer estas informações significa que acabamos de baixar a pasta do nosso repositório para o Disco Local C: e inicializar o git nela. No nosso caso, clonamos o repositório **branch_doc** onde faremos os testes do GitDocker:

<img src="https://imgur.com/ue8w93S.png" alt="Pasta do branch_doc no disco local C">

<a name="step9"></a>
9. Perceba que nós temos também uma pasta chamada **gitd** que está o executável do GitDocker, certifique-se de criar esta pasta no Disco Local C: e executar o **Build.bat** para compilar o projeto do GitDocker para esta pasta, também configure nas **variáveis de ambiente** nas variaveis de sistema **path** (se você tiver utilizando a plataforma Windows) o seguinte caminho **C:\gitd\**:

<img src="https://imgur.com/nFWw4KG.png" alt="Variaveis de ambiente do GitDocker">

10. Porém, isto se você tiver clonando o repositório do GitDocker, mas o instalador do GitDocker feito em outras versões fará isso automaticamente. Então abra a pasta do repositório que você clonou, no nosso caso o **branch_doc** apontado pelo <a href="#step9">passo 9</a> e insira 2 pastas neste diretório: A pasta **configs** que terá o arquivo **config.json** e a pasta **infos** que terá o arquivo **info.json** Estas 2 pastas com estes arquivos estão no repositório do GitDocker que você provavelmente já clonou pra sua máquina, apenas copie-os e cole-os dentro de **branch_doc**:

<img src="https://imgur.com/8cvayx9.png" alt="Pasta configs e infos do GitDocker">

11. Inicialmente os arquivos estarão configurados desta maneira:

### Arquivo config.json

<img src="https://imgur.com/FrO2NTh.png" alt="Arquivo config.json">

### Arquivo info.json

<img src="https://imgur.com/Fg3Jaq5.png" alt="Arquivo info.json">

O arquivo **config.json** é para configurações de extensões aceitas pelo GitDocker, no qual você poderia inserir manualmente novas extensões ou executando o parâmetro CLI --config, que poderá ser apresentado em outras sessões (Na data que você estiver lendo esta documentação, este arquivo pode ter mudado, contendo novos valores) e o arquivo **info.json** com informações de versões, commits, descrições, branchs criadas e dados para merge. O info.json é de fato o arquivo que será constantemente lido e escrito pelo software GitDocker durante as operações de comandos e este arquivo definitivamente será uma parte do seu projeto de software (Exceto o config.json em outras versões que fará parte do GitDocker), o info.json também poderá ser integrado como uma API para outras versões.

12. Crie um arquivo de qualquer nome ou extensão (desde que esteja configurada no config.json) na pasta que você clonou. Vamos criar um projeto simples em linguagem C++ para testar os comandos branch, commit e description, então criaremos um arquivo chamado **main.cpp** no editor VSCode:

<img src="https://imgur.com/LUJsmNn.png" alt="Projeto em Linguagem C++">

A partir daqui, vamos começar a desenvolver nossas funções, documentando-as e versionando-as usando o GitDocker. Criaremos um projeto simples de calculadora pra ser executado no CMD. Vamos dividir nosso desenvolvimento em etapas começando da versão 0.0 e a cada função, aumentaremos o número **menor** ou _minor_ que é o 2ª número, quando nosso sisteminha estiver pronto, zeramos o minor e aumentamos o número **maior** ou _major_ que é o 1ª número. Estes números de versão vamos inserir no nome de toda branch após o nome **calc**. Em outras sessões em versões futuras do GitDocker falaremos mais sobre a **versão semântica** e como ela vai funcionar no GitDocker utilizando outros comandos.

Agora vamos adicionar entre a abertura e fechadura do **comentário de bloco** alguns dados pra descrever nosso software, começando por **Autor**, **Data** e **Programa** com uma descrição simples:

<img src="https://imgur.com/KKiGAd2.png" alt="Descrição inicial do software">

Lembrando que estas descrições não são comandos portanto não influencia no GitDocker no entanto futuramente terão outros comandos para descrever melhor o software, inserir números de versões e data de compilação. Antes de tudo, execute um `git add *` e `git commit -m "Salvando untrackeds"`, pois nesta versão atual durante a escrita desta documentação há um problema pra ser resolvido com arquivos untrackeds, então abra seu terminal CMD ou Bash no VSCode e digite os comandos do git:

<img src="https://imgur.com/Zf12GXx.png" alt="Salvando untrackeds">

Optei por utilizar o Bash do VSCode porque ele mostra o nome da branch atual acima da linha de comando e ainda aceita a coloração das informações do GitDocker (O que não acontece com o Git Bash fora do VSCode, mas aceita no CMD fora do VSCode também), ainda não vou executar o git push para atualizar o repositório remoto, vou deixar que o próprio GitDocker faça isto pra gente. Como inicialmente vamos trabalhar com a branch main, vamos inserir ela abaixo das descrições juntamente com o comando de commit e description, que será antes da nossa função principal **main()** em C++:

<img src="https://imgur.com/jZeTqHR.png" alt="Utilizando branch, commit e description">

Inserimos o comando `@branch` com o nome **main** após o comando, um commit e uma description. Note que nosso commit e description está totalmente de acordo com o que realmente estamos fazendo que é criar uma função main() vazia, onde será um código principal para chamada de outras funções. Inicialmente ainda não vamos compilar o projeto, apenas executamos o GitDocker via linha de comando para processar os comandos acima. 

Como pode ver na imagem abaixo, o nosso arquivo main.cpp está no estado de modificado, então podemos efetuar as operações sem problema:

<img src="https://imgur.com/ew2PRSb.png" alt="Estado de modificado do main.cpp">

A branch main será gerada no **info.json** e vai verificar se algum commit está sendo efetuado (que no caso está), caso sim, ele efetua o commit nesta branch e realiza o git push para subir remotamente para a branch clonada, então na linha de comando digite **gitdocker --init main.cpp** e veja o resultado:

<img src="https://imgur.com/P6wmq6K.png" alt="Executando o GitDocker para main.cpp">

Ele apresenta os logs de informações do commit e description em verde e também o log de informação do comando `@branch` dizendo que a branch main foi criada, porém o próprio git identifica como **Fatal Error** pois não é possível criar uma branch que já está criada, como a própria main. No entanto, ignore esta mensagem se tiver executando nesta mesma data, pois isto será corrigido em outras versões do GitDocker. Então, as informações sendo escritas de cor branca são as do próprio git, efetuando o commit pelo comando `@commit` e subindo o projeto pro GitHub através do **git push**.

Digite **git status** pra verificar os estados dos arquivos:

<img src="https://imgur.com/I2l7PSG.png" alt="Branch up-to-date">

Não contém nenhum arquivo modificado e a branch main do repositório local está **up-to-date**, isto é, atualizado com o repositório remoto de **origin/main**. Agora veremos no repositório remoto do GitHub os nossos arquivos e commits:

<img src="https://imgur.com/CwKNHzB.png" alt="Arquivos no repositório remoto">

Teremos o nosso commit **Insere funcao main() vazia** e a descrição quando apontado a seta do mouse para a mensagem de commit, contendo a mesma descrição que colocamos no comando `@description`. Também teremos o commit **Salvando Untrackeds** que atualmente está na pasta **Configs**, porém ela também estava na pasta **Infos**, porém um segundo commit **substituiu** a mensagem "Salvando Untrackeds" da pasta Infos, este segundo commit é o **Commit automatico do GitDocker** que no final efetua este commit pois após os commits do usuário (Feitos pelo comando `@commit`), o arquivo **info.json** ainda é alterado pelo GitDocker, então para ser possível o envio remoto pelo git push, é preciso efetuar um último commit automatico, pra deixar tudo em ordem. Atualmente existem 2 commits automaticos no software GitDocker, porém estamos vendo apenas 1 na tela.

De agora em diante, veremos a criação das próximas funções, onde cada branch será uma nova versão contendo a nova função.

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


