
// Includes
#include <assert.h>
#include "..\include\duration.h"


// Constructors
// Initialize time to 0
Duration::Duration () {
    time = 0;
    alarm = -1;
    alarmHasBeenSet = false;
}

// Initialize time to t
Duration::Duration (int t) {
    assert (t >= 0);
    time = t;
    alarm = -1;
    alarmHasBeenSet = false;
}

// Methods
// Returns current time
int Duration::getDuration () {
    return time;
}

// Increment time by 1
// Returns true if the time has exceeded the alarm
bool Duration::tick () {
    // Increment duration
    time++;
    return checkAndUpdateAlarm ();
}

// Increment time by dt
// Returns true if the time has exceeded the alarm
bool Duration::tick (int dt) {
    assert (dt >= 0);

    // Increase duration by dt
    time += dt; 
    return checkAndUpdateAlarm ();
}

// Returns true if time has exceeded the alarm and then updates the alarm
bool Duration::checkAndUpdateAlarm () {
    bool exceeded = false;
    if (alarmHasBeenSet && time >= alarm) {
        alarm = -1;
        alarmHasBeenSet = false;
        exceeded = true;
    } 
    return exceeded;
}

// Sets alarm
void Duration::setAlarm (int t) {
    assert (t >= 0 && t > time);
    alarm = t;
    alarmHasBeenSet = true;
}

