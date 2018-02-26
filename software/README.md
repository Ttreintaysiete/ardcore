# MCP Library

In order to compile sketches using the MCP49 DAC, you have to download the library [here](https://github.com/downloads/exscape/electronics/Arduino_DAC_MCP49x1_v1.0.zip) and install it in your Arduino library. Also note that some instructions used in the fac_drums were deprecated on the newest Arduino IDE, so you need to compile and upload them on the older.

You need to do a small tweak on the code in order to work properlly, this is because this new DAC uses SPI. This is based on the Euroardcore but with the mcp4921 has [been fully tested](https://www.youtube.com/watch?v=P1rAHDsiEtc):

  * you need to add to the beggining of any sketch using the DAC,
    ```
    #include <SPI.h>
    #include <DAC_MCP49xx.h>
    DAC_MCP49xx dac(DAC_MCP49xx::MCP4921, 10);
    ```
  * also you need to add the following code at the end of the __setup()__ so the DAC is properlly initialized:
    ```
    dac.setBuffer(true);        //  Set FALSE for 5V vref.
    dac.setGain(1);             //  "1" for 5V vref. "2" for 2.5V vref.
    dac.setPortWrite(true); 
    ```
  * and finally replace the __dacOutput()__ and __dacOutputfast()__ to be something like:
    ```
     void dacOutput(long v)
    {
      dac.outputA(v);
    }
    ```


# Compiling the sketches of this repo

I'm using __arduino 1.0.6__ to compile all fac_drum sketches, it may be possible to use newer arduino versions on the rest of the sketches.

In the __libraries__ folder you can find the library I'm currently using to compile all the sketches with the MCP (dac).

![lib configuration ardcore]( images/libraries-folder.png)

In my case I'm using Arduino with sudo command (to let read/write USB ports for the programmer), so my __sketbook__ is located at __/root/sketchbook__ and here is were I coped the DAC_MCP49xx library.

```
[root@boxita sketchbook]# tree
.
└── libraries
    ├── DAC_MCP49xx
    │   ├── DAC_MCP49xx.cpp
    │   ├── DAC_MCP49xx.h
    │   ├── examples
    │   │   ├── MCP49x1_single_demo
    │   │   │   └── MCP49x1_single_demo.ino
    │   │   └── MCP49x2_dual_demo
    │   │       └── MCP49x2_dual_demo.ino
    │   ├── keywords.txt
    │   └── README.txt
    └── readme.txt

5 directories, 8 files
[root@boxita sketchbook]# 
```

# Uploading hex using __avrdude__ and your AVRISP mkII.

To upload the file directly you can try the following command, I'm doing this on linux (Arch) so depending on your system configuration you may need to __sudo__ the command. Remember to burn the fuses as explained in the building guide.

```
$ avrdude -c avrispmkII -p ATmega328P -e -U flash:w:fac_fm_osc.cpp.hex
```