#include "eeprom_stuff.h"

struct Data
    {
        int                       important_int;
        char                      some_text[29];
        double                    important_double;
    };

typedef EEPROM_STUFF<Data> NONVOLATILE;

template<>
Data NONVOLATILE::data = {11, "Save this text to EEPROM", 23.0f};


/* ***************** setup() and loop() ********************* */

void setup()
{
    //NONVOLATILE::Write();  // To save some default data uncomment this line
    Serial.begin(9600);
    Serial.println("Arduino ON");
    NONVOLATILE::Read();
}

void loop()
{
    delay(5000);
    NONVOLATILE::data.important_int = 12;
    if ( NONVOLATILE::HasChanged() )
    {
        Serial.println("Data has changed. Writing the changes to EEPROM.");
        NONVOLATILE::Write();
    }
    else
    {
        Serial.println("Data hasn't changed.");
    }

}
