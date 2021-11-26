
#ifndef _DURATION_CLASS_H_
#define _DURATION_CLASS_H_

class Duration {
    private:
        // ATTRIBUTES
        int time;
        int alarm;
        bool alarmHasBeenSet;
        
        // METHODS
        bool checkAndUpdateAlarm ();

    public:
        // METHODS
        // Contructors
        Duration ();
        Duration (int t);

        // Returns the current time
        int getDuration ();

        // Tick - increment time
        // Returns true if time exceeds alarm 
        bool tick (); // Increment by 1
        bool tick (int dt); // Increment by dt

        // Sets alarm
        void setAlarm (int t);
};

#endif