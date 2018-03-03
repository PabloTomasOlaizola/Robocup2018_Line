const int blanco =  200;
const int nsensores = 7;
//HACEMOS UN ARRAY CON LOS SENSORES QUE LEEN NEGRO
int pines[nsensores] = {1,2,3,4,5,6,7};

void setup() {
  Serial.begin(9600);

  //ACA DECLARAMOS CADA UNO DE LOS PINES QUE ESTAN EN EL ARRAY COMO INPUT
  for(int i = 0; i < nsensores; i++)
      pinMode(pines[i],INPUT);
}

//ACA PONEMOS QUE CUANDO LEA BLANCO NOS TIRE TRUE
bool lee_blanco(int pin){

      if(analogRead(pines[pin]) < blanco)
         return false;

    return true;
}
//ACA HACEMOS QUE LEA LOS SENSORES QUE TIENE PARA DESPUES IMPRIMIR
void loop() {
  for(int i = 0; i < nsensores; i++){

    print("Sensor ");
    print(i);
    print(": ");
    //ACA SI LEE BLANCO VA A IMPRIMIR "LEE BLANCO" Y SI NO "NO LEE BLANCO"
    if(lee_blanco(i))
      println("Lee blanco");
     else
     println("No lee blanco");
  }
    delay(2000);
}
