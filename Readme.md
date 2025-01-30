# Obstacle Avoidance Robot Using Ultrasonic and IR Sensors

This project is an Arduino-based obstacle-avoiding robot that uses both **ultrasonic** and **infrared (IR) sensors** for navigation. The robot moves forward while continuously scanning for obstacles. If an obstacle is detected, it stops, moves backward, and changes direction accordingly.

## Features
- **Ultrasonic Sensor**: Measures the distance to objects and prevents collisions.
- **IR Sensors**: Detects obstacles on the left and right sides.
- **Motor Driver (L298N or similar)**: Controls the robot's movement.
- **Autonomous Navigation**: Automatically detects and avoids obstacles.

## Components Required
- Arduino Uno/Nano  
- L298N Motor Driver  
- Ultrasonic Sensor (HC-SR04)  
- IR Sensors (x2)  
- Two DC Motors  
- Wheels  
- Power Source (Battery)  
- Chassis  

## Wiring Diagram
| Component  | Arduino Pin |
|------------|------------|
| Motor A ENA | 9 |
| Motor A IN1 | 8 |
| Motor A IN2 | 7 |
| Motor B IN3 | 6 |
| Motor B IN4 | 5 |
| Motor B ENB | 10 |
| Ultrasonic TRIG | 11 |
| Ultrasonic ECHO | 12 |
| IR Sensor Left | A0 |
| IR Sensor Right | A1 |

## Installation & Usage
1. **Upload Code**:  
   - Open the Arduino IDE  
   - Copy and paste the provided code  
   - Select the correct **board** and **port**, then upload  

2. **Power the Robot**:  
   - Connect an appropriate battery pack  

3. **Observe Movement**:  
   - The robot should move forward and avoid obstacles automatically  

## Working Principle
1. **Ultrasonic Sensor** continuously checks for obstacles.  
2. **IR Sensors** detect objects on the left and right sides.  
3. If an obstacle is detected:
   - The robot stops and moves backward.  
   - If the left IR sensor is triggered, it turns right.  
   - If the right IR sensor is triggered, it turns left.  
   - If both IR sensors detect an obstacle, it defaults to turning left.  
4. The robot resumes forward motion after avoiding the obstacle.

## Contributing
Feel free to contribute by improving the code, adding features, or optimizing the movement logic.

## License
This project is open-source under the **MIT License**.
