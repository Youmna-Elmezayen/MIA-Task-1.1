// C++ code
//
using namespace std;
#define led 13
String password;
String mainPassword;

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  // ask user to set inital password
  Serial.println("Set the password.\n");
  while (Serial.available() == 0)
  {}
  mainPassword = Serial.readString();
}

void loop()
{
  Serial.println("Enter the password.\n");
  while (Serial.available() == 0) 
  {}
  password = Serial.readString();
  
  char passArray[mainPassword.length() + 1]; // change it to character array
  mainPassword.toCharArray(passArray, mainPassword.length() + 1);
  char * pointerToChar = &passArray[0]; //pointer to string to modify each character
  
  // check if password entered matches the password set before
  if(password.compareTo(mainPassword) == 0)
  { // if yes cipher correct password by 1
  while(* pointerToChar != '\0')
  {
    if (isalpha(* pointerToChar))
    {
      if(* pointerToChar >= 'A' && * pointerToChar <= 'Z') // check for uppercase alphabets
      {
        * pointerToChar = (((* pointerToChar - 'A') + 1) % 26) + 'A'; // shift by 1 and make sure it wraps around
      }
      else if(* pointerToChar >= 'a' && * pointerToChar <= 'z') //check for lowercase alphabets
      {
        * pointerToChar = (((* pointerToChar - 'a') + 1) % 26) + 'a'; // shift by 1 and make sure it wraps around
      }
    }
    else if(isdigit(* pointerToChar)) // check for digits
    {
      * pointerToChar = (((* pointerToChar - '0') + 1) % 10) + '0';// shift by 1 and make sure it wraps around
    }
  }
  // make the led light up for 3 seconds
  digitalWrite(led, HIGH);
  delay(3000);
  digitalWrite(led,LOW);
  }
  else
  { //make it blink for 3 seconds
    for(int i = 0; i < 3; i++)
    {
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
    }
  }
}
