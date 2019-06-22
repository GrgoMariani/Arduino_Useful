# EEPROM

### Short explanation

Arduino has an EEPROM library but usually there is no _good practice_ code around which can point you in the right
direction on how to use it.

This example covers it by using the custom written `struct EEPROM_STUFF< >` over `EEPROM` class.

Check the code in [EEPROM_STUFF.ino](EEPROM_STUFF/EEPROM_STUFF.ino) .

Advantages:
* Small memory footprint
* Fast
* Saves EEPROM write cycles
* Easily modifyiable
* Keeps the code short and understandable

Drawbacks:
* Requires you to read this readme file in one take
* Can only _Read/Write_ everything - if you need to write only part of the data you have to write the code yourselves
  
### How to use ?

* Be sure to copy the [eeprom_stuff.h](EEPROM_STUFF/eeprom_stuff.h) header to your project directory.

* Include `eeprom_stuff.h`, define the class you wish to use as your desired storage data.
  ```C++
    #include "eeprom_stuff.h"

    struct Data
        {
            int                       important_int;
            char                      some_text[29];
            double                    important_double;
        };
  ```

* typedef the new structure to make it more readable
  ```C++
  typedef EEPROM_STUFF<Data> NONVOLATILE;
  ```
  Now we will only need to use the keyword `NONVOLATILE` when accessing the memory.

* Create the data object in your code like this
  ```C++
    template<>
    Data NONVOLATILE::data = {11, "data we wish to save", 23.0f};
  ```

* Use it in the code
  ```C++
  /* To read the variables from EEPROM use Read()*/
  NONVOLATILE::Read();

  /* To overwrite the EEPROM use Write() */
  NONVOLATILE::Write();

  /* To check if the EEPROM is different from RAM */
  NONVOLATILE::HasChanged();

  /* To change the data in the RAM use NONVOLATILE::data member */
  NONVOLATILE::data.important_int = 6;
  NONVOLATILE::data.important_double = 2.3f;
  ```
