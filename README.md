# Mentes³ 🧠

CESAR School | Programação Imperativa e Funcional - 2024.2

## Descrição
Mentes³ é um jogo da forca que desafia seu raciocínio lógico ao mesmo tempo que se diverte! Desenvolvido em C, o game é jogado no terminal, onde você tentará adivinhar as letras de palavras secretas. Para cada letra correta, você acumula pontos. No entanto, a cada letra errada, uma parte do corpo será mostrada e o jogo fica mais próximo de terminar. E daí GAME OVER. Será que você consegue desvendar a palavra e alcançar o máximo de pontos?

## Time
- Débora Buriti (@debburiti)
- Mirella Santana (@mihebs)
- Myllena Navarro (@Myllena-lins)

## Regras do game
- O objetivo é adivinhar as letras da palavra secreta antes que o desenho do corpo seja completado.
- A cada letra correta, você ganha 5 pontos.
- A cada erro, uma parte do corpo será desenhada e você perde 3 pontos.
- Se o corpo for completamente desenhado, você perde o jogo.

## Procedimentos (compilação | execução)
Para compilar e executar esse jogo de forca em C, você precisará seguir alguns procedimentos específicos, que incluem a configuração do ambiente de desenvolvimento e o entendimento das funções de cada arquivo.

1. Estrutura do Código e Arquivos
O código está dividido em vários arquivos .h e .c que juntos implementam a mecânica do jogo:

- *Keyboard.h e Keyboard.c*: Controlam a captura de entrada do teclado.
- *Screen.h e Screen.c*: Gerenciam a exibição de elementos na tela, incluindo desenhos de bordas, cursor e cores.
- *Timer.h e Timer.c*: Controlam o temporizador do jogo.
- *Main.c*: Gerencia a lógica principal do jogo, incluindo inicialização, controle de tentativas, exibição da palavra e gerenciamento da pontuação.

Cada arquivo .h é um "header" que declara funções e macros, enquanto os arquivos .c implementam as funções.

2. Compilação
Para compilar o código, você precisa usar um compilador C, como gcc. Siga esses passos:

1. Navegue até o diretório onde os arquivos estão localizados.
2. Execute o comando abaixo para compilar todos os arquivos:
   bash
   gcc Main.c Keyboard.c Screen.c Timer.c -o main
   
   Esse comando compila cada arquivo .c e gera um executável chamado main.

3. Execução
Depois de compilar, você pode executar o jogo com o seguinte comando:
bash
./main


4. Implementação e Mecânica do Jogo
Abaixo, explico a mecânica de cada parte do jogo, desde a entrada de dados até a atualização da tela e controle do tempo.

- *Entrada do Teclado* (Keyboard.c): A função keyhit() verifica se uma tecla foi pressionada, e get_input() captura o caractere pressionado. Elas usam configurações do terminal para evitar a exibição do caractere e o modo "canônico".

- *Exibição e Controle de Tela* (Screen.c): 
  - O código usa sequências de escape ANSI (definidas em Screen.h) para controlar a tela e aplicar cores.
  - A função screenDrawBorders() desenha as bordas da área de jogo.
  - screenForca() desenha o "boneco da forca" dependendo do número de erros.
  - screenTrofeu() e screenCaveira() mostram mensagens de vitória ou derrota.

- *Temporizador* (Timer.c): 
  - A função timerInit() inicia o tempo máximo do jogo.
  - timerTimeOver() verifica se o tempo acabou, comparando o tempo atual com o tempo inicial.

- *Lógica do Jogo* (Main.c): 
  - A função initializeForca() inicializa a estrutura Forca, configurando o nome do jogador, a palavra secreta e as tentativas.
  - Durante o jogo, showPalavra_secreta() exibe a palavra oculta com as letras descobertas.
  - showLetra_certa() verifica se a letra escolhida está na palavra e atualiza o estado do jogo.
  - checkVictory() verifica se o jogador acertou toda a palavra.
  - showgameOver() exibe uma mensagem final caso o jogador perca.

Esse conjunto de funções cria uma interação básica de um jogo de forca, permitindo que o jogador tente adivinhar uma palavra dentro de um número limitado de tentativas e tempo, com feedback visual na tela.

## Observações
- Este jogo funciona por meio do terminal.
- Não é compatível com sistemas Windows devido ao uso da biblioteca CLI-lib. Utilize Linux ou macOS.

## Implementação da mecânica
- Ao implementar a biblioteca com os arquivos screen, timer e keyboard como cabeçalhos, começamos a construir os seus respectivos módulos na pasta source e incluí-los na main.
Para o arquivo keyboard.c, tivemos o objetivo de configurar corretamente as capturas de entradas de teclado, sem exibir os caracteres mostrados na tela. O usuário deve inserir as letras presentes no teclado, de acordo com o que ele acredita ser a letra correspondente da palavra secreta. Portanto, alterar as funcionalidades das letras do teclado não é necessário.

 - Para o arquivo timer.c, construímos a lógica do temporizador. Por meio de funções, o timer controla o tempo decorrido entre um momento inicial e um momento atual. Ele armazena o horário de início e calcula a diferença entre esse horário  e o horário atual a cada consulta. Um valor de atraso em milissegundos é configurado para o temporizador, determinando o tempo máximo permitido antes de “expirar”.
  Quando o temporizador é iniciado, o programa armazena o horário atual e define o valor de atraso desejado. Cada vez que é verificado, o temporizador calcula a diferença entre o horário atual e o horário de início. Se essa diferença ultrapassar o valor de atraso configurado, considera-se que o tempo “acabou”. Esse mecanismo é útil para monitorar intervalos de tempo e reagir após um período específico, permitindo ajustes e configurações conforme necessário durante a execução do programa

 - Para o arquivo screen.c, construímos a interface com caracteres ASCII, uma função para bem vindo, o desenho da forca, imagem de erro e o troféu.

 - Para o main.c,  é feita da seguinte maneira: Iniciar o jogo chamando uma função para dar Bem-vindo aos jogadores, pedindo para o usuário inserir seu nome. A partir disso, entrará a tela com a palavra que é para encontrar, a dica acima da palavra, a parte de pontuação zerada, o cronômetro no meio da borda superior e as letras que não acertou.  A medida que o jogador for acertando, este  ganhará 5 pontos e caso erre perderá 3 pontos, e simultaneamente rodará o temporizador. A partir disso, ficará no histórico tudo que foi tido.


   
