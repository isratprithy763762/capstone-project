Servo myServo; 

int trigPin = 8;
int echoPin = 9;

int trigPin2 = 10;
int echoPin2 = 11;

int ir=7;
int irval;
int g=3;
int y=4;
int r=5;
int buz=6;
int ldr=A3;
int ldrval;

int Nled = 14;
int infraNled = 13;

int val=0;



void setup() {
   Serial.begin(9600); 
   pinMode(Nled, OUTPUT);
   pinMode(infraNled, OUTPUT);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   
   pinMode(trigPin2, OUTPUT);
   pinMode(echoPin2, INPUT);

   pinMode(ir,INPUT);
   pinMode(ldr,INPUT);

   pinMode(buz,OUTPUT);
   pinMode(y,OUTPUT);
   pinMode(g,OUTPUT);
   pinMode(r,OUTPUT);

    myservo.attach(12);  

}

void loop() {

  irval=digitalRead(ir);
  Serial.print("IR:");
  Serial.println(irval);

  ldrval=analogRead(ldr);
  Serial.print("LDR:");
  Serial.println(ldrval);
  
  
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println("CM");
  delay(10);

  long duration2, distance2;
  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin2, LOW);
  duration2=pulseIn(echoPin2, HIGH);
  distance2 =(duration2/2)/29.1;
   Serial.print("distance2: ");
  Serial.print(distance2);
  Serial.println("CM");
  delay(10);
  
 
 if(distance<=6)
  {
    val=1;
    
  }
   if(distance2<=6)
  {
    val=0;
    
  }

   if(val==1)
   {
    digitalWrite(y, HIGH);
    digitalWrite(r, LOW);
    digitalWrite(g, LOW);
    digitalWrite(buz,HIGH);
    myservo.write(180);
    delay(1000);
    digitalWrite(y, LOW);
    digitalWrite(r, HIGH);
    digitalWrite(g, LOW);
    val=2;
   }

      if(val==0)
   {
    digitalWrite(y, HIGH);
    digitalWrite(r, LOW);
    digitalWrite(g, LOW);
    digitalWrite(buz,LOW);
    myservo.write(0);
    delay(1000);
    digitalWrite(y, LOW);
    digitalWrite(r, LOW);
    digitalWrite(g, HIGH);
    val=2;
   }

   Serial.print("val:");
   Serial.println(val);

if(ldrval<=100)
{
  digitalWrite(Nled,HIGH);
}
else
{
 digitalWrite(Nled,LOW);
}

if(irval==0)
{
  digitalWrite(infraNled,HIGH);
}
else
{
 digitalWrite(infraNled,LOW);
}

}
