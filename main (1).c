#include <kipr/wombat.h>
//integers
int first straight
int right turn
int sort drive
int servo left
int servo right
int main()
{
    create_connect();
    set_create_distance(0);
    while(get_create_distance()<1000)
    {
    create_drive_direct(250,250);
        msleep(10);
    }
// drive forward to first (red) pom in claws with servo arm in right position
// turn right 90 degrees and move servo arm to left position to secure first pom
// drive forward for 
// after msleep(1000) pick up second (green) pom and move servo arm to right position to secure second pom
// after msleep(1000) pick up third (red) pom and move servo arm to left position to secure third pom
//
    create_stop();
    create_disconnect();
    return 0;
}
