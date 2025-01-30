// Define motor driver pins
#define ENA 9  // Enable pin for motor A
#define IN1 8  // Motor A input 1
#define IN2 7  // Motor A input 2
#define IN3 6  // Motor B input 1
#define IN4 5  // Motor B input 2
#define ENB 10 // Enable pin for motor B

// Define ultrasonic sensor pins
#define TRIG 11
#define ECHO 12

// Define IR sensor pins
#define IR_LEFT A0  // Left IR sensor
#define IR_RIGHT A1 // Right IR sensor

void setup() {
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENB, OUTPUT);
    
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    
    pinMode(IR_LEFT, INPUT);
    pinMode(IR_RIGHT, INPUT);
    
    Serial.begin(9600); // Debugging via Serial Monitor
}

// Function to measure distance using ultrasonic sensor
int getDistance() {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    
    long duration = pulseIn(ECHO, HIGH);
    int distance = duration * 0.034 / 2; // Convert to cm
    
    return distance;
}

// Function to move forward
void moveForward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 150); // Adjust speed
    analogWrite(ENB, 150);
}

// Function to move backward
void moveBackward() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
}

// Function to turn left
void turnLeft() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
}

// Function to turn right
void turnRight() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
}

// Function to stop the car
void stopCar() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
}

void loop() {
    int distance = getDistance();
    int irLeft = digitalRead(IR_LEFT);
    int irRight = digitalRead(IR_RIGHT);

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" | IR Left: ");
    Serial.print(irLeft);
    Serial.print(" | IR Right: ");
    Serial.println(irRight);

    if (distance > 15 && irLeft == 1 && irRight == 1) {  
        // No obstacles detected
        moveForward();
    } 
    else {  
        // Obstacle detected, take action
        stopCar();
        delay(500);
        moveBackward();
        delay(500);
        
        if (irLeft == 0) {
            turnRight(); // If left sensor detects obstacle, turn right
        } else if (irRight == 0) {
            turnLeft(); // If right sensor detects obstacle, turn left
        } else {
            turnLeft(); // Default turn left if ultrasonic detects obstacle
        }

        delay(500);
        stopCar();
    }
}
