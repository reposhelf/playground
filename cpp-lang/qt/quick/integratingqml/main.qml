import QtQuick 2.6
import QtQuick.Controls 2.0
import io.qt.examples.backend 1.0

ApplicationWindow {
    id: root
    width: 300
    height: 400
    visible: true

    BackEnd {
        id: backEnd
    }

    TextField {
        text: backEnd.userName
        placeholderText: qsTr("User name")
        anchors.centerIn: parent

        onTextChanged: backEnd.userName = text
    }
}
