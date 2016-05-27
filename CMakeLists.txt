cmake_minimum_required(VERSION 3.1)
project(iscore_addon_remotecontrol LANGUAGES CXX)

###  General initialization of always necessary stuff (AUTOMOC, etc) ###
iscore_common_setup()

### Files & main target ###
set(SRCS
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Settings/Model.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Settings/Model.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Settings/Presenter.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Settings/Presenter.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Settings/View.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Settings/View.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Settings/Factory.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Settings/Factory.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/Process.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/Scenario.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/ScenarioFactory.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/Loop.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/LoopFactory.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/Constraint.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/Event.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/TimeNode.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/State.hpp"

"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/Process.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/Scenario.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/ScenarioFactory.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/Loop.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/LoopFactory.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/Constraint.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/Event.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/TimeNode.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/Scenario/State.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/ApplicationPlugin.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/ApplicationPlugin.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/DocumentPlugin.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/RemoteControl/DocumentPlugin.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/iscore_addon_remotecontrol.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/iscore_addon_remotecontrol.hpp"
)

add_library(${PROJECT_NAME} ${SRCS} ${HDRS} ${QRCS})

target_link_libraries(${PROJECT_NAME} PUBLIC iscore_plugin_scenario iscore_plugin_loop)

### Setup of the target ###
setup_iscore_plugin(${PROJECT_NAME})
