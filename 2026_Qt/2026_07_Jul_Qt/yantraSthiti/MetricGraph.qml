import QtQuick
import QtQuick.Controls

Rectangle {

    id: graph

    property string title: "CPU Usage"

    property real minimumValue: 0
    property real maximumValue: 100

    color: "#181c23"

    radius: 12

    border.width: 1
    border.color: "#292f39"

    //-------------------------------------------
    // Title
    //-------------------------------------------

    Label {

        id: graphTitle

        anchors.left: parent.left
        anchors.top: parent.top

        anchors.leftMargin: 18
        anchors.topMargin: 14

        text: graph.title

        color: "white"

        font.pixelSize: 18
        font.bold: true
    }

    //-------------------------------------------
    // Graph
    //-------------------------------------------

    Canvas {

        id: canvas

        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: graphTitle.bottom
        anchors.bottom: parent.bottom

        anchors.margins: 18

        anchors.topMargin: 12

        onPaint: {

            var ctx = getContext("2d")

            ctx.clearRect(
                0,
                0,
                width,
                height
            )

            //-------------------------------------------
            // Grid
            //-------------------------------------------

            ctx.lineWidth = 1

            for (var i = 0; i <= 4; ++i) {

                var y =
                    height * i / 4

                ctx.beginPath()

                ctx.moveTo(
                    0,
                    y
                )

                ctx.lineTo(
                    width,
                    y
                )

                ctx.stroke()
            }

            //-------------------------------------------
            // Dummy graph
            //-------------------------------------------

            ctx.lineWidth = 2

            ctx.beginPath()

            ctx.moveTo(
                0,
                height * 0.65
            )

            ctx.lineTo(
                width * 0.10,
                height * 0.55
            )

            ctx.lineTo(
                width * 0.20,
                height * 0.60
            )

            ctx.lineTo(
                width * 0.30,
                height * 0.35
            )

            ctx.lineTo(
                width * 0.40,
                height * 0.45
            )

            ctx.lineTo(
                width * 0.50,
                height * 0.25
            )

            ctx.lineTo(
                width * 0.60,
                height * 0.40
            )

            ctx.lineTo(
                width * 0.70,
                height * 0.20
            )

            ctx.lineTo(
                width * 0.80,
                height * 0.30
            )

            ctx.lineTo(
                width * 0.90,
                height * 0.15
            )

            ctx.lineTo(
                width,
                height * 0.25
            )

            ctx.stroke()
        }
    }
}