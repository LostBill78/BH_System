SOURCES = $(shell find cpu device kernel -type f -name \*.c)

PREFIX?= usr/local
INCDIR?= $(PREFIX)/include
BOOTDIR?= $(PREFIX)/boot

CFLAGS:=$(CFLAGS) -ffreestanding -Wall -Wextra
CPPFLAGS:=$(CPPFLAGS) -D__is_kernel -Iinclude
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -lk -lgcc

ARCHDIR=arch/$(HOSTARCH)

include $(ARCHDIR)/make.config

CFLAGS:=$(CFLAGS) $(KERNEL_ARCH_CFLAGS)
CPPFLAGS:=$(CPPFLAGS) $(KERNEL_ARCH_CPPFLAGS)
LDFLAGS:=$(LDFLAGS) $(KERNEL_ARCH_LDFLAGS)
LIBS:=$(LIBS) $(KERNEL_ARCH_LIBS)

KERNEL_OBJS = \
$(KERNEL_ARCH_OBJS) \
$(SOURCES:.c=.o) \

OBJS= \
$(KERNEL_OBJS) \

LINK_LIST= \
$(LDFLAGS) \
$(KERNEL_OBJS) \
$(LIBS) \

.PHONY: all install clean install-headers install-kernel
.SUFFIXES: .o .c .s

build:
	@echo $(DESTDIR)

bh.os: $(OBJS) $(ARCHDIR)/linker.ld
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) $(LINK_LIST)
	grub-file --is-x86-multiboot bh.os

.c.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 $(CFLAGS) $(CPPFLAGS)

.s.o:
	$(CC) -MD -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

install: install-headers install-kernel

install-headers: 
	mkdir -p $(DESTDIR)$(INCDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCDIR)/.

install-kernel: bh.os
	mkdir -p $(DESTDIR)$(BOOTDIR)    
	@cp bh.os $(DESTDIR)$(BOOTDIR)
	
clean:
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d
	rm -f *.os

