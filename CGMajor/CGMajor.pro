#-------------------------------------------------
#
# Project created by QtCreator 2015-10-09T22:21:45
#
#-------------------------------------------------
INCLUDEPATH += "C:/Users/Sarthak/Dropbox/IIITDsem7/CG/Simple OpenGL Image Library/src"
LIBS += -L"C:/Users/Sarthak/Dropbox/IIITDsem7/CG/Simple OpenGL Image Library/lib" -lSOIL

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CGMajor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    shader_utils.cpp \
    Scene.cpp \
    Joint.cpp \
    Human.cpp \
    Transformation.cpp \
    Human_Joints.cpp \
    dataset.cpp \
    vector3D.cpp \
    Character.cpp \
    Filter.cpp

HEADERS  += mainwindow.h \
    shader_utils.h \
    Scene.h \
    Joint.h \
    Human.h \
    Transformation.h \
    Human_Joints.h \
    dataset.h \
    vector3D.h \
    Character.h \
    Filters.h

FORMS    += mainwindow.ui



INCLUDEPATH +=  "C:/Users/Sarthak/Dropbox/IIITDsem7/CG/glew-gcc-debug-1.10.0-win32/include/" \

DEPENDPATH +=   "C:/Users/Sarthak/Dropbox/IIITDsem7/CG/glew-gcc-debug-1.10.0-win32/lib/" \
                "C:/Users/Sarthak/Dropbox/IIITDsem7/CG/glew-gcc-debug-1.10.0-win32/bin/"


LIBS += -L"C:/Users/Sarthak/Dropbox/IIITDsem7/CG/glew-gcc-debug-1.10.0-win32/lib/" -lglew32.dll

OTHER_FILES += \
    triangle.f.glsl \
    triangle.v.glsl

