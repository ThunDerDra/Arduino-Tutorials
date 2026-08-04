int buttonpin = 12;
int ledpin = 9;
int dt = 50;
int brightup = 10;
int brightdown = 11;
int brightness = 255;

bool currentstate;
bool laststate = HIGH;
bool ledstate = false;
bool brightinc;
bool brightdec;

void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(buttonpin, INPUT);
  Serial.begin(9600);
  digitalWrite(ledpin, LOW);

}

void loop() {
  currentstate = digitalRead(buttonpin);
  brightinc = digitalRead(brightup);
  brightdec = digitalRead(brightdown);
    
  Serial.println(currentstate);
  delay(dt);

  if (laststate == HIGH  &&  currentstate == LOW) {
    ledstate = !ledstate;
    if(ledstate){ 
    analogWrite(ledpin, brightness);
    }
    else {
    analogWrite(ledpin, 0);
    }
    delay(dt);
  } 

  laststate = currentstate;

  if (brightinc == LOW  &&  brightness < 255) { 
    if(ledstate){
    brightness += 17;
    analogWrite(ledpin, brightness);
    }
  }

  if (brightdec == LOW &&  brightness > 0) {
    if(ledstate){
    brightness -= 17;
    analogWrite(ledpin, brightness);
    }
  }
}
