# Range Alert System Using Arduino
## Date 
6th April, 2024
## By
[Oluwabiyi Boluwatife](https://github.com/BoluBiyi03)
# Introduction 
The Range Alert System, utilizing Arduino and the HC-SR04 ultrasonic sensor, represents a significant advancement in safety technology. By leveraging the precision of ultrasonic waves for distance measurement and the versatility of Arduino for real-time data processing, this system offers a robust solution for various safety challenges. Whether it's maintaining safe distances in industrial environments or assisting individuals with visual impairments in navigating public spaces, the Range Alert System provides accurate distance monitoring and timely alerts based on predefined thresholds. With endless customization possibilities and the potential for integration with other sensors and technologies, this system has the capacity to revolutionize safety standards across industries, ultimately leading to safer workplaces and environments.
# Problem Statement 
In today's fast-paced world, ensuring safety across different environments is crucial. However, current safety measures often struggle to effectively handle changing situations and potential dangers. For example, in industrial settings, accidents are still a risk due to limited real-time monitoring of distances between workers and machinery. Likewise, people with visual impairments encounter difficulties navigating public areas safely, as current aids may not promptly warn them about obstacles ahead. This underscores the urgent need for a dependable and adaptable safety solution that can accurately track distances and give timely alerts to reduce risks and prevent accidents. Therefore, the challenge is to create an affordable and user-friendly range alert system that utilizes technology to elevate safety standards in various sectors, ultimately safeguarding individuals and fostering safer environments for everyone.
# Require Hardware 
The following hardware component listed below was used for the coupling and assembling of the **Range Alert System**;

1) Aruino Board 
2) HC-SR04
3) 220 ohms Resistors
4) Jumper Wires 
5) Breadboard
6) LEDs (Red,Yellow,Green)

# Circuit Design
[schematic design]()

[circuit diagram]()
# Source Code 
``` cpp
/* 
This is an Ultrasonic Sensor Project
By Oluwabiyi Boluwatife 
Title - Range Alert System Using Arduino and HC-SR04
The purpose of this invention is to alert humans against an obstacles 
This is the code written to be imported on the Arduino Board 
*/

// Define the pins for the HC-SR04 Ultrasonic Sensor 
const int trigPin = 0;
const int echoPin = 1;

//Define pins for the LEDs 
const int red_led = 8;
const int yellow_led = 9;
const int green_led = 10;

//Define the threshold distance for each LEDs that would be triggered
const int redThreshold = 10;
const int yellowThreshold = 20;
const int greenThreshold = 50;

void setup()
{
  // Initialize serial communication debugging 
  Serial.begin(9600);

  //Set the defined pins for the HC-SR04 as input/output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Set the defined pins for the LEDs as input/output
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delay(200);
  digitalWrite(trigPin, HIGH);
  delay(200);
  digitalWrite(trigPin, LOW);
  delay(200);

  //Measure the pulse duration for the ultrasonic sensor 
  long duration = pulseIn(echoPin, HIGH);

  //Calculate the distance based on the speed of sound 
  int distance = duration * 0.034 / 2;

  //Print distance to the serial monitor for debugging 
  Serial.print("Distance: ");
  Serial.println(distance);

  //Check distance against threshold and trigger LEDs 
  if (distance >= greenThreshold)
  {
    digitalWrite(red_led, LOW);
    digitalWrite(yellow_led, LOW);
    digitalWrite(green_led, HIGH);
  }
  else if (distance >= yellowThreshold)
  {
    digitalWrite(red_led, LOW);
    digitalWrite(yellow_led, HIGH);
    digitalWrite(green_led, LOW);
  }
  else if (distance >= redThreshold)
  {
    digitalWrite(red_led, HIGH);
    digitalWrite(yellow_led, LOW);
    digitalWrite(green_led, LOW);
  }
  
  else
  {
    digitalWrite(red_led, LOW);
    digitalWrite(yellow_led, LOW);
    digitalWrite(green_led, LOW);  
  }

  delay(100);


}
```
# HEX File 
[text](ultrasonic_sensor_sketch/ultrasonic_sensor_sketch.ino.hex)
# Working Principles 
The project operates by utilizing an ultrasonic sensor, specifically the **HC-SR04**, to gauge distances accurately. This sensor emits ultrasonic waves and measures the time taken for these waves to bounce back after hitting an object, allowing for precise distance calculations. Acting as the central processing unit, an Arduino board receives distance measurements from the ultrasonic sensor and interprets them based on predetermined parameters and thresholds. The system establishes predefined distance thresholds to classify safety levels, determining appropriate actions or alerts based on the measured distance. LED indicators serve as visual cues to convey the safety status, with different colors representing various safety levels such as safe, cautionary, or hazardous. Continuous real-time monitoring enables the system to trigger alerts promptly if the measured distance surpasses predefined thresholds, ensuring timely warnings and proactive risk management. Through these integrated principles, the project aims to develop a range alert system that effectively monitors distances, provides timely alerts, and enhances safety across different environments, contributing to accident prevention and the overall well-being of individuals.
# Advantages 
The following below are the benefits of this invention which they are ;

1. **Enhanced Safety Standards :** The project significantly improves safety standards in various environments by providing real-time distance monitoring and timely alerts. This proactive approach helps prevent accidents and mitigate risks, ultimately fostering a safer environment for individuals.

2. **Versatility and Adaptability:** The system's versatility allows it to be customized and adapted to diverse applications and industries. Whether in industrial settings, public spaces, or assisting individuals with visual impairments, the range alert system can be tailored to suit specific needs and environments.

3. **Cost-effectiveness:** Utilizing affordable components such as Arduino boards and HC-SR04 sensors, the project offers a cost-effective solution for enhancing safety measures. This makes it accessible for implementation across different sectors and organizations, regardless of budget constraints.

4. **Ease of Use:** With its user-friendly interface and straightforward operation, the range alert system is easy to set up and deploy. Minimal training is required for users to understand and utilize the system effectively, making it accessible to a wide range of users.

5. **Promotes Proactive Risk Management:** By continuously monitoring distances and providing real-time alerts, the project promotes proactive risk management practices. This proactive approach enables organizations and individuals to identify and address potential hazards before they escalate into accidents, leading to improved safety outcomes and reduced liabilities.
# Disadvantage
Here are some of the disadvantages of the invention ;

1. **Limited Range:** The HC-SR04 ultrasonic sensor has a limited range, typically up to a few meters. This limitation may restrict the applicability of the system in scenarios where longer distance monitoring is required, such as large industrial facilities or outdoor environments.

2. **Interference and False Readings:** Ultrasonic sensors can be susceptible to interference from ambient noise, echoes, or reflective surfaces. These factors may lead to inaccurate distance measurements and false readings, compromising the reliability of the system.

3. **Maintenance and Durability:** Like any electronic system, the range alert system requires regular maintenance to ensure proper functionality. Components such as the ultrasonic sensor and Arduino board may degrade over time, requiring replacement or repairs to maintain optimal performance. Additionally, exposure to harsh environmental conditions or physical damage could affect the durability and longevity of the system.

While the range alert system offers significant benefits in enhancing safety standards, addressing these potential disadvantages through proper planning, maintenance, and ongoing optimization is crucial to maximize its effectiveness and reliability in real-world applications.
# Output
[picture]()

[video]()
# Summary and Conclusion 
The range alert system project introduces a innovative safety solution that combines Arduino technology with the HC-SR04 ultrasonic sensor to enhance safety standards across various environments. By continuously monitoring distances and providing real-time alerts based on predefined thresholds, the system proactively identifies potential hazards and mitigates risks, ultimately promoting a safer environment for individuals. With its versatility and adaptability, the system can be customized to suit diverse applications, from industrial workplaces to public spaces, addressing the specific safety needs of different sectors.

Despite its advantages, the project also faces potential limitations, such as the HC-SR04 sensor's limited range and susceptibility to interference, as well as dependency on continuous power and the complexity of calibration. Additionally, maintenance and durability considerations highlight the need for ongoing care and optimization to ensure the system's long-term reliability. By addressing these challenges and leveraging the system's strengths, the range alert project holds promise in significantly improving safety standards and fostering a culture of proactive risk management in various environments.




















