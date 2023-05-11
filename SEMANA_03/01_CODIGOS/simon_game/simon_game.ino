// Pinagem dos Leds
#define LedVermelho 16
#define LedAmarelo 17
#define LedVerde 18
#define LedAzul 19

// Pinagem dos botões
#define buttonRes 15  // Botão de reset
#define buttonVm 32
#define buttonAm 33
#define buttonVd 34
#define buttonAz 35

// Variáveis globais
int sequencia[32] = {};
int botoes[4] = {buttonVm, buttonAm, buttonVd, buttonAz};
int leds[4] = {LedVermelho, LedAmarelo, LedVerde, LedAzul};
int rodada = 0;
int passo = 0;
int botao_pressionado;
bool game_over = false;
bool iniciar_jogo = false;
int pontuacao = 0;

void setup() {
  // Inicialização dos Leds e botões
  pinMode(LedVermelho, OUTPUT);
  pinMode(LedAmarelo, OUTPUT);
  pinMode(LedVerde, OUTPUT);
  pinMode(LedAzul, OUTPUT);
  pinMode(buttonVm, INPUT);
  pinMode(buttonVd, INPUT);
  pinMode(buttonAz, INPUT);
  pinMode(buttonAm, INPUT);
  pinMode(buttonRes, INPUT);

  Serial.begin(115200);
}
void loop() {

  if (digitalRead(buttonRes) == HIGH) {
    iniciar_jogo = true;
    Serial.print("Começou o jogo");
  }

  if (iniciar_jogo == true) {
    proximaRodada();
    pontuacao = rodada;
    Serial.print("Pontuação: ");
    Serial.println(pontuacao);
    reproduzirSequencia();
    aguardarJogador();

    // Estrutura para reiniciar as variáveis
    if (game_over == true) {
      resetarJogo();
    }

    delay(1000);
  }
}

// Funções
void proximaRodada() {
  int sorteio = random(4);
  sequencia[rodada] = sorteio;
  rodada += 1;
}

void reproduzirSequencia() {
  for (int i = 0; i < rodada; i++) {
    digitalWrite(leds[sequencia[i]], HIGH);
    delay(1000);
    digitalWrite(leds[sequencia[i]], LOW);
    delay(100);
  }
}

void aguardarJogador() {
  for (int i = 0; i < rodada; i++) {
    bool jogada_efetuada = false;
    while (jogada_efetuada == false) {
      for (int j = 0; j < 4; j++) {
        if (digitalRead(botoes[j]) == HIGH) {
          botao_pressionado = j;
          digitalWrite(leds[j], HIGH);
          delay(300);
          digitalWrite(leds[j], LOW);
          jogada_efetuada = true;
        }
        if (digitalRead(buttonRes) == HIGH){
          game_over = true;
        }
      }
    }

    if (sequencia[passo] != botao_pressionado) {
      game_over = true;
      break;
    }

    passo += 1;
  }

  passo = 0;
}

void resetarJogo() {
  for (int i = 0; i < 32; i++) {
    sequencia[i] = 0;
  }
  for (int l = 0; l < 5; l++){
    for (int k = 0; k < 4; k++) {
      digitalWrite(leds[k], HIGH);
      delay(50);
      digitalWrite(leds[k], LOW);
      delay(50);
    }
  }
  rodada = 0;
  passo = 0;
  game_over = false;
  iniciar_jogo = false;
}