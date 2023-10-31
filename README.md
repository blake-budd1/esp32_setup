# esp32_setup
Initial setup of esp32 and build walk through
This is done with the following hardware:
https://www.adafruit.com/product/3405

# Directions:
Follow download directions at the following link for MAC / LINUX / WINDOWS :
https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/windows-setup.html

Once this is downloaded, a terminal will open:
  - Created a new directory to hold projects:
      mkdir <directory_name>
      cd <directory_name>

to create a new project:
  - in  C:\Espressif\frameworks\esp-idf-v5.1.1/<directory_name>/ directory:
      - idf.py create-project <project_name>
      - cd /<project_name>

  - to set target:
      - idf.py set-target <board>
      - in this case:
      -     idf.py set-target esp32

  - to initailly build / download all possible packages to use:
      - idf.py build 

  - to flash build onto board:
      - idf.py -p <PORT> flash
      - <PORT> is COM<num> in device manager

  - to view output of program:
      - idf.py -p <PORT> monitor
