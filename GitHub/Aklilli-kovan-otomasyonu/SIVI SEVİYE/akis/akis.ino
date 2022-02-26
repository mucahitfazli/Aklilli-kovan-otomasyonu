float deger  =  0.0,l_dk;
unsigned char akissensor = 3;   // Sensör Girişi
unsigned long currentTime;
unsigned long cloopTime;
int akis_frekansi;
void akis ()  // Akışı artırmak için kesme işlevi
{
   akis_frekansi++;
}
void setup()
{
   Serial.begin( 9600 );
 pinMode (4, OUTPUT );
   pinMode (akissensor, INPUT );
   digitalWrite( akissensor, HIGH ); 
   attachInterrupt( digitalPinToInterrupt ( akissensor ), akis , RISING );  // Kurulum Kesmesi
   currentTime = millis();
   cloopTime = currentTime;
}
void loop ()
{
   currentTime = millis();  // Her saniye, litre / saat hesaplayın ve yazdırın
   if (  currentTime >= (cloopTime + 100) )
   {
    cloopTime  =  currentTime; // CloopTime'ı günceller
    if ( akis_frekansi  !=  0 )
    {
   l_dk  = ( akis_frekansi / 7.5 ); // (Darbe frekansı x 60 dk) / 7,5Q = L / saat cinsinden akış hızı
      Serial.print(" Oran:  ");
    Serial.println( l_dk );
      Serial.println(" L/dk ");
      l_dk = l_dk/60;
      deger = deger +l_dk;
if ( deger > 2) 
{
   pinMode( 4, HIGH ); 
}
else 
{
  pinMode( 4, LOW ); 
}
    Serial.print(" Deger: ");
    Serial.println( deger );
    Serial.println(" L ");
      akis_frekansi = 0; // Sayacı Sıfırla
      Serial.print( l_dk, DEC ); // Yazdır litre / saat
      Serial.println("  L/sn ");
    }
    else {
      Serial.print(" akıs oranı = 0  ");
 Serial.print(" Oran:  ");
      Serial.println( akis_frekansi );
      Serial.println(" L/dk ");
      Serial.print(" Deger: ");
      Serial.println (deger );
      Serial.println(" L");
    }
   }
delay(100);
}
