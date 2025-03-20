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

    // Las definiciones de que TARGET usar esta en CMakeList.txt es una variable TARGET definida en .mbed
    // Esa variable la modifica la IDE web y en base a eso la usa el CMake. y luego con ellos compila.
    while (true) {
        if ( gasDetector == ON ) {
            alarmLed = ON;
        }
        
        if ( gasDetector == OFF ) {
            alarmLed = OFF;
        }
    }
}


// En mbed-os estan los targets que serian las distintas placas.
// En algun punto se tiene que definir cual de ellas usar y en base a eso
// se decide que tipo de mapeo hacer.