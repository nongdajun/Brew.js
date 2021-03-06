
/**

    @file CTR.hpp
    @brief Brew.js API - N3DS modules - CTR
    @author XorTroll
    @copyright Brew.js project

*/

#pragma once
#include <bjs/JavaScript.hpp>

namespace bjs::modules::CTR
{
    /**
        @brief API JS Function: "ctr.isNew3DS() → Boolean"
        @note Returns whether the current console is a new 3DS. This description is for using the function with JavaScript.
    */
    js::Function isNew3DS(js::NativeContext Context);

    /**
        @brief API JS Function: "ctr.is2DS() → Boolean"
        @note Returns whether the current console is a 2DS. This description is for using the function with JavaScript.
    */
    js::Function is2DS(js::NativeContext Context);

    /**
        @brief API JS Function: "ctr.launchLibraryApplet(AppletID)"
        @note Attemps to launch a library applet with its ID. This description is for using the function with JavaScript.
    */
    js::Function launchLibraryApplet(js::NativeContext Context);
    
    /**
        @brief API JS Function: "ctr.batteryLevel() → Number"
        @note Returns the current battery level (0 to 100). This description is for using the function with JavaScript.
    */
    js::Function batteryLevel(js::NativeContext Context);

    /**
        @brief API JS Function: "ctr.reboot()"
        @note Reboots the console. This description is for using the function with JavaScript.
    */
    js::Function reboot(js::NativeContext Context);

    /**
        @brief API JS Function: "ctr.shutDown()"
        @note Powers off the console. This description is for using the function with JavaScript.
    */
    js::Function shutDown(js::NativeContext Context);
    
    /**
        @brief API JS Function: "ctr.isCharging() → Boolean"
        @note Returns whether the console is being charged at the moment. This description is for using the function with JavaScript.
    */
    js::Function isCharging(js::NativeContext Context);
    
    /**
        @brief API JS Function: "ctr.sendNotification(Title, Message)"
        @note Sends a notification to the news applet of the 3DS console. This description is for using the function with JavaScript.
    */
    js::Function sendNotification(js::NativeContext Context);

    /**
        @brief Gets the Brew.js module of ctr.
        @return The module.
    */
    js::Module Initialize();
}