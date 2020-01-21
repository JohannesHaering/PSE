QT += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ViewModule/src/classificationresult.cpp \
    ViewModule/src/classificationresultpanel.cpp \
    ViewModule/src/classprobability.cpp \
    ViewModule/src/contentview.cpp \
    ViewModule/src/detectioncontrolpanel.cpp \
    ViewModule/src/detectionresultpanel.cpp \
    ViewModule/src/device.cpp \
    ViewModule/src/devicecheckboxmanager.cpp \
    ViewModule/src/imageclassificationcontrolpanel.cpp \
    ViewModule/src/inferencepage.cpp \
    ViewModule/src/inferencepageadapter.cpp \
    ViewModule/src/main.cpp \
    ViewModule/src/mainwindow.cpp \
    ViewModule/src/objectdetectioninferencepage.cpp \
    ViewModule/src/objectdetectioninferencepageadapter.cpp \
    ViewModule/src/result.cpp \
    ViewModule/src/topology.cpp \
    ViewModule/src/training.cpp \
    ViewModule/src/view.cpp \
    ViewModule/src/viewfacade.cpp \
    RendererModule/src/classificationresultrenderer.cpp \
    RendererModule/src/detectionresultrenderer.cpp \
    RendererModule/src/render.cpp \
    RendererModule/src/renderer.cpp \
    RendererModule/src/trainingrenderer.cpp

HEADERS += \
    ViewModule/include/classificationresult.h \
    ViewModule/include/classificationresultpanel.h \
    ViewModule/include/classprobability.h \
    ViewModule/include/contentview.h \
    ViewModule/include/detectioncontrolpanel.h \
    ViewModule/include/detectionresultpanel.h \
    ViewModule/include/device.h \
    ViewModule/include/devicecheckboxmanager.h \
    ViewModule/include/imageclassificationcontrolpanel.h \
    ViewModule/include/inferencepage.h \
    ViewModule/include/inferencepageadapter.h \
    ViewModule/include/mainwindow.h \
    ViewModule/include/objectdetectioninferencepage.h \
    ViewModule/include/objectdetectioninferencepageadapter.h \
    ViewModule/include/result.h \
    ViewModule/include/topology.h \
    ViewModule/include/training.h \
    ViewModule/include/view.h \
    ViewModule/include/viewfacade.h \
    RendererModule/include/classificationresultrenderer.h \
    RendererModule/include/detectionresultrenderer.h \
    RendererModule/include/render.h \
    RendererModule/include/renderer.h \
    RendererModule/include/trainingrenderer.h

FORMS += \
    ViewModule/ui/classificationresultpanel.ui \
    ViewModule/ui/detectioncontrolpanel.ui \
    ViewModule/ui/detectionresultpanel.ui \
    ViewModule/ui/devicecheckboxmanager.ui \
    ViewModule/ui/imageclassificationcontrolpanel.ui \
    ViewModule/ui/inferencepage.ui \
    ViewModule/ui/mainwindow.ui \
    ViewModule/ui/objectdetectioninferencepage.ui \
    ViewModule/ui/topology.ui \
    ViewModule/ui/training.ui \
    RendererModule/ui/render.ui
INCLUDEPATH += \
    ViewModule/include \
    RendererModule/include

#LIBS += -lopencv_highgui -lopencv_core -lopencv_imgproc -lopencv_videoio
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
