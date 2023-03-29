#include <kipr/wombat.h>
//integers
int firststraight=30;
int rightturn=90;
int sortdrive=19;
int servoport=3;
int servoleft=408;
int servoright=1947;
int main()
{
    create_connect();
enable_servos();

    //servo arm in right position
    set_servo_position(servoport, servoright);
    set_create_distance(0); //reset distance encoder
    // drive forward to first (red) pom in walls
    while(abs(get_create_distance())<firststraight)
    {
    create_drive_direct(250,250); // drive straight
        msleep(10);
    }
create_drive_direct(0,0);//stop before turn
    msleep(500);
    set_create_total_angle(0); // reset angle encoder
    while(abs(get_create_total_angle())<rightturn*37/90)
    {
    create_drive_direct(150,-150); //turn right
    msleep(10);
    }
    set_servo_position(servoport, servoleft); //move servo arm to left position to secure first pom
    set_create_distance(0); //reset distance encoder
    while(abs(get_create_distance())<sortdrive)
    {
    create_drive_direct(250,250); // drive straight to pick up second pom
        msleep(10);
    }
    set_servo_position(servoport, servoright); //move servo arm to right position to secure second pom
    set_create_distance(0); //reset distance encoder
    while(abs(get_create_distance())<sortdrive)
    {
    create_drive_direct(250,250); // drive straight to pick up third pom
        msleep(10);
    }
    set_servo_position(servoport, servoleft); //move servo arm to left position to secure third pom
    set_create_distance(0); //reset distance encoder
    while(abs(get_create_distance())<sortdrive)
    {
    create_drive_direct(250,250); // drive straight to pick up third pom
        msleep(10);
    }
    set_servo_position(servoport, servoright); //move servo arm to right position to secure fourth pom
    set_create_distance(0); //reset distance encoder
    while(abs(get_create_distance())<sortdrive)
    {
    create_drive_direct(250,250); // drive straight to pick up third pom
        msleep(10);
    }
    set_servo_position(servoport, servoright); //move servo arm to right position to secure fourth pom    
    disable_servos();
    create_stop();
    create_disconnect();
    return 0;
}
