#include <kipr/wombat.h>
//integers
int firststraight=15;
int rightturn=45;
int sortdrive=7;
int servoport=3;
int servomiddle=1260;
int servoleft=408;
int servoright=1947;
int main()
{
    create_connect();
enable_servos();
    //servo arm in right position
    set_servo_position(servoport, servomiddle); //position servo in the middle of walls
    create_drive_direct(100,-100);// face second (green) pom
    msleep(700);
    create_drive_direct(100,100);//pick up both first and second pom
    msleep(700);
    set_servo_position(servoport, servoright); //secure second (green) pom
        set_create_total_angle(0); // reset angle encoder
    // turn slightly right to face third(red) pom
    while(abs(get_create_total_angle())<3)
    {
    create_drive_direct(100,-100); // turn right
        msleep(10);
    }
    create_drive_direct(0,0);
msleep(100);
    create_drive_direct(100,100);
    msleep(1000);
        set_servo_position(servoport, servoleft); //move servo arm to left position to secure third pom
        set_create_total_angle(0); // reset angle encoder
        while(abs(get_create_total_angle())<7)
    {
    create_drive_direct(100,-100); // turn right
        msleep(10);
    }
    create_drive_direct(0,0);
    msleep(20);
    create_drive_direct(100,100);
    msleep(1250);
    set_servo_position(servoport, servoright); //move servo arm to right position to secure fourth pom
create_drive_direct(100,100);
    msleep(1500);
    create_drive_direct(0,0);
    msleep(20);
    set_create_total_angle(0); // reset angle encoder
    // turn slightly right to be on black line pom
    while(abs(get_create_total_angle())<8)
    {
    create_drive_direct(100,-100); // turn right
        msleep(10);
    }
    create_drive_direct(100,100);
    msleep(1000);//drive straight to pick up first double pom
        set_servo_position(servoport, servoleft); //move servo arm to left position to secure first double pom
    create_drive_direct(100,100);
    msleep(1800);
    set_servo_position(servoport, servoright); //move servo arm to right position to secure second double pom  
    create_drive_direct(100,100); // drive straight to pick up third double pom set 
        msleep(1800);
    set_servo_position(servoport, servoleft); //move servo arm to right position to secure third double pom
    create_drive_direct(100,100); // drive straight to pick up fourth double pom set 
        msleep(1550);
    set_servo_position(servoport, servoright); //move servo arm to right position to secure fourth double pom  
    create_drive_direct(100,100); // drive straight to pick up first triple pom set 
    msleep(2000);
    set_servo_position(servoport, servoleft); //move servo arm to right position to secure first triple pom
    create_drive_direct(100,100); // drive straight to pick up second triple pom set 
        msleep(2100);
    set_servo_position(servoport, servoright); //move servo arm to right position to secure second triple pom
    msleep(500);
    create_drive_direct(100,-100);
    msleep(1000);
    create_drive_direct(100,100);
    msleep(1000);
    create_drive_direct(-100,-100);
    msleep(2000);
    create_drive_direct(100,-100);
        msleep(2000);
    create_drive_direct(100,100);
    msleep(5000);
    disable_servos();
    create_stop();
    create_disconnect();
    return 0;
}
