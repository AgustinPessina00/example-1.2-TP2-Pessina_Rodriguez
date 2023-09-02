#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    /*
    * DigitalIn es una clase. Tiene un constructor, que instancia un objeto DigitalIn pasando por parámetro un PIN
    * (D2 y D3). Estos están definidos mediante un tipo enumerativo PinName en "PinNames.h".
    * Tenemos sobrecarga de constructores, en este caso, utilizamos el constructor que permite conectar el PIN requerido
    * y lo inicializa en modo PullDefault. El Constructor llama a una función que se encarga de inicializar el atributo
    * gpio (Una estructura) que mapea con los registros del microcontrolador. 
    * El atributo gpio (estructura) se definé como protegido, por lo que si utilizamos herencia en alguna clase que creemos
    * vamos a poder acceder al atributo desde la clase hija.
    */
    DigitalIn gasDetector(D2);
    DigitalIn overTempDetector(D3);
   
    /*
    * Idem para Clase DigitalOut. En este caso carga el PIN indicado (LED1) como salida. Son dos clases distintas, con
    * métodos diferentes, pero con el mismo atributo de la estructura gpio.
    */
    DigitalOut alarmLed(LED1);
   
    /*
    * Se llama a uno de los métodos de la clase DigitalIn (mode(PinMode)) y le pasa el modo del PIN. En este caso se elige
    * un PullDown.
    */
    gasDetector.mode(PullDown);   
    overTempDetector.mode(PullDown);

    while (true) {
    
        if ( gasDetector || overTempDetector ) {
            /*
            * El operador "=" está sobrecargado en la clase DigitalOut. En este caso, al pasarle un entero, setea la salida
            * en un estado alto o bajo. Esto lo hace seteando las vriables set o clr de la estructura gpio y luego mapea con
            * los registros del microcontrolador
            */
            alarmLed = ON;
            printf("%s%s\n", "El sensor de gas está ", gasDetector ? "ACTIVADO" : "DESACTIVADO");
            printf("%s%s\n", "El sensor de sobretemperatura está ", overTempDetector ? "ACTIVADO" : "DESACTIVADO");
            printf("%s\n" , "El estado de la alarma es ACTIVADO.");
        } else {
        alarmLed = OFF;
        printf("%s\n" , "El estado de la alarma es DESACTIVADO.");
        }
    }
}