#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "duration.h"


// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Tests constructors
TEST_CASE ("contructors") {
    Duration duration;
    REQUIRE (duration.getDuration() == 0);

    Duration duration_t (10);
    REQUIRE (duration_t.getDuration() == 10);
}

// Tests tick methods
TEST_CASE ("tick") {
    Duration duration;
    duration.tick();
    REQUIRE (duration.getDuration() == 1);

    Duration duration2 (10);
    duration2.tick (100);
    REQUIRE (duration2.getDuration() == 110);
}

// Tests alarm
TEST_CASE ("alarm") {  
    // Creates an object
    Duration duration;
    int exceeded = false; // if time have exceeded the alarm
    
    // Testing tick & alarm - without setting alarm
    exceeded = duration.tick();
    REQUIRE (exceeded == false);

    // Testing tick & alarm - time = alarm
    duration.setAlarm (11);
    exceeded = duration.tick (10);
    REQUIRE (exceeded == true);

    // Testing tick & alarm - time > alarm
    duration.setAlarm (20);
    exceeded = duration.tick (99);
    REQUIRE (exceeded == true);
    
    // Testing alarm reset
    exceeded = duration.tick ();
    REQUIRE (exceeded == false);
}