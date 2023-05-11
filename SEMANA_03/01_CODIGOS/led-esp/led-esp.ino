// Definição do pinagem
#define led1 32

void setup() {
  // Configura o pino do LED como saída
  pinMode(led1, OUTPUT);
}

void loop() {
  // Liga o LED
  digitalWrite(led1, HIGH);
  delay(1000);
  // Desliga o LED
  digitalWrite(led1, LOW);
  delay(300);
}

