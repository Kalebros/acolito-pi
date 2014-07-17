import QtQuick 2.2
import QtQuick.Window 2.1
import QtGraphicalEffects 1.0

Window {
    id: windowRoot
    visible: true
    width: 360
    height: 360
    color: "#e0e0e0"
    visibility: "FullScreen"

    Item
    {
        id: itemContainer
        anchors.fill: parent
        anchors.margins: item_container_margins


        MouseArea {
            anchors.fill: parent
            onClicked: {
                //TODO
            }
        }

        Timer {
            interval: 1000; running: true; repeat: true;
            onTriggered: {
                pViewAct.incrementCurrentIndex();
                pViewPrincipal.incrementCurrentIndex();
            }
        }


        //Elemento RELOJ
        RelojAcolito
        {
            id: reloj
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.left: actividadBackgr.right
            anchors.topMargin: 5
            anchors.rightMargin: 5
            anchors.leftMargin: 5
            height: (parent.height / 10)+10
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

        //Elemento ACTIVIDAD

        Rectangle
        {
            id: actividadBackgr
            color: "white"
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: pViewAct.left
            anchors.bottomMargin: 10
            anchors.leftMargin: 10
            anchors.rightMargin: 10
            anchors.topMargin: 5

        }

        PathView
        {
            id: pViewPrincipal
            model: modeloAct
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: pViewAct.left
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            anchors.topMargin: 5
            anchors.bottomMargin: 10

            delegate: DelegadoActividad {}
            path: Path {
                startX: pViewPrincipal.width/2 ; startY: pViewPrincipal.height /2;
                PathLine {
                    x: pViewPrincipal.width/2
                    y: pViewPrincipal.height*4
                }

            }

            pathItemCount: 3
        }

    }
}
