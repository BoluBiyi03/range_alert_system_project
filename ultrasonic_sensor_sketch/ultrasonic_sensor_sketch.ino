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