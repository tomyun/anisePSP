# 2005/10/17 02:17:14 compiled by AmesianX in POWERHACKER.NET. 
# anisePSP Makefile

#control build
DISABLE_SCALERS = true
DISABLE_HQ_SCALERS = true
DISABLE_KYRA = true

srcdir = .
VPATH = $(srcdir)
HAVE_GCC3 = false

PSPSDK=$(shell psp-config --pspsdk-path)
PSPBIN = $(PSPSDK)/../bin
LDFLAGS =

CXX     = psp-g++
AS      = psp-gcc
LD      = psp-gcc
AR      = psp-ar cru
RANLIB  = psp-ranlib
STRIP   = psp-strip
MKDIR 	= mkdir -p
RM 	= rm -f
MKSFO	= mksfo
PACK_PBP = pack-pbp
FIXUP	= psp-fixup-imports

#check PSPSDK presence
ifeq ($(PSPSDK),)
$(error $$(PSPSDK) is undefined.  Use "PSPSDK := $$(shell psp-config --pspsdk-path)" in your Makefile)
endif

# Add in PSPSDK includes and libraries.
INCDIR   := $(PSPSDK)/include
LIBDIR   := $(PSPSDK)/lib

CFLAGS = -O2 -G0 -Wall -D__PSP__ -DNONSTANDARD_PORT -DUSE_ZLIB -Wno-multichar -I/usr/local/pspdev/psp/include/SDL
CFLAGS	:= $(addprefix -I,$(INCDIR)) $(CFLAGS) -I$(PSPSDK)/../include -I$(PSPSDK)/../include/libmad -I$(PSPSDK)/../include/libTremor -I$(PSPSDK)/../include/mpeg2dec -I$(PSPSDK)/../include/SDL
LDFLAGS := $(addprefix -L,$(LIBDIR)) $(LDFLAGS)
LIBS     = 

#comment this out if you don't want to use libmad
CFLAGS	+= -DUSE_MAD
LIBS	+= -lmad 

#comment this out if you don't want to use libtremor
CFLAGS	+= -DUSE_VORBIS -DUSE_TREMOR
LIBS	+= -lvorbisidec -lstdc++
LIBS    += $(shell sdl-config --libs)

CXXFLAGS := $(CFLAGS) $(CXXFLAGS) -fno-exceptions -fno-rtti
ASFLAGS  := $(CFLAGS) $(ASFLAGS)

TARGET = anisePSP
OBJS := main.o \
	trace.o \
	engine.o \
	op_animate.o \
	op_call.o \
	op_callprocedure.o \
	op_clearscreen.o \
	op_defineprocedure.o \
	op_delay.o \
	op_displaynumber.o \
	op_if.o \
	op_makearray.o \
	op_makebytearray.o \
	op_null.o \
	op_saveconstant.o \
	op_saveexpression.o \
	op_setbasevariable.o \
	op_setcolor.o \
	op_setdialoguecolor.o \
	op_utility.o \
	op_wait.o \
	op4_blitdirect.o \
	op4_blitmasked.o \
	op4_blitswapped.o \
	op4_break.o \
	op4_callscript.o \
	op4_changeslot.o \
	op4_checkclick.o \
	op4_continue.o \
	op4_displayselection.o \
	op4_drawsolidbox.o \
	op4_drawinversebox.o \
	op4_dummy.o \
	op4_field.o \
	op4_initializeselection.o \
	op4_jumpscript.o \
	op4_loadfile.o \
	op4_loadimage.o \
	op4_manipulateflag.o \
	op4_mouse.o \
	op4_palette.o \
	op4_sound.o \
	op4_while.o \
	oput_dummy.o \
	oput_overlapscreen.o \
	oput_sprayscreen.o \
	oput_swapscreen.o \
	oput_unpackaniheader.o \
	script_opre.o \
	memory.o \
	memory_segment.o \
	memory_block.o \
	timer.o \
	input.o \
	sound.o \
	video.o \
	script.o \
	script_value.o \
	script_parameter.o \
	script_stack.o \
	file.o \
	image.o \
	animation.o \
	dialogue.o \
	dialogue_jis.o \
	dialogue_jishan.o \
	dialogue_gamebox.o \
	dialogue_sagwa.o \
	field.o \
	field_move.o \
	field_path.o \
	option.o \
	mfile.o \
	ymf262.o

MODULE_DIRS += .

DEPDIR := .deps

DEPDIRS = ($addsuffix /$(DEPDIR),$(MODULE_DIRS))
DEPFILES =

ifndef HAVE_GCC3
# If you use GCC, disable the above and enable this for intelligent
# dependency tracking.
.cpp.o:
	$(MKDIR) $(*D)/$(DEPDIR)
	$(CXX) -Wp,-MMD,"$(*D)/$(DEPDIR)/$(*F).d2" $(CXXFLAGS) $(CPPFLAGS) -c $(<) -o $*.o
	$(ECHO) "$(*D)/" > $(*D)/$(DEPDIR)/$(*F).d
	$(CAT) "$(*D)/$(DEPDIR)/$(*F).d2" >> "$(*D)/$(DEPDIR)/$(*F).d"
	$(RM) "$(*D)/$(DEPDIR)/$(*F).d2"
else
# If you even have GCC 3.x, you can use this build rule, which is safer; the above
# rule can get you into a bad state if you Ctrl-C at the wrong moment.
# Also, with this GCC inserts additional dummy rules for the involved headers,
# which ensures a smooth compilation even if said headers become obsolete.
.cpp.o:
	$(MKDIR) $(*D)/$(DEPDIR)
	$(CXX) -Wp,-MMD,"$(*D)/$(DEPDIR)/$(*F).d",-MQ,"$@",-MP $(CXXFLAGS) $(CPPFLAGS) -c $(<) -o $*.o
endif


PSP_EBOOT_SFO = param.sfo
PSP_EBOOT_TITLE = anisePSP
PSP_EBOOT = EBOOT.PBP
PSP_EBOOT_ICON = icon0.png
PSP_EBOOT_ICON1 = NULL
PSP_EBOOT_PIC0 = pic0.png
PSP_EBOOT_PIC1 = pic1.png
PSP_EBOOT_SND0 = NULL
PSP_EBOOT_PSAR = NULL

all: $(PSP_EBOOT)

$(TARGET).elf: $(OBJS)
	$(LD) $^ $(LIBS) -o $@
	$(FIXUP) $@

$(PSP_EBOOT_SFO):
	$(MKSFO) '$(PSP_EBOOT_TITLE)' $@

$(PSP_EBOOT): $(TARGET).elf $(PSP_EBOOT_SFO)
	$(STRIP) $(TARGET).elf
	$(PACK_PBP) $@ $(PSP_EBOOT_SFO) $(PSP_EBOOT_ICON) $(PSP_EBOOT_ICON1) \
		$(PSP_EBOOT_PIC0) $(PSP_EBOOT_PIC1) $(PSP_EBOOT_SND0)  \
		$(TARGET).elf $(PSP_EBOOT_PSAR)

kxploit: $(TARGET).elf $(PSP_EBOOT_SFO)
	mkdir -p "$(TARGET)"
	$(STRIP) $(TARGET).elf -o $(TARGET)/$(PSP_EBOOT)
	mkdir -p "$(TARGET)%"
	$(PACK_PBP) "$(TARGET)%/$(PSP_EBOOT)" $(PSP_EBOOT_SFO) $(PSP_EBOOT_ICON)  \
		$(PSP_EBOOT_ICON1) $(PSP_EBOOT_PIC0) $(PSP_EBOOT_PIC1)  \
		$(PSP_EBOOT_SND0) NULL $(PSP_EBOOT_PSAR)

clean:
	$(RM) $(OBJS) $(PSP_EBOOT) $(TARGET).elf \
        rm -rf ./.deps
