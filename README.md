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

## Usage

Upon running the application, you will be greeted by the main window, where you can choose to Publish/Subscribe to shapes and see the current existing shapes on the field.

![Main Window](/docs/MainWindow.png)

### Publish


![Publish Window](/docs/PublisherWindow.png)


### Subscribe


![Subscriber Window](/docs/SubscriberWindow.png)
