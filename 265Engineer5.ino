int Pump = 2;
int lights = 3;
int LightStatus = A0;
int WaterLevel = A1;


void setup() {
  // put your setup code here, to run once:
  pinMode(WaterLevel, INPUT);
    pinMode(LightStatus, INPUT);
  pinMode(Pump , OUTPUT);
  pinMode(lights , OUTPUT);
 Serial.begin(9600);
}



void loop() {
  // put your main code here, to run repeatedly:
waterSystem();
//Serial.println(analogRead(LightStatus));
Serial.println(analogRead(WaterLevel));

delay(1000);
}



void waterSystem ()
{
 WaterControl();
 lightStatus(); 
}



void WaterControl()
{

 if (analogRead(WaterLevel)<=264)
  {
    digitalWrite(Pump , LOW);
    Serial.println("water Pump Turned Off");
  }
  else if (analogRead(WaterLevel)>264)
  {
    digitalWrite(Pump , HIGH);
    Serial.println("water Pump Turned ON");
  }

}

void lightStatus ()
{
 
Serial.println(analogRead(LightStatus));
if(analogRead(LightStatus) <= 50)
{
  digitalWrite(lights , HIGH);
  Serial.println("ON");
}
else if(analogRead(LightStatus) > 50)
 {
  digitalWrite(lights , LOW);  
  Serial.println("OFF");
}
 
}