Project Description:
- This is an RC-Tank made using ESP8266 NodeMCU, controlled via the Blynk app on a Mobile Device. It can move in All Directions at a User-Indicated Speed, as well as Aim and Fire a loaded Rubber-Band.

Tank Components:
- 1x ESP8266 NodeMCU
- 1x L298N Motor Driver
- 6x D-Size Batteries & Battery Holders
- 4x Motors
- 3x Servos
- 1x Ice Cream Stick
- 1x Rubber Band
- 6x D-Size Batteries & Battery Holders
- Other Materials For Tank Body

Software Setup and Installation:
1. Download Project:
    - git clone https://github.com/jaredpek/RC-Tank
2. Download Blynk on your mobile device
3. Setup Tank Controls on Blynk:
    - Add 1 Joystick (Tank Movement)
        - Pin: V1
        - Output[0]: (-1, 1)
        - Output[1]: (-1, 1)
    - Add 1 Vertical Slider (Firing of Rubber Band)
        - Pin: V2
        - Output: (110, 180)
    - Add 1 Vertical Slider (Turret Up and Down)
        - Pin: V5
        - Output: (65, 120)
    - Add 1 Slider (Turret Left and Right)
        - Pin: V3
        - Output: (180, 0)
    - Add 1 Slider (Tank Speed)
        - Pin: V4
        - Output: (200, 300)
4. Input RC-Tank Parameters into the code:
    - Input Pins for Motor A and Motor B
    - Blynk Authentication Key
    - Mobile Device Hotspot SSID
    - Mobile Device Hotspot Password
5. Upload code to ESP8266 Board
6. Wait for board to connect to phone's hotspot
