PROJECTS:=libc system

export HOST=i686-elf
export HOSTARCH=i386

export CC = $(HOST)-gcc
export LD = $(HOST)-ld
export AR = $(HOST)-ar
export AS = $(HOST)-as

export PREFIX = /usr
export INCDIR=$(PREFIX)/include
export LIBDIF=$(PREFIX)/lib
export BOOTDIR=$(PREFIX)/boot

export SYSROOT=$(shell pwd)/sysroot
export CC = $(HOST)-gcc --sysroot=$(SYSROOT) -isystem=$(INCDIR)
export DESTDIR=$(SYSROOT)

ISODIR = $(shell pwd)/isodir
ISOBOOT = $(ISODIR)/boot
ISOGRUB = $(ISOBOOT)/grub




install: install-headers 
	mkdir -p $(SYSROOT)
	@for PROJECT in $(PROJECTS) ; do \
		make $@ -C $$PROJECT ; \
	done

install-headers:
	@for PROJECT in $(PROJECTS) ; do \
		make $@ -C $$PROJECT ; \
	done

clean:
	@for PROJECT in $(PROJECTS) ; do \
		make $@ -C $$PROJECT ; \
	done
	rm -rf $(SYSROOT)


iso:
	mkdir -p $(ISOGRUB)
	cp $(SYSROOT)$(BOOTDIR)/bh.os $(ISOBOOT)/.
	cp ./resources/grub.cfg $(ISOGRUB)/grub.cfg
	grub-mkrescue -o BH_Systems.iso $(ISODIR)

qemu:
	qemu-system-i386 -cdrom BH_Systems.iso

debug:
	qemu-system-i386 -s -S -cdrom BH_Systems.iso