The following code implements the above functionality.


int RMotor_1 = 2; # Front Right Motor is Connected to Pin 2 of Arduino UNO
int RMotor_2 = 3; # Back Right Motor is Connected to Pin 3 of Arduino UNO
int LMotor_1 = 4; # Front Left Motor is Connected to Pin 4 of Arduino UNO
int LMotor_2 = 5; # Back Left Motor is Connected to Pin 4 of Arduino UNO
int REnable = 10; # Right Motor Enable is Connected to Pin 10 of Arduino UNO
int LEnable = 11; # Left Motor Enable is Connected to Pin 11 of Arduino UNO


/* The setup() function is called when a sketch starts. Use it to initialize variables
pin modes, start using libraries, etc. The setup() function will only run once, after each powerup or reset of the Arduino board. */


void setup() {
  Serial.begin(9600);
  pinMode(RMotor_1, OUTPUT);
  pinMode(RMotor_2, OUTPUT);
  pinMode(LMotor_1, OUTPUT);
  pinMode(LMotor_2, OUTPUT);
  pinMode(REnable, OUTPUT);
  pinMode(LEnable, OUTPUT);

  analogWrite(10, 210); # Used to Set the Speed of Right Motors
  analogWrite(11, 210); # Used to Set the Speed of Left Motors

}

/* The loop() function runs forever i.e it does the functionality of the system */

void loop() {
  
  # The Light Detector Module returns 0 if the intensity of the light is high else 1

  int ldrright = digitalRead(7); # The Right Light Detector Module is connected to Pin 7 of Arduino UNO
  int ldrleft = digitalRead(8);  # The Left Light Detector Module is connected to Pin 8 of Arduino UNO

  if (ldrright == 0 && ldrleft == 0) {
    Serial.println("Forward"); 
    move_forward(); # Routine for moving the vehicle forward
  }
  if (ldrright == 0 && ldrleft == 1) {
    Serial.println("Right");
    turn_right(); # Routine for moving the vehicle Right
  }
  if (ldrright == 1 && ldrleft == 0) {
    Serial.println("Left");
    turn_left(); # Routine for moving the vehicle Left
  }
  if (ldrright == 1 && ldrleft == 1) {
    Serial.println("Stop");
    move_stop(); # Routine to Stop the vechicle
  }
  delay(100);

}

// Functions to Control the Rotation of Motors

void move_forward() {
  digitalWrite(RMotor_1, LOW);
  digitalWrite(RMotor_2, HIGH);
  digitalWrite(LMotor_1, HIGH);
  digitalWrite(LMotor_2, LOW);
}

void turn_right() {
  digitalWrite(RMotor_1, LOW);
  digitalWrite(RMotor_2, HIGH);
  digitalWrite(LMotor_1, LOW);
  digitalWrite(LMotor_2, HIGH);
}

void turn_left() {
  digitalWrite(RMotor_1, HIGH);
  digitalWrite(RMotor_2, LOW);
  digitalWrite(LMotor_1, HIGH);
  digitalWrite(LMotor_2, LOW);
}

void move_stop() {
  digitalWrite(RMotor_1, LOW);
  digitalWrite(RMotor_2, LOW);
  digitalWrite(LMotor_1, LOW);
  digitalWrite(LMotor_2, LOW);
}
