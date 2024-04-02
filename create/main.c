#include "../kipr/wombat.h"
#include "../kipr/create3/client/client.h"


int main()
{
    // const Create3AudioNote Note[] = {{392, 0.5}, {440, 0.5}, {494, 0.5}, {523, 0.5}, {587, 1.0}, {523, 0.5}, {494, 0.5}, {440, 0.5}, {392, 1.0}, {392, 0.5}, {440, 0.5}, {494, 0.5}, {523, 0.5}, {587, 1.0}, {523, 0.5}, {494, 0.5}, {440, 0.5}, {392, 1.0}};
    while (create3_is_connected() == 0)
    {
        create3_connect(); // constantly try to connect to the create
    }
    create3_rotate_degrees(270, 1);   // rotote the create by 270 degrees
    create3_wait();                   // wait for the create to finish rotating
    printf("Hello World\n");          // print "Hello World" to the console for debugging purposes
    create3_rotate_degrees(-270, 1);  // rotate the create by -270 degrees
    create3_wait();                   // wait for the create to finish rotating
                                      /*    for (int i = 0; i < sizeof(Note) / sizeof(Note[0]); i++)
                                          {
                                              create3_audio_play(&Note[i], 1, 0);
                                          }
                                          */
    create3_drive_straight(0.1, 0.2); // drive the create forwards for a small distance
    msleep(1000);                     // add a second of delay
    create3_wait();
    const Create3Lightring Ring = {{0, 255, 0}, {255, 255, 255}, {0, 255, 0}, {0, 0, 255}, {0, 0, 0}, {0, 0, 255}}; // trying out the create3 light ring
    create3_led_animation(Create3SpinLights, Ring, 10);
    create3_wait();
    return 0; // end the program
}
