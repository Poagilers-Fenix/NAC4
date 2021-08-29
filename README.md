* <h1>Poá Smart City Weather Station</h1> 

  <img src="https://i.pinimg.com/originals/53/32/38/533238dd9a8ebfeaf7a8f4d4c2cabab6.gif" width="200px" alt="☼" />
  
  This repository has been built for academic purposes, required by FIAP as an periodic assessment of the student's current skills on IoT.


  ## Poágilers

  

  	We are a tech-driven, determined team directed towards the future. 
  	
  	Our name is taken after the glourious city of Poá, where small things are destined to greatness.

  


  ```Members```

  Daniel Sanchez Melero - rm85109<br>
  Eric Luiz Campos Pessoa - rm86405<br>
  Giovanna de Mello Leiva - rm85817<br>
  Henrique Neves Lago - rm84549<br>
  Kaue Augusto Miranda Santos - rm85707<br>
  Larissa Alves da Silva - rm86351

  

  ```Class``` - 2TDSG

  

  ## Project Description

  Poá Smart City was built on behalf of weather consulting, trying to improve the users experience. Our team has developed a code that can be loaded into a microcontroller board to return the necessary information to the <a href="https://nodered.org/">Node-RED</a> flow controller. This information is published in topics through the <a href="https://mqtt.org/">MQTT</a> protocol, and from there anyone can have access.

  ## How to

  For the Poá Smart City project work correctly, you must execute the following steps:

  - [ ] First, you must access Manage Pallete in Node-RED and install the following nodes: node-red-dashboard, node-red-serialport, node-red-node-twitter, node-red-contrib-firebase-data, node-red-firebase, node-red-node-rbe and node-red-node-serialport. Then, you can click <a href="https://github.com/Poagilers-Fenix/NAC4/blob/main/Node-RED/flows.json">here</a> to access the json file. You can copy the json line and paste in the Node-RED import box. You may also clone this repository and import the json file directly into Node-RED;

  ![image](https://user-images.githubusercontent.com/61790986/131124912-7ea239f1-44d4-48dd-97ec-915514a1f354.png)


  - [ ] You must install and configure com0com to emulate COM ports to establish Serial communication. In this project, COM3 and COM4 were set to send json data between the microcontroller and the Node-RED Serial node;
  - [ ] SimulIDE or Arduino IDE that can connect with <a href="https://mqtt.org/">MQTT</a>;
  - [ ] Create a Twitter account to receive alert coming from <a href="https://nodered.org/">Node-RED</a>. Keep in mind that you need API credentials in a Twitter developer account. These credentials will be required to configure the Twitter node;
  - OBS: if you are going to use a physical microcontroller board, you will need a temperature sensor, an anemometer and a light sensor;

  ## Video link

  <a href="https://youtu.be/uaH2S0pGXAE">Click here</a> to access the demonstration video of the system.

  

  ## References

  * [youtube - JSON Data in Node Red](https://www.youtube.com/watch?v=24ZY3CEsiow&list=WL&index=3&t=148s)
  * [Arduino: Frequencímetro TIAGO HENRIQUE](http://microcontrolandos.blogspot.com/2013/01/frquencimetro-com-arduino.html)
  * [Rajkumar2506 in CircuitsArduino](https://www.instructables.com/Arduino-Frequency-Counter/)
  * [node-red-contrib-firebase](https://flows.nodered.org/node/node-red-contrib-firebase)
  * [node-red-contrib-firebase-admin](https://www.npmjs.com/package/node-red-contrib-firebase-admin)
  * [Primeiros passos: gravar, testar e implantar](https://firebase.google.com/docs/functions/get-started?hl=pt-br)

  
