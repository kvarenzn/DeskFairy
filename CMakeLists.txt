cmake_minimum_required(VERSION 3.16.0)

project(DeskFairy VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)

find_package(Qt5 COMPONENTS X11Extras REQUIRED)

include_directories(DeskFairy/src)
include_directories(DeskFairy/src/Framework)

include_directories(3rdparty/cubismcore/include)
include_directories(3rdparty/qhotkey/include)
include_directories(3rdparty/stb/include)

link_directories(3rdparty/cubismcore/lib)

add_executable(
    ${PROJECT_NAME}
    DeskFairy/src/Allocator.cpp
    DeskFairy/src/Defines.cpp
    DeskFairy/src/FileLoader.cpp
    DeskFairy/src/Framework/CubismCdiJson.cpp
    DeskFairy/src/Framework/CubismDefaultParameterId.cpp
    DeskFairy/src/Framework/CubismFramework.cpp
    DeskFairy/src/Framework/CubismModelSettingJson.cpp
    DeskFairy/src/Framework/Effect/CubismBreath.cpp
    DeskFairy/src/Framework/Effect/CubismEyeBlink.cpp
    DeskFairy/src/Framework/Effect/CubismPose.cpp
    DeskFairy/src/Framework/Id/CubismId.cpp
    DeskFairy/src/Framework/Id/CubismIdManager.cpp
    DeskFairy/src/Framework/Math/CubismMath.cpp
    DeskFairy/src/Framework/Math/CubismMatrix44.cpp
    DeskFairy/src/Framework/Math/CubismModelMatrix.cpp
    DeskFairy/src/Framework/Math/CubismTargetPoint.cpp
    DeskFairy/src/Framework/Math/CubismVector2.cpp
    DeskFairy/src/Framework/Math/CubismViewMatrix.cpp
    DeskFairy/src/Framework/Model/CubismMoc.cpp
    DeskFairy/src/Framework/Model/CubismModel.cpp
    DeskFairy/src/Framework/Model/CubismModelUserData.cpp
    DeskFairy/src/Framework/Model/CubismModelUserDataJson.cpp
    DeskFairy/src/Framework/Model/CubismUserModel.cpp
    DeskFairy/src/Framework/Motion/ACubismMotion.cpp
    DeskFairy/src/Framework/Motion/CubismExpressionMotion.cpp
    DeskFairy/src/Framework/Motion/CubismMotion.cpp
    DeskFairy/src/Framework/Motion/CubismMotionJson.cpp
    DeskFairy/src/Framework/Motion/CubismMotionManager.cpp
    DeskFairy/src/Framework/Motion/CubismMotionQueueEntry.cpp
    DeskFairy/src/Framework/Motion/CubismMotionQueueManager.cpp
    DeskFairy/src/Framework/Physics/CubismPhysics.cpp
    DeskFairy/src/Framework/Physics/CubismPhysicsJson.cpp
    DeskFairy/src/Framework/Rendering/CubismRenderer.cpp
    DeskFairy/src/Framework/Rendering/OpenGL/CubismOffscreenSurface_OpenGLES2.cpp
    DeskFairy/src/Framework/Rendering/OpenGL/CubismRenderer_OpenGLES2.cpp
    DeskFairy/src/Framework/Type/csmRectF.cpp
    DeskFairy/src/Framework/Type/csmString.cpp
    DeskFairy/src/Framework/Utils/CubismDebug.cpp
    DeskFairy/src/Framework/Utils/CubismJson.cpp
    DeskFairy/src/Framework/Utils/CubismString.cpp
    DeskFairy/src/GLFuncs.cpp
    DeskFairy/src/ItemManager.cpp
    DeskFairy/src/Live2DWidget.cpp
    DeskFairy/src/Logger.cpp
    DeskFairy/src/main.cpp
    DeskFairy/src/Model.cpp
    DeskFairy/src/MouseTracker.cpp
    DeskFairy/src/ScreenGrabber.cpp
    DeskFairy/src/Settings.cpp
    DeskFairy/src/TextureLoader.cpp
    DeskFairy/src/TouchManager.cpp
    DeskFairy/src/TransparentWindow.cpp

	DeskFairy/src/qhotkey.cpp
	DeskFairy/src/qhotkey_x11.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::X11Extras Qt5::Widgets Qt5::Gui GLEW GL X11 Xext box2d Live2DCubismCore)
