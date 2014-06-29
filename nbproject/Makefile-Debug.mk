#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/3DObject.o \
	${OBJECTDIR}/src/AngularMovement.o \
	${OBJECTDIR}/src/Block.o \
	${OBJECTDIR}/src/Conception.o \
	${OBJECTDIR}/src/Enemy.o \
	${OBJECTDIR}/src/GameController.o \
	${OBJECTDIR}/src/Item.o \
	${OBJECTDIR}/src/LinearMovement.o \
	${OBJECTDIR}/src/Modelable.o \
	${OBJECTDIR}/src/Movable.o \
	${OBJECTDIR}/src/Movement.o \
	${OBJECTDIR}/src/Observable.o \
	${OBJECTDIR}/src/Observer.o \
	${OBJECTDIR}/src/Penguin.o \
	${OBJECTDIR}/src/Scenario.o \
	${OBJECTDIR}/src/Texture.o \
	${OBJECTDIR}/src/bitmap.o \
	${OBJECTDIR}/src/glm.o \
	${OBJECTDIR}/src/glmimg.o \
	${OBJECTDIR}/src/utils.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fcg-pengo

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fcg-pengo: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fcg-pengo ${OBJECTFILES} ${LDLIBSOPTIONS} -lGL -lglut -lGLU

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/3DObject.o: src/3DObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/3DObject.o src/3DObject.cpp

${OBJECTDIR}/src/AngularMovement.o: src/AngularMovement.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/AngularMovement.o src/AngularMovement.cpp

${OBJECTDIR}/src/Block.o: src/Block.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Block.o src/Block.cpp

${OBJECTDIR}/src/Conception.o: src/Conception.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Conception.o src/Conception.cpp

${OBJECTDIR}/src/Enemy.o: src/Enemy.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Enemy.o src/Enemy.cpp

${OBJECTDIR}/src/GameController.o: src/GameController.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GameController.o src/GameController.cpp

${OBJECTDIR}/src/Item.o: src/Item.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Item.o src/Item.cpp

${OBJECTDIR}/src/LinearMovement.o: src/LinearMovement.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LinearMovement.o src/LinearMovement.cpp

${OBJECTDIR}/src/Modelable.o: src/Modelable.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Modelable.o src/Modelable.cpp

${OBJECTDIR}/src/Movable.o: src/Movable.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Movable.o src/Movable.cpp

${OBJECTDIR}/src/Movement.o: src/Movement.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Movement.o src/Movement.cpp

${OBJECTDIR}/src/Observable.o: src/Observable.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Observable.o src/Observable.cpp

${OBJECTDIR}/src/Observer.o: src/Observer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Observer.o src/Observer.cpp

${OBJECTDIR}/src/Penguin.o: src/Penguin.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Penguin.o src/Penguin.cpp

${OBJECTDIR}/src/Scenario.o: src/Scenario.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Scenario.o src/Scenario.cpp

${OBJECTDIR}/src/Texture.o: src/Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Texture.o src/Texture.cpp

${OBJECTDIR}/src/bitmap.o: src/bitmap.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/bitmap.o src/bitmap.c

${OBJECTDIR}/src/glm.o: src/glm.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/glm.o src/glm.cpp

${OBJECTDIR}/src/glmimg.o: src/glmimg.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/glmimg.o src/glmimg.cpp

${OBJECTDIR}/src/utils.o: src/utils.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/utils.o src/utils.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fcg-pengo

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
