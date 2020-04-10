import QtQuick 2.0

Rectangle {
    id: root
    color: "#86a9e0"

    Timer {id: timer}

    function delay(delayTime, callBack) {
        timer.interval = delayTime;
        timer.repeat = false;
        timer.triggered.connect(callBack);
        timer.start();
    }

    Connections {
        target: board
        onDrawLineRequest: {
            crossLine.x = x
            crossLine.y = y
            crossLine.width = w
            crossLine.height = h
            crossLine.rotation = r
            crossLine.visible = true
        }
    }

    Connections {
        target: result
        onRoundFinished: {
            rountText.text = lastRoundText
            hideAnimation.start()
        }
    }

    Repeater {
        model: board.squaresProperty
        Square {}
    }

    Rectangle {
        id: crossLine
        color: "red"
        opacity: 0.85
        radius: 90
        visible: false
    }

    ParallelAnimation {
        id: hideAnimation

        onStopped: {
            board.reset()
            crossLine.visible = false
            delay(2000, function() {showAnimation.start()})
        }

        NumberAnimation {
            target: roundResult
            property: "y"
            from: root.y - roundResult.height
            to: 0
            duration: 750
        }
    }

    ParallelAnimation {
        id: showAnimation

        NumberAnimation {
            target: roundResult
            property: "y"
            from: 0
            to: root.y - roundResult.height
            duration: 750
        }
    }

    Rectangle {
        id: roundResult
        color: "#42536d"
        width: parent.width
        height: parent.height
        x: 0
        y: 0 - height
        Text {
            id: rountText
            color: "#bac3d1"
            font.pixelSize: 64
            anchors.centerIn: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }
}
