# Version-ESP8266-projet-SmartESP
Version optimisée pour ESP8266 du projet SmartESP. Très léger, facile à comprendre, structure modulaire.



📌 Étapes pour ajouter le support ESP8266 dans Arduino IDE :


1- Ouvre Arduino IDE.

2- Va dans Fichier > Préférences (ou Arduino > Preferences sur Mac).

3- Dans le champ "URL de gestionnaire de cartes supplémentaires", colle cette URL :




http://arduino.esp8266.com/stable/package_esp8266com_index.json




  a - Dans Préférences

  
      
<img width="741" alt="Capture d’écran 2025-07-09 210622" src="https://github.com/user-attachments/assets/44dc79c7-25e2-4c02-a6f2-d609088ace32" />




   b -  colle cette URL   : http://arduino.esp8266.com/stable/package_esp8266com_index.json

   

   

<img width="746" alt="Capture d’écran 2025-07-09 210708" src="https://github.com/user-attachments/assets/1754488a-572b-4a18-a007-3d258776b159" />





   c-   Clique sur OK.

   
4- Va dans Outils → Type de carte → Gestionnaire de cartes…

Dans la barre de recherche, tape : ESP8266

Clique sur "Installer" pour esp8266 by ESP8266 Community






<img width="605" alt="Screenshot 2025-07-09 203622" src="https://github.com/user-attachments/assets/4c1950e4-cb54-4ab3-ba94-e83af8c2b15e" />






5-   Une fois l'installation terminée branche ta cart et  verifie le com  et sélèctione le :




<img width="713" alt="image" src="https://github.com/user-attachments/assets/4101094f-d795-45b9-ab16-a69701f4d8e3" />






6 -    Ensuite recherche et choisis ta carte selon ton modèle  , sélectionne ta carte ESP8266, par exemple :
NodeMCU 1.0 (ESP-12E Module)







<img width="671" alt="image" src="https://github.com/user-attachments/assets/6adc5b9d-d22c-4901-82c3-65457b8a811d" />




Résumé rapide des mots-clés à chercher dans le Library Manager :


ESPAsyncWebServer





<img width="611" alt="image" src="https://github.com/user-attachments/assets/86557e98-285d-4eb6-b108-9fc5d5279b78" />


ESPAsyncTCP




<img width="587" alt="image" src="https://github.com/user-attachments/assets/72cf9247-49cc-4903-a439-68e02db97651" />



ArduinoJson




<img width="646" alt="image" src="https://github.com/user-attachments/assets/e80a0a19-e14c-493b-b929-eebbdc8ac1a2" />











❗ Problèmes fréquents  sur  certain appareil :
Si le port n’apparaît pas → installe le pilote CH340  en  ligne ou sur  le  site  de smart ESP


<img width="728" alt="image" src="https://github.com/user-attachments/assets/62a67a7a-b813-49b2-ad73-6569f1df73dd" />





