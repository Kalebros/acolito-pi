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
            pViewAct.incrementCurrentIndex()
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
        ListElement
        {
            nombre: "Actividad 4"
            tipo: "Rol en mesa"
            hInicio: "16:00"
            hFin: "19:00"
        }
        ListElement
        {
            nombre: "Actividad 5"
            tipo: "Rol en mesa"
            hInicio: "16:00"
            hFin: "19:00"
        }
        ListElement
        {
            nombre: "Actividad 6"
            tipo: "Rol en mesa"
            hInicio: "16:00"
            hFin: "19:00"
        }
        ListElement
        {
            nombre: "Actividad 7"
            tipo: "Rol en mesa"
            hInicio: "16:00"
            hFin: "19:00"
        }
        ListElement
        {
            nombre: "Actividad 8"
            tipo: "Rol en mesa"
            hInicio: "16:00"
            hFin: "19:00"
        }
        ListElement
        {
            nombre: "Actividad 9"
            tipo: "Rol en mesa"
            hInicio: "16:00"
            hFin: "19:00"
        }
        ListElement
        {
            nombre: "Actividad 10"
            tipo: "Rol en mesa"
            hInicio: "16:00"
            hFin: "19:00"
        }
        ListElement
        {
            nombre: "Actividad 11"
            tipo: "Rol en mesa"
            hInicio: "16:00"
            hFin: "19:00"
        }
        ListElement
        {
            nombre: "Actividad 12"
            tipo: "Rol en mesa"
            hInicio: "16:00"
            hFin: "19:00"
        }
        ListElement
        {
            nombre: "Actividad 13"
            tipo: "Rol en mesa"
            hInicio: "16:00"
            hFin: "19:00"
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

    PathView
    {
        id: pViewAct
        model: modeloAct
        anchors.top: reloj.bottom
        width: parent.width / 4

        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.rightMargin: 5

        delegate: DelegadoListaActividad {}
        path: Path {
            startX: pViewAct.width/2 ; startY: reloj.height-20;
            PathLine {
                x: pViewAct.width/2
                y: pViewAct.height
            }

        }
        pathItemCount: 8
    }

}
