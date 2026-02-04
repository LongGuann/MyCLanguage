#include "common.h"
#include "flight.h"
#include "menu.h"

int main(int argc, char const *argv[])
{
    FlightSystem *s = initFilghtSystem();
    if (s == NULL)
    {
        return -1;
    }

    moco_data(s);

    // displayFlightInfo(s);

    main_menu(s);

    return 0;
}
