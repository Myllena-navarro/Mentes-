# Mentes³ 🧠

CESAR School | Programação Imperativa e Funcional - 2024.2

## Descrição
Mentes³ é um jogo da forca que desafia seu raciocínio lógico ao mesmo tempo que se diverte! Desenvolvido em C, o game é jogado no terminal, onde você tentará adivinhar as letras de palavras secretas. Para cada letra correta, você acumula pontos. No entanto, a cada letra errada, uma parte do corpo será mostrada e o jogo fica mais próximo de terminar. E daí GAME OVER. Será que você consegue desvendar todas as palavras e alcançar o máximo de pontos?

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
_(em processo de definição)_

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


   
