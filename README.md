# ESP API Documentation:
-    https://docs.espressif.com/projects/esp-idf/en/latest/esp32/search.html?q=&check_keywords=yes&area=default

# esp32_setup
Initial setup of esp32 and build walk through
This is done with the following hardware:
https://www.adafruit.com/product/3405

# Directions:
Follow download directions at the following link for MAC / LINUX / WINDOWS :
https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/windows-setup.html

Once this is downloaded, a terminal will open:
  - Created a new directory to hold projects:
      -    mkdir <directory_name>
      -    cd <directory_name>

to create a new project:
  - in  C:\Espressif\frameworks\esp-idf-v5.1.1/<directory_name>/ directory:
      -     idf.py create-project <project_name>
      -     cd /<project_name>

  - to set target:
      - idf.py set-target <board>
      - in this case:
      -     idf.py set-target esp32

  - to initailly build / download all possible packages to use:
      -     idf.py build 

  - to flash build onto board:
      -     idf.py -p <PORT> flash
      - <PORT> is COM<num> in device manager

  - to view output of program:
      -     idf.py -p <PORT> monitor

## Sources:
## Creating Project:
Link to youtube video's going over espressif C code:
- https://www.youtube.com/@ControltheController

Example code for the screen:
- https://github.com/lvgl/lv_port_esp32

Github repo with example of decoding jpegs to the ST7789:
- https://github.com/nopnop2002/esp-idf-st7789/tree/master

## Settings for the st7789 Screen:
  - 240x135px

## Youtube help for setting up wifi:
  - videos in this playlist go over both hosting a wifi connection on the ESP32 and connecting to an external network with the ESP32:
  - https://www.youtube.com/watch?v=4Tz5j72uiUY

## Youtube video for esp32-s2:
https://www.youtube.com/watch?v=gzJCpKXPF20

## Setting up Python Virtual Environment 
- cd TheModernJukebox/hardware_src
- python -m venv <insert virtual env name>
- source <insert virtual env name>/bin/activate

## Python Image Code References
- https://www.geeksforgeeks.org/how-to-download-an-image-from-a-url-in-python/
- https://forum.opencv.org/t/how-to-expand-image-to-fullscreen-with-imshow-method/6924
