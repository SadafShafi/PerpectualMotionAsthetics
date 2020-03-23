int hsInp1 = 3;
int hsInp2 = 5;
int hsInp3 = 7;
int eMagnet = 12;
int LP39D = 13;

unsigned long startTime;
unsigned long endTime;
int distance = 10000;
int limitSpeed = 1150;

float rodSpeed;
unsigned long duration;

int ranStopCount[3] = {0, 1, 2};

int jupiter = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(hsInp1, INPUT);
  pinMode(hsInp2, INPUT);
  pinMode(hsInp3, INPUT);
  pinMode(eMagnet, OUTPUT);
  pinMode(LP39D, OUTPUT);

  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LP39D, HIGH);
  digitalWrite(eMagnet, LOW);

  if (digitalRead(hsInp1) == LOW || digitalRead(hsInp3) == LOW) {
    startTime = millis();

  } else if (digitalRead(hsInp2) == LOW && startTime > 0) {
    if (jupiter == 0) {
      endTime = millis();

      duration = endTime - startTime;
      rodSpeed = (float)((distance / duration));
      Serial.println(rodSpeed);

      if (rodSpeed < limitSpeed) {
        digitalWrite(eMagnet, HIGH);
        delay(370);
      } else if (rodSpeed > limitSpeed) {
        jupiter = ranStopCount[rand() % 2];
      }

      startTime = 0;
    }
  } else if (jupiter > 0) {
    jupiter--;
  }

//  startTime = 0;

}

