void setup() {
  
  
  // inicia com 9600 
  Serial.begin(9600); 
}

void loop() {
  
  // parte do yago: definir a lógicas variáveis e como será a entrada/saída dos dados
  // parte do Luiz Covas: definir como será as estruturas de controle para cada tipo de variável
  // parte do Thomaz: ajudou na representação do sistema  
  // parte da Raab: ajudou a montar o código e transformar em C arduino
  // parte da Eduarda: codou a parte do CNH
  // parte do Marcos: ajudou na definição da lógica e variáveis
  // parte do Mauricio: ajudou na integração dos códigos com a duda e raab
  
  
  // Começando o cadastro
  Serial.println("BEM VINDO AO CADASTRO DOS QUE FORAM"); 

  
  
  // Capturando a idade do usuário 
  Serial.print("Digite sua idade: ");
  
  // esperando que o usuário digite o valor fornecido
  while (!Serial.available()) {} 
  
  // transforma o dado fornecido em inteiro 
  int age = Serial.parseInt(); 

  
  if(age < 18)
  {
    // Printando a idade do usuário e informando sua categoria (menor de idade)
  	Serial.println(" Sua idade: " + String(age) + "anos." + ". Faixa de idade: menor de idade."); 
  }
  
  else if(age >= 18 && age <60)
  {
    // Printando a idade do usuário e informando sua categoria (adulto)
  	Serial.println("Sua idade: " + String(age) + "anos." + "Faixa de idade: adulto."); 
    
    Serial.print("Vamos tirar a CNH (responda com sim ou nao)? ");
    
    // esperando que o usuário digite o valor fornecido
    while (!Serial.available()) {} 
    
    
    String answer = Serial.readString();
    
    if(answer == "sim")
    {
      Serial.println("agora pode dirigir barco");
    }
    
    if(answer == "nao")
    {
      Serial.println("adquira sua CNH agora na conta da raab, gratuitamente");
    }
  }
  
  else
  {
    // Printando a idade do usuário e informando sua categoria (Idoso)
  	Serial.println("Sua idade: " + String(age) + "anos." + "Faixa de idade: Idosa."); 
  }
  

  // Coleta o nome do usuário
  Serial.print("Digite seu nome: ");
  
  // esperando que o usuário digite o valor fornecido
  while (!Serial.available()) {} 
  
  // Lê a string passada
  String name = Serial.readString(); 
  
  
  // Imprime o nome do usuário 
  Serial.println("Seu nome: " + name); 

  // Coleta o dado sobre o estado civil do usuário
  Serial.print("Estado civil: Casado(a) ?  (responda com c ou s)");
  
  // booleano para identificar o estado civil do usuário
  while (!Serial.available()) {} 
  
  String civilStatus = Serial.readString();
  
  
  // verifica a entrada do usuario
  if(civilStatus == "c")
  {
    bool civilStatusBool;
    civilStatusBool = true;
  }
  
  if(civilStatus == "s")
  {
    bool civilStatusBool;
    civilStatusBool = false;
  }
    
 
  bool civilStatusBool;
  // lógica de recebimento do valor para o booleano acima
  if(civilStatusBool == true)
  {
    
  	Serial.println("foi um belo casamento ! ");
  }
  if(civilStatusBool == false)
  {
	Serial.println("seu amor ainda vai nascer");
  }
  


  // Solicita a altura do usuário em metros
  Serial.print("Digite sua altura em metros: ");
  
  // esperando que o usuário digite o valor fornecido
  while (!Serial.available()) {} 
  
  // passa a altura para float 
  float height = Serial.parseFloat(); 
  Serial.println("Sua altura: " + String(height) + " m"); 
  
  // finaliza o cadastro do usuário
  Serial.println("Obrigado por se cadastrar ! Agora, faremos um novo cadastro.");
  
  // Aguarda um pouco antes de pedir as informações novamente
  delay(4000);
}
