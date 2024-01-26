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

  // Detecta si pulso el boton de activar/desactivar
  if (digitalRead(pulsaActivar) == LOW ) {
    delay(400); // delay para evitar efecto rebote

    if (estado == 0) { // si esta desactivada
      estado = 1; // la activamos
    }
    else { // sino (esta activada)
      estado = 0; // la desactivamos
    }
  } // fin if pulsador

  if (digitalRead(pulsaPuerta) == LOW ) { // detectamos la apertura de puerta
    estado = 2;
  } // fin pulsador puerta

  if (estado == 0) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, HIGH);
  }
  if ( estado == 1) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarillo, LOW);
  }
  if ( estado == 2) {
    digitalWrite(bocina, HIGH);
  }

} // fin loop




/*
       if (digitalRead(ledVerde) == LOW) { // si el led verde esta apagado, lo enciendo
         digitalWrite(ledVerde, HIGH);
         digitalWrite(ledAmarillo, LOW);
       }
       else { // SINO lo apago
         digitalWrite(ledVerde, LOW);
         digitalWrite(ledAmarillo, HIGH);
       }
*/


