# Arduino-karti-ile-otomat

Bu projedeki amaç bir otomatik araç yıkama 
makinesinin minimum sayıda para üstü vererek 
çalışmasını sağlayan bir proje geliştirmektir.
 Proje kapsamında bir “hizmetler.txt” dosyası 
oluşturulmalı, istenilen değerler bu dosyadan 
okunmalı ve değerler güncellenmelidir. Kullanıcı 
butonları kullanarak para girişi yapabilmeli ve 
girdiği parayla daha sonra tekrar hizmet seçimi 
yapabilmeli ve seçtiği hizmetlere göre para üstü 
alabilmelidir

Proje fiziksel bir ortam kullanılarak 
geliştirilmiştir, geliştirme kartı olarak Arduino 
UNO R3 Klon kullanılmıştır. Dosya okuması 
yapmak için SD kart ve SD kartı Arduino kartına 
bağlamak için mikro SD kart modülü kullanılmıştır. 
SD kart modülünü Arduino ile bağlamak için Dişi-Erkek M-F Jumper Kablo kullanılmıştır. Arduino 
kartı ile breadboard arası bağlantı için Erkek-Erkek 
M-M Jumper Kablo kullanılmıştır. Kullanıcın para 
atması için beş adet para butonu ve bir adet bitiş 
butonu eklenmiştir breadboarda. Daha sonra bu beş 
adet para butonu hizmet seçimi sırasında hizmet 
butonu ve hizmet seçimi için bitiş butonu olarak 
kullanılmıştır. Ayrıca seçimlerin iptali için 
breadborda bir reset butonu eklenmiştir. Paranın 
sıkışmadığı durumda yanması için bir adet yeşil led 
kullanılmıştır. Para sıkışma durumunda yanması 
için bir adet kırmızı led kullanılmıştır. Ledlerle 
birlikte kullanmak için iki adet 0.25 W 330 R 
direnç kullanılmıştır.

 
