# ePRosima Fast RTPS Shapes Demo

The Shapes Demo is an application that Publishes and Subscribes to shapes of different colors and sizes moving on a board. Each Shape conforms its own topic: Square, Triangle or Circle. A single instance of the Shapes Demo can publish on or subscribe to several topics at a time.

It can be used to demonstrate the capabilities of eProsima Fast RTPS or as an interoperability demonstrator with other implementations of the RTPS protocol.

## Building from sources

You will need Qt5 and eProsima Fast RTPS 1.3.0+ to build the Shapes Demo. The default configuration downloads and compiles the latest version of eProsima Fast RTPS from Github.

    $ mkdir build; cd build;
    $ cmake ../
    $ make

If you already have eProsima Fast RTPS installed in your system, you can skip building it as a dependency by specifying 

    $ cmake ../ -DTHIRDPARTY=OFF

Note: To build and run the application on Windows, you need to set the *CMAKE_PREFIX_PATH* environmental variable to the Qt folder for the Visual Studio version you are compiling against (C:\Qt\5.7\msvc2015_64 for example). You will also need to add the /bin/ folder to the path (C:\Qt\5.7\msvc2015_64\bin for example).

## Usage

Upon running the application, you will be greeted by the main window, where you can choose to Publish/Subscribe to shapes and see the current existing shapes on the field.

![Main Window](/docs/MainWindow.png)

### Publish

The Publish Window allows you to generate a new Shape and corresponding RTPS Topic on the network.

![Publish Window](/docs/PublisherScreen.png)

There are multiple parameters that the user can define in this menu:

* Shape: Defines the topic where the publication is going to occur. Three different shapes can be published: Square, Circle and Triangle. 
* Color: Defines the color of the Shape. This parameter will be used as key; that is, a way to distinguish between multiple instances of the same shape.
* Size: Allows you to control how big the shape is. The size can vary between 1 and 99.
* Partition: You can select different partitions to differentiate groups of publishers and subscribers. You can select between four partitions (A, B, C and D). Additionally you can select the “*” partition, that will be matched against all other partitions. You should note, however, that using the “wildcard (*)” partition is not the same as not using any partition. A publisher that uses the wildcard partition will not be matched with a subscriber that uses no partitions. 
* Reliable: You can select to disable the Reliable check-box to use a Best-Effort Publisher.
* History and Durability: The History of the Publishers is set to KEEP_LAST by default. You can select the number of samples that the Publisher is going to save. You can also select whether this History is going to be VOLATILE or TRANSIENT_LOCAL. The latter will send the last stored values to subscribers joining after the Publisher has been created. 
* Liveliness: You can select the Liveliness Qos for the Publisher between three different values: AUTOMATIC, MANUAL_BY_PARTICIPANT and MANUAL_BY_TOPIC. You can also set the Lease Duration for the Publisher.
* Ownership: The Ownership Qos determines whether the instance (color) of the Topic (Shape) is owned by a single Publisher. If the selected ownership is EXCLUSIVE the Publisher will use the Ownership strength value as the strength of its publication. Only the publisher with the highest strength can publish in the same Topic with the same Key. 

### Subscribe

The Subscribe Window allows you to read and represent existing shapes on the network.

![Subscriber Window](/docs/SubscriberWindow.png)

This menu provides the options present in the Publish Windows plus the following additions:

* Time Based Filter: This value can be used to specify the minimum amount of time (in milliseconds) that the subscriber wants between updates. 
* Content Based Filter: This filter draws a rectangle in the shapes window. Only the instances that are included in this rectangle are accepted. The rest of them are ignored. The user can dynamically resize and move this content filter. 
