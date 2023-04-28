#include <kipr/wombat.h>

//integers
int servoport=0; //port for servo sweeper
int servomiddle=1310; //middle position for sweeper
int servoleft=408; //left position for sweeper
int servoright=1947; //right position for sweeper
int armport=3; //port for servo arm
int armup=900; //up position for arm
int armforward=1887; //forward position for arm
int armback=0; //back position for arm
int irport=0; //port for ir sensor
int rms=100; //right motor speed
int lms=100; //left motor speed
int dbp=220; //distance between poms
int main()
{
    wait_for_light(0); //start when light sensor
    shut_down_in(119); //stop in 2 minutes
    create_connect();
enable_servos();
    msleep(3000);
    set_servo_position(armport, armup); //position arm up    
    //servo arm in right position
    set_servo_position(servoport, servomiddle); //position servo in the middle of walls
    set_create_distance(0);
   while(abs(get_create_distance())<40)
         {
         create_drive_direct(lms,rms);//pick up both first and second pom
   		 msleep(10);
         }
        while(abs(get_create_total_angle())<15)
    {
    create_drive_direct(lms,-rms); // turn right
        msleep(10);
    }
       while(abs(get_create_distance())<42)// face second (green) pom
         {
         create_drive_direct(lms,rms);//pick up second pom
   		 msleep(10);
         }
    msleep(50);
    set_servo_position(servoport, servoright); //secure second (green) pom
        set_create_total_angle(0); // reset angle encoder
    //urn slightly right to face third(red) pom
    while(abs(get_create_total_angle())<17)
    {
    create_drive_direct(lms,-rms); // turn right
        msleep(10);
    }
    create_drive_direct(0,0);
msleep(100);
        set_create_distance(0);
   while(abs(get_create_distance())<180)// Move forward to get in place
         {
         create_drive_direct(lms,rms);
   		 msleep(10);
         }
        set_create_total_angle(0); // reset angle encoder
        while(abs(get_create_total_angle())<35)
    {
    create_drive_direct(lms,-rms); // turn right to get on black line
        msleep(10);
    }
  set_servo_position(servoport, servoleft); //move servo arm to left position to secure third pom
    set_create_distance(0);
   while(abs(get_create_distance())<255)// secure 4th pom
         {
         create_drive_direct(lms,rms);//pick up 4th pom
   		 msleep(10);
         }
    set_servo_position(servoport, servoright); //move servo arm to right position to secure fourth pom
    create_drive_direct(0,0);
    msleep(20);
    set_create_total_angle(0); // reset angle encoder
    // turn slightly right to be on black line pom
    while(abs(get_create_total_angle())<6.33375)
    {
    create_drive_direct(lms,-rms); // turn right
        msleep(10);
    }
        set_create_distance(0);
   while(abs(get_create_distance())<dbp) //Drive to pick up first double pom
         {
         create_drive_direct(lms+10,rms);
   		 msleep(10);
         }
        set_servo_position(servoport, servoleft); //move servo arm to left position to secure first double pom
        set_create_distance(0);
   while(abs(get_create_distance())<dbp)// Drive to face second double pom
         {
         create_drive_direct(lms+10,rms);//
   		 msleep(10);
         }
    set_servo_position(servoport, servoright); //move servo arm to right position to secure second double pom
        set_create_distance(0);
   while(abs(get_create_distance())<dbp)// Drive to third double pom
         {
         create_drive_direct(lms+10,rms);//
   		 msleep(10);
         }
    set_servo_position(servoport, servoleft); //move servo arm to right position to secure third double pom
        set_create_distance(0);
    while(abs(get_create_distance())<dbp)// drive to final double pom
         {
         create_drive_direct(lms+10,rms);
   		 msleep(10);
         }
    set_servo_position(servoport, servoright); //move servo arm to right position to secure final double pom
        set_create_distance(0);
   while(abs(get_create_distance())<240)// drive to first triple pom
         {
         create_drive_direct(lms+10,rms);
   		 msleep(10);
         }
    set_servo_position(servoport, servoleft); //move servo arm to right position to secure first triple pom
        set_create_distance(0);
     while(abs(get_create_distance())<250)// drive to final set of poms
         {
         create_drive_direct(lms+10,rms);//
   		 msleep(10);
         }
    set_servo_position(servoport, servoright); //move servo arm to right position to secure second triple pom
    msleep(500);
        set_create_distance(0);
    	set_create_total_angle(0);
    while (abs(get_create_total_angle())<50)//turn around to start to drop off poms
    {
        create_drive_direct(lms,-rms);
        msleep(10);
    }
   while(abs(get_create_distance())<170)//drive into cybersecurity center
         {
         create_drive_direct(lms,rms);//
   		 msleep(10);
         }
        set_create_distance(0);
       	set_create_total_angle(0);
    while (abs(get_create_total_angle())<20)//shake
    {
        create_drive_direct(lms,-rms);
        msleep(10);
    }
       	set_create_total_angle(0);
    while (abs(get_create_total_angle())<20)//shake
    {
        create_drive_direct(-lms,rms);
        msleep(10);
    }
           	set_create_total_angle(0);
    while (abs(get_create_total_angle())<20)//shake
    {
        create_drive_direct(lms,-rms);
        msleep(10);
    }
           	set_create_total_angle(0);
    while (abs(get_create_total_angle())<20)//shake
    {
        create_drive_direct(-lms,rms);
        msleep(10);
    }
   while(abs(get_create_distance())<170)// Back up to release set of poms
         {
         create_drive_direct(-lms,-rms);//
   		 msleep(10);
         }
        set_create_distance(0);
       	set_create_total_angle(0);
    while (abs(get_create_total_angle())<93.825)//turn around to analysis lab to drop off green poms
    {
        create_drive_direct(lms,-rms);
        msleep(10);
    }
     set_servo_position(armport,armforward);
    msleep(500);
            set_create_distance(0);
   while(abs(get_create_distance())<420)// drive to analysis lab
         {
         create_drive_direct(lms,rms);
   		 msleep(10);
         }
        create_drive_direct(0,0);
      set_servo_position(armport, armup);
   msleep (500);
         set_servo_position(armport,armback);
    msleep(500);

       	set_create_total_angle(0);    
            while (abs(get_create_total_angle())<5)//turn slightly
    {
        create_drive_direct(lms,-rms);
        msleep(10);
    }
                    set_create_distance(0);
       while(abs(get_create_distance())<300)// drive to analysis lab
         {
         create_drive_direct(lms,rms);
   		 msleep(10);
         }
        set_servo_position(servoport, servoleft); //move servo arm to left position to release green poms
           	set_create_total_angle(0);   
        while (abs(get_create_total_angle())<20)//shake
    {
        create_drive_direct(lms,-rms);
        msleep(10);
    }
       	set_create_total_angle(0);
    while (abs(get_create_total_angle())<20)//shake
    {
        create_drive_direct(-lms,rms);
        msleep(10);
    }
           	set_create_total_angle(0);
    while (abs(get_create_total_angle())<20)//shake
    {
        create_drive_direct(lms,-rms);
        msleep(10);
    }
           	set_create_total_angle(0);
    while (abs(get_create_total_angle())<20)//shake
    {
        create_drive_direct(-lms,rms);
        msleep(10);
    }
                        set_create_distance(0);
       while(abs(get_create_distance())<225)//back up from poms
         {
         create_drive_direct(-lms,-rms);
   		 msleep(10);
         }
    //drive over to next noodle
    //move servo up to knock noodle off
    //move servo down
    //drive over to next noodle
    //move servo up to knock noodle off
    //move servo down  
    disable_servos();
    create_stop();
    create_disconnect();
    return 0;
}
