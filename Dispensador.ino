// Definición de pines
const int trigPin = 9;
const int echoPin = 8;
const int relePin = 7;

void setup() {
  pinMode(trigPin, OUTPUT);  // Pin del Trigger como salida
  pinMode(echoPin, INPUT);   // Pin del Echo como entrada
  pinMode(relePin, OUTPUT);  // Pin del relé como salida
  
  digitalWrite(relePin, LOW);  // Inicialmente la bomba está apagada
  Serial.begin(9600);         // Inicializar la comunicación serial para monitorear
}

void loop() {
  // Enviar pulso de trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Medir el tiempo que tarda en recibir el eco
  long duration = pulseIn(echoPin, HIGH);
  
  // Calcular la distancia (en cm)
  int distance = duration * 0.034 / 2;
  
  // Mostrar la distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Encender la bomba si la distancia es menor o igual a 5 cm
  if (distance <= 5) {
    digitalWrite(relePin, HIGH);  // Encender bomba
    Serial.println("Bomba encendida");
  } else {
    digitalWrite(relePin, LOW);   // Apagar bomba
    Serial.println("Bomba apagada");
  }

  delay(500);  // Pequeño retraso para evitar lecturas muy rápidas
}