#**Processamento de bebidas**

- Victor Otávio Nogueira Sales   558460 
- Matheus Santos de Almeida      558249


##**1 Introdução**

Este trabalho tem como foco impletar em um Arduino um sistema para controlar um processo industrial de mistura de liquidos. Os líquidos são misturados pelo motor de passos e o processo é dividido em várias etapas que são mostradas em um Display LCD. Outros dispositivos como botões e LEDS foram usadas para simular o funcionamento do processo.


##**2 Abordagem**

###**2.1 Materiais e métodos**

<p style="text-align: justify;">Usamos uma placa Arduino Mega e os seguintes componentes do Grove - Starter kit: um Led Azul, um Led Vermelho, um botão, dois sensores de toque e um shield.</p>

###**2.2 Processo**

<p style="text-align: justify;">O processamento de líquidos é divido em várias etapas. O processo está no estado inicial, o segundo estado é deflagrado quando um botão é pressionado. Primeiramente, o líquido 1 é admitido no compartimento de mistura, isso acontece pela abertura de um cano, quando o líquido atingiu um determinado nível (altura), um sensor é acionado e o cano é fechado; o líquido 1 é agitado pelo motor de passos, que gira no sentido anti-horário a 50 rpm, por 30 segundos. Em seguida, o líquido 2 é admitido pela abertura de um segundo cano; novamente, a mistura atinge um nível determinado e um segundo sensor, que se encontra exatamente na altura em que o líquido deve chegar, é ativado. A solução de líquido 1 e líquido 2 é agitada por 30 segundos e, desta vez, o motor gira no sentido anti-horário. Por fim, há uma espera de 30 segundos e o processo volta ao estado incial.</p>


##3 **Esquemático**

![Clique aqui para ver o esquemático.](http://i.imgur.com/ru0nGjU.jpg?1)

##4 **Vídeo de demonstração**

[![Trabalho Final MIC](http://img.youtube.com/vi/J-q5R4f5pd8/0.jpg)]
(http://www.youtube.com/watch?v=J-q5R4f5pd8)
