/*********************************************************************
 * Переключение светодиодов через Serial
 * Платформа: Iskra Neo
 *                    
 * Подключенные модули: Красный светодиод - пин: 5, 9
 *                      Зеленый светодиод - пин: 6, 10                  
 *                      
 * Описание: Включает/выключает светодиоды в зависимости от того, какое значение  
 *            придет по Serial Port. 
 *            0 - красные светодиоды
 *            1 - зеленые светодиоды
 *            2 - красные и зеленые светодиоды
 *            3 - перебор цветов
 * 
 *********************************************************************/

#define RED_LED_1     5
#define GREEN_LED_1   6
#define RED_LED_2     9
#define GREEN_LED_2   10

int serial_data;

void setup() {
  pinMode(RED_LED_1, OUTPUT); 
  pinMode(GREEN_LED_1, OUTPUT);
  pinMode(RED_LED_2, OUTPUT); 
  pinMode(GREEN_LED_2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if(Serial.available())
  {
    delay(10);
    serial_data = Serial.read(); //Записать значение полученное по Serial port
    
    switch(serial_data)
    {
      case 0: 
        Red_Led();
        break; 
      case 1:
        Green_Led();
        break;
      case 2:        
        Red_Green_Led();
        break;
      case 3:
        while(true)
        {
            Red_Led(); //включить красный
            serial_data = Serial.read();
            if(serial_data == 4) break;
            delay(700);
  
            Green_Led(); //включить зеленый
            serial_data = Serial.read();
            if(serial_data == 4) break;
            delay(700);
              
            Green_Led(); //выключить зеленый
            serial_data = Serial.read();
            if(serial_data == 4) break;
             
            Red_Green_Led(); //включить оба
            serial_data = Serial.read();
            if(serial_data == 4) break;
            delay(700);
            
            Red_Green_Led(); //выключить оба
            serial_data = Serial.read();
            if(serial_data == 4) break;
            delay(700);
            
            Green_Led(); //включить зеленый
            serial_data = Serial.read();
            if(serial_data == 4) break;
            delay(700);
              
            Red_Led(); //включить красный
            serial_data = Serial.read();
            if(serial_data == 4) break;
            delay(700);

            Red_Led(); //выключить красный
            serial_data = Serial.read();
            if(serial_data == 4) break;

            Red_Green_Led(); //включить оба
            serial_data = Serial.read();
            if(serial_data == 4) break;
            delay(700);
            
            Red_Green_Led(); //выключить оба
            serial_data = Serial.read();
            if(serial_data == 4) break;
            delay(700);
          }
          break;      
        default:
          break;        
      }      
  }
}

void Red_Led() //включить красный
{
  digitalWrite(RED_LED_1, !digitalRead(RED_LED_1)); 
  digitalWrite(RED_LED_2, !digitalRead(RED_LED_2));
  digitalWrite(GREEN_LED_1, LOW); 
  digitalWrite(GREEN_LED_2, LOW);
}

void Green_Led() //включить зеленый
{
  digitalWrite(RED_LED_1, LOW); 
  digitalWrite(RED_LED_2, LOW);
  digitalWrite(GREEN_LED_1, !digitalRead(GREEN_LED_1)); 
  digitalWrite(GREEN_LED_2, !digitalRead(GREEN_LED_2));
}

void Red_Green_Led() //включить красный + зеленый 
{
  digitalWrite(RED_LED_1, !digitalRead(RED_LED_1)); 
  digitalWrite(RED_LED_2, !digitalRead(RED_LED_2)); 
  digitalWrite(GREEN_LED_1, !digitalRead(GREEN_LED_1)); 
  digitalWrite(GREEN_LED_2, !digitalRead(GREEN_LED_2));
}

