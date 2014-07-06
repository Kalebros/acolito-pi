import QtQuick 2.2

Item {

    id: itemRoot
    //Propiedades del RelojAcolito
    property string colorFondo : "darkgrey"
    property string colorFuente : "white"
    property string colorBorde : "white"
    property int borderRadius : 0

    Timer {
        interval: 500; running: true; repeat: true;
        onTriggered: {
            horaReloj.text = Qt.formatTime(new Date(),"HH:mm");
        }
    }

    Rectangle
    {
        id: backgroundReloj
        color: colorFondo
        anchors.fill: itemRoot
        anchors.centerIn: itemRoot
        Text
        {
            id: horaReloj
            text: qsTr(Qt.formatTime(new Date(),"HH:mm"))
            anchors.centerIn: backgroundReloj
            anchors.fill: backgroundReloj
            horizontalAlignment: Text.Center
            font.pixelSize: 200
            fontSizeMode: Text.Fit
            color: colorFuente
            font.family: "Roboto"
            font.italic: true
            antialiasing: true
        }

    }

}
