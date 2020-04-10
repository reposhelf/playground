# 1.1 QT MODULES

* <b>The need for cross platform libraries</b>

  Write code once to target multiple platforms ("Write Once, Compile Anywhere")
* <b>Overview of Qt modules and their key functionality</b>

  [All Modules](http://doc.qt.io/qt-5/qtmodules.html): A list of all modules in Qt 5.

  <b><i>Qt Essentials</i></b>
  
  Qt essentials define the foundation of Qt on all platforms. Essential modules are general and useful for a majority of Qt applicatiosns. A module that is used for special purpuse is concidered an add-on module even if it is available on all supported platforms.
  
  The following lists the Qt essentials:
  
  [Qt Core](http://doc.qt.io/qt-5/qtcore-index.html): Core non-graphical classes used by other modules.
  
  [Qt GUI](http://doc.qt.io/qt-5/qtgui-index.html): Base classes for graphical user interface (GUI) components. Includes OpenGL.
  
  [Qt Multimedia](http://doc.qt.io/qt-5/qtmultimedia-index.html): Classes for audio, video, camera and radio functionality.
  
  [Qt Multimedia Widgets](http://doc.qt.io/qt-5/qtmultimediawidgets-index.html): Widget-based classes for implementing multimedia functionality.
  
  [Qt Network](http://doc.qt.io/qt-5/qtnetwork-index.html): Classes to make network programming easier and more portable.
  
  [Qt QML](http://doc.qt.io/qt-5/qtqml-index.html): Classes for QML and JavaScript languages.
  
  [Qt Quick](http://doc.qt.io/qt-5/qtquick-index.html): A declarative framework for building highly dynamic applications with custom interfaces.
  
  [Qt Quick Controls](http://doc.qt.io/qt-5/qtquickcontrols-index.html): Reusable Qt Quick based UI controls to create classic desktop-style user interfaces.
  
  [Qt Quick Dialogs](http://doc.qt.io/qt-5/qtquickdialogs-index.html): Types for creating and interacting with system dialogs from a Qt Quick applications.
  
  [Qt Quick Layouts](http://doc.qt.io/qt-5/qtquicklayouts-index.html): Layouts are items that are used to arrange Qt Quick 2 based items in the user interface.
  
  [Qt SQL](http://doc.qt.io/qt-5/qtsql-index.html): Classes for database integration using SQL.
  
  [Qt Test](http://doc.qt.io/qt-5/qttest-index.html): Classes for unit testing Qt applications and libraries.
  
  [Qt Widgets](http://doc.qt.io/qt-5/qtwidgets-index.html): Classes to extend Qt GUI with C++ widgets.
  
  <b><i>Qt Add-Ons</i></b>
  
  Qt Add-On modules bring additional value for specific purposes. These modules may only be available on some development platform. Many add-on modules are either feature-complete and exist for backwards compatibility, or are only applicable to certain platforms. Each add-on module specifies its compatibility promise separately.
  
  The following table lists the Qt add-ons:
  
  [Active Qt](http://doc.qt.io/qt-5/activeqt-index.html): Classes for applications which use ActiveX and COM
  
  [Qt 3D](http://doc.qt.io/qt-5/qt3d-index.html): Functionality for near-realtime simulation systems with support for 2D and 3D rendering.
  
  [Qt Android Extras](http://doc.qt.io/qt-5/qtandroidextras-index.html): Provides platform-specific APIs for Android.
  
  [Qt Bluetooth](http://doc.qt.io/qt-5/qtbluetooth-index.html): Provides access to Bluetooth hardware.
  
  [Qt Canvas 3D](http://doc.qt.io/qt-5/qtcanvas3d-index.html): Enables OpenGL-like 3D drawing calls from Qt Quick applications using JavaScript.
  
  [Qt Concurent](http://doc.qt.io/qt-5/qtconcurrent-index.html): Classes for writing multi-threaded programs without using low-level threading primitives.
  
  [Qt D-Bus](http://doc.qt.io/qt-5/qtdbus-index.html): Classes for inter-process communication over the D-Bus protocol.
  
  [Qt Graphical Effects](http://doc.qt.io/qt-5/qtgraphicaleffects-index.html): Graphical effects for use with Qt Quick 2.
  
  [Qt Image Formats](http://doc.qt.io/qt-5/qtimageformats-index.html): Plugins for additional image formats: TIFF, MNG, TGA, WBMP.
  
  [Qt Location](http://doc.qt.io/qt-5/qtlocation-index.html): Displays map, navigation, and place content in a QML application.
  
  [Qt Mac Extras](http://doc.qt.io/qt-5/qtmacextras-index.html): Provides platform-specific APIs for OS X.
  
  [Qt NFC](http://doc.qt.io/qt-5/qtnfc-index.html): Provides access to Near-Field communication (NFC) hardware.
  
  [Qt Platform Headers](http://doc.qt.io/qt-5/qtplatformheaders-index.html): Provides classes that encapsulate platform-specific information, tied to a given runtime configuration of a platform plugin.
  
  [Qt Positioning](http://doc.qt.io/qt-5/qtpositioning-index.html): Provides access to position, satellite and area monitoring classes.
  
  [Qt Print Support](http://doc.qt.io/qt-5/qtprintsupport-index.html): Classes to make printing easier and more portable.
  
  [Qt Purchasing](http://doc.qt.io/qt-5/qtpurchasing-index.html): Enables in-app purchase of products in Qt applications.
  
  [Qt Quick Controls 2](http://doc.qt.io/qt-5/qtquickcontrols2-index.html): Provides lightweight QML types for creating performant user interfaces for embedded and mobile devices. These controls achieve improved efficiency by employing a simplified styling architecture when compared to Qt Quick Controls. These types work in conjunction with Qt Quick and Qt Quick Layouts.
  
  [Qt Quick Extras](http://doc.qt.io/qt-5/qtquickextras-index.html): Provides a specialized set of controls that can be used to build interfaces in Qt Quick.
  
  [Qt Quick Widgets](http://doc.qt.io/qt-5/qtquickwidgets-module.html): Provides a C++ widget class for displaying a Qt Quick user interface.
  
  [Qt Sensors](http://doc.qt.io/qt-5/qtsensors-index.html): Provides access to sensor hardware and motion gesture recognition.
  
  [Qt Serial Port](http://doc.qt.io/qt-5/qtserialport-index.html): Provides access to hardware and virtual serial ports.
  
  [Qt SVG](http://doc.qt.io/qt-5/qtsvg-index.html): Classes for displaying the contents of SVG files. Supports a subset of the SVG 1.2 Tiny standard.
  
  [Qt WebChannel](http://doc.qt.io/qt-5/qtwebchannel-index.html): Provides access to QObject or QML objects from HTML clients for seamless integration of Qt applications with HTML/JavaScript clients.
  
  [Qt WebEngine](http://doc.qt.io/qt-5/qtwebengine-index.html): Classes and functions for embedding web content in applications using the Chromium browser project.
  
  [Qt WebSockets](http://doc.qt.io/qt-5/qtwebsockets-index.html): Provides WebSocket communication compliant with RFC 6455.
   
  [Qt WebView](http://doc.qt.io/qt-5/qtwebview-index.html): Displays web content in a QML application by using APIs native to the platform, without the need to include a full web browser stack.
  
  [Qt Windows Extras](http://doc.qt.io/qt-5/qtwinextras-index.html): Provides platform-specific APIs for Windows.
  
  [Qt X11 Extras](http://doc.qt.io/qt-5/qtx11extras-index.html): Provides platform-specific APIs for X11.
  
  [Qt XML](http://doc.qt.io/qt-5/qtxml-index.html): C++ implementations of SAX and DOM. Note: This module is not required to use QXmlStreamReader and QXmlStreamWriter. They are already part of Qt Core.
  
  [Qt XML Patterns](http://doc.qt.io/qt-5/qtxmlpatterns-index.html): Support for XPath, XQuery, XSLT and XML schema validation.
  
  <b><i>Add-ons available under GPLv3 license</i></b>
  
  [Qt Charts](http://doc.qt.io/qt-5/qtcharts-index.html): UI Components for displaying visually pleasing charts, driven by static or dynamic data models.
  
  [Qt Data Visualization](http://doc.qt.io/qt-5/qtdatavisualization-index.html): UI Components for creating stunning 3D data visualizations.
  
  [Qt Virtual Keyboard](http://doc.qt.io/qt-5/qtvirtualkeyboard-index.html): A framework for implementing different input methods as well as a QML virtual keyboard. Supports localized keyboard layouts and custom visual themes.
  
  [Qt Quick 2D Renderer](http://doc.qt.io/QtQuick2DRenderer): Enables the use of Qt Quick UI on devices without OpenGL capability.
  
  <b><i>Value-Add Modules</i></b>
  
  [Qt for Device Creation](http://doc.qt.io/QtForDeviceCreation): Tools for fast, easy, and fully-integrated embedded device application development. Includes most other Value-Add features.
  
  [Qt Quick Compiler](http://doc.qt.io/QtQuickCompiler): 
  
  <b><i>Technology Preview Modules</i></b>
  
  [Qt Gamepad](http://doc.qt.io/qt-5/qtgamepad-index.html): Enables Qt applications to support the use of gamepad hardware.
  
  [Qt Serial Bus](http://doc.qt.io/qt-5/qtserialbus-index.html): Provides access to serial industrial bus interface. Currently the module supports the CAN bus and Modbus protocols.
  
  [Qt Wayland Compositor](http://doc.qt.io/qt-5/qtwaylandcompositor-index.html): Provides a framework to develop a Wayland compositor.
  
  [Qt SCXML](http://doc.qt.io/qt-5/qtscxml-index.html): Provides functionality to create state machines from SCXML files.
  
  <b><i>Qt Tools</i></b>
  
  [Qt Designer](http://doc.qt.io/qt-5/qtdesigner-index.html): Classes for extending Qt Designer.
  
  [Qt Help](http://doc.qt.io/qt-5/qthelp-index.html): Classes for integrating online documentation into applications, similar to Qt Assistant.
  
  [Qt UI Tools](http://doc.qt.io/qt-5/qtuitools-index.html): Classes to handle the forms created in Qt Designer.

* The difference between native APIs and cross platform APIs

  Native API is platform specific. Cross platform APIs can be built for different platforms
* The difference between toolkits and frameworks

  Framework enforces some design pattern on the developer and give some tools for code generation.  
  * A framework is pretty-much the structure of an application.
  * Usually implemented as a set of cooperating classes making up a reusable design for a specific class of software.
  * The framework "dictates the architecture" of your application.
  * You build an application by filling in the holes in the framework
  * Frameworks encourage plug-ins.
  * Frameworks emphasize design reuse over code reuse.
  
  Library or toolkit gives you functionality for you to use as you wish. Like the stdio functions of C, Console of C#.  
  * A toolkit is probably just an oo way to say "library".
  * Could be a class library or a component library.
  * Toolkits are all about code reuse between applications.
  * Different applications can use the same toolkit.
  * Good toolkits are pretty general, not application-specific at all.
