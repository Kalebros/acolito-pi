import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
    id: delegado

    property double itemsVisibles:0
    property double heightParent:0
    width: parent.width
    height: (parent.height / 10) -5
    antialiasing: true

    Rectangle
    {
        id: delegateContainer
        anchors.fill: parent
        color: "white"

        Rectangle
        {
            id: delegateDecoration
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.topMargin: 5
            anchors.leftMargin: 5
            anchors.bottomMargin: 5
            width: parent.width / 6
            color: delegado.PathView.isCurrentItem ? "#03a9f4" : "#673ab7"

            Text
            {
                id: textInitial
                anchors.fill: parent
                text: model.tipo[0]
                color: "white"
                font.family: "Roboto"
                font.pixelSize: 100
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.Center
                verticalAlignment: Text.Center
                antialiasing: true
            }
        }

        Text {
            id: textNombre
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.left: delegateDecoration.right
            anchors.leftMargin: 5 +(parent.width / 100)
            height: 2 * (parent.height / 3)
            font.pixelSize: 100
            fontSizeMode: Text.VerticalFit
            elide: Text.ElideRight
            text: model.nombre
            font.weight: Font.Light

            font.family: "Roboto"
            antialiasing: true
        }

       Text
       {
           id: textHorario
           anchors.top: textNombre.bottom
           anchors.bottom: parent.bottom
           anchors.left: delegateDecoration.right
           anchors.right: parent.right
           anchors.leftMargin: textNombre.anchors.leftMargin
           anchors.bottomMargin: textNombre.anchors.leftMargin
           font.pixelSize: 100
           fontSizeMode: Text.Fit
           text: model.hInicio + " - "+model.hFin
           font.weight: Font.Light
           font.family: "Roboto"
           antialiasing: true
       }
    }

    DropShadow
    {
        anchors.fill: delegateContainer
        cached: true
        horizontalOffset: 1
        verticalOffset: 3
        radius: 8.0
        samples: 16
        color: "#9e9e9e"
        source: delegateContainer

    }

}
