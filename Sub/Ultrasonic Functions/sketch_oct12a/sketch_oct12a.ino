void setup(){}
void loop(){}

bool ultraResult(int trigPin,int echoPin,int destance){
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);
 return (destance==(pulseIn(echoPin,HIGH)*0.017))? true : false;
}

int doUltraConfig (int trigPin ,int echopin)
{
  pinMode (trigPin,OUTPUT);
  pinMode (echopin ,INPUT);
}
 
