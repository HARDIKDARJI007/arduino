const int a = 2;  //For displaying segment "a"
const int b = 3;  //For displaying segment "b"
const int c = 4;  //For displaying segment "c"
const int d = 5;  //For displaying segment "d"
const int e = 6;  //For displaying segment "e"
const int f = 7;  //For displaying segment "f"
const int g = 8;  //For displaying segment "g"

bool bPress = false;
const int buttonPin = 10;

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  // put your setup code here, to run once:
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G

  pinMode( buttonPin , INPUT_PULLUP );
  Serial.begin(9600);
  displayDigit(buttonPushCounter);
}

void loop() {

   buttonState = digitalRead(buttonPin);
   Serial.println(buttonState);

   // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == LOW) {
      // if the current state is HIGH then the button went from off to on:
      bPress = true;
      buttonPushCounter--;
      if( buttonPushCounter < 0) buttonPushCounter =9 ;
      Serial.println("on");
    
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;

  if( bPress ){
     turnOff();
     displayDigit(buttonPushCounter);
     Serial.println();
  }


}



void displayDigit(int digit)
{
 //Conditions for displaying segment 1
 if(digit==1 ){
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);       //Generating 1
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);}

 //Conditions for displaying segment 2
 if(digit ==2){
 digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);      //Generating 2
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);}

 //Conditions for displaying segment 3
 if(digit ==3){
 digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);      //Generating 3
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);}

 //Conditions for displaying segment 4
 if(digit == 4)
{ digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);     //Generating 4
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);}

 //Conditions for displaying segment 5
 if(digit == 5){
 digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);     //Generating 5
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);}

 //Conditions for displaying segment 6
 if(digit == 6){
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);    //Generating 6
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);}

 //Conditions for displaying segment 7
 if (digit == 7){
 digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);   //Generating 7
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);}
  
  //Conditions for displaying segment 8
 if (digit == 8){
  digitalWrite(a, LOW );
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);     //Generating 8
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
 }

  //Conditions for displaying segment 9
 if (digit == 9){
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);    //Generating 9
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
 
 }
  
Serial.println(digit);
}
void turnOff()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
