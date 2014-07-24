TEMPLATE = app

QT += qml quick sql

SOURCES += main.cpp \
    qmlmodelointermedio.cpp \
    acopiconfiguracion.cpp \
    acopianunciomodel.cpp \
    qmlmiquerymodel.cpp \
    acopiconfreader.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    qmlmodelointermedio.h \
    acopiconfiguracion.h \
    acopianunciomodel.h \
    qmlmiquerymodel.h \
    acopiconfreader.h

win32 {
    message("Plataforma Windows, usando metodo JSON para Windows")
    DEFINES += WINDOWS_PLATFORM
}

unix {
    message("Plataforma UNIX, usando metodo JSON para UNIX")
    DEFINES += LINUX_PLATFORM
}
