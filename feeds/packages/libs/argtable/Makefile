#
# Copyright (C) 2007 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=argtable
PKG_VERSION:=2.9
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)2-9.tar.gz
PKG_SOURCE_URL:=@SF/argtable/
PKG_MD5SUM:=a7fcddef768db0ae66534ec4c4a51dee

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)2-9

include $(INCLUDE_DIR)/package.mk

define Package/argtable
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=A library for parsing GNU style command line options
  URL:=http://argtable.sourceforge.net/
endef

define Package/argtable/description
	Argtable is an ANSI C library for parsing GNU style command line options with a minimum of fuss. 
	It enables a program's command line syntax to be defined in the source code as an array of argtable 
	structs. The command line is then parsed according to that specification and the resulting values 
	are returned in those same structs where they are accessible to the main program. Both tagged 
	(-v, --verbose, --foo=bar) and untagged arguments are supported, as are multiple instances of 
	each argument.
endef

TARGET_CFLAGS += $(FPIC)
CONFIGURE_ARGS += \
	--enable-shared \
	--enable-static \

MAKE_FLAGS += \
	-C $(PKG_BUILD_DIR)/src \
	DESTDIR="$(PKG_INSTALL_DIR)" \
	all install \

define Build/InstallDev
	mkdir -p $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/include/argtable2.h $(1)/usr/include/
	mkdir -p $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libargtable2.{a,so*} $(1)/usr/lib/
endef

define Build/UninstallDev
	rm -rf \
	$(STAGING_DIR)/usr/include/argtable2.h \
	$(STAGING_DIR)/usr/lib/libargtable2.{a,so*}
endef		

define Package/argtable/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libargtable2.so.* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,argtable))
