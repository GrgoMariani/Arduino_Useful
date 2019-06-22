#include <EEPROM.h>


template <typename T>
struct EEPROM_STUFF
{
    static T data;

    static void Read()            /* Read the data struct from EEPROM */
    {
        for(unsigned int i=0; i<sizeof(T);i++)
        {
            byte * value = ((byte*)&data+i);
            *value=EEPROM.read(i);
        }
    }

    static void Write()           /* Write the data struct to EEPROM */
    {
        for(unsigned int i=0; i<sizeof(T);i++)
        {
            byte* value=(((byte*)&data+i));
            EEPROM.update(i, *value);
        }
    }

    static bool HasChanged()      /* Check if the data struct is the same as what's been written in EEPROM */
    {
        for(unsigned int i=0; i<sizeof(T);i++)
        {
            byte* value1 = (((byte*)&data+i));
            byte  value2 = EEPROM.read(i);
            if ( *value1 != value2 )
                return true;
        }
        return false;
    }
};
