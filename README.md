# Tarefa01_0602
Tarefa 1 - Unidade 4 - Capítulo 7 - PWM

Funcionamento do Código
O servomotor começa na posição de 180°, aguarda 5 segundos.

Em seguida, move-se para 90°, aguarda 5 segundos.

Depois, move-se para 0°, aguarda 5 segundos.

Após essas posições, entra em um loop infinito de movimentação suave entre 0° e 180°.


# Item 06 da tarefa
No item 06 da tarefa, foi solicitado um experimento com o código deste exercício utilizando o LED RGB – GPIO 12 (cor azul). O código configura o GPIO 12 como saída PWM com uma frequência de 50 Hz (período de 20 ms). O ciclo ativo (duty cycle) do PWM varia entre 500 µs (0 graus) e 2400 µs (180 graus).   
O LED RGB se comportará como um indicador de intensidade luminosa. A cor correspondente ao GPIO 12 variará de acordo com o ciclo ativo do PWM:
1) Quando o ciclo ativo for 500 µs (0 graus), a intensidade da cor será mínima.  
2) Quando o ciclo ativo for 2400 µs (180 graus), a intensidade da cor será máxima.  
3) Durante a movimentação periódica, a intensidade da cor variará suavemente entre mínima e máxima.  
