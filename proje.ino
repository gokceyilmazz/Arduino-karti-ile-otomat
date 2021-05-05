
#include <SPI.h>
#include <SD.h>

#define Buton1 8
#define Buton2 3
#define Buton3 5
#define Buton4 6
#define Buton5 7
#define Buton6 2
#define Buton_reset 9
#define Ledyesil A1
#define Ledkirmizi A2

int buton_deg=0;
int para=0;
int kopukleme=0,yikama=0,kurulama=0,cilalama=0;
int sayi;

File dosya;


int kopuklememiktar,yikamamiktar,kurulamamiktar,cilalamamiktar;
int bestl, ontl, yirmitl, ellitl, yuztl;
int yuz=0, elli=0, yirmi=0, on=0, bes=0;
int eklenenbes=0,eklenenon=0,eklenenyirmi=0,eklenenelli=0,eklenenyuz=0;
int eksilenkopukleme=0,eksilenyikama=0,eksilenkurulama=0,eksilencilalama=0;
int kasa=0;

void setup() {
  pinMode(Buton1, INPUT_PULLUP);
  pinMode(Buton2, INPUT_PULLUP);
  pinMode(Buton3, INPUT_PULLUP);
  pinMode(Buton4, INPUT_PULLUP);
  pinMode(Buton5, INPUT_PULLUP);
  pinMode(Buton6, INPUT_PULLUP);
  pinMode(Buton_reset, INPUT_PULLUP);
  pinMode(Ledyesil, OUTPUT);
  pinMode(Ledkirmizi, OUTPUT);
  
  Serial.begin(115200);
    char okunan[100]; 
    int i=0; 
    char *nokta;
    int miktar[5];
    int say;
    
   
   Serial.println(F("SD kart hazirlniyor..."));
  if(!SD.begin(4)){
    Serial.println(F("SD kart takili degil!!!!"));
    Serial.println(F("Lutfen SD kartinizi takiniz!!!"));
    while(!SD.begin(4));
    Serial.println(F("SD kart kullanima hazir!!!"));
    delay(1000);
  }
  else{
    Serial.println(F("SD kart kullanima hazir!!!"));
    delay(1000);
  }

    
    
    dosya = SD.open("LRT.txt",FILE_WRITE); 
    
    dosya.seek(0); 
    
    
    while (dosya.available()) 
    {
      
       okunan[i] = dosya.read(); 
       i++;
       
    }
    
    dosya.close(); // dosya kapatılıyor
    
    
    
    Serial.println(okunan);
    Serial.println(F("------------------------------"));
    Serial.println(F("Lütfen para girişi yapınız:"));
    nokta=strtok(okunan,",");
    for(int j=0; j<5 ;j++){
      say=atoi(nokta);
      miktar[j]=say;
      nokta=strtok(NULL,",");
    }
    nokta=strtok(NULL,"\n");
    
    say=atoi(nokta);
    kopuklememiktar=say;
    nokta=strtok(NULL,",");
    nokta=strtok(NULL,",");
    nokta=strtok(NULL,",");
    say=atoi(nokta);
    yikamamiktar=say;
    nokta=strtok(NULL,",");
    nokta=strtok(NULL,",");
    nokta=strtok(NULL,",");
    say=atoi(nokta);
    kurulamamiktar=say;
    nokta=strtok(NULL,",");
    nokta=strtok(NULL,",");
    nokta=strtok(NULL,",");
    say=atoi(nokta);
    cilalamamiktar=say;
    
    

   bestl=miktar[0];
   ontl=miktar[1];
   yirmitl=miktar[2];
   ellitl=miktar[3];
   yuztl=miktar[4];

   

}

void loop() {

      sayi = random(1,5);
  
      if(digitalRead(Buton1) == 0){
      if(buton_deg==0){
      para=para+5;
      eklenenbes+=1;
      delay(500);
      }
      else{
        if(kopuklememiktar<=0){
          Serial.println("Üzgünüz malzeme eksikliği dolayısıyla köpükleme hizmeti veremiyoruz.");
        }
        else{
        kopukleme+=1;
        eksilenkopukleme+=1; 
        }
        delay(500);
      }
      }
      if(digitalRead(Buton2) == 0){
      if(buton_deg==0){
      para=para+10;
      eklenenon+=1;
      delay(500);
      }
       else{
        if(yikamamiktar<=0){
          Serial.println("Üzgünüz malzeme eksikliği dolayısıyla yıkama hizmeti veremiyoruz.");
        }
        else{
        yikama+=1;
        eksilenyikama+=1; 
        }
        delay(500);
      }
      }
      if(digitalRead(Buton3) == 0){
        if(buton_deg==0){
      para=para+20;
      eklenenyirmi+=1;
      delay(500);
        }
        else{
          if(kurulamamiktar<=0){
          Serial.println("Üzgünüz malzeme eksikliği dolayısıyla kurulama hizmeti veremiyoruz.");
        }
        else{
        kurulama+=1;
        eksilenkurulama+=1; 
        }
        delay(500);
      }
      }
      if(digitalRead(Buton4) == 0){
         if(buton_deg==0){
      para=para+50;
      eklenenelli+=1;
      delay(500);
         }
         else{
          if(cilalamamiktar<=0){
          Serial.println("Üzgünüz malzeme eksikliği dolayısıyla cilalama hizmeti veremiyoruz.");
        }
        else{
        cilalama+=1; 
        eksilencilalama+=1;
        }
        delay(500);
      }
      }
      if(digitalRead(Buton5) == 0){
        
        if(buton_deg==0){
      para=para+100;
      eklenenyuz+=1;
      delay(500);
        }
        else{
          if(kopukleme!=0){
            Serial.print(kopukleme);
            Serial.println(F(" kere köpükleme hizmeti satın aldınız"));
          }
          if(yikama!=0){
            Serial.print(yikama);
            Serial.println(F(" kere yıkama hizmeti satın aldınız")); 
          }
          if(kurulama!=0){
            Serial.print(kurulama);
            Serial.println(F(" kere kurulama hizmeti satın aldınız"));
          }
          if(cilalama!=0){
            Serial.print(cilalama);
            Serial.println(F(" kere cilalama hizmeti satın aldınız")); 
          }
          delay(500);
          if(((kopukleme*15)+(yikama*10)+(kurulama*5)+(cilalama*50))>para){
              Serial.println(F("İstediğiniz işlemler için paranız yeterli değildir"));
            }
            else{
          
          Serial.println(sayi);
          delay(500);
          if(sayi==2){
            digitalWrite(Ledkirmizi,HIGH);
            Serial.println(F("Para sıkıştı!!!"));
            Serial.print(para);
            Serial.println(F(" TL paranız iade edilmiştir"));
            para=0;
            delay(500);
          }
          else{
            digitalWrite(Ledyesil,HIGH);
            
            para= para-(kopukleme*15)-(yikama*10)-(kurulama*5)-(cilalama*50);
            bestl+=eklenenbes, ontl+=eklenenon, yirmitl+=eklenenyirmi, ellitl+=eklenenelli, yuztl+=eklenenyuz;
            kopuklememiktar-=eksilenkopukleme, yikamamiktar-=eksilenyikama, kurulamamiktar-=eksilenkurulama, cilalamamiktar-=eksilencilalama;
            Serial.print(F("Paraüstü: "));
            Serial.println(para);
            
            yuz = para/100;
            para -= 100*yuz;

            elli = para/50;
            para -= 50*elli;

            yirmi = para/20;
            para -= 20*yirmi;

            on = para/10;
            para -= 10*on;

            bes = para/5;
            para -= 5*bes;

             if(yuztl<=0){
              yuz=yuz*2;
              elli=elli+yuz;
              yuz=0;
            }
            if(ellitl<=0){
              if(yirmitl<=0){
              yirmi=yirmi*2;
              on=on+yirmi;
              yirmi=0;
            }
            if(ontl<=0){
              on=on*2;
              bes=bes+on;
              on=0;
            }
              yirmi=yirmi+(elli*2);
              on=on+elli;
              elli=0;
            }
             if(yirmitl<=0){
              yirmi=yirmi*2;
              on=on+yirmi;
              yirmi=0;
            }
            if(ontl<=0){
              on=on*2;
              bes=bes+on;
              on=0;
            }
            

            yuztl-=yuz, ellitl-=elli, yirmitl-=yirmi, ontl-=on, bestl-=bes;

            if(yuztl<0 || ellitl<0 || yirmitl<0 || ontl<0 || bestl<0){
              kasa=1;
            }
  
            if(kasa==0){
            Serial.print(F("Paraüstünüz "));
            Serial.print(yuz);
            Serial.print(F(" tane yüz tl, "));
            Serial.print(elli);
            Serial.print(F(" tane elli tl, "));
            Serial.print(yirmi);
            Serial.print(F(" tane yirmi tl, "));
            Serial.print(on);
            Serial.print(F(" tane on tl, "));
            Serial.print(bes);
            Serial.print(F(" tane beş tl "));
            Serial.println(F(" olarak verilmiştir. "));
            }
            else if (kasa==1){
              Serial.println(F("Kasada yeterli para yoktur,paranız iade edilmiştir ve hizmetiniz iptal edilmiştir"));
              yuztl+=yuz, ellitl+=elli, yirmitl+=yirmi, ontl+=on, bestl+=bes;
              bestl-=eklenenbes, ontl-=eklenenon, yirmitl-=eklenenyirmi, ellitl-=eklenenelli, yuztl-=eklenenyuz;
              kopuklememiktar+=eksilenkopukleme, yikamamiktar+=eksilenyikama, kurulamamiktar+=eksilenkurulama, cilalamamiktar+=eksilencilalama;
              
            }
            
            delay(500);
          }
            
          }
            Serial.println(F("Kalan para miktarı:"));
            Serial.print(bestl);
            Serial.print(F(","));
            Serial.print(ontl);
            Serial.print(F(","));
            Serial.print(yirmitl);
            Serial.print(F(","));
            Serial.print(ellitl);
            Serial.print(F(","));
            Serial.println(yuztl);

            SD.remove("LRT.txt");
            dosya = SD.open("LRT.txt",FILE_WRITE);
            
           if(dosya){
      dosya.print(int(bestl));
      dosya.print(",");
      dosya.print(int(ontl));
      dosya.print(",");
      dosya.print(int(yirmitl));
      dosya.print(",");
      dosya.print(int(ellitl));
      dosya.print(",");
      dosya.println(int(yuztl));
      dosya.print("1,köpükleme,");
      dosya.print(int(kopuklememiktar));
      dosya.println(",15TL");
      dosya.print("2,yıkama,");
      dosya.print(int(yikamamiktar));
      dosya.println(",10TL");
      dosya.print("3,kurulama,");
      dosya.print(int(kurulamamiktar));
      dosya.println(",5TL");
      dosya.print("4,cilalama,");
      dosya.print(int(cilalamamiktar));
      dosya.println(",50TL");
      dosya.close();
    }
            
         
            
           
        }
      }
      if(digitalRead(Buton6) == 0){
      buton_deg=1;
      Serial.print(para);
      Serial.println(F(" TL para attınız"));
      delay(500);
      Serial.println(F("---------------------"));
      Serial.println(F("1.Buton: Köpükleme"));
      Serial.println(F("2.Buton: Yıkama"));
      Serial.println(F("3.Buton: Kurulama"));
      Serial.println(F("4.Buton: Cilalama"));
      Serial.println(F("5.Buton: Bitiş"));
      }
      if(digitalRead(Buton_reset) == 0){
        buton_deg=0,kopukleme=0,yikama=0,kurulama=0,cilalama=0;
        eklenenbes=0,eklenenon=0,eklenenyirmi=0,eklenenelli=0,eklenenyuz=0;
        eksilenkopukleme=0,eksilenyikama=0,eksilenkurulama=0,eksilencilalama=0;
        digitalWrite(Ledkirmizi,LOW);
        digitalWrite(Ledyesil,LOW);
      Serial.println(F("Tüm seçimleriniz iptal edilmiştir!!!"));
      delay(500);
      }
    
    
     
      
    

}
