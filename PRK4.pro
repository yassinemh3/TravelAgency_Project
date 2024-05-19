QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    booking.cpp \
    bookingdetails.cpp \
    customer.cpp \
    flightbooking.cpp \
    flightdetails.cpp \
    hotelbooking.cpp \
    main.cpp \
    mainwindow.cpp \
    rentalcarreservation.cpp \
    suche.cpp \
    trainticket.cpp \
    travel.cpp \
    travelagency.cpp \
    travelagencyui.cpp

HEADERS += \
    booking.h \
    bookingdetails.h \
    customer.h \
    flightbooking.h \
    flightdetails.h \
    hotelbooking.h \
    json.hpp \
    mainwindow.h \
    rentalcarreservation.h \
    suche.h \
    trainticket.h \
    travel.h \
    travelagency.h \
    travelagencyui.h

FORMS += \
    bookingdetails.ui \
    flightdetails.ui \
    mainwindow.ui \
    suche.ui \
    travelagencyui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    bookings.json \
    bookingsBinary.bin \
    hotel_905462.png \
    icon.png \
    icons8-auto-64.png \
    loupe_751463.png \
    plane_723955.png \
    train_11116398.png

RESOURCES += \
    icon.qrc
