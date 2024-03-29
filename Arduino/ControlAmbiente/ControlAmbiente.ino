//KY015 DHT11 Temperature and humidity sensor
int DHpin = 8;
byte dat [5];
int comida1 = 0;
int comida2 = 0;
int comida3 = 0;
char faltante[] = {0,0,0};
void(* Resetea) (void) = 0;//Funcíon Reset por soft para el arduino (como si apretaramos el botón reset)



byte read_data () {
byte data;
for (int i = 0; i < 8; i ++) {
if (digitalRead (DHpin) == LOW) {
while (digitalRead (DHpin) == LOW); // wait for 50us
delayMicroseconds (30); // determine the duration of the high level to determine the data is '0 'or '1'
if (digitalRead (DHpin) == HIGH)
data |= (1 << (7-i)); // high front and low in the post
while (digitalRead (DHpin) == HIGH); // data '1 ', wait for the next one receiver
}
}
return data;
}
void start_test () {
digitalWrite (DHpin, LOW); // bus down, send start signal
delay (30); // delay greater than 18ms, so DHT11 start signal can be detected
digitalWrite (DHpin, HIGH);
delayMicroseconds (40); // Wait for DHT11 response
pinMode (DHpin, INPUT);
while (digitalRead (DHpin) == HIGH);
delayMicroseconds (80); // DHT11 response, pulled the bus 80us
if (digitalRead (DHpin) == LOW);
delayMicroseconds (80); // DHT11 80us after the bus pulled to start sending data
for (int i = 0; i < 4; i ++) // receive temperature and humidity data, the parity bit is not considered
dat[i] = read_data ();
pinMode (DHpin, OUTPUT);
digitalWrite (DHpin, HIGH); // send data once after releasing the bus, wait for the host to open the next Start signal
}
void setup () {
Serial.begin (9600);
pinMode(0, INPUT);
pinMode(4, INPUT);
pinMode(2, INPUT);
pinMode (DHpin, OUTPUT);
}
void loop () {  
   start_test ();
  /*Serial.print ("Current humdity =");
  Serial.print (dat [0], DEC); // display the humidity-bit integer;
  Serial.print ('.');
  Serial.print (dat [1], DEC); // display the humidity decimal places;
  Serial.println ('%');
  Serial.print ("Current temperature =");*/
  String myString = String(dat[2]);
  pinMode(13,OUTPUT);
  if(myString.toInt() >= 24)
  {
    digitalWrite(13, HIGH);  
  }else{
    digitalWrite(13, LOW);  
  }
  Serial.print (dat [2], DEC); // display the temperature of integer bits;
  Serial.print ('.');
  Serial.print (dat [3], DEC); // display the temperature of decimal places;
  Serial.println ('C');
/////////////////////////////////////////////////////////////////////////////
  for(int i = 0; i==2; i++)
  {
    faltante[i] = '0';
  }
  comida1 = digitalRead(0);
  if(comida1 == HIGH)
  {
    faltante[0] = '0';
  }
  comida2 = digitalRead(4);
  if(comida2 == HIGH)
  {
    faltante[1] = '1';
  }
  comida3 = digitalRead(2);
  if(comida3 == HIGH)
  {
    faltante[2] = '2';
  }
  Serial.print(faltante[0]);
  Serial.print(faltante[1]);
  Serial.print(faltante[2]);
////////////////////////////////////////////////////////////////////////////
  delay (500);
  Resetea();
}
