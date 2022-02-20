#define redled 9       //This will define "redled" as number 9 whenever it occurs again in code

#define greenled 8     //This will define "greenled" as number 8 whenever it occurs again in code

#define BuzzerPin 7    //This will define "BuzzerPin" as number 7 whenever it occurs again in code

#define FlamePin 5     //This will define "FlamePin" as number 5 whenever it occurs again in code

 

boolean Flame_Sensor_Value = HIGH;    //This variable will store the value of Flame Sensor

 

void setup()  //This will run only once and at the start of the program

{

  /*By using pinMode function we will declare state 

   * of each pin as Output/Input depending on their nature

   * We use OUTPUT when we have to define the output state of the pin (0/5V)

   * We use Input when we have to read

   */

  pinMode(BuzzerPin, OUTPUT);

  pinMode(redled, OUTPUT);

  pinMode(greenled, OUTPUT);

  pinMode(FlamePin, INPUT);

  Serial.begin(9600);   //Set the baud rate to 9600 bit per second

}

 

void loop()   //This will run indefinitely till the program is terminated

{

  Flame_Sensor_Value = digitalRead(FlamePin); //Store the value of sensor in this variable

 

  if (Flame_Sensor_Value == LOW)  //check if condition matches with fire detection state

  {

    /*Turn on Indicators*/

    digitalWrite(BuzzerPin, HIGH);    // Turn Buzzer on

    digitalWrite(redled, HIGH);       // Turn Red LED on

    digitalWrite(greenled, LOW);      // Turn Green LED off

   

    /*Responsible for sending SMS*/

    Serial.println("AT+CMGF=1");                 //Selects SMS message format as TEXT

    delay(1000);                                 // Delay of 1 second

    Serial.println("AT+CMGS=\"+8801762259976\""); // Replace x with mobile number

    Serial.println("Fire Detected!!! at Uttara,sector 6 House_97,road-20");         // The SMS text you want to send

    Serial.println((char)26);

    delay(500);

   

    /*Responsible for making a CALL*/

    Serial.println("ATD+ +8801762259976;"); // Replace x with your mobile number

    delay(5000);                          //Wait for Call to reach

    Serial.println("ATH");                 //Hang up the Call

  }

  else

  {

 

    digitalWrite(BuzzerPin, LOW);          // Turn Buzzer off

    digitalWrite(greenled, HIGH);          // Turn Green LED on

    digitalWrite(redled, LOW);             // Turn Red LED off

  }

}
