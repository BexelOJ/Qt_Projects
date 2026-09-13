import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {

    id: card

    property string title: ""
    property real metricValue: 0.0

    color: "#181c23"

    radius: 12

    border.width: 1
    border.color: "#292f39"

    ColumnLayout {

        anchors.fill: parent
        anchors.margins: 18

        spacing: 8

        //-------------------------------------------
        // Metric title
        //-------------------------------------------

        Label {

            text: card.title

            color: "#8f98a8"

            font.pixelSize: 15
            font.bold: true
        }

        //-------------------------------------------
        // Metric value
        //-------------------------------------------

        Label {

            Layout.fillWidth: true
            Layout.fillHeight: true

            verticalAlignment: Text.AlignVCenter

            text: Math.round(card.metricValue) + " %"

            color: "white"

            font.pixelSize: 32
            font.bold: true
        }

        //-------------------------------------------
        // Progress bar
        //-------------------------------------------

        ProgressBar {

            id: progressBar

            Layout.fillWidth: true

            from: 0.0
            to: 100.0

            value: Number(card.metricValue)
        }
    }
}

