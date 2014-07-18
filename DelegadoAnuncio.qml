import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
    id: anuncioDelegate
    width: parent.width
    height: parent.height

    Image {
        id: anuncioCanvas
        anchors.fill: parent
        source: "file://"+display
        fillMode: Image.PreserveAspectFit
    }
}
