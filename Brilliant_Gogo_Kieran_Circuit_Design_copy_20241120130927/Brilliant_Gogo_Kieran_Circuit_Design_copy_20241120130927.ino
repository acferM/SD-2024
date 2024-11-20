#define BUTTON_PIN 2
#define RED_LED_PIN 7
#define YELLOW_LED_PIN 6
#define GREEN_LED_PIN 5
#define MID 3
#define UP_LEFT 4
#define BOTTOM_LEFT 8
#define BOTTOM 9
#define BOTTOM_RIGHT 10
#define UP_RIGHT 13
#define POINT 11
#define UP 12

int buttonLastValue = 1;
bool hasCountStarted = false;

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(MID, OUTPUT);
  pinMode(UP_LEFT, OUTPUT);
  pinMode(BOTTOM_LEFT, OUTPUT);
  pinMode(BOTTOM, OUTPUT);
  pinMode(BOTTOM_RIGHT, OUTPUT);
  pinMode(POINT, OUTPUT);
  pinMode(UP, OUTPUT);
  pinMode(UP_RIGHT, OUTPUT);
}

void led_control(int number) {
  if (number == 0) {
    digitalWrite(UP_LEFT, HIGH);
    digitalWrite(BOTTOM_LEFT, HIGH);
    digitalWrite(BOTTOM, HIGH);
    digitalWrite(BOTTOM_RIGHT, HIGH);
    digitalWrite(UP_RIGHT, HIGH);
    digitalWrite(UP, HIGH);
    digitalWrite(MID, LOW);
  }

  if (number == 1) {
    digitalWrite(UP_LEFT, HIGH);
    digitalWrite(BOTTOM_LEFT, HIGH);
    digitalWrite(UP, LOW);
    digitalWrite(MID, LOW);
    digitalWrite(BOTTOM, LOW);
    digitalWrite(BOTTOM_RIGHT, LOW);
    digitalWrite(UP_RIGHT, LOW);
  }

  if (number == 2) {
    digitalWrite(UP, HIGH);
    digitalWrite(UP_RIGHT, HIGH);
    digitalWrite(MID, HIGH);
    digitalWrite(BOTTOM_LEFT, HIGH);
    digitalWrite(BOTTOM, HIGH);
    digitalWrite(UP_LEFT, LOW);
    digitalWrite(BOTTOM_RIGHT, LOW);
  }

  if (number == 3) {
    digitalWrite(UP, HIGH);
    digitalWrite(UP_RIGHT, HIGH);
    digitalWrite(MID, HIGH);
    digitalWrite(BOTTOM_RIGHT, HIGH);
    digitalWrite(BOTTOM, HIGH);
    digitalWrite(UP_LEFT, LOW);
    digitalWrite(BOTTOM_LEFT, LOW);
  }

  if (number == 4) {
    digitalWrite(UP_LEFT, HIGH);
    digitalWrite(MID, HIGH);
    digitalWrite(UP_RIGHT, HIGH);
    digitalWrite(BOTTOM_RIGHT, HIGH);
    digitalWrite(UP, LOW);
    digitalWrite(BOTTOM_LEFT, LOW);
    digitalWrite(BOTTOM, LOW);
  }

  if (number == 5) {
    digitalWrite(UP, HIGH);
    digitalWrite(UP_LEFT, HIGH);
    digitalWrite(MID, HIGH);
    digitalWrite(BOTTOM_RIGHT, HIGH);
    digitalWrite(BOTTOM, HIGH);
    digitalWrite(UP_RIGHT, LOW);
    digitalWrite(BOTTOM_LEFT, LOW);
  }

  if (number == 6) {
    digitalWrite(UP, HIGH);
    digitalWrite(UP_LEFT, HIGH);
    digitalWrite(MID, HIGH);
    digitalWrite(BOTTOM_LEFT, HIGH);
    digitalWrite(BOTTOM, HIGH);
    digitalWrite(BOTTOM_RIGHT, HIGH);
    digitalWrite(UP_RIGHT, LOW);
  }

  if (number == 7) {
    digitalWrite(UP, HIGH);
    digitalWrite(UP_RIGHT, HIGH);
    digitalWrite(BOTTOM_LEFT, HIGH);
    digitalWrite(UP_LEFT, LOW);
    digitalWrite(MID, LOW);
    digitalWrite(BOTTOM_LEFT, LOW);
    digitalWrite(BOTTOM, LOW);
  }

  if (number == 8) {
    digitalWrite(UP, HIGH);
    digitalWrite(UP_LEFT, HIGH);
    digitalWrite(UP_RIGHT, HIGH);
    digitalWrite(MID, HIGH);
    digitalWrite(BOTTOM_LEFT, HIGH);
    digitalWrite(BOTTOM_RIGHT, HIGH);
    digitalWrite(BOTTOM, HIGH);
  }

  if (number == 9) {
    digitalWrite(UP, HIGH);
    digitalWrite(UP_LEFT, HIGH);
    digitalWrite(UP_RIGHT, HIGH);
    digitalWrite(MID, HIGH);
    digitalWrite(BOTTOM_RIGHT, HIGH);
    digitalWrite(BOTTOM_LEFT, LOW);
    digitalWrite(BOTTOM, LOW);
  }
}

void count() {
  int buttonValue = digitalRead(BUTTON_PIN);
  buttonLastValue = buttonValue;
  int counter = 0;
  
  while (counter <= 9) {
  	counter += 1;
    led_control(counter);
    buttonValue = digitalRead(BUTTON_PIN);
    
    if (buttonValue != buttonLastValue) {
      if (buttonValue == 1) {
        hasCountStarted = false;
      	break;
      }
      
      buttonLastValue = buttonValue;
    }
    
    delay(1000);
  }
  
  if (counter <= 4) {
  	digitalWrite(YELLOW_LED_PIN, HIGH);
    return;
  }
  
  if (counter > 5) {
  	digitalWrite(RED_LED_PIN, HIGH);
    return;
  }
  
  digitalWrite(GREEN_LED_PIN, HIGH);
  return;
}

void loop()
{
  int buttonValue = digitalRead(BUTTON_PIN);
    
  if (buttonValue != buttonLastValue) {
    if (buttonLastValue == 0 && !hasCountStarted) {
      digitalWrite(YELLOW_LED_PIN, LOW);
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, LOW);
      hasCountStarted = true;
      count();
    }
    
  	buttonLastValue = buttonValue;
  }
  
  delay(100);
}