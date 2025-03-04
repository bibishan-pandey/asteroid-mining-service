set(ASTEROID_MINING_SIMULATION_GAME_TARGET_NAME AsteroidMiningSimulationGame)

add_executable(
        ${ASTEROID_MINING_SIMULATION_GAME_TARGET_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(${ASTEROID_MINING_SIMULATION_GAME_TARGET_NAME} PUBLIC
        sfml-audio
        sfml-graphics
        sfml-window
        sfml-system
        sfml-network
)

#function(CopyLibToTarget LIB_NAME TARGET_NAME)
#    add_custom_command(
#            TARGET ${TARGET_NAME}
#            POST_BUILD
#            COMMAND ${CMAKE_COMMAND} -E copy_if_different
#                $<TARGET_FILE:${LIB_NAME}>
#                $<TARGET_FILE_DIR:${TARGET_NAME}>
#    )
#endfunction()
#
#CopyLibToTarget(sfml-graphics ${ASTEROID_MINING_SIMULATION_GAME_TARGET_NAME})
#CopyLibToTarget(sfml-window ${ASTEROID_MINING_SIMULATION_GAME_TARGET_NAME})
#CopyLibToTarget(sfml-system ${ASTEROID_MINING_SIMULATION_GAME_TARGET_NAME})
#CopyLibToTarget(sfml-audio ${ASTEROID_MINING_SIMULATION_GAME_TARGET_NAME})
#CopyLibToTarget(sfml-network ${ASTEROID_MINING_SIMULATION_GAME_TARGET_NAME})

# Replaces the above function where we had to copy the dlls into the build target folder
add_custom_command(
        TARGET ${ASTEROID_MINING_SIMULATION_GAME_TARGET_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_RUNTIME_DLLS:${ASTEROID_MINING_SIMULATION_GAME_TARGET_NAME}>
            $<TARGET_FILE_DIR:${ASTEROID_MINING_SIMULATION_GAME_TARGET_NAME}>
        COMMAND_EXPAND_LISTS
)
