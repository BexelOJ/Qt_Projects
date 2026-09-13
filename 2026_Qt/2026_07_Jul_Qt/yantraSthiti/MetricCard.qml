import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {

    property string title: ""
    property string value: ""

    color: "#181c23"

    radius: 12

    border.width: 1
    border.color: "#292f39"

    ColumnLayout {

        anchors.centerIn: parent

        spacing: 8

        Label {
            Layout.alignment: Qt.AlignHCenter

            text: title

            color: "#8f98a8"

            font.pixelSize: 15
            font.bold: true
        }

        Label {
            Layout.alignment: Qt.AlignHCenter

            text: value

            color: "white"

            font.pixelSize: 32
            font.bold: true
        }
    }
}

