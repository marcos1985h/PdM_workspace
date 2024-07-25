Punto 1: Implementación de la MEF Anti-rebote en main.c

    Crear un nuevo proyecto como copia del proyecto realizado para la práctica 3.
    Implementar una MEF anti-rebote que permita leer el estado del pulsador de la placa NUCLEO-F429ZI y generar acciones ante un flanco descendente o ascendente, según el siguiente diagrama:

MEF Diagram

    El estado inicial de la MEF debe ser BUTTON_UP.
    Implementar las siguientes funciones dentro de "main.c":

    void debounceFSM_init();    // debe cargar el estado inicial
    void debounceFSM_update();  // debe leer las entradas, resolver la lógica de transición de estados y actualizar las salidas
    void buttonPressed();       // debe invertir el estado del LED1
    void buttonReleased();      // debe invertir el estado del LED3
