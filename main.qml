import QtQuick 2.2
import QtQuick.Window 2.1
import QtGraphicalEffects 1.0

Window {
    id: windowRoot
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

    //Modelo listo para depuracion
    ListModel
    {
        id: actDebugModel

        ListElement
        {
            nombre: "Actividad 1"
            tipo: "Rol en mesa"
            hInicio: "16:00"
            hFin: "19:00"
        }
        ListElement
        {
            nombre: "Actividad 2"
            tipo: "Wargames"
            hInicio: "17:00"
            hFin: "18:00"
        }
        ListElement
        {
            nombre: "Actividad 3"
            tipo: "Juegos de mesa y cartas"
            hInicio: "20:00"
            hFin: "22:00"
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

    //Elemento LISTADO

    Rectangle
    {
        id: listaContainer
        anchors.top: reloj.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.topMargin: 15
        anchors.rightMargin: 5
        anchors.bottomMargin: 10
        width: parent.width / 4
        color: "white"
    }
}
