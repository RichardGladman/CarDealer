cmake_minimum_required(VERSION 3.5)

project(CarDealer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CarDealer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        settings/settingsframe.h settings/settingsframe.cpp settings/settingsframe.ui
        resources.qrc
        vehicles/vehiclesframe.h vehicles/vehiclesframe.cpp vehicles/vehiclesframe.ui
        vehicles/newvehicledialog.h vehicles/newvehicledialog.cpp vehicles/newvehicledialog.ui
        vehicles/editvehicledialog.h vehicles/editvehicledialog.cpp vehicles/editvehicledialog.ui
        vehicles/viewvehicledialog.h vehicles/viewvehicledialog.cpp vehicles/viewvehicledialog.ui
        sellers/sellerframe.h sellers/sellerframe.cpp sellers/sellerframe.ui
        sellers/newsellerdialog.h sellers/newsellerdialog.cpp sellers/newsellerdialog.ui
        sellers/editsellerdialog.h sellers/editsellerdialog.cpp sellers/editsellerdialog.ui
        customers/customersframe.h customers/customersframe.cpp customers/customersframe.ui
        customers/newcustomerdialog.h customers/newcustomerdialog.cpp customers/newcustomerdialog.ui
        customers/viewcustomerdialog.h customers/viewcustomerdialog.cpp customers/viewcustomerdialog.ui
        customers/editcustomerdialog.h customers/editcustomerdialog.cpp customers/editcustomerdialog.ui
        sales/salesframe.h sales/salesframe.cpp sales/salesframe.ui
        sales/newsaledialog.h sales/newsaledialog.cpp sales/newsaledialog.ui
        sales/viewsalesdialog.h sales/viewsalesdialog.cpp sales/viewsalesdialog.ui
        reports/reportsellerpermonthdialog.h reports/reportsellerpermonthdialog.cpp reports/reportsellerpermonthdialog.ui
        reports/reportsellerperyeardialog.h reports/reportsellerperyeardialog.cpp reports/reportsellerperyeardialog.ui
        reports/reportcustomerbyyeardialog.h reports/reportcustomerbyyeardialog.cpp reports/reportcustomerbyyeardialog.ui
        reports/reportcardealerperyeardialog.h reports/reportcardealerperyeardialog.cpp reports/reportcardealerperyeardialog.ui
        reports/reportcardealerbymonthdialog.h reports/reportcardealerbymonthdialog.cpp reports/reportcardealerbymonthdialog.ui
        customers/customervalidator.h customers/customervalidator.cpp
        sellers/sellervalidator.h sellers/sellervalidator.cpp

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET CarDealer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(CarDealer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(CarDealer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(CarDealer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.CarDealer)
endif()
set_target_properties(CarDealer PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS CarDealer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CarDealer)
endif()
