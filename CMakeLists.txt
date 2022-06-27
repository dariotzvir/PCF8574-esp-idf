set(COMPONENT_SRCS "PCF8574.cpp")

idf_component_register(SRCS "${COMPONENT_SRCS}"
                    INCLUDE_DIRS "."
                    REQUIRES driver freertos log)
