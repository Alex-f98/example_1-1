#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    //Entrada digital para gas detector
    DigitalIn gasDetector(D2);

    // Salida digital para ALARMA
    DigitalOut alarmLed(LED1);

    // MODO pull dom D2
    gasDetector.mode(PullDown);

    //Inicializo en OFF LED1.
    // nose
    alarmLed = OFF;

    // Las direcciones de memroia de los puertos estan en definidas en ST en un struct.
    // hay dos struct que definer numeros y con ello se obtiene los puertos necesarios.
    // DigitalIn.h esta en mbeg_gpio en una clase de gpio define como pines de proposito general y v inciando constructores
    // segun los argumetos
    while (true) {
        if ( gasDetector == ON ) {
            alarmLed = ON;
        }
        
        if ( gasDetector == OFF ) {
            alarmLed = OFF;
        }
    }
}