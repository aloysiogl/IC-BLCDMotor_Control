Planta = tf([13.095],[2.66*10^(-6) 0.0171 1])

figure
bode(Planta)
figure
step(Planta)
Kp = 2.8522
Ki = 104.55

Controlador = tf([Kp + Ki], [1 0])

Sistema = Controlador*Planta

feedback(Sistema,1)

margin(feedback(Sistema,1))

figure
bode(feedback(Sistema,1))