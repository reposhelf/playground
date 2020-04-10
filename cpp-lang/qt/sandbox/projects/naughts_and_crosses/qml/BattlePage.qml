import QtQuick 2.0
import QtQuick.Layouts 1.2

Item {
    RowLayout {
        anchors.fill: parent
        anchors.margins: 15

        Board {
            Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: board.width
            Layout.preferredHeight: board.height
            Layout.maximumWidth: board.width
            Layout.maximumHeight: board.height
            Layout.minimumWidth: board.width
            Layout.minimumHeight: board.height
        }

        ScorePane {
            Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 100
            Layout.preferredHeight: board.height
            Layout.maximumWidth: 200
            Layout.maximumHeight: board.height
            Layout.minimumWidth: 100
            Layout.minimumHeight: board.height
        }
    }
}
