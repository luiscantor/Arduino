# HC-SR501

int ledPin = 13;                // choose the pin for the LED
int inputPin = 8;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

int _ledPin = 9;
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(_ledPin, OUTPUT);
 
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  
  if (val == HIGH)	// check if the input is HIGH
  {            
    digitalWrite(ledPin, HIGH);  // turn LED ON
	
    if (pirState == LOW) 
	{
      Serial.println("Motion detected!");	// print on output change
      pirState = HIGH;

      digitalWrite(_ledPin, HIGH);
      delay(2000);

      digitalWrite(_ledPin, LOW);
      delay(1000); // Wait for 1 second
    }
  } 
  else 
  {
    digitalWrite(ledPin, LOW); // turn LED OFF
	
    if (pirState == HIGH)
	{
      Serial.println("Motion ended!");	// print on output change
      pirState = LOW;
    }
  }
}
