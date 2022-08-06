String voice;
#define relay1 4    //Connect relay1 to pin 4
#define relay2 5    //Connect relay2 to pin 5
#define relay3 6   //Connect relay1 to pin 6
#define relay4 7    //Connect relay2 to pin 7
void setup()
{
  Serial.begin(9600);            //Set rate for communicating with phone and arduino serial monitor
  pinMode(relay1, OUTPUT);       //Set relay1 as an output
  pinMode(relay2, OUTPUT);       //Set relay2 as an output
  pinMode(relay3, OUTPUT);      //Set relay3 as an output
  pinMode(relay4, OUTPUT);      //Set relay4 as an output
  digitalWrite(relay1, LOW);     //Switch relay1 on
  digitalWrite(relay2, LOW);     //Swtich relay2 on
  digitalWrite(relay3, LOW);     //Switch relay3 on
  digitalWrite(relay4, LOW);     //Swtich relay4 on
}
void loop()
{
  while(Serial.available()>0)    //Check if there are available bytes to read
  {
    delay(10);                 //Delay to make it stable
    char c = Serial.read();    //Conduct a serial read
    if (c == '#'){
      break;                   //Stop the loop once # is detected after a word
    }
    voice += c;                //voice = voice + c
  }
    if (voice.length() >0)
    {
      Serial.println(voice);
      if(voice == "all on"){
        switchon();// switch on function to on all appliances
      }               
      else if(voice == "all of"){
        switchoff();//switch off function to off all appliances
      }             
      else if(voice == "light chalu"){   
        digitalWrite(relay1, LOW);
      }
      else if(voice == "light band"){
        digitalWrite(relay1, HIGH);
      }
       else if(voice == "mobile charging on"){   
        digitalWrite(relay2, LOW);
      }
      else if(voice == "mobile charging off"){
        digitalWrite(relay2, HIGH);
      }
       else if(voice == "Pankha chalu"){   
        digitalWrite(relay3, LOW);
      }
      else if(voice == "Pankha band"){
        digitalWrite(relay3, HIGH);
      }
      else if(voice == "cooler chalu"){
        digitalWrite(relay4, LOW);
      }
      else if(voice == "cooler band"){
        digitalWrite(relay4, HIGH);
      }
      voice="";//Reset the variable after initiating
    }
}
void switchon()               //Function for turning on all relays
{
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
}
void switchoff()              //Function for turning off all relays
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}
