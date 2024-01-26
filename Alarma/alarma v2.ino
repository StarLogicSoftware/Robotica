#define ledAmarillo 6
#define ledVerde 5
#define bocina 4
#define pulsaActivar 3
#define pulsaPuerta 2

int estado = 0;
// 0 -> desactivada, 1 -> activada, 2 -> disparada

void setup() {
  pinMode(pulsaActivar , INPUT_PULLUP);
  pinMode(pulsaPuerta , INPUT_PULLUP);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(bocina, OUTPUT);

  digitalWrite(ledAmarillo, HIGH);
}

void loop() {
//------------ PULSADOR ACTIVAR / DESACTIVAR ------------------------------------------
  // Detecta si pulso el boton de activar/desactivar
  if (digitalRead(pulsaActivar) == LOW ) {
    delay(400); // delay para evitar efecto rebote

    if( estado != 0 ){
      estado = 0;
    }
    else{
      estado = 1;
    }
  } // fin if pulsador

//------------ PULSADOR PUERTA ------------------------------------------
  if (digitalRead(pulsaPuerta) == LOW ) { // detectamos la apertura de puerta
    if(estado == 1){ // solo si la alarma esta activada (estado 1)
      estado = 2;
    }
  } // fin pulsador puerta
  
//------------ MANEJO DE LEDS ------------------------------------------
  if (estado == 0) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, HIGH);
    digitalWrite(bocina, LOW);
  }
  if ( estado == 1) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarillo, LOW);
  }
  if ( estado == 2) {
    digitalWrite(bocina, HIGH);
  }

} // fin loop

