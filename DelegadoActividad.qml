import QtQuick 2.0
import QtGraphicalEffects 1.0

Item
{
    id: actividadRoot
    width: parent.width
    height: parent.height
    property int heightCuadro: (height / 4) - 25

    Item
    {
        id: dataColumn
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        width: parent.width / 4

        //TIPO
        Rectangle
        {
            id: tipoRect
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.topMargin: 20
            anchors.leftMargin: 20
            anchors.rightMargin: 20
            height: heightCuadro
            color: "#e51c23"

            Text
            {
                id: textTipo
                anchors.fill: parent
                anchors.margins: 10
                font.family: "Roboto"
                font.pixelSize: 100
                fontSizeMode: Text.Fit
                color: "white"
                text: model.tipo
                wrapMode: Text.Wrap
                font.weight: Font.Bold
                antialiasing: true
            }
        }

        DropShadow
        {
            anchors.fill: tipoRect
            cached: true
            horizontalOffset: 1
            verticalOffset: 3
            radius: 8.0
            samples: 16
            color: "#9e9e9e"
            source: tipoRect

        }

        //DIA
        Rectangle
        {
            id: diaRect
            anchors.top: tipoRect.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.topMargin: 20
            anchors.leftMargin: 20
            anchors.rightMargin: 20
            height: heightCuadro
            color: "#259b24"

            Text
            {
                id: diaText
                anchors.top: parent.top
                anchors.right: parent.right
                anchors.left: parent.left
                height: parent.height /2
                anchors.margins: 10
                font.family: "Roboto"
                font.pixelSize: 100
                fontSizeMode: Text.HorizontalFit
                horizontalAlignment: Text.horizontalCenter
                color: "white"
                text: dia
                wrapMode: Text.Wrap
                font.weight: Font.Bold
                antialiasing: true
            }

            Text
            {
                id: horarioText
                anchors.right: parent.right
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.top: diaText.bottom
                height: parent.height / 2
                anchors.margins: 10
                font.family: "Roboto"
                font.pixelSize: 100
                fontSizeMode: Text.VerticalFit
                horizontalAlignment: Text.horizontalCenter
                color: "white"
                text: hInicio + " - " + hFin
                wrapMode: Text.Wrap
                font.weight: Font.Bold
                antialiasing: true
            }

        }

        DropShadow
        {
            anchors.fill: diaRect
            cached: true
            horizontalOffset: 1
            verticalOffset: 3
            radius: 8.0
            samples: 16
            color: "#9e9e9e"
            source: diaRect

        }

        //PARTICIPANTES
        Rectangle
        {
            id: participantesRect
            anchors.top: diaRect.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.topMargin: 20
            anchors.leftMargin: 20
            anchors.rightMargin: 20
            height: heightCuadro
            color: "#3f51b5"

            Text {
                id: participantesText
                anchors.fill: parent
                font.family: "Roboto"
                font.pixelSize: 100
                anchors.margins: 10
                fontSizeMode: Text.HorizontalFit
                horizontalAlignment: Text.horizontalCenter
                color: "white"
                text: "De " + minParticipantes +" a "+maxParticipantes +"\nparticipantes"
                wrapMode: Text.Wrap
                font.weight: Font.Bold
                antialiasing: true

            }
        }

        DropShadow
        {
            anchors.fill: participantesRect
            cached: true
            horizontalOffset: 1
            verticalOffset: 3
            radius: 8.0
            samples: 16
            color: "#9e9e9e"
            source: participantesRect

        }

        //LUGAR
        Rectangle
        {
            id: lugarRect
            anchors.top: participantesRect.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.topMargin: 20
            anchors.leftMargin: 20
            anchors.rightMargin: 20
            height: heightCuadro
            color: "#ffc107"

            Text {
                id: lugarText
                anchors.fill: parent
                font.family: "Roboto"
                font.pixelSize: 100
                anchors.margins: 10
                fontSizeMode: Text.HorizontalFit
                horizontalAlignment: Text.horizontalCenter
                color: "white"
                text: "Donde:\n" + lugar
                wrapMode: Text.Wrap
                font.weight: Font.Bold
                antialiasing: true

            }

        }

        DropShadow
        {
            anchors.fill: lugarRect
            cached: true
            horizontalOffset: 1
            verticalOffset: 3
            radius: 8.0
            samples: 16
            color: "#9e9e9e"
            source: lugarRect

        }
    }

    Item {
        id: infoColumn
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: dataColumn.right
        anchors.right: parent.right

        //Nombre de la actividad

        Text {
            id: nombreInfo
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right

            height: parent.height / 10

            font.family: "Roboto"
            font.pixelSize: 100
            anchors.margins: 10
            fontSizeMode: Text.VerticalFit
            horizontalAlignment: Text.horizontalCenter
            color: "#212121"
            text: nombre
            wrapMode: Text.Wrap
            antialiasing: true

        }

        Rectangle
        {
            id: borderNombre
            anchors.top: nombreInfo.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.rightMargin: 5
            height: 1
            color: "slategrey"
        }

        //Descripcion

        Text {
            id: descCab
            anchors.top: borderNombre.bottom
            anchors.left: parent.left
            anchors.right: parent.right

            height: (parent.height / 15)
            font.family: "Roboto"
            font.pixelSize: 100
            anchors.margins: 10
            fontSizeMode: Text.VerticalFit
            horizontalAlignment: Text.horizontalCenter
            color: "#424242"
            text: "Descripción de la actividad:"
            wrapMode: Text.Wrap
            antialiasing: true
        }

        Text {
            id: descripcionInfo
            anchors.top: descCab.bottom
            anchors.left: parent.left
            anchors.right: parent.right

            height: parent.height / 3
            font.family: "Roboto"
            font.pixelSize: 100
            anchors.margins: 10
            fontSizeMode: Text.VerticalFit
            horizontalAlignment: Text.horizontalCenter
            color: "#424242"
            text: descripcion
            wrapMode: Text.Wrap
            elide: Text.ElideRight
            antialiasing: true
        }

        //REQUISTOS
        Text
        {
            id: reqCab
            anchors.top: descripcionInfo.bottom
            anchors.topMargin: 20
            anchors.left: parent.left
            anchors.right: parent.right

            height: (parent.height / 15)
            font.family: "Roboto"
            font.pixelSize: 100
            anchors.margins: 10
            fontSizeMode: Text.VerticalFit
            horizontalAlignment: Text.horizontalCenter
            color: "#424242"
            text: "Requisitos"
            wrapMode: Text.Wrap
            antialiasing: true
        }

        Text {
            id: requisitosInfo
            anchors.top: reqCab.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom

            font.family: "Roboto"
            font.pixelSize: 100
            anchors.margins: 10
            fontSizeMode: Text.VerticalFit
            horizontalAlignment: Text.horizontalCenter
            color: "#424242"
            text: requisitos
            wrapMode: Text.Wrap
            antialiasing: true
        }

    }

}
