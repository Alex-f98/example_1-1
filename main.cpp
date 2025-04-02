#include "mbed.h"
#include "arm_book_lib.h"

//cinco.
/*

*/

int main()
{
    // Definodo D2(un enum de mbed hacia de dir. mem. del pin D2) como gasDetector de tipo DigitalIn.
    DigitalIn gasDetector(D2);

    // Definodo LED1 como alarmLed como tipo DigitalOut.
    DigitalOut alarmLed(LED1);

    // En gasDetector por ser entrada activo MODO pull down.
    //https://alihamdan.id/wp-content/uploads/2022/12/pull-up-resistor.jpg
    gasDetector.mode(PullDown);

    //Inicializo en OFF (OFF=0) a alarmLed(LED1).
    alarmLed = OFF;

    // Las direcciones de memroia de los puertos estan en definidas en ST en un struct.
    // hay dos struct que definer numeros y con ello se obtiene los puertos necesarios.
    // DigitalIn.h esta en mbed_gpio en una clase de gpio define como pines de proposito general y v inciando constructores
    // segun los argumetos


    // ON = !0
    // SuperLoop: si se detecta gas    -> enciende alarma.
    //            si no se detecta gas -> alarma apagada.
    while (true) {
        if ( gasDetector == ON ) {
            alarmLed = ON;
        }
        
        if ( gasDetector == OFF ) {
            alarmLed = OFF;
        }
    }
}

// Las definiciones de que TARGET usar esta en CMakeList.txt es una variable TARGET definida en .mbed
// Esa variable la modifica la IDE web y en base a eso la usa el CMake. y luego con ellos compila.

// En mbed-os estan los targets que serian las distintas placas.
// En algun punto se tiene que definir cual de ellas usar y en base a eso
// se decide que tipo de mapeo hacer.
// La IDE online selecciona el TARGET desde la opccion "Build target" y modifica el archivo .mbed
// TARGET=NUCLEO_F429ZI el cual es usado como variable de entorno detro del cmakelist necesario para 
// la compilacion.

//En "compile_commands.json" estan los comandos para la commpilacion.

