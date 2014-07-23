TEMPLATE = app

QT += qml quick sql

SOURCES += main.cpp \
    qmlmodelointermedio.cpp \
    acopiconfiguracion.cpp \
    acopianunciomodel.cpp \
    qmlmiquerymodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    qmlmodelointermedio.h \
    acopiconfiguracion.h \
    acopianunciomodel.h \
    qmlmiquerymodel.h

win32 {
    DEFINES += WINDOWS_PLATFORM
}
unix {
}
