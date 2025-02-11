# Tarefa01_0602
Tarefa 1 - Unidade 4 - Capítulo 7 - PWM

Esta tarefa contém um código em C para controlar um servomotor utilizando PWM (Pulse Width Modulation) no Raspberry Pi Pico. O código permite posicionar o servomotor em diferentes ângulos (0°, 90° e 180°) e também realiza uma movimentação periódica suave entre 0° e 180°.

# Componentes necessários  
1) Microcontrolador Raspberry Pi Pico W.  
2) Servomotor – motor micro servo padrão – Wokwi (conectado ao pino GPIO 22).  
3) LED RGB - Gpio 12 (item 6 da tarefa).  
  
# Funcionamento do Código  
1) O servomotor começa na posição de 180°, aguarda 5 segundos.  
2) Em seguida, move-se para 90°, aguarda 5 segundos.  
3) Depois, move-se para 0°, aguarda 5 segundos.  
4) Após essas posições, entra em um loop infinito de movimentação suave entre 0° e 180°.  

# Item 06 da tarefa
No item 06 da tarefa, foi solicitado um experimento com o código deste exercício utilizando o LED RGB – GPIO 12 (cor azul). O código configura o GPIO 12 como saída PWM com uma frequência de 50 Hz (período de 20 ms). O ciclo ativo (duty cycle) do PWM varia entre 500 µs (0 graus) e 2400 µs (180 graus).   
O LED RGB se comportará como um indicador de intensidade luminosa. A cor correspondente ao GPIO 12 variará de acordo com o ciclo ativo do PWM:
1) Quando o ciclo ativo for 500 µs (0 graus), a intensidade da cor será mínima.  
2) Quando o ciclo ativo for 2400 µs (180 graus), a intensidade da cor será máxima.  
3) Durante a movimentação periódica, a intensidade da cor variará suavemente entre mínima e máxima.

OBS: no código do experimento, só é necessário substituir na definição das variáveis: #define SERVO_PIN 22 ---> #define SERVO_PIN 12

# Link do video  
https://drive.google.com/file/d/1pKDFy6szUcOp3LPMldaZtbf05byBTm54/view?usp=sharing  
  
# Desenvolvido por   
Priscila Pereira Suzart de Carvalho
