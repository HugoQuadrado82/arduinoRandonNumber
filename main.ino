/*

  //criar um array vazio;
  //gerar um numero aleatorio de 1 a 50;
    //comparar se esse numero já exite no array;
    //se não existir guardar o numero no array;
    //se já existir ignora e volta a gerar outro numero aleatorio;
    //mostar no LCD o array do números únicos;
    //repetir o processo para as estrelas;


*/

// include the library code:
#include <LiquidCrystal.h>

int numbers[5]; //numeros
int stars[2]; //estrelas
int tempNumber;
int tempStart;
int c = 1; //cursor
int number;
int star;
bool numberExists;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  
  lcd.setCursor(0,0);
  lcd.print("Number Generator");
  lcd.setCursor(0,1);
  lcd.print("by: tecnovlogger");
  delay(2000);
  
}

void loop() {
 
  
    lcd.clear();  
  
  int numbersCompleted = 0;
    int startsCompleted = 0;
  
  
    Serial.println("Start generating numbers");
    //Numeros
    do {
        numberExists = false;
        //animation
        for(int x=0; x<100;x++) {
            tempNumber = random(1, 51);
            lcd.setCursor(c,0);
            lcd.print(tempNumber);
            lcd.print(" ");
            delay(20);
        }
        //end animation
        //random number
        number = random(1, 51);
        Serial.println("--------------");
        Serial.println(number);
        Serial.println("--------------");
           
              
        //check if number exists
      
          for (int x = 0; x < numbersCompleted; x++)
          {
            if (number == numbers[x])
            {
              Serial.println("numero repetido");
              numberExists = true;
              break;
            }
          }
      
          if (numberExists == false) {
        Serial.println("new number");
              numbers[numbersCompleted] = number;
        lcd.setCursor(c,0);
              
              if (number < 10){
            lcd.print("0");
                lcd.print(number);
              } else {
                lcd.print(number);
              }
              
                  lcd.print(" ");
              c = c + 3;
                  delay(1000);
              
                numbersCompleted++;

            } 
      
  } while (numbersCompleted < 5);
    Serial.println("End generating numbers");
  
 
  int c = 5; //reset the cursor
  
  
    Serial.println("Start generating stars");
    //stars
    do {
        numberExists = false;
        //animation
        for(int x=0; x<100;x++) {
            tempNumber = random(1, 13);
            lcd.setCursor(c,1);
            lcd.print(tempNumber);
            lcd.print(" ");
            delay(20);
        }
        star = random(1, 13);
        Serial.println("*--------------*");
        Serial.println(star);
        Serial.println("*--------------*");
      //end animation    
              
        //check if number exists
      
          for (int x = 0; x < startsCompleted; x++)
          {
            if (star == stars[x])
            {
              Serial.println("numero repetido");
              numberExists = true;
              break;
            }
          }
      
          if (numberExists == false) {
                Serial.println("new number");
              stars[startsCompleted] = star;
        lcd.setCursor(c,1);
              
              if (star < 10){
            lcd.print("0");
                lcd.print(star);
              } else {
                lcd.print(star);
              }
              
                  lcd.print(" ");
              c = c + 3;
                  delay(1000);
              
                startsCompleted++;

            } 
            
  } while (startsCompleted < 2);
    Serial.println("End generating Stars");
  
 
  //wait for a keypress
  delay(10000);
}
