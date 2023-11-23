# Human-Computer-Interface-Glove-for-Sign-Language-Translation

https://hackaday.io/project/167663-human-computer-interface-glove-for-sign-language
https://www.slideshare.net/ParnikaGupta5/human-computer-interface-glove-for-sign-language-translation

Aims translating sign language via text to speech for mute people that includes a user friendly glove with flex sensor and adafruit. Team of 3 students, designing a glove for deaf and dumb people (sign to speech conversion) using teensyduino, adafruit BNO055 and flex sensors that would give audio output with different patterns of hand movements through a mobile application (speaking serial monitor).  All components will be placed on the back side of the glove providing the user with full range of motion, and not restricting the user from performing other tasks while wearing the glove.
Embedded code in the Teensyduino

This code enables the connection between the teensyduino and the app on the mobile via bluetooth where two movements have been converted to speech:

1. For change in 'value' of flex sensor, the app will say 'DRINK WATER'.

2. For change in the 'event.orientation.y' of adafruit, the app will say 'HELP ME'.

NOTE: Flex sensor and the adafruit measures the finger and the axis movement respectively and are fabricated on the glove. Like wise many commands can be given for different values generated by the hand movements.
