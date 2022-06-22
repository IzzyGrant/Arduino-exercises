const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
const int led = 4; // Pin para led
const int boton = 5; // Pin para boton
int estadoBoton = 0; // Pin para capturar estado de boton


void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  pinMode(led, OUTPUT); // se establece pin led como salida
  pinMode(boton, INPUT); // se establece pin boton como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
}

void loop()
{
  estadoBoton = digitalRead(boton);
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm

  
  if(estadoBoton == HIGH){ 
  if(d <= 30){ digitalWrite(led, HIGH); }
  if(d >= 31){ digitalWrite(led, LOW); }  
    }
  if (estadoBoton == LOW){digitalWrite(led, LOW);}
  
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.print(" Estado de boton : ");
  Serial.print(estadoBoton);
  Serial.println();
  delay(100);          //Hacemos una pausa de 100ms
}
