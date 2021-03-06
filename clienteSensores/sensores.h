// Sensor Presencia

// Set pines...
int pirState = LOW;           // de inicio no hay movimiento
int val = 0;                  // estado del pin

// Configurar presencia

void configurarSensorPresencia (int ledPin, int pirPin) {
  pinMode(ledPin, OUTPUT); 
  pinMode(pirPin, INPUT);
}

// Leer presencia

int16_t leerSensorPresencia (int ledPin, int pirPin) {
  val = digitalRead(pirPin);
   if (val == HIGH)   //si está activado
   { 
      digitalWrite(ledPin, HIGH);  //LED ON
      if (pirState == LOW)  //si previamente estaba apagado
      {
        Serial.println("Sensor presencia activado");
        pirState = HIGH;
        return 1;
      }
   } 
   else   //si esta desactivado
   {
      digitalWrite(ledPin, LOW); // LED OFF
      if (pirState == HIGH)  //si previamente estaba encendido
      {
        Serial.println("Sensor presencia parado");
        pirState = LOW;
        return 0;
      }
   }
}

// Sensor Capacitativo

/*int16_t leerSensorCapacitativo (int pinCapacitativo) {
  if (digitalRead(pinCapacitativo) == HIGH)   //si está activado
    Serial.println("Sensor capacitativo activado");
    return 1;
  } else{
    Serial.println("Sensor capacitativo parado");
    return 0; 
  }
}*/