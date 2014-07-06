import QtQuick 2.2
import QtQuick.Window 2.1
import QtGraphicalEffects 1.0

Window {
    visible: true
    width: 360
    height: 360
    color: "#e0e0e0"

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    //Elemento RELOJ
    RelojAcolito
    {
        id: reloj
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.topMargin: 5
        anchors.rightMargin: 5
        height: parent.height / 10
        width: parent.width / 4
        colorFuente:"black"
        colorFondo: "white"
    }

    DropShadow
    {
        anchors.fill: reloj
        cached: true
        horizontalOffset: 1
        verticalOffset: 3
        radius: 8.0
        samples: 16
        color: "#9e9e9e"
        source: reloj
    }

    //
}
